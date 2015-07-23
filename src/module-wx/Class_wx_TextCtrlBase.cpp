//----------------------------------------------------------------------------
// wxTextCtrlBase
// (automatically generated)
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_TextCtrlBase: public wxTextCtrlBase, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_TextCtrlBase *_pObj;
public:
	~wx_TextCtrlBase();
	inline void AssocWithGura(Object_wx_TextCtrlBase *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_TextCtrlBase::~wx_TextCtrlBase()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_TextCtrlBase::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxTextCtrlBase
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTextCtrlBase
//----------------------------------------------------------------------------
Object_wx_TextCtrlBase::~Object_wx_TextCtrlBase()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_TextCtrlBase::Clone() const
{
	return nullptr;
}

String Object_wx_TextCtrlBase::ToString(bool exprFlag)
{
	String rtn("<wx.TextCtrlBase:");
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
// Class implementation for wxTextCtrlBase
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextCtrlBase)
{
}

Gura_ImplementDescendantCreator(wx_TextCtrlBase)
{
	return new Object_wx_TextCtrlBase((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
