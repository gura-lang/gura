//----------------------------------------------------------------------------
// wxImageHandler
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_IMAGEHANDLER_H__
#define __CLASS_WX_IMAGEHANDLER_H__
#include <wx/image.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxImageHandler
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ImageHandler);

//----------------------------------------------------------------------------
// Object declaration for wxImageHandler
//----------------------------------------------------------------------------
class Object_wx_ImageHandler : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_ImageHandler)
public:
	inline Object_wx_ImageHandler(wxImageHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_ImageHandler), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ImageHandler(Class *pClass, wxImageHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ImageHandler();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxImageHandler *GetEntity() {
		return static_cast<wxImageHandler *>(_pEntity);
	}
	inline wxImageHandler *ReleaseEntity() {
		wxImageHandler *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxImageHandler");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
