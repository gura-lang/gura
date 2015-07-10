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
	Gura::Signal *_pSig;
	Object_wx_HtmlWindowInterface *_pObj;
public:
	~wx_HtmlWindowInterface();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_HtmlWindowInterface *pObj) {
		_pSig = &sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_HtmlWindowInterface::~wx_HtmlWindowInterface()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_HtmlWindowInterface::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlWindowInterface
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlWindowInterface
//----------------------------------------------------------------------------
Object_wx_HtmlWindowInterface::~Object_wx_HtmlWindowInterface()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_HtmlWindowInterface::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlWindowInterface::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlWindowInterface:");
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
// Class implementation for wxHtmlWindowInterface
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlWindowInterface)
{
}

Gura_ImplementDescendantCreator(wx_HtmlWindowInterface)
{
	return new Object_wx_HtmlWindowInterface((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
