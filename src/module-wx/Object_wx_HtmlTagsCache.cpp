//----------------------------------------------------------------------------
// wxHtmlTagsCache
// (automatically generated)
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_HtmlTagsCache: public wxHtmlTagsCache, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_HtmlTagsCache *_pObj;
public:
	~wx_HtmlTagsCache();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_HtmlTagsCache *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_HtmlTagsCache::~wx_HtmlTagsCache()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_HtmlTagsCache::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlTagsCache
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlTagsCache
//----------------------------------------------------------------------------
Object_wx_HtmlTagsCache::~Object_wx_HtmlTagsCache()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_HtmlTagsCache::Clone() const
{
	return NULL;
}

String Object_wx_HtmlTagsCache::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.HtmlTagsCache:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlTagsCache
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlTagsCache)
{
}

Gura_ImplementDescendantCreator(wx_HtmlTagsCache)
{
	return new Object_wx_HtmlTagsCache((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
