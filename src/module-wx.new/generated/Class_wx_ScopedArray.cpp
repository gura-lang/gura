//----------------------------------------------------------------------------
// wxScopedArray
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxScopedArray
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxScopedArray
//----------------------------------------------------------------------------
Object_wx_ScopedArray::~Object_wx_ScopedArray()
{
}

Object *Object_wx_ScopedArray::Clone() const
{
	return nullptr;
}

String Object_wx_ScopedArray::ToString(bool exprFlag)
{
	String rtn("<wx.ScopedArray:");
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
Gura_DeclareFunctionAlias(__ScopedArray, "ScopedArray")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "array", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_ScopedArray));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__ScopedArray)
{
	//int array = arg.GetNumber(0)
	//wxScopedArray();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__ScopedArray_1, "ScopedArray_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "count", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_ScopedArray));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__ScopedArray_1)
{
	//int count = arg.GetNumber(0)
	//wxScopedArray();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_ScopedArray, __unspecified_bool_type, "unspecified_bool_type")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ScopedArray, __unspecified_bool_type)
{
	Object_wx_ScopedArray *pThis = Object_wx_ScopedArray::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->unspecified_bool_type();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ScopedArray, __reset, "reset")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "array", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ScopedArray, __reset)
{
	Object_wx_ScopedArray *pThis = Object_wx_ScopedArray::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int array = arg.GetNumber(0)
	//pThis->GetEntity()->reset();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ScopedArray, __get, "get")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ScopedArray, __get)
{
	Object_wx_ScopedArray *pThis = Object_wx_ScopedArray::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->get();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ScopedArray, __swap, "swap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "other", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ScopedArray, __swap)
{
	Object_wx_ScopedArray *pThis = Object_wx_ScopedArray::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int other = arg.GetNumber(0)
	//pThis->GetEntity()->swap();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxScopedArray
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ScopedArray)
{
	// Constructor assignment
	Gura_AssignFunction(__ScopedArray);
	Gura_AssignFunction(__ScopedArray_1);
	// Method assignment
	Gura_AssignMethod(wx_ScopedArray, __unspecified_bool_type);
	Gura_AssignMethod(wx_ScopedArray, __reset);
	Gura_AssignMethod(wx_ScopedArray, __get);
	Gura_AssignMethod(wx_ScopedArray, __swap);
}

Gura_ImplementDescendantCreator(wx_ScopedArray)
{
	return new Object_wx_ScopedArray((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
