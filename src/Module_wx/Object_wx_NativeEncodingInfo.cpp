//----------------------------------------------------------------------------
// wxNativeEncodingInfo
// (automatically generated)
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_NativeEncodingInfo: public wxNativeEncodingInfo, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_NativeEncodingInfo *_pObj;
public:
	~wx_NativeEncodingInfo();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_NativeEncodingInfo *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_NativeEncodingInfo::~wx_NativeEncodingInfo()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_NativeEncodingInfo::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxNativeEncodingInfo
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxNativeEncodingInfo
//----------------------------------------------------------------------------
Object_wx_NativeEncodingInfo::~Object_wx_NativeEncodingInfo()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_NativeEncodingInfo::Clone() const
{
	return NULL;
}

String Object_wx_NativeEncodingInfo::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.NativeEncodingInfo:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_NativeEncodingInfo::OnModuleEntry(Environment &env, Signal sig)
{
}

//----------------------------------------------------------------------------
// Class implementation for wxNativeEncodingInfo
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_NativeEncodingInfo)
{
}

Gura_ImplementDescendantCreator(wx_NativeEncodingInfo)
{
	return new Object_wx_NativeEncodingInfo((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
