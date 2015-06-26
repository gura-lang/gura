//----------------------------------------------------------------------------
// wxHelpControllerBase
// (automatically generated)
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_HelpControllerBase: public wxHelpControllerBase, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_HelpControllerBase *_pObj;
public:
	~wx_HelpControllerBase();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_HelpControllerBase *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_HelpControllerBase::~wx_HelpControllerBase()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_HelpControllerBase::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxHelpControllerBase
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHelpControllerBase
//----------------------------------------------------------------------------
Object_wx_HelpControllerBase::~Object_wx_HelpControllerBase()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_HelpControllerBase::Clone() const
{
	return nullptr;
}

String Object_wx_HelpControllerBase::ToString(bool exprFlag)
{
	String rtn("<wx.HelpControllerBase:");
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
// Class implementation for wxHelpControllerBase
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HelpControllerBase)
{
}

Gura_ImplementDescendantCreator(wx_HelpControllerBase)
{
	return new Object_wx_HelpControllerBase((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
