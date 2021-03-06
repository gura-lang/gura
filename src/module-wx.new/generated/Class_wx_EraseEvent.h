//----------------------------------------------------------------------------
// wxEraseEvent
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_ERASEEVENT_H__
#define __CLASS_WX_ERASEEVENT_H__
#include <wx/event.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxEraseEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_EraseEvent);

//----------------------------------------------------------------------------
// Object declaration for wxEraseEvent
//----------------------------------------------------------------------------
class Object_wx_EraseEvent : public Object_wx_Event {
public:
	Gura_DeclareObjectAccessor(wx_EraseEvent)
public:
	inline Object_wx_EraseEvent(wxEraseEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(Gura_UserClass(wx_EraseEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_EraseEvent(Class *pClass, wxEraseEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_EraseEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxEraseEvent *GetEntity() {
		return static_cast<wxEraseEvent *>(_pEntity);
	}
	inline wxEraseEvent *ReleaseEntity() {
		wxEraseEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxEraseEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
