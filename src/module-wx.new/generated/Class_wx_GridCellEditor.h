//----------------------------------------------------------------------------
// wxGridCellEditor
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_GRIDCELLEDITOR_H__
#define __CLASS_WX_GRIDCELLEDITOR_H__
#include <wx/grid.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGridCellEditor
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GridCellEditor);

//----------------------------------------------------------------------------
// Object declaration for wxGridCellEditor
//----------------------------------------------------------------------------
class Object_wx_GridCellEditor : public Object_wx_ClientDataContainer {
public:
	Gura_DeclareObjectAccessor(wx_GridCellEditor)
public:
	inline Object_wx_GridCellEditor(wxGridCellEditor *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ClientDataContainer(Gura_UserClass(wx_GridCellEditor), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_GridCellEditor(Class *pClass, wxGridCellEditor *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_ClientDataContainer(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_GridCellEditor();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxGridCellEditor *GetEntity() {
		return static_cast<wxGridCellEditor *>(_pEntity);
	}
	inline wxGridCellEditor *ReleaseEntity() {
		wxGridCellEditor *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxGridCellEditor");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
