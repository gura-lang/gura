//----------------------------------------------------------------------------
// wxSocketOutputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSocketOutputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSocketOutputStream
//----------------------------------------------------------------------------
Object_wx_SocketOutputStream::~Object_wx_SocketOutputStream()
{
}

Object *Object_wx_SocketOutputStream::Clone() const
{
	return nullptr;
}

String Object_wx_SocketOutputStream::ToString(bool exprFlag)
{
	String rtn("<wx.SocketOutputStream:");
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
// Class implementation for wxSocketOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SocketOutputStream)
{
}

Gura_ImplementDescendantCreator(wx_SocketOutputStream)
{
	return new Object_wx_SocketOutputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
