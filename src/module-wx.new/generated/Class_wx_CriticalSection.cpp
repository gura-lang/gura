//----------------------------------------------------------------------------
// wxCriticalSection
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxCriticalSection
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxCriticalSection
//----------------------------------------------------------------------------
Object_wx_CriticalSection::~Object_wx_CriticalSection()
{
}

Object *Object_wx_CriticalSection::Clone() const
{
	return nullptr;
}

String Object_wx_CriticalSection::ToString(bool exprFlag)
{
	String rtn("<wx.CriticalSection:");
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
// Class implementation for wxCriticalSection
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CriticalSection)
{
}

Gura_ImplementDescendantCreator(wx_CriticalSection)
{
	return new Object_wx_CriticalSection((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
