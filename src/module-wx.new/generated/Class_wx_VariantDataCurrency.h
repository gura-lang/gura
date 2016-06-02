//----------------------------------------------------------------------------
// wxVariantDataCurrency
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_VARIANTDATACURRENCY_H__
#define __CLASS_WX_VARIANTDATACURRENCY_H__
#include <wx/msw/ole/automtn.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxVariantDataCurrency
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_VariantDataCurrency);

//----------------------------------------------------------------------------
// Object declaration for wxVariantDataCurrency
//----------------------------------------------------------------------------
class Object_wx_VariantDataCurrency : public Object_wx_VariantData {
public:
	Gura_DeclareObjectAccessor(wx_VariantDataCurrency)
public:
	inline Object_wx_VariantDataCurrency(wxVariantDataCurrency *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_VariantData(Gura_UserClass(wx_VariantDataCurrency), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_VariantDataCurrency(Class *pClass, wxVariantDataCurrency *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_VariantData(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_VariantDataCurrency();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxVariantDataCurrency *GetEntity() {
		return static_cast<wxVariantDataCurrency *>(_pEntity);
	}
	inline wxVariantDataCurrency *ReleaseEntity() {
		wxVariantDataCurrency *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxVariantDataCurrency");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
