//----------------------------------------------------------------------------
// wxGridCellEnumRenderer
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_GRIDCELLENUMRENDERER_H__
#define __CLASS_WX_GRIDCELLENUMRENDERER_H__
#include <wx/grid.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGridCellEnumRenderer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GridCellEnumRenderer);

//----------------------------------------------------------------------------
// Object declaration for wxGridCellEnumRenderer
//----------------------------------------------------------------------------
class Object_wx_GridCellEnumRenderer : public Object_wx_GridCellStringRenderer {
public:
	Gura_DeclareObjectAccessor(wx_GridCellEnumRenderer)
public:
	inline Object_wx_GridCellEnumRenderer(wxGridCellEnumRenderer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GridCellStringRenderer(Gura_UserClass(wx_GridCellEnumRenderer), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_GridCellEnumRenderer(Class *pClass, wxGridCellEnumRenderer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GridCellStringRenderer(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_GridCellEnumRenderer();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxGridCellEnumRenderer *GetEntity() {
		return static_cast<wxGridCellEnumRenderer *>(_pEntity);
	}
	inline wxGridCellEnumRenderer *ReleaseEntity() {
		wxGridCellEnumRenderer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxGridCellEnumRenderer");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
