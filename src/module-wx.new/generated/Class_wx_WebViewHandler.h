//----------------------------------------------------------------------------
// wxWebViewHandler
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_WEBVIEWHANDLER_H__
#define __CLASS_WX_WEBVIEWHANDLER_H__
#include <wx/webview.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxWebViewHandler
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_WebViewHandler);

//----------------------------------------------------------------------------
// Object declaration for wxWebViewHandler
//----------------------------------------------------------------------------
class Object_wx_WebViewHandler : public Object {
protected:
	wxWebViewHandler *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_WebViewHandler)
public:
	inline Object_wx_WebViewHandler(wxWebViewHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_WebViewHandler(Class *pClass, wxWebViewHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_WebViewHandler();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxWebViewHandler *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxWebViewHandler *GetEntity() {
		return static_cast<wxWebViewHandler *>(_pEntity);
	}
	inline wxWebViewHandler *ReleaseEntity() {
		wxWebViewHandler *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxWebViewHandler");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
