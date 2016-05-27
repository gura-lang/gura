//----------------------------------------------------------------------------
// wxLogFormatter
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxLogFormatter
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxLogFormatter
//----------------------------------------------------------------------------
Object_wx_LogFormatter::~Object_wx_LogFormatter()
{
}

Object *Object_wx_LogFormatter::Clone() const
{
	return nullptr;
}

String Object_wx_LogFormatter::ToString(bool exprFlag)
{
	String rtn("<wx.LogFormatter:");
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
// Class implementation for wxLogFormatter
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_LogFormatter)
{
}

Gura_ImplementDescendantCreator(wx_LogFormatter)
{
	return new Object_wx_LogFormatter((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
