//----------------------------------------------------------------------------
// wxContextMenuEvent
// extracted from cntxtevt.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_CONTEXTMENUEVENT_H__
#define __OBJECT_WX_CONTEXTMENUEVENT_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxContextMenuEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ContextMenuEvent);

//----------------------------------------------------------------------------
// Object declaration for wxContextMenuEvent
//----------------------------------------------------------------------------
class Object_wx_ContextMenuEvent : public Object_wx_CommandEvent {
public:
	Gura_DeclareObjectAccessor(wx_ContextMenuEvent)
public:
	inline Object_wx_ContextMenuEvent(wxContextMenuEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(Gura_UserClass(wx_ContextMenuEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ContextMenuEvent(Class *pClass, wxContextMenuEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ContextMenuEvent();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxContextMenuEvent *GetEntity() {
		return dynamic_cast<wxContextMenuEvent *>(_pEntity);
	}
	inline wxContextMenuEvent *ReleaseEntity() {
		wxContextMenuEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxContextMenuEvent");
		return true;
	}
};

}}

#endif
