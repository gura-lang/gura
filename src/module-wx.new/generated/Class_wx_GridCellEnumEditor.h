//----------------------------------------------------------------------------
// wxGridCellEnumEditor
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_GRIDCELLENUMEDITOR_H__
#define __CLASS_WX_GRIDCELLENUMEDITOR_H__
#include <wx/grid.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGridCellEnumEditor
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GridCellEnumEditor);

//----------------------------------------------------------------------------
// Object declaration for wxGridCellEnumEditor
//----------------------------------------------------------------------------
class Object_wx_GridCellEnumEditor : public Object_wx_GridCellChoiceEditor {
public:
	Gura_DeclareObjectAccessor(wx_GridCellEnumEditor)
public:
	inline Object_wx_GridCellEnumEditor(wxGridCellEnumEditor *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GridCellChoiceEditor(Gura_UserClass(wx_GridCellEnumEditor), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_GridCellEnumEditor(Class *pClass, wxGridCellEnumEditor *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GridCellChoiceEditor(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_GridCellEnumEditor();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxGridCellEnumEditor *GetEntity() {
		return static_cast<wxGridCellEnumEditor *>(_pEntity);
	}
	inline wxGridCellEnumEditor *ReleaseEntity() {
		wxGridCellEnumEditor *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxGridCellEnumEditor");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
