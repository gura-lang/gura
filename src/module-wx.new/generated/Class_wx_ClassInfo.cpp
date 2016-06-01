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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_ClassInfo, wxClassInfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "className", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "baseClass1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "baseClass2", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fn", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ClassInfo, wxClassInfo)
{
	Signal &sig = env.GetSignal();
	Object_wx_ClassInfo *pThis = Object_wx_ClassInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int className = arg.GetNumber(0)
	//int baseClass1 = arg.GetNumber(1)
	//int baseClass2 = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int fn = arg.GetNumber(4)
	//pThis->GetEntity()->wxClassInfo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ClassInfo, CreateObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ClassInfo, CreateObject)
{
	Signal &sig = env.GetSignal();
	Object_wx_ClassInfo *pThis = Object_wx_ClassInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CreateObject();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ClassInfo, FindClass)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "className", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ClassInfo, FindClass)
{
	Signal &sig = env.GetSignal();
	Object_wx_ClassInfo *pThis = Object_wx_ClassInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int className = arg.GetNumber(0)
	//pThis->GetEntity()->FindClass();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ClassInfo, GetBaseClassName1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ClassInfo, GetBaseClassName1)
{
	Signal &sig = env.GetSignal();
	Object_wx_ClassInfo *pThis = Object_wx_ClassInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetBaseClassName1();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ClassInfo, GetBaseClassName2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ClassInfo, GetBaseClassName2)
{
	Signal &sig = env.GetSignal();
	Object_wx_ClassInfo *pThis = Object_wx_ClassInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetBaseClassName2();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ClassInfo, GetClassName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ClassInfo, GetClassName)
{
	Signal &sig = env.GetSignal();
	Object_wx_ClassInfo *pThis = Object_wx_ClassInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetClassName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ClassInfo, GetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ClassInfo, GetSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_ClassInfo *pThis = Object_wx_ClassInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ClassInfo, IsDynamic)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ClassInfo, IsDynamic)
{
	Signal &sig = env.GetSignal();
	Object_wx_ClassInfo *pThis = Object_wx_ClassInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsDynamic();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ClassInfo, IsKindOf)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "info", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ClassInfo, IsKindOf)
{
	Signal &sig = env.GetSignal();
	Object_wx_ClassInfo *pThis = Object_wx_ClassInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int info = arg.GetNumber(0)
	//pThis->GetEntity()->IsKindOf();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxClassInfo
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ClassInfo)
{
	Gura_AssignMethod(wx_ClassInfo, wxClassInfo);
	Gura_AssignMethod(wx_ClassInfo, CreateObject);
	Gura_AssignMethod(wx_ClassInfo, FindClass);
	Gura_AssignMethod(wx_ClassInfo, GetBaseClassName1);
	Gura_AssignMethod(wx_ClassInfo, GetBaseClassName2);
	Gura_AssignMethod(wx_ClassInfo, GetClassName);
	Gura_AssignMethod(wx_ClassInfo, GetSize);
	Gura_AssignMethod(wx_ClassInfo, IsDynamic);
	Gura_AssignMethod(wx_ClassInfo, IsKindOf);
}

Gura_ImplementDescendantCreator(wx_ClassInfo)
{
	return new Object_wx_ClassInfo((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
