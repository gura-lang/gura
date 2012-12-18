//----------------------------------------------------------------------------
// wxToolBarBase
// (automatically generated)
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ToolBarBase: public wxToolBarBase, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_ToolBarBase *_pObj;
public:
	~wx_ToolBarBase();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ToolBarBase *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ToolBarBase::~wx_ToolBarBase()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_ToolBarBase::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxToolBarBase
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxToolBarBase
//----------------------------------------------------------------------------
Object_wx_ToolBarBase::~Object_wx_ToolBarBase()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_ToolBarBase::Clone() const
{
	return NULL;
}

String Object_wx_ToolBarBase::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.ToolBarBase:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_ToolBarBase::OnModuleEntry(Environment &env, Signal sig)
{
}

//----------------------------------------------------------------------------
// Class implementation for wxToolBarBase
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ToolBarBase)
{
}

Gura_ImplementDescendantCreator(wx_ToolBarBase)
{
	return new Object_wx_ToolBarBase((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
