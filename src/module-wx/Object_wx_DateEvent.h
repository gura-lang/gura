//----------------------------------------------------------------------------
// wxDateEvent
// extracted from dateevt.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_DATEEVENT_H__
#define __OBJECT_WX_DATEEVENT_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxDateEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_DateEvent);

//----------------------------------------------------------------------------
// Object declaration for wxDateEvent
//----------------------------------------------------------------------------
class Object_wx_DateEvent : public Object_wx_CommandEvent {
public:
	Gura_DeclareObjectAccessor(wx_DateEvent)
public:
	inline Object_wx_DateEvent(wxDateEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(Gura_UserClass(wx_DateEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_DateEvent(Class *pClass, wxDateEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_DateEvent();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxDateEvent *GetEntity() {
		return dynamic_cast<wxDateEvent *>(_pEntity);
	}
	inline wxDateEvent *ReleaseEntity() {
		wxDateEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxDateEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
