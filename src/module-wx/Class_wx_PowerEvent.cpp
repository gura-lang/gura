//----------------------------------------------------------------------------
// wxPowerEvent
// extracted from powerevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_PowerEvent: public wxPowerEvent, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_PowerEvent *_pObj;
public:
	~wx_PowerEvent();
	inline void AssocWithGura(Object_wx_PowerEvent *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_PowerEvent::~wx_PowerEvent()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_PowerEvent::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxPowerEvent
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_PowerEvent, Veto)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PowerEvent, Veto)
{
	Signal &sig = env.GetSignal();
	Object_wx_PowerEvent *pThis = Object_wx_PowerEvent::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Veto();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxPowerEvent
//----------------------------------------------------------------------------
Object_wx_PowerEvent::~Object_wx_PowerEvent()
{
}

Object *Object_wx_PowerEvent::Clone() const
{
	return nullptr;
}

String Object_wx_PowerEvent::ToString(bool exprFlag)
{
	String rtn("<wx.PowerEvent:");
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
// Class implementation for wxPowerEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PowerEvent)
{
	Gura_AssignMethod(wx_PowerEvent, Veto);
}

Gura_ImplementDescendantCreator(wx_PowerEvent)
{
	return new Object_wx_PowerEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
