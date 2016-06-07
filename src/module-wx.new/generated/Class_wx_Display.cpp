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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__Display, "Display")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Display));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Display)
{
	//unsigned int index = arg.GetNumber(0)
	//wxDisplay(index);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Display, __ChangeMode, "ChangeMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Display, __ChangeMode)
{
	Object_wx_Display *pThis = Object_wx_Display::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxVideoMode& mode = arg.GetNumber(0)
	//pThis->GetEntity()->ChangeMode(mode);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Display, __GetClientArea, "GetClientArea")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Display, __GetClientArea)
{
	Object_wx_Display *pThis = Object_wx_Display::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetClientArea();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Display, __GetCount, "GetCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Display, __GetCount)
{
	Object_wx_Display *pThis = Object_wx_Display::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Display, __GetCurrentMode, "GetCurrentMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Display, __GetCurrentMode)
{
	Object_wx_Display *pThis = Object_wx_Display::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCurrentMode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Display, __GetFromPoint, "GetFromPoint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Display, __GetFromPoint)
{
	Object_wx_Display *pThis = Object_wx_Display::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint& pt = arg.GetNumber(0)
	//pThis->GetEntity()->GetFromPoint(pt);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Display, __GetFromWindow, "GetFromWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Display, __GetFromWindow)
{
	Object_wx_Display *pThis = Object_wx_Display::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxWindow* win = arg.GetNumber(0)
	//pThis->GetEntity()->GetFromWindow(win);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Display, __GetGeometry, "GetGeometry")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Display, __GetGeometry)
{
	Object_wx_Display *pThis = Object_wx_Display::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetGeometry();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Display, __GetModes, "GetModes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Display, __GetModes)
{
	Object_wx_Display *pThis = Object_wx_Display::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxVideoMode& mode = arg.GetNumber(0)
	//pThis->GetEntity()->GetModes(mode);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Display, __GetName, "GetName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Display, __GetName)
{
	Object_wx_Display *pThis = Object_wx_Display::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Display, __IsPrimary, "IsPrimary")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Display, __IsPrimary)
{
	Object_wx_Display *pThis = Object_wx_Display::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsPrimary();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDisplay
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Display)
{
	// Constructor assignment
	Gura_AssignFunction(__Display);
	// Method assignment
	Gura_AssignMethod(wx_Display, __ChangeMode);
	Gura_AssignMethod(wx_Display, __GetClientArea);
	Gura_AssignMethod(wx_Display, __GetCount);
	Gura_AssignMethod(wx_Display, __GetCurrentMode);
	Gura_AssignMethod(wx_Display, __GetFromPoint);
	Gura_AssignMethod(wx_Display, __GetFromWindow);
	Gura_AssignMethod(wx_Display, __GetGeometry);
	Gura_AssignMethod(wx_Display, __GetModes);
	Gura_AssignMethod(wx_Display, __GetName);
	Gura_AssignMethod(wx_Display, __IsPrimary);
}

Gura_ImplementDescendantCreator(wx_Display)
{
	return new Object_wx_Display((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
