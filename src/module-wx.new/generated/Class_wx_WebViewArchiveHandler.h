//----------------------------------------------------------------------------
// wxWebViewArchiveHandler
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_WEBVIEWARCHIVEHANDLER_H__
#define __CLASS_WX_WEBVIEWARCHIVEHANDLER_H__
#include <wx/webviewarchivehandler.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxWebViewArchiveHandler
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_WebViewArchiveHandler);

//----------------------------------------------------------------------------
// Object declaration for wxWebViewArchiveHandler
//----------------------------------------------------------------------------
class Object_wx_WebViewArchiveHandler : public Object_wx_WebViewHandler {
public:
	Gura_DeclareObjectAccessor(wx_WebViewArchiveHandler)
public:
	inline Object_wx_WebViewArchiveHandler(wxWebViewArchiveHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_WebViewHandler(Gura_UserClass(wx_WebViewArchiveHandler), pEntity, pObserver, ownerFlag) {}
	inline Object_wx_WebViewArchiveHandler(Class *pClass, wxWebViewArchiveHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object_wx_WebViewHandler(pClass, pEntity, pObserver, ownerFlag) {}
	virtual ~Object_wx_WebViewArchiveHandler();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline wxWebViewArchiveHandler *GetEntity() {
		return static_cast<wxWebViewArchiveHandler *>(_pEntity);
	}
	inline wxWebViewArchiveHandler *ReleaseEntity() {
		wxWebViewArchiveHandler *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline bool IsInvalid(Environment &env) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(env, "wxWebViewArchiveHandler");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
