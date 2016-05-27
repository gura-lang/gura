//----------------------------------------------------------------------------
// wxWebKitBeforeLoadEvent
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_WEBKITBEFORELOADEVENT_H__
#define __CLASS_WX_WEBKITBEFORELOADEVENT_H__
#include <wx/html/webkit.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxWebKitBeforeLoadEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_WebKitBeforeLoadEvent);

//----------------------------------------------------------------------------
// Object declaration for wxWebKitBeforeLoadEvent
//----------------------------------------------------------------------------
class Object_wx_WebKitBeforeLoadEvent : public Object_wx_CommandEvent {
public:
	Gura_DeclareObjectAccessor(wx_WebKitBeforeLoadEvent)
public:
	inline Object_wx_WebKitBeforeLoadEvent(wxWebKitBeforeLoadEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(Gura_UserClass(wx_WebKitBeforeLoadEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_WebKitBeforeLoadEvent(Class *pClass, wxWebKitBeforeLoadEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_CommandEvent(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_WebKitBeforeLoadEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxWebKitBeforeLoadEvent *GetEntity() {
		return static_cast<wxWebKitBeforeLoadEvent *>(_pEntity);
	}
	inline wxWebKitBeforeLoadEvent *ReleaseEntity() {
		wxWebKitBeforeLoadEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxWebKitBeforeLoadEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
