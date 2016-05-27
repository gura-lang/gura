//----------------------------------------------------------------------------
// wxWrapperInputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxWrapperInputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxWrapperInputStream
//----------------------------------------------------------------------------
Object_wx_WrapperInputStream::~Object_wx_WrapperInputStream()
{
}

Object *Object_wx_WrapperInputStream::Clone() const
{
	return nullptr;
}

String Object_wx_WrapperInputStream::ToString(bool exprFlag)
{
	String rtn("<wx.WrapperInputStream:");
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
// Class implementation for wxWrapperInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WrapperInputStream)
{
}

Gura_ImplementDescendantCreator(wx_WrapperInputStream)
{
	return new Object_wx_WrapperInputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
