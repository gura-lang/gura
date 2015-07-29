//----------------------------------------------------------------------------
// wxFindReplaceDialog
// extracted from fdrepdlg.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_FindReplaceDialog: public wxFindReplaceDialog, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_FindReplaceDialog *_pObj;
public:
	inline wx_FindReplaceDialog() : wxFindReplaceDialog(), _pObj(nullptr) {}
	inline wx_FindReplaceDialog(wxWindow * parent, wxFindReplaceData* data, const wxString& title, int style) : wxFindReplaceDialog(parent, data, title, style), _pObj(nullptr) {}
	~wx_FindReplaceDialog();
	inline void AssocWithGura(Object_wx_FindReplaceDialog *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_FindReplaceDialog::~wx_FindReplaceDialog()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_FindReplaceDialog::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxFindReplaceDialog
//----------------------------------------------------------------------------
Gura_DeclareFunction(FindReplaceDialogEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_FindReplaceDialog));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FindReplaceDialogEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wx_FindReplaceDialog *pEntity = new wx_FindReplaceDialog();
	Object_wx_FindReplaceDialog *pObj = Object_wx_FindReplaceDialog::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_FindReplaceDialog(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareFunction(FindReplaceDialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_FindReplaceDialog));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "data", VTYPE_wx_FindReplaceData, OCCUR_Once);
	DeclareArg(env, "title", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(FindReplaceDialog)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *parent = args.IsValid(0)?
			Object_wx_Window::GetObject(args, 0)->GetEntity() : nullptr;
	wxFindReplaceData *data = Object_wx_FindReplaceData::GetObject(args, 1)->GetEntity();
	wxString title = wxString::FromUTF8(args.GetString(2));
	int style = 0;
	if (args.IsValid(3)) style = args.GetInt(3);
	wx_FindReplaceDialog *pEntity = new wx_FindReplaceDialog(parent, data, title, style);
	Object_wx_FindReplaceDialog *pObj = Object_wx_FindReplaceDialog::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_FindReplaceDialog(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_FindReplaceDialog, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "data", VTYPE_wx_FindReplaceData, OCCUR_Once);
	DeclareArg(env, "title", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FindReplaceDialog, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_FindReplaceDialog *pThis = Object_wx_FindReplaceDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *parent = args.IsValid(0)?
			Object_wx_Window::GetObject(args, 0)->GetEntity() : nullptr;
	wxFindReplaceData *data = Object_wx_FindReplaceData::GetObject(args, 1)->GetEntity();
	wxString title = wxString::FromUTF8(args.GetString(2));
	int style = 0;
	if (args.IsValid(3)) style = args.GetInt(3);
	bool rtn = pThis->GetEntity()->Create(parent, data, title, style);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_FindReplaceDialog, GetData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FindReplaceDialog, GetData)
{
	Signal &sig = env.GetSignal();
	Object_wx_FindReplaceDialog *pThis = Object_wx_FindReplaceDialog::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFindReplaceData *rtn = (wxFindReplaceData *)pThis->GetEntity()->GetData();
	return ReturnValue(env, args, Value(new Object_wx_FindReplaceData(rtn, nullptr, OwnerFalse)));
}

//----------------------------------------------------------------------------
// Object implementation for wxFindReplaceDialog
//----------------------------------------------------------------------------
Object_wx_FindReplaceDialog::~Object_wx_FindReplaceDialog()
{
}

Object *Object_wx_FindReplaceDialog::Clone() const
{
	return nullptr;
}

String Object_wx_FindReplaceDialog::ToString(bool exprFlag)
{
	String rtn("<wx.FindReplaceDialog:");
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
// Class implementation for wxFindReplaceDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FindReplaceDialog)
{
	Gura_AssignFunction(FindReplaceDialogEmpty);
	Gura_AssignFunction(FindReplaceDialog);
	Gura_AssignMethod(wx_FindReplaceDialog, Create);
	Gura_AssignMethod(wx_FindReplaceDialog, GetData);
}

Gura_ImplementDescendantCreator(wx_FindReplaceDialog)
{
	return new Object_wx_FindReplaceDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
