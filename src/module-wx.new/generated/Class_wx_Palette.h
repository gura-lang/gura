//----------------------------------------------------------------------------
// wxPalette
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_PALETTE_H__
#define __CLASS_WX_PALETTE_H__
#include <wx/palette.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPalette
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Palette);

//----------------------------------------------------------------------------
// Object declaration for wxPalette
//----------------------------------------------------------------------------
class Object_wx_Palette : public Object_wx_GDIObject {
public:
	Gura_DeclareObjectAccessor(wx_Palette)
public:
	inline Object_wx_Palette(wxPalette *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GDIObject(Gura_UserClass(wx_Palette), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_Palette(Class *pClass, wxPalette *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GDIObject(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_Palette();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxPalette *GetEntity() {
		return static_cast<wxPalette *>(_pEntity);
	}
	inline wxPalette *ReleaseEntity() {
		wxPalette *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxPalette");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
