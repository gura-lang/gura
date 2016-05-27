//----------------------------------------------------------------------------
// wxResourceTranslationsLoader
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxResourceTranslationsLoader
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxResourceTranslationsLoader
//----------------------------------------------------------------------------
Object_wx_ResourceTranslationsLoader::~Object_wx_ResourceTranslationsLoader()
{
}

Object *Object_wx_ResourceTranslationsLoader::Clone() const
{
	return nullptr;
}

String Object_wx_ResourceTranslationsLoader::ToString(bool exprFlag)
{
	String rtn("<wx.ResourceTranslationsLoader:");
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
// Class implementation for wxResourceTranslationsLoader
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ResourceTranslationsLoader)
{
}

Gura_ImplementDescendantCreator(wx_ResourceTranslationsLoader)
{
	return new Object_wx_ResourceTranslationsLoader((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
