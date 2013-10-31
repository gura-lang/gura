//----------------------------------------------------------------------------
// wxFocusEvent
// extracted from focusevt.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_FOCUSEVENT_H__
#define __OBJECT_WX_FOCUSEVENT_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxFocusEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_FocusEvent);

//----------------------------------------------------------------------------
// Object declaration for wxFocusEvent
//----------------------------------------------------------------------------
class Object_wx_FocusEvent : public Object_wx_Event {
public:
	Gura_DeclareObjectAccessor(wx_FocusEvent)
public:
	inline Object_wx_FocusEvent(wxFocusEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(Gura_UserClass(wx_FocusEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_FocusEvent(Class *pClass, wxFocusEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_FocusEvent();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxFocusEvent *GetEntity() {
		return dynamic_cast<wxFocusEvent *>(_pEntity);
	}
	inline wxFocusEvent *ReleaseEntity() {
		wxFocusEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxFocusEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
