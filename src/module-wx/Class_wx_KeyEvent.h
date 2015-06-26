//----------------------------------------------------------------------------
// wxKeyEvent
// extracted from keyevent.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_KEYEVENT_H__
#define __CLASS_WX_KEYEVENT_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxKeyEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_KeyEvent);

//----------------------------------------------------------------------------
// Object declaration for wxKeyEvent
//----------------------------------------------------------------------------
class Object_wx_KeyEvent : public Object_wx_Event {
public:
	Gura_DeclareObjectAccessor(wx_KeyEvent)
public:
	inline Object_wx_KeyEvent(wxKeyEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(Gura_UserClass(wx_KeyEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_KeyEvent(Class *pClass, wxKeyEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_KeyEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxKeyEvent *GetEntity() {
		return dynamic_cast<wxKeyEvent *>(_pEntity);
	}
	inline wxKeyEvent *ReleaseEntity() {
		wxKeyEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxKeyEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
