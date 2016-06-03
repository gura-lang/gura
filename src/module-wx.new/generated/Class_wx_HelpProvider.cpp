//----------------------------------------------------------------------------
// wxHelpProvider
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHelpProvider
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHelpProvider
//----------------------------------------------------------------------------
Object_wx_HelpProvider::~Object_wx_HelpProvider()
{
}

Object *Object_wx_HelpProvider::Clone() const
{
	return nullptr;
}

String Object_wx_HelpProvider::ToString(bool exprFlag)
{
	String rtn("<wx.HelpProvider:");
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
Gura_DeclareMethodAlias(wx_HelpProvider, __AddHelp, "AddHelp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HelpProvider, __AddHelp)
{
	Object_wx_HelpProvider *pThis = Object_wx_HelpProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindowBase* window = arg.GetNumber(0)
	//const wxString& text = arg.GetNumber(1)
	//pThis->GetEntity()->AddHelp();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HelpProvider, __AddHelp_1, "AddHelp_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HelpProvider, __AddHelp_1)
{
	Object_wx_HelpProvider *pThis = Object_wx_HelpProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindowID id = arg.GetNumber(0)
	//const wxString& text = arg.GetNumber(1)
	//pThis->GetEntity()->AddHelp();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HelpProvider, __Get, "Get")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HelpProvider, __Get)
{
	Object_wx_HelpProvider *pThis = Object_wx_HelpProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Get();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HelpProvider, __GetHelp, "GetHelp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HelpProvider, __GetHelp)
{
	Object_wx_HelpProvider *pThis = Object_wx_HelpProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxWindowBase* window = arg.GetNumber(0)
	//pThis->GetEntity()->GetHelp();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HelpProvider, __RemoveHelp, "RemoveHelp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HelpProvider, __RemoveHelp)
{
	Object_wx_HelpProvider *pThis = Object_wx_HelpProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindowBase* window = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveHelp();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HelpProvider, __Set, "Set")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "helpProvider", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HelpProvider, __Set)
{
	Object_wx_HelpProvider *pThis = Object_wx_HelpProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxHelpProvider* helpProvider = arg.GetNumber(0)
	//pThis->GetEntity()->Set();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HelpProvider, __ShowHelp, "ShowHelp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HelpProvider, __ShowHelp)
{
	Object_wx_HelpProvider *pThis = Object_wx_HelpProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindowBase* window = arg.GetNumber(0)
	//pThis->GetEntity()->ShowHelp();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HelpProvider, __ShowHelpAtPoint, "ShowHelpAtPoint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "point", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "origin", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HelpProvider, __ShowHelpAtPoint)
{
	Object_wx_HelpProvider *pThis = Object_wx_HelpProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindowBase* window = arg.GetNumber(0)
	//const wxPoint& point = arg.GetNumber(1)
	//wxHelpEvent::Origin origin = arg.GetNumber(2)
	//pThis->GetEntity()->ShowHelpAtPoint();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHelpProvider
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HelpProvider)
{
	// Class assignment
	Gura_AssignValueEx("HelpProvider", Reference());
	// Method assignment
	Gura_AssignMethod(wx_HelpProvider, __AddHelp);
	Gura_AssignMethod(wx_HelpProvider, __AddHelp_1);
	Gura_AssignMethod(wx_HelpProvider, __Get);
	Gura_AssignMethod(wx_HelpProvider, __GetHelp);
	Gura_AssignMethod(wx_HelpProvider, __RemoveHelp);
	Gura_AssignMethod(wx_HelpProvider, __Set);
	Gura_AssignMethod(wx_HelpProvider, __ShowHelp);
	Gura_AssignMethod(wx_HelpProvider, __ShowHelpAtPoint);
}

Gura_ImplementDescendantCreator(wx_HelpProvider)
{
	return new Object_wx_HelpProvider((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
