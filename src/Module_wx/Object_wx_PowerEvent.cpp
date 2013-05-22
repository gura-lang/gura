//----------------------------------------------------------------------------
// wxPowerEvent
// extracted from powerevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_PowerEvent: public wxPowerEvent, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_PowerEvent *_pObj;
public:
	~wx_PowerEvent();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_PowerEvent *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_PowerEvent::~wx_PowerEvent()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_PowerEvent::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxPowerEvent
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_PowerEvent, Veto)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PowerEvent, Veto)
{
	Object_wx_PowerEvent *pThis = Object_wx_PowerEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Veto();
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxPowerEvent
//----------------------------------------------------------------------------
Object_wx_PowerEvent::~Object_wx_PowerEvent()
{
}

Object *Object_wx_PowerEvent::Clone() const
{
	return NULL;
}

String Object_wx_PowerEvent::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.PowerEvent:");
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
// Class implementation for wxPowerEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PowerEvent)
{
	Gura_AssignMethod(wx_PowerEvent, Veto);
}

Gura_ImplementDescendantCreator(wx_PowerEvent)
{
	return new Object_wx_PowerEvent((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
