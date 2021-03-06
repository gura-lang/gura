//----------------------------------------------------------------------------
// wxRecursionGuardFlag
// extracted from recguard.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_RecursionGuardFlag: public wxRecursionGuardFlag, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_RecursionGuardFlag *_pObj;
public:
	~wx_RecursionGuardFlag();
	inline void AssocWithGura(Object_wx_RecursionGuardFlag *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_RecursionGuardFlag::~wx_RecursionGuardFlag()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_RecursionGuardFlag::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxRecursionGuardFlag
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRecursionGuardFlag
//----------------------------------------------------------------------------
Object_wx_RecursionGuardFlag::~Object_wx_RecursionGuardFlag()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_RecursionGuardFlag::Clone() const
{
	return nullptr;
}

String Object_wx_RecursionGuardFlag::ToString(bool exprFlag)
{
	String rtn("<wx.RecursionGuardFlag:");
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
// Class implementation for wxRecursionGuardFlag
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RecursionGuardFlag)
{
}

Gura_ImplementDescendantCreator(wx_RecursionGuardFlag)
{
	return new Object_wx_RecursionGuardFlag((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
