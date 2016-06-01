//----------------------------------------------------------------------------
// wxHashMap
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHashMap
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHashMap
//----------------------------------------------------------------------------
Object_wx_HashMap::~Object_wx_HashMap()
{
}

Object *Object_wx_HashMap::Clone() const
{
	return nullptr;
}

String Object_wx_HashMap::ToString(bool exprFlag)
{
	String rtn("<wx.HashMap:");
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
Gura_DeclareMethod(wx_HashMap, wxHashMap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HashMap, wxHashMap)
{
	Signal &sig = env.GetSignal();
	Object_wx_HashMap *pThis = Object_wx_HashMap::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->wxHashMap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HashMap, wxHashMap_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "map", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HashMap, wxHashMap_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_HashMap *pThis = Object_wx_HashMap::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int map = arg.GetNumber(0)
	//pThis->GetEntity()->wxHashMap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HashMap, begin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HashMap, begin)
{
	Signal &sig = env.GetSignal();
	Object_wx_HashMap *pThis = Object_wx_HashMap::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->begin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HashMap, begin_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HashMap, begin_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_HashMap *pThis = Object_wx_HashMap::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->begin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HashMap, clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HashMap, clear)
{
	Signal &sig = env.GetSignal();
	Object_wx_HashMap *pThis = Object_wx_HashMap::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->clear();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HashMap, count)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "key", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HashMap, count)
{
	Signal &sig = env.GetSignal();
	Object_wx_HashMap *pThis = Object_wx_HashMap::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int key = arg.GetNumber(0)
	//pThis->GetEntity()->count();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HashMap, empty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HashMap, empty)
{
	Signal &sig = env.GetSignal();
	Object_wx_HashMap *pThis = Object_wx_HashMap::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->empty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HashMap, end)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HashMap, end)
{
	Signal &sig = env.GetSignal();
	Object_wx_HashMap *pThis = Object_wx_HashMap::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->end();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HashMap, end_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HashMap, end_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_HashMap *pThis = Object_wx_HashMap::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->end();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HashMap, erase)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "key", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HashMap, erase)
{
	Signal &sig = env.GetSignal();
	Object_wx_HashMap *pThis = Object_wx_HashMap::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int key = arg.GetNumber(0)
	//pThis->GetEntity()->erase();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HashMap, erase_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "it", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HashMap, erase_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_HashMap *pThis = Object_wx_HashMap::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int it = arg.GetNumber(0)
	//pThis->GetEntity()->erase();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HashMap, erase_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "it", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HashMap, erase_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_HashMap *pThis = Object_wx_HashMap::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int it = arg.GetNumber(0)
	//pThis->GetEntity()->erase();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HashMap, find)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "key", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HashMap, find)
{
	Signal &sig = env.GetSignal();
	Object_wx_HashMap *pThis = Object_wx_HashMap::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int key = arg.GetNumber(0)
	//pThis->GetEntity()->find();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HashMap, find_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "key", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HashMap, find_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_HashMap *pThis = Object_wx_HashMap::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int key = arg.GetNumber(0)
	//pThis->GetEntity()->find();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HashMap, insert)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "v", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HashMap, insert)
{
	Signal &sig = env.GetSignal();
	Object_wx_HashMap *pThis = Object_wx_HashMap::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int v = arg.GetNumber(0)
	//pThis->GetEntity()->insert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HashMap, size)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HashMap, size)
{
	Signal &sig = env.GetSignal();
	Object_wx_HashMap *pThis = Object_wx_HashMap::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->size();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHashMap
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HashMap)
{
	Gura_AssignMethod(wx_HashMap, wxHashMap);
	Gura_AssignMethod(wx_HashMap, wxHashMap_1);
	Gura_AssignMethod(wx_HashMap, begin);
	Gura_AssignMethod(wx_HashMap, begin_1);
	Gura_AssignMethod(wx_HashMap, clear);
	Gura_AssignMethod(wx_HashMap, count);
	Gura_AssignMethod(wx_HashMap, empty);
	Gura_AssignMethod(wx_HashMap, end);
	Gura_AssignMethod(wx_HashMap, end_1);
	Gura_AssignMethod(wx_HashMap, erase);
	Gura_AssignMethod(wx_HashMap, erase_1);
	Gura_AssignMethod(wx_HashMap, erase_2);
	Gura_AssignMethod(wx_HashMap, find);
	Gura_AssignMethod(wx_HashMap, find_1);
	Gura_AssignMethod(wx_HashMap, insert);
	Gura_AssignMethod(wx_HashMap, size);
}

Gura_ImplementDescendantCreator(wx_HashMap)
{
	return new Object_wx_HashMap((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
