//----------------------------------------------------------------------------
// wxFileDialog
// extracted from filedlg.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_FileDialog: public wxFileDialog, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_FileDialog *_pObj;
public:
	inline wx_FileDialog(wxWindow* parent, const wxString& message, const wxString& defaultDir, const wxString& defaultFile, const wxString& wildcard, long style, const wxPoint& pos, const wxSize& sz, const wxString& name) : wxFileDialog(parent, message, defaultDir, defaultFile, wildcard, style, pos, sz, name), _pObj(nullptr) {}
	~wx_FileDialog();
	inline void AssocWithGura(Object_wx_FileDialog *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_FileDialog::~wx_FileDialog()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_FileDialog::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxFileDialog
//----------------------------------------------------------------------------
Gura_DeclareFunction(FileDialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_FileDialog));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "message", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "defaultDir", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "defaultFile", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "wildcard", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "sz", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FileDialog)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxWindow *parent = args.IsValid(0)?
			Object_wx_Window::GetObject(args, 0)->GetEntity() : nullptr;
	wxString message = wxT("Choose a file");
	if (args.IsValid(1)) message = wxString::FromUTF8(args.GetString(1));
	wxString defaultDir = wxT("");
	if (args.IsValid(2)) defaultDir = wxString::FromUTF8(args.GetString(2));
	wxString defaultFile = wxT("");
	if (args.IsValid(3)) defaultFile = wxString::FromUTF8(args.GetString(3));
	wxString wildcard = wxT("*.*");
	if (args.IsValid(4)) wildcard = wxString::FromUTF8(args.GetString(4));
	long style = wxFD_DEFAULT_STYLE;
	if (args.IsValid(5)) style = args.GetLong(5);
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(6)) pos = Object_wx_Point::GetObject(args, 6)->GetEntity();
	wxSize *sz = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(7)) sz = Object_wx_Size::GetObject(args, 7)->GetEntity();
	wxString name = wxT("filedlg");
	if (args.IsValid(8)) name = wxString::FromUTF8(args.GetString(8));
	wx_FileDialog *pEntity = new wx_FileDialog(parent, message, defaultDir, defaultFile, wildcard, style, *pos, *sz, name);
	Object_wx_FileDialog *pObj = Object_wx_FileDialog::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_FileDialog(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_FileDialog, GetDirectory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileDialog, GetDirectory)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileDialog *pThis = Object_wx_FileDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetDirectory();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_FileDialog, GetFilename)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileDialog, GetFilename)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileDialog *pThis = Object_wx_FileDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetFilename();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_FileDialog, GetFilenames)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileDialog, GetFilenames)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileDialog *pThis = Object_wx_FileDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxArrayString filenames;
	pThis->GetEntity()->GetFilenames(filenames);
	return ReturnValue(env, args, ArrayStringToValue(env, filenames));
}

Gura_DeclareMethod(wx_FileDialog, GetFilterIndex)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileDialog, GetFilterIndex)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileDialog *pThis = Object_wx_FileDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetFilterIndex();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_FileDialog, GetMessage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileDialog, GetMessage)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileDialog *pThis = Object_wx_FileDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetMessage();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_FileDialog, GetPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileDialog, GetPath)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileDialog *pThis = Object_wx_FileDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetPath();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_FileDialog, GetPaths)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileDialog, GetPaths)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileDialog *pThis = Object_wx_FileDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxArrayString paths;
	pThis->GetEntity()->GetPaths(paths);
	return ReturnValue(env, args, ArrayStringToValue(env, paths));
}

Gura_DeclareMethod(wx_FileDialog, GetWildcard)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileDialog, GetWildcard)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileDialog *pThis = Object_wx_FileDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetWildcard();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_FileDialog, SetDirectory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "directory", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileDialog, SetDirectory)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileDialog *pThis = Object_wx_FileDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString directory = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetDirectory(directory);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileDialog, SetFilename)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "setfilename", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileDialog, SetFilename)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileDialog *pThis = Object_wx_FileDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString setfilename = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetFilename(setfilename);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileDialog, SetFilterIndex)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "filterIndex", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileDialog, SetFilterIndex)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileDialog *pThis = Object_wx_FileDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int filterIndex = args.GetInt(0);
	pThis->GetEntity()->SetFilterIndex(filterIndex);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileDialog, SetMessage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "message", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileDialog, SetMessage)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileDialog *pThis = Object_wx_FileDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString message = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetMessage(message);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileDialog, SetPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "path", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileDialog, SetPath)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileDialog *pThis = Object_wx_FileDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString path = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetPath(path);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileDialog, SetWildcard)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "wildCard", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileDialog, SetWildcard)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileDialog *pThis = Object_wx_FileDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString wildCard = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetWildcard(wildCard);
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileDialog, ShowModal)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FileDialog, ShowModal)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileDialog *pThis = Object_wx_FileDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->ShowModal();
	return ReturnValue(env, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxFileDialog
//----------------------------------------------------------------------------
Object_wx_FileDialog::~Object_wx_FileDialog()
{
}

Object *Object_wx_FileDialog::Clone() const
{
	return nullptr;
}

String Object_wx_FileDialog::ToString(bool exprFlag)
{
	String rtn("<wx.FileDialog:");
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
// Class implementation for wxFileDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileDialog)
{
	Gura_AssignFunction(FileDialog);
	Gura_AssignMethod(wx_FileDialog, GetDirectory);
	Gura_AssignMethod(wx_FileDialog, GetFilename);
	Gura_AssignMethod(wx_FileDialog, GetFilenames);
	Gura_AssignMethod(wx_FileDialog, GetFilterIndex);
	Gura_AssignMethod(wx_FileDialog, GetMessage);
	Gura_AssignMethod(wx_FileDialog, GetPath);
	Gura_AssignMethod(wx_FileDialog, GetPaths);
	Gura_AssignMethod(wx_FileDialog, GetWildcard);
	Gura_AssignMethod(wx_FileDialog, SetDirectory);
	Gura_AssignMethod(wx_FileDialog, SetFilename);
	Gura_AssignMethod(wx_FileDialog, SetFilterIndex);
	Gura_AssignMethod(wx_FileDialog, SetMessage);
	Gura_AssignMethod(wx_FileDialog, SetPath);
	Gura_AssignMethod(wx_FileDialog, SetWildcard);
	Gura_AssignMethod(wx_FileDialog, ShowModal);
}

Gura_ImplementDescendantCreator(wx_FileDialog)
{
	return new Object_wx_FileDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
