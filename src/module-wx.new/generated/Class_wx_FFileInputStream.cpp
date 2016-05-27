//----------------------------------------------------------------------------
// wxFFileInputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFFileInputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFFileInputStream
//----------------------------------------------------------------------------
Object_wx_FFileInputStream::~Object_wx_FFileInputStream()
{
}

Object *Object_wx_FFileInputStream::Clone() const
{
	return nullptr;
}

String Object_wx_FFileInputStream::ToString(bool exprFlag)
{
	String rtn("<wx.FFileInputStream:");
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
// Class implementation for wxFFileInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FFileInputStream)
{
}

Gura_ImplementDescendantCreator(wx_FFileInputStream)
{
	return new Object_wx_FFileInputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
