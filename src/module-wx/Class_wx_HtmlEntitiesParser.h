//----------------------------------------------------------------------------
// wxHtmlEntitiesParser
// (automatically generated)
//----------------------------------------------------------------------------
#ifndef __CLASS_WX_HTMLENTITIESPARSER_H__
#define __CLASS_WX_HTMLENTITIESPARSER_H__

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class declaration for wxHtmlEntitiesParser
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_HtmlEntitiesParser);

//----------------------------------------------------------------------------
// Object declaration for wxHtmlEntitiesParser
//----------------------------------------------------------------------------
class Object_wx_HtmlEntitiesParser : public Object {
protected:
	wxHtmlEntitiesParser *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_HtmlEntitiesParser)
public:
	inline Object_wx_HtmlEntitiesParser(wxHtmlEntitiesParser *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_HtmlEntitiesParser)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_HtmlEntitiesParser(Class *pClass, wxHtmlEntitiesParser *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_HtmlEntitiesParser();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline void SetEntity(wxHtmlEntitiesParser *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = nullptr, _pObserver = nullptr, _ownerFlag = false; }
	inline wxHtmlEntitiesParser *GetEntity() { return _pEntity; }
	inline wxHtmlEntitiesParser *ReleaseEntity() {
		wxHtmlEntitiesParser *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != nullptr) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != nullptr) return false;
		SetError_InvalidWxObject(sig, "wxHtmlEntitiesParser");
		return true;
	}
};

Gura_EndModuleScope(wx)

#endif
