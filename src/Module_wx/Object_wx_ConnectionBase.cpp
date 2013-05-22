//----------------------------------------------------------------------------
// wxConnectionBase
// (automatically generated)
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ConnectionBase: public wxConnectionBase, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_ConnectionBase *_pObj;
public:
	~wx_ConnectionBase();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ConnectionBase *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ConnectionBase::~wx_ConnectionBase()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_ConnectionBase::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxConnectionBase
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxConnectionBase
//----------------------------------------------------------------------------
Object_wx_ConnectionBase::~Object_wx_ConnectionBase()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_ConnectionBase::Clone() const
{
	return NULL;
}

String Object_wx_ConnectionBase::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.ConnectionBase:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_ConnectionBase::DoAssignConstructor(Environment &env, Signal sig)
{
}

//----------------------------------------------------------------------------
// Class implementation for wxConnectionBase
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ConnectionBase)
{
}

Gura_ImplementDescendantCreator(wx_ConnectionBase)
{
	return new Object_wx_ConnectionBase((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
