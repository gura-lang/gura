//----------------------------------------------------------------------------
// wxArrayString
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxArrayString
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxArrayString
//----------------------------------------------------------------------------
Object_wx_ArrayString::~Object_wx_ArrayString()
{
}

Object *Object_wx_ArrayString::Clone() const
{
	return nullptr;
}

String Object_wx_ArrayString::ToString(bool exprFlag)
{
	String rtn("<wx.ArrayString:");
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
Gura_DeclareMethodAlias(wx_ArrayString, __int, "int")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "first", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "second", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArrayString, __int)
{
	Object_wx_ArrayString *pThis = Object_wx_ArrayString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int first = arg.GetNumber(0)
	//int second = arg.GetNumber(1)
	//pThis->GetEntity()->int();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ArrayString, __wxArrayString, "wxArrayString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ArrayString, __wxArrayString)
{
	Object_wx_ArrayString *pThis = Object_wx_ArrayString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxArrayString();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ArrayString, __wxArrayString_1, "wxArrayString_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "array", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArrayString, __wxArrayString_1)
{
	Object_wx_ArrayString *pThis = Object_wx_ArrayString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int array = arg.GetNumber(0)
	//pThis->GetEntity()->wxArrayString();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ArrayString, __wxArrayString_2, "wxArrayString_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "arr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArrayString, __wxArrayString_2)
{
	Object_wx_ArrayString *pThis = Object_wx_ArrayString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sz = arg.GetNumber(0)
	//int arr = arg.GetNumber(1)
	//pThis->GetEntity()->wxArrayString();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ArrayString, __wxArrayString_3, "wxArrayString_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "arr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArrayString, __wxArrayString_3)
{
	Object_wx_ArrayString *pThis = Object_wx_ArrayString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sz = arg.GetNumber(0)
	//int arr = arg.GetNumber(1)
	//pThis->GetEntity()->wxArrayString();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ArrayString, __wxArrayString_4, "wxArrayString_4")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "arr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArrayString, __wxArrayString_4)
{
	Object_wx_ArrayString *pThis = Object_wx_ArrayString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sz = arg.GetNumber(0)
	//int arr = arg.GetNumber(1)
	//pThis->GetEntity()->wxArrayString();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ArrayString, __Add, "Add")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "copies", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArrayString, __Add)
{
	Object_wx_ArrayString *pThis = Object_wx_ArrayString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//int copies = arg.GetNumber(1)
	//pThis->GetEntity()->Add();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ArrayString, __Alloc, "Alloc")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nCount", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArrayString, __Alloc)
{
	Object_wx_ArrayString *pThis = Object_wx_ArrayString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int nCount = arg.GetNumber(0)
	//pThis->GetEntity()->Alloc();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ArrayString, __Clear, "Clear")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ArrayString, __Clear)
{
	Object_wx_ArrayString *pThis = Object_wx_ArrayString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ArrayString, __Empty, "Empty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ArrayString, __Empty)
{
	Object_wx_ArrayString *pThis = Object_wx_ArrayString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Empty();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ArrayString, __GetCount, "GetCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ArrayString, __GetCount)
{
	Object_wx_ArrayString *pThis = Object_wx_ArrayString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ArrayString, __Index, "Index")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bCase", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bFromEnd", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArrayString, __Index)
{
	Object_wx_ArrayString *pThis = Object_wx_ArrayString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sz = arg.GetNumber(0)
	//int bCase = arg.GetNumber(1)
	//int bFromEnd = arg.GetNumber(2)
	//pThis->GetEntity()->Index();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ArrayString, __Insert, "Insert")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lItem", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nIndex", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "copies", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArrayString, __Insert)
{
	Object_wx_ArrayString *pThis = Object_wx_ArrayString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int lItem = arg.GetNumber(0)
	//int nIndex = arg.GetNumber(1)
	//int copies = arg.GetNumber(2)
	//pThis->GetEntity()->Insert();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ArrayString, __IsEmpty, "IsEmpty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ArrayString, __IsEmpty)
{
	Object_wx_ArrayString *pThis = Object_wx_ArrayString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsEmpty();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ArrayString, __Item, "Item")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nIndex", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArrayString, __Item)
{
	Object_wx_ArrayString *pThis = Object_wx_ArrayString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int nIndex = arg.GetNumber(0)
	//pThis->GetEntity()->Item();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ArrayString, __Item_1, "Item_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nIndex", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArrayString, __Item_1)
{
	Object_wx_ArrayString *pThis = Object_wx_ArrayString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int nIndex = arg.GetNumber(0)
	//pThis->GetEntity()->Item();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ArrayString, __Last, "Last")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ArrayString, __Last)
{
	Object_wx_ArrayString *pThis = Object_wx_ArrayString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Last();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ArrayString, __Last_1, "Last_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ArrayString, __Last_1)
{
	Object_wx_ArrayString *pThis = Object_wx_ArrayString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Last();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ArrayString, __Remove, "Remove")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArrayString, __Remove)
{
	Object_wx_ArrayString *pThis = Object_wx_ArrayString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sz = arg.GetNumber(0)
	//pThis->GetEntity()->Remove();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ArrayString, __RemoveAt, "RemoveAt")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nIndex", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "count", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArrayString, __RemoveAt)
{
	Object_wx_ArrayString *pThis = Object_wx_ArrayString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int nIndex = arg.GetNumber(0)
	//int count = arg.GetNumber(1)
	//pThis->GetEntity()->RemoveAt();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ArrayString, __Shrink, "Shrink")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ArrayString, __Shrink)
{
	Object_wx_ArrayString *pThis = Object_wx_ArrayString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Shrink();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ArrayString, __Sort, "Sort")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "reverseOrder", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArrayString, __Sort)
{
	Object_wx_ArrayString *pThis = Object_wx_ArrayString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int reverseOrder = arg.GetNumber(0)
	//pThis->GetEntity()->Sort();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ArrayString, __Sort_1, "Sort_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "compareFunction", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArrayString, __Sort_1)
{
	Object_wx_ArrayString *pThis = Object_wx_ArrayString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int compareFunction = arg.GetNumber(0)
	//pThis->GetEntity()->Sort();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxArrayString
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ArrayString)
{
	Gura_AssignMethod(wx_ArrayString, __int);
	Gura_AssignMethod(wx_ArrayString, __wxArrayString);
	Gura_AssignMethod(wx_ArrayString, __wxArrayString_1);
	Gura_AssignMethod(wx_ArrayString, __wxArrayString_2);
	Gura_AssignMethod(wx_ArrayString, __wxArrayString_3);
	Gura_AssignMethod(wx_ArrayString, __wxArrayString_4);
	Gura_AssignMethod(wx_ArrayString, __Add);
	Gura_AssignMethod(wx_ArrayString, __Alloc);
	Gura_AssignMethod(wx_ArrayString, __Clear);
	Gura_AssignMethod(wx_ArrayString, __Empty);
	Gura_AssignMethod(wx_ArrayString, __GetCount);
	Gura_AssignMethod(wx_ArrayString, __Index);
	Gura_AssignMethod(wx_ArrayString, __Insert);
	Gura_AssignMethod(wx_ArrayString, __IsEmpty);
	Gura_AssignMethod(wx_ArrayString, __Item);
	Gura_AssignMethod(wx_ArrayString, __Item_1);
	Gura_AssignMethod(wx_ArrayString, __Last);
	Gura_AssignMethod(wx_ArrayString, __Last_1);
	Gura_AssignMethod(wx_ArrayString, __Remove);
	Gura_AssignMethod(wx_ArrayString, __RemoveAt);
	Gura_AssignMethod(wx_ArrayString, __Shrink);
	Gura_AssignMethod(wx_ArrayString, __Sort);
	Gura_AssignMethod(wx_ArrayString, __Sort_1);
}

Gura_ImplementDescendantCreator(wx_ArrayString)
{
	return new Object_wx_ArrayString((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
