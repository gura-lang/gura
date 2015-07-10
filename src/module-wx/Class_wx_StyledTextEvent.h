//----------------------------------------------------------------------------
// wxStyledTextEvent
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_STYLEDTEXTEVENT_H__
#define __CLASS_WX_STYLEDTEXTEVENT_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxStyledTextEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_StyledTextEvent);

//----------------------------------------------------------------------------
// Object declaration for wxStyledTextEvent
//----------------------------------------------------------------------------
class Object_wx_StyledTextEvent : public Object_wx_CommandEvent {
public:
	Gura_DeclareObjectAccessor(wx_StyledTextEvent)
public:
	inline Object_wx_StyledTextEvent(wxStyledTextEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(Gura_UserClass(wx_StyledTextEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_StyledTextEvent(Class *pClass, wxStyledTextEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_StyledTextEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxStyledTextEvent *GetEntity() {
		return dynamic_cast<wxStyledTextEvent *>(_pEntity);
	}
	inline wxStyledTextEvent *ReleaseEntity() {
		wxStyledTextEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxStyledTextEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
