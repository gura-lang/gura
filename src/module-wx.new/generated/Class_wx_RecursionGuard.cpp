//----------------------------------------------------------------------------
// wxRecursionGuard
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRecursionGuard
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRecursionGuard
//----------------------------------------------------------------------------
Object_wx_RecursionGuard::~Object_wx_RecursionGuard()
{
}

Object *Object_wx_RecursionGuard::Clone() const
{
	return nullptr;
}

String Object_wx_RecursionGuard::ToString(bool exprFlag)
{
	String rtn("<wx.RecursionGuard:");
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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxRecursionGuard, "wxRecursionGuard")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxRecursionGuard)
{
	//int flag = arg.GetNumber(0)
	//wxRecursionGuard();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RecursionGuard, __IsInside, "IsInside")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RecursionGuard, __IsInside)
{
	Object_wx_RecursionGuard *pThis = Object_wx_RecursionGuard::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsInside();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRecursionGuard
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RecursionGuard)
{
	// Constructor assignment
	Gura_AssignFunction(__wxRecursionGuard);
	// Method assignment
	Gura_AssignMethod(wx_RecursionGuard, __IsInside);
}

Gura_ImplementDescendantCreator(wx_RecursionGuard)
{
	return new Object_wx_RecursionGuard((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
