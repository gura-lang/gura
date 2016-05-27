//----------------------------------------------------------------------------
// wxTranslationsLoader
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTranslationsLoader
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTranslationsLoader
//----------------------------------------------------------------------------
Object_wx_TranslationsLoader::~Object_wx_TranslationsLoader()
{
}

Object *Object_wx_TranslationsLoader::Clone() const
{
	return nullptr;
}

String Object_wx_TranslationsLoader::ToString(bool exprFlag)
{
	String rtn("<wx.TranslationsLoader:");
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
// Class implementation for wxTranslationsLoader
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TranslationsLoader)
{
}

Gura_ImplementDescendantCreator(wx_TranslationsLoader)
{
	return new Object_wx_TranslationsLoader((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
