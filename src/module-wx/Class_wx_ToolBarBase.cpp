//----------------------------------------------------------------------------
// wxToolBarBase
// (automatically generated)
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ToolBarBase: public wxToolBarBase, public GuraObjectObserver {
private:
	Gura::Signal *_pSig;
	Object_wx_ToolBarBase *_pObj;
public:
	~wx_ToolBarBase();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ToolBarBase *pObj) {
		_pSig = &sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ToolBarBase::~wx_ToolBarBase()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_ToolBarBase::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxToolBarBase
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxToolBarBase
//----------------------------------------------------------------------------
Object_wx_ToolBarBase::~Object_wx_ToolBarBase()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_ToolBarBase::Clone() const
{
	return nullptr;
}

String Object_wx_ToolBarBase::ToString(bool exprFlag)
{
	String rtn("<wx.ToolBarBase:");
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
// Class implementation for wxToolBarBase
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ToolBarBase)
{
}

Gura_ImplementDescendantCreator(wx_ToolBarBase)
{
	return new Object_wx_ToolBarBase((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
