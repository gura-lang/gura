//----------------------------------------------------------------------------
// wxVector<T>
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxVector<T>
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxVector<T>
//----------------------------------------------------------------------------
Object_wx_Vector<T>::~Object_wx_Vector<T>()
{
}

Object *Object_wx_Vector<T>::Clone() const
{
	return nullptr;
}

String Object_wx_Vector<T>::ToString(bool exprFlag)
{
	String rtn("<wx.Vector<T>:");
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
Gura_DeclareMethodAlias(wx_Vector<T>, __wxVector, "wxVector")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Vector<T>, __wxVector)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxVector();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Vector<T>, __wxVector_1, "wxVector_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Vector<T>, __wxVector_1)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->wxVector();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Vector<T>, __wxVector_2, "wxVector_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Vector<T>, __wxVector_2)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//int value = arg.GetNumber(1)
	//pThis->GetEntity()->wxVector();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Vector<T>, __wxVector_3, "wxVector_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "first", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "last", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Vector<T>, __wxVector_3)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int first = arg.GetNumber(0)
	//int last = arg.GetNumber(1)
	//pThis->GetEntity()->wxVector();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Vector<T>, __wxVector_4, "wxVector_4")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Vector<T>, __wxVector_4)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int c = arg.GetNumber(0)
	//pThis->GetEntity()->wxVector();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Vector<T>, __assign, "assign")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "v", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Vector<T>, __assign)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//int v = arg.GetNumber(1)
	//pThis->GetEntity()->assign();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Vector<T>, __assign_1, "assign_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "first", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "last", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Vector<T>, __assign_1)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int first = arg.GetNumber(0)
	//int last = arg.GetNumber(1)
	//pThis->GetEntity()->assign();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Vector<T>, __at, "at")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Vector<T>, __at)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int idx = arg.GetNumber(0)
	//pThis->GetEntity()->at();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Vector<T>, __at_1, "at_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Vector<T>, __at_1)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int idx = arg.GetNumber(0)
	//pThis->GetEntity()->at();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Vector<T>, __back, "back")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Vector<T>, __back)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->back();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Vector<T>, __back_1, "back_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Vector<T>, __back_1)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->back();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Vector<T>, __begin, "begin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Vector<T>, __begin)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->begin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Vector<T>, __begin_1, "begin_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Vector<T>, __begin_1)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->begin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Vector<T>, __rbegin, "rbegin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Vector<T>, __rbegin)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->rbegin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Vector<T>, __rend, "rend")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Vector<T>, __rend)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->rend();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Vector<T>, __capacity, "capacity")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Vector<T>, __capacity)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->capacity();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Vector<T>, __clear, "clear")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Vector<T>, __clear)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->clear();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Vector<T>, __empty, "empty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Vector<T>, __empty)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->empty();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Vector<T>, __end, "end")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Vector<T>, __end)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->end();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Vector<T>, __end_1, "end_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Vector<T>, __end_1)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->end();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Vector<T>, __erase, "erase")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "it", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Vector<T>, __erase)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int it = arg.GetNumber(0)
	//pThis->GetEntity()->erase();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Vector<T>, __erase_1, "erase_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "first", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "last", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Vector<T>, __erase_1)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int first = arg.GetNumber(0)
	//int last = arg.GetNumber(1)
	//pThis->GetEntity()->erase();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Vector<T>, __front, "front")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Vector<T>, __front)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->front();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Vector<T>, __front_1, "front_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Vector<T>, __front_1)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->front();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Vector<T>, __insert, "insert")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "it", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "v", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Vector<T>, __insert)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int it = arg.GetNumber(0)
	//int v = arg.GetNumber(1)
	//pThis->GetEntity()->insert();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Vector<T>, __pop_back, "pop_back")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Vector<T>, __pop_back)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->pop_back();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Vector<T>, __push_back, "push_back")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "v", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Vector<T>, __push_back)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int v = arg.GetNumber(0)
	//pThis->GetEntity()->push_back();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Vector<T>, __reserve, "reserve")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Vector<T>, __reserve)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->reserve();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Vector<T>, __resize, "resize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Vector<T>, __resize)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->resize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Vector<T>, __resize_1, "resize_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "v", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Vector<T>, __resize_1)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//int v = arg.GetNumber(1)
	//pThis->GetEntity()->resize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Vector<T>, __size, "size")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Vector<T>, __size)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->size();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Vector<T>, __swap, "swap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "v", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Vector<T>, __swap)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int v = arg.GetNumber(0)
	//pThis->GetEntity()->swap();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxVector<T>
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Vector<T>)
{
	// Class assignment
	Gura_AssignValueEx("Vector<T>", Reference());
	// Method assignment
	Gura_AssignMethod(wx_Vector<T>, __wxVector);
	Gura_AssignMethod(wx_Vector<T>, __wxVector_1);
	Gura_AssignMethod(wx_Vector<T>, __wxVector_2);
	Gura_AssignMethod(wx_Vector<T>, __wxVector_3);
	Gura_AssignMethod(wx_Vector<T>, __wxVector_4);
	Gura_AssignMethod(wx_Vector<T>, __assign);
	Gura_AssignMethod(wx_Vector<T>, __assign_1);
	Gura_AssignMethod(wx_Vector<T>, __at);
	Gura_AssignMethod(wx_Vector<T>, __at_1);
	Gura_AssignMethod(wx_Vector<T>, __back);
	Gura_AssignMethod(wx_Vector<T>, __back_1);
	Gura_AssignMethod(wx_Vector<T>, __begin);
	Gura_AssignMethod(wx_Vector<T>, __begin_1);
	Gura_AssignMethod(wx_Vector<T>, __rbegin);
	Gura_AssignMethod(wx_Vector<T>, __rend);
	Gura_AssignMethod(wx_Vector<T>, __capacity);
	Gura_AssignMethod(wx_Vector<T>, __clear);
	Gura_AssignMethod(wx_Vector<T>, __empty);
	Gura_AssignMethod(wx_Vector<T>, __end);
	Gura_AssignMethod(wx_Vector<T>, __end_1);
	Gura_AssignMethod(wx_Vector<T>, __erase);
	Gura_AssignMethod(wx_Vector<T>, __erase_1);
	Gura_AssignMethod(wx_Vector<T>, __front);
	Gura_AssignMethod(wx_Vector<T>, __front_1);
	Gura_AssignMethod(wx_Vector<T>, __insert);
	Gura_AssignMethod(wx_Vector<T>, __pop_back);
	Gura_AssignMethod(wx_Vector<T>, __push_back);
	Gura_AssignMethod(wx_Vector<T>, __reserve);
	Gura_AssignMethod(wx_Vector<T>, __resize);
	Gura_AssignMethod(wx_Vector<T>, __resize_1);
	Gura_AssignMethod(wx_Vector<T>, __size);
	Gura_AssignMethod(wx_Vector<T>, __swap);
}

Gura_ImplementDescendantCreator(wx_Vector<T>)
{
	return new Object_wx_Vector<T>((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
