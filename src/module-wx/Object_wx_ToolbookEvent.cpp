//----------------------------------------------------------------------------
// wxToolbookEvent
// (hand-coded)
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ToolbookEvent: public wxToolbookEvent, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_ToolbookEvent *_pObj;
public:
	inline wx_ToolbookEvent(wxEventType eventType, int id, int sel, int oldSel) : wxToolbookEvent(eventType, id, sel, oldSel), _sig(NULL), _pObj(NULL) {}
	~wx_ToolbookEvent();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ToolbookEvent *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ToolbookEvent::~wx_ToolbookEvent()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_ToolbookEvent::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxToolbookEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxToolbookEvent
//----------------------------------------------------------------------------
Object_wx_ToolbookEvent::~Object_wx_ToolbookEvent()
{
}

Object *Object_wx_ToolbookEvent::Clone() const
{
	return NULL;
}

String Object_wx_ToolbookEvent::ToString(bool exprFlag)
{
	String rtn("<wx.ToolbookEvent:");
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
// Class implementation for wxToolbookEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ToolbookEvent)
{
}

Gura_ImplementDescendantCreator(wx_ToolbookEvent)
{
	return new Object_wx_ToolbookEvent((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
