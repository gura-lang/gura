//----------------------------------------------------------------------------
// wxHelpEvent
// extracted from helpevt.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_HELPEVENT_H__
#define __OBJECT_WX_HELPEVENT_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxHelpEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_HelpEvent);

//----------------------------------------------------------------------------
// Object declaration for wxHelpEvent
//----------------------------------------------------------------------------
class Object_wx_HelpEvent : public Object_wx_CommandEvent {
public:
	Gura_DeclareObjectAccessor(wx_HelpEvent)
public:
	inline Object_wx_HelpEvent(wxHelpEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(Gura_UserClass(wx_HelpEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_HelpEvent(Class *pClass, wxHelpEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_HelpEvent();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxHelpEvent *GetEntity() {
		return dynamic_cast<wxHelpEvent *>(_pEntity);
	}
	inline wxHelpEvent *ReleaseEntity() {
		wxHelpEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxHelpEvent");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
