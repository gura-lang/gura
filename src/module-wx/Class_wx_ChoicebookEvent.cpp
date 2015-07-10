//----------------------------------------------------------------------------
// wxChoicebookEvent
// (hand-coded)
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ChoicebookEvent: public wxChoicebookEvent, public GuraObjectObserver {
private:
	Gura::Signal *_pSig;
	Object_wx_ChoicebookEvent *_pObj;
public:
	inline wx_ChoicebookEvent(wxEventType eventType, int id, int sel, int oldSel) : wxChoicebookEvent(eventType, id, sel, oldSel), _pSig(nullptr), _pObj(nullptr) {}
	~wx_ChoicebookEvent();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ChoicebookEvent *pObj) {
		_pSig = &sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ChoicebookEvent::~wx_ChoicebookEvent()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_ChoicebookEvent::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxChoicebookEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxChoicebookEvent
//----------------------------------------------------------------------------
Object_wx_ChoicebookEvent::~Object_wx_ChoicebookEvent()
{
}

Object *Object_wx_ChoicebookEvent::Clone() const
{
	return nullptr;
}

String Object_wx_ChoicebookEvent::ToString(bool exprFlag)
{
	String rtn("<wx.ChoicebookEvent:");
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
// Class implementation for wxChoicebookEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ChoicebookEvent)
{
}

Gura_ImplementDescendantCreator(wx_ChoicebookEvent)
{
	return new Object_wx_ChoicebookEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
