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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_Initializer, wxInitializer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "argc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "argv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Initializer, wxInitializer)
{
	Object_wx_Initializer *pThis = Object_wx_Initializer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int argc = arg.GetNumber(0)
	//int argv = arg.GetNumber(1)
	//pThis->GetEntity()->wxInitializer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Initializer, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Initializer, IsOk)
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
	Gura_AssignMethod(wx_Initializer, wxInitializer);
	Gura_AssignMethod(wx_Initializer, IsOk);
}

Gura_ImplementDescendantCreator(wx_Initializer)
{
	return new Object_wx_Initializer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
