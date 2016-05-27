//----------------------------------------------------------------------------
// wxGridCellRenderer
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_GRIDCELLRENDERER_H__
#define __CLASS_WX_GRIDCELLRENDERER_H__
#include <wx/grid.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGridCellRenderer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GridCellRenderer);

//----------------------------------------------------------------------------
// Object declaration for wxGridCellRenderer
//----------------------------------------------------------------------------
class Object_wx_GridCellRenderer : public Object_wx_ClientDataContainer {
public:
	Gura_DeclareObjectAccessor(wx_GridCellRenderer)
public:
	inline Object_wx_GridCellRenderer(wxGridCellRenderer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ClientDataContainer(Gura_UserClass(wx_GridCellRenderer), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_GridCellRenderer(Class *pClass, wxGridCellRenderer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ClientDataContainer(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_GridCellRenderer();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxGridCellRenderer *GetEntity() {
		return static_cast<wxGridCellRenderer *>(_pEntity);
	}
	inline wxGridCellRenderer *ReleaseEntity() {
		wxGridCellRenderer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxGridCellRenderer");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
