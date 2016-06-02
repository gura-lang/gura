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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_ScopedArray, wxScopedArray)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "array", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ScopedArray, wxScopedArray)
{
	Object_wx_ScopedArray *pThis = Object_wx_ScopedArray::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int array = arg.GetNumber(0)
	//pThis->GetEntity()->wxScopedArray();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ScopedArray, wxScopedArray_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "count", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ScopedArray, wxScopedArray_1)
{
	Object_wx_ScopedArray *pThis = Object_wx_ScopedArray::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int count = arg.GetNumber(0)
	//pThis->GetEntity()->wxScopedArray();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ScopedArray, unspecified_bool_type)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ScopedArray, unspecified_bool_type)
{
	Object_wx_ScopedArray *pThis = Object_wx_ScopedArray::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->unspecified_bool_type();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ScopedArray, reset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "array", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ScopedArray, reset)
{
	Object_wx_ScopedArray *pThis = Object_wx_ScopedArray::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int array = arg.GetNumber(0)
	//pThis->GetEntity()->reset();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ScopedArray, get)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ScopedArray, get)
{
	Object_wx_ScopedArray *pThis = Object_wx_ScopedArray::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->get();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ScopedArray, swap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "other", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ScopedArray, swap)
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
	Gura_AssignMethod(wx_ScopedArray, wxScopedArray);
	Gura_AssignMethod(wx_ScopedArray, wxScopedArray_1);
	Gura_AssignMethod(wx_ScopedArray, unspecified_bool_type);
	Gura_AssignMethod(wx_ScopedArray, reset);
	Gura_AssignMethod(wx_ScopedArray, get);
	Gura_AssignMethod(wx_ScopedArray, swap);
}

Gura_ImplementDescendantCreator(wx_ScopedArray)
{
	return new Object_wx_ScopedArray((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
