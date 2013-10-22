//----------------------------------------------------------------------------
// wxServerBase
// (automatically generated)
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ServerBase: public wxServerBase, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_ServerBase *_pObj;
public:
	~wx_ServerBase();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ServerBase *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ServerBase::~wx_ServerBase()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_ServerBase::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxServerBase
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxServerBase
//----------------------------------------------------------------------------
Object_wx_ServerBase::~Object_wx_ServerBase()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_ServerBase::Clone() const
{
	return NULL;
}

String Object_wx_ServerBase::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.ServerBase:");
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
// Class implementation for wxServerBase
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ServerBase)
{
}

Gura_ImplementDescendantCreator(wx_ServerBase)
{
	return new Object_wx_ServerBase((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
