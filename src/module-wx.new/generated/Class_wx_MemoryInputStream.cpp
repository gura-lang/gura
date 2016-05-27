//----------------------------------------------------------------------------
// wxMemoryInputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMemoryInputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMemoryInputStream
//----------------------------------------------------------------------------
Object_wx_MemoryInputStream::~Object_wx_MemoryInputStream()
{
}

Object *Object_wx_MemoryInputStream::Clone() const
{
	return nullptr;
}

String Object_wx_MemoryInputStream::ToString(bool exprFlag)
{
	String rtn("<wx.MemoryInputStream:");
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
// Class implementation for wxMemoryInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MemoryInputStream)
{
}

Gura_ImplementDescendantCreator(wx_MemoryInputStream)
{
	return new Object_wx_MemoryInputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
