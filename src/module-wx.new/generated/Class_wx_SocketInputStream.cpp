//----------------------------------------------------------------------------
// wxSocketInputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSocketInputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSocketInputStream
//----------------------------------------------------------------------------
Object_wx_SocketInputStream::~Object_wx_SocketInputStream()
{
}

Object *Object_wx_SocketInputStream::Clone() const
{
	return nullptr;
}

String Object_wx_SocketInputStream::ToString(bool exprFlag)
{
	String rtn("<wx.SocketInputStream:");
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
// Class implementation for wxSocketInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SocketInputStream)
{
}

Gura_ImplementDescendantCreator(wx_SocketInputStream)
{
	return new Object_wx_SocketInputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
