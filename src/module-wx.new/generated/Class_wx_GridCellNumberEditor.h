//----------------------------------------------------------------------------
// wxGridCellNumberEditor
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_GRIDCELLNUMBEREDITOR_H__
#define __CLASS_WX_GRIDCELLNUMBEREDITOR_H__
#include <wx/grid.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGridCellNumberEditor
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GridCellNumberEditor);

//----------------------------------------------------------------------------
// Object declaration for wxGridCellNumberEditor
//----------------------------------------------------------------------------
class Object_wx_GridCellNumberEditor : public Object_wx_GridCellTextEditor {
public:
	Gura_DeclareObjectAccessor(wx_GridCellNumberEditor)
public:
	inline Object_wx_GridCellNumberEditor(wxGridCellNumberEditor *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GridCellTextEditor(Gura_UserClass(wx_GridCellNumberEditor), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_GridCellNumberEditor(Class *pClass, wxGridCellNumberEditor *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GridCellTextEditor(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_GridCellNumberEditor();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxGridCellNumberEditor *GetEntity() {
		return static_cast<wxGridCellNumberEditor *>(_pEntity);
	}
	inline wxGridCellNumberEditor *ReleaseEntity() {
		wxGridCellNumberEditor *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxGridCellNumberEditor");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
