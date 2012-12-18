//----------------------------------------------------------------------------
// wxListbookEvent
// (hand-coded)
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ListbookEvent: public wxListbookEvent, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_ListbookEvent *_pObj;
public:
	inline wx_ListbookEvent(wxEventType eventType, int id, int sel, int oldSel) : wxListbookEvent(eventType, id, sel, oldSel), _sig(NULL), _pObj(NULL) {}
	~wx_ListbookEvent();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ListbookEvent *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ListbookEvent::~wx_ListbookEvent()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_ListbookEvent::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxListbookEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxListbookEvent
//----------------------------------------------------------------------------
Object_wx_ListbookEvent::~Object_wx_ListbookEvent()
{
}

Object *Object_wx_ListbookEvent::Clone() const
{
	return NULL;
}

String Object_wx_ListbookEvent::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.ListbookEvent:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_ListbookEvent::OnModuleEntry(Environment &env, Signal sig)
{
}

//----------------------------------------------------------------------------
// Class implementation for wxListbookEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ListbookEvent)
{
}

Gura_ImplementDescendantCreator(wx_ListbookEvent)
{
	return new Object_wx_ListbookEvent((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
