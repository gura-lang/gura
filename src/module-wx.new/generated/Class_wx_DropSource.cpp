//----------------------------------------------------------------------------
// wxDropSource
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDropSource
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDropSource
//----------------------------------------------------------------------------
Object_wx_DropSource::~Object_wx_DropSource()
{
}

Object *Object_wx_DropSource::Clone() const
{
	return nullptr;
}

String Object_wx_DropSource::ToString(bool exprFlag)
{
	String rtn("<wx.DropSource:");
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
// Class implementation for wxDropSource
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DropSource)
{
}

Gura_ImplementDescendantCreator(wx_DropSource)
{
	return new Object_wx_DropSource((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
