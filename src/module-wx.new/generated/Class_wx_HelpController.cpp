//----------------------------------------------------------------------------
// wxHelpController
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHelpController
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHelpController
//----------------------------------------------------------------------------
Object_wx_HelpController::~Object_wx_HelpController()
{
}

Object *Object_wx_HelpController::Clone() const
{
	return nullptr;
}

String Object_wx_HelpController::ToString(bool exprFlag)
{
	String rtn("<wx.HelpController:");
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
Gura_DeclareFunctionAlias(__wxHelpController, "wxHelpController")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parentWindow", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxHelpController)
{
	//int parentWindow = arg.GetNumber(0)
	//wxHelpController();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHelpController
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HelpController)
{
	// Constructor assignment
	Gura_AssignFunction(__wxHelpController);
}

Gura_ImplementDescendantCreator(wx_HelpController)
{
	return new Object_wx_HelpController((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
