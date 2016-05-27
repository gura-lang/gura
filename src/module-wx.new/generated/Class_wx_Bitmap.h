//----------------------------------------------------------------------------
// wxBitmap
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_BITMAP_H__
#define __CLASS_WX_BITMAP_H__
#include <wx/bitmap.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxBitmap
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Bitmap);

//----------------------------------------------------------------------------
// Object declaration for wxBitmap
//----------------------------------------------------------------------------
class Object_wx_Bitmap : public Object_wx_GDIObject {
public:
	Gura_DeclareObjectAccessor(wx_Bitmap)
public:
	inline Object_wx_Bitmap(wxBitmap *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GDIObject(Gura_UserClass(wx_Bitmap), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_Bitmap(Class *pClass, wxBitmap *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GDIObject(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_Bitmap();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxBitmap *GetEntity() {
		return static_cast<wxBitmap *>(_pEntity);
	}
	inline wxBitmap *ReleaseEntity() {
		wxBitmap *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxBitmap");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
