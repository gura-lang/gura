//----------------------------------------------------------------------------
// wxTextEntry
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTextEntry
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTextEntry
//----------------------------------------------------------------------------
Object_wx_TextEntry::~Object_wx_TextEntry()
{
}

Object *Object_wx_TextEntry::Clone() const
{
	return nullptr;
}

String Object_wx_TextEntry::ToString(bool exprFlag)
{
	String rtn("<wx.TextEntry:");
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
// Class implementation for wxTextEntry
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextEntry)
{
}

Gura_ImplementDescendantCreator(wx_TextEntry)
{
	return new Object_wx_TextEntry((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
