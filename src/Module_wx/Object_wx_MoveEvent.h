//----------------------------------------------------------------------------
// wxMoveEvent
// extracted from moveevt.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_MOVEEVENT_H__
#define __OBJECT_WX_MOVEEVENT_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxMoveEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_MoveEvent);

//----------------------------------------------------------------------------
// Object declaration for wxMoveEvent
//----------------------------------------------------------------------------
class Object_wx_MoveEvent : public Object_wx_Event {
public:
	Gura_DeclareObjectAccessor(wx_MoveEvent)
public:
	inline Object_wx_MoveEvent(wxMoveEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(Gura_UserClass(wx_MoveEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_MoveEvent(Class *pClass, wxMoveEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_MoveEvent();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxMoveEvent *GetEntity() {
		return dynamic_cast<wxMoveEvent *>(_pEntity);
	}
	inline wxMoveEvent *ReleaseEntity() {
		wxMoveEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxMoveEvent");
		return true;
	}
};

}}

#endif
