//----------------------------------------------------------------------------
// wxClassInfo
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxClassInfo
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxClassInfo
//----------------------------------------------------------------------------
Object_wx_ClassInfo::~Object_wx_ClassInfo()
{
}

Object *Object_wx_ClassInfo::Clone() const
{
	return nullptr;
}

String Object_wx_ClassInfo::ToString(bool exprFlag)
{
	String rtn("<wx.ClassInfo:");
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
Gura_DeclareFunctionAlias(__wxClassInfo, "wxClassInfo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "className", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "baseClass1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "baseClass2", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fn", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxClassInfo)
{
	//int className = arg.GetNumber(0)
	//int baseClass1 = arg.GetNumber(1)
	//int baseClass2 = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int fn = arg.GetNumber(4)
	//wxClassInfo();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_ClassInfo, __CreateObject, "CreateObject")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ClassInfo, __CreateObject)
{
	Object_wx_ClassInfo *pThis = Object_wx_ClassInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CreateObject();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ClassInfo, __FindClass, "FindClass")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "className", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ClassInfo, __FindClass)
{
	Object_wx_ClassInfo *pThis = Object_wx_ClassInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int className = arg.GetNumber(0)
	//pThis->GetEntity()->FindClass();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ClassInfo, __GetBaseClassName1, "GetBaseClassName1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ClassInfo, __GetBaseClassName1)
{
	Object_wx_ClassInfo *pThis = Object_wx_ClassInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBaseClassName1();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ClassInfo, __GetBaseClassName2, "GetBaseClassName2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ClassInfo, __GetBaseClassName2)
{
	Object_wx_ClassInfo *pThis = Object_wx_ClassInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBaseClassName2();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ClassInfo, __GetClassName, "GetClassName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ClassInfo, __GetClassName)
{
	Object_wx_ClassInfo *pThis = Object_wx_ClassInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetClassName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ClassInfo, __GetSize, "GetSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ClassInfo, __GetSize)
{
	Object_wx_ClassInfo *pThis = Object_wx_ClassInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ClassInfo, __IsDynamic, "IsDynamic")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ClassInfo, __IsDynamic)
{
	Object_wx_ClassInfo *pThis = Object_wx_ClassInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsDynamic();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ClassInfo, __IsKindOf, "IsKindOf")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "info", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ClassInfo, __IsKindOf)
{
	Object_wx_ClassInfo *pThis = Object_wx_ClassInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int info = arg.GetNumber(0)
	//pThis->GetEntity()->IsKindOf();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxClassInfo
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ClassInfo)
{
	// Constructor assignment
	Gura_AssignFunction(__wxClassInfo);
	// Method assignment
	Gura_AssignMethod(wx_ClassInfo, __CreateObject);
	Gura_AssignMethod(wx_ClassInfo, __FindClass);
	Gura_AssignMethod(wx_ClassInfo, __GetBaseClassName1);
	Gura_AssignMethod(wx_ClassInfo, __GetBaseClassName2);
	Gura_AssignMethod(wx_ClassInfo, __GetClassName);
	Gura_AssignMethod(wx_ClassInfo, __GetSize);
	Gura_AssignMethod(wx_ClassInfo, __IsDynamic);
	Gura_AssignMethod(wx_ClassInfo, __IsKindOf);
}

Gura_ImplementDescendantCreator(wx_ClassInfo)
{
	return new Object_wx_ClassInfo((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
