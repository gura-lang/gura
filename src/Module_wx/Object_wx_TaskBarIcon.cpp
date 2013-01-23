//----------------------------------------------------------------------------
// wxTaskBarIcon
// extracted from taskbar.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

Gura_DeclarePrivUserSymbol(CreatePopupMenu);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_TaskBarIcon: public wxTaskBarIcon, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_TaskBarIcon *_pObj;
public:
	inline wx_TaskBarIcon() : wxTaskBarIcon(), _sig(NULL), _pObj(NULL) {}
	//virtual wxMenu* CreatePopupMenu();
	~wx_TaskBarIcon();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_TaskBarIcon *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_TaskBarIcon::~wx_TaskBarIcon()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_TaskBarIcon::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxTaskBarIcon
//----------------------------------------------------------------------------
Gura_DeclareFunction(TaskBarIconEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_TaskBarIcon));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(TaskBarIconEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_TaskBarIcon *pEntity = new wx_TaskBarIcon();
	Object_wx_TaskBarIcon *pObj = Object_wx_TaskBarIcon::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_TaskBarIcon(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_TaskBarIcon, CreatePopupMenu)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TaskBarIcon, CreatePopupMenu)
{
#if 0
	Object_wx_TaskBarIcon *pSelf = Object_wx_TaskBarIcon::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxMenu *rtn = (wxMenu *)pSelf->GetEntity()->CreatePopupMenu();
	return ReturnValue(env, sig, args, Value(new Object_wx_Menu(rtn, NULL, OwnerFalse)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_TaskBarIcon, IsIconInstalled)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TaskBarIcon, IsIconInstalled)
{
	Object_wx_TaskBarIcon *pSelf = Object_wx_TaskBarIcon::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsIconInstalled();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TaskBarIcon, IsOk)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TaskBarIcon, IsOk)
{
	Object_wx_TaskBarIcon *pSelf = Object_wx_TaskBarIcon::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsOk();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TaskBarIcon, PopupMenu)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "menu", VTYPE_wx_Menu, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TaskBarIcon, PopupMenu)
{
	Object_wx_TaskBarIcon *pSelf = Object_wx_TaskBarIcon::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxMenu *menu = Object_wx_Menu::GetObject(args, 0)->GetEntity();
	bool rtn = pSelf->GetEntity()->PopupMenu(menu);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TaskBarIcon, RemoveIcon)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TaskBarIcon, RemoveIcon)
{
	Object_wx_TaskBarIcon *pSelf = Object_wx_TaskBarIcon::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->RemoveIcon();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TaskBarIcon, SetIcon)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "icon", VTYPE_wx_Icon, OCCUR_Once);
	DeclareArg(env, "tooltip", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TaskBarIcon, SetIcon)
{
	Object_wx_TaskBarIcon *pSelf = Object_wx_TaskBarIcon::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxIcon *icon = Object_wx_Icon::GetObject(args, 0)->GetEntity();
	wxString tooltip = wxString::FromUTF8(args.GetString(1));
	bool rtn = pSelf->GetEntity()->SetIcon(*icon, tooltip);
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxTaskBarIcon
//----------------------------------------------------------------------------
Object_wx_TaskBarIcon::~Object_wx_TaskBarIcon()
{
}

Object *Object_wx_TaskBarIcon::Clone() const
{
	return NULL;
}

String Object_wx_TaskBarIcon::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.TaskBarIcon:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_TaskBarIcon::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_RealizeUserSymbol(CreatePopupMenu);
	Gura_AssignFunction(TaskBarIconEmpty);
}

//----------------------------------------------------------------------------
// Class implementation for wxTaskBarIcon
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TaskBarIcon)
{
	Gura_AssignMethod(wx_TaskBarIcon, CreatePopupMenu);
	Gura_AssignMethod(wx_TaskBarIcon, IsIconInstalled);
	Gura_AssignMethod(wx_TaskBarIcon, IsOk);
	Gura_AssignMethod(wx_TaskBarIcon, PopupMenu);
	Gura_AssignMethod(wx_TaskBarIcon, RemoveIcon);
	Gura_AssignMethod(wx_TaskBarIcon, SetIcon);
}

Gura_ImplementDescendantCreator(wx_TaskBarIcon)
{
	return new Object_wx_TaskBarIcon((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
