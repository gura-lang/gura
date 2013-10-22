//----------------------------------------------------------------------------
// wxWizard
// extracted from wizard.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_WIZARD_H__
#define __OBJECT_WX_WIZARD_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxWizard
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Wizard);

//----------------------------------------------------------------------------
// Object declaration for wxWizard
//----------------------------------------------------------------------------
class Object_wx_Wizard : public Object_wx_Dialog {
public:
	Gura_DeclareObjectAccessor(wx_Wizard)
public:
	inline Object_wx_Wizard(wxWizard *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Dialog(Gura_UserClass(wx_Wizard), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_Wizard(Class *pClass, wxWizard *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Dialog(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_Wizard();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxWizard *GetEntity() {
		return dynamic_cast<wxWizard *>(_pEntity);
	}
	inline wxWizard *ReleaseEntity() {
		wxWizard *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxWizard");
		return true;
	}
};

}}

#endif
