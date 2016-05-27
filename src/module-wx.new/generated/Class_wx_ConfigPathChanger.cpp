//----------------------------------------------------------------------------
// wxConfigPathChanger
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxConfigPathChanger
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxConfigPathChanger
//----------------------------------------------------------------------------
Object_wx_ConfigPathChanger::~Object_wx_ConfigPathChanger()
{
}

Object *Object_wx_ConfigPathChanger::Clone() const
{
	return nullptr;
}

String Object_wx_ConfigPathChanger::ToString(bool exprFlag)
{
	String rtn("<wx.ConfigPathChanger:");
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
// Class implementation for wxConfigPathChanger
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ConfigPathChanger)
{
}

Gura_ImplementDescendantCreator(wx_ConfigPathChanger)
{
	return new Object_wx_ConfigPathChanger((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
