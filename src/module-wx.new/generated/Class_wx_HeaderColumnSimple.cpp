//----------------------------------------------------------------------------
// wxHeaderColumnSimple
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHeaderColumnSimple
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHeaderColumnSimple
//----------------------------------------------------------------------------
Object_wx_HeaderColumnSimple::~Object_wx_HeaderColumnSimple()
{
}

Object *Object_wx_HeaderColumnSimple::Clone() const
{
	return nullptr;
}

String Object_wx_HeaderColumnSimple::ToString(bool exprFlag)
{
	String rtn("<wx.HeaderColumnSimple:");
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
// Class implementation for wxHeaderColumnSimple
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HeaderColumnSimple)
{
}

Gura_ImplementDescendantCreator(wx_HeaderColumnSimple)
{
	return new Object_wx_HeaderColumnSimple((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
