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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_ToolTip, wxToolTip)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tip", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolTip, wxToolTip)
{
	Object_wx_ToolTip *pThis = Object_wx_ToolTip::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tip = arg.GetNumber(0)
	//pThis->GetEntity()->wxToolTip();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolTip, Enable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolTip, Enable)
{
	Object_wx_ToolTip *pThis = Object_wx_ToolTip::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->Enable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolTip, GetTip)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolTip, GetTip)
{
	Object_wx_ToolTip *pThis = Object_wx_ToolTip::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTip();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolTip, GetWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolTip, GetWindow)
{
	Object_wx_ToolTip *pThis = Object_wx_ToolTip::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolTip, SetAutoPop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "msecs", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolTip, SetAutoPop)
{
	Object_wx_ToolTip *pThis = Object_wx_ToolTip::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int msecs = arg.GetNumber(0)
	//pThis->GetEntity()->SetAutoPop();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolTip, SetDelay)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "msecs", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolTip, SetDelay)
{
	Object_wx_ToolTip *pThis = Object_wx_ToolTip::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int msecs = arg.GetNumber(0)
	//pThis->GetEntity()->SetDelay();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolTip, SetMaxWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolTip, SetMaxWidth)
{
	Object_wx_ToolTip *pThis = Object_wx_ToolTip::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//pThis->GetEntity()->SetMaxWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolTip, SetReshow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "msecs", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolTip, SetReshow)
{
	Object_wx_ToolTip *pThis = Object_wx_ToolTip::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int msecs = arg.GetNumber(0)
	//pThis->GetEntity()->SetReshow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolTip, SetTip)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tip", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolTip, SetTip)
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
	Gura_AssignMethod(wx_ToolTip, wxToolTip);
	Gura_AssignMethod(wx_ToolTip, Enable);
	Gura_AssignMethod(wx_ToolTip, GetTip);
	Gura_AssignMethod(wx_ToolTip, GetWindow);
	Gura_AssignMethod(wx_ToolTip, SetAutoPop);
	Gura_AssignMethod(wx_ToolTip, SetDelay);
	Gura_AssignMethod(wx_ToolTip, SetMaxWidth);
	Gura_AssignMethod(wx_ToolTip, SetReshow);
	Gura_AssignMethod(wx_ToolTip, SetTip);
}

Gura_ImplementDescendantCreator(wx_ToolTip)
{
	return new Object_wx_ToolTip((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
