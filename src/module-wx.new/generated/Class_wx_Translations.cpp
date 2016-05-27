//----------------------------------------------------------------------------
// wxTranslations
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTranslations
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTranslations
//----------------------------------------------------------------------------
Object_wx_Translations::~Object_wx_Translations()
{
}

Object *Object_wx_Translations::Clone() const
{
	return nullptr;
}

String Object_wx_Translations::ToString(bool exprFlag)
{
	String rtn("<wx.Translations:");
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
// Class implementation for wxTranslations
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Translations)
{
}

Gura_ImplementDescendantCreator(wx_Translations)
{
	return new Object_wx_Translations((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
