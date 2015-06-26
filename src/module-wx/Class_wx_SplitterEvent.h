//----------------------------------------------------------------------------
// wxSplitterEvent
// extracted from splitevt.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_SPLITTEREVENT_H__
#define __CLASS_WX_SPLITTEREVENT_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxSplitterEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_SplitterEvent);

//----------------------------------------------------------------------------
// Object declaration for wxSplitterEvent
//----------------------------------------------------------------------------
class Object_wx_SplitterEvent : public Object_wx_NotifyEvent {
public:
	Gura_DeclareObjectAccessor(wx_SplitterEvent)
public:
	inline Object_wx_SplitterEvent(wxSplitterEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_NotifyEvent(Gura_UserClass(wx_SplitterEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_SplitterEvent(Class *pClass, wxSplitterEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_NotifyEvent(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_SplitterEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxSplitterEvent *GetEntity() {
		return dynamic_cast<wxSplitterEvent *>(_pEntity);
	}
	inline wxSplitterEvent *ReleaseEntity() {
		wxSplitterEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxSplitterEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
