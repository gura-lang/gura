//----------------------------------------------------------------------------
// wxNativeFontInfo
// (automatically generated)
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

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
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_NativeFontInfo::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxNativeFontInfo
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxNativeFontInfo
//----------------------------------------------------------------------------
Object_wx_NativeFontInfo::~Object_wx_NativeFontInfo()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_NativeFontInfo::Clone() const
{
	return nullptr;
}

String Object_wx_NativeFontInfo::ToString(bool exprFlag)
{
	String rtn("<wx.NativeFontInfo:");
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
// Class implementation for wxNativeFontInfo
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_NativeFontInfo)
{
}

Gura_ImplementDescendantCreator(wx_NativeFontInfo)
{
	return new Object_wx_NativeFontInfo((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
