//----------------------------------------------------------------------------
// wxStack<T>
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxStack<T>
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxStack<T>
//----------------------------------------------------------------------------
Object_wx_Stack<T>::~Object_wx_Stack<T>()
{
}

Object *Object_wx_Stack<T>::Clone() const
{
	return nullptr;
}

String Object_wx_Stack<T>::ToString(bool exprFlag)
{
	String rtn("<wx.Stack<T>:");
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
Gura_DeclareMethod(wx_Stack<T>, wxStack)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Stack<T>, wxStack)
{
	Object_wx_Stack<T> *pThis = Object_wx_Stack<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxStack();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Stack<T>, wxStack_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cont", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Stack<T>, wxStack_1)
{
	Object_wx_Stack<T> *pThis = Object_wx_Stack<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int cont = arg.GetNumber(0)
	//pThis->GetEntity()->wxStack();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Stack<T>, empty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Stack<T>, empty)
{
	Object_wx_Stack<T> *pThis = Object_wx_Stack<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->empty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Stack<T>, size)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Stack<T>, size)
{
	Object_wx_Stack<T> *pThis = Object_wx_Stack<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->size();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Stack<T>, top)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Stack<T>, top)
{
	Object_wx_Stack<T> *pThis = Object_wx_Stack<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->top();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Stack<T>, top_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Stack<T>, top_1)
{
	Object_wx_Stack<T> *pThis = Object_wx_Stack<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->top();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Stack<T>, push)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Stack<T>, push)
{
	Object_wx_Stack<T> *pThis = Object_wx_Stack<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int val = arg.GetNumber(0)
	//pThis->GetEntity()->push();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Stack<T>, pop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Stack<T>, pop)
{
	Object_wx_Stack<T> *pThis = Object_wx_Stack<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->pop();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxStack<T>
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Stack<T>)
{
	Gura_AssignMethod(wx_Stack<T>, wxStack);
	Gura_AssignMethod(wx_Stack<T>, wxStack_1);
	Gura_AssignMethod(wx_Stack<T>, empty);
	Gura_AssignMethod(wx_Stack<T>, size);
	Gura_AssignMethod(wx_Stack<T>, top);
	Gura_AssignMethod(wx_Stack<T>, top_1);
	Gura_AssignMethod(wx_Stack<T>, push);
	Gura_AssignMethod(wx_Stack<T>, pop);
}

Gura_ImplementDescendantCreator(wx_Stack<T>)
{
	return new Object_wx_Stack<T>((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
