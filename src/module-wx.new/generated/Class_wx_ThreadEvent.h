//----------------------------------------------------------------------------
// wxThreadEvent
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_THREADEVENT_H__
#define __CLASS_WX_THREADEVENT_H__
#include <wx/event.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxThreadEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_ThreadEvent);

//----------------------------------------------------------------------------
// Object declaration for wxThreadEvent
//----------------------------------------------------------------------------
class Object_wx_ThreadEvent : public Object_wx_Event {
public:
	Gura_DeclareObjectAccessor(wx_ThreadEvent)
public:
	inline Object_wx_ThreadEvent(wxThreadEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(Gura_UserClass(wx_ThreadEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_ThreadEvent(Class *pClass, wxThreadEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Event(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_ThreadEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxThreadEvent *GetEntity() {
		return static_cast<wxThreadEvent *>(_pEntity);
	}
	inline wxThreadEvent *ReleaseEntity() {
		wxThreadEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxThreadEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
