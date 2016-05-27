//----------------------------------------------------------------------------
// wxGridCellAttrProvider
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_GRIDCELLATTRPROVIDER_H__
#define __CLASS_WX_GRIDCELLATTRPROVIDER_H__
#include <wx/grid.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGridCellAttrProvider
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GridCellAttrProvider);

//----------------------------------------------------------------------------
// Object declaration for wxGridCellAttrProvider
//----------------------------------------------------------------------------
class Object_wx_GridCellAttrProvider : public Object_wx_ClientDataContainer {
public:
	Gura_DeclareObjectAccessor(wx_GridCellAttrProvider)
public:
	inline Object_wx_GridCellAttrProvider(wxGridCellAttrProvider *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ClientDataContainer(Gura_UserClass(wx_GridCellAttrProvider), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_GridCellAttrProvider(Class *pClass, wxGridCellAttrProvider *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ClientDataContainer(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_GridCellAttrProvider();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxGridCellAttrProvider *GetEntity() {
		return static_cast<wxGridCellAttrProvider *>(_pEntity);
	}
	inline wxGridCellAttrProvider *ReleaseEntity() {
		wxGridCellAttrProvider *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxGridCellAttrProvider");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
