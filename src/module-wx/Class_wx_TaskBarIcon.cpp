//----------------------------------------------------------------------------
// wxTaskBarIcon
// extracted from taskbar.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(CreatePopupMenu);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_TaskBarIcon: public wxTaskBarIcon, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_TaskBarIcon *_pObj;
public:
	inline wx_TaskBarIcon() : wxTaskBarIcon(), _pObj(nullptr) {}
	//virtual wxMenu* CreatePopupMenu();
	~wx_TaskBarIcon();
	inline void AssocWithGura(Object_wx_TaskBarIcon *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_TaskBarIcon::~wx_TaskBarIcon()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_TaskBarIcon::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxTaskBarIcon
//----------------------------------------------------------------------------
Gura_DeclareFunction(TaskBarIconEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_TaskBarIcon));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(TaskBarIconEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_TaskBarIcon *pEntity = new wx_TaskBarIcon();
	Object_wx_TaskBarIcon *pObj = Object_wx_TaskBarIcon::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_TaskBarIcon(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareMethod(wx_TaskBarIcon, CreatePopupMenu)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TaskBarIcon, CreatePopupMenu)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_TaskBarIcon *pThis = Object_wx_TaskBarIcon::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxMenu *rtn = (wxMenu *)pThis->GetEntity()->CreatePopupMenu();
	return ReturnValue(env, args, Value(new Object_wx_Menu(rtn, nullptr, OwnerFalse)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TaskBarIcon, IsIconInstalled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TaskBarIcon, IsIconInstalled)
{
	Signal &sig = env.GetSignal();
	Object_wx_TaskBarIcon *pThis = Object_wx_TaskBarIcon::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsIconInstalled();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TaskBarIcon, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TaskBarIcon, IsOk)
{
	Signal &sig = env.GetSignal();
	Object_wx_TaskBarIcon *pThis = Object_wx_TaskBarIcon::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsOk();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TaskBarIcon, PopupMenu)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "menu", VTYPE_wx_Menu, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TaskBarIcon, PopupMenu)
{
	Signal &sig = env.GetSignal();
	Object_wx_TaskBarIcon *pThis = Object_wx_TaskBarIcon::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxMenu *menu = Object_wx_Menu::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->PopupMenu(menu);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TaskBarIcon, RemoveIcon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TaskBarIcon, RemoveIcon)
{
	Signal &sig = env.GetSignal();
	Object_wx_TaskBarIcon *pThis = Object_wx_TaskBarIcon::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->RemoveIcon();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TaskBarIcon, SetIcon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "icon", VTYPE_wx_Icon, OCCUR_Once);
	DeclareArg(env, "tooltip", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TaskBarIcon, SetIcon)
{
	Signal &sig = env.GetSignal();
	Object_wx_TaskBarIcon *pThis = Object_wx_TaskBarIcon::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxIcon *icon = Object_wx_Icon::GetObject(args, 0)->GetEntity();
	wxString tooltip = wxString::FromUTF8(args.GetString(1));
	bool rtn = pThis->GetEntity()->SetIcon(*icon, tooltip);
	return ReturnValue(env, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxTaskBarIcon
//----------------------------------------------------------------------------
Object_wx_TaskBarIcon::~Object_wx_TaskBarIcon()
{
}

Object *Object_wx_TaskBarIcon::Clone() const
{
	return nullptr;
}

String Object_wx_TaskBarIcon::ToString(bool exprFlag)
{
	String rtn("<wx.TaskBarIcon:");
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
// Class implementation for wxTaskBarIcon
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TaskBarIcon)
{
	Gura_RealizeUserSymbol(CreatePopupMenu);
	Gura_AssignFunction(TaskBarIconEmpty);
	Gura_AssignMethod(wx_TaskBarIcon, CreatePopupMenu);
	Gura_AssignMethod(wx_TaskBarIcon, IsIconInstalled);
	Gura_AssignMethod(wx_TaskBarIcon, IsOk);
	Gura_AssignMethod(wx_TaskBarIcon, PopupMenu);
	Gura_AssignMethod(wx_TaskBarIcon, RemoveIcon);
	Gura_AssignMethod(wx_TaskBarIcon, SetIcon);
}

Gura_ImplementDescendantCreator(wx_TaskBarIcon)
{
	return new Object_wx_TaskBarIcon((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
