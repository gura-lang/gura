//----------------------------------------------------------------------------
// wxVarVScrollHelper
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxVarVScrollHelper
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxVarVScrollHelper
//----------------------------------------------------------------------------
Object_wx_VarVScrollHelper::~Object_wx_VarVScrollHelper()
{
}

Object *Object_wx_VarVScrollHelper::Clone() const
{
	return nullptr;
}

String Object_wx_VarVScrollHelper::ToString(bool exprFlag)
{
	String rtn("<wx.VarVScrollHelper:");
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
// Class implementation for wxVarVScrollHelper
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_VarVScrollHelper)
{
}

Gura_ImplementDescendantCreator(wx_VarVScrollHelper)
{
	return new Object_wx_VarVScrollHelper((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
