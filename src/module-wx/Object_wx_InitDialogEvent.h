//----------------------------------------------------------------------------
// wxInitDialogEvent
// extracted from indlgevt.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_INITDIALOGEVENT_H__
#define __OBJECT_WX_INITDIALOGEVENT_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxInitDialogEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_InitDialogEvent);

//----------------------------------------------------------------------------
// Object declaration for wxInitDialogEvent
//----------------------------------------------------------------------------
class Object_wx_InitDialogEvent : public Object_wx_Event {
public:
	Gura_DeclareObjectAccessor(wx_InitDialogEvent)
public:
	inline Object_wx_InitDialogEvent(wxInitDialogEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(Gura_UserClass(wx_InitDialogEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_InitDialogEvent(Class *pClass, wxInitDialogEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_InitDialogEvent();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxInitDialogEvent *GetEntity() {
		return dynamic_cast<wxInitDialogEvent *>(_pEntity);
	}
	inline wxInitDialogEvent *ReleaseEntity() {
		wxInitDialogEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxInitDialogEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
