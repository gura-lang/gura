//----------------------------------------------------------------------------
// wxWebViewEvent
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_WEBVIEWEVENT_H__
#define __CLASS_WX_WEBVIEWEVENT_H__
#include <wx/webview.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxWebViewEvent
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_WebViewEvent);

//----------------------------------------------------------------------------
// Object declaration for wxWebViewEvent
//----------------------------------------------------------------------------
class Object_wx_WebViewEvent : public Object_wx_NotifyEvent {
public:
	Gura_DeclareObjectAccessor(wx_WebViewEvent)
public:
	inline Object_wx_WebViewEvent(wxWebViewEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_NotifyEvent(Gura_UserClass(wx_WebViewEvent), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_WebViewEvent(Class *pClass, wxWebViewEvent *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_NotifyEvent(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_WebViewEvent();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxWebViewEvent *GetEntity() {
		return static_cast<wxWebViewEvent *>(_pEntity);
	}
	inline wxWebViewEvent *ReleaseEntity() {
		wxWebViewEvent *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxWebViewEvent");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
