//----------------------------------------------------------------------------
// wxServerBase
// (automatically generated)
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ServerBase: public wxServerBase, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_ServerBase *_pObj;
public:
	~wx_ServerBase();
	inline void AssocWithGura(Object_wx_ServerBase *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ServerBase::~wx_ServerBase()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_ServerBase::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxServerBase
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxServerBase
//----------------------------------------------------------------------------
Object_wx_ServerBase::~Object_wx_ServerBase()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_ServerBase::Clone() const
{
	return nullptr;
}

String Object_wx_ServerBase::ToString(bool exprFlag)
{
	String rtn("<wx.ServerBase:");
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
// Class implementation for wxServerBase
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ServerBase)
{
}

Gura_ImplementDescendantCreator(wx_ServerBase)
{
	return new Object_wx_ServerBase((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
