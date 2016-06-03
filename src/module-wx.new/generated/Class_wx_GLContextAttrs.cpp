//----------------------------------------------------------------------------
// wxGLContextAttrs
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGLContextAttrs
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGLContextAttrs
//----------------------------------------------------------------------------
Object_wx_GLContextAttrs::~Object_wx_GLContextAttrs()
{
}

Object *Object_wx_GLContextAttrs::Clone() const
{
	return nullptr;
}

String Object_wx_GLContextAttrs::ToString(bool exprFlag)
{
	String rtn("<wx.GLContextAttrs:");
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
Gura_DeclareMethodAlias(wx_GLContextAttrs, __CoreProfile, "CoreProfile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GLContextAttrs, __CoreProfile)
{
	Object_wx_GLContextAttrs *pThis = Object_wx_GLContextAttrs::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CoreProfile();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GLContextAttrs, __MajorVersion, "MajorVersion")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GLContextAttrs, __MajorVersion)
{
	Object_wx_GLContextAttrs *pThis = Object_wx_GLContextAttrs::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int val = arg.GetNumber(0)
	//pThis->GetEntity()->MajorVersion();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GLContextAttrs, __MinorVersion, "MinorVersion")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GLContextAttrs, __MinorVersion)
{
	Object_wx_GLContextAttrs *pThis = Object_wx_GLContextAttrs::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int val = arg.GetNumber(0)
	//pThis->GetEntity()->MinorVersion();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GLContextAttrs, __OGLVersion, "OGLVersion")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "vmayor", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "vminor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GLContextAttrs, __OGLVersion)
{
	Object_wx_GLContextAttrs *pThis = Object_wx_GLContextAttrs::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int vmayor = arg.GetNumber(0)
	//int vminor = arg.GetNumber(1)
	//pThis->GetEntity()->OGLVersion();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GLContextAttrs, __CompatibilityProfile, "CompatibilityProfile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GLContextAttrs, __CompatibilityProfile)
{
	Object_wx_GLContextAttrs *pThis = Object_wx_GLContextAttrs::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CompatibilityProfile();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GLContextAttrs, __ForwardCompatible, "ForwardCompatible")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GLContextAttrs, __ForwardCompatible)
{
	Object_wx_GLContextAttrs *pThis = Object_wx_GLContextAttrs::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ForwardCompatible();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GLContextAttrs, __ES2, "ES2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GLContextAttrs, __ES2)
{
	Object_wx_GLContextAttrs *pThis = Object_wx_GLContextAttrs::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ES2();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GLContextAttrs, __DebugCtx, "DebugCtx")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GLContextAttrs, __DebugCtx)
{
	Object_wx_GLContextAttrs *pThis = Object_wx_GLContextAttrs::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DebugCtx();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GLContextAttrs, __Robust, "Robust")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GLContextAttrs, __Robust)
{
	Object_wx_GLContextAttrs *pThis = Object_wx_GLContextAttrs::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Robust();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GLContextAttrs, __NoResetNotify, "NoResetNotify")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GLContextAttrs, __NoResetNotify)
{
	Object_wx_GLContextAttrs *pThis = Object_wx_GLContextAttrs::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->NoResetNotify();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GLContextAttrs, __LoseOnReset, "LoseOnReset")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GLContextAttrs, __LoseOnReset)
{
	Object_wx_GLContextAttrs *pThis = Object_wx_GLContextAttrs::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->LoseOnReset();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GLContextAttrs, __ResetIsolation, "ResetIsolation")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GLContextAttrs, __ResetIsolation)
{
	Object_wx_GLContextAttrs *pThis = Object_wx_GLContextAttrs::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ResetIsolation();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GLContextAttrs, __ReleaseFlush, "ReleaseFlush")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GLContextAttrs, __ReleaseFlush)
{
	Object_wx_GLContextAttrs *pThis = Object_wx_GLContextAttrs::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int val = arg.GetNumber(0)
	//pThis->GetEntity()->ReleaseFlush();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GLContextAttrs, __PlatformDefaults, "PlatformDefaults")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GLContextAttrs, __PlatformDefaults)
{
	Object_wx_GLContextAttrs *pThis = Object_wx_GLContextAttrs::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->PlatformDefaults();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GLContextAttrs, __EndList, "EndList")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GLContextAttrs, __EndList)
{
	Object_wx_GLContextAttrs *pThis = Object_wx_GLContextAttrs::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->EndList();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGLContextAttrs
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GLContextAttrs)
{
	// Method assignment
	Gura_AssignMethod(wx_GLContextAttrs, __CoreProfile);
	Gura_AssignMethod(wx_GLContextAttrs, __MajorVersion);
	Gura_AssignMethod(wx_GLContextAttrs, __MinorVersion);
	Gura_AssignMethod(wx_GLContextAttrs, __OGLVersion);
	Gura_AssignMethod(wx_GLContextAttrs, __CompatibilityProfile);
	Gura_AssignMethod(wx_GLContextAttrs, __ForwardCompatible);
	Gura_AssignMethod(wx_GLContextAttrs, __ES2);
	Gura_AssignMethod(wx_GLContextAttrs, __DebugCtx);
	Gura_AssignMethod(wx_GLContextAttrs, __Robust);
	Gura_AssignMethod(wx_GLContextAttrs, __NoResetNotify);
	Gura_AssignMethod(wx_GLContextAttrs, __LoseOnReset);
	Gura_AssignMethod(wx_GLContextAttrs, __ResetIsolation);
	Gura_AssignMethod(wx_GLContextAttrs, __ReleaseFlush);
	Gura_AssignMethod(wx_GLContextAttrs, __PlatformDefaults);
	Gura_AssignMethod(wx_GLContextAttrs, __EndList);
}

Gura_ImplementDescendantCreator(wx_GLContextAttrs)
{
	return new Object_wx_GLContextAttrs((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
