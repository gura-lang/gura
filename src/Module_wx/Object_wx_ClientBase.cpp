//----------------------------------------------------------------------------
// wxClientBase
// (automatically generated)
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ClientBase: public wxClientBase, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_ClientBase *_pObj;
public:
	~wx_ClientBase();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ClientBase *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ClientBase::~wx_ClientBase()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_ClientBase::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxClientBase
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxClientBase
//----------------------------------------------------------------------------
Object_wx_ClientBase::~Object_wx_ClientBase()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_ClientBase::Clone() const
{
	return NULL;
}

String Object_wx_ClientBase::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.ClientBase:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_ClientBase::OnModuleEntry(Environment &env, Signal sig)
{
}

//----------------------------------------------------------------------------
// Class implementation for wxClientBase
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ClientBase)
{
}

Gura_ImplementDescendantCreator(wx_ClientBase)
{
	return new Object_wx_ClientBase((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
