//----------------------------------------------------------------------------
// wxAnyValueType
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAnyValueType
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAnyValueType
//----------------------------------------------------------------------------
Object_wx_AnyValueType::~Object_wx_AnyValueType()
{
}

Object *Object_wx_AnyValueType::Clone() const
{
	return nullptr;
}

String Object_wx_AnyValueType::ToString(bool exprFlag)
{
	String rtn("<wx.AnyValueType:");
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
Gura_DeclareFunctionAlias(__AnyValueType, "AnyValueType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_AnyValueType));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__AnyValueType)
{
	//wxAnyValueType();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_AnyValueType, __CheckType, "CheckType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_AnyValueType, __CheckType)
{
	Object_wx_AnyValueType *pThis = Object_wx_AnyValueType::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->CheckType();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AnyValueType, __ConvertValue, "ConvertValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "src", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dstType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dst", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnyValueType, __ConvertValue)
{
	Object_wx_AnyValueType *pThis = Object_wx_AnyValueType::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxAnyValueBuffer& src = arg.GetNumber(0)
	//wxAnyValueType* dstType = arg.GetNumber(1)
	//wxAnyValueBuffer& dst = arg.GetNumber(2)
	//bool _rtn = pThis->GetEntity()->ConvertValue(src, dstType, dst);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AnyValueType, __CopyBuffer, "CopyBuffer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "src", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dst", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnyValueType, __CopyBuffer)
{
	Object_wx_AnyValueType *pThis = Object_wx_AnyValueType::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxAnyValueBuffer& src = arg.GetNumber(0)
	//wxAnyValueBuffer& dst = arg.GetNumber(1)
	//pThis->GetEntity()->CopyBuffer(src, dst);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AnyValueType, __DeleteValue, "DeleteValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnyValueType, __DeleteValue)
{
	Object_wx_AnyValueType *pThis = Object_wx_AnyValueType::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxAnyValueBuffer& buf = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteValue(buf);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AnyValueType, __IsSameType, "IsSameType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "otherType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnyValueType, __IsSameType)
{
	Object_wx_AnyValueType *pThis = Object_wx_AnyValueType::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxAnyValueType* otherType = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->IsSameType(otherType);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxAnyValueType
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AnyValueType)
{
	// Constructor assignment
	Gura_AssignFunction(__AnyValueType);
	// Method assignment
	Gura_AssignMethod(wx_AnyValueType, __CheckType);
	Gura_AssignMethod(wx_AnyValueType, __ConvertValue);
	Gura_AssignMethod(wx_AnyValueType, __CopyBuffer);
	Gura_AssignMethod(wx_AnyValueType, __DeleteValue);
	Gura_AssignMethod(wx_AnyValueType, __IsSameType);
}

Gura_ImplementDescendantCreator(wx_AnyValueType)
{
	return new Object_wx_AnyValueType((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
