//----------------------------------------------------------------------------
// wxPathList
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPathList
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPathList
//----------------------------------------------------------------------------
Object_wx_PathList::~Object_wx_PathList()
{
}

Object *Object_wx_PathList::Clone() const
{
	return nullptr;
}

String Object_wx_PathList::ToString(bool exprFlag)
{
	String rtn("<wx.PathList:");
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
Gura_DeclareFunctionAlias(__wxPathList, "wxPathList")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_PathList));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxPathList)
{
	//wxPathList();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxPathList_1, "wxPathList_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "arr", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_PathList));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxPathList_1)
{
	//int arr = arg.GetNumber(0)
	//wxPathList();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_PathList, __Add, "Add")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PathList, __Add)
{
	Object_wx_PathList *pThis = Object_wx_PathList::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int path = arg.GetNumber(0)
	//pThis->GetEntity()->Add();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PathList, __Add_1, "Add_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "arr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PathList, __Add_1)
{
	Object_wx_PathList *pThis = Object_wx_PathList::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int arr = arg.GetNumber(0)
	//pThis->GetEntity()->Add();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PathList, __AddEnvList, "AddEnvList")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "env_variable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PathList, __AddEnvList)
{
	Object_wx_PathList *pThis = Object_wx_PathList::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int env_variable = arg.GetNumber(0)
	//pThis->GetEntity()->AddEnvList();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PathList, __EnsureFileAccessible, "EnsureFileAccessible")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PathList, __EnsureFileAccessible)
{
	Object_wx_PathList *pThis = Object_wx_PathList::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//pThis->GetEntity()->EnsureFileAccessible();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PathList, __FindAbsoluteValidPath, "FindAbsoluteValidPath")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "file", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PathList, __FindAbsoluteValidPath)
{
	Object_wx_PathList *pThis = Object_wx_PathList::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int file = arg.GetNumber(0)
	//pThis->GetEntity()->FindAbsoluteValidPath();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PathList, __FindValidPath, "FindValidPath")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "file", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PathList, __FindValidPath)
{
	Object_wx_PathList *pThis = Object_wx_PathList::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int file = arg.GetNumber(0)
	//pThis->GetEntity()->FindValidPath();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPathList
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PathList)
{
	// Constructor assignment
	Gura_AssignFunction(__wxPathList);
	Gura_AssignFunction(__wxPathList_1);
	// Method assignment
	Gura_AssignMethod(wx_PathList, __Add);
	Gura_AssignMethod(wx_PathList, __Add_1);
	Gura_AssignMethod(wx_PathList, __AddEnvList);
	Gura_AssignMethod(wx_PathList, __EnsureFileAccessible);
	Gura_AssignMethod(wx_PathList, __FindAbsoluteValidPath);
	Gura_AssignMethod(wx_PathList, __FindValidPath);
}

Gura_ImplementDescendantCreator(wx_PathList)
{
	return new Object_wx_PathList((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
