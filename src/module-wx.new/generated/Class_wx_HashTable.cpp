//----------------------------------------------------------------------------
// wxHashTable
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHashTable
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHashTable
//----------------------------------------------------------------------------
Object_wx_HashTable::~Object_wx_HashTable()
{
}

Object *Object_wx_HashTable::Clone() const
{
	return nullptr;
}

String Object_wx_HashTable::ToString(bool exprFlag)
{
	String rtn("<wx.HashTable:");
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
Gura_DeclareMethod(wx_HashTable, wxHashTable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "key_type", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HashTable, wxHashTable)
{
	Object_wx_HashTable *pThis = Object_wx_HashTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int key_type = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//pThis->GetEntity()->wxHashTable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HashTable, BeginFind)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HashTable, BeginFind)
{
	Object_wx_HashTable *pThis = Object_wx_HashTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->BeginFind();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HashTable, Clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HashTable, Clear)
{
	Object_wx_HashTable *pThis = Object_wx_HashTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HashTable, Delete)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "key", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HashTable, Delete)
{
	Object_wx_HashTable *pThis = Object_wx_HashTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int key = arg.GetNumber(0)
	//pThis->GetEntity()->Delete();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HashTable, Delete_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "key", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HashTable, Delete_1)
{
	Object_wx_HashTable *pThis = Object_wx_HashTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int key = arg.GetNumber(0)
	//pThis->GetEntity()->Delete();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HashTable, DeleteContents)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HashTable, DeleteContents)
{
	Object_wx_HashTable *pThis = Object_wx_HashTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteContents();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HashTable, Get)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "key", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HashTable, Get)
{
	Object_wx_HashTable *pThis = Object_wx_HashTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int key = arg.GetNumber(0)
	//pThis->GetEntity()->Get();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HashTable, Get_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "key", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HashTable, Get_1)
{
	Object_wx_HashTable *pThis = Object_wx_HashTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int key = arg.GetNumber(0)
	//pThis->GetEntity()->Get();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HashTable, GetCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HashTable, GetCount)
{
	Object_wx_HashTable *pThis = Object_wx_HashTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HashTable, MakeKey)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "string", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HashTable, MakeKey)
{
	Object_wx_HashTable *pThis = Object_wx_HashTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int string = arg.GetNumber(0)
	//pThis->GetEntity()->MakeKey();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HashTable, Next)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HashTable, Next)
{
	Object_wx_HashTable *pThis = Object_wx_HashTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Next();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HashTable, Put)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "key", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "object", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HashTable, Put)
{
	Object_wx_HashTable *pThis = Object_wx_HashTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int key = arg.GetNumber(0)
	//int object = arg.GetNumber(1)
	//pThis->GetEntity()->Put();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HashTable, Put_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "key", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "object", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HashTable, Put_1)
{
	Object_wx_HashTable *pThis = Object_wx_HashTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int key = arg.GetNumber(0)
	//int object = arg.GetNumber(1)
	//pThis->GetEntity()->Put();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHashTable
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HashTable)
{
	Gura_AssignMethod(wx_HashTable, wxHashTable);
	Gura_AssignMethod(wx_HashTable, BeginFind);
	Gura_AssignMethod(wx_HashTable, Clear);
	Gura_AssignMethod(wx_HashTable, Delete);
	Gura_AssignMethod(wx_HashTable, Delete_1);
	Gura_AssignMethod(wx_HashTable, DeleteContents);
	Gura_AssignMethod(wx_HashTable, Get);
	Gura_AssignMethod(wx_HashTable, Get_1);
	Gura_AssignMethod(wx_HashTable, GetCount);
	Gura_AssignMethod(wx_HashTable, MakeKey);
	Gura_AssignMethod(wx_HashTable, Next);
	Gura_AssignMethod(wx_HashTable, Put);
	Gura_AssignMethod(wx_HashTable, Put_1);
}

Gura_ImplementDescendantCreator(wx_HashTable)
{
	return new Object_wx_HashTable((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
