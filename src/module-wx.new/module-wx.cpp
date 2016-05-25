//-----------------------------------------------------------------------------
// Gura module: wx
//-----------------------------------------------------------------------------
#include "stdafx.h"

#if defined(__WXMSW__)

WXDLLIMPEXP_BASE void wxSetInstance(HINSTANCE hInst);

BOOL WINAPI DllMain(HINSTANCE hInst, DWORD dwReason, LPVOID lpvReserved)
{
	// This is necessary to load resources correctly.
	::wxSetInstance(hInst);
	return TRUE;
}

#endif

Gura_BeginModuleBody(wx)

const bool OwnerTrue = true;
const bool OwnerFalse = false;

static bool g_wxReadyFlag = false;

void AssignConstants(Environment &env);
void RegisterClasses(Environment &env);
void RegisterFunctions(Environment &env);

//-----------------------------------------------------------------------------
// Module Entries
//-----------------------------------------------------------------------------
Gura_ModuleValidate()
{
	return Version::CheckCoreVersion(GURA_VERSION, nullptr);
}

Gura_ModuleEntry()
{
	RealizeBaseClass(EventFactory);
	PrepareClass(EventFactory);
	RegisterClasses(env);
	//RegisterFunctions(env);
}

Gura_ModuleTerminate()
{
}

//-----------------------------------------------------------------------------
// utility functions
//-----------------------------------------------------------------------------
Function *LookupFunctionCustom(Environment &env, const Symbol *pSymbol, EnvRefMode envRefMode)
{
	Function *pFunc = env.LookupFunction(pSymbol, envRefMode);
	return (pFunc != nullptr && pFunc->IsCustom())? pFunc : nullptr;
}

void SetWxReadyFlag(bool wxReadyFlag)
{
	g_wxReadyFlag = wxReadyFlag;
}

bool IsWxReady()
{
	return g_wxReadyFlag;
}

bool CheckWxReady(Signal &sig)
{
	if (g_wxReadyFlag) return true;
	sig.SetError(ERR_RuntimeError, "wxWidgets functions must be called after wxApp::OnInit");
	return false;
}

void SetError_Obsolete(Signal &sig)
{
	sig.SetError(ERR_NotImplementedError, "obsolete function");
}

void SetError_NotImplemented(Signal &sig)
{
	sig.SetError(ERR_NotImplementedError, "sorry, not implemented yet");
}

void SetError_MSWOnly(Signal &sig)
{
	sig.SetError(ERR_NotImplementedError, "this function is only implemented in MSW");
}

void SetError_InvalidWxObject(Signal &sig, const char *name)
{
	sig.SetError(ERR_ValueError, "invalid wx object of %s", name);
}

void SetLogError(const Signal &sig)
{
	//::wxLogError(wxString::FromUTF8(sig.GetError().MakeText(true).c_str()));
}

wxArrayString *CreateArrayString(const ValueList &valList)
{
	wxArrayString *pArray = new wxArrayString();
	AddToArrayString(*pArray, valList);
	return pArray;
}

wxArrayInt *CreateArrayInt(const ValueList &valList)
{
	wxArrayInt *pArray = new wxArrayInt();
	AddToArrayInt(*pArray, valList);
	return pArray;
}

Value ArrayIntToValue(Environment &env, const wxArrayInt &array)
{
	Value rtn;
	Object_list *pObjList = rtn.InitAsList(env);
	pObjList->Reserve(array.GetCount());
	for (size_t i = 0; i < array.GetCount(); i++) {
		pObjList->Add(Value(array.Item(i)));
	}
	return rtn;
}

Value ArrayStringToValue(Environment &env, const wxArrayString &array)
{
	Value rtn;
	Object_list *pObjList = rtn.InitAsList(env);
	pObjList->Reserve(array.GetCount());
	for (size_t i = 0; i < array.GetCount(); i++) {
		pObjList->Add(Value(array.Item(i).ToUTF8()));
	}
	return rtn;
}

Value ArrayStringToValue(Environment &env, const wxString *array, int n)
{
	Value rtn;
	Object_list *pObjList = rtn.InitAsList(env);
	pObjList->Reserve(n);
	for (int i = 0; i < n; i++) {
		pObjList->Add(Value(array[i].ToUTF8()));
	}
	return rtn;
}

void AddToArrayString(wxArrayString &array, const ValueList &valList)
{
	foreach_const (ValueList, pValue, valList) {
		array.Add(wxString::FromUTF8(pValue->GetString()));
	}
}

void AddToArrayInt(wxArrayInt &array, const ValueList &valList)
{
	foreach_const (ValueList, pValue, valList) {
		array.Add(pValue->GetInt());
	}
}

void ConvertToWxImage(Image *pImageGura, wxImage *pImage)
{
	do {
		std::unique_ptr<Image::Scanner> pScanner(pImageGura->CreateScanner());
		unsigned char *pBuffDst = pImage->GetData();
		do {
			unsigned char *pPixel = pScanner->GetPointer();
			*(pBuffDst + 0) = *(pPixel + Image::OffsetR);
			*(pBuffDst + 1) = *(pPixel + Image::OffsetG);
			*(pBuffDst + 2) = *(pPixel + Image::OffsetB);
			pBuffDst += 3;
		} while (pScanner->Next());
	} while (0);
	if (pImageGura->GetFormat() == Image::FORMAT_RGBA) {
		pImage->SetAlpha();
		std::unique_ptr<Image::Scanner> pScanner(pImageGura->CreateScanner());
		unsigned char *pBuffDst = pImage->GetAlpha();
		do {
			unsigned char *pPixel = pScanner->GetPointer();
			*pBuffDst = *(pPixel + Image::OffsetA);
			pBuffDst++;
		} while (pScanner->Next());
	}
}

bool CheckMethodResult(Signal &sig)
{
	if (sig.IsSignalled()) {
		SetLogError(sig);
		wxDynamicCast(wxApp::GetInstance(), wxApp)->ExitMainLoop();
		return false;
	}
	return true;
}

bool CheckMethodResult(Signal &sig, const Value &rtn,
						ValueType valueType, bool invalidAcceptableFlag)
{
	if (sig.IsSignalled()) {
		SetLogError(sig);
		wxDynamicCast(wxApp::GetInstance(), wxApp)->ExitMainLoop();
		return false;
	}
	if (invalidAcceptableFlag && rtn.IsInvalid()) return true;
	if (!rtn.IsInstanceOf(valueType)) {
		sig.SetError(ERR_ValueError, "unexpected result type");
		wxDynamicCast(wxApp::GetInstance(), wxApp)->ExitMainLoop();
		return false;
	}
	return true;
}

//-----------------------------------------------------------------------------
// Iterator_NewIds
//-----------------------------------------------------------------------------
Iterator *Iterator_NewIds::Clone() const
{
	return Iterator::Reference(this);
}

Iterator *Iterator_NewIds::GetSource()
{
	return nullptr;
}

bool Iterator_NewIds::DoNext(Environment &env, Value &value)
{
	value = Value(::wxNewId());
	return true;
}

String Iterator_NewIds::ToString() const
{
	String rtn = "<iterator:wx.newids>";
	return rtn;
}

void Iterator_NewIds::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

Gura_EndModuleBody(wx, wx)

Gura_RegisterModule(wx)
