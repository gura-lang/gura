//----------------------------------------------------------------------------
// wxNode<T>
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxNode<T>
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxNode<T>
//----------------------------------------------------------------------------
Object_wx_Node<T>::~Object_wx_Node<T>()
{
}

Object *Object_wx_Node<T>::Clone() const
{
	return nullptr;
}

String Object_wx_Node<T>::ToString(bool exprFlag)
{
	String rtn("<wx.Node<T>:");
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
Gura_DeclareMethod(wx_Node<T>, GetData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Node<T>, GetData)
{
	Signal &sig = env.GetSignal();
	Object_wx_Node<T> *pThis = Object_wx_Node<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Node<T>, GetNext)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Node<T>, GetNext)
{
	Signal &sig = env.GetSignal();
	Object_wx_Node<T> *pThis = Object_wx_Node<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetNext();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Node<T>, GetPrevious)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Node<T>, GetPrevious)
{
	Signal &sig = env.GetSignal();
	Object_wx_Node<T> *pThis = Object_wx_Node<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPrevious();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Node<T>, IndexOf)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Node<T>, IndexOf)
{
	Signal &sig = env.GetSignal();
	Object_wx_Node<T> *pThis = Object_wx_Node<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IndexOf();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Node<T>, SetData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Node<T>, SetData)
{
	Signal &sig = env.GetSignal();
	Object_wx_Node<T> *pThis = Object_wx_Node<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->SetData();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxNode<T>
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Node<T>)
{
	Gura_AssignMethod(wx_Node<T>, GetData);
	Gura_AssignMethod(wx_Node<T>, GetNext);
	Gura_AssignMethod(wx_Node<T>, GetPrevious);
	Gura_AssignMethod(wx_Node<T>, IndexOf);
	Gura_AssignMethod(wx_Node<T>, SetData);
}

Gura_ImplementDescendantCreator(wx_Node<T>)
{
	return new Object_wx_Node<T>((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
