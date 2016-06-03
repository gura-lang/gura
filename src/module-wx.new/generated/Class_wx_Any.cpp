//----------------------------------------------------------------------------
// wxAny
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAny
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAny
//----------------------------------------------------------------------------
Object_wx_Any::~Object_wx_Any()
{
}

Object *Object_wx_Any::Clone() const
{
	return nullptr;
}

String Object_wx_Any::ToString(bool exprFlag)
{
	String rtn("<wx.Any:");
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
Gura_DeclareMethodAlias(wx_Any, __wxAny, "wxAny")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Any, __wxAny)
{
	Object_wx_Any *pThis = Object_wx_Any::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxAny();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Any, __wxAny_1, "wxAny_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Any, __wxAny_1)
{
	Object_wx_Any *pThis = Object_wx_Any::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//pThis->GetEntity()->wxAny();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Any, __wxAny_2, "wxAny_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "any", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Any, __wxAny_2)
{
	Object_wx_Any *pThis = Object_wx_Any::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int any = arg.GetNumber(0)
	//pThis->GetEntity()->wxAny();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Any, __wxAny_3, "wxAny_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "variant", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Any, __wxAny_3)
{
	Object_wx_Any *pThis = Object_wx_Any::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int variant = arg.GetNumber(0)
	//pThis->GetEntity()->wxAny();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Any, __As, "As")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Any, __As)
{
	Object_wx_Any *pThis = Object_wx_Any::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->As();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Any, __CheckType, "CheckType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Any, __CheckType)
{
	Object_wx_Any *pThis = Object_wx_Any::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CheckType();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Any, __GetAs, "GetAs")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Any, __GetAs)
{
	Object_wx_Any *pThis = Object_wx_Any::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//pThis->GetEntity()->GetAs();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Any, __GetAs_1, "GetAs_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Any, __GetAs_1)
{
	Object_wx_Any *pThis = Object_wx_Any::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//pThis->GetEntity()->GetAs();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Any, __GetType, "GetType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Any, __GetType)
{
	Object_wx_Any *pThis = Object_wx_Any::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetType();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Any, __HasSameType, "HasSameType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "other", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Any, __HasSameType)
{
	Object_wx_Any *pThis = Object_wx_Any::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int other = arg.GetNumber(0)
	//pThis->GetEntity()->HasSameType();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Any, __IsNull, "IsNull")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Any, __IsNull)
{
	Object_wx_Any *pThis = Object_wx_Any::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsNull();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Any, __MakeNull, "MakeNull")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Any, __MakeNull)
{
	Object_wx_Any *pThis = Object_wx_Any::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->MakeNull();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxAny
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Any)
{
	Gura_AssignMethod(wx_Any, __wxAny);
	Gura_AssignMethod(wx_Any, __wxAny_1);
	Gura_AssignMethod(wx_Any, __wxAny_2);
	Gura_AssignMethod(wx_Any, __wxAny_3);
	Gura_AssignMethod(wx_Any, __As);
	Gura_AssignMethod(wx_Any, __CheckType);
	Gura_AssignMethod(wx_Any, __GetAs);
	Gura_AssignMethod(wx_Any, __GetAs_1);
	Gura_AssignMethod(wx_Any, __GetType);
	Gura_AssignMethod(wx_Any, __HasSameType);
	Gura_AssignMethod(wx_Any, __IsNull);
	Gura_AssignMethod(wx_Any, __MakeNull);
}

Gura_ImplementDescendantCreator(wx_Any)
{
	return new Object_wx_Any((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
