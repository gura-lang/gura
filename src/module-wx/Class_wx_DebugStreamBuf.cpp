//----------------------------------------------------------------------------
// wxDebugStreamBuf
// extracted from debugcxt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DebugStreamBuf: public wxDebugStreamBuf, public GuraObjectObserver {
private:
	Gura::Signal *_pSig;
	Object_wx_DebugStreamBuf *_pObj;
public:
	~wx_DebugStreamBuf();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_DebugStreamBuf *pObj) {
		_pSig = &sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DebugStreamBuf::~wx_DebugStreamBuf()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_DebugStreamBuf::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDebugStreamBuf
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDebugStreamBuf
//----------------------------------------------------------------------------
Object_wx_DebugStreamBuf::~Object_wx_DebugStreamBuf()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_DebugStreamBuf::Clone() const
{
	return nullptr;
}

String Object_wx_DebugStreamBuf::ToString(bool exprFlag)
{
	String rtn("<wx.DebugStreamBuf:");
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
// Class implementation for wxDebugStreamBuf
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DebugStreamBuf)
{
}

Gura_ImplementDescendantCreator(wx_DebugStreamBuf)
{
	return new Object_wx_DebugStreamBuf((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
