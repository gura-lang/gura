//----------------------------------------------------------------------------
// wxChildFocusEvent
// extracted from chfocevt.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_CHILDFOCUSEVENT_H__
#define __OBJECT_WX_CHILDFOCUSEVENT_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxChildFocusEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ChildFocusEvent);

//----------------------------------------------------------------------------
// Object declaration for wxChildFocusEvent
//----------------------------------------------------------------------------
class Object_wx_ChildFocusEvent : public Object_wx_CommandEvent {
public:
	Gura_DeclareObjectAccessor(wx_ChildFocusEvent)
public:
	inline Object_wx_ChildFocusEvent(wxChildFocusEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(Gura_UserClass(wx_ChildFocusEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ChildFocusEvent(Class *pClass, wxChildFocusEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ChildFocusEvent();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxChildFocusEvent *GetEntity() {
		return dynamic_cast<wxChildFocusEvent *>(_pEntity);
	}
	inline wxChildFocusEvent *ReleaseEntity() {
		wxChildFocusEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxChildFocusEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
