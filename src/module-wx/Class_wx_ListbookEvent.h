//----------------------------------------------------------------------------
// wxListbookEvent
// (hand-coded)
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_LISTBOOKEVENT_H__
#define __CLASS_WX_LISTBOOKEVENT_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxListbookEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ListbookEvent);

//----------------------------------------------------------------------------
// Object declaration for wxListbookEvent
//----------------------------------------------------------------------------
class Object_wx_ListbookEvent : public Object_wx_BookCtrlBaseEvent {
public:
	Gura_DeclareObjectAccessor(wx_ListbookEvent)
public:
	inline Object_wx_ListbookEvent(wxListbookEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_BookCtrlBaseEvent(Gura_UserClass(wx_ListbookEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ListbookEvent(Class *pClass, wxListbookEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_BookCtrlBaseEvent(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ListbookEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxListbookEvent *GetEntity() {
		return dynamic_cast<wxListbookEvent *>(_pEntity);
	}
	inline wxListbookEvent *ReleaseEntity() {
		wxListbookEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxListbookEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
