//----------------------------------------------------------------------------
// wxHtmlWindowInterface
// (automatically generated)
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_HtmlWindowInterface: public wxHtmlWindowInterface, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_HtmlWindowInterface *_pObj;
public:
	~wx_HtmlWindowInterface();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_HtmlWindowInterface *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_HtmlWindowInterface::~wx_HtmlWindowInterface()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_HtmlWindowInterface::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlWindowInterface
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlWindowInterface
//----------------------------------------------------------------------------
Object_wx_HtmlWindowInterface::~Object_wx_HtmlWindowInterface()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_HtmlWindowInterface::Clone() const
{
	return NULL;
}

String Object_wx_HtmlWindowInterface::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.HtmlWindowInterface:");
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
// Class implementation for wxHtmlWindowInterface
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlWindowInterface)
{
}

Gura_ImplementDescendantCreator(wx_HtmlWindowInterface)
{
	return new Object_wx_HtmlWindowInterface((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
