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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__Any, "Any")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Any));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Any)
{
	//wxAny();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Any_1, "Any_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Any));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Any_1)
{
	//const T& value = arg.GetNumber(0)
	//wxAny(value);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Any_2, "Any_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "any", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Any));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Any_2)
{
	//const wxAny& any = arg.GetNumber(0)
	//wxAny(any);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Any_3, "Any_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "variant", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Any));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Any_3)
{
	//const wxVariant& variant = arg.GetNumber(0)
	//wxAny(variant);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Any, __As, "As")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Any, __As)
{
	Object_wx_Any *pThis = Object_wx_Any::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//T _rtn = pThis->GetEntity()->As();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Any, __CheckType, "CheckType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Any, __CheckType)
{
	Object_wx_Any *pThis = Object_wx_Any::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->CheckType();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Any, __GetAs, "GetAs")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Any, __GetAs)
{
	Object_wx_Any *pThis = Object_wx_Any::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//T* value = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->GetAs(value);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Any, __GetAs_1, "GetAs_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Any, __GetAs_1)
{
	Object_wx_Any *pThis = Object_wx_Any::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxVariant* value = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->GetAs(value);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Any, __GetType, "GetType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Any, __GetType)
{
	Object_wx_Any *pThis = Object_wx_Any::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxAnyValueType* _rtn = pThis->GetEntity()->GetType();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Any, __HasSameType, "HasSameType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "other", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Any, __HasSameType)
{
	Object_wx_Any *pThis = Object_wx_Any::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxAny& other = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->HasSameType(other);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Any, __IsNull, "IsNull")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Any, __IsNull)
{
	Object_wx_Any *pThis = Object_wx_Any::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsNull();
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
	// Constructor assignment
	Gura_AssignFunction(__Any);
	Gura_AssignFunction(__Any_1);
	Gura_AssignFunction(__Any_2);
	Gura_AssignFunction(__Any_3);
	// Method assignment
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
