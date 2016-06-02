//----------------------------------------------------------------------------
// wxSharedPtr<T>
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSharedPtr<T>
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSharedPtr<T>
//----------------------------------------------------------------------------
Object_wx_SharedPtr<T>::~Object_wx_SharedPtr<T>()
{
}

Object *Object_wx_SharedPtr<T>::Clone() const
{
	return nullptr;
}

String Object_wx_SharedPtr<T>::ToString(bool exprFlag)
{
	String rtn("<wx.SharedPtr<T>:");
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
Gura_DeclareMethod(wx_SharedPtr<T>, wxSharedPtr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ptr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SharedPtr<T>, wxSharedPtr)
{
	Object_wx_SharedPtr<T> *pThis = Object_wx_SharedPtr<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ptr = arg.GetNumber(0)
	//pThis->GetEntity()->wxSharedPtr();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SharedPtr<T>, wxSharedPtr_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ptr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "d", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SharedPtr<T>, wxSharedPtr_1)
{
	Object_wx_SharedPtr<T> *pThis = Object_wx_SharedPtr<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ptr = arg.GetNumber(0)
	//int d = arg.GetNumber(1)
	//pThis->GetEntity()->wxSharedPtr();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SharedPtr<T>, wxSharedPtr_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tocopy", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SharedPtr<T>, wxSharedPtr_2)
{
	Object_wx_SharedPtr<T> *pThis = Object_wx_SharedPtr<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tocopy = arg.GetNumber(0)
	//pThis->GetEntity()->wxSharedPtr();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SharedPtr<T>, get)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SharedPtr<T>, get)
{
	Object_wx_SharedPtr<T> *pThis = Object_wx_SharedPtr<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->get();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SharedPtr<T>, unspecified_bool_type)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SharedPtr<T>, unspecified_bool_type)
{
	Object_wx_SharedPtr<T> *pThis = Object_wx_SharedPtr<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->unspecified_bool_type();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SharedPtr<T>, reset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ptr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SharedPtr<T>, reset)
{
	Object_wx_SharedPtr<T> *pThis = Object_wx_SharedPtr<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ptr = arg.GetNumber(0)
	//pThis->GetEntity()->reset();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SharedPtr<T>, reset_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ptr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "d", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SharedPtr<T>, reset_1)
{
	Object_wx_SharedPtr<T> *pThis = Object_wx_SharedPtr<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ptr = arg.GetNumber(0)
	//int d = arg.GetNumber(1)
	//pThis->GetEntity()->reset();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SharedPtr<T>, unique)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SharedPtr<T>, unique)
{
	Object_wx_SharedPtr<T> *pThis = Object_wx_SharedPtr<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->unique();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SharedPtr<T>, use_count)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SharedPtr<T>, use_count)
{
	Object_wx_SharedPtr<T> *pThis = Object_wx_SharedPtr<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->use_count();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSharedPtr<T>
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SharedPtr<T>)
{
	Gura_AssignMethod(wx_SharedPtr<T>, wxSharedPtr);
	Gura_AssignMethod(wx_SharedPtr<T>, wxSharedPtr_1);
	Gura_AssignMethod(wx_SharedPtr<T>, wxSharedPtr_2);
	Gura_AssignMethod(wx_SharedPtr<T>, get);
	Gura_AssignMethod(wx_SharedPtr<T>, unspecified_bool_type);
	Gura_AssignMethod(wx_SharedPtr<T>, reset);
	Gura_AssignMethod(wx_SharedPtr<T>, reset_1);
	Gura_AssignMethod(wx_SharedPtr<T>, unique);
	Gura_AssignMethod(wx_SharedPtr<T>, use_count);
}

Gura_ImplementDescendantCreator(wx_SharedPtr<T>)
{
	return new Object_wx_SharedPtr<T>((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
