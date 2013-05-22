//----------------------------------------------------------------------------
// wxSetCursorEvent
// extracted from setcursorevt.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_SETCURSOREVENT_H__
#define __OBJECT_WX_SETCURSOREVENT_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxSetCursorEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_SetCursorEvent);

//----------------------------------------------------------------------------
// Object declaration for wxSetCursorEvent
//----------------------------------------------------------------------------
class Object_wx_SetCursorEvent : public Object_wx_Event {
public:
	Gura_DeclareObjectAccessor(wx_SetCursorEvent)
public:
	inline Object_wx_SetCursorEvent(wxSetCursorEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(Gura_UserClass(wx_SetCursorEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_SetCursorEvent(Class *pClass, wxSetCursorEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_SetCursorEvent();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxSetCursorEvent *GetEntity() {
		return dynamic_cast<wxSetCursorEvent *>(_pEntity);
	}
	inline wxSetCursorEvent *ReleaseEntity() {
		wxSetCursorEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxSetCursorEvent");
		return true;
	}
};

}}

#endif
