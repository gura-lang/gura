//----------------------------------------------------------------------------
// wxIconLocation
// extracted from iconloc.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_IconLocation: public wxIconLocation, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_IconLocation *_pObj;
public:
	~wx_IconLocation();
	inline void AssocWithGura(Object_wx_IconLocation *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_IconLocation::~wx_IconLocation()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_IconLocation::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxIconLocation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_IconLocation, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_IconLocation, IsOk)
{
	Signal &sig = env.GetSignal();
	Object_wx_IconLocation *pThis = Object_wx_IconLocation::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsOk();
	return ReturnValue(env, arg, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxIconLocation
//----------------------------------------------------------------------------
Object_wx_IconLocation::~Object_wx_IconLocation()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_IconLocation::Clone() const
{
	return nullptr;
}

String Object_wx_IconLocation::ToString(bool exprFlag)
{
	String rtn("<wx.IconLocation:");
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
// Class implementation for wxIconLocation
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_IconLocation)
{
	Gura_AssignMethod(wx_IconLocation, IsOk);
}

Gura_ImplementDescendantCreator(wx_IconLocation)
{
	return new Object_wx_IconLocation((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
