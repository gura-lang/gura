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
Gura_DeclareMethod(wx_WeakRef<T>, wxWeakRef)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pobj", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WeakRef<T>, wxWeakRef)
{
	Signal &sig = env.GetSignal();
	Object_wx_WeakRef<T> *pThis = Object_wx_WeakRef<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pobj = arg.GetNumber(0)
	//pThis->GetEntity()->wxWeakRef();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WeakRef<T>, wxWeakRef_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "wr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WeakRef<T>, wxWeakRef_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_WeakRef<T> *pThis = Object_wx_WeakRef<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int wr = arg.GetNumber(0)
	//pThis->GetEntity()->wxWeakRef();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WeakRef<T>, ~wxWeakRef)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WeakRef<T>, ~wxWeakRef)
{
	Signal &sig = env.GetSignal();
	Object_wx_WeakRef<T> *pThis = Object_wx_WeakRef<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxWeakRef();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WeakRef<T>, OnObjectDestroy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WeakRef<T>, OnObjectDestroy)
{
	Signal &sig = env.GetSignal();
	Object_wx_WeakRef<T> *pThis = Object_wx_WeakRef<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->OnObjectDestroy();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WeakRef<T>, Release)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WeakRef<T>, Release)
{
	Signal &sig = env.GetSignal();
	Object_wx_WeakRef<T> *pThis = Object_wx_WeakRef<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Release();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WeakRef<T>, get)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WeakRef<T>, get)
{
	Signal &sig = env.GetSignal();
	Object_wx_WeakRef<T> *pThis = Object_wx_WeakRef<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->get();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxWeakRef<T>
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WeakRef<T>)
{
	Gura_AssignMethod(wx_WeakRef<T>, wxWeakRef);
	Gura_AssignMethod(wx_WeakRef<T>, wxWeakRef_1);
	Gura_AssignMethod(wx_WeakRef<T>, ~wxWeakRef);
	Gura_AssignMethod(wx_WeakRef<T>, OnObjectDestroy);
	Gura_AssignMethod(wx_WeakRef<T>, Release);
	Gura_AssignMethod(wx_WeakRef<T>, get);
}

Gura_ImplementDescendantCreator(wx_WeakRef<T>)
{
	return new Object_wx_WeakRef<T>((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
