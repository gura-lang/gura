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
Gura_DeclareMethod(wx_GLContextAttrs, CoreProfile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GLContextAttrs, CoreProfile)
{
	Object_wx_GLContextAttrs *pThis = Object_wx_GLContextAttrs::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CoreProfile();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GLContextAttrs, MajorVersion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GLContextAttrs, MajorVersion)
{
	Object_wx_GLContextAttrs *pThis = Object_wx_GLContextAttrs::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int val = arg.GetNumber(0)
	//pThis->GetEntity()->MajorVersion();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GLContextAttrs, MinorVersion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GLContextAttrs, MinorVersion)
{
	Object_wx_GLContextAttrs *pThis = Object_wx_GLContextAttrs::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int val = arg.GetNumber(0)
	//pThis->GetEntity()->MinorVersion();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GLContextAttrs, OGLVersion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "vmayor", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "vminor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GLContextAttrs, OGLVersion)
{
	Object_wx_GLContextAttrs *pThis = Object_wx_GLContextAttrs::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int vmayor = arg.GetNumber(0)
	//int vminor = arg.GetNumber(1)
	//pThis->GetEntity()->OGLVersion();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GLContextAttrs, CompatibilityProfile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GLContextAttrs, CompatibilityProfile)
{
	Object_wx_GLContextAttrs *pThis = Object_wx_GLContextAttrs::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CompatibilityProfile();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GLContextAttrs, ForwardCompatible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GLContextAttrs, ForwardCompatible)
{
	Object_wx_GLContextAttrs *pThis = Object_wx_GLContextAttrs::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ForwardCompatible();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GLContextAttrs, ES2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GLContextAttrs, ES2)
{
	Object_wx_GLContextAttrs *pThis = Object_wx_GLContextAttrs::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ES2();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GLContextAttrs, DebugCtx)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GLContextAttrs, DebugCtx)
{
	Object_wx_GLContextAttrs *pThis = Object_wx_GLContextAttrs::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DebugCtx();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GLContextAttrs, Robust)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GLContextAttrs, Robust)
{
	Object_wx_GLContextAttrs *pThis = Object_wx_GLContextAttrs::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Robust();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GLContextAttrs, NoResetNotify)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GLContextAttrs, NoResetNotify)
{
	Object_wx_GLContextAttrs *pThis = Object_wx_GLContextAttrs::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->NoResetNotify();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GLContextAttrs, LoseOnReset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GLContextAttrs, LoseOnReset)
{
	Object_wx_GLContextAttrs *pThis = Object_wx_GLContextAttrs::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->LoseOnReset();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GLContextAttrs, ResetIsolation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GLContextAttrs, ResetIsolation)
{
	Object_wx_GLContextAttrs *pThis = Object_wx_GLContextAttrs::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ResetIsolation();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GLContextAttrs, ReleaseFlush)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GLContextAttrs, ReleaseFlush)
{
	Object_wx_GLContextAttrs *pThis = Object_wx_GLContextAttrs::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int val = arg.GetNumber(0)
	//pThis->GetEntity()->ReleaseFlush();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GLContextAttrs, PlatformDefaults)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GLContextAttrs, PlatformDefaults)
{
	Object_wx_GLContextAttrs *pThis = Object_wx_GLContextAttrs::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->PlatformDefaults();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GLContextAttrs, EndList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GLContextAttrs, EndList)
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
	Gura_AssignMethod(wx_GLContextAttrs, CoreProfile);
	Gura_AssignMethod(wx_GLContextAttrs, MajorVersion);
	Gura_AssignMethod(wx_GLContextAttrs, MinorVersion);
	Gura_AssignMethod(wx_GLContextAttrs, OGLVersion);
	Gura_AssignMethod(wx_GLContextAttrs, CompatibilityProfile);
	Gura_AssignMethod(wx_GLContextAttrs, ForwardCompatible);
	Gura_AssignMethod(wx_GLContextAttrs, ES2);
	Gura_AssignMethod(wx_GLContextAttrs, DebugCtx);
	Gura_AssignMethod(wx_GLContextAttrs, Robust);
	Gura_AssignMethod(wx_GLContextAttrs, NoResetNotify);
	Gura_AssignMethod(wx_GLContextAttrs, LoseOnReset);
	Gura_AssignMethod(wx_GLContextAttrs, ResetIsolation);
	Gura_AssignMethod(wx_GLContextAttrs, ReleaseFlush);
	Gura_AssignMethod(wx_GLContextAttrs, PlatformDefaults);
	Gura_AssignMethod(wx_GLContextAttrs, EndList);
}

Gura_ImplementDescendantCreator(wx_GLContextAttrs)
{
	return new Object_wx_GLContextAttrs((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
