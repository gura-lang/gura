//----------------------------------------------------------------------------
// wxWrapSizer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxWrapSizer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxWrapSizer
//----------------------------------------------------------------------------
Object_wx_WrapSizer::~Object_wx_WrapSizer()
{
}

Object *Object_wx_WrapSizer::Clone() const
{
	return nullptr;
}

String Object_wx_WrapSizer::ToString(bool exprFlag)
{
	String rtn("<wx.WrapSizer:");
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
// Class implementation for wxWrapSizer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WrapSizer)
{
}

Gura_ImplementDescendantCreator(wx_WrapSizer)
{
	return new Object_wx_WrapSizer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
