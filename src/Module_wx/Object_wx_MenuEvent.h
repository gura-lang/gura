//----------------------------------------------------------------------------
// wxMenuEvent
// extracted from menuevt.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_MENUEVENT_H__
#define __OBJECT_WX_MENUEVENT_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxMenuEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_MenuEvent);

//----------------------------------------------------------------------------
// Object declaration for wxMenuEvent
//----------------------------------------------------------------------------
class Object_wx_MenuEvent : public Object_wx_Event {
public:
	Gura_DeclareObjectAccessor(wx_MenuEvent)
public:
	inline Object_wx_MenuEvent(wxMenuEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(Gura_UserClass(wx_MenuEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_MenuEvent(Class *pClass, wxMenuEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_MenuEvent();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxMenuEvent *GetEntity() {
		return dynamic_cast<wxMenuEvent *>(_pEntity);
	}
	inline wxMenuEvent *ReleaseEntity() {
		wxMenuEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxMenuEvent");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
