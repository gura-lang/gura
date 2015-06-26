//----------------------------------------------------------------------------
// wxHtmlModalHelp
// extracted from hthlpfrm.tex
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_HTMLMODALHELP_H__
#define __CLASS_WX_HTMLMODALHELP_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxHtmlModalHelp
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_HtmlModalHelp);

//----------------------------------------------------------------------------
// Object declaration for wxHtmlModalHelp
//----------------------------------------------------------------------------
class Object_wx_HtmlModalHelp : public Object {
protected:
	wxHtmlModalHelp *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_HtmlModalHelp)
public:
	inline Object_wx_HtmlModalHelp(wxHtmlModalHelp *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_HtmlModalHelp)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_HtmlModalHelp(Class *pClass, wxHtmlModalHelp *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_HtmlModalHelp();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxHtmlModalHelp *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxHtmlModalHelp *GetEntity() { return _pEntity; }
	inline wxHtmlModalHelp *ReleaseEntity() {
		wxHtmlModalHelp *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxHtmlModalHelp");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
