//----------------------------------------------------------------------------
// wxStaticBoxSizer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxStaticBoxSizer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxStaticBoxSizer
//----------------------------------------------------------------------------
Object_wx_StaticBoxSizer::~Object_wx_StaticBoxSizer()
{
}

Object *Object_wx_StaticBoxSizer::Clone() const
{
	return nullptr;
}

String Object_wx_StaticBoxSizer::ToString(bool exprFlag)
{
	String rtn("<wx.StaticBoxSizer:");
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
// Class implementation for wxStaticBoxSizer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StaticBoxSizer)
{
}

Gura_ImplementDescendantCreator(wx_StaticBoxSizer)
{
	return new Object_wx_StaticBoxSizer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
