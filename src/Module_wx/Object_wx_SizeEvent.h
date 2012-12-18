//----------------------------------------------------------------------------
// wxSizeEvent
// extracted from sizeevt.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_SIZEEVENT_H__
#define __OBJECT_WX_SIZEEVENT_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxSizeEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_SizeEvent);

//----------------------------------------------------------------------------
// Object declaration for wxSizeEvent
//----------------------------------------------------------------------------
class Object_wx_SizeEvent : public Object_wx_Event {
public:
	Gura_DeclareObjectAccessor(wx_SizeEvent)
public:
	inline Object_wx_SizeEvent(wxSizeEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(Gura_UserClass(wx_SizeEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_SizeEvent(Class *pClass, wxSizeEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_SizeEvent();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxSizeEvent *GetEntity() {
		return dynamic_cast<wxSizeEvent *>(_pEntity);
	}
	inline wxSizeEvent *ReleaseEntity() {
		wxSizeEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxSizeEvent");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
