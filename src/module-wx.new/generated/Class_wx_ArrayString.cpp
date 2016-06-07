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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__ArrayString, "ArrayString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_ArrayString));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__ArrayString)
{
	//wxArrayString();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__ArrayString_1, "ArrayString_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "array", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_ArrayString));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__ArrayString_1)
{
	//const wxArrayString& array = arg.GetNumber(0)
	//wxArrayString(array);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__ArrayString_2, "ArrayString_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "arr", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_ArrayString));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__ArrayString_2)
{
	//size_t sz = arg.GetNumber(0)
	//const char** arr = arg.GetNumber(1)
	//wxArrayString(sz, arr);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__ArrayString_3, "ArrayString_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "arr", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_ArrayString));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__ArrayString_3)
{
	//size_t sz = arg.GetNumber(0)
	//const wchar_t** arr = arg.GetNumber(1)
	//wxArrayString(sz, arr);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__ArrayString_4, "ArrayString_4")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "arr", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_ArrayString));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__ArrayString_4)
{
	//size_t sz = arg.GetNumber(0)
	//const wxString* arr = arg.GetNumber(1)
	//wxArrayString(sz, arr);
	return Value::Nil;
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
	//*CompareFunction)(const wxString& first = arg.GetNumber(0)
	//const wxString& second = arg.GetNumber(1)
	//pThis->GetEntity()->int(first, second);
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
	//const wxString& str = arg.GetNumber(0)
	//size_t copies = arg.GetNumber(1)
	//pThis->GetEntity()->Add(str, copies);
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
	//size_t nCount = arg.GetNumber(0)
	//pThis->GetEntity()->Alloc(nCount);
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
	//const wxString& sz = arg.GetNumber(0)
	//bool bCase = arg.GetNumber(1)
	//bool bFromEnd = arg.GetNumber(2)
	//pThis->GetEntity()->Index(sz, bCase, bFromEnd);
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
	//wxString lItem = arg.GetNumber(0)
	//size_t nIndex = arg.GetNumber(1)
	//size_t copies = arg.GetNumber(2)
	//pThis->GetEntity()->Insert(lItem, nIndex, copies);
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
	//size_t nIndex = arg.GetNumber(0)
	//pThis->GetEntity()->Item(nIndex);
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
	//size_t nIndex = arg.GetNumber(0)
	//pThis->GetEntity()->Item(nIndex);
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
	//const wxString& sz = arg.GetNumber(0)
	//pThis->GetEntity()->Remove(sz);
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
	//size_t nIndex = arg.GetNumber(0)
	//size_t count = arg.GetNumber(1)
	//pThis->GetEntity()->RemoveAt(nIndex, count);
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
	//bool reverseOrder = arg.GetNumber(0)
	//pThis->GetEntity()->Sort(reverseOrder);
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
	//CompareFunction compareFunction = arg.GetNumber(0)
	//pThis->GetEntity()->Sort(compareFunction);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxArrayString
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ArrayString)
{
	// Constructor assignment
	Gura_AssignFunction(__ArrayString);
	Gura_AssignFunction(__ArrayString_1);
	Gura_AssignFunction(__ArrayString_2);
	Gura_AssignFunction(__ArrayString_3);
	Gura_AssignFunction(__ArrayString_4);
	// Method assignment
	Gura_AssignMethod(wx_ArrayString, __int);
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
