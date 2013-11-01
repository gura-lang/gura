//----------------------------------------------------------------------------
// wxHtmlWinTagHandler
// extracted from htwinhnd.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_HtmlWinTagHandler: public wxHtmlWinTagHandler, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_HtmlWinTagHandler *_pObj;
public:
	~wx_HtmlWinTagHandler();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_HtmlWinTagHandler *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_HtmlWinTagHandler::~wx_HtmlWinTagHandler()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_HtmlWinTagHandler::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlWinTagHandler
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlWinTagHandler
//----------------------------------------------------------------------------
Object_wx_HtmlWinTagHandler::~Object_wx_HtmlWinTagHandler()
{
}

Object *Object_wx_HtmlWinTagHandler::Clone() const
{
	return NULL;
}

String Object_wx_HtmlWinTagHandler::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlWinTagHandler:");
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
// Class implementation for wxHtmlWinTagHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlWinTagHandler)
{
}

Gura_ImplementDescendantCreator(wx_HtmlWinTagHandler)
{
	return new Object_wx_HtmlWinTagHandler((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
