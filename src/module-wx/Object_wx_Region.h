//----------------------------------------------------------------------------
// wxRegion
// extracted from region.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_REGION_H__
#define __OBJECT_WX_REGION_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxRegion
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Region);

//----------------------------------------------------------------------------
// Object declaration for wxRegion
//----------------------------------------------------------------------------
class Object_wx_Region : public Object_wx_GDIObject {
public:
	Gura_DeclareObjectAccessor(wx_Region)
public:
	inline Object_wx_Region(wxRegion *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GDIObject(Gura_UserClass(wx_Region), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_Region(Class *pClass, wxRegion *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GDIObject(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_Region();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxRegion *GetEntity() {
		return dynamic_cast<wxRegion *>(_pEntity);
	}
	inline wxRegion *ReleaseEntity() {
		wxRegion *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxRegion");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
