//----------------------------------------------------------------------------
// wxSplashScreen
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSplashScreen
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSplashScreen
//----------------------------------------------------------------------------
Object_wx_SplashScreen::~Object_wx_SplashScreen()
{
}

Object *Object_wx_SplashScreen::Clone() const
{
	return nullptr;
}

String Object_wx_SplashScreen::ToString(bool exprFlag)
{
	String rtn("<wx.SplashScreen:");
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
Gura_DeclareMethod(wx_SplashScreen, wxSplashScreen)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "splashStyle", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "milliseconds", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SplashScreen, wxSplashScreen)
{
	Object_wx_SplashScreen *pThis = Object_wx_SplashScreen::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bitmap = arg.GetNumber(0)
	//int splashStyle = arg.GetNumber(1)
	//int milliseconds = arg.GetNumber(2)
	//int parent = arg.GetNumber(3)
	//int id = arg.GetNumber(4)
	//int pos = arg.GetNumber(5)
	//int size = arg.GetNumber(6)
	//int style = arg.GetNumber(7)
	//pThis->GetEntity()->wxSplashScreen();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SplashScreen, GetSplashStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SplashScreen, GetSplashStyle)
{
	Object_wx_SplashScreen *pThis = Object_wx_SplashScreen::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSplashStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SplashScreen, GetSplashWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SplashScreen, GetSplashWindow)
{
	Object_wx_SplashScreen *pThis = Object_wx_SplashScreen::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSplashWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SplashScreen, GetTimeout)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SplashScreen, GetTimeout)
{
	Object_wx_SplashScreen *pThis = Object_wx_SplashScreen::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTimeout();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SplashScreen, OnCloseWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SplashScreen, OnCloseWindow)
{
	Object_wx_SplashScreen *pThis = Object_wx_SplashScreen::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->OnCloseWindow();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSplashScreen
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SplashScreen)
{
	Gura_AssignMethod(wx_SplashScreen, wxSplashScreen);
	Gura_AssignMethod(wx_SplashScreen, GetSplashStyle);
	Gura_AssignMethod(wx_SplashScreen, GetSplashWindow);
	Gura_AssignMethod(wx_SplashScreen, GetTimeout);
	Gura_AssignMethod(wx_SplashScreen, OnCloseWindow);
}

Gura_ImplementDescendantCreator(wx_SplashScreen)
{
	return new Object_wx_SplashScreen((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
