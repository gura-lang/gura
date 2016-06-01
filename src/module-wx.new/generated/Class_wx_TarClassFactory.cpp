//----------------------------------------------------------------------------
// wxTarClassFactory
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

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
// Method implementation
//----------------------------------------------------------------------------


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
