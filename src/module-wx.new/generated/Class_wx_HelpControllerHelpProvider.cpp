//----------------------------------------------------------------------------
// wxHelpControllerHelpProvider
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHelpControllerHelpProvider
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHelpControllerHelpProvider
//----------------------------------------------------------------------------
Object_wx_HelpControllerHelpProvider::~Object_wx_HelpControllerHelpProvider()
{
}

Object *Object_wx_HelpControllerHelpProvider::Clone() const
{
	return nullptr;
}

String Object_wx_HelpControllerHelpProvider::ToString(bool exprFlag)
{
	String rtn("<wx.HelpControllerHelpProvider:");
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
Gura_DeclareFunctionAlias(__HelpControllerHelpProvider, "HelpControllerHelpProvider")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "hc", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_HelpControllerHelpProvider));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__HelpControllerHelpProvider)
{
	//wxHelpControllerBase* hc = arg.GetNumber(0)
	//wxHelpControllerHelpProvider(hc);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_HelpControllerHelpProvider, __GetHelpController, "GetHelpController")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_HelpControllerHelpProvider, __GetHelpController)
{
	Object_wx_HelpControllerHelpProvider *pThis = Object_wx_HelpControllerHelpProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxHelpControllerBase* _rtn = pThis->GetEntity()->GetHelpController();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HelpControllerHelpProvider, __SetHelpController, "SetHelpController")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "hc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HelpControllerHelpProvider, __SetHelpController)
{
	Object_wx_HelpControllerHelpProvider *pThis = Object_wx_HelpControllerHelpProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxHelpControllerBase* hc = arg.GetNumber(0)
	//pThis->GetEntity()->SetHelpController(hc);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHelpControllerHelpProvider
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HelpControllerHelpProvider)
{
	// Constructor assignment
	Gura_AssignFunction(__HelpControllerHelpProvider);
	// Method assignment
	Gura_AssignMethod(wx_HelpControllerHelpProvider, __GetHelpController);
	Gura_AssignMethod(wx_HelpControllerHelpProvider, __SetHelpController);
}

Gura_ImplementDescendantCreator(wx_HelpControllerHelpProvider)
{
	return new Object_wx_HelpControllerHelpProvider((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
