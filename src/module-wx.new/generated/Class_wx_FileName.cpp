//----------------------------------------------------------------------------
// wxFileName
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFileName
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFileName
//----------------------------------------------------------------------------
Object_wx_FileName::~Object_wx_FileName()
{
}

Object *Object_wx_FileName::Clone() const
{
	return nullptr;
}

String Object_wx_FileName::ToString(bool exprFlag)
{
	String rtn("<wx.FileName:");
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
// Class implementation for wxFileName
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileName)
{
}

Gura_ImplementDescendantCreator(wx_FileName)
{
	return new Object_wx_FileName((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
