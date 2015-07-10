//----------------------------------------------------------------------------
// wxToolBarToolBase
// (automatically generated)
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ToolBarToolBase: public wxToolBarToolBase, public GuraObjectObserver {
private:
	Gura::Signal *_pSig;
	Object_wx_ToolBarToolBase *_pObj;
public:
	~wx_ToolBarToolBase();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ToolBarToolBase *pObj) {
		_pSig = &sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ToolBarToolBase::~wx_ToolBarToolBase()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_ToolBarToolBase::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxToolBarToolBase
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxToolBarToolBase
//----------------------------------------------------------------------------
Object_wx_ToolBarToolBase::~Object_wx_ToolBarToolBase()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_ToolBarToolBase::Clone() const
{
	return nullptr;
}

String Object_wx_ToolBarToolBase::ToString(bool exprFlag)
{
	String rtn("<wx.ToolBarToolBase:");
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
// Class implementation for wxToolBarToolBase
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ToolBarToolBase)
{
}

Gura_ImplementDescendantCreator(wx_ToolBarToolBase)
{
	return new Object_wx_ToolBarToolBase((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
