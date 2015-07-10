//----------------------------------------------------------------------------
// wxProcessEvent
// extracted from procevt.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_PROCESSEVENT_H__
#define __CLASS_WX_PROCESSEVENT_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxProcessEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ProcessEvent);

//----------------------------------------------------------------------------
// Object declaration for wxProcessEvent
//----------------------------------------------------------------------------
class Object_wx_ProcessEvent : public Object_wx_Event {
public:
	Gura_DeclareObjectAccessor(wx_ProcessEvent)
public:
	inline Object_wx_ProcessEvent(wxProcessEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(Gura_UserClass(wx_ProcessEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ProcessEvent(Class *pClass, wxProcessEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ProcessEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxProcessEvent *GetEntity() {
		return dynamic_cast<wxProcessEvent *>(_pEntity);
	}
	inline wxProcessEvent *ReleaseEntity() {
		wxProcessEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxProcessEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
