//----------------------------------------------------------------------------
// wxImageList
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_IMAGELIST_H__
#define __CLASS_WX_IMAGELIST_H__
#include <wx/imaglist.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxImageList
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ImageList);

//----------------------------------------------------------------------------
// Object declaration for wxImageList
//----------------------------------------------------------------------------
class Object_wx_ImageList : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_ImageList)
public:
	inline Object_wx_ImageList(wxImageList *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_ImageList), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ImageList(Class *pClass, wxImageList *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ImageList();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxImageList *GetEntity() {
		return static_cast<wxImageList *>(_pEntity);
	}
	inline wxImageList *ReleaseEntity() {
		wxImageList *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxImageList");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
