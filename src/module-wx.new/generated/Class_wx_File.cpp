//----------------------------------------------------------------------------
// wxFile
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFile
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFile
//----------------------------------------------------------------------------
Object_wx_File::~Object_wx_File()
{
}

Object *Object_wx_File::Clone() const
{
	return nullptr;
}

String Object_wx_File::ToString(bool exprFlag)
{
	String rtn("<wx.File:");
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
// Class implementation for wxFile
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_File)
{
}

Gura_ImplementDescendantCreator(wx_File)
{
	return new Object_wx_File((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
