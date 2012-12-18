//----------------------------------------------------------------------------
// wxCalculateLayoutEvent
// extracted from calclevt.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_CALCULATELAYOUTEVENT_H__
#define __OBJECT_WX_CALCULATELAYOUTEVENT_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxCalculateLayoutEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_CalculateLayoutEvent);

//----------------------------------------------------------------------------
// Object declaration for wxCalculateLayoutEvent
//----------------------------------------------------------------------------
class Object_wx_CalculateLayoutEvent : public Object_wx_Event {
public:
	Gura_DeclareObjectAccessor(wx_CalculateLayoutEvent)
public:
	inline Object_wx_CalculateLayoutEvent(wxCalculateLayoutEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(Gura_UserClass(wx_CalculateLayoutEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_CalculateLayoutEvent(Class *pClass, wxCalculateLayoutEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_CalculateLayoutEvent();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxCalculateLayoutEvent *GetEntity() {
		return dynamic_cast<wxCalculateLayoutEvent *>(_pEntity);
	}
	inline wxCalculateLayoutEvent *ReleaseEntity() {
		wxCalculateLayoutEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxCalculateLayoutEvent");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
