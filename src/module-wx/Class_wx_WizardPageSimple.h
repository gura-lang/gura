//----------------------------------------------------------------------------
// wxWizardPageSimple
// extracted from wizpage.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_WIZARDPAGESIMPLE_H__
#define __CLASS_WX_WIZARDPAGESIMPLE_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxWizardPageSimple
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_WizardPageSimple);

//----------------------------------------------------------------------------
// Object declaration for wxWizardPageSimple
//----------------------------------------------------------------------------
class Object_wx_WizardPageSimple : public Object_wx_WizardPage {
public:
	Gura_DeclareObjectAccessor(wx_WizardPageSimple)
public:
	inline Object_wx_WizardPageSimple(wxWizardPageSimple *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_WizardPage(Gura_UserClass(wx_WizardPageSimple), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_WizardPageSimple(Class *pClass, wxWizardPageSimple *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_WizardPage(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_WizardPageSimple();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxWizardPageSimple *GetEntity() {
		return dynamic_cast<wxWizardPageSimple *>(_pEntity);
	}
	inline wxWizardPageSimple *ReleaseEntity() {
		wxWizardPageSimple *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxWizardPageSimple");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
