//----------------------------------------------------------------------------
// wxStackWalker
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxStackWalker
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxStackWalker
//----------------------------------------------------------------------------
Object_wx_StackWalker::~Object_wx_StackWalker()
{
}

Object *Object_wx_StackWalker::Clone() const
{
	return nullptr;
}

String Object_wx_StackWalker::ToString(bool exprFlag)
{
	String rtn("<wx.StackWalker:");
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
// Class implementation for wxStackWalker
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StackWalker)
{
}

Gura_ImplementDescendantCreator(wx_StackWalker)
{
	return new Object_wx_StackWalker((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
