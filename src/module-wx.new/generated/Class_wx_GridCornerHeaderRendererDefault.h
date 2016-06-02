//----------------------------------------------------------------------------
// wxGridCornerHeaderRendererDefault
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_GRIDCORNERHEADERRENDERERDEFAULT_H__
#define __CLASS_WX_GRIDCORNERHEADERRENDERERDEFAULT_H__
#include <wx/grid.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGridCornerHeaderRendererDefault
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GridCornerHeaderRendererDefault);

//----------------------------------------------------------------------------
// Object declaration for wxGridCornerHeaderRendererDefault
//----------------------------------------------------------------------------
class Object_wx_GridCornerHeaderRendererDefault : public Object_wx_GridCornerHeaderRenderer {
public:
	Gura_DeclareObjectAccessor(wx_GridCornerHeaderRendererDefault)
public:
	inline Object_wx_GridCornerHeaderRendererDefault(wxGridCornerHeaderRendererDefault *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GridCornerHeaderRenderer(Gura_UserClass(wx_GridCornerHeaderRendererDefault), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_GridCornerHeaderRendererDefault(Class *pClass, wxGridCornerHeaderRendererDefault *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GridCornerHeaderRenderer(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_GridCornerHeaderRendererDefault();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxGridCornerHeaderRendererDefault *GetEntity() {
		return static_cast<wxGridCornerHeaderRendererDefault *>(_pEntity);
	}
	inline wxGridCornerHeaderRendererDefault *ReleaseEntity() {
		wxGridCornerHeaderRendererDefault *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxGridCornerHeaderRendererDefault");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
