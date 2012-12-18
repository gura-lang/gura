//----------------------------------------------------------------------------
// wxGridEditorCreatedEvent
// extracted from gridevt.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_GRIDEDITORCREATEDEVENT_H__
#define __OBJECT_WX_GRIDEDITORCREATEDEVENT_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxGridEditorCreatedEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_GridEditorCreatedEvent);

//----------------------------------------------------------------------------
// Object declaration for wxGridEditorCreatedEvent
//----------------------------------------------------------------------------
class Object_wx_GridEditorCreatedEvent : public Object_wx_Event {
public:
	Gura_DeclareObjectAccessor(wx_GridEditorCreatedEvent)
public:
	inline Object_wx_GridEditorCreatedEvent(wxGridEditorCreatedEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(Gura_UserClass(wx_GridEditorCreatedEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_GridEditorCreatedEvent(Class *pClass, wxGridEditorCreatedEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_GridEditorCreatedEvent();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxGridEditorCreatedEvent *GetEntity() {
		return dynamic_cast<wxGridEditorCreatedEvent *>(_pEntity);
	}
	inline wxGridEditorCreatedEvent *ReleaseEntity() {
		wxGridEditorCreatedEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxGridEditorCreatedEvent");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
