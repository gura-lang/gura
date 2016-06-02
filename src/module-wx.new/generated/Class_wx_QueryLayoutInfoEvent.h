//----------------------------------------------------------------------------
// wxQueryLayoutInfoEvent
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_QUERYLAYOUTINFOEVENT_H__
#define __CLASS_WX_QUERYLAYOUTINFOEVENT_H__
#include <wx/laywin.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxQueryLayoutInfoEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_QueryLayoutInfoEvent);

//----------------------------------------------------------------------------
// Object declaration for wxQueryLayoutInfoEvent
//----------------------------------------------------------------------------
class Object_wx_QueryLayoutInfoEvent : public Object_wx_Event {
public:
	Gura_DeclareObjectAccessor(wx_QueryLayoutInfoEvent)
public:
	inline Object_wx_QueryLayoutInfoEvent(wxQueryLayoutInfoEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(Gura_UserClass(wx_QueryLayoutInfoEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_QueryLayoutInfoEvent(Class *pClass, wxQueryLayoutInfoEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_QueryLayoutInfoEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxQueryLayoutInfoEvent *GetEntity() {
		return static_cast<wxQueryLayoutInfoEvent *>(_pEntity);
	}
	inline wxQueryLayoutInfoEvent *ReleaseEntity() {
		wxQueryLayoutInfoEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxQueryLayoutInfoEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
