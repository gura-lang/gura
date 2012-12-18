//----------------------------------------------------------------------------
// wxIconLocation
// extracted from iconloc.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_IconLocation: public wxIconLocation, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_IconLocation *_pObj;
public:
	~wx_IconLocation();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_IconLocation *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_IconLocation::~wx_IconLocation()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_IconLocation::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxIconLocation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_IconLocation, IsOk)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_IconLocation, IsOk)
{
	Object_wx_IconLocation *pSelf = Object_wx_IconLocation::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsOk();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxIconLocation
//----------------------------------------------------------------------------
Object_wx_IconLocation::~Object_wx_IconLocation()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_IconLocation::Clone() const
{
	return NULL;
}

String Object_wx_IconLocation::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.IconLocation:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_IconLocation::OnModuleEntry(Environment &env, Signal sig)
{
}

//----------------------------------------------------------------------------
// Class implementation for wxIconLocation
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_IconLocation)
{
	Gura_AssignMethod(wx_IconLocation, IsOk);
}

Gura_ImplementDescendantCreator(wx_IconLocation)
{
	return new Object_wx_IconLocation((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
