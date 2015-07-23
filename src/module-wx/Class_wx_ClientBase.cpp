//----------------------------------------------------------------------------
// wxClientBase
// (automatically generated)
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ClientBase: public wxClientBase, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_ClientBase *_pObj;
public:
	~wx_ClientBase();
	inline void AssocWithGura(Object_wx_ClientBase *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ClientBase::~wx_ClientBase()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_ClientBase::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxClientBase
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxClientBase
//----------------------------------------------------------------------------
Object_wx_ClientBase::~Object_wx_ClientBase()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_ClientBase::Clone() const
{
	return nullptr;
}

String Object_wx_ClientBase::ToString(bool exprFlag)
{
	String rtn("<wx.ClientBase:");
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
// Class implementation for wxClientBase
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ClientBase)
{
}

Gura_ImplementDescendantCreator(wx_ClientBase)
{
	return new Object_wx_ClientBase((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
