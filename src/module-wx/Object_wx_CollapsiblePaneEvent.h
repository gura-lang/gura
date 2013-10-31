//----------------------------------------------------------------------------
// wxCollapsiblePaneEvent
// extracted from collpane.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_COLLAPSIBLEPANEEVENT_H__
#define __OBJECT_WX_COLLAPSIBLEPANEEVENT_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxCollapsiblePaneEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_CollapsiblePaneEvent);

//----------------------------------------------------------------------------
// Object declaration for wxCollapsiblePaneEvent
//----------------------------------------------------------------------------
class Object_wx_CollapsiblePaneEvent : public Object_wx_CommandEvent {
public:
	Gura_DeclareObjectAccessor(wx_CollapsiblePaneEvent)
public:
	inline Object_wx_CollapsiblePaneEvent(wxCollapsiblePaneEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(Gura_UserClass(wx_CollapsiblePaneEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_CollapsiblePaneEvent(Class *pClass, wxCollapsiblePaneEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_CollapsiblePaneEvent();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxCollapsiblePaneEvent *GetEntity() {
		return dynamic_cast<wxCollapsiblePaneEvent *>(_pEntity);
	}
	inline wxCollapsiblePaneEvent *ReleaseEntity() {
		wxCollapsiblePaneEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxCollapsiblePaneEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
