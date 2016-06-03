//----------------------------------------------------------------------------
// wxInitializer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxInitializer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxInitializer
//----------------------------------------------------------------------------
Object_wx_Initializer::~Object_wx_Initializer()
{
}

Object *Object_wx_Initializer::Clone() const
{
	return nullptr;
}

String Object_wx_Initializer::ToString(bool exprFlag)
{
	String rtn("<wx.Initializer:");
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
Gura_DeclareFunctionAlias(__wxInitializer, "wxInitializer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "argc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "argv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxInitializer)
{
	//int argc = arg.GetNumber(0)
	//int argv = arg.GetNumber(1)
	//wxInitializer();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Initializer, __IsOk, "IsOk")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Initializer, __IsOk)
{
	Object_wx_Initializer *pThis = Object_wx_Initializer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxInitializer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Initializer)
{
	// Constructor assignment
	Gura_AssignFunction(__wxInitializer);
	// Method assignment
	Gura_AssignMethod(wx_Initializer, __IsOk);
}

Gura_ImplementDescendantCreator(wx_Initializer)
{
	return new Object_wx_Initializer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
