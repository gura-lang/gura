//----------------------------------------------------------------------------
// wxTarClassFactory
// extracted from tarstrm.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_TarClassFactory: public wxTarClassFactory, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_TarClassFactory *_pObj;
public:
	~wx_TarClassFactory();
	inline void AssocWithGura(Object_wx_TarClassFactory *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_TarClassFactory::~wx_TarClassFactory()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_TarClassFactory::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxTarClassFactory
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTarClassFactory
//----------------------------------------------------------------------------
Object_wx_TarClassFactory::~Object_wx_TarClassFactory()
{
}

Object *Object_wx_TarClassFactory::Clone() const
{
	return nullptr;
}

String Object_wx_TarClassFactory::ToString(bool exprFlag)
{
	String rtn("<wx.TarClassFactory:");
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
// Class implementation for wxTarClassFactory
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TarClassFactory)
{
}

Gura_ImplementDescendantCreator(wx_TarClassFactory)
{
	return new Object_wx_TarClassFactory((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
