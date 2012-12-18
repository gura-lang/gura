//----------------------------------------------------------------------------
// wxTreeEvent
// extracted from treeevt.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_TREEEVENT_H__
#define __OBJECT_WX_TREEEVENT_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTreeEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_TreeEvent);

//----------------------------------------------------------------------------
// Object declaration for wxTreeEvent
//----------------------------------------------------------------------------
class Object_wx_TreeEvent : public Object_wx_NotifyEvent {
public:
	Gura_DeclareObjectAccessor(wx_TreeEvent)
public:
	inline Object_wx_TreeEvent(wxTreeEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_NotifyEvent(Gura_UserClass(wx_TreeEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_TreeEvent(Class *pClass, wxTreeEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_NotifyEvent(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_TreeEvent();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxTreeEvent *GetEntity() {
		return dynamic_cast<wxTreeEvent *>(_pEntity);
	}
	inline wxTreeEvent *ReleaseEntity() {
		wxTreeEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxTreeEvent");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
