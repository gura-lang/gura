//----------------------------------------------------------------------------
// wxAppTraits
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAppTraits
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAppTraits
//----------------------------------------------------------------------------
Object_wx_AppTraits::~Object_wx_AppTraits()
{
}

Object *Object_wx_AppTraits::Clone() const
{
	return nullptr;
}

String Object_wx_AppTraits::ToString(bool exprFlag)
{
	String rtn("<wx.AppTraits:");
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
Gura_DeclareMethod(wx_AppTraits, CreateConfig)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppTraits, CreateConfig)
{
	Object_wx_AppTraits *pThis = Object_wx_AppTraits::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CreateConfig();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AppTraits, CreateEventLoop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppTraits, CreateEventLoop)
{
	Object_wx_AppTraits *pThis = Object_wx_AppTraits::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CreateEventLoop();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AppTraits, CreateFontMapper)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppTraits, CreateFontMapper)
{
	Object_wx_AppTraits *pThis = Object_wx_AppTraits::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CreateFontMapper();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AppTraits, CreateLogTarget)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppTraits, CreateLogTarget)
{
	Object_wx_AppTraits *pThis = Object_wx_AppTraits::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CreateLogTarget();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AppTraits, CreateMessageOutput)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppTraits, CreateMessageOutput)
{
	Object_wx_AppTraits *pThis = Object_wx_AppTraits::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CreateMessageOutput();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AppTraits, CreateRenderer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppTraits, CreateRenderer)
{
	Object_wx_AppTraits *pThis = Object_wx_AppTraits::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CreateRenderer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AppTraits, GetDesktopEnvironment)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppTraits, GetDesktopEnvironment)
{
	Object_wx_AppTraits *pThis = Object_wx_AppTraits::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDesktopEnvironment();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AppTraits, GetStandardPaths)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppTraits, GetStandardPaths)
{
	Object_wx_AppTraits *pThis = Object_wx_AppTraits::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStandardPaths();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AppTraits, GetToolkitVersion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "major", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "minor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AppTraits, GetToolkitVersion)
{
	Object_wx_AppTraits *pThis = Object_wx_AppTraits::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int major = arg.GetNumber(0)
	//int minor = arg.GetNumber(1)
	//pThis->GetEntity()->GetToolkitVersion();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AppTraits, HasStderr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppTraits, HasStderr)
{
	Object_wx_AppTraits *pThis = Object_wx_AppTraits::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasStderr();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AppTraits, IsUsingUniversalWidgets)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppTraits, IsUsingUniversalWidgets)
{
	Object_wx_AppTraits *pThis = Object_wx_AppTraits::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsUsingUniversalWidgets();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AppTraits, ShowAssertDialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "msg", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AppTraits, ShowAssertDialog)
{
	Object_wx_AppTraits *pThis = Object_wx_AppTraits::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int msg = arg.GetNumber(0)
	//pThis->GetEntity()->ShowAssertDialog();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxAppTraits
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AppTraits)
{
	Gura_AssignMethod(wx_AppTraits, CreateConfig);
	Gura_AssignMethod(wx_AppTraits, CreateEventLoop);
	Gura_AssignMethod(wx_AppTraits, CreateFontMapper);
	Gura_AssignMethod(wx_AppTraits, CreateLogTarget);
	Gura_AssignMethod(wx_AppTraits, CreateMessageOutput);
	Gura_AssignMethod(wx_AppTraits, CreateRenderer);
	Gura_AssignMethod(wx_AppTraits, GetDesktopEnvironment);
	Gura_AssignMethod(wx_AppTraits, GetStandardPaths);
	Gura_AssignMethod(wx_AppTraits, GetToolkitVersion);
	Gura_AssignMethod(wx_AppTraits, HasStderr);
	Gura_AssignMethod(wx_AppTraits, IsUsingUniversalWidgets);
	Gura_AssignMethod(wx_AppTraits, ShowAssertDialog);
}

Gura_ImplementDescendantCreator(wx_AppTraits)
{
	return new Object_wx_AppTraits((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
