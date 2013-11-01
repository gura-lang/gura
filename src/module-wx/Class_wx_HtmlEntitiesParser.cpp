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
	Gura::Signal _sig;
	Object_wx_HtmlEntitiesParser *_pObj;
public:
	~wx_HtmlEntitiesParser();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_HtmlEntitiesParser *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_HtmlEntitiesParser::~wx_HtmlEntitiesParser()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_HtmlEntitiesParser::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlEntitiesParser
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlEntitiesParser
//----------------------------------------------------------------------------
Object_wx_HtmlEntitiesParser::~Object_wx_HtmlEntitiesParser()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_HtmlEntitiesParser::Clone() const
{
	return NULL;
}

String Object_wx_HtmlEntitiesParser::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlEntitiesParser:");
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
// Class implementation for wxHtmlEntitiesParser
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlEntitiesParser)
{
}

Gura_ImplementDescendantCreator(wx_HtmlEntitiesParser)
{
	return new Object_wx_HtmlEntitiesParser((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
