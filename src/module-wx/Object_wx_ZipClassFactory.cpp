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
	Gura::Signal _sig;
	Object_wx_ZipClassFactory *_pObj;
public:
	~wx_ZipClassFactory();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ZipClassFactory *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ZipClassFactory::~wx_ZipClassFactory()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_ZipClassFactory::GuraObjectDeleted()
{
	_pObj = NULL;
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
	return NULL;
}

String Object_wx_ZipClassFactory::ToString(bool exprFlag)
{
	String rtn("<wx.ZipClassFactory:");
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
// Class implementation for wxZipClassFactory
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ZipClassFactory)
{
}

Gura_ImplementDescendantCreator(wx_ZipClassFactory)
{
	return new Object_wx_ZipClassFactory((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
