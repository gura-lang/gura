//----------------------------------------------------------------------------
// wxGridCellStringRenderer
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_GRIDCELLSTRINGRENDERER_H__
#define __CLASS_WX_GRIDCELLSTRINGRENDERER_H__
#include <wx/grid.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGridCellStringRenderer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GridCellStringRenderer);

//----------------------------------------------------------------------------
// Object declaration for wxGridCellStringRenderer
//----------------------------------------------------------------------------
class Object_wx_GridCellStringRenderer : public Object_wx_GridCellRenderer {
public:
	Gura_DeclareObjectAccessor(wx_GridCellStringRenderer)
public:
	inline Object_wx_GridCellStringRenderer(wxGridCellStringRenderer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GridCellRenderer(Gura_UserClass(wx_GridCellStringRenderer), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_GridCellStringRenderer(Class *pClass, wxGridCellStringRenderer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GridCellRenderer(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_GridCellStringRenderer();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxGridCellStringRenderer *GetEntity() {
		return static_cast<wxGridCellStringRenderer *>(_pEntity);
	}
	inline wxGridCellStringRenderer *ReleaseEntity() {
		wxGridCellStringRenderer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxGridCellStringRenderer");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
