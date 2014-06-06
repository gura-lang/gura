//----------------------------------------------------------------------------
// wxShowEvent
// extracted from sizeevt.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_SHOWEVENT_H__
#define __CLASS_WX_SHOWEVENT_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxShowEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ShowEvent);

//----------------------------------------------------------------------------
// Object declaration for wxShowEvent
//----------------------------------------------------------------------------
class Object_wx_ShowEvent : public Object_wx_Event {
public:
	Gura_DeclareObjectAccessor(wx_ShowEvent)
public:
	inline Object_wx_ShowEvent(wxShowEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(Gura_UserClass(wx_ShowEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ShowEvent(Class *pClass, wxShowEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ShowEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxShowEvent *GetEntity() {
		return dynamic_cast<wxShowEvent *>(_pEntity);
	}
	inline wxShowEvent *ReleaseEntity() {
		wxShowEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxShowEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
