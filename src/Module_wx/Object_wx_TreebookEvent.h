//----------------------------------------------------------------------------
// wxTreebookEvent
// extracted from treebookevent.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_TREEBOOKEVENT_H__
#define __OBJECT_WX_TREEBOOKEVENT_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxTreebookEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_TreebookEvent);

//----------------------------------------------------------------------------
// Object declaration for wxTreebookEvent
//----------------------------------------------------------------------------
class Object_wx_TreebookEvent : public Object_wx_BookCtrlBaseEvent {
public:
	Gura_DeclareObjectAccessor(wx_TreebookEvent)
public:
	inline Object_wx_TreebookEvent(wxTreebookEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_BookCtrlBaseEvent(Gura_UserClass(wx_TreebookEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_TreebookEvent(Class *pClass, wxTreebookEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_BookCtrlBaseEvent(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_TreebookEvent();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxTreebookEvent *GetEntity() {
		return dynamic_cast<wxTreebookEvent *>(_pEntity);
	}
	inline wxTreebookEvent *ReleaseEntity() {
		wxTreebookEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxTreebookEvent");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
