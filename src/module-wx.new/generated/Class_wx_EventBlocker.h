//----------------------------------------------------------------------------
// wxEventBlocker
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_EVENTBLOCKER_H__
#define __CLASS_WX_EVENTBLOCKER_H__
#include <wx/event.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxEventBlocker
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_EventBlocker);

//----------------------------------------------------------------------------
// Object declaration for wxEventBlocker
//----------------------------------------------------------------------------
class Object_wx_EventBlocker : public Object_wx_EvtHandler {
public:
	Gura_DeclareObjectAccessor(wx_EventBlocker)
public:
	inline Object_wx_EventBlocker(wxEventBlocker *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_EvtHandler(Gura_UserClass(wx_EventBlocker), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_EventBlocker(Class *pClass, wxEventBlocker *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_EvtHandler(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_EventBlocker();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxEventBlocker *GetEntity() {
		return static_cast<wxEventBlocker *>(_pEntity);
	}
	inline wxEventBlocker *ReleaseEntity() {
		wxEventBlocker *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxEventBlocker");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
