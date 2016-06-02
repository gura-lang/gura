//----------------------------------------------------------------------------
// wxVariantDataSafeArray
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_VARIANTDATASAFEARRAY_H__
#define __CLASS_WX_VARIANTDATASAFEARRAY_H__
#include <wx/msw/ole/automtn.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxVariantDataSafeArray
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_VariantDataSafeArray);

//----------------------------------------------------------------------------
// Object declaration for wxVariantDataSafeArray
//----------------------------------------------------------------------------
class Object_wx_VariantDataSafeArray : public Object_wx_VariantData {
public:
	Gura_DeclareObjectAccessor(wx_VariantDataSafeArray)
public:
	inline Object_wx_VariantDataSafeArray(wxVariantDataSafeArray *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_VariantData(Gura_UserClass(wx_VariantDataSafeArray), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_VariantDataSafeArray(Class *pClass, wxVariantDataSafeArray *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_VariantData(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_VariantDataSafeArray();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxVariantDataSafeArray *GetEntity() {
		return static_cast<wxVariantDataSafeArray *>(_pEntity);
	}
	inline wxVariantDataSafeArray *ReleaseEntity() {
		wxVariantDataSafeArray *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxVariantDataSafeArray");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
