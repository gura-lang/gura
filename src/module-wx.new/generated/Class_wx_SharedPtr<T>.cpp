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
Gura_DeclareMethodAlias(wx_SharedPtr<T>, __wxSharedPtr, "wxSharedPtr")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "ptr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SharedPtr<T>, __wxSharedPtr)
{
	Object_wx_SharedPtr<T> *pThis = Object_wx_SharedPtr<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//T* ptr = arg.GetNumber(0)
	//wxEXPLICIT _rtn = pThis->GetEntity()->wxSharedPtr(ptr);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SharedPtr<T>, __wxSharedPtr_1, "wxSharedPtr_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "ptr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "d", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SharedPtr<T>, __wxSharedPtr_1)
{
	Object_wx_SharedPtr<T> *pThis = Object_wx_SharedPtr<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//T* ptr = arg.GetNumber(0)
	//Deleter d = arg.GetNumber(1)
	//wxEXPLICIT _rtn = pThis->GetEntity()->wxSharedPtr(ptr, d);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SharedPtr<T>, __wxSharedPtr_2, "wxSharedPtr_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "tocopy", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SharedPtr<T>, __wxSharedPtr_2)
{
	Object_wx_SharedPtr<T> *pThis = Object_wx_SharedPtr<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxSharedPtr<T>& tocopy = arg.GetNumber(0)
	//pThis->GetEntity()->wxSharedPtr(tocopy);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SharedPtr<T>, __get, "get")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_SharedPtr<T>, __get)
{
	Object_wx_SharedPtr<T> *pThis = Object_wx_SharedPtr<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//T* _rtn = pThis->GetEntity()->get();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SharedPtr<T>, __unspecified_bool_type, "unspecified_bool_type")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_SharedPtr<T>, __unspecified_bool_type)
{
	Object_wx_SharedPtr<T> *pThis = Object_wx_SharedPtr<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//operator _rtn = pThis->GetEntity()->unspecified_bool_type();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SharedPtr<T>, __reset, "reset")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ptr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SharedPtr<T>, __reset)
{
	Object_wx_SharedPtr<T> *pThis = Object_wx_SharedPtr<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//T* ptr = arg.GetNumber(0)
	//pThis->GetEntity()->reset(ptr);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SharedPtr<T>, __reset_1, "reset_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ptr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "d", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SharedPtr<T>, __reset_1)
{
	Object_wx_SharedPtr<T> *pThis = Object_wx_SharedPtr<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//T* ptr = arg.GetNumber(0)
	//Deleter d = arg.GetNumber(1)
	//pThis->GetEntity()->reset(ptr, d);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SharedPtr<T>, __unique, "unique")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_SharedPtr<T>, __unique)
{
	Object_wx_SharedPtr<T> *pThis = Object_wx_SharedPtr<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->unique();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SharedPtr<T>, __use_count, "use_count")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_SharedPtr<T>, __use_count)
{
	Object_wx_SharedPtr<T> *pThis = Object_wx_SharedPtr<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long _rtn = pThis->GetEntity()->use_count();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSharedPtr<T>
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SharedPtr<T>)
{
	// Class assignment
	Gura_AssignValueEx("SharedPtr<T>", Reference());
	// Method assignment
	Gura_AssignMethod(wx_SharedPtr<T>, __wxSharedPtr);
	Gura_AssignMethod(wx_SharedPtr<T>, __wxSharedPtr_1);
	Gura_AssignMethod(wx_SharedPtr<T>, __wxSharedPtr_2);
	Gura_AssignMethod(wx_SharedPtr<T>, __get);
	Gura_AssignMethod(wx_SharedPtr<T>, __unspecified_bool_type);
	Gura_AssignMethod(wx_SharedPtr<T>, __reset);
	Gura_AssignMethod(wx_SharedPtr<T>, __reset_1);
	Gura_AssignMethod(wx_SharedPtr<T>, __unique);
	Gura_AssignMethod(wx_SharedPtr<T>, __use_count);
}

Gura_ImplementDescendantCreator(wx_SharedPtr<T>)
{
	return new Object_wx_SharedPtr<T>((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
