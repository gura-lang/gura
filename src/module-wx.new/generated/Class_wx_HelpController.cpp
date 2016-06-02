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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_HelpController, wxHelpController)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parentWindow", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HelpController, wxHelpController)
{
	Object_wx_HelpController *pThis = Object_wx_HelpController::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parentWindow = arg.GetNumber(0)
	//pThis->GetEntity()->wxHelpController();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHelpController
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HelpController)
{
	Gura_AssignMethod(wx_HelpController, wxHelpController);
}

Gura_ImplementDescendantCreator(wx_HelpController)
{
	return new Object_wx_HelpController((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
