//----------------------------------------------------------------------------
// wxConvAuto
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxConvAuto
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxConvAuto
//----------------------------------------------------------------------------
Object_wx_ConvAuto::~Object_wx_ConvAuto()
{
}

Object *Object_wx_ConvAuto::Clone() const
{
	return nullptr;
}

String Object_wx_ConvAuto::ToString(bool exprFlag)
{
	String rtn("<wx.ConvAuto:");
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
// Class implementation for wxConvAuto
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ConvAuto)
{
}

Gura_ImplementDescendantCreator(wx_ConvAuto)
{
	return new Object_wx_ConvAuto((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
