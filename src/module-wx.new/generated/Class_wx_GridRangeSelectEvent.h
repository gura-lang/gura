//----------------------------------------------------------------------------
// wxGridRangeSelectEvent
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_GRIDRANGESELECTEVENT_H__
#define __CLASS_WX_GRIDRANGESELECTEVENT_H__
#include <wx/grid.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGridRangeSelectEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GridRangeSelectEvent);

//----------------------------------------------------------------------------
// Object declaration for wxGridRangeSelectEvent
//----------------------------------------------------------------------------
class Object_wx_GridRangeSelectEvent : public Object_wx_NotifyEvent {
public:
	Gura_DeclareObjectAccessor(wx_GridRangeSelectEvent)
public:
	inline Object_wx_GridRangeSelectEvent(wxGridRangeSelectEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_NotifyEvent(Gura_UserClass(wx_GridRangeSelectEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_GridRangeSelectEvent(Class *pClass, wxGridRangeSelectEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_NotifyEvent(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_GridRangeSelectEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxGridRangeSelectEvent *GetEntity() {
		return static_cast<wxGridRangeSelectEvent *>(_pEntity);
	}
	inline wxGridRangeSelectEvent *ReleaseEntity() {
		wxGridRangeSelectEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxGridRangeSelectEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
