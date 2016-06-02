//----------------------------------------------------------------------------
// wxFont
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_FONT_H__
#define __CLASS_WX_FONT_H__
#include <wx/font.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxFont
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Font);

//----------------------------------------------------------------------------
// Object declaration for wxFont
//----------------------------------------------------------------------------
class Object_wx_Font : public Object_wx_GDIObject {
public:
	Gura_DeclareObjectAccessor(wx_Font)
public:
	inline Object_wx_Font(wxFont *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GDIObject(Gura_UserClass(wx_Font), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_Font(Class *pClass, wxFont *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GDIObject(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_Font();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxFont *GetEntity() {
		return static_cast<wxFont *>(_pEntity);
	}
	inline wxFont *ReleaseEntity() {
		wxFont *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxFont");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
