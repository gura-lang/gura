//----------------------------------------------------------------------------
// wxScopedPtr<T>
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxScopedPtr<T>
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxScopedPtr<T>
//----------------------------------------------------------------------------
Object_wx_ScopedPtr<T>::~Object_wx_ScopedPtr<T>()
{
}

Object *Object_wx_ScopedPtr<T>::Clone() const
{
	return nullptr;
}

String Object_wx_ScopedPtr<T>::ToString(bool exprFlag)
{
	String rtn("<wx.ScopedPtr<T>:");
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
Gura_DeclareMethodAlias(wx_ScopedPtr<T>, __wxScopedPtr, "wxScopedPtr")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ptr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ScopedPtr<T>, __wxScopedPtr)
{
	Object_wx_ScopedPtr<T> *pThis = Object_wx_ScopedPtr<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ptr = arg.GetNumber(0)
	//pThis->GetEntity()->wxScopedPtr();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ScopedPtr<T>, __get, "get")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ScopedPtr<T>, __get)
{
	Object_wx_ScopedPtr<T> *pThis = Object_wx_ScopedPtr<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->get();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ScopedPtr<T>, __unspecified_bool_type, "unspecified_bool_type")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ScopedPtr<T>, __unspecified_bool_type)
{
	Object_wx_ScopedPtr<T> *pThis = Object_wx_ScopedPtr<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->unspecified_bool_type();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ScopedPtr<T>, __release, "release")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ScopedPtr<T>, __release)
{
	Object_wx_ScopedPtr<T> *pThis = Object_wx_ScopedPtr<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->release();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ScopedPtr<T>, __reset, "reset")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ptr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ScopedPtr<T>, __reset)
{
	Object_wx_ScopedPtr<T> *pThis = Object_wx_ScopedPtr<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ptr = arg.GetNumber(0)
	//pThis->GetEntity()->reset();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ScopedPtr<T>, __swap, "swap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ot", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ScopedPtr<T>, __swap)
{
	Object_wx_ScopedPtr<T> *pThis = Object_wx_ScopedPtr<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ot = arg.GetNumber(0)
	//pThis->GetEntity()->swap();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxScopedPtr<T>
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ScopedPtr<T>)
{
	// Method assignment
	Gura_AssignMethod(wx_ScopedPtr<T>, __wxScopedPtr);
	Gura_AssignMethod(wx_ScopedPtr<T>, __get);
	Gura_AssignMethod(wx_ScopedPtr<T>, __unspecified_bool_type);
	Gura_AssignMethod(wx_ScopedPtr<T>, __release);
	Gura_AssignMethod(wx_ScopedPtr<T>, __reset);
	Gura_AssignMethod(wx_ScopedPtr<T>, __swap);
}

Gura_ImplementDescendantCreator(wx_ScopedPtr<T>)
{
	return new Object_wx_ScopedPtr<T>((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
