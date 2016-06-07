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
Gura_DeclareMethodAlias(wx_Stack<T>, __wxStack, "wxStack")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Stack<T>, __wxStack)
{
	Object_wx_Stack<T> *pThis = Object_wx_Stack<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxStack();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Stack<T>, __wxStack_1, "wxStack_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "cont", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Stack<T>, __wxStack_1)
{
	Object_wx_Stack<T> *pThis = Object_wx_Stack<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const container_type& cont = arg.GetNumber(0)
	//explicit _rtn = pThis->GetEntity()->wxStack(cont);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Stack<T>, __empty, "empty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Stack<T>, __empty)
{
	Object_wx_Stack<T> *pThis = Object_wx_Stack<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->empty();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Stack<T>, __size, "size")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Stack<T>, __size)
{
	Object_wx_Stack<T> *pThis = Object_wx_Stack<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_type _rtn = pThis->GetEntity()->size();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Stack<T>, __top, "top")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Stack<T>, __top)
{
	Object_wx_Stack<T> *pThis = Object_wx_Stack<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//value_type& _rtn = pThis->GetEntity()->top();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Stack<T>, __top_1, "top_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Stack<T>, __top_1)
{
	Object_wx_Stack<T> *pThis = Object_wx_Stack<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const value_type& _rtn = pThis->GetEntity()->top();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Stack<T>, __push, "push")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Stack<T>, __push)
{
	Object_wx_Stack<T> *pThis = Object_wx_Stack<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const value_type& val = arg.GetNumber(0)
	//pThis->GetEntity()->push(val);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Stack<T>, __pop, "pop")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Stack<T>, __pop)
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
	// Class assignment
	Gura_AssignValueEx("Stack<T>", Reference());
	// Method assignment
	Gura_AssignMethod(wx_Stack<T>, __wxStack);
	Gura_AssignMethod(wx_Stack<T>, __wxStack_1);
	Gura_AssignMethod(wx_Stack<T>, __empty);
	Gura_AssignMethod(wx_Stack<T>, __size);
	Gura_AssignMethod(wx_Stack<T>, __top);
	Gura_AssignMethod(wx_Stack<T>, __top_1);
	Gura_AssignMethod(wx_Stack<T>, __push);
	Gura_AssignMethod(wx_Stack<T>, __pop);
}

Gura_ImplementDescendantCreator(wx_Stack<T>)
{
	return new Object_wx_Stack<T>((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
