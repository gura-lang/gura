//----------------------------------------------------------------------------
// wxSingleInstanceChecker
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSingleInstanceChecker
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSingleInstanceChecker
//----------------------------------------------------------------------------
Object_wx_SingleInstanceChecker::~Object_wx_SingleInstanceChecker()
{
}

Object *Object_wx_SingleInstanceChecker::Clone() const
{
	return nullptr;
}

String Object_wx_SingleInstanceChecker::ToString(bool exprFlag)
{
	String rtn("<wx.SingleInstanceChecker:");
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
// Class implementation for wxSingleInstanceChecker
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SingleInstanceChecker)
{
}

Gura_ImplementDescendantCreator(wx_SingleInstanceChecker)
{
	return new Object_wx_SingleInstanceChecker((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
