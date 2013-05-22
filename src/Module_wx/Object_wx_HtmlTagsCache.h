//----------------------------------------------------------------------------
// wxHtmlTagsCache
// (automatically generated)
//----------------------------------------------------------------------------
#ifndef __OBJECT_WX_HTMLTAGSCACHE_H__
#define __OBJECT_WX_HTMLTAGSCACHE_H__

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class declaration for wxHtmlTagsCache
//----------------------------------------------------------------------------
Gura_DeclareUserClass(wx_HtmlTagsCache);

//----------------------------------------------------------------------------
// Object declaration for wxHtmlTagsCache
//----------------------------------------------------------------------------
class Object_wx_HtmlTagsCache : public Object {
protected:
	wxHtmlTagsCache *_pEntity;
	GuraObjectObserver *_pObserver;
	bool _ownerFlag;
public:
	Gura_DeclareObjectAccessor(wx_HtmlTagsCache)
public:
	inline Object_wx_HtmlTagsCache(wxHtmlTagsCache *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(Gura_UserClass(wx_HtmlTagsCache)),
				_pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	inline Object_wx_HtmlTagsCache(Class *pClass, wxHtmlTagsCache *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) :
				Object(pClass), _pEntity(pEntity), _pObserver(pObserver), _ownerFlag(ownerFlag) {}
	virtual ~Object_wx_HtmlTagsCache();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline void SetEntity(wxHtmlTagsCache *pEntity, GuraObjectObserver *pObserver, bool ownerFlag) {
		if (_ownerFlag) delete _pEntity;
		_pEntity = pEntity;
		_pObserver = pObserver;
		_ownerFlag = ownerFlag;
	}
	inline void InvalidateEntity() { _pEntity = NULL, _pObserver = NULL, _ownerFlag = false; }
	inline wxHtmlTagsCache *GetEntity() { return _pEntity; }
	inline wxHtmlTagsCache *ReleaseEntity() {
		wxHtmlTagsCache *pEntity = GetEntity();
		InvalidateEntity();
		return pEntity;
	}
	inline void NotifyGuraObjectDeleted() {
		if (_pObserver != NULL) _pObserver->GuraObjectDeleted();
	}
	inline bool IsInvalid(Signal sig) const {
		if (_pEntity != NULL) return false;
		SetError_InvalidWxObject(sig, "wxHtmlTagsCache");
		return true;
	}
public:
	static void DoAssignConstructor(Environment &env, Signal sig);
};

}}

#endif
