//----------------------------------------------------------------------------
// wxVariant
// extracted from variant.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_VARIANT_H__
#define __OBJECT_WX_VARIANT_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxVariant
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Variant);

//----------------------------------------------------------------------------
// Object declaration for wxVariant
//----------------------------------------------------------------------------
class Object_wx_Variant : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_Variant)
public:
	inline Object_wx_Variant(wxVariant *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_Variant), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_Variant(Class *pClass, wxVariant *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_Variant();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxVariant *GetEntity() {
		return dynamic_cast<wxVariant *>(_pEntity);
	}
	inline wxVariant *ReleaseEntity() {
		wxVariant *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxVariant");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
