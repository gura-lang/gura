//----------------------------------------------------------------------------
// wxWebView
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_WEBVIEW_H__
#define __CLASS_WX_WEBVIEW_H__
#include <wx/webview.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxWebView
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_WebView);

//----------------------------------------------------------------------------
// Object declaration for wxWebView
//----------------------------------------------------------------------------
class Object_wx_WebView : public Object_wx_Control {
public:
	Gura_DeclareObjectAccessor(wx_WebView)
public:
	inline Object_wx_WebView(wxWebView *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(Gura_UserClass(wx_WebView), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_WebView(Class *pClass, wxWebView *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Control(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_WebView();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxWebView *GetEntity() {
		return static_cast<wxWebView *>(_pEntity);
	}
	inline wxWebView *ReleaseEntity() {
		wxWebView *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxWebView");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
