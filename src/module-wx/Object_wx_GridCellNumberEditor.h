//----------------------------------------------------------------------------
// wxGridCellNumberEditor
// extracted from gridedit.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_GRIDCELLNUMBEREDITOR_H__
#define __OBJECT_WX_GRIDCELLNUMBEREDITOR_H__

Gura_BeginModule(wx)

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
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxGridCellNumberEditor *GetEntity() {
		return dynamic_cast<wxGridCellNumberEditor *>(_pEntity);
	}
	inline wxGridCellNumberEditor *ReleaseEntity() {
		wxGridCellNumberEditor *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxGridCellNumberEditor");
		return true;
	}
};

}}

#endif
