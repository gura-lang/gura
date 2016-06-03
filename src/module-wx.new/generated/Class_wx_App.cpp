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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxApp, "wxApp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(__wxApp)
{
	//wxApp();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_App, __GetDisplayMode, "GetDisplayMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_App, __GetDisplayMode)
{
	Object_wx_App *pThis = Object_wx_App::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDisplayMode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_App, __GetExitOnFrameDelete, "GetExitOnFrameDelete")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_App, __GetExitOnFrameDelete)
{
	Object_wx_App *pThis = Object_wx_App::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetExitOnFrameDelete();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_App, __GetLayoutDirection, "GetLayoutDirection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_App, __GetLayoutDirection)
{
	Object_wx_App *pThis = Object_wx_App::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLayoutDirection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_App, __GetUseBestVisual, "GetUseBestVisual")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_App, __GetUseBestVisual)
{
	Object_wx_App *pThis = Object_wx_App::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetUseBestVisual();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_App, __GetTopWindow, "GetTopWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_App, __GetTopWindow)
{
	Object_wx_App *pThis = Object_wx_App::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTopWindow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_App, __IsActive, "IsActive")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_App, __IsActive)
{
	Object_wx_App *pThis = Object_wx_App::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsActive();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_App, __SafeYield, "SafeYield")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "onlyIfNeeded", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_App, __SafeYield)
{
	Object_wx_App *pThis = Object_wx_App::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//int onlyIfNeeded = arg.GetNumber(1)
	//pThis->GetEntity()->SafeYield();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_App, __SafeYieldFor, "SafeYieldFor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "eventsToProcess", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_App, __SafeYieldFor)
{
	Object_wx_App *pThis = Object_wx_App::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//int eventsToProcess = arg.GetNumber(1)
	//pThis->GetEntity()->SafeYieldFor();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_App, __ProcessMessage, "ProcessMessage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "msg", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_App, __ProcessMessage)
{
	Object_wx_App *pThis = Object_wx_App::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int msg = arg.GetNumber(0)
	//pThis->GetEntity()->ProcessMessage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_App, __SetDisplayMode, "SetDisplayMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "info", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_App, __SetDisplayMode)
{
	Object_wx_App *pThis = Object_wx_App::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int info = arg.GetNumber(0)
	//pThis->GetEntity()->SetDisplayMode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_App, __SetExitOnFrameDelete, "SetExitOnFrameDelete")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_App, __SetExitOnFrameDelete)
{
	Object_wx_App *pThis = Object_wx_App::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->SetExitOnFrameDelete();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_App, __SetNativeTheme, "SetNativeTheme")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "theme", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_App, __SetNativeTheme)
{
	Object_wx_App *pThis = Object_wx_App::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int theme = arg.GetNumber(0)
	//pThis->GetEntity()->SetNativeTheme();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_App, __SetTopWindow, "SetTopWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_App, __SetTopWindow)
{
	Object_wx_App *pThis = Object_wx_App::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//pThis->GetEntity()->SetTopWindow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_App, __SetUseBestVisual, "SetUseBestVisual")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "forceTrueColour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_App, __SetUseBestVisual)
{
	Object_wx_App *pThis = Object_wx_App::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//int forceTrueColour = arg.GetNumber(1)
	//pThis->GetEntity()->SetUseBestVisual();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_App, __MacNewFile, "MacNewFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_App, __MacNewFile)
{
	Object_wx_App *pThis = Object_wx_App::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->MacNewFile();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_App, __MacOpenFiles, "MacOpenFiles")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fileNames", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_App, __MacOpenFiles)
{
	Object_wx_App *pThis = Object_wx_App::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int fileNames = arg.GetNumber(0)
	//pThis->GetEntity()->MacOpenFiles();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_App, __MacOpenFile, "MacOpenFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fileName", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_App, __MacOpenFile)
{
	Object_wx_App *pThis = Object_wx_App::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int fileName = arg.GetNumber(0)
	//pThis->GetEntity()->MacOpenFile();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_App, __MacOpenURL, "MacOpenURL")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "url", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_App, __MacOpenURL)
{
	Object_wx_App *pThis = Object_wx_App::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int url = arg.GetNumber(0)
	//pThis->GetEntity()->MacOpenURL();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_App, __MacPrintFile, "MacPrintFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fileName", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_App, __MacPrintFile)
{
	Object_wx_App *pThis = Object_wx_App::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int fileName = arg.GetNumber(0)
	//pThis->GetEntity()->MacPrintFile();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_App, __MacReopenApp, "MacReopenApp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_App, __MacReopenApp)
{
	Object_wx_App *pThis = Object_wx_App::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->MacReopenApp();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_App, __OSXIsGUIApplication, "OSXIsGUIApplication")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_App, __OSXIsGUIApplication)
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
	// Constructor assignment
	Gura_AssignFunction(__wxApp);
	// Method assignment
	Gura_AssignMethod(wx_App, __GetDisplayMode);
	Gura_AssignMethod(wx_App, __GetExitOnFrameDelete);
	Gura_AssignMethod(wx_App, __GetLayoutDirection);
	Gura_AssignMethod(wx_App, __GetUseBestVisual);
	Gura_AssignMethod(wx_App, __GetTopWindow);
	Gura_AssignMethod(wx_App, __IsActive);
	Gura_AssignMethod(wx_App, __SafeYield);
	Gura_AssignMethod(wx_App, __SafeYieldFor);
	Gura_AssignMethod(wx_App, __ProcessMessage);
	Gura_AssignMethod(wx_App, __SetDisplayMode);
	Gura_AssignMethod(wx_App, __SetExitOnFrameDelete);
	Gura_AssignMethod(wx_App, __SetNativeTheme);
	Gura_AssignMethod(wx_App, __SetTopWindow);
	Gura_AssignMethod(wx_App, __SetUseBestVisual);
	Gura_AssignMethod(wx_App, __MacNewFile);
	Gura_AssignMethod(wx_App, __MacOpenFiles);
	Gura_AssignMethod(wx_App, __MacOpenFile);
	Gura_AssignMethod(wx_App, __MacOpenURL);
	Gura_AssignMethod(wx_App, __MacPrintFile);
	Gura_AssignMethod(wx_App, __MacReopenApp);
	Gura_AssignMethod(wx_App, __OSXIsGUIApplication);
}

Gura_ImplementDescendantCreator(wx_App)
{
	return new Object_wx_App((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
