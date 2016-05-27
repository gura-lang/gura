//----------------------------------------------------------------------------
// wxNumValidator
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_NUMVALIDATOR_H__
#define __CLASS_WX_NUMVALIDATOR_H__
#include <wx/valnum.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxNumValidator
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_NumValidator);

//----------------------------------------------------------------------------
// Object declaration for wxNumValidator
//----------------------------------------------------------------------------
class Object_wx_NumValidator : public Object_wx_Validator {
public:
	Gura_DeclareObjectAccessor(wx_NumValidator)
public:
	inline Object_wx_NumValidator(wxNumValidator *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Validator(Gura_UserClass(wx_NumValidator), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_NumValidator(Class *pClass, wxNumValidator *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Validator(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_NumValidator();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxNumValidator *GetEntity() {
		return static_cast<wxNumValidator *>(_pEntity);
	}
	inline wxNumValidator *ReleaseEntity() {
		wxNumValidator *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxNumValidator");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
