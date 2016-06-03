//----------------------------------------------------------------------------
// wxHashSet
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHashSet
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHashSet
//----------------------------------------------------------------------------
Object_wx_HashSet::~Object_wx_HashSet()
{
}

Object *Object_wx_HashSet::Clone() const
{
	return nullptr;
}

String Object_wx_HashSet::ToString(bool exprFlag)
{
	String rtn("<wx.HashSet:");
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
Gura_DeclareFunctionAlias(__HashSet, "HashSet")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_HashSet));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__HashSet)
{
	//int size = arg.GetNumber(0)
	//wxHashSet();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__HashSet_1, "HashSet_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "set", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_HashSet));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__HashSet_1)
{
	//int set = arg.GetNumber(0)
	//wxHashSet();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_HashSet, __begin, "begin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HashSet, __begin)
{
	Object_wx_HashSet *pThis = Object_wx_HashSet::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->begin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HashSet, __begin_1, "begin_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HashSet, __begin_1)
{
	Object_wx_HashSet *pThis = Object_wx_HashSet::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->begin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HashSet, __clear, "clear")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HashSet, __clear)
{
	Object_wx_HashSet *pThis = Object_wx_HashSet::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->clear();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HashSet, __count, "count")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "key", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HashSet, __count)
{
	Object_wx_HashSet *pThis = Object_wx_HashSet::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int key = arg.GetNumber(0)
	//pThis->GetEntity()->count();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HashSet, __empty, "empty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HashSet, __empty)
{
	Object_wx_HashSet *pThis = Object_wx_HashSet::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->empty();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HashSet, __end, "end")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HashSet, __end)
{
	Object_wx_HashSet *pThis = Object_wx_HashSet::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->end();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HashSet, __end_1, "end_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HashSet, __end_1)
{
	Object_wx_HashSet *pThis = Object_wx_HashSet::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->end();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HashSet, __erase, "erase")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "key", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HashSet, __erase)
{
	Object_wx_HashSet *pThis = Object_wx_HashSet::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int key = arg.GetNumber(0)
	//pThis->GetEntity()->erase();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HashSet, __erase_1, "erase_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "it", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HashSet, __erase_1)
{
	Object_wx_HashSet *pThis = Object_wx_HashSet::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int it = arg.GetNumber(0)
	//pThis->GetEntity()->erase();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HashSet, __erase_2, "erase_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "it", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HashSet, __erase_2)
{
	Object_wx_HashSet *pThis = Object_wx_HashSet::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int it = arg.GetNumber(0)
	//pThis->GetEntity()->erase();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HashSet, __find, "find")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "key", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HashSet, __find)
{
	Object_wx_HashSet *pThis = Object_wx_HashSet::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int key = arg.GetNumber(0)
	//pThis->GetEntity()->find();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HashSet, __find_1, "find_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "key", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HashSet, __find_1)
{
	Object_wx_HashSet *pThis = Object_wx_HashSet::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int key = arg.GetNumber(0)
	//pThis->GetEntity()->find();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HashSet, __insert, "insert")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "v", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HashSet, __insert)
{
	Object_wx_HashSet *pThis = Object_wx_HashSet::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int v = arg.GetNumber(0)
	//pThis->GetEntity()->insert();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HashSet, __size, "size")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HashSet, __size)
{
	Object_wx_HashSet *pThis = Object_wx_HashSet::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->size();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHashSet
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HashSet)
{
	// Constructor assignment
	Gura_AssignFunction(__HashSet);
	Gura_AssignFunction(__HashSet_1);
	// Method assignment
	Gura_AssignMethod(wx_HashSet, __begin);
	Gura_AssignMethod(wx_HashSet, __begin_1);
	Gura_AssignMethod(wx_HashSet, __clear);
	Gura_AssignMethod(wx_HashSet, __count);
	Gura_AssignMethod(wx_HashSet, __empty);
	Gura_AssignMethod(wx_HashSet, __end);
	Gura_AssignMethod(wx_HashSet, __end_1);
	Gura_AssignMethod(wx_HashSet, __erase);
	Gura_AssignMethod(wx_HashSet, __erase_1);
	Gura_AssignMethod(wx_HashSet, __erase_2);
	Gura_AssignMethod(wx_HashSet, __find);
	Gura_AssignMethod(wx_HashSet, __find_1);
	Gura_AssignMethod(wx_HashSet, __insert);
	Gura_AssignMethod(wx_HashSet, __size);
}

Gura_ImplementDescendantCreator(wx_HashSet)
{
	return new Object_wx_HashSet((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
