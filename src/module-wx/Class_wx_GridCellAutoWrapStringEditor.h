//----------------------------------------------------------------------------
// wxGridCellAutoWrapStringEditor
// extracted from gridedit.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_GRIDCELLAUTOWRAPSTRINGEDITOR_H__
#define __CLASS_WX_GRIDCELLAUTOWRAPSTRINGEDITOR_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGridCellAutoWrapStringEditor
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GridCellAutoWrapStringEditor);

//----------------------------------------------------------------------------
// Object declaration for wxGridCellAutoWrapStringEditor
//----------------------------------------------------------------------------
class Object_wx_GridCellAutoWrapStringEditor : public Object_wx_GridCellTextEditor {
public:
	Gura_DeclareObjectAccessor(wx_GridCellAutoWrapStringEditor)
public:
	inline Object_wx_GridCellAutoWrapStringEditor(wxGridCellAutoWrapStringEditor *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GridCellTextEditor(Gura_UserClass(wx_GridCellAutoWrapStringEditor), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_GridCellAutoWrapStringEditor(Class *pClass, wxGridCellAutoWrapStringEditor *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GridCellTextEditor(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_GridCellAutoWrapStringEditor();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxGridCellAutoWrapStringEditor *GetEntity() {
		return dynamic_cast<wxGridCellAutoWrapStringEditor *>(_pEntity);
	}
	inline wxGridCellAutoWrapStringEditor *ReleaseEntity() {
		wxGridCellAutoWrapStringEditor *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxGridCellAutoWrapStringEditor");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
