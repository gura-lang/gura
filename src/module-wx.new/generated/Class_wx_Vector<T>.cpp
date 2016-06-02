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
Gura_DeclareMethod(wx_Vector<T>, wxVector)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Vector<T>, wxVector)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxVector();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Vector<T>, wxVector_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Vector<T>, wxVector_1)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->wxVector();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Vector<T>, wxVector_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Vector<T>, wxVector_2)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//int value = arg.GetNumber(1)
	//pThis->GetEntity()->wxVector();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Vector<T>, wxVector_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "first", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "last", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Vector<T>, wxVector_3)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int first = arg.GetNumber(0)
	//int last = arg.GetNumber(1)
	//pThis->GetEntity()->wxVector();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Vector<T>, wxVector_4)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Vector<T>, wxVector_4)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int c = arg.GetNumber(0)
	//pThis->GetEntity()->wxVector();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Vector<T>, assign)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "v", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Vector<T>, assign)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//int v = arg.GetNumber(1)
	//pThis->GetEntity()->assign();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Vector<T>, assign_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "first", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "last", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Vector<T>, assign_1)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int first = arg.GetNumber(0)
	//int last = arg.GetNumber(1)
	//pThis->GetEntity()->assign();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Vector<T>, at)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Vector<T>, at)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int idx = arg.GetNumber(0)
	//pThis->GetEntity()->at();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Vector<T>, at_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Vector<T>, at_1)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int idx = arg.GetNumber(0)
	//pThis->GetEntity()->at();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Vector<T>, back)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Vector<T>, back)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->back();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Vector<T>, back_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Vector<T>, back_1)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->back();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Vector<T>, begin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Vector<T>, begin)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->begin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Vector<T>, begin_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Vector<T>, begin_1)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->begin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Vector<T>, rbegin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Vector<T>, rbegin)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->rbegin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Vector<T>, rend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Vector<T>, rend)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->rend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Vector<T>, capacity)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Vector<T>, capacity)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->capacity();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Vector<T>, clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Vector<T>, clear)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->clear();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Vector<T>, empty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Vector<T>, empty)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->empty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Vector<T>, end)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Vector<T>, end)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->end();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Vector<T>, end_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Vector<T>, end_1)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->end();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Vector<T>, erase)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "it", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Vector<T>, erase)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int it = arg.GetNumber(0)
	//pThis->GetEntity()->erase();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Vector<T>, erase_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "first", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "last", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Vector<T>, erase_1)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int first = arg.GetNumber(0)
	//int last = arg.GetNumber(1)
	//pThis->GetEntity()->erase();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Vector<T>, front)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Vector<T>, front)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->front();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Vector<T>, front_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Vector<T>, front_1)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->front();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Vector<T>, insert)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "it", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "v", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Vector<T>, insert)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int it = arg.GetNumber(0)
	//int v = arg.GetNumber(1)
	//pThis->GetEntity()->insert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Vector<T>, pop_back)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Vector<T>, pop_back)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->pop_back();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Vector<T>, push_back)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "v", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Vector<T>, push_back)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int v = arg.GetNumber(0)
	//pThis->GetEntity()->push_back();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Vector<T>, reserve)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Vector<T>, reserve)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->reserve();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Vector<T>, resize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Vector<T>, resize)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->resize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Vector<T>, resize_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "v", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Vector<T>, resize_1)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//int v = arg.GetNumber(1)
	//pThis->GetEntity()->resize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Vector<T>, size)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Vector<T>, size)
{
	Object_wx_Vector<T> *pThis = Object_wx_Vector<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->size();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Vector<T>, swap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "v", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Vector<T>, swap)
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
	Gura_AssignMethod(wx_Vector<T>, wxVector);
	Gura_AssignMethod(wx_Vector<T>, wxVector_1);
	Gura_AssignMethod(wx_Vector<T>, wxVector_2);
	Gura_AssignMethod(wx_Vector<T>, wxVector_3);
	Gura_AssignMethod(wx_Vector<T>, wxVector_4);
	Gura_AssignMethod(wx_Vector<T>, assign);
	Gura_AssignMethod(wx_Vector<T>, assign_1);
	Gura_AssignMethod(wx_Vector<T>, at);
	Gura_AssignMethod(wx_Vector<T>, at_1);
	Gura_AssignMethod(wx_Vector<T>, back);
	Gura_AssignMethod(wx_Vector<T>, back_1);
	Gura_AssignMethod(wx_Vector<T>, begin);
	Gura_AssignMethod(wx_Vector<T>, begin_1);
	Gura_AssignMethod(wx_Vector<T>, rbegin);
	Gura_AssignMethod(wx_Vector<T>, rend);
	Gura_AssignMethod(wx_Vector<T>, capacity);
	Gura_AssignMethod(wx_Vector<T>, clear);
	Gura_AssignMethod(wx_Vector<T>, empty);
	Gura_AssignMethod(wx_Vector<T>, end);
	Gura_AssignMethod(wx_Vector<T>, end_1);
	Gura_AssignMethod(wx_Vector<T>, erase);
	Gura_AssignMethod(wx_Vector<T>, erase_1);
	Gura_AssignMethod(wx_Vector<T>, front);
	Gura_AssignMethod(wx_Vector<T>, front_1);
	Gura_AssignMethod(wx_Vector<T>, insert);
	Gura_AssignMethod(wx_Vector<T>, pop_back);
	Gura_AssignMethod(wx_Vector<T>, push_back);
	Gura_AssignMethod(wx_Vector<T>, reserve);
	Gura_AssignMethod(wx_Vector<T>, resize);
	Gura_AssignMethod(wx_Vector<T>, resize_1);
	Gura_AssignMethod(wx_Vector<T>, size);
	Gura_AssignMethod(wx_Vector<T>, swap);
}

Gura_ImplementDescendantCreator(wx_Vector<T>)
{
	return new Object_wx_Vector<T>((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
