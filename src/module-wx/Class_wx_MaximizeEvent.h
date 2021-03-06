//----------------------------------------------------------------------------
// wxMaximizeEvent
// extracted from maxzevt.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_MAXIMIZEEVENT_H__
#define __CLASS_WX_MAXIMIZEEVENT_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxMaximizeEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_MaximizeEvent);

//----------------------------------------------------------------------------
// Object declaration for wxMaximizeEvent
//----------------------------------------------------------------------------
class Object_wx_MaximizeEvent : public Object_wx_Event {
public:
	Gura_DeclareObjectAccessor(wx_MaximizeEvent)
public:
	inline Object_wx_MaximizeEvent(wxMaximizeEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(Gura_UserClass(wx_MaximizeEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_MaximizeEvent(Class *pClass, wxMaximizeEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_MaximizeEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxMaximizeEvent *GetEntity() {
		return dynamic_cast<wxMaximizeEvent *>(_pEntity);
	}
	inline wxMaximizeEvent *ReleaseEntity() {
		wxMaximizeEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxMaximizeEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
