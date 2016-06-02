//----------------------------------------------------------------------------
// wxGridCellAutoWrapStringRenderer
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_GRIDCELLAUTOWRAPSTRINGRENDERER_H__
#define __CLASS_WX_GRIDCELLAUTOWRAPSTRINGRENDERER_H__
#include <wx/grid.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGridCellAutoWrapStringRenderer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GridCellAutoWrapStringRenderer);

//----------------------------------------------------------------------------
// Object declaration for wxGridCellAutoWrapStringRenderer
//----------------------------------------------------------------------------
class Object_wx_GridCellAutoWrapStringRenderer : public Object_wx_GridCellStringRenderer {
public:
	Gura_DeclareObjectAccessor(wx_GridCellAutoWrapStringRenderer)
public:
	inline Object_wx_GridCellAutoWrapStringRenderer(wxGridCellAutoWrapStringRenderer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GridCellStringRenderer(Gura_UserClass(wx_GridCellAutoWrapStringRenderer), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_GridCellAutoWrapStringRenderer(Class *pClass, wxGridCellAutoWrapStringRenderer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GridCellStringRenderer(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_GridCellAutoWrapStringRenderer();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxGridCellAutoWrapStringRenderer *GetEntity() {
		return static_cast<wxGridCellAutoWrapStringRenderer *>(_pEntity);
	}
	inline wxGridCellAutoWrapStringRenderer *ReleaseEntity() {
		wxGridCellAutoWrapStringRenderer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxGridCellAutoWrapStringRenderer");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
