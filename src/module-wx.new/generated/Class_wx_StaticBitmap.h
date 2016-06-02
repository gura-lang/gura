//----------------------------------------------------------------------------
// wxStaticBitmap
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_STATICBITMAP_H__
#define __CLASS_WX_STATICBITMAP_H__
#include <wx/statbmp.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxStaticBitmap
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_StaticBitmap);

//----------------------------------------------------------------------------
// Object declaration for wxStaticBitmap
//----------------------------------------------------------------------------
class Object_wx_StaticBitmap : public Object_wx_Control {
public:
	Gura_DeclareObjectAccessor(wx_StaticBitmap)
public:
	inline Object_wx_StaticBitmap(wxStaticBitmap *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(Gura_UserClass(wx_StaticBitmap), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_StaticBitmap(Class *pClass, wxStaticBitmap *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_StaticBitmap();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxStaticBitmap *GetEntity() {
		return static_cast<wxStaticBitmap *>(_pEntity);
	}
	inline wxStaticBitmap *ReleaseEntity() {
		wxStaticBitmap *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxStaticBitmap");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
