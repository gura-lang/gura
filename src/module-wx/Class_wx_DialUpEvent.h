//----------------------------------------------------------------------------
// wxDialUpEvent
// extracted from dialevt.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_DIALUPEVENT_H__
#define __CLASS_WX_DIALUPEVENT_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDialUpEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DialUpEvent);

//----------------------------------------------------------------------------
// Object declaration for wxDialUpEvent
//----------------------------------------------------------------------------
class Object_wx_DialUpEvent : public Object_wx_Event {
public:
	Gura_DeclareObjectAccessor(wx_DialUpEvent)
public:
	inline Object_wx_DialUpEvent(wxDialUpEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(Gura_UserClass(wx_DialUpEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_DialUpEvent(Class *pClass, wxDialUpEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_DialUpEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxDialUpEvent *GetEntity() {
		return dynamic_cast<wxDialUpEvent *>(_pEntity);
	}
	inline wxDialUpEvent *ReleaseEntity() {
		wxDialUpEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxDialUpEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
