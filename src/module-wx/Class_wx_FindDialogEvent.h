//----------------------------------------------------------------------------
// wxFindDialogEvent
// extracted from fdrepdlg.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_FINDDIALOGEVENT_H__
#define __CLASS_WX_FINDDIALOGEVENT_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxFindDialogEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_FindDialogEvent);

//----------------------------------------------------------------------------
// Object declaration for wxFindDialogEvent
//----------------------------------------------------------------------------
class Object_wx_FindDialogEvent : public Object_wx_CommandEvent {
public:
	Gura_DeclareObjectAccessor(wx_FindDialogEvent)
public:
	inline Object_wx_FindDialogEvent(wxFindDialogEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(Gura_UserClass(wx_FindDialogEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_FindDialogEvent(Class *pClass, wxFindDialogEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_FindDialogEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxFindDialogEvent *GetEntity() {
		return dynamic_cast<wxFindDialogEvent *>(_pEntity);
	}
	inline wxFindDialogEvent *ReleaseEntity() {
		wxFindDialogEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxFindDialogEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
