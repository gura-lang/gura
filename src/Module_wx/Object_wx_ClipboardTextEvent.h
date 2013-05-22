//----------------------------------------------------------------------------
// wxClipboardTextEvent
// extracted from clipevent.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_CLIPBOARDTEXTEVENT_H__
#define __OBJECT_WX_CLIPBOARDTEXTEVENT_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxClipboardTextEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ClipboardTextEvent);

//----------------------------------------------------------------------------
// Object declaration for wxClipboardTextEvent
//----------------------------------------------------------------------------
class Object_wx_ClipboardTextEvent : public Object_wx_CommandEvent {
public:
	Gura_DeclareObjectAccessor(wx_ClipboardTextEvent)
public:
	inline Object_wx_ClipboardTextEvent(wxClipboardTextEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(Gura_UserClass(wx_ClipboardTextEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ClipboardTextEvent(Class *pClass, wxClipboardTextEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ClipboardTextEvent();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxClipboardTextEvent *GetEntity() {
		return dynamic_cast<wxClipboardTextEvent *>(_pEntity);
	}
	inline wxClipboardTextEvent *ReleaseEntity() {
		wxClipboardTextEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxClipboardTextEvent");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
