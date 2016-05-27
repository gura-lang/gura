//----------------------------------------------------------------------------
// wxIntegerValidator
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_INTEGERVALIDATOR_H__
#define __CLASS_WX_INTEGERVALIDATOR_H__
#include <wx/valnum.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxIntegerValidator
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_IntegerValidator);

//----------------------------------------------------------------------------
// Object declaration for wxIntegerValidator
//----------------------------------------------------------------------------
class Object_wx_IntegerValidator : public Object_wx_NumValidator {
public:
	Gura_DeclareObjectAccessor(wx_IntegerValidator)
public:
	inline Object_wx_IntegerValidator(wxIntegerValidator *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_NumValidator(Gura_UserClass(wx_IntegerValidator), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_IntegerValidator(Class *pClass, wxIntegerValidator *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_NumValidator(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_IntegerValidator();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxIntegerValidator *GetEntity() {
		return static_cast<wxIntegerValidator *>(_pEntity);
	}
	inline wxIntegerValidator *ReleaseEntity() {
		wxIntegerValidator *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxIntegerValidator");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
