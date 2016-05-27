//----------------------------------------------------------------------------
// wxMemoryOutputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMemoryOutputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMemoryOutputStream
//----------------------------------------------------------------------------
Object_wx_MemoryOutputStream::~Object_wx_MemoryOutputStream()
{
}

Object *Object_wx_MemoryOutputStream::Clone() const
{
	return nullptr;
}

String Object_wx_MemoryOutputStream::ToString(bool exprFlag)
{
	String rtn("<wx.MemoryOutputStream:");
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
// Class implementation for wxMemoryOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MemoryOutputStream)
{
}

Gura_ImplementDescendantCreator(wx_MemoryOutputStream)
{
	return new Object_wx_MemoryOutputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
