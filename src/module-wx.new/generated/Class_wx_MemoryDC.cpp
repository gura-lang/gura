//----------------------------------------------------------------------------
// wxMemoryDC
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMemoryDC
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMemoryDC
//----------------------------------------------------------------------------
Object_wx_MemoryDC::~Object_wx_MemoryDC()
{
}

Object *Object_wx_MemoryDC::Clone() const
{
	return nullptr;
}

String Object_wx_MemoryDC::ToString(bool exprFlag)
{
	String rtn("<wx.MemoryDC:");
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
// Class implementation for wxMemoryDC
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MemoryDC)
{
}

Gura_ImplementDescendantCreator(wx_MemoryDC)
{
	return new Object_wx_MemoryDC((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
