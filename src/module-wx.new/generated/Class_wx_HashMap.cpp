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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__HashMap, "HashMap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_HashMap));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__HashMap)
{
	//size_type size = arg.GetNumber(0)
	//wxHashMap();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__HashMap_1, "HashMap_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "map", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_HashMap));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__HashMap_1)
{
	//const wxHashMap& map = arg.GetNumber(0)
	//wxHashMap();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_HashMap, __begin, "begin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HashMap, __begin)
{
	Object_wx_HashMap *pThis = Object_wx_HashMap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->begin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HashMap, __begin_1, "begin_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HashMap, __begin_1)
{
	Object_wx_HashMap *pThis = Object_wx_HashMap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->begin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HashMap, __clear, "clear")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HashMap, __clear)
{
	Object_wx_HashMap *pThis = Object_wx_HashMap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->clear();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HashMap, __count, "count")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "key", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HashMap, __count)
{
	Object_wx_HashMap *pThis = Object_wx_HashMap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const key_type& key = arg.GetNumber(0)
	//pThis->GetEntity()->count();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HashMap, __empty, "empty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HashMap, __empty)
{
	Object_wx_HashMap *pThis = Object_wx_HashMap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->empty();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HashMap, __end, "end")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HashMap, __end)
{
	Object_wx_HashMap *pThis = Object_wx_HashMap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->end();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HashMap, __end_1, "end_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HashMap, __end_1)
{
	Object_wx_HashMap *pThis = Object_wx_HashMap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->end();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HashMap, __erase, "erase")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "key", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HashMap, __erase)
{
	Object_wx_HashMap *pThis = Object_wx_HashMap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const key_type& key = arg.GetNumber(0)
	//pThis->GetEntity()->erase();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HashMap, __erase_1, "erase_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "it", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HashMap, __erase_1)
{
	Object_wx_HashMap *pThis = Object_wx_HashMap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//iterator it = arg.GetNumber(0)
	//pThis->GetEntity()->erase();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HashMap, __erase_2, "erase_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "it", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HashMap, __erase_2)
{
	Object_wx_HashMap *pThis = Object_wx_HashMap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const_iterator it = arg.GetNumber(0)
	//pThis->GetEntity()->erase();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HashMap, __find, "find")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "key", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HashMap, __find)
{
	Object_wx_HashMap *pThis = Object_wx_HashMap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const key_type& key = arg.GetNumber(0)
	//pThis->GetEntity()->find();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HashMap, __find_1, "find_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "key", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HashMap, __find_1)
{
	Object_wx_HashMap *pThis = Object_wx_HashMap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const key_type& key = arg.GetNumber(0)
	//pThis->GetEntity()->find();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HashMap, __insert, "insert")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "v", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HashMap, __insert)
{
	Object_wx_HashMap *pThis = Object_wx_HashMap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const value_type& v = arg.GetNumber(0)
	//pThis->GetEntity()->insert();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HashMap, __size, "size")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HashMap, __size)
{
	Object_wx_HashMap *pThis = Object_wx_HashMap::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->size();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHashMap
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HashMap)
{
	// Constructor assignment
	Gura_AssignFunction(__HashMap);
	Gura_AssignFunction(__HashMap_1);
	// Method assignment
	Gura_AssignMethod(wx_HashMap, __begin);
	Gura_AssignMethod(wx_HashMap, __begin_1);
	Gura_AssignMethod(wx_HashMap, __clear);
	Gura_AssignMethod(wx_HashMap, __count);
	Gura_AssignMethod(wx_HashMap, __empty);
	Gura_AssignMethod(wx_HashMap, __end);
	Gura_AssignMethod(wx_HashMap, __end_1);
	Gura_AssignMethod(wx_HashMap, __erase);
	Gura_AssignMethod(wx_HashMap, __erase_1);
	Gura_AssignMethod(wx_HashMap, __erase_2);
	Gura_AssignMethod(wx_HashMap, __find);
	Gura_AssignMethod(wx_HashMap, __find_1);
	Gura_AssignMethod(wx_HashMap, __insert);
	Gura_AssignMethod(wx_HashMap, __size);
}

Gura_ImplementDescendantCreator(wx_HashMap)
{
	return new Object_wx_HashMap((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
