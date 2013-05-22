//----------------------------------------------------------------------------
// wxAppConsole
// (automatically generated)
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_AppConsole: public wxAppConsole, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_AppConsole *_pObj;
public:
	~wx_AppConsole();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_AppConsole *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_AppConsole::~wx_AppConsole()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_AppConsole::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxAppConsole
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAppConsole
//----------------------------------------------------------------------------
Object_wx_AppConsole::~Object_wx_AppConsole()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_AppConsole::Clone() const
{
	return NULL;
}

String Object_wx_AppConsole::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.AppConsole:");
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
// Class implementation for wxAppConsole
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AppConsole)
{
}

Gura_ImplementDescendantCreator(wx_AppConsole)
{
	return new Object_wx_AppConsole((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
