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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__SplashScreen, "SplashScreen")
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
	SetClassToConstruct(Gura_UserClass(wx_SplashScreen));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__SplashScreen)
{
	//const wxBitmap& bitmap = arg.GetNumber(0)
	//long splashStyle = arg.GetNumber(1)
	//int milliseconds = arg.GetNumber(2)
	//wxWindow* parent = arg.GetNumber(3)
	//wxWindowID id = arg.GetNumber(4)
	//const wxPoint& pos = arg.GetNumber(5)
	//const wxSize& size = arg.GetNumber(6)
	//long style = arg.GetNumber(7)
	//wxSplashScreen();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_SplashScreen, __GetSplashStyle, "GetSplashStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SplashScreen, __GetSplashStyle)
{
	Object_wx_SplashScreen *pThis = Object_wx_SplashScreen::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSplashStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SplashScreen, __GetSplashWindow, "GetSplashWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SplashScreen, __GetSplashWindow)
{
	Object_wx_SplashScreen *pThis = Object_wx_SplashScreen::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSplashWindow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SplashScreen, __GetTimeout, "GetTimeout")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SplashScreen, __GetTimeout)
{
	Object_wx_SplashScreen *pThis = Object_wx_SplashScreen::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTimeout();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SplashScreen, __OnCloseWindow, "OnCloseWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SplashScreen, __OnCloseWindow)
{
	Object_wx_SplashScreen *pThis = Object_wx_SplashScreen::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCloseEvent& event = arg.GetNumber(0)
	//pThis->GetEntity()->OnCloseWindow();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSplashScreen
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SplashScreen)
{
	// Constructor assignment
	Gura_AssignFunction(__SplashScreen);
	// Method assignment
	Gura_AssignMethod(wx_SplashScreen, __GetSplashStyle);
	Gura_AssignMethod(wx_SplashScreen, __GetSplashWindow);
	Gura_AssignMethod(wx_SplashScreen, __GetTimeout);
	Gura_AssignMethod(wx_SplashScreen, __OnCloseWindow);
}

Gura_ImplementDescendantCreator(wx_SplashScreen)
{
	return new Object_wx_SplashScreen((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
