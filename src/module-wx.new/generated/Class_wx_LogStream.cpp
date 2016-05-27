//----------------------------------------------------------------------------
// wxLogStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxLogStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxLogStream
//----------------------------------------------------------------------------
Object_wx_LogStream::~Object_wx_LogStream()
{
}

Object *Object_wx_LogStream::Clone() const
{
	return nullptr;
}

String Object_wx_LogStream::ToString(bool exprFlag)
{
	String rtn("<wx.LogStream:");
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
// Class implementation for wxLogStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_LogStream)
{
}

Gura_ImplementDescendantCreator(wx_LogStream)
{
	return new Object_wx_LogStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
