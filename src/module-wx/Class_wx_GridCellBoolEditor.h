//----------------------------------------------------------------------------
// wxGridCellBoolEditor
// extracted from gridedit.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_GRIDCELLBOOLEDITOR_H__
#define __CLASS_WX_GRIDCELLBOOLEDITOR_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGridCellBoolEditor
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GridCellBoolEditor);

//----------------------------------------------------------------------------
// Object declaration for wxGridCellBoolEditor
//----------------------------------------------------------------------------
class Object_wx_GridCellBoolEditor : public Object_wx_GridCellEditor {
public:
	Gura_DeclareObjectAccessor(wx_GridCellBoolEditor)
public:
	inline Object_wx_GridCellBoolEditor(wxGridCellBoolEditor *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GridCellEditor(Gura_UserClass(wx_GridCellBoolEditor), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_GridCellBoolEditor(Class *pClass, wxGridCellBoolEditor *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GridCellEditor(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_GridCellBoolEditor();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxGridCellBoolEditor *GetEntity() {
		return dynamic_cast<wxGridCellBoolEditor *>(_pEntity);
	}
	inline wxGridCellBoolEditor *ReleaseEntity() {
		wxGridCellBoolEditor *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxGridCellBoolEditor");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
