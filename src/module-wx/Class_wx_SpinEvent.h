//----------------------------------------------------------------------------
// wxSpinEvent
// extracted from spinevt.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_SPINEVENT_H__
#define __CLASS_WX_SPINEVENT_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxSpinEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_SpinEvent);

//----------------------------------------------------------------------------
// Object declaration for wxSpinEvent
//----------------------------------------------------------------------------
class Object_wx_SpinEvent : public Object_wx_NotifyEvent {
public:
	Gura_DeclareObjectAccessor(wx_SpinEvent)
public:
	inline Object_wx_SpinEvent(wxSpinEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_NotifyEvent(Gura_UserClass(wx_SpinEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_SpinEvent(Class *pClass, wxSpinEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_NotifyEvent(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_SpinEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxSpinEvent *GetEntity() {
		return dynamic_cast<wxSpinEvent *>(_pEntity);
	}
	inline wxSpinEvent *ReleaseEntity() {
		wxSpinEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxSpinEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
