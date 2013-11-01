//----------------------------------------------------------------------------
// wxWizardEvent
// extracted from wizevt.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_WIZARDEVENT_H__
#define __OBJECT_WX_WIZARDEVENT_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxWizardEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_WizardEvent);

//----------------------------------------------------------------------------
// Object declaration for wxWizardEvent
//----------------------------------------------------------------------------
class Object_wx_WizardEvent : public Object_wx_NotifyEvent {
public:
	Gura_DeclareObjectAccessor(wx_WizardEvent)
public:
	inline Object_wx_WizardEvent(wxWizardEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_NotifyEvent(Gura_UserClass(wx_WizardEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_WizardEvent(Class *pClass, wxWizardEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_NotifyEvent(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_WizardEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxWizardEvent *GetEntity() {
		return dynamic_cast<wxWizardEvent *>(_pEntity);
	}
	inline wxWizardEvent *ReleaseEntity() {
		wxWizardEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxWizardEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
