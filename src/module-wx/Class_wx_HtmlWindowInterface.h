//----------------------------------------------------------------------------
// wxHtmlWindowInterface
// (automatically generated)
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_HTMLWINDOWINTERFACE_H__
#define __CLASS_WX_HTMLWINDOWINTERFACE_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxHtmlWindowInterface
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_HtmlWindowInterface);

//----------------------------------------------------------------------------
// Object declaration for wxHtmlWindowInterface
//----------------------------------------------------------------------------
class Object_wx_HtmlWindowInterface : public Object {
protected:
	wxHtmlWindowInterface *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_HtmlWindowInterface)
public:
	inline Object_wx_HtmlWindowInterface(wxHtmlWindowInterface *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_HtmlWindowInterface)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_HtmlWindowInterface(Class *pClass, wxHtmlWindowInterface *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_HtmlWindowInterface();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxHtmlWindowInterface *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxHtmlWindowInterface *GetEntity() { return _pEntity; }
	inline wxHtmlWindowInterface *ReleaseEntity() {
		wxHtmlWindowInterface *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxHtmlWindowInterface");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
