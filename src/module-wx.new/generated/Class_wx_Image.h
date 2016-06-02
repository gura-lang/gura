//----------------------------------------------------------------------------
// wxImage
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_IMAGE_H__
#define __CLASS_WX_IMAGE_H__
#include <wx/image.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxImage
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Image);

//----------------------------------------------------------------------------
// Object declaration for wxImage
//----------------------------------------------------------------------------
class Object_wx_Image : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_Image)
public:
	inline Object_wx_Image(wxImage *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_Image), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_Image(Class *pClass, wxImage *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_Image();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxImage *GetEntity() {
		return static_cast<wxImage *>(_pEntity);
	}
	inline wxImage *ReleaseEntity() {
		wxImage *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxImage");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
