//----------------------------------------------------------------------------
// wxNativeFontInfo
// (automatically generated)
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_NativeFontInfo: public wxNativeFontInfo, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_NativeFontInfo *_pObj;
public:
	~wx_NativeFontInfo();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_NativeFontInfo *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_NativeFontInfo::~wx_NativeFontInfo()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_NativeFontInfo::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxNativeFontInfo
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxNativeFontInfo
//----------------------------------------------------------------------------
Object_wx_NativeFontInfo::~Object_wx_NativeFontInfo()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_NativeFontInfo::Clone() const
{
	return NULL;
}

String Object_wx_NativeFontInfo::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.NativeFontInfo:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_NativeFontInfo::OnModuleEntry(Environment &env, Signal sig)
{
}

//----------------------------------------------------------------------------
// Class implementation for wxNativeFontInfo
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_NativeFontInfo)
{
}

Gura_ImplementDescendantCreator(wx_NativeFontInfo)
{
	return new Object_wx_NativeFontInfo((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
