//----------------------------------------------------------------------------
// wxToolTip
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxToolTip
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxToolTip
//----------------------------------------------------------------------------
Object_wx_ToolTip::~Object_wx_ToolTip()
{
}

Object *Object_wx_ToolTip::Clone() const
{
	return nullptr;
}

String Object_wx_ToolTip::ToString(bool exprFlag)
{
	String rtn("<wx.ToolTip:");
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
Gura_DeclareFunctionAlias(__wxToolTip, "wxToolTip")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tip", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_ToolTip));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxToolTip)
{
	//int tip = arg.GetNumber(0)
	//wxToolTip();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_ToolTip, __Enable, "Enable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolTip, __Enable)
{
	Object_wx_ToolTip *pThis = Object_wx_ToolTip::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->Enable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolTip, __GetTip, "GetTip")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolTip, __GetTip)
{
	Object_wx_ToolTip *pThis = Object_wx_ToolTip::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTip();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolTip, __GetWindow, "GetWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolTip, __GetWindow)
{
	Object_wx_ToolTip *pThis = Object_wx_ToolTip::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWindow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolTip, __SetAutoPop, "SetAutoPop")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "msecs", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolTip, __SetAutoPop)
{
	Object_wx_ToolTip *pThis = Object_wx_ToolTip::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int msecs = arg.GetNumber(0)
	//pThis->GetEntity()->SetAutoPop();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolTip, __SetDelay, "SetDelay")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "msecs", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolTip, __SetDelay)
{
	Object_wx_ToolTip *pThis = Object_wx_ToolTip::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int msecs = arg.GetNumber(0)
	//pThis->GetEntity()->SetDelay();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolTip, __SetMaxWidth, "SetMaxWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolTip, __SetMaxWidth)
{
	Object_wx_ToolTip *pThis = Object_wx_ToolTip::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//pThis->GetEntity()->SetMaxWidth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolTip, __SetReshow, "SetReshow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "msecs", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolTip, __SetReshow)
{
	Object_wx_ToolTip *pThis = Object_wx_ToolTip::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int msecs = arg.GetNumber(0)
	//pThis->GetEntity()->SetReshow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolTip, __SetTip, "SetTip")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tip", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolTip, __SetTip)
{
	Object_wx_ToolTip *pThis = Object_wx_ToolTip::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tip = arg.GetNumber(0)
	//pThis->GetEntity()->SetTip();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxToolTip
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ToolTip)
{
	// Constructor assignment
	Gura_AssignFunction(__wxToolTip);
	// Method assignment
	Gura_AssignMethod(wx_ToolTip, __Enable);
	Gura_AssignMethod(wx_ToolTip, __GetTip);
	Gura_AssignMethod(wx_ToolTip, __GetWindow);
	Gura_AssignMethod(wx_ToolTip, __SetAutoPop);
	Gura_AssignMethod(wx_ToolTip, __SetDelay);
	Gura_AssignMethod(wx_ToolTip, __SetMaxWidth);
	Gura_AssignMethod(wx_ToolTip, __SetReshow);
	Gura_AssignMethod(wx_ToolTip, __SetTip);
}

Gura_ImplementDescendantCreator(wx_ToolTip)
{
	return new Object_wx_ToolTip((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
