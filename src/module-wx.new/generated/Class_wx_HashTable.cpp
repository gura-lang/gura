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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__HashTable, "HashTable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "key_type", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_HashTable));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__HashTable)
{
	//wxKeyType key_type = arg.GetNumber(0)
	//size_t size = arg.GetNumber(1)
	//wxHashTable(key_type, size);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_HashTable, __BeginFind, "BeginFind")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HashTable, __BeginFind)
{
	Object_wx_HashTable *pThis = Object_wx_HashTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->BeginFind();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HashTable, __Clear, "Clear")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HashTable, __Clear)
{
	Object_wx_HashTable *pThis = Object_wx_HashTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HashTable, __Delete, "Delete")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "key", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HashTable, __Delete)
{
	Object_wx_HashTable *pThis = Object_wx_HashTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long key = arg.GetNumber(0)
	//wxObject* _rtn = pThis->GetEntity()->Delete(key);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HashTable, __Delete_1, "Delete_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "key", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HashTable, __Delete_1)
{
	Object_wx_HashTable *pThis = Object_wx_HashTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& key = arg.GetNumber(0)
	//wxObject* _rtn = pThis->GetEntity()->Delete(key);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HashTable, __DeleteContents, "DeleteContents")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HashTable, __DeleteContents)
{
	Object_wx_HashTable *pThis = Object_wx_HashTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool flag = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteContents(flag);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HashTable, __Get, "Get")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "key", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HashTable, __Get)
{
	Object_wx_HashTable *pThis = Object_wx_HashTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long key = arg.GetNumber(0)
	//wxObject* _rtn = pThis->GetEntity()->Get(key);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HashTable, __Get_1, "Get_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "key", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HashTable, __Get_1)
{
	Object_wx_HashTable *pThis = Object_wx_HashTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const char* key = arg.GetNumber(0)
	//wxObject* _rtn = pThis->GetEntity()->Get(key);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HashTable, __GetCount, "GetCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_HashTable, __GetCount)
{
	Object_wx_HashTable *pThis = Object_wx_HashTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t _rtn = pThis->GetEntity()->GetCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HashTable, __MakeKey, "MakeKey")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "string", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HashTable, __MakeKey)
{
	Object_wx_HashTable *pThis = Object_wx_HashTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& string = arg.GetNumber(0)
	//long _rtn = pThis->GetEntity()->MakeKey(string);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HashTable, __Next, "Next")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_HashTable, __Next)
{
	Object_wx_HashTable *pThis = Object_wx_HashTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxHashTable::Node* _rtn = pThis->GetEntity()->Next();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HashTable, __Put, "Put")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "key", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "object", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HashTable, __Put)
{
	Object_wx_HashTable *pThis = Object_wx_HashTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long key = arg.GetNumber(0)
	//wxObject* object = arg.GetNumber(1)
	//pThis->GetEntity()->Put(key, object);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HashTable, __Put_1, "Put_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "key", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "object", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HashTable, __Put_1)
{
	Object_wx_HashTable *pThis = Object_wx_HashTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const char* key = arg.GetNumber(0)
	//wxObject* object = arg.GetNumber(1)
	//pThis->GetEntity()->Put(key, object);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHashTable
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HashTable)
{
	// Constructor assignment
	Gura_AssignFunction(__HashTable);
	// Method assignment
	Gura_AssignMethod(wx_HashTable, __BeginFind);
	Gura_AssignMethod(wx_HashTable, __Clear);
	Gura_AssignMethod(wx_HashTable, __Delete);
	Gura_AssignMethod(wx_HashTable, __Delete_1);
	Gura_AssignMethod(wx_HashTable, __DeleteContents);
	Gura_AssignMethod(wx_HashTable, __Get);
	Gura_AssignMethod(wx_HashTable, __Get_1);
	Gura_AssignMethod(wx_HashTable, __GetCount);
	Gura_AssignMethod(wx_HashTable, __MakeKey);
	Gura_AssignMethod(wx_HashTable, __Next);
	Gura_AssignMethod(wx_HashTable, __Put);
	Gura_AssignMethod(wx_HashTable, __Put_1);
}

Gura_ImplementDescendantCreator(wx_HashTable)
{
	return new Object_wx_HashTable((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
