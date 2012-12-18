//----------------------------------------------------------------------------
// wxRecursionGuardFlag
// extracted from recguard.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_RecursionGuardFlag: public wxRecursionGuardFlag, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_RecursionGuardFlag *_pObj;
public:
	~wx_RecursionGuardFlag();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_RecursionGuardFlag *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_RecursionGuardFlag::~wx_RecursionGuardFlag()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_RecursionGuardFlag::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxRecursionGuardFlag
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRecursionGuardFlag
//----------------------------------------------------------------------------
Object_wx_RecursionGuardFlag::~Object_wx_RecursionGuardFlag()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_RecursionGuardFlag::Clone() const
{
	return NULL;
}

String Object_wx_RecursionGuardFlag::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.RecursionGuardFlag:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_RecursionGuardFlag::OnModuleEntry(Environment &env, Signal sig)
{
}

//----------------------------------------------------------------------------
// Class implementation for wxRecursionGuardFlag
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RecursionGuardFlag)
{
}

Gura_ImplementDescendantCreator(wx_RecursionGuardFlag)
{
	return new Object_wx_RecursionGuardFlag((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
