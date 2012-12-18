//----------------------------------------------------------------------------
// wxFindReplaceDialog
// extracted from fdrepdlg.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_FindReplaceDialog: public wxFindReplaceDialog, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_FindReplaceDialog *_pObj;
public:
	inline wx_FindReplaceDialog() : wxFindReplaceDialog(), _sig(NULL), _pObj(NULL) {}
	inline wx_FindReplaceDialog(wxWindow * parent, wxFindReplaceData* data, const wxString& title, int style) : wxFindReplaceDialog(parent, data, title, style), _sig(NULL), _pObj(NULL) {}
	~wx_FindReplaceDialog();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_FindReplaceDialog *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_FindReplaceDialog::~wx_FindReplaceDialog()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_FindReplaceDialog::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxFindReplaceDialog
//----------------------------------------------------------------------------
Gura_DeclareFunction(FindReplaceDialogEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_FindReplaceDialog));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FindReplaceDialogEmpty)
{
	wx_FindReplaceDialog *pEntity = new wx_FindReplaceDialog();
	Object_wx_FindReplaceDialog *pObj = Object_wx_FindReplaceDialog::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_FindReplaceDialog(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareFunction(FindReplaceDialog)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_FindReplaceDialog));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "data", VTYPE_wx_FindReplaceData, OCCUR_Once);
	DeclareArg(env, "title", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FindReplaceDialog)
{
	wxWindow *parent = args.IsValid(0)?
			Object_wx_Window::GetObject(args, 0)->GetEntity() : NULL;
	wxFindReplaceData *data = Object_wx_FindReplaceData::GetObject(args, 1)->GetEntity();
	wxString title = wxString::FromUTF8(args.GetString(2));
	int style = 0;
	if (args.IsValid(3)) style = args.GetInt(3);
	wx_FindReplaceDialog *pEntity = new wx_FindReplaceDialog(parent, data, title, style);
	Object_wx_FindReplaceDialog *pObj = Object_wx_FindReplaceDialog::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_FindReplaceDialog(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_FindReplaceDialog, Create)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "data", VTYPE_wx_FindReplaceData, OCCUR_Once);
	DeclareArg(env, "title", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FindReplaceDialog, Create)
{
	Object_wx_FindReplaceDialog *pSelf = Object_wx_FindReplaceDialog::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxWindow *parent = args.IsValid(0)?
			Object_wx_Window::GetObject(args, 0)->GetEntity() : NULL;
	wxFindReplaceData *data = Object_wx_FindReplaceData::GetObject(args, 1)->GetEntity();
	wxString title = wxString::FromUTF8(args.GetString(2));
	int style = 0;
	if (args.IsValid(3)) style = args.GetInt(3);
	bool rtn = pSelf->GetEntity()->Create(parent, data, title, style);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_FindReplaceDialog, GetData)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FindReplaceDialog, GetData)
{
	Object_wx_FindReplaceDialog *pSelf = Object_wx_FindReplaceDialog::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxFindReplaceData *rtn = (wxFindReplaceData *)pSelf->GetEntity()->GetData();
	return ReturnValue(env, sig, args, Value(new Object_wx_FindReplaceData(rtn, NULL, OwnerFalse)));
}

//----------------------------------------------------------------------------
// Object implementation for wxFindReplaceDialog
//----------------------------------------------------------------------------
Object_wx_FindReplaceDialog::~Object_wx_FindReplaceDialog()
{
}

Object *Object_wx_FindReplaceDialog::Clone() const
{
	return NULL;
}

String Object_wx_FindReplaceDialog::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.FindReplaceDialog:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_FindReplaceDialog::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(FindReplaceDialogEmpty);
	Gura_AssignFunction(FindReplaceDialog);
}

//----------------------------------------------------------------------------
// Class implementation for wxFindReplaceDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FindReplaceDialog)
{
	Gura_AssignMethod(wx_FindReplaceDialog, Create);
	Gura_AssignMethod(wx_FindReplaceDialog, GetData);
}

Gura_ImplementDescendantCreator(wx_FindReplaceDialog)
{
	return new Object_wx_FindReplaceDialog((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
