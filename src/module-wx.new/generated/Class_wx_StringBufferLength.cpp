//----------------------------------------------------------------------------
// wxStringBufferLength
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxStringBufferLength
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxStringBufferLength
//----------------------------------------------------------------------------
Object_wx_StringBufferLength::~Object_wx_StringBufferLength()
{
}

Object *Object_wx_StringBufferLength::Clone() const
{
	return nullptr;
}

String Object_wx_StringBufferLength::ToString(bool exprFlag)
{
	String rtn("<wx.StringBufferLength:");
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
// Class implementation for wxStringBufferLength
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StringBufferLength)
{
}

Gura_ImplementDescendantCreator(wx_StringBufferLength)
{
	return new Object_wx_StringBufferLength((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
