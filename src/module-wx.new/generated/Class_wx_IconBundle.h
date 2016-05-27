//----------------------------------------------------------------------------
// wxIconBundle
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_ICONBUNDLE_H__
#define __CLASS_WX_ICONBUNDLE_H__
#include <wx/iconbndl.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxIconBundle
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_IconBundle);

//----------------------------------------------------------------------------
// Object declaration for wxIconBundle
//----------------------------------------------------------------------------
class Object_wx_IconBundle : public Object_wx_GDIObject {
public:
	Gura_DeclareObjectAccessor(wx_IconBundle)
public:
	inline Object_wx_IconBundle(wxIconBundle *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GDIObject(Gura_UserClass(wx_IconBundle), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_IconBundle(Class *pClass, wxIconBundle *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GDIObject(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_IconBundle();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxIconBundle *GetEntity() {
		return static_cast<wxIconBundle *>(_pEntity);
	}
	inline wxIconBundle *ReleaseEntity() {
		wxIconBundle *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxIconBundle");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
