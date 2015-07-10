//----------------------------------------------------------------------------
// wxHtmlEntitiesParser
// (automatically generated)
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_HtmlEntitiesParser: public wxHtmlEntitiesParser, public GuraObjectObserver {
private:
	Gura::Signal *_pSig;
	Object_wx_HtmlEntitiesParser *_pObj;
public:
	~wx_HtmlEntitiesParser();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_HtmlEntitiesParser *pObj) {
		_pSig = &sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_HtmlEntitiesParser::~wx_HtmlEntitiesParser()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_HtmlEntitiesParser::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlEntitiesParser
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlEntitiesParser
//----------------------------------------------------------------------------
Object_wx_HtmlEntitiesParser::~Object_wx_HtmlEntitiesParser()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_HtmlEntitiesParser::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlEntitiesParser::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlEntitiesParser:");
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
// Class implementation for wxHtmlEntitiesParser
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlEntitiesParser)
{
}

Gura_ImplementDescendantCreator(wx_HtmlEntitiesParser)
{
	return new Object_wx_HtmlEntitiesParser((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
