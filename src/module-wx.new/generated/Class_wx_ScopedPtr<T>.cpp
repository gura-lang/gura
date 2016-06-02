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
Gura_DeclareMethod(wx_ScopedPtr<T>, wxScopedPtr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ptr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ScopedPtr<T>, wxScopedPtr)
{
	Object_wx_ScopedPtr<T> *pThis = Object_wx_ScopedPtr<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ptr = arg.GetNumber(0)
	//pThis->GetEntity()->wxScopedPtr();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ScopedPtr<T>, get)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ScopedPtr<T>, get)
{
	Object_wx_ScopedPtr<T> *pThis = Object_wx_ScopedPtr<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->get();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ScopedPtr<T>, unspecified_bool_type)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ScopedPtr<T>, unspecified_bool_type)
{
	Object_wx_ScopedPtr<T> *pThis = Object_wx_ScopedPtr<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->unspecified_bool_type();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ScopedPtr<T>, release)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ScopedPtr<T>, release)
{
	Object_wx_ScopedPtr<T> *pThis = Object_wx_ScopedPtr<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->release();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ScopedPtr<T>, reset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ptr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ScopedPtr<T>, reset)
{
	Object_wx_ScopedPtr<T> *pThis = Object_wx_ScopedPtr<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ptr = arg.GetNumber(0)
	//pThis->GetEntity()->reset();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ScopedPtr<T>, swap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ot", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ScopedPtr<T>, swap)
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
	Gura_AssignMethod(wx_ScopedPtr<T>, wxScopedPtr);
	Gura_AssignMethod(wx_ScopedPtr<T>, get);
	Gura_AssignMethod(wx_ScopedPtr<T>, unspecified_bool_type);
	Gura_AssignMethod(wx_ScopedPtr<T>, release);
	Gura_AssignMethod(wx_ScopedPtr<T>, reset);
	Gura_AssignMethod(wx_ScopedPtr<T>, swap);
}

Gura_ImplementDescendantCreator(wx_ScopedPtr<T>)
{
	return new Object_wx_ScopedPtr<T>((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
