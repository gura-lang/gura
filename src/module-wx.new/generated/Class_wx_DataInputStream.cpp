//----------------------------------------------------------------------------
// wxDataInputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDataInputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDataInputStream
//----------------------------------------------------------------------------
Object_wx_DataInputStream::~Object_wx_DataInputStream()
{
}

Object *Object_wx_DataInputStream::Clone() const
{
	return nullptr;
}

String Object_wx_DataInputStream::ToString(bool exprFlag)
{
	String rtn("<wx.DataInputStream:");
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
// Class implementation for wxDataInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataInputStream)
{
}

Gura_ImplementDescendantCreator(wx_DataInputStream)
{
	return new Object_wx_DataInputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
