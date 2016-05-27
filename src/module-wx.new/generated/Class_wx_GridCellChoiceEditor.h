//----------------------------------------------------------------------------
// wxGridCellChoiceEditor
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_GRIDCELLCHOICEEDITOR_H__
#define __CLASS_WX_GRIDCELLCHOICEEDITOR_H__
#include <wx/grid.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGridCellChoiceEditor
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GridCellChoiceEditor);

//----------------------------------------------------------------------------
// Object declaration for wxGridCellChoiceEditor
//----------------------------------------------------------------------------
class Object_wx_GridCellChoiceEditor : public Object_wx_GridCellEditor {
public:
	Gura_DeclareObjectAccessor(wx_GridCellChoiceEditor)
public:
	inline Object_wx_GridCellChoiceEditor(wxGridCellChoiceEditor *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GridCellEditor(Gura_UserClass(wx_GridCellChoiceEditor), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_GridCellChoiceEditor(Class *pClass, wxGridCellChoiceEditor *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GridCellEditor(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_GridCellChoiceEditor();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxGridCellChoiceEditor *GetEntity() {
		return static_cast<wxGridCellChoiceEditor *>(_pEntity);
	}
	inline wxGridCellChoiceEditor *ReleaseEntity() {
		wxGridCellChoiceEditor *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxGridCellChoiceEditor");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
