//----------------------------------------------------------------------------
// wxIconizeEvent
// extracted from iconevt.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_ICONIZEEVENT_H__
#define __CLASS_WX_ICONIZEEVENT_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxIconizeEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_IconizeEvent);

//----------------------------------------------------------------------------
// Object declaration for wxIconizeEvent
//----------------------------------------------------------------------------
class Object_wx_IconizeEvent : public Object_wx_Event {
public:
	Gura_DeclareObjectAccessor(wx_IconizeEvent)
public:
	inline Object_wx_IconizeEvent(wxIconizeEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(Gura_UserClass(wx_IconizeEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_IconizeEvent(Class *pClass, wxIconizeEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_IconizeEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxIconizeEvent *GetEntity() {
		return dynamic_cast<wxIconizeEvent *>(_pEntity);
	}
	inline wxIconizeEvent *ReleaseEntity() {
		wxIconizeEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxIconizeEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
