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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_HashSet, wxHashSet)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HashSet, wxHashSet)
{
	Object_wx_HashSet *pThis = Object_wx_HashSet::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->wxHashSet();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HashSet, wxHashSet_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "set", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HashSet, wxHashSet_1)
{
	Object_wx_HashSet *pThis = Object_wx_HashSet::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int set = arg.GetNumber(0)
	//pThis->GetEntity()->wxHashSet();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HashSet, begin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HashSet, begin)
{
	Object_wx_HashSet *pThis = Object_wx_HashSet::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->begin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HashSet, begin_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HashSet, begin_1)
{
	Object_wx_HashSet *pThis = Object_wx_HashSet::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->begin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HashSet, clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HashSet, clear)
{
	Object_wx_HashSet *pThis = Object_wx_HashSet::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->clear();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HashSet, count)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "key", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HashSet, count)
{
	Object_wx_HashSet *pThis = Object_wx_HashSet::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int key = arg.GetNumber(0)
	//pThis->GetEntity()->count();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HashSet, empty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HashSet, empty)
{
	Object_wx_HashSet *pThis = Object_wx_HashSet::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->empty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HashSet, end)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HashSet, end)
{
	Object_wx_HashSet *pThis = Object_wx_HashSet::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->end();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HashSet, end_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HashSet, end_1)
{
	Object_wx_HashSet *pThis = Object_wx_HashSet::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->end();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HashSet, erase)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "key", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HashSet, erase)
{
	Object_wx_HashSet *pThis = Object_wx_HashSet::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int key = arg.GetNumber(0)
	//pThis->GetEntity()->erase();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HashSet, erase_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "it", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HashSet, erase_1)
{
	Object_wx_HashSet *pThis = Object_wx_HashSet::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int it = arg.GetNumber(0)
	//pThis->GetEntity()->erase();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HashSet, erase_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "it", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HashSet, erase_2)
{
	Object_wx_HashSet *pThis = Object_wx_HashSet::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int it = arg.GetNumber(0)
	//pThis->GetEntity()->erase();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HashSet, find)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "key", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HashSet, find)
{
	Object_wx_HashSet *pThis = Object_wx_HashSet::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int key = arg.GetNumber(0)
	//pThis->GetEntity()->find();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HashSet, find_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "key", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HashSet, find_1)
{
	Object_wx_HashSet *pThis = Object_wx_HashSet::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int key = arg.GetNumber(0)
	//pThis->GetEntity()->find();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HashSet, insert)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "v", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HashSet, insert)
{
	Object_wx_HashSet *pThis = Object_wx_HashSet::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int v = arg.GetNumber(0)
	//pThis->GetEntity()->insert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HashSet, size)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HashSet, size)
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
	Gura_AssignMethod(wx_HashSet, wxHashSet);
	Gura_AssignMethod(wx_HashSet, wxHashSet_1);
	Gura_AssignMethod(wx_HashSet, begin);
	Gura_AssignMethod(wx_HashSet, begin_1);
	Gura_AssignMethod(wx_HashSet, clear);
	Gura_AssignMethod(wx_HashSet, count);
	Gura_AssignMethod(wx_HashSet, empty);
	Gura_AssignMethod(wx_HashSet, end);
	Gura_AssignMethod(wx_HashSet, end_1);
	Gura_AssignMethod(wx_HashSet, erase);
	Gura_AssignMethod(wx_HashSet, erase_1);
	Gura_AssignMethod(wx_HashSet, erase_2);
	Gura_AssignMethod(wx_HashSet, find);
	Gura_AssignMethod(wx_HashSet, find_1);
	Gura_AssignMethod(wx_HashSet, insert);
	Gura_AssignMethod(wx_HashSet, size);
}

Gura_ImplementDescendantCreator(wx_HashSet)
{
	return new Object_wx_HashSet((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
