//----------------------------------------------------------------------------
// wxAppConsole
// (automatically generated)
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_AppConsole: public wxAppConsole, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_AppConsole *_pObj;
public:
	~wx_AppConsole();
	inline void AssocWithGura(Object_wx_AppConsole *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_AppConsole::~wx_AppConsole()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_AppConsole::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxAppConsole
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAppConsole
//----------------------------------------------------------------------------
Object_wx_AppConsole::~Object_wx_AppConsole()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_AppConsole::Clone() const
{
	return nullptr;
}

String Object_wx_AppConsole::ToString(bool exprFlag)
{
	String rtn("<wx.AppConsole:");
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
// Class implementation for wxAppConsole
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AppConsole)
{
}

Gura_ImplementDescendantCreator(wx_AppConsole)
{
	return new Object_wx_AppConsole((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
