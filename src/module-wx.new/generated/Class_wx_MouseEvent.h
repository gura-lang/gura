//----------------------------------------------------------------------------
// wxMouseEvent
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_MOUSEEVENT_H__
#define __CLASS_WX_MOUSEEVENT_H__
#include <wx/event.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxMouseEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_MouseEvent);

//----------------------------------------------------------------------------
// Object declaration for wxMouseEvent
//----------------------------------------------------------------------------
class Object_wx_MouseEvent : public Object_wx_Event {
public:
	Gura_DeclareObjectAccessor(wx_MouseEvent)
public:
	inline Object_wx_MouseEvent(wxMouseEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(Gura_UserClass(wx_MouseEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_MouseEvent(Class *pClass, wxMouseEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_MouseEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxMouseEvent *GetEntity() {
		return static_cast<wxMouseEvent *>(_pEntity);
	}
	inline wxMouseEvent *ReleaseEntity() {
		wxMouseEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxMouseEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
