//----------------------------------------------------------------------------
// wxListbookEvent
// (hand-coded)
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ListbookEvent: public wxListbookEvent, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_ListbookEvent *_pObj;
public:
	inline wx_ListbookEvent(wxEventType eventType, int id, int sel, int oldSel) : wxListbookEvent(eventType, id, sel, oldSel), _pObj(nullptr) {}
	~wx_ListbookEvent();
	inline void AssocWithGura(Object_wx_ListbookEvent *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ListbookEvent::~wx_ListbookEvent()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_ListbookEvent::GuraObjectDeleted()
{
	_pObj = nullptr;
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
	return nullptr;
}

String Object_wx_ListbookEvent::ToString(bool exprFlag)
{
	String rtn("<wx.ListbookEvent:");
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
// Class implementation for wxListbookEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ListbookEvent)
{
}

Gura_ImplementDescendantCreator(wx_ListbookEvent)
{
	return new Object_wx_ListbookEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
