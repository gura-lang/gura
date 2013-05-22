//----------------------------------------------------------------------------
// wxToolBarToolBase
// (automatically generated)
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ToolBarToolBase: public wxToolBarToolBase, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_ToolBarToolBase *_pObj;
public:
	~wx_ToolBarToolBase();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ToolBarToolBase *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ToolBarToolBase::~wx_ToolBarToolBase()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_ToolBarToolBase::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxToolBarToolBase
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxToolBarToolBase
//----------------------------------------------------------------------------
Object_wx_ToolBarToolBase::~Object_wx_ToolBarToolBase()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_ToolBarToolBase::Clone() const
{
	return NULL;
}

String Object_wx_ToolBarToolBase::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.ToolBarToolBase:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_ToolBarToolBase::DoAssignConstructor(Environment &env, Signal sig)
{
}

//----------------------------------------------------------------------------
// Class implementation for wxToolBarToolBase
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ToolBarToolBase)
{
}

Gura_ImplementDescendantCreator(wx_ToolBarToolBase)
{
	return new Object_wx_ToolBarToolBase((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
