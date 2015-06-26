//----------------------------------------------------------------------------
// wxSashEvent
// extracted from sashevt.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_SASHEVENT_H__
#define __CLASS_WX_SASHEVENT_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxSashEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_SashEvent);

//----------------------------------------------------------------------------
// Object declaration for wxSashEvent
//----------------------------------------------------------------------------
class Object_wx_SashEvent : public Object_wx_CommandEvent {
public:
	Gura_DeclareObjectAccessor(wx_SashEvent)
public:
	inline Object_wx_SashEvent(wxSashEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(Gura_UserClass(wx_SashEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_SashEvent(Class *pClass, wxSashEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_SashEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxSashEvent *GetEntity() {
		return dynamic_cast<wxSashEvent *>(_pEntity);
	}
	inline wxSashEvent *ReleaseEntity() {
		wxSashEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxSashEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
