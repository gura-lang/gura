//----------------------------------------------------------------------------
// wxArray<T>
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxArray<T>
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxArray<T>
//----------------------------------------------------------------------------
Object_wx_Array<T>::~Object_wx_Array<T>()
{
}

Object *Object_wx_Array<T>::Clone() const
{
	return nullptr;
}

String Object_wx_Array<T>::ToString(bool exprFlag)
{
	String rtn("<wx.Array<T>:");
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
Gura_DeclareMethod(wx_Array<T>, wxArray)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Array<T>, wxArray)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array<T> *pThis = Object_wx_Array<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxArray();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Array<T>, wxObjArray)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Array<T>, wxObjArray)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array<T> *pThis = Object_wx_Array<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxObjArray();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Array<T>, wxSortedArray)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "first", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Array<T>, wxSortedArray)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array<T> *pThis = Object_wx_Array<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int first = arg.GetNumber(0)
	//pThis->GetEntity()->wxSortedArray();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Array<T>, wxArray_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "array", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Array<T>, wxArray_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array<T> *pThis = Object_wx_Array<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int array = arg.GetNumber(0)
	//pThis->GetEntity()->wxArray();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Array<T>, wxSortedArray_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "array", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Array<T>, wxSortedArray_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array<T> *pThis = Object_wx_Array<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int array = arg.GetNumber(0)
	//pThis->GetEntity()->wxSortedArray();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Array<T>, wxObjArray_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "array", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Array<T>, wxObjArray_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array<T> *pThis = Object_wx_Array<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int array = arg.GetNumber(0)
	//pThis->GetEntity()->wxObjArray();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Array<T>, ~wxArray)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Array<T>, ~wxArray)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array<T> *pThis = Object_wx_Array<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxArray();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Array<T>, ~wxSortedArray)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Array<T>, ~wxSortedArray)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array<T> *pThis = Object_wx_Array<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxSortedArray();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Array<T>, ~wxObjArray)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Array<T>, ~wxObjArray)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array<T> *pThis = Object_wx_Array<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxObjArray();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Array<T>, Alloc)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "count", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Array<T>, Alloc)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array<T> *pThis = Object_wx_Array<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int count = arg.GetNumber(0)
	//pThis->GetEntity()->Alloc();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Array<T>, Shrink)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Array<T>, Shrink)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array<T> *pThis = Object_wx_Array<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Shrink();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Array<T>, GetCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Array<T>, GetCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array<T> *pThis = Object_wx_Array<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Array<T>, IsEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Array<T>, IsEmpty)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array<T> *pThis = Object_wx_Array<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsEmpty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Array<T>, Item)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Array<T>, Item)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array<T> *pThis = Object_wx_Array<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//pThis->GetEntity()->Item();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Array<T>, Last)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Array<T>, Last)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array<T> *pThis = Object_wx_Array<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Last();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Array<T>, Add)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "copies", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Array<T>, Add)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array<T> *pThis = Object_wx_Array<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int copies = arg.GetNumber(1)
	//pThis->GetEntity()->Add();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Array<T>, Add_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Array<T>, Add_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array<T> *pThis = Object_wx_Array<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->Add();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Array<T>, Add_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Array<T>, Add_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array<T> *pThis = Object_wx_Array<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->Add();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Array<T>, Add_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "copies", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Array<T>, Add_3)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array<T> *pThis = Object_wx_Array<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int copies = arg.GetNumber(1)
	//pThis->GetEntity()->Add();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Array<T>, AddAt)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Array<T>, AddAt)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array<T> *pThis = Object_wx_Array<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int index = arg.GetNumber(1)
	//pThis->GetEntity()->AddAt();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Array<T>, Insert)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "copies", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Array<T>, Insert)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array<T> *pThis = Object_wx_Array<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int n = arg.GetNumber(1)
	//int copies = arg.GetNumber(2)
	//pThis->GetEntity()->Insert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Array<T>, Insert_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Array<T>, Insert_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array<T> *pThis = Object_wx_Array<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int n = arg.GetNumber(1)
	//pThis->GetEntity()->Insert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Array<T>, Insert_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "copies", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Array<T>, Insert_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array<T> *pThis = Object_wx_Array<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int n = arg.GetNumber(1)
	//int copies = arg.GetNumber(2)
	//pThis->GetEntity()->Insert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Array<T>, SetCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "count", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defval", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Array<T>, SetCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array<T> *pThis = Object_wx_Array<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int count = arg.GetNumber(0)
	//int defval = arg.GetNumber(1)
	//pThis->GetEntity()->SetCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Array<T>, Clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Array<T>, Clear)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array<T> *pThis = Object_wx_Array<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Array<T>, Detach)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Array<T>, Detach)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array<T> *pThis = Object_wx_Array<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//pThis->GetEntity()->Detach();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Array<T>, Empty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Array<T>, Empty)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array<T> *pThis = Object_wx_Array<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Empty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Array<T>, Remove)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Array<T>, Remove)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array<T> *pThis = Object_wx_Array<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->Remove();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Array<T>, RemoveAt)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "count", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Array<T>, RemoveAt)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array<T> *pThis = Object_wx_Array<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//int count = arg.GetNumber(1)
	//pThis->GetEntity()->RemoveAt();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Array<T>, Index)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "searchFromEnd", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Array<T>, Index)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array<T> *pThis = Object_wx_Array<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int searchFromEnd = arg.GetNumber(1)
	//pThis->GetEntity()->Index();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Array<T>, Index_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Array<T>, Index_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array<T> *pThis = Object_wx_Array<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->Index();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Array<T>, IndexForInsert)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Array<T>, IndexForInsert)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array<T> *pThis = Object_wx_Array<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->IndexForInsert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Array<T>, Sort)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "compareFunction", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Array<T>, Sort)
{
	Signal &sig = env.GetSignal();
	Object_wx_Array<T> *pThis = Object_wx_Array<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int compareFunction = arg.GetNumber(0)
	//pThis->GetEntity()->Sort();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxArray<T>
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Array<T>)
{
	Gura_AssignMethod(wx_Array<T>, wxArray);
	Gura_AssignMethod(wx_Array<T>, wxObjArray);
	Gura_AssignMethod(wx_Array<T>, wxSortedArray);
	Gura_AssignMethod(wx_Array<T>, wxArray_1);
	Gura_AssignMethod(wx_Array<T>, wxSortedArray_1);
	Gura_AssignMethod(wx_Array<T>, wxObjArray_1);
	Gura_AssignMethod(wx_Array<T>, ~wxArray);
	Gura_AssignMethod(wx_Array<T>, ~wxSortedArray);
	Gura_AssignMethod(wx_Array<T>, ~wxObjArray);
	Gura_AssignMethod(wx_Array<T>, Alloc);
	Gura_AssignMethod(wx_Array<T>, Shrink);
	Gura_AssignMethod(wx_Array<T>, GetCount);
	Gura_AssignMethod(wx_Array<T>, IsEmpty);
	Gura_AssignMethod(wx_Array<T>, Item);
	Gura_AssignMethod(wx_Array<T>, Last);
	Gura_AssignMethod(wx_Array<T>, Add);
	Gura_AssignMethod(wx_Array<T>, Add_1);
	Gura_AssignMethod(wx_Array<T>, Add_2);
	Gura_AssignMethod(wx_Array<T>, Add_3);
	Gura_AssignMethod(wx_Array<T>, AddAt);
	Gura_AssignMethod(wx_Array<T>, Insert);
	Gura_AssignMethod(wx_Array<T>, Insert_1);
	Gura_AssignMethod(wx_Array<T>, Insert_2);
	Gura_AssignMethod(wx_Array<T>, SetCount);
	Gura_AssignMethod(wx_Array<T>, Clear);
	Gura_AssignMethod(wx_Array<T>, Detach);
	Gura_AssignMethod(wx_Array<T>, Empty);
	Gura_AssignMethod(wx_Array<T>, Remove);
	Gura_AssignMethod(wx_Array<T>, RemoveAt);
	Gura_AssignMethod(wx_Array<T>, Index);
	Gura_AssignMethod(wx_Array<T>, Index_1);
	Gura_AssignMethod(wx_Array<T>, IndexForInsert);
	Gura_AssignMethod(wx_Array<T>, Sort);
}

Gura_ImplementDescendantCreator(wx_Array<T>)
{
	return new Object_wx_Array<T>((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
