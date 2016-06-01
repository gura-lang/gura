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
Gura_DeclareMethod(wx_HelpProvider, ~wxHelpProvider)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HelpProvider, ~wxHelpProvider)
{
	Signal &sig = env.GetSignal();
	Object_wx_HelpProvider *pThis = Object_wx_HelpProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxHelpProvider();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HelpProvider, AddHelp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HelpProvider, AddHelp)
{
	Signal &sig = env.GetSignal();
	Object_wx_HelpProvider *pThis = Object_wx_HelpProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//int text = arg.GetNumber(1)
	//pThis->GetEntity()->AddHelp();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HelpProvider, AddHelp_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HelpProvider, AddHelp_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_HelpProvider *pThis = Object_wx_HelpProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int text = arg.GetNumber(1)
	//pThis->GetEntity()->AddHelp();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HelpProvider, Get)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HelpProvider, Get)
{
	Signal &sig = env.GetSignal();
	Object_wx_HelpProvider *pThis = Object_wx_HelpProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Get();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HelpProvider, GetHelp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HelpProvider, GetHelp)
{
	Signal &sig = env.GetSignal();
	Object_wx_HelpProvider *pThis = Object_wx_HelpProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//pThis->GetEntity()->GetHelp();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HelpProvider, RemoveHelp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HelpProvider, RemoveHelp)
{
	Signal &sig = env.GetSignal();
	Object_wx_HelpProvider *pThis = Object_wx_HelpProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveHelp();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HelpProvider, Set)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "helpProvider", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HelpProvider, Set)
{
	Signal &sig = env.GetSignal();
	Object_wx_HelpProvider *pThis = Object_wx_HelpProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int helpProvider = arg.GetNumber(0)
	//pThis->GetEntity()->Set();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HelpProvider, ShowHelp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HelpProvider, ShowHelp)
{
	Signal &sig = env.GetSignal();
	Object_wx_HelpProvider *pThis = Object_wx_HelpProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//pThis->GetEntity()->ShowHelp();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HelpProvider, ShowHelpAtPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "point", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "origin", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HelpProvider, ShowHelpAtPoint)
{
	Signal &sig = env.GetSignal();
	Object_wx_HelpProvider *pThis = Object_wx_HelpProvider::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//int point = arg.GetNumber(1)
	//int origin = arg.GetNumber(2)
	//pThis->GetEntity()->ShowHelpAtPoint();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHelpProvider
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HelpProvider)
{
	Gura_AssignMethod(wx_HelpProvider, ~wxHelpProvider);
	Gura_AssignMethod(wx_HelpProvider, AddHelp);
	Gura_AssignMethod(wx_HelpProvider, AddHelp_1);
	Gura_AssignMethod(wx_HelpProvider, Get);
	Gura_AssignMethod(wx_HelpProvider, GetHelp);
	Gura_AssignMethod(wx_HelpProvider, RemoveHelp);
	Gura_AssignMethod(wx_HelpProvider, Set);
	Gura_AssignMethod(wx_HelpProvider, ShowHelp);
	Gura_AssignMethod(wx_HelpProvider, ShowHelpAtPoint);
}

Gura_ImplementDescendantCreator(wx_HelpProvider)
{
	return new Object_wx_HelpProvider((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
