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
	//Gura::Signal *_pSig;
	Object_wx_ToolbookEvent *_pObj;
public:
	inline wx_ToolbookEvent(wxEventType eventType, int id, int sel, int oldSel) : wxToolbookEvent(eventType, id, sel, oldSel), _pObj(nullptr) {}
	~wx_ToolbookEvent();
	inline void AssocWithGura(Object_wx_ToolbookEvent *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ToolbookEvent::~wx_ToolbookEvent()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_ToolbookEvent::GuraObjectDeleted()
{
	_pObj = nullptr;
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
	return nullptr;
}

String Object_wx_ToolbookEvent::ToString(bool exprFlag)
{
	String rtn("<wx.ToolbookEvent:");
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
// Class implementation for wxToolbookEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ToolbookEvent)
{
}

Gura_ImplementDescendantCreator(wx_ToolbookEvent)
{
	return new Object_wx_ToolbookEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
