//----------------------------------------------------------------------------
// wxPropertyGrid
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_PROPERTYGRID_H__
#define __CLASS_WX_PROPERTYGRID_H__
#include <wx/propgrid/propgrid.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxPropertyGrid
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_PropertyGrid);

//----------------------------------------------------------------------------
// Object declaration for wxPropertyGrid
//----------------------------------------------------------------------------
class Object_wx_PropertyGrid : public Object_wx_Control {
public:
	Gura_DeclareObjectAccessor(wx_PropertyGrid)
public:
	inline Object_wx_PropertyGrid(wxPropertyGrid *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(Gura_UserClass(wx_PropertyGrid), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_PropertyGrid(Class *pClass, wxPropertyGrid *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_PropertyGrid();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxPropertyGrid *GetEntity() {
		return static_cast<wxPropertyGrid *>(_pEntity);
	}
	inline wxPropertyGrid *ReleaseEntity() {
		wxPropertyGrid *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxPropertyGrid");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
