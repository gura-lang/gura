//----------------------------------------------------------------------------
// wxHtmlParser
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_HTMLPARSER_H__
#define __CLASS_WX_HTMLPARSER_H__
#include <wx/html/htmlpars.h>

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxHtmlParser
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_HtmlParser);

//----------------------------------------------------------------------------
// Object declaration for wxHtmlParser
//----------------------------------------------------------------------------
class Object_wx_HtmlParser : public Object {
protected:
	wxHtmlParser *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_HtmlParser)
public:
	inline Object_wx_HtmlParser(wxHtmlParser *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_AboutDialogInfo)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_HtmlParser(Class *pClass, wxHtmlParser *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_HtmlParser();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxHtmlParser *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxHtmlParser *GetEntity() {
		return static_cast<wxHtmlParser *>(_pEntity);
	}
	inline wxHtmlParser *ReleaseEntity() {
		wxHtmlParser *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal &sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxHtmlParser");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
