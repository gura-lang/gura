//----------------------------------------------------------------------------
// wxBrush
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_BRUSH_H__
#define __CLASS_WX_BRUSH_H__
#include <wx/brush.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxBrush
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Brush);

//----------------------------------------------------------------------------
// Object declaration for wxBrush
//----------------------------------------------------------------------------
class Object_wx_Brush : public Object_wx_GDIObject {
public:
	Gura_DeclareObjectAccessor(wx_Brush)
public:
	inline Object_wx_Brush(wxBrush *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GDIObject(Gura_UserClass(wx_Brush), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_Brush(Class *pClass, wxBrush *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GDIObject(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_Brush();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxBrush *GetEntity() {
		return static_cast<wxBrush *>(_pEntity);
	}
	inline wxBrush *ReleaseEntity() {
		wxBrush *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxBrush");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
