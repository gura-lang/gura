//----------------------------------------------------------------------------
// wxVariantData
// extracted from variant.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_VARIANTDATA_H__
#define __CLASS_WX_VARIANTDATA_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxVariantData
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_VariantData);

//----------------------------------------------------------------------------
// Object declaration for wxVariantData
//----------------------------------------------------------------------------
class Object_wx_VariantData : public Object_wx_ObjectRefData {
public:
	Gura_DeclareObjectAccessor(wx_VariantData)
public:
	inline Object_wx_VariantData(wxVariantData *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ObjectRefData(Gura_UserClass(wx_VariantData), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_VariantData(Class *pClass, wxVariantData *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ObjectRefData(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_VariantData();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxVariantData *GetEntity() {
		return dynamic_cast<wxVariantData *>(_pEntity);
	}
	inline wxVariantData *ReleaseEntity() {
		wxVariantData *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxVariantData");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
