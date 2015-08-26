//----------------------------------------------------------------------------
// wxIconizeEvent
// extracted from iconevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_IconizeEvent: public wxIconizeEvent, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_IconizeEvent *_pObj;
public:
	inline wx_IconizeEvent(int id, bool iconized) : wxIconizeEvent(id, iconized), _pObj(nullptr) {}
	~wx_IconizeEvent();
	inline void AssocWithGura(Object_wx_IconizeEvent *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_IconizeEvent::~wx_IconizeEvent()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_IconizeEvent::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxIconizeEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(IconizeEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_IconizeEvent));
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "iconized", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(IconizeEvent)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	int id = 0;
	if (args.IsValid(0)) id = args.GetInt(0);
	bool iconized = true;
	if (args.IsValid(1)) iconized = args.GetBoolean(1);
	wx_IconizeEvent *pEntity = new wx_IconizeEvent(id, iconized);
	Object_wx_IconizeEvent *pObj = Object_wx_IconizeEvent::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_IconizeEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareMethod(wx_IconizeEvent, Iconized)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_IconizeEvent, Iconized)
{
	Signal &sig = env.GetSignal();
	Object_wx_IconizeEvent *pThis = Object_wx_IconizeEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->Iconized();
	return ReturnValue(env, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxIconizeEvent
//----------------------------------------------------------------------------
Object_wx_IconizeEvent::~Object_wx_IconizeEvent()
{
}

Object *Object_wx_IconizeEvent::Clone() const
{
	return nullptr;
}

String Object_wx_IconizeEvent::ToString(bool exprFlag)
{
	String rtn("<wx.IconizeEvent:");
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
// Class implementation for wxIconizeEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_IconizeEvent)
{
	Gura_AssignFunction(IconizeEvent);
	Gura_AssignMethod(wx_IconizeEvent, Iconized);
}

Gura_ImplementDescendantCreator(wx_IconizeEvent)
{
	return new Object_wx_IconizeEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
