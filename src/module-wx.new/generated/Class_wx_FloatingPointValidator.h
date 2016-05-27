//----------------------------------------------------------------------------
// wxFloatingPointValidator
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_FLOATINGPOINTVALIDATOR_H__
#define __CLASS_WX_FLOATINGPOINTVALIDATOR_H__
#include <wx/valnum.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxFloatingPointValidator
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_FloatingPointValidator);

//----------------------------------------------------------------------------
// Object declaration for wxFloatingPointValidator
//----------------------------------------------------------------------------
class Object_wx_FloatingPointValidator : public Object_wx_NumValidator {
public:
	Gura_DeclareObjectAccessor(wx_FloatingPointValidator)
public:
	inline Object_wx_FloatingPointValidator(wxFloatingPointValidator *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_NumValidator(Gura_UserClass(wx_FloatingPointValidator), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_FloatingPointValidator(Class *pClass, wxFloatingPointValidator *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_NumValidator(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_FloatingPointValidator();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxFloatingPointValidator *GetEntity() {
		return static_cast<wxFloatingPointValidator *>(_pEntity);
	}
	inline wxFloatingPointValidator *ReleaseEntity() {
		wxFloatingPointValidator *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxFloatingPointValidator");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
