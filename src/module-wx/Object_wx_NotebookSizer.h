//----------------------------------------------------------------------------
// wxNotebookSizer
// extracted from nbsizer.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_NOTEBOOKSIZER_H__
#define __OBJECT_WX_NOTEBOOKSIZER_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxNotebookSizer
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_NotebookSizer);

//----------------------------------------------------------------------------
// Object declaration for wxNotebookSizer
//----------------------------------------------------------------------------
class Object_wx_NotebookSizer : public Object_wx_Sizer {
public:
	Gura_DeclareObjectAccessor(wx_NotebookSizer)
public:
	inline Object_wx_NotebookSizer(wxNotebookSizer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Sizer(Gura_UserClass(wx_NotebookSizer), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_NotebookSizer(Class *pClass, wxNotebookSizer *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Sizer(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_NotebookSizer();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxNotebookSizer *GetEntity() {
		return dynamic_cast<wxNotebookSizer *>(_pEntity);
	}
	inline wxNotebookSizer *ReleaseEntity() {
		wxNotebookSizer *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxNotebookSizer");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
