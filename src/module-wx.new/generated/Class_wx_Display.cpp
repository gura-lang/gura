//----------------------------------------------------------------------------
// wxDisplay
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDisplay
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDisplay
//----------------------------------------------------------------------------
Object_wx_Display::~Object_wx_Display()
{
}

Object *Object_wx_Display::Clone() const
{
	return nullptr;
}

String Object_wx_Display::ToString(bool exprFlag)
{
	String rtn("<wx.Display:");
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
Gura_DeclareMethod(wx_Display, wxDisplay)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Display, wxDisplay)
{
	Signal &sig = env.GetSignal();
	Object_wx_Display *pThis = Object_wx_Display::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//pThis->GetEntity()->wxDisplay();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Display, ~wxDisplay)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Display, ~wxDisplay)
{
	Signal &sig = env.GetSignal();
	Object_wx_Display *pThis = Object_wx_Display::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxDisplay();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Display, ChangeMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Display, ChangeMode)
{
	Signal &sig = env.GetSignal();
	Object_wx_Display *pThis = Object_wx_Display::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int mode = arg.GetNumber(0)
	//pThis->GetEntity()->ChangeMode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Display, GetClientArea)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Display, GetClientArea)
{
	Signal &sig = env.GetSignal();
	Object_wx_Display *pThis = Object_wx_Display::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetClientArea();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Display, GetCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Display, GetCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_Display *pThis = Object_wx_Display::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Display, GetCurrentMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Display, GetCurrentMode)
{
	Signal &sig = env.GetSignal();
	Object_wx_Display *pThis = Object_wx_Display::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetCurrentMode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Display, GetFromPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Display, GetFromPoint)
{
	Signal &sig = env.GetSignal();
	Object_wx_Display *pThis = Object_wx_Display::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->GetFromPoint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Display, GetFromWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Display, GetFromWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_Display *pThis = Object_wx_Display::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//pThis->GetEntity()->GetFromWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Display, GetGeometry)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Display, GetGeometry)
{
	Signal &sig = env.GetSignal();
	Object_wx_Display *pThis = Object_wx_Display::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetGeometry();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Display, GetModes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Display, GetModes)
{
	Signal &sig = env.GetSignal();
	Object_wx_Display *pThis = Object_wx_Display::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int mode = arg.GetNumber(0)
	//pThis->GetEntity()->GetModes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Display, GetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Display, GetName)
{
	Signal &sig = env.GetSignal();
	Object_wx_Display *pThis = Object_wx_Display::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Display, IsPrimary)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Display, IsPrimary)
{
	Signal &sig = env.GetSignal();
	Object_wx_Display *pThis = Object_wx_Display::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsPrimary();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDisplay
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Display)
{
	Gura_AssignMethod(wx_Display, wxDisplay);
	Gura_AssignMethod(wx_Display, ~wxDisplay);
	Gura_AssignMethod(wx_Display, ChangeMode);
	Gura_AssignMethod(wx_Display, GetClientArea);
	Gura_AssignMethod(wx_Display, GetCount);
	Gura_AssignMethod(wx_Display, GetCurrentMode);
	Gura_AssignMethod(wx_Display, GetFromPoint);
	Gura_AssignMethod(wx_Display, GetFromWindow);
	Gura_AssignMethod(wx_Display, GetGeometry);
	Gura_AssignMethod(wx_Display, GetModes);
	Gura_AssignMethod(wx_Display, GetName);
	Gura_AssignMethod(wx_Display, IsPrimary);
}

Gura_ImplementDescendantCreator(wx_Display)
{
	return new Object_wx_Display((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
