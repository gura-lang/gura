//----------------------------------------------------------------------------
// wxGridCellEditor
// extracted from gridedit.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_GRIDCELLEDITOR_H__
#define __OBJECT_WX_GRIDCELLEDITOR_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGridCellEditor
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GridCellEditor);

//----------------------------------------------------------------------------
// Object declaration for wxGridCellEditor
//----------------------------------------------------------------------------
class Object_wx_GridCellEditor : public Object_wx_GridCellWorker {
public:
	Gura_DeclareObjectAccessor(wx_GridCellEditor)
public:
	inline Object_wx_GridCellEditor(wxGridCellEditor *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GridCellWorker(Gura_UserClass(wx_GridCellEditor), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_GridCellEditor(Class *pClass, wxGridCellEditor *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_GridCellWorker(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_GridCellEditor();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxGridCellEditor *GetEntity() {
		return dynamic_cast<wxGridCellEditor *>(_pEntity);
	}
	inline wxGridCellEditor *ReleaseEntity() {
		wxGridCellEditor *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxGridCellEditor");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
