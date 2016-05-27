//----------------------------------------------------------------------------
// wxVarHVScrollHelper
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxVarHVScrollHelper
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxVarHVScrollHelper
//----------------------------------------------------------------------------
Object_wx_VarHVScrollHelper::~Object_wx_VarHVScrollHelper()
{
}

Object *Object_wx_VarHVScrollHelper::Clone() const
{
	return nullptr;
}

String Object_wx_VarHVScrollHelper::ToString(bool exprFlag)
{
	String rtn("<wx.VarHVScrollHelper:");
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
// Class implementation for wxVarHVScrollHelper
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_VarHVScrollHelper)
{
}

Gura_ImplementDescendantCreator(wx_VarHVScrollHelper)
{
	return new Object_wx_VarHVScrollHelper((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
