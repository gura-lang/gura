//----------------------------------------------------------------------------
// wxDirTraverser
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDirTraverser
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDirTraverser
//----------------------------------------------------------------------------
Object_wx_DirTraverser::~Object_wx_DirTraverser()
{
}

Object *Object_wx_DirTraverser::Clone() const
{
	return nullptr;
}

String Object_wx_DirTraverser::ToString(bool exprFlag)
{
	String rtn("<wx.DirTraverser:");
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
// Class implementation for wxDirTraverser
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DirTraverser)
{
}

Gura_ImplementDescendantCreator(wx_DirTraverser)
{
	return new Object_wx_DirTraverser((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
