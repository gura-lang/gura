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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_HelpControllerHelpProvider, wxHelpControllerHelpProvider)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "hc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HelpControllerHelpProvider, wxHelpControllerHelpProvider)
{
	Signal &sig = env.GetSignal();
	Object_wx_HelpControllerHelpProvider *pThis = Object_wx_HelpControllerHelpProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int hc = arg.GetNumber(0)
	//pThis->GetEntity()->wxHelpControllerHelpProvider();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HelpControllerHelpProvider, GetHelpController)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HelpControllerHelpProvider, GetHelpController)
{
	Signal &sig = env.GetSignal();
	Object_wx_HelpControllerHelpProvider *pThis = Object_wx_HelpControllerHelpProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetHelpController();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HelpControllerHelpProvider, SetHelpController)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "hc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HelpControllerHelpProvider, SetHelpController)
{
	Signal &sig = env.GetSignal();
	Object_wx_HelpControllerHelpProvider *pThis = Object_wx_HelpControllerHelpProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int hc = arg.GetNumber(0)
	//pThis->GetEntity()->SetHelpController();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHelpControllerHelpProvider
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HelpControllerHelpProvider)
{
	Gura_AssignMethod(wx_HelpControllerHelpProvider, wxHelpControllerHelpProvider);
	Gura_AssignMethod(wx_HelpControllerHelpProvider, GetHelpController);
	Gura_AssignMethod(wx_HelpControllerHelpProvider, SetHelpController);
}

Gura_ImplementDescendantCreator(wx_HelpControllerHelpProvider)
{
	return new Object_wx_HelpControllerHelpProvider((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
