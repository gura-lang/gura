//----------------------------------------------------------------------------
// wxApp
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxApp
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxApp
//----------------------------------------------------------------------------
Object_wx_App::~Object_wx_App()
{
}

Object *Object_wx_App::Clone() const
{
	return nullptr;
}

String Object_wx_App::ToString(bool exprFlag)
{
	String rtn("<wx.App:");
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
Gura_DeclareMethod(wx_App, wxApp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_App, wxApp)
{
	Object_wx_App *pThis = Object_wx_App::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxApp();
	return Value::Nil;
}

Gura_DeclareMethod(wx_App, GetDisplayMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_App, GetDisplayMode)
{
	Object_wx_App *pThis = Object_wx_App::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDisplayMode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_App, GetExitOnFrameDelete)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_App, GetExitOnFrameDelete)
{
	Object_wx_App *pThis = Object_wx_App::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetExitOnFrameDelete();
	return Value::Nil;
}

Gura_DeclareMethod(wx_App, GetLayoutDirection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_App, GetLayoutDirection)
{
	Object_wx_App *pThis = Object_wx_App::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLayoutDirection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_App, GetUseBestVisual)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_App, GetUseBestVisual)
{
	Object_wx_App *pThis = Object_wx_App::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetUseBestVisual();
	return Value::Nil;
}

Gura_DeclareMethod(wx_App, GetTopWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_App, GetTopWindow)
{
	Object_wx_App *pThis = Object_wx_App::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTopWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_App, IsActive)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_App, IsActive)
{
	Object_wx_App *pThis = Object_wx_App::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsActive();
	return Value::Nil;
}

Gura_DeclareMethod(wx_App, SafeYield)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "onlyIfNeeded", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_App, SafeYield)
{
	Object_wx_App *pThis = Object_wx_App::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//int onlyIfNeeded = arg.GetNumber(1)
	//pThis->GetEntity()->SafeYield();
	return Value::Nil;
}

Gura_DeclareMethod(wx_App, SafeYieldFor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "eventsToProcess", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_App, SafeYieldFor)
{
	Object_wx_App *pThis = Object_wx_App::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//int eventsToProcess = arg.GetNumber(1)
	//pThis->GetEntity()->SafeYieldFor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_App, ProcessMessage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "msg", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_App, ProcessMessage)
{
	Object_wx_App *pThis = Object_wx_App::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int msg = arg.GetNumber(0)
	//pThis->GetEntity()->ProcessMessage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_App, SetDisplayMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "info", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_App, SetDisplayMode)
{
	Object_wx_App *pThis = Object_wx_App::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int info = arg.GetNumber(0)
	//pThis->GetEntity()->SetDisplayMode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_App, SetExitOnFrameDelete)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_App, SetExitOnFrameDelete)
{
	Object_wx_App *pThis = Object_wx_App::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->SetExitOnFrameDelete();
	return Value::Nil;
}

Gura_DeclareMethod(wx_App, SetNativeTheme)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "theme", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_App, SetNativeTheme)
{
	Object_wx_App *pThis = Object_wx_App::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int theme = arg.GetNumber(0)
	//pThis->GetEntity()->SetNativeTheme();
	return Value::Nil;
}

Gura_DeclareMethod(wx_App, SetTopWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_App, SetTopWindow)
{
	Object_wx_App *pThis = Object_wx_App::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//pThis->GetEntity()->SetTopWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_App, SetUseBestVisual)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "forceTrueColour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_App, SetUseBestVisual)
{
	Object_wx_App *pThis = Object_wx_App::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//int forceTrueColour = arg.GetNumber(1)
	//pThis->GetEntity()->SetUseBestVisual();
	return Value::Nil;
}

Gura_DeclareMethod(wx_App, MacNewFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_App, MacNewFile)
{
	Object_wx_App *pThis = Object_wx_App::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->MacNewFile();
	return Value::Nil;
}

Gura_DeclareMethod(wx_App, MacOpenFiles)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fileNames", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_App, MacOpenFiles)
{
	Object_wx_App *pThis = Object_wx_App::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int fileNames = arg.GetNumber(0)
	//pThis->GetEntity()->MacOpenFiles();
	return Value::Nil;
}

Gura_DeclareMethod(wx_App, MacOpenFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fileName", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_App, MacOpenFile)
{
	Object_wx_App *pThis = Object_wx_App::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int fileName = arg.GetNumber(0)
	//pThis->GetEntity()->MacOpenFile();
	return Value::Nil;
}

Gura_DeclareMethod(wx_App, MacOpenURL)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "url", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_App, MacOpenURL)
{
	Object_wx_App *pThis = Object_wx_App::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int url = arg.GetNumber(0)
	//pThis->GetEntity()->MacOpenURL();
	return Value::Nil;
}

Gura_DeclareMethod(wx_App, MacPrintFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fileName", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_App, MacPrintFile)
{
	Object_wx_App *pThis = Object_wx_App::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int fileName = arg.GetNumber(0)
	//pThis->GetEntity()->MacPrintFile();
	return Value::Nil;
}

Gura_DeclareMethod(wx_App, MacReopenApp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_App, MacReopenApp)
{
	Object_wx_App *pThis = Object_wx_App::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->MacReopenApp();
	return Value::Nil;
}

Gura_DeclareMethod(wx_App, OSXIsGUIApplication)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_App, OSXIsGUIApplication)
{
	Object_wx_App *pThis = Object_wx_App::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->OSXIsGUIApplication();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxApp
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_App)
{
	Gura_AssignMethod(wx_App, wxApp);
	Gura_AssignMethod(wx_App, GetDisplayMode);
	Gura_AssignMethod(wx_App, GetExitOnFrameDelete);
	Gura_AssignMethod(wx_App, GetLayoutDirection);
	Gura_AssignMethod(wx_App, GetUseBestVisual);
	Gura_AssignMethod(wx_App, GetTopWindow);
	Gura_AssignMethod(wx_App, IsActive);
	Gura_AssignMethod(wx_App, SafeYield);
	Gura_AssignMethod(wx_App, SafeYieldFor);
	Gura_AssignMethod(wx_App, ProcessMessage);
	Gura_AssignMethod(wx_App, SetDisplayMode);
	Gura_AssignMethod(wx_App, SetExitOnFrameDelete);
	Gura_AssignMethod(wx_App, SetNativeTheme);
	Gura_AssignMethod(wx_App, SetTopWindow);
	Gura_AssignMethod(wx_App, SetUseBestVisual);
	Gura_AssignMethod(wx_App, MacNewFile);
	Gura_AssignMethod(wx_App, MacOpenFiles);
	Gura_AssignMethod(wx_App, MacOpenFile);
	Gura_AssignMethod(wx_App, MacOpenURL);
	Gura_AssignMethod(wx_App, MacPrintFile);
	Gura_AssignMethod(wx_App, MacReopenApp);
	Gura_AssignMethod(wx_App, OSXIsGUIApplication);
}

Gura_ImplementDescendantCreator(wx_App)
{
	return new Object_wx_App((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
