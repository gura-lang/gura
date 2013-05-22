//----------------------------------------------------------------------------
// wxGridCellTextEditor
// extracted from gridedit.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_GRIDCELLTEXTEDITOR_H__
#define __OBJECT_WX_GRIDCELLTEXTEDITOR_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGridCellTextEditor
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GridCellTextEditor);

//----------------------------------------------------------------------------
// Object declaration for wxGridCellTextEditor
//----------------------------------------------------------------------------
class Object_wx_GridCellTextEditor : public Object_wx_GridCellEditor {
public:
	Gura_DeclareObjectAccessor(wx_GridCellTextEditor)
public:
	inline Object_wx_GridCellTextEditor(wxGridCellTextEditor *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GridCellEditor(Gura_UserClass(wx_GridCellTextEditor), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_GridCellTextEditor(Class *pClass, wxGridCellTextEditor *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GridCellEditor(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_GridCellTextEditor();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxGridCellTextEditor *GetEntity() {
		return dynamic_cast<wxGridCellTextEditor *>(_pEntity);
	}
	inline wxGridCellTextEditor *ReleaseEntity() {
		wxGridCellTextEditor *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxGridCellTextEditor");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
