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
private:
	AutoPtr<Object_wx_WizardPage> _pPrev;
	AutoPtr<Object_wx_WizardPage> _pNext;
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
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxWizardPageSimple");
		return true;
	}
	inline void SetPrev(Object_wx_WizardPage *prev) {
		_pPrev.reset(prev->Reference());
		GetEntity()->SetPrev(prev->GetEntity());
	}
	inline void SetNext(Object_wx_WizardPage *next) {
		_pNext.reset(next->Reference());
		GetEntity()->SetNext(next->GetEntity());
	}
};

Gura_EndModuleScope(wx)

#endif
