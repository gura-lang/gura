//----------------------------------------------------------------------------
// wxLongLong
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxLongLong
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxLongLong
//----------------------------------------------------------------------------
Object_wx_LongLong::~Object_wx_LongLong()
{
}

Object *Object_wx_LongLong::Clone() const
{
	return nullptr;
}

String Object_wx_LongLong::ToString(bool exprFlag)
{
	String rtn("<wx.LongLong:");
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
Gura_DeclareFunctionAlias(__LongLong, "LongLong")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_LongLong));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__LongLong)
{
	//wxLongLong();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__LongLong_1, "LongLong_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ll", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_LongLong));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__LongLong_1)
{
	//wxLongLong_t ll = arg.GetNumber(0)
	//wxLongLong();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__LongLong_2, "LongLong_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "hi", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "lo", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_LongLong));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__LongLong_2)
{
	//long hi = arg.GetNumber(0)
	//unsigned long lo = arg.GetNumber(1)
	//wxLongLong();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_LongLong, __Abs, "Abs")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_LongLong, __Abs)
{
	Object_wx_LongLong *pThis = Object_wx_LongLong::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Abs();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_LongLong, __Abs_1, "Abs_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_LongLong, __Abs_1)
{
	Object_wx_LongLong *pThis = Object_wx_LongLong::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Abs();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_LongLong, __Assign, "Assign")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "d", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_LongLong, __Assign)
{
	Object_wx_LongLong *pThis = Object_wx_LongLong::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//double d = arg.GetNumber(0)
	//pThis->GetEntity()->Assign();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_LongLong, __GetHi, "GetHi")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_LongLong, __GetHi)
{
	Object_wx_LongLong *pThis = Object_wx_LongLong::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHi();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_LongLong, __GetLo, "GetLo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_LongLong, __GetLo)
{
	Object_wx_LongLong *pThis = Object_wx_LongLong::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_LongLong, __GetValue, "GetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_LongLong, __GetValue)
{
	Object_wx_LongLong *pThis = Object_wx_LongLong::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_LongLong, __ToDouble, "ToDouble")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_LongLong, __ToDouble)
{
	Object_wx_LongLong *pThis = Object_wx_LongLong::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ToDouble();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_LongLong, __ToLong, "ToLong")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_LongLong, __ToLong)
{
	Object_wx_LongLong *pThis = Object_wx_LongLong::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ToLong();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_LongLong, __ToString, "ToString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_LongLong, __ToString)
{
	Object_wx_LongLong *pThis = Object_wx_LongLong::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ToString();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxLongLong
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_LongLong)
{
	// Constructor assignment
	Gura_AssignFunction(__LongLong);
	Gura_AssignFunction(__LongLong_1);
	Gura_AssignFunction(__LongLong_2);
	// Method assignment
	Gura_AssignMethod(wx_LongLong, __Abs);
	Gura_AssignMethod(wx_LongLong, __Abs_1);
	Gura_AssignMethod(wx_LongLong, __Assign);
	Gura_AssignMethod(wx_LongLong, __GetHi);
	Gura_AssignMethod(wx_LongLong, __GetLo);
	Gura_AssignMethod(wx_LongLong, __GetValue);
	Gura_AssignMethod(wx_LongLong, __ToDouble);
	Gura_AssignMethod(wx_LongLong, __ToLong);
	Gura_AssignMethod(wx_LongLong, __ToString);
}

Gura_ImplementDescendantCreator(wx_LongLong)
{
	return new Object_wx_LongLong((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
