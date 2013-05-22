//----------------------------------------------------------------------------
// wxTimerEvent
// extracted from timer.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_TimerEvent: public wxTimerEvent, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_TimerEvent *_pObj;
public:
	~wx_TimerEvent();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_TimerEvent *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_TimerEvent::~wx_TimerEvent()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_TimerEvent::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxTimerEvent
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_TimerEvent, GetInterval)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TimerEvent, GetInterval)
{
	Object_wx_TimerEvent *pThis = Object_wx_TimerEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetInterval();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxTimerEvent
//----------------------------------------------------------------------------
Object_wx_TimerEvent::~Object_wx_TimerEvent()
{
}

Object *Object_wx_TimerEvent::Clone() const
{
	return NULL;
}

String Object_wx_TimerEvent::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.TimerEvent:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

//----------------------------------------------------------------------------
// Class implementation for wxTimerEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TimerEvent)
{
	Gura_AssignMethod(wx_TimerEvent, GetInterval);
}

Gura_ImplementDescendantCreator(wx_TimerEvent)
{
	return new Object_wx_TimerEvent((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
