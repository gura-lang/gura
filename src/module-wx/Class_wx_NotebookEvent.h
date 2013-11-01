//----------------------------------------------------------------------------
// wxNotebookEvent
// extracted from noteevt.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_NOTEBOOKEVENT_H__
#define __CLASS_WX_NOTEBOOKEVENT_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxNotebookEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_NotebookEvent);

//----------------------------------------------------------------------------
// Object declaration for wxNotebookEvent
//----------------------------------------------------------------------------
class Object_wx_NotebookEvent : public Object_wx_BookCtrlBaseEvent {
public:
	Gura_DeclareObjectAccessor(wx_NotebookEvent)
public:
	inline Object_wx_NotebookEvent(wxNotebookEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_BookCtrlBaseEvent(Gura_UserClass(wx_NotebookEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_NotebookEvent(Class *pClass, wxNotebookEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_BookCtrlBaseEvent(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_NotebookEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxNotebookEvent *GetEntity() {
		return dynamic_cast<wxNotebookEvent *>(_pEntity);
	}
	inline wxNotebookEvent *ReleaseEntity() {
		wxNotebookEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxNotebookEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
