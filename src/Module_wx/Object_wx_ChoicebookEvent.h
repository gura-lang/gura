//----------------------------------------------------------------------------
// wxChoicebookEvent
// (hand-coded)
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_CHOICEBOOKEVENT_H__
#define __OBJECT_WX_CHOICEBOOKEVENT_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxChoicebookEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ChoicebookEvent);

//----------------------------------------------------------------------------
// Object declaration for wxChoicebookEvent
//----------------------------------------------------------------------------
class Object_wx_ChoicebookEvent : public Object_wx_BookCtrlBaseEvent {
public:
	Gura_DeclareObjectAccessor(wx_ChoicebookEvent)
public:
	inline Object_wx_ChoicebookEvent(wxChoicebookEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_BookCtrlBaseEvent(Gura_UserClass(wx_ChoicebookEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ChoicebookEvent(Class *pClass, wxChoicebookEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_BookCtrlBaseEvent(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ChoicebookEvent();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxChoicebookEvent *GetEntity() {
		return dynamic_cast<wxChoicebookEvent *>(_pEntity);
	}
	inline wxChoicebookEvent *ReleaseEntity() {
		wxChoicebookEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxChoicebookEvent");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
