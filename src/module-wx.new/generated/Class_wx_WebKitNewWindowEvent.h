//----------------------------------------------------------------------------
// wxWebKitNewWindowEvent
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_WEBKITNEWWINDOWEVENT_H__
#define __CLASS_WX_WEBKITNEWWINDOWEVENT_H__
#include <wx/html/webkit.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxWebKitNewWindowEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_WebKitNewWindowEvent);

//----------------------------------------------------------------------------
// Object declaration for wxWebKitNewWindowEvent
//----------------------------------------------------------------------------
class Object_wx_WebKitNewWindowEvent : public Object_wx_CommandEvent {
public:
	Gura_DeclareObjectAccessor(wx_WebKitNewWindowEvent)
public:
	inline Object_wx_WebKitNewWindowEvent(wxWebKitNewWindowEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(Gura_UserClass(wx_WebKitNewWindowEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_WebKitNewWindowEvent(Class *pClass, wxWebKitNewWindowEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_WebKitNewWindowEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxWebKitNewWindowEvent *GetEntity() {
		return static_cast<wxWebKitNewWindowEvent *>(_pEntity);
	}
	inline wxWebKitNewWindowEvent *ReleaseEntity() {
		wxWebKitNewWindowEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxWebKitNewWindowEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
