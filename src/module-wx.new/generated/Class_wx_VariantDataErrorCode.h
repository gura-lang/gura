//----------------------------------------------------------------------------
// wxVariantDataErrorCode
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_VARIANTDATAERRORCODE_H__
#define __CLASS_WX_VARIANTDATAERRORCODE_H__
#include <wx/msw/ole/automtn.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxVariantDataErrorCode
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_VariantDataErrorCode);

//----------------------------------------------------------------------------
// Object declaration for wxVariantDataErrorCode
//----------------------------------------------------------------------------
class Object_wx_VariantDataErrorCode : public Object_wx_VariantData {
public:
	Gura_DeclareObjectAccessor(wx_VariantDataErrorCode)
public:
	inline Object_wx_VariantDataErrorCode(wxVariantDataErrorCode *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_VariantData(Gura_UserClass(wx_VariantDataErrorCode), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_VariantDataErrorCode(Class *pClass, wxVariantDataErrorCode *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_VariantData(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_VariantDataErrorCode();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxVariantDataErrorCode *GetEntity() {
		return static_cast<wxVariantDataErrorCode *>(_pEntity);
	}
	inline wxVariantDataErrorCode *ReleaseEntity() {
		wxVariantDataErrorCode *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxVariantDataErrorCode");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
