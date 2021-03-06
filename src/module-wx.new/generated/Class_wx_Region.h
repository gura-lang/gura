//----------------------------------------------------------------------------
// wxRegion
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_REGION_H__
#define __CLASS_WX_REGION_H__
#include <wx/region.h>

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
	virtual String ToString(bool exprFlag);
	inline wxRegion *GetEntity() {
		return static_cast<wxRegion *>(_pEntity);
	}
	inline wxRegion *ReleaseEntity() {
		wxRegion *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxRegion");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
