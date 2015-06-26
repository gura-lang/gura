//----------------------------------------------------------------------------
// wxMask
// extracted from mask.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_MASK_H__
#define __CLASS_WX_MASK_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxMask
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Mask);

//----------------------------------------------------------------------------
// Object declaration for wxMask
//----------------------------------------------------------------------------
class Object_wx_Mask : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_Mask)
public:
	inline Object_wx_Mask(wxMask *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_Mask), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_Mask(Class *pClass, wxMask *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_Mask();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxMask *GetEntity() {
		return dynamic_cast<wxMask *>(_pEntity);
	}
	inline wxMask *ReleaseEntity() {
		wxMask *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxMask");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
