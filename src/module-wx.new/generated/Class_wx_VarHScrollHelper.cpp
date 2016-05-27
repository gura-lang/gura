//----------------------------------------------------------------------------
// wxVarHScrollHelper
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxVarHScrollHelper
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxVarHScrollHelper
//----------------------------------------------------------------------------
Object_wx_VarHScrollHelper::~Object_wx_VarHScrollHelper()
{
}

Object *Object_wx_VarHScrollHelper::Clone() const
{
	return nullptr;
}

String Object_wx_VarHScrollHelper::ToString(bool exprFlag)
{
	String rtn("<wx.VarHScrollHelper:");
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
// Class implementation for wxVarHScrollHelper
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_VarHScrollHelper)
{
}

Gura_ImplementDescendantCreator(wx_VarHScrollHelper)
{
	return new Object_wx_VarHScrollHelper((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
