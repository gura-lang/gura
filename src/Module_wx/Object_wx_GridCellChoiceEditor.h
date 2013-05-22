//----------------------------------------------------------------------------
// wxGridCellChoiceEditor
// extracted from gridedit.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_GRIDCELLCHOICEEDITOR_H__
#define __OBJECT_WX_GRIDCELLCHOICEEDITOR_H__

Gura_BeginModule(wx)

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
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxGridCellChoiceEditor *GetEntity() {
		return dynamic_cast<wxGridCellChoiceEditor *>(_pEntity);
	}
	inline wxGridCellChoiceEditor *ReleaseEntity() {
		wxGridCellChoiceEditor *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxGridCellChoiceEditor");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
