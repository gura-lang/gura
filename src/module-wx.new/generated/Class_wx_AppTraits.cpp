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
Gura_DeclareMethodAlias(wx_AppTraits, __CreateConfig, "CreateConfig")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppTraits, __CreateConfig)
{
	Object_wx_AppTraits *pThis = Object_wx_AppTraits::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CreateConfig();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppTraits, __CreateEventLoop, "CreateEventLoop")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppTraits, __CreateEventLoop)
{
	Object_wx_AppTraits *pThis = Object_wx_AppTraits::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CreateEventLoop();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppTraits, __CreateFontMapper, "CreateFontMapper")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppTraits, __CreateFontMapper)
{
	Object_wx_AppTraits *pThis = Object_wx_AppTraits::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CreateFontMapper();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppTraits, __CreateLogTarget, "CreateLogTarget")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppTraits, __CreateLogTarget)
{
	Object_wx_AppTraits *pThis = Object_wx_AppTraits::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CreateLogTarget();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppTraits, __CreateMessageOutput, "CreateMessageOutput")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppTraits, __CreateMessageOutput)
{
	Object_wx_AppTraits *pThis = Object_wx_AppTraits::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CreateMessageOutput();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppTraits, __CreateRenderer, "CreateRenderer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppTraits, __CreateRenderer)
{
	Object_wx_AppTraits *pThis = Object_wx_AppTraits::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CreateRenderer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppTraits, __GetDesktopEnvironment, "GetDesktopEnvironment")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppTraits, __GetDesktopEnvironment)
{
	Object_wx_AppTraits *pThis = Object_wx_AppTraits::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDesktopEnvironment();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppTraits, __GetStandardPaths, "GetStandardPaths")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppTraits, __GetStandardPaths)
{
	Object_wx_AppTraits *pThis = Object_wx_AppTraits::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStandardPaths();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppTraits, __GetToolkitVersion, "GetToolkitVersion")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "major", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "minor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AppTraits, __GetToolkitVersion)
{
	Object_wx_AppTraits *pThis = Object_wx_AppTraits::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int* major = arg.GetNumber(0)
	//int* minor = arg.GetNumber(1)
	//pThis->GetEntity()->GetToolkitVersion(major, minor);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppTraits, __HasStderr, "HasStderr")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppTraits, __HasStderr)
{
	Object_wx_AppTraits *pThis = Object_wx_AppTraits::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasStderr();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppTraits, __IsUsingUniversalWidgets, "IsUsingUniversalWidgets")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AppTraits, __IsUsingUniversalWidgets)
{
	Object_wx_AppTraits *pThis = Object_wx_AppTraits::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsUsingUniversalWidgets();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AppTraits, __ShowAssertDialog, "ShowAssertDialog")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "msg", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AppTraits, __ShowAssertDialog)
{
	Object_wx_AppTraits *pThis = Object_wx_AppTraits::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& msg = arg.GetNumber(0)
	//pThis->GetEntity()->ShowAssertDialog(msg);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxAppTraits
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AppTraits)
{
	// Class assignment
	Gura_AssignValueEx("AppTraits", Reference());
	// Method assignment
	Gura_AssignMethod(wx_AppTraits, __CreateConfig);
	Gura_AssignMethod(wx_AppTraits, __CreateEventLoop);
	Gura_AssignMethod(wx_AppTraits, __CreateFontMapper);
	Gura_AssignMethod(wx_AppTraits, __CreateLogTarget);
	Gura_AssignMethod(wx_AppTraits, __CreateMessageOutput);
	Gura_AssignMethod(wx_AppTraits, __CreateRenderer);
	Gura_AssignMethod(wx_AppTraits, __GetDesktopEnvironment);
	Gura_AssignMethod(wx_AppTraits, __GetStandardPaths);
	Gura_AssignMethod(wx_AppTraits, __GetToolkitVersion);
	Gura_AssignMethod(wx_AppTraits, __HasStderr);
	Gura_AssignMethod(wx_AppTraits, __IsUsingUniversalWidgets);
	Gura_AssignMethod(wx_AppTraits, __ShowAssertDialog);
}

Gura_ImplementDescendantCreator(wx_AppTraits)
{
	return new Object_wx_AppTraits((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
