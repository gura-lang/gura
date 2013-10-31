//----------------------------------------------------------------------------
// wxGridRangeSelectEvent
// extracted from gridevt.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_GRIDRANGESELECTEVENT_H__
#define __OBJECT_WX_GRIDRANGESELECTEVENT_H__

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
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxGridRangeSelectEvent *GetEntity() {
		return dynamic_cast<wxGridRangeSelectEvent *>(_pEntity);
	}
	inline wxGridRangeSelectEvent *ReleaseEntity() {
		wxGridRangeSelectEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxGridRangeSelectEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
