//----------------------------------------------------------------------------
// wxGridCellAttr
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_GRIDCELLATTR_H__
#define __CLASS_WX_GRIDCELLATTR_H__
#include <wx/grid.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGridCellAttr
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GridCellAttr);

//----------------------------------------------------------------------------
// Object declaration for wxGridCellAttr
//----------------------------------------------------------------------------
class Object_wx_GridCellAttr : public Object_wx_ClientDataContainer {
public:
	Gura_DeclareObjectAccessor(wx_GridCellAttr)
public:
	inline Object_wx_GridCellAttr(wxGridCellAttr *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ClientDataContainer(Gura_UserClass(wx_GridCellAttr), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_GridCellAttr(Class *pClass, wxGridCellAttr *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ClientDataContainer(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_GridCellAttr();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxGridCellAttr *GetEntity() {
		return static_cast<wxGridCellAttr *>(_pEntity);
	}
	inline wxGridCellAttr *ReleaseEntity() {
		wxGridCellAttr *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxGridCellAttr");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
