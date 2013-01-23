//----------------------------------------------------------------------------
// wxDialog
// extracted from dialog.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

Gura_DeclarePrivUserSymbol(DoOK);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Dialog: public wxDialog, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_Dialog *_pObj;
public:
	inline wx_Dialog() : wxDialog(), _sig(NULL), _pObj(NULL) {}
	inline wx_Dialog(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style, const wxString& name) : wxDialog(parent, id, title, pos, size, style, name), _sig(NULL), _pObj(NULL) {}
	//virtual bool DoOK();
	~wx_Dialog();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_Dialog *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Dialog::~wx_Dialog()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_Dialog::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDialog
//----------------------------------------------------------------------------
Gura_DeclareFunction(DialogEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Dialog));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DialogEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_Dialog *pEntity = new wx_Dialog();
	Object_wx_Dialog *pObj = Object_wx_Dialog::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Dialog(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareFunction(Dialog)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Dialog));
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "title", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Dialog)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *parent = args.IsValid(0)?
			Object_wx_Window::GetObject(args, 0)->GetEntity() : NULL;
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxString title = wxString::FromUTF8(args.GetString(2));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(3)) pos = Object_wx_Point::GetObject(args, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(4)) size = Object_wx_Size::GetObject(args, 4)->GetEntity();
	long style = wxDEFAULT_DIALOG_STYLE;
	if (args.IsValid(5)) style = args.GetLong(5);
	wxString name = wxT("dialogBox");
	if (args.IsValid(6)) name = wxString::FromUTF8(args.GetString(6));
	wx_Dialog *pEntity = new wx_Dialog(parent, id, title, *pos, *size, style, name);
	Object_wx_Dialog *pObj = Object_wx_Dialog::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Dialog(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_Dialog, Centre)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "direction", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dialog, Centre)
{
	Object_wx_Dialog *pSelf = Object_wx_Dialog::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int direction = wxBOTH;
	if (args.IsValid(0)) direction = args.GetInt(0);
	pSelf->GetEntity()->Centre(direction);
	return Value::Null;
}

Gura_DeclareMethod(wx_Dialog, Create)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "parent", VTYPE_wx_Window, OCCUR_Once, FLAG_Nil);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "title", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dialog, Create)
{
	Object_wx_Dialog *pSelf = Object_wx_Dialog::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxWindow *parent = args.IsValid(0)?
			Object_wx_Window::GetObject(args, 0)->GetEntity() : NULL;
	wxWindowID id = static_cast<wxWindowID>(args.GetInt(1));
	wxString title = wxString::FromUTF8(args.GetString(2));
	wxPoint *pos = (wxPoint *)(&wxDefaultPosition);
	if (args.IsValid(3)) pos = Object_wx_Point::GetObject(args, 3)->GetEntity();
	wxSize *size = (wxSize *)(&wxDefaultSize);
	if (args.IsValid(4)) size = Object_wx_Size::GetObject(args, 4)->GetEntity();
	long style = wxDEFAULT_DIALOG_STYLE;
	if (args.IsValid(5)) style = args.GetLong(5);
	wxString name = wxT("dialogBox");
	if (args.IsValid(6)) name = wxString::FromUTF8(args.GetString(6));
	bool rtn = pSelf->GetEntity()->Create(parent, id, title, *pos, *size, style, name);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Dialog, CreateButtonSizer)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dialog, CreateButtonSizer)
{
	Object_wx_Dialog *pSelf = Object_wx_Dialog::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long flags = args.GetLong(0);
	wxSizer *rtn = (wxSizer *)pSelf->GetEntity()->CreateButtonSizer(flags);
	return ReturnValue(env, sig, args, Value(new Object_wx_Sizer(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_Dialog, CreateSeparatedButtonSizer)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dialog, CreateSeparatedButtonSizer)
{
	Object_wx_Dialog *pSelf = Object_wx_Dialog::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long flags = args.GetLong(0);
	wxSizer *rtn = (wxSizer *)pSelf->GetEntity()->CreateSeparatedButtonSizer(flags);
	return ReturnValue(env, sig, args, Value(new Object_wx_Sizer(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_Dialog, CreateStdDialogButtonSizer)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dialog, CreateStdDialogButtonSizer)
{
	Object_wx_Dialog *pSelf = Object_wx_Dialog::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long flags = args.GetLong(0);
	wxStdDialogButtonSizer *rtn = (wxStdDialogButtonSizer *)pSelf->GetEntity()->CreateStdDialogButtonSizer(flags);
	return ReturnValue(env, sig, args, Value(new Object_wx_StdDialogButtonSizer(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_Dialog, DoOK)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dialog, DoOK)
{
#if 0
	Object_wx_Dialog *pSelf = Object_wx_Dialog::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->DoOK();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Dialog, EndModal)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "retCode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, EndModal)
{
	Object_wx_Dialog *pSelf = Object_wx_Dialog::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int retCode = args.GetInt(0);
	pSelf->GetEntity()->EndModal(retCode);
	return Value::Null;
}

Gura_DeclareMethod(wx_Dialog, GetAffirmativeId)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dialog, GetAffirmativeId)
{
	Object_wx_Dialog *pSelf = Object_wx_Dialog::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetAffirmativeId();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Dialog, GetEscapeId)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dialog, GetEscapeId)
{
	Object_wx_Dialog *pSelf = Object_wx_Dialog::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetEscapeId();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Dialog, GetReturnCode)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dialog, GetReturnCode)
{
	Object_wx_Dialog *pSelf = Object_wx_Dialog::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetReturnCode();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Dialog, GetToolBar)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dialog, GetToolBar)
{
#if 0
	Object_wx_Dialog *pSelf = Object_wx_Dialog::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxToolBar *rtn = (wxToolBar *)pSelf->GetEntity()->GetToolBar();
	return ReturnValue(env, sig, args, Value(new Object_wx_ToolBar(rtn, NULL, OwnerFalse)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Dialog, Iconize)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "iconize", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, Iconize)
{
	Object_wx_Dialog *pSelf = Object_wx_Dialog::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool iconize = args.GetBoolean(0);
	pSelf->GetEntity()->Iconize(iconize);
	return Value::Null;
}

Gura_DeclareMethod(wx_Dialog, IsIconized)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dialog, IsIconized)
{
	Object_wx_Dialog *pSelf = Object_wx_Dialog::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsIconized();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Dialog, IsModal)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dialog, IsModal)
{
	Object_wx_Dialog *pSelf = Object_wx_Dialog::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsModal();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Dialog, OnSysColourChanged)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "event", VTYPE_wx_SysColourChangedEvent, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_Dialog, OnSysColourChanged)
{
#if 0
	Object_wx_Dialog *pSelf = Object_wx_Dialog::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxSysColourChangedEvent *event = Object_wx_SysColourChangedEvent::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->OnSysColourChanged(*event);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_Dialog, SetAffirmativeId)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, SetAffirmativeId)
{
	Object_wx_Dialog *pSelf = Object_wx_Dialog::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int id = args.GetInt(0);
	pSelf->GetEntity()->SetAffirmativeId(id);
	return Value::Null;
}

Gura_DeclareMethod(wx_Dialog, SetEscapeId)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, SetEscapeId)
{
	Object_wx_Dialog *pSelf = Object_wx_Dialog::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int id = args.GetInt(0);
	pSelf->GetEntity()->SetEscapeId(id);
	return Value::Null;
}

Gura_DeclareMethod(wx_Dialog, SetIcon)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "icon", VTYPE_wx_Icon, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, SetIcon)
{
	Object_wx_Dialog *pSelf = Object_wx_Dialog::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxIcon *icon = Object_wx_Icon::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetIcon(*icon);
	return Value::Null;
}

Gura_DeclareMethod(wx_Dialog, SetIcons)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "icons", VTYPE_wx_IconBundle, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, SetIcons)
{
	Object_wx_Dialog *pSelf = Object_wx_Dialog::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxIconBundle *icons = Object_wx_IconBundle::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetIcons(*icons);
	return Value::Null;
}

Gura_DeclareMethod(wx_Dialog, SetModal)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "flag", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, SetModal)
{
	Object_wx_Dialog *pSelf = Object_wx_Dialog::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool flag = args.GetBoolean(0);
	pSelf->GetEntity()->SetModal(flag);
	return Value::Null;
}

Gura_DeclareMethod(wx_Dialog, SetReturnCode)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "retCode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, SetReturnCode)
{
	Object_wx_Dialog *pSelf = Object_wx_Dialog::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int retCode = args.GetInt(0);
	pSelf->GetEntity()->SetReturnCode(retCode);
	return Value::Null;
}

Gura_DeclareMethod(wx_Dialog, Show)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "show", VTYPE_boolean, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dialog, Show)
{
	Object_wx_Dialog *pSelf = Object_wx_Dialog::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool show = args.GetBoolean(0);
	bool rtn = pSelf->GetEntity()->Show(show);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Dialog, ShowModal)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Dialog, ShowModal)
{
	Object_wx_Dialog *pSelf = Object_wx_Dialog::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->ShowModal();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxDialog
//----------------------------------------------------------------------------
Object_wx_Dialog::~Object_wx_Dialog()
{
}

Object *Object_wx_Dialog::Clone() const
{
	return NULL;
}

String Object_wx_Dialog::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.Dialog:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_Dialog::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_RealizeUserSymbol(DoOK);
	Gura_AssignFunction(DialogEmpty);
	Gura_AssignFunction(Dialog);
}

//----------------------------------------------------------------------------
// Class implementation for wxDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Dialog)
{
	Gura_AssignMethod(wx_Dialog, Centre);
	Gura_AssignMethod(wx_Dialog, Create);
	Gura_AssignMethod(wx_Dialog, CreateButtonSizer);
	Gura_AssignMethod(wx_Dialog, CreateSeparatedButtonSizer);
	Gura_AssignMethod(wx_Dialog, CreateStdDialogButtonSizer);
	Gura_AssignMethod(wx_Dialog, DoOK);
	Gura_AssignMethod(wx_Dialog, EndModal);
	Gura_AssignMethod(wx_Dialog, GetAffirmativeId);
	Gura_AssignMethod(wx_Dialog, GetEscapeId);
	Gura_AssignMethod(wx_Dialog, GetReturnCode);
	Gura_AssignMethod(wx_Dialog, GetToolBar);
	Gura_AssignMethod(wx_Dialog, Iconize);
	Gura_AssignMethod(wx_Dialog, IsIconized);
	Gura_AssignMethod(wx_Dialog, IsModal);
	Gura_AssignMethod(wx_Dialog, OnSysColourChanged);
	Gura_AssignMethod(wx_Dialog, SetAffirmativeId);
	Gura_AssignMethod(wx_Dialog, SetEscapeId);
	Gura_AssignMethod(wx_Dialog, SetIcon);
	Gura_AssignMethod(wx_Dialog, SetIcons);
	Gura_AssignMethod(wx_Dialog, SetModal);
	Gura_AssignMethod(wx_Dialog, SetReturnCode);
	Gura_AssignMethod(wx_Dialog, Show);
	Gura_AssignMethod(wx_Dialog, ShowModal);
}

Gura_ImplementDescendantCreator(wx_Dialog)
{
	return new Object_wx_Dialog((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
