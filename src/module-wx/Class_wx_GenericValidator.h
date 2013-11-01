//----------------------------------------------------------------------------
// wxGenericValidator
// extracted from valgen.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_GENERICVALIDATOR_H__
#define __CLASS_WX_GENERICVALIDATOR_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGenericValidator
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GenericValidator);

//----------------------------------------------------------------------------
// Object declaration for wxGenericValidator
//----------------------------------------------------------------------------
class Object_wx_GenericValidator : public Object_wx_Validator {
public:
	Gura_DeclareObjectAccessor(wx_GenericValidator)
public:
	inline Object_wx_GenericValidator(wxGenericValidator *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Validator(Gura_UserClass(wx_GenericValidator), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_GenericValidator(Class *pClass, wxGenericValidator *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Validator(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_GenericValidator();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxGenericValidator *GetEntity() {
		return dynamic_cast<wxGenericValidator *>(_pEntity);
	}
	inline wxGenericValidator *ReleaseEntity() {
		wxGenericValidator *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxGenericValidator");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
