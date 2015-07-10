//----------------------------------------------------------------------------
// wxConnectionBase
// (automatically generated)
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ConnectionBase: public wxConnectionBase, public GuraObjectObserver {
private:
	Gura::Signal *_pSig;
	Object_wx_ConnectionBase *_pObj;
public:
	~wx_ConnectionBase();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ConnectionBase *pObj) {
		_pSig = &sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ConnectionBase::~wx_ConnectionBase()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_ConnectionBase::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxConnectionBase
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxConnectionBase
//----------------------------------------------------------------------------
Object_wx_ConnectionBase::~Object_wx_ConnectionBase()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_ConnectionBase::Clone() const
{
	return nullptr;
}

String Object_wx_ConnectionBase::ToString(bool exprFlag)
{
	String rtn("<wx.ConnectionBase:");
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
// Class implementation for wxConnectionBase
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ConnectionBase)
{
}

Gura_ImplementDescendantCreator(wx_ConnectionBase)
{
	return new Object_wx_ConnectionBase((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
