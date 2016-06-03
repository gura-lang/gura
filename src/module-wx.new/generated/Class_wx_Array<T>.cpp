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
Gura_DeclareMethodAlias(wx_Array<T>, __wxArray, "wxArray")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Array<T>, __wxArray)
{
	Object_wx_Array<T> *pThis = Object_wx_Array<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxArray();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Array<T>, __wxObjArray, "wxObjArray")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Array<T>, __wxObjArray)
{
	Object_wx_Array<T> *pThis = Object_wx_Array<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxObjArray();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Array<T>, __wxArray_1, "wxArray_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "array", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Array<T>, __wxArray_1)
{
	Object_wx_Array<T> *pThis = Object_wx_Array<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int array = arg.GetNumber(0)
	//pThis->GetEntity()->wxArray();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Array<T>, __wxSortedArray, "wxSortedArray")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "array", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Array<T>, __wxSortedArray)
{
	Object_wx_Array<T> *pThis = Object_wx_Array<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int array = arg.GetNumber(0)
	//pThis->GetEntity()->wxSortedArray();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Array<T>, __wxObjArray_1, "wxObjArray_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "array", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Array<T>, __wxObjArray_1)
{
	Object_wx_Array<T> *pThis = Object_wx_Array<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int array = arg.GetNumber(0)
	//pThis->GetEntity()->wxObjArray();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Array<T>, __Alloc, "Alloc")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "count", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Array<T>, __Alloc)
{
	Object_wx_Array<T> *pThis = Object_wx_Array<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int count = arg.GetNumber(0)
	//pThis->GetEntity()->Alloc();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Array<T>, __Shrink, "Shrink")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Array<T>, __Shrink)
{
	Object_wx_Array<T> *pThis = Object_wx_Array<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Shrink();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Array<T>, __GetCount, "GetCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Array<T>, __GetCount)
{
	Object_wx_Array<T> *pThis = Object_wx_Array<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Array<T>, __IsEmpty, "IsEmpty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Array<T>, __IsEmpty)
{
	Object_wx_Array<T> *pThis = Object_wx_Array<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsEmpty();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Array<T>, __Item, "Item")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Array<T>, __Item)
{
	Object_wx_Array<T> *pThis = Object_wx_Array<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//pThis->GetEntity()->Item();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Array<T>, __Last, "Last")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Array<T>, __Last)
{
	Object_wx_Array<T> *pThis = Object_wx_Array<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Last();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Array<T>, __Add, "Add")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "copies", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Array<T>, __Add)
{
	Object_wx_Array<T> *pThis = Object_wx_Array<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int copies = arg.GetNumber(1)
	//pThis->GetEntity()->Add();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Array<T>, __Add_1, "Add_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Array<T>, __Add_1)
{
	Object_wx_Array<T> *pThis = Object_wx_Array<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->Add();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Array<T>, __Add_2, "Add_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Array<T>, __Add_2)
{
	Object_wx_Array<T> *pThis = Object_wx_Array<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->Add();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Array<T>, __Add_3, "Add_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "copies", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Array<T>, __Add_3)
{
	Object_wx_Array<T> *pThis = Object_wx_Array<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int copies = arg.GetNumber(1)
	//pThis->GetEntity()->Add();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Array<T>, __AddAt, "AddAt")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Array<T>, __AddAt)
{
	Object_wx_Array<T> *pThis = Object_wx_Array<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int index = arg.GetNumber(1)
	//pThis->GetEntity()->AddAt();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Array<T>, __Insert, "Insert")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "copies", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Array<T>, __Insert)
{
	Object_wx_Array<T> *pThis = Object_wx_Array<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int n = arg.GetNumber(1)
	//int copies = arg.GetNumber(2)
	//pThis->GetEntity()->Insert();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Array<T>, __Insert_1, "Insert_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Array<T>, __Insert_1)
{
	Object_wx_Array<T> *pThis = Object_wx_Array<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int n = arg.GetNumber(1)
	//pThis->GetEntity()->Insert();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Array<T>, __Insert_2, "Insert_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "copies", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Array<T>, __Insert_2)
{
	Object_wx_Array<T> *pThis = Object_wx_Array<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int n = arg.GetNumber(1)
	//int copies = arg.GetNumber(2)
	//pThis->GetEntity()->Insert();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Array<T>, __SetCount, "SetCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "count", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defval", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Array<T>, __SetCount)
{
	Object_wx_Array<T> *pThis = Object_wx_Array<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int count = arg.GetNumber(0)
	//int defval = arg.GetNumber(1)
	//pThis->GetEntity()->SetCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Array<T>, __Clear, "Clear")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Array<T>, __Clear)
{
	Object_wx_Array<T> *pThis = Object_wx_Array<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Array<T>, __Detach, "Detach")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Array<T>, __Detach)
{
	Object_wx_Array<T> *pThis = Object_wx_Array<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//pThis->GetEntity()->Detach();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Array<T>, __Empty, "Empty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Array<T>, __Empty)
{
	Object_wx_Array<T> *pThis = Object_wx_Array<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Empty();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Array<T>, __Remove, "Remove")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Array<T>, __Remove)
{
	Object_wx_Array<T> *pThis = Object_wx_Array<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->Remove();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Array<T>, __RemoveAt, "RemoveAt")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "count", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Array<T>, __RemoveAt)
{
	Object_wx_Array<T> *pThis = Object_wx_Array<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//int count = arg.GetNumber(1)
	//pThis->GetEntity()->RemoveAt();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Array<T>, __Index, "Index")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "searchFromEnd", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Array<T>, __Index)
{
	Object_wx_Array<T> *pThis = Object_wx_Array<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int searchFromEnd = arg.GetNumber(1)
	//pThis->GetEntity()->Index();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Array<T>, __Index_1, "Index_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Array<T>, __Index_1)
{
	Object_wx_Array<T> *pThis = Object_wx_Array<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->Index();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Array<T>, __IndexForInsert, "IndexForInsert")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Array<T>, __IndexForInsert)
{
	Object_wx_Array<T> *pThis = Object_wx_Array<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->IndexForInsert();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Array<T>, __Sort, "Sort")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "compareFunction", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Array<T>, __Sort)
{
	Object_wx_Array<T> *pThis = Object_wx_Array<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int compareFunction = arg.GetNumber(0)
	//pThis->GetEntity()->Sort();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxArray<T>
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Array<T>)
{
	// Class assignment
	Gura_AssignValueEx("Array<T>", Reference());
	// Method assignment
	Gura_AssignMethod(wx_Array<T>, __wxArray);
	Gura_AssignMethod(wx_Array<T>, __wxObjArray);
	Gura_AssignMethod(wx_Array<T>, __wxArray_1);
	Gura_AssignMethod(wx_Array<T>, __wxSortedArray);
	Gura_AssignMethod(wx_Array<T>, __wxObjArray_1);
	Gura_AssignMethod(wx_Array<T>, __Alloc);
	Gura_AssignMethod(wx_Array<T>, __Shrink);
	Gura_AssignMethod(wx_Array<T>, __GetCount);
	Gura_AssignMethod(wx_Array<T>, __IsEmpty);
	Gura_AssignMethod(wx_Array<T>, __Item);
	Gura_AssignMethod(wx_Array<T>, __Last);
	Gura_AssignMethod(wx_Array<T>, __Add);
	Gura_AssignMethod(wx_Array<T>, __Add_1);
	Gura_AssignMethod(wx_Array<T>, __Add_2);
	Gura_AssignMethod(wx_Array<T>, __Add_3);
	Gura_AssignMethod(wx_Array<T>, __AddAt);
	Gura_AssignMethod(wx_Array<T>, __Insert);
	Gura_AssignMethod(wx_Array<T>, __Insert_1);
	Gura_AssignMethod(wx_Array<T>, __Insert_2);
	Gura_AssignMethod(wx_Array<T>, __SetCount);
	Gura_AssignMethod(wx_Array<T>, __Clear);
	Gura_AssignMethod(wx_Array<T>, __Detach);
	Gura_AssignMethod(wx_Array<T>, __Empty);
	Gura_AssignMethod(wx_Array<T>, __Remove);
	Gura_AssignMethod(wx_Array<T>, __RemoveAt);
	Gura_AssignMethod(wx_Array<T>, __Index);
	Gura_AssignMethod(wx_Array<T>, __Index_1);
	Gura_AssignMethod(wx_Array<T>, __IndexForInsert);
	Gura_AssignMethod(wx_Array<T>, __Sort);
}

Gura_ImplementDescendantCreator(wx_Array<T>)
{
	return new Object_wx_Array<T>((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
