//----------------------------------------------------------------------------
// wxListEvent
// extracted from listevt.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_LISTEVENT_H__
#define __CLASS_WX_LISTEVENT_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxListEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ListEvent);

//----------------------------------------------------------------------------
// Object declaration for wxListEvent
//----------------------------------------------------------------------------
class Object_wx_ListEvent : public Object_wx_NotifyEvent {
public:
	Gura_DeclareObjectAccessor(wx_ListEvent)
public:
	inline Object_wx_ListEvent(wxListEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_NotifyEvent(Gura_UserClass(wx_ListEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ListEvent(Class *pClass, wxListEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_NotifyEvent(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ListEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxListEvent *GetEntity() {
		return dynamic_cast<wxListEvent *>(_pEntity);
	}
	inline wxListEvent *ReleaseEntity() {
		wxListEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxListEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
