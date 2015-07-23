//----------------------------------------------------------------------------
// wxMenuEvent
// extracted from menuevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_MenuEvent: public wxMenuEvent, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_MenuEvent *_pObj;
public:
	inline wx_MenuEvent(WXTYPE type, int id, wxMenu* menu) : wxMenuEvent(type, id, menu), _pObj(nullptr) {}
	~wx_MenuEvent();
	inline void AssocWithGura(Object_wx_MenuEvent *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_MenuEvent::~wx_MenuEvent()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_MenuEvent::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxMenuEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(MenuEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_MenuEvent));
	DeclareArg(env, "type", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "menu", VTYPE_wx_Menu, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(MenuEvent)
{
	if (!CheckWxReady(sig)) return Value::Null;
	WXTYPE type = 0;
	if (args.IsValid(0)) type = static_cast<WXTYPE>(args.GetInt(0));
	int id = 0;
	if (args.IsValid(1)) id = args.GetInt(1);
	wxMenu *menu = (wxMenu *)(nullptr);
	if (args.IsValid(2)) menu = Object_wx_Menu::GetObject(args, 2)->GetEntity();
	wx_MenuEvent *pEntity = new wx_MenuEvent(type, id, menu);
	Object_wx_MenuEvent *pObj = Object_wx_MenuEvent::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_MenuEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_MenuEvent, GetMenu)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MenuEvent, GetMenu)
{
	Object_wx_MenuEvent *pThis = Object_wx_MenuEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxMenu *rtn = (wxMenu *)pThis->GetEntity()->GetMenu();
	return ReturnValue(env, args, Value(new Object_wx_Menu(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_MenuEvent, GetMenuId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MenuEvent, GetMenuId)
{
	Object_wx_MenuEvent *pThis = Object_wx_MenuEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetMenuId();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_MenuEvent, IsPopup)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MenuEvent, IsPopup)
{
	Object_wx_MenuEvent *pThis = Object_wx_MenuEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsPopup();
	return ReturnValue(env, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxMenuEvent
//----------------------------------------------------------------------------
Object_wx_MenuEvent::~Object_wx_MenuEvent()
{
}

Object *Object_wx_MenuEvent::Clone() const
{
	return nullptr;
}

String Object_wx_MenuEvent::ToString(bool exprFlag)
{
	String rtn("<wx.MenuEvent:");
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
// Class implementation for wxMenuEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MenuEvent)
{
	Gura_AssignFunction(MenuEvent);
	Gura_AssignMethod(wx_MenuEvent, GetMenu);
	Gura_AssignMethod(wx_MenuEvent, GetMenuId);
	Gura_AssignMethod(wx_MenuEvent, IsPopup);
}

Gura_ImplementDescendantCreator(wx_MenuEvent)
{
	return new Object_wx_MenuEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
