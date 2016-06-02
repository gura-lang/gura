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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_PathList, wxPathList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PathList, wxPathList)
{
	Object_wx_PathList *pThis = Object_wx_PathList::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxPathList();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PathList, wxPathList_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "arr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PathList, wxPathList_1)
{
	Object_wx_PathList *pThis = Object_wx_PathList::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int arr = arg.GetNumber(0)
	//pThis->GetEntity()->wxPathList();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PathList, Add)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PathList, Add)
{
	Object_wx_PathList *pThis = Object_wx_PathList::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int path = arg.GetNumber(0)
	//pThis->GetEntity()->Add();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PathList, Add_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "arr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PathList, Add_1)
{
	Object_wx_PathList *pThis = Object_wx_PathList::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int arr = arg.GetNumber(0)
	//pThis->GetEntity()->Add();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PathList, AddEnvList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "env_variable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PathList, AddEnvList)
{
	Object_wx_PathList *pThis = Object_wx_PathList::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int env_variable = arg.GetNumber(0)
	//pThis->GetEntity()->AddEnvList();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PathList, EnsureFileAccessible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PathList, EnsureFileAccessible)
{
	Object_wx_PathList *pThis = Object_wx_PathList::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//pThis->GetEntity()->EnsureFileAccessible();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PathList, FindAbsoluteValidPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "file", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PathList, FindAbsoluteValidPath)
{
	Object_wx_PathList *pThis = Object_wx_PathList::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int file = arg.GetNumber(0)
	//pThis->GetEntity()->FindAbsoluteValidPath();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PathList, FindValidPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "file", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PathList, FindValidPath)
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
	Gura_AssignMethod(wx_PathList, wxPathList);
	Gura_AssignMethod(wx_PathList, wxPathList_1);
	Gura_AssignMethod(wx_PathList, Add);
	Gura_AssignMethod(wx_PathList, Add_1);
	Gura_AssignMethod(wx_PathList, AddEnvList);
	Gura_AssignMethod(wx_PathList, EnsureFileAccessible);
	Gura_AssignMethod(wx_PathList, FindAbsoluteValidPath);
	Gura_AssignMethod(wx_PathList, FindValidPath);
}

Gura_ImplementDescendantCreator(wx_PathList)
{
	return new Object_wx_PathList((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
