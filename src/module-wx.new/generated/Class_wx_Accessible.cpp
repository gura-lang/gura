//----------------------------------------------------------------------------
// wxAccessible
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAccessible
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAccessible
//----------------------------------------------------------------------------
Object_wx_Accessible::~Object_wx_Accessible()
{
}

Object *Object_wx_Accessible::Clone() const
{
	return nullptr;
}

String Object_wx_Accessible::ToString(bool exprFlag)
{
	String rtn("<wx.Accessible:");
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
Gura_DeclareFunctionAlias(__Accessible, "Accessible")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Accessible));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Accessible)
{
	//wxWindow* win = arg.GetNumber(0)
	//wxAccessible();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Accessible, __DoDefaultAction, "DoDefaultAction")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "childId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, __DoDefaultAction)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int childId = arg.GetNumber(0)
	//pThis->GetEntity()->DoDefaultAction();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Accessible, __GetChild, "GetChild")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "childId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "child", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, __GetChild)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int childId = arg.GetNumber(0)
	//wxAccessible** child = arg.GetNumber(1)
	//pThis->GetEntity()->GetChild();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Accessible, __GetChildCount, "GetChildCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "childCount", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, __GetChildCount)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int* childCount = arg.GetNumber(0)
	//pThis->GetEntity()->GetChildCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Accessible, __GetDefaultAction, "GetDefaultAction")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "childId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "actionName", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, __GetDefaultAction)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int childId = arg.GetNumber(0)
	//wxString* actionName = arg.GetNumber(1)
	//pThis->GetEntity()->GetDefaultAction();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Accessible, __GetDescription, "GetDescription")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "childId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "description", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, __GetDescription)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int childId = arg.GetNumber(0)
	//wxString* description = arg.GetNumber(1)
	//pThis->GetEntity()->GetDescription();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Accessible, __GetFocus, "GetFocus")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "childId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "child", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, __GetFocus)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int* childId = arg.GetNumber(0)
	//wxAccessible** child = arg.GetNumber(1)
	//pThis->GetEntity()->GetFocus();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Accessible, __GetHelpText, "GetHelpText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "childId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "helpText", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, __GetHelpText)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int childId = arg.GetNumber(0)
	//wxString* helpText = arg.GetNumber(1)
	//pThis->GetEntity()->GetHelpText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Accessible, __GetKeyboardShortcut, "GetKeyboardShortcut")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "childId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "shortcut", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, __GetKeyboardShortcut)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int childId = arg.GetNumber(0)
	//wxString* shortcut = arg.GetNumber(1)
	//pThis->GetEntity()->GetKeyboardShortcut();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Accessible, __GetLocation, "GetLocation")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "elementId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, __GetLocation)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRect& rect = arg.GetNumber(0)
	//int elementId = arg.GetNumber(1)
	//pThis->GetEntity()->GetLocation();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Accessible, __GetName, "GetName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "childId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, __GetName)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int childId = arg.GetNumber(0)
	//wxString* name = arg.GetNumber(1)
	//pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Accessible, __GetParent, "GetParent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, __GetParent)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxAccessible** parent = arg.GetNumber(0)
	//pThis->GetEntity()->GetParent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Accessible, __GetRole, "GetRole")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "childId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "role", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, __GetRole)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int childId = arg.GetNumber(0)
	//wxAccRole* role = arg.GetNumber(1)
	//pThis->GetEntity()->GetRole();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Accessible, __GetSelections, "GetSelections")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "selections", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, __GetSelections)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxVariant* selections = arg.GetNumber(0)
	//pThis->GetEntity()->GetSelections();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Accessible, __GetState, "GetState")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "childId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "state", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, __GetState)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int childId = arg.GetNumber(0)
	//long* state = arg.GetNumber(1)
	//pThis->GetEntity()->GetState();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Accessible, __GetValue, "GetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "childId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "strValue", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, __GetValue)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int childId = arg.GetNumber(0)
	//wxString* strValue = arg.GetNumber(1)
	//pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Accessible, __GetWindow, "GetWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Accessible, __GetWindow)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWindow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Accessible, __HitTest, "HitTest")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "childId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "childObject", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, __HitTest)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint& pt = arg.GetNumber(0)
	//int* childId = arg.GetNumber(1)
	//wxAccessible** childObject = arg.GetNumber(2)
	//pThis->GetEntity()->HitTest();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Accessible, __Navigate, "Navigate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "navDir", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fromId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "toId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "toObject", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, __Navigate)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxNavDir navDir = arg.GetNumber(0)
	//int fromId = arg.GetNumber(1)
	//int* toId = arg.GetNumber(2)
	//wxAccessible** toObject = arg.GetNumber(3)
	//pThis->GetEntity()->Navigate();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Accessible, __NotifyEvent, "NotifyEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "eventType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "objectType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "objectType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, __NotifyEvent)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int eventType = arg.GetNumber(0)
	//wxWindow* window = arg.GetNumber(1)
	//wxAccObject objectType = arg.GetNumber(2)
	//int objectType = arg.GetNumber(3)
	//pThis->GetEntity()->NotifyEvent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Accessible, __Select, "Select")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "childId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "selectFlags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, __Select)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int childId = arg.GetNumber(0)
	//wxAccSelectionFlags selectFlags = arg.GetNumber(1)
	//pThis->GetEntity()->Select();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Accessible, __SetWindow, "SetWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, __SetWindow)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* window = arg.GetNumber(0)
	//pThis->GetEntity()->SetWindow();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxAccessible
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Accessible)
{
	// Constructor assignment
	Gura_AssignFunction(__Accessible);
	// Method assignment
	Gura_AssignMethod(wx_Accessible, __DoDefaultAction);
	Gura_AssignMethod(wx_Accessible, __GetChild);
	Gura_AssignMethod(wx_Accessible, __GetChildCount);
	Gura_AssignMethod(wx_Accessible, __GetDefaultAction);
	Gura_AssignMethod(wx_Accessible, __GetDescription);
	Gura_AssignMethod(wx_Accessible, __GetFocus);
	Gura_AssignMethod(wx_Accessible, __GetHelpText);
	Gura_AssignMethod(wx_Accessible, __GetKeyboardShortcut);
	Gura_AssignMethod(wx_Accessible, __GetLocation);
	Gura_AssignMethod(wx_Accessible, __GetName);
	Gura_AssignMethod(wx_Accessible, __GetParent);
	Gura_AssignMethod(wx_Accessible, __GetRole);
	Gura_AssignMethod(wx_Accessible, __GetSelections);
	Gura_AssignMethod(wx_Accessible, __GetState);
	Gura_AssignMethod(wx_Accessible, __GetValue);
	Gura_AssignMethod(wx_Accessible, __GetWindow);
	Gura_AssignMethod(wx_Accessible, __HitTest);
	Gura_AssignMethod(wx_Accessible, __Navigate);
	Gura_AssignMethod(wx_Accessible, __NotifyEvent);
	Gura_AssignMethod(wx_Accessible, __Select);
	Gura_AssignMethod(wx_Accessible, __SetWindow);
}

Gura_ImplementDescendantCreator(wx_Accessible)
{
	return new Object_wx_Accessible((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
