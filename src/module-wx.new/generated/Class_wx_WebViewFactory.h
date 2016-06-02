//----------------------------------------------------------------------------
// wxWebViewFactory
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_WEBVIEWFACTORY_H__
#define __CLASS_WX_WEBVIEWFACTORY_H__
#include <wx/webview.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxWebViewFactory
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_WebViewFactory);

//----------------------------------------------------------------------------
// Object declaration for wxWebViewFactory
//----------------------------------------------------------------------------
class Object_wx_WebViewFactory : public Object_wx_Object {
public:
	Gura_DeclareObjectAccessor(wx_WebViewFactory)
public:
	inline Object_wx_WebViewFactory(wxWebViewFactory *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(Gura_UserClass(wx_WebViewFactory), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_WebViewFactory(Class *pClass, wxWebViewFactory *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_Object(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_WebViewFactory();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxWebViewFactory *GetEntity() {
		return static_cast<wxWebViewFactory *>(_pEntity);
	}
	inline wxWebViewFactory *ReleaseEntity() {
		wxWebViewFactory *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxWebViewFactory");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
