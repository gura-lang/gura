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

//----------------------------------------------------------------------------
// Class implementation for wxSplashScreen
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SplashScreen)
{
}

Gura_ImplementDescendantCreator(wx_SplashScreen)
{
	return new Object_wx_SplashScreen((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
