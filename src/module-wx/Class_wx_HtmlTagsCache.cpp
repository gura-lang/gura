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
	Gura::Signal *_pSig;
	Object_wx_HtmlTagsCache *_pObj;
public:
	~wx_HtmlTagsCache();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_HtmlTagsCache *pObj) {
		_pSig = &sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_HtmlTagsCache::~wx_HtmlTagsCache()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_HtmlTagsCache::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlTagsCache
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlTagsCache
//----------------------------------------------------------------------------
Object_wx_HtmlTagsCache::~Object_wx_HtmlTagsCache()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_HtmlTagsCache::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlTagsCache::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlTagsCache:");
	if (GetEntity() == nullptr) {
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
	return new Object_wx_HtmlTagsCache((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
