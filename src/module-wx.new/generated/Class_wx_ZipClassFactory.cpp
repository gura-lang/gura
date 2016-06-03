//----------------------------------------------------------------------------
// wxZipClassFactory
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

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
	// Class assignment
	Gura_AssignValueEx("ZipClassFactory", Reference());
}

Gura_ImplementDescendantCreator(wx_ZipClassFactory)
{
	return new Object_wx_ZipClassFactory((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
