//----------------------------------------------------------------------------
// wxWizardPage
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_WIZARDPAGE_H__
#define __CLASS_WX_WIZARDPAGE_H__
#include <wx/wizard.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxWizardPage
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_WizardPage);

//----------------------------------------------------------------------------
// Object declaration for wxWizardPage
//----------------------------------------------------------------------------
class Object_wx_WizardPage : public Object_wx_Panel {
public:
	Gura_DeclareObjectAccessor(wx_WizardPage)
public:
	inline Object_wx_WizardPage(wxWizardPage *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Panel(Gura_UserClass(wx_WizardPage), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_WizardPage(Class *pClass, wxWizardPage *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Panel(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_WizardPage();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxWizardPage *GetEntity() {
		return static_cast<wxWizardPage *>(_pEntity);
	}
	inline wxWizardPage *ReleaseEntity() {
		wxWizardPage *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxWizardPage");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
