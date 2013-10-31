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
	Gura::Signal _sig;
	Object_wx_TextCtrlBase *_pObj;
public:
	~wx_TextCtrlBase();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_TextCtrlBase *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_TextCtrlBase::~wx_TextCtrlBase()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_TextCtrlBase::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxTextCtrlBase
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTextCtrlBase
//----------------------------------------------------------------------------
Object_wx_TextCtrlBase::~Object_wx_TextCtrlBase()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_TextCtrlBase::Clone() const
{
	return NULL;
}

String Object_wx_TextCtrlBase::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.TextCtrlBase:");
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
// Class implementation for wxTextCtrlBase
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextCtrlBase)
{
}

Gura_ImplementDescendantCreator(wx_TextCtrlBase)
{
	return new Object_wx_TextCtrlBase((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
