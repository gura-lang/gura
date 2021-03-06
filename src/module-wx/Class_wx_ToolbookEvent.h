//----------------------------------------------------------------------------
// wxToolbookEvent
// (hand-coded)
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_TOOLBOOKEVENT_H__
#define __CLASS_WX_TOOLBOOKEVENT_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxToolbookEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ToolbookEvent);

//----------------------------------------------------------------------------
// Object declaration for wxToolbookEvent
//----------------------------------------------------------------------------
class Object_wx_ToolbookEvent : public Object_wx_BookCtrlBaseEvent {
public:
	Gura_DeclareObjectAccessor(wx_ToolbookEvent)
public:
	inline Object_wx_ToolbookEvent(wxToolbookEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_BookCtrlBaseEvent(Gura_UserClass(wx_ToolbookEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ToolbookEvent(Class *pClass, wxToolbookEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_BookCtrlBaseEvent(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ToolbookEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxToolbookEvent *GetEntity() {
		return dynamic_cast<wxToolbookEvent *>(_pEntity);
	}
	inline wxToolbookEvent *ReleaseEntity() {
		wxToolbookEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxToolbookEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
