//----------------------------------------------------------------------------
// wxLogGui
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxLogGui
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxLogGui
//----------------------------------------------------------------------------
Object_wx_LogGui::~Object_wx_LogGui()
{
}

Object *Object_wx_LogGui::Clone() const
{
	return nullptr;
}

String Object_wx_LogGui::ToString(bool exprFlag)
{
	String rtn("<wx.LogGui:");
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
// Class implementation for wxLogGui
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_LogGui)
{
}

Gura_ImplementDescendantCreator(wx_LogGui)
{
	return new Object_wx_LogGui((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
