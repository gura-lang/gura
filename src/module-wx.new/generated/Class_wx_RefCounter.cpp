//----------------------------------------------------------------------------
// wxRefCounter
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRefCounter
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRefCounter
//----------------------------------------------------------------------------
Object_wx_RefCounter::~Object_wx_RefCounter()
{
}

Object *Object_wx_RefCounter::Clone() const
{
	return nullptr;
}

String Object_wx_RefCounter::ToString(bool exprFlag)
{
	String rtn("<wx.RefCounter:");
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
// Class implementation for wxRefCounter
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RefCounter)
{
}

Gura_ImplementDescendantCreator(wx_RefCounter)
{
	return new Object_wx_RefCounter((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
