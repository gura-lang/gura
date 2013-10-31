//----------------------------------------------------------------------------
// wxMediaEvent
// extracted from mediaevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_MediaEvent: public wxMediaEvent, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_MediaEvent *_pObj;
public:
	~wx_MediaEvent();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_MediaEvent *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_MediaEvent::~wx_MediaEvent()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_MediaEvent::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxMediaEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMediaEvent
//----------------------------------------------------------------------------
Object_wx_MediaEvent::~Object_wx_MediaEvent()
{
}

Object *Object_wx_MediaEvent::Clone() const
{
	return NULL;
}

String Object_wx_MediaEvent::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.MediaEvent:");
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
// Class implementation for wxMediaEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MediaEvent)
{
}

Gura_ImplementDescendantCreator(wx_MediaEvent)
{
	return new Object_wx_MediaEvent((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
