//----------------------------------------------------------------------------
// wxMemoryBuffer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMemoryBuffer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMemoryBuffer
//----------------------------------------------------------------------------
Object_wx_MemoryBuffer::~Object_wx_MemoryBuffer()
{
}

Object *Object_wx_MemoryBuffer::Clone() const
{
	return nullptr;
}

String Object_wx_MemoryBuffer::ToString(bool exprFlag)
{
	String rtn("<wx.MemoryBuffer:");
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
// Class implementation for wxMemoryBuffer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MemoryBuffer)
{
}

Gura_ImplementDescendantCreator(wx_MemoryBuffer)
{
	return new Object_wx_MemoryBuffer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
