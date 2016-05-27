//----------------------------------------------------------------------------
// wxTextCompleter
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTextCompleter
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTextCompleter
//----------------------------------------------------------------------------
Object_wx_TextCompleter::~Object_wx_TextCompleter()
{
}

Object *Object_wx_TextCompleter::Clone() const
{
	return nullptr;
}

String Object_wx_TextCompleter::ToString(bool exprFlag)
{
	String rtn("<wx.TextCompleter:");
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
// Class implementation for wxTextCompleter
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextCompleter)
{
}

Gura_ImplementDescendantCreator(wx_TextCompleter)
{
	return new Object_wx_TextCompleter((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
