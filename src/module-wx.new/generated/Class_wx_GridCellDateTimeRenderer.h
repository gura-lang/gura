//----------------------------------------------------------------------------
// wxGridCellDateTimeRenderer
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_GRIDCELLDATETIMERENDERER_H__
#define __CLASS_WX_GRIDCELLDATETIMERENDERER_H__
#include <wx/grid.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGridCellDateTimeRenderer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GridCellDateTimeRenderer);

//----------------------------------------------------------------------------
// Object declaration for wxGridCellDateTimeRenderer
//----------------------------------------------------------------------------
class Object_wx_GridCellDateTimeRenderer : public Object_wx_GridCellStringRenderer {
public:
	Gura_DeclareObjectAccessor(wx_GridCellDateTimeRenderer)
public:
	inline Object_wx_GridCellDateTimeRenderer(wxGridCellDateTimeRenderer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GridCellStringRenderer(Gura_UserClass(wx_GridCellDateTimeRenderer), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_GridCellDateTimeRenderer(Class *pClass, wxGridCellDateTimeRenderer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GridCellStringRenderer(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_GridCellDateTimeRenderer();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxGridCellDateTimeRenderer *GetEntity() {
		return static_cast<wxGridCellDateTimeRenderer *>(_pEntity);
	}
	inline wxGridCellDateTimeRenderer *ReleaseEntity() {
		wxGridCellDateTimeRenderer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxGridCellDateTimeRenderer");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
