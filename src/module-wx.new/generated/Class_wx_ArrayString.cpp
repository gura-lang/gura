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
Gura_DeclareMethod(wx_ArrayString, int)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "first", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "second", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArrayString, int)
{
	Object_wx_ArrayString *pThis = Object_wx_ArrayString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int first = arg.GetNumber(0)
	//int second = arg.GetNumber(1)
	//pThis->GetEntity()->int();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArrayString, wxArrayString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ArrayString, wxArrayString)
{
	Object_wx_ArrayString *pThis = Object_wx_ArrayString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxArrayString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArrayString, wxArrayString_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "array", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArrayString, wxArrayString_1)
{
	Object_wx_ArrayString *pThis = Object_wx_ArrayString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int array = arg.GetNumber(0)
	//pThis->GetEntity()->wxArrayString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArrayString, wxArrayString_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "arr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArrayString, wxArrayString_2)
{
	Object_wx_ArrayString *pThis = Object_wx_ArrayString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sz = arg.GetNumber(0)
	//int arr = arg.GetNumber(1)
	//pThis->GetEntity()->wxArrayString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArrayString, wxArrayString_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "arr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArrayString, wxArrayString_3)
{
	Object_wx_ArrayString *pThis = Object_wx_ArrayString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sz = arg.GetNumber(0)
	//int arr = arg.GetNumber(1)
	//pThis->GetEntity()->wxArrayString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArrayString, wxArrayString_4)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "arr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArrayString, wxArrayString_4)
{
	Object_wx_ArrayString *pThis = Object_wx_ArrayString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sz = arg.GetNumber(0)
	//int arr = arg.GetNumber(1)
	//pThis->GetEntity()->wxArrayString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArrayString, Add)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "copies", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArrayString, Add)
{
	Object_wx_ArrayString *pThis = Object_wx_ArrayString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//int copies = arg.GetNumber(1)
	//pThis->GetEntity()->Add();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArrayString, Alloc)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nCount", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArrayString, Alloc)
{
	Object_wx_ArrayString *pThis = Object_wx_ArrayString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int nCount = arg.GetNumber(0)
	//pThis->GetEntity()->Alloc();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArrayString, Clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ArrayString, Clear)
{
	Object_wx_ArrayString *pThis = Object_wx_ArrayString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArrayString, Empty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ArrayString, Empty)
{
	Object_wx_ArrayString *pThis = Object_wx_ArrayString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Empty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArrayString, GetCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ArrayString, GetCount)
{
	Object_wx_ArrayString *pThis = Object_wx_ArrayString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArrayString, Index)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bCase", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bFromEnd", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArrayString, Index)
{
	Object_wx_ArrayString *pThis = Object_wx_ArrayString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sz = arg.GetNumber(0)
	//int bCase = arg.GetNumber(1)
	//int bFromEnd = arg.GetNumber(2)
	//pThis->GetEntity()->Index();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArrayString, Insert)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lItem", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nIndex", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "copies", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArrayString, Insert)
{
	Object_wx_ArrayString *pThis = Object_wx_ArrayString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int lItem = arg.GetNumber(0)
	//int nIndex = arg.GetNumber(1)
	//int copies = arg.GetNumber(2)
	//pThis->GetEntity()->Insert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArrayString, IsEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ArrayString, IsEmpty)
{
	Object_wx_ArrayString *pThis = Object_wx_ArrayString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsEmpty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArrayString, Item)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nIndex", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArrayString, Item)
{
	Object_wx_ArrayString *pThis = Object_wx_ArrayString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int nIndex = arg.GetNumber(0)
	//pThis->GetEntity()->Item();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArrayString, Item_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nIndex", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArrayString, Item_1)
{
	Object_wx_ArrayString *pThis = Object_wx_ArrayString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int nIndex = arg.GetNumber(0)
	//pThis->GetEntity()->Item();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArrayString, Last)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ArrayString, Last)
{
	Object_wx_ArrayString *pThis = Object_wx_ArrayString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Last();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArrayString, Last_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ArrayString, Last_1)
{
	Object_wx_ArrayString *pThis = Object_wx_ArrayString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Last();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArrayString, Remove)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArrayString, Remove)
{
	Object_wx_ArrayString *pThis = Object_wx_ArrayString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sz = arg.GetNumber(0)
	//pThis->GetEntity()->Remove();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArrayString, RemoveAt)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nIndex", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "count", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArrayString, RemoveAt)
{
	Object_wx_ArrayString *pThis = Object_wx_ArrayString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int nIndex = arg.GetNumber(0)
	//int count = arg.GetNumber(1)
	//pThis->GetEntity()->RemoveAt();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArrayString, Shrink)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ArrayString, Shrink)
{
	Object_wx_ArrayString *pThis = Object_wx_ArrayString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Shrink();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArrayString, Sort)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "reverseOrder", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArrayString, Sort)
{
	Object_wx_ArrayString *pThis = Object_wx_ArrayString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int reverseOrder = arg.GetNumber(0)
	//pThis->GetEntity()->Sort();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArrayString, Sort_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "compareFunction", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArrayString, Sort_1)
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
	Gura_AssignMethod(wx_ArrayString, int);
	Gura_AssignMethod(wx_ArrayString, wxArrayString);
	Gura_AssignMethod(wx_ArrayString, wxArrayString_1);
	Gura_AssignMethod(wx_ArrayString, wxArrayString_2);
	Gura_AssignMethod(wx_ArrayString, wxArrayString_3);
	Gura_AssignMethod(wx_ArrayString, wxArrayString_4);
	Gura_AssignMethod(wx_ArrayString, Add);
	Gura_AssignMethod(wx_ArrayString, Alloc);
	Gura_AssignMethod(wx_ArrayString, Clear);
	Gura_AssignMethod(wx_ArrayString, Empty);
	Gura_AssignMethod(wx_ArrayString, GetCount);
	Gura_AssignMethod(wx_ArrayString, Index);
	Gura_AssignMethod(wx_ArrayString, Insert);
	Gura_AssignMethod(wx_ArrayString, IsEmpty);
	Gura_AssignMethod(wx_ArrayString, Item);
	Gura_AssignMethod(wx_ArrayString, Item_1);
	Gura_AssignMethod(wx_ArrayString, Last);
	Gura_AssignMethod(wx_ArrayString, Last_1);
	Gura_AssignMethod(wx_ArrayString, Remove);
	Gura_AssignMethod(wx_ArrayString, RemoveAt);
	Gura_AssignMethod(wx_ArrayString, Shrink);
	Gura_AssignMethod(wx_ArrayString, Sort);
	Gura_AssignMethod(wx_ArrayString, Sort_1);
}

Gura_ImplementDescendantCreator(wx_ArrayString)
{
	return new Object_wx_ArrayString((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
