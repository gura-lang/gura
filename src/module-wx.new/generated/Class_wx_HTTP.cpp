//----------------------------------------------------------------------------
// wxHTTP
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHTTP
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHTTP
//----------------------------------------------------------------------------
Object_wx_HTTP::~Object_wx_HTTP()
{
}

Object *Object_wx_HTTP::Clone() const
{
	return nullptr;
}

String Object_wx_HTTP::ToString(bool exprFlag)
{
	String rtn("<wx.HTTP:");
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
// Class implementation for wxHTTP
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HTTP)
{
}

Gura_ImplementDescendantCreator(wx_HTTP)
{
	return new Object_wx_HTTP((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
