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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__Module, "Module")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Module));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Module)
{
	//wxModule();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Module, __OnExit, "OnExit")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Module, __OnExit)
{
	Object_wx_Module *pThis = Object_wx_Module::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->OnExit();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Module, __OnInit, "OnInit")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Module, __OnInit)
{
	Object_wx_Module *pThis = Object_wx_Module::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->OnInit();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Module, __AddDependency, "AddDependency")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dep", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Module, __AddDependency)
{
	Object_wx_Module *pThis = Object_wx_Module::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxClassInfo* dep = arg.GetNumber(0)
	//pThis->GetEntity()->AddDependency();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Module, __AddDependency_1, "AddDependency_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "classname", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Module, __AddDependency_1)
{
	Object_wx_Module *pThis = Object_wx_Module::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const char* classname = arg.GetNumber(0)
	//pThis->GetEntity()->AddDependency();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxModule
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Module)
{
	// Constructor assignment
	Gura_AssignFunction(__Module);
	// Method assignment
	Gura_AssignMethod(wx_Module, __OnExit);
	Gura_AssignMethod(wx_Module, __OnInit);
	Gura_AssignMethod(wx_Module, __AddDependency);
	Gura_AssignMethod(wx_Module, __AddDependency_1);
}

Gura_ImplementDescendantCreator(wx_Module)
{
	return new Object_wx_Module((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
