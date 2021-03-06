//----------------------------------------------------------------------------
// wxZipClassFactory
// extracted from zipstrm.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ZipClassFactory: public wxZipClassFactory, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_ZipClassFactory *_pObj;
public:
	~wx_ZipClassFactory();
	inline void AssocWithGura(Object_wx_ZipClassFactory *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ZipClassFactory::~wx_ZipClassFactory()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_ZipClassFactory::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxZipClassFactory
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxZipClassFactory
//----------------------------------------------------------------------------
Object_wx_ZipClassFactory::~Object_wx_ZipClassFactory()
{
}

Object *Object_wx_ZipClassFactory::Clone() const
{
	return nullptr;
}

String Object_wx_ZipClassFactory::ToString(bool exprFlag)
{
	String rtn("<wx.ZipClassFactory:");
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
// Class implementation for wxZipClassFactory
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ZipClassFactory)
{
}

Gura_ImplementDescendantCreator(wx_ZipClassFactory)
{
	return new Object_wx_ZipClassFactory((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
