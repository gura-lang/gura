//----------------------------------------------------------------------------
// wxEvent
// extracted from event.tex
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_EVENT_H__
#define __OBJECT_WX_EVENT_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_Event);

//----------------------------------------------------------------------------
// Object declaration for wxEvent
//----------------------------------------------------------------------------
class Object_wx_Event : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_Event)
public:
	inline Object_wx_Event(wxEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_Event), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_Event(Class *pClass, wxEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_Event();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline wxEvent *GetEntity() {
		return dynamic_cast<wxEvent *>(_pEntity);
	}
	inline wxEvent *ReleaseEntity() {
		wxEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxEvent");
		return true;
	}
public:
	static void OnModuleEntry(Environment &env, Signal sig);
};

}}

#endif
