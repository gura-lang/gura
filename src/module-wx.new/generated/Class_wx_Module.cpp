//----------------------------------------------------------------------------
// wxModule
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxModule
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxModule
//----------------------------------------------------------------------------
Object_wx_Module::~Object_wx_Module()
{
}

Object *Object_wx_Module::Clone() const
{
	return nullptr;
}

String Object_wx_Module::ToString(bool exprFlag)
{
	String rtn("<wx.Module:");
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
Gura_DeclareMethod(wx_Module, wxModule)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Module, wxModule)
{
	Object_wx_Module *pThis = Object_wx_Module::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxModule();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Module, OnExit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Module, OnExit)
{
	Object_wx_Module *pThis = Object_wx_Module::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->OnExit();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Module, OnInit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Module, OnInit)
{
	Object_wx_Module *pThis = Object_wx_Module::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->OnInit();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Module, AddDependency)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dep", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Module, AddDependency)
{
	Object_wx_Module *pThis = Object_wx_Module::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dep = arg.GetNumber(0)
	//pThis->GetEntity()->AddDependency();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Module, AddDependency_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "classname", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Module, AddDependency_1)
{
	Object_wx_Module *pThis = Object_wx_Module::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int classname = arg.GetNumber(0)
	//pThis->GetEntity()->AddDependency();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxModule
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Module)
{
	Gura_AssignMethod(wx_Module, wxModule);
	Gura_AssignMethod(wx_Module, OnExit);
	Gura_AssignMethod(wx_Module, OnInit);
	Gura_AssignMethod(wx_Module, AddDependency);
	Gura_AssignMethod(wx_Module, AddDependency_1);
}

Gura_ImplementDescendantCreator(wx_Module)
{
	return new Object_wx_Module((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
