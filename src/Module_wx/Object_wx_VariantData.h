//----------------------------------------------------------------------------
// wxVariantData
// extracted from variant.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_VARIANTDATA_H__
#define __OBJECT_WX_VARIANTDATA_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxVariantData
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_VariantData);

//----------------------------------------------------------------------------
// Object declaration for wxVariantData
//----------------------------------------------------------------------------
class Object_wx_VariantData : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_VariantData)
public:
	inline Object_wx_VariantData(wxVariantData *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_VariantData), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_VariantData(Class *pClass, wxVariantData *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_VariantData();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
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

}}

#endif
