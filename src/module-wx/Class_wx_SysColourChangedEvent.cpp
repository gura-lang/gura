//----------------------------------------------------------------------------
// wxSysColourChangedEvent
// extracted from sysclevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_SysColourChangedEvent: public wxSysColourChangedEvent, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_SysColourChangedEvent *_pObj;
public:
	inline wx_SysColourChangedEvent() : wxSysColourChangedEvent(), _pObj(nullptr) {}
	~wx_SysColourChangedEvent();
	inline void AssocWithGura(Object_wx_SysColourChangedEvent *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_SysColourChangedEvent::~wx_SysColourChangedEvent()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_SysColourChangedEvent::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxSysColourChangedEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(SysColourChangedEventEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_SysColourChangedEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(SysColourChangedEventEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_SysColourChangedEvent *pEntity = new wx_SysColourChangedEvent();
	Object_wx_SysColourChangedEvent *pObj = Object_wx_SysColourChangedEvent::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_SysColourChangedEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxSysColourChangedEvent
//----------------------------------------------------------------------------
Object_wx_SysColourChangedEvent::~Object_wx_SysColourChangedEvent()
{
}

Object *Object_wx_SysColourChangedEvent::Clone() const
{
	return nullptr;
}

String Object_wx_SysColourChangedEvent::ToString(bool exprFlag)
{
	String rtn("<wx.SysColourChangedEvent:");
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
// Class implementation for wxSysColourChangedEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SysColourChangedEvent)
{
	Gura_AssignFunction(SysColourChangedEventEmpty);
}

Gura_ImplementDescendantCreator(wx_SysColourChangedEvent)
{
	return new Object_wx_SysColourChangedEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
