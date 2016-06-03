//----------------------------------------------------------------------------
// wxWeakRef<T>
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxWeakRef<T>
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxWeakRef<T>
//----------------------------------------------------------------------------
Object_wx_WeakRef<T>::~Object_wx_WeakRef<T>()
{
}

Object *Object_wx_WeakRef<T>::Clone() const
{
	return nullptr;
}

String Object_wx_WeakRef<T>::ToString(bool exprFlag)
{
	String rtn("<wx.WeakRef<T>:");
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
Gura_DeclareMethodAlias(wx_WeakRef<T>, __wxWeakRef, "wxWeakRef")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pobj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WeakRef<T>, __wxWeakRef)
{
	Object_wx_WeakRef<T> *pThis = Object_wx_WeakRef<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pobj = arg.GetNumber(0)
	//pThis->GetEntity()->wxWeakRef();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WeakRef<T>, __wxWeakRef_1, "wxWeakRef_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "wr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WeakRef<T>, __wxWeakRef_1)
{
	Object_wx_WeakRef<T> *pThis = Object_wx_WeakRef<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int wr = arg.GetNumber(0)
	//pThis->GetEntity()->wxWeakRef();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WeakRef<T>, __OnObjectDestroy, "OnObjectDestroy")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WeakRef<T>, __OnObjectDestroy)
{
	Object_wx_WeakRef<T> *pThis = Object_wx_WeakRef<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->OnObjectDestroy();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WeakRef<T>, __Release, "Release")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WeakRef<T>, __Release)
{
	Object_wx_WeakRef<T> *pThis = Object_wx_WeakRef<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Release();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WeakRef<T>, __get, "get")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WeakRef<T>, __get)
{
	Object_wx_WeakRef<T> *pThis = Object_wx_WeakRef<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->get();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxWeakRef<T>
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WeakRef<T>)
{
	Gura_AssignMethod(wx_WeakRef<T>, __wxWeakRef);
	Gura_AssignMethod(wx_WeakRef<T>, __wxWeakRef_1);
	Gura_AssignMethod(wx_WeakRef<T>, __OnObjectDestroy);
	Gura_AssignMethod(wx_WeakRef<T>, __Release);
	Gura_AssignMethod(wx_WeakRef<T>, __get);
}

Gura_ImplementDescendantCreator(wx_WeakRef<T>)
{
	return new Object_wx_WeakRef<T>((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
