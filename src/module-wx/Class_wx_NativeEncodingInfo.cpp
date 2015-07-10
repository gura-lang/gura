//----------------------------------------------------------------------------
// wxNativeEncodingInfo
// (automatically generated)
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_NativeEncodingInfo: public wxNativeEncodingInfo, public GuraObjectObserver {
private:
	Gura::Signal *_pSig;
	Object_wx_NativeEncodingInfo *_pObj;
public:
	~wx_NativeEncodingInfo();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_NativeEncodingInfo *pObj) {
		_pSig = &sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_NativeEncodingInfo::~wx_NativeEncodingInfo()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_NativeEncodingInfo::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxNativeEncodingInfo
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxNativeEncodingInfo
//----------------------------------------------------------------------------
Object_wx_NativeEncodingInfo::~Object_wx_NativeEncodingInfo()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_NativeEncodingInfo::Clone() const
{
	return nullptr;
}

String Object_wx_NativeEncodingInfo::ToString(bool exprFlag)
{
	String rtn("<wx.NativeEncodingInfo:");
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
// Class implementation for wxNativeEncodingInfo
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_NativeEncodingInfo)
{
}

Gura_ImplementDescendantCreator(wx_NativeEncodingInfo)
{
	return new Object_wx_NativeEncodingInfo((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
