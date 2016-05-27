//----------------------------------------------------------------------------
// wxWebViewHistoryItem
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_WEBVIEWHISTORYITEM_H__
#define __CLASS_WX_WEBVIEWHISTORYITEM_H__
#include <wx/webview.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxWebViewHistoryItem
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_WebViewHistoryItem);

//----------------------------------------------------------------------------
// Object declaration for wxWebViewHistoryItem
//----------------------------------------------------------------------------
class Object_wx_WebViewHistoryItem : public Object {
protected:
	wxWebViewHistoryItem *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_WebViewHistoryItem)
public:
	inline Object_wx_WebViewHistoryItem(wxWebViewHistoryItem *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_WebViewHistoryItem(Class *pClass, wxWebViewHistoryItem *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_WebViewHistoryItem();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxWebViewHistoryItem *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxWebViewHistoryItem *GetEntity() {
		return static_cast<wxWebViewHistoryItem *>(_pEntity);
	}
	inline wxWebViewHistoryItem *ReleaseEntity() {
		wxWebViewHistoryItem *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxWebViewHistoryItem");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
