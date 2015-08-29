//----------------------------------------------------------------------------
// wxPrinter
// extracted from print.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Printer: public wxPrinter, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_Printer *_pObj;
public:
	inline wx_Printer(wxPrintDialogData* data) : wxPrinter(data), _pObj(nullptr) {}
	~wx_Printer();
	inline void AssocWithGura(Object_wx_Printer *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Printer::~wx_Printer()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_Printer::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxPrinter
//----------------------------------------------------------------------------
Gura_DeclareFunction(Printer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Printer));
	DeclareArg(env, "data", VTYPE_wx_PrintDialogData, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Printer)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxPrintDialogData *data = (wxPrintDialogData *)(nullptr);
	if (arg.IsValid(0)) data = Object_wx_PrintDialogData::GetObject(arg, 0)->GetEntity();
	wx_Printer *pEntity = new wx_Printer(data);
	Object_wx_Printer *pObj = Object_wx_Printer::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_Printer(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_Printer, CreateAbortWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "printout", VTYPE_wx_Printout, OCCUR_Once);
}

Gura_ImplementMethod(wx_Printer, CreateAbortWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_Printer *pThis = Object_wx_Printer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxPrintout *printout = Object_wx_Printout::GetObject(arg, 1)->GetEntity();
	pThis->GetEntity()->CreateAbortWindow(parent, printout);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Printer, GetAbort)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Printer, GetAbort)
{
	Signal &sig = env.GetSignal();
	Object_wx_Printer *pThis = Object_wx_Printer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->GetAbort();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareClassMethod(wx_Printer, GetLastError)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Printer, GetLastError)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxPrinterError rtn = wxPrinter::GetLastError();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Printer, GetPrintDialogData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Printer, GetPrintDialogData)
{
	Signal &sig = env.GetSignal();
	Object_wx_Printer *pThis = Object_wx_Printer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPrintDialogData &rtn = pThis->GetEntity()->GetPrintDialogData();
	return ReturnValue(env, arg, Value(new Object_wx_PrintDialogData(new wxPrintDialogData(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Printer, Print)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "printout", VTYPE_wx_Printout, OCCUR_Once);
	DeclareArg(env, "prompt", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Printer, Print)
{
	Signal &sig = env.GetSignal();
	Object_wx_Printer *pThis = Object_wx_Printer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxPrintout *printout = Object_wx_Printout::GetObject(arg, 1)->GetEntity();
	bool prompt = true;
	if (arg.IsValid(2)) prompt = arg.GetBoolean(2);
	bool rtn = pThis->GetEntity()->Print(parent, printout, prompt);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Printer, PrintDialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Printer, PrintDialog)
{
	Signal &sig = env.GetSignal();
	Object_wx_Printer *pThis = Object_wx_Printer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxDC *rtn = (wxDC *)pThis->GetEntity()->PrintDialog(parent);
	return ReturnValue(env, arg, Value(new Object_wx_DC(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Printer, ReportError)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "printout", VTYPE_wx_Printout, OCCUR_Once);
	DeclareArg(env, "message", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Printer, ReportError)
{
	Signal &sig = env.GetSignal();
	Object_wx_Printer *pThis = Object_wx_Printer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	wxPrintout *printout = Object_wx_Printout::GetObject(arg, 1)->GetEntity();
	wxString message = wxString::FromUTF8(arg.GetString(2));
	pThis->GetEntity()->ReportError(parent, printout, message);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Printer, Setup)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Printer, Setup)
{
	Signal &sig = env.GetSignal();
	Object_wx_Printer *pThis = Object_wx_Printer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *parent = Object_wx_Window::GetObject(arg, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->Setup(parent);
	return ReturnValue(env, arg, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxPrinter
//----------------------------------------------------------------------------
Object_wx_Printer::~Object_wx_Printer()
{
}

Object *Object_wx_Printer::Clone() const
{
	return nullptr;
}

String Object_wx_Printer::ToString(bool exprFlag)
{
	String rtn("<wx.Printer:");
	if (GetEntity() == nullptr) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

//----------------------------------------------------------------------------
// Class implementation for wxPrinter
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Printer)
{
	Gura_AssignFunction(Printer);
	Gura_AssignMethod(wx_Printer, CreateAbortWindow);
	Gura_AssignMethod(wx_Printer, GetAbort);
	Gura_AssignMethod(wx_Printer, GetLastError);
	Gura_AssignMethod(wx_Printer, GetPrintDialogData);
	Gura_AssignMethod(wx_Printer, Print);
	Gura_AssignMethod(wx_Printer, PrintDialog);
	Gura_AssignMethod(wx_Printer, ReportError);
	Gura_AssignMethod(wx_Printer, Setup);
}

Gura_ImplementDescendantCreator(wx_Printer)
{
	return new Object_wx_Printer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
