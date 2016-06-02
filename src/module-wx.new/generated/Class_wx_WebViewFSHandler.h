//----------------------------------------------------------------------------
// wxWebViewFSHandler
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_WEBVIEWFSHANDLER_H__
#define __CLASS_WX_WEBVIEWFSHANDLER_H__
#include <wx/webviewfshandler.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxWebViewFSHandler
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_WebViewFSHandler);

//----------------------------------------------------------------------------
// Object declaration for wxWebViewFSHandler
//----------------------------------------------------------------------------
class Object_wx_WebViewFSHandler : public Object_wx_WebViewHandler {
public:
	Gura_DeclareObjectAccessor(wx_WebViewFSHandler)
public:
	inline Object_wx_WebViewFSHandler(wxWebViewFSHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_WebViewHandler(Gura_UserClass(wx_WebViewFSHandler), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_WebViewFSHandler(Class *pClass, wxWebViewFSHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_WebViewHandler(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_WebViewFSHandler();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxWebViewFSHandler *GetEntity() {
		return static_cast<wxWebViewFSHandler *>(_pEntity);
	}
	inline wxWebViewFSHandler *ReleaseEntity() {
		wxWebViewFSHandler *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxWebViewFSHandler");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
