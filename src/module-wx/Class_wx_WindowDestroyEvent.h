//----------------------------------------------------------------------------
// wxWindowDestroyEvent
// extracted from destroyevt.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_WINDOWDESTROYEVENT_H__
#define __CLASS_WX_WINDOWDESTROYEVENT_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxWindowDestroyEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_WindowDestroyEvent);

//----------------------------------------------------------------------------
// Object declaration for wxWindowDestroyEvent
//----------------------------------------------------------------------------
class Object_wx_WindowDestroyEvent : public Object_wx_CommandEvent {
public:
	Gura_DeclareObjectAccessor(wx_WindowDestroyEvent)
public:
	inline Object_wx_WindowDestroyEvent(wxWindowDestroyEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(Gura_UserClass(wx_WindowDestroyEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_WindowDestroyEvent(Class *pClass, wxWindowDestroyEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_WindowDestroyEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxWindowDestroyEvent *GetEntity() {
		return dynamic_cast<wxWindowDestroyEvent *>(_pEntity);
	}
	inline wxWindowDestroyEvent *ReleaseEntity() {
		wxWindowDestroyEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxWindowDestroyEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
