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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_Accessible, wxAccessible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, wxAccessible)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//pThis->GetEntity()->wxAccessible();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Accessible, DoDefaultAction)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "childId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, DoDefaultAction)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int childId = arg.GetNumber(0)
	//pThis->GetEntity()->DoDefaultAction();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Accessible, GetChild)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "childId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "child", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, GetChild)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int childId = arg.GetNumber(0)
	//int child = arg.GetNumber(1)
	//pThis->GetEntity()->GetChild();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Accessible, GetChildCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "childCount", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, GetChildCount)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int childCount = arg.GetNumber(0)
	//pThis->GetEntity()->GetChildCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Accessible, GetDefaultAction)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "childId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "actionName", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, GetDefaultAction)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int childId = arg.GetNumber(0)
	//int actionName = arg.GetNumber(1)
	//pThis->GetEntity()->GetDefaultAction();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Accessible, GetDescription)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "childId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "description", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, GetDescription)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int childId = arg.GetNumber(0)
	//int description = arg.GetNumber(1)
	//pThis->GetEntity()->GetDescription();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Accessible, GetFocus)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "childId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "child", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, GetFocus)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int childId = arg.GetNumber(0)
	//int child = arg.GetNumber(1)
	//pThis->GetEntity()->GetFocus();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Accessible, GetHelpText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "childId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "helpText", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, GetHelpText)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int childId = arg.GetNumber(0)
	//int helpText = arg.GetNumber(1)
	//pThis->GetEntity()->GetHelpText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Accessible, GetKeyboardShortcut)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "childId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "shortcut", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, GetKeyboardShortcut)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int childId = arg.GetNumber(0)
	//int shortcut = arg.GetNumber(1)
	//pThis->GetEntity()->GetKeyboardShortcut();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Accessible, GetLocation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "elementId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, GetLocation)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//int elementId = arg.GetNumber(1)
	//pThis->GetEntity()->GetLocation();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Accessible, GetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "childId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, GetName)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int childId = arg.GetNumber(0)
	//int name = arg.GetNumber(1)
	//pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Accessible, GetParent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, GetParent)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//pThis->GetEntity()->GetParent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Accessible, GetRole)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "childId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "role", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, GetRole)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int childId = arg.GetNumber(0)
	//int role = arg.GetNumber(1)
	//pThis->GetEntity()->GetRole();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Accessible, GetSelections)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "selections", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, GetSelections)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int selections = arg.GetNumber(0)
	//pThis->GetEntity()->GetSelections();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Accessible, GetState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "childId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "state", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, GetState)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int childId = arg.GetNumber(0)
	//int state = arg.GetNumber(1)
	//pThis->GetEntity()->GetState();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Accessible, GetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "childId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "strValue", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, GetValue)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int childId = arg.GetNumber(0)
	//int strValue = arg.GetNumber(1)
	//pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Accessible, GetWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Accessible, GetWindow)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Accessible, HitTest)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "childId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "childObject", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, HitTest)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//int childId = arg.GetNumber(1)
	//int childObject = arg.GetNumber(2)
	//pThis->GetEntity()->HitTest();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Accessible, Navigate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "navDir", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fromId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "toId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "toObject", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, Navigate)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int navDir = arg.GetNumber(0)
	//int fromId = arg.GetNumber(1)
	//int toId = arg.GetNumber(2)
	//int toObject = arg.GetNumber(3)
	//pThis->GetEntity()->Navigate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Accessible, NotifyEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "eventType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "objectType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "objectType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, NotifyEvent)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int eventType = arg.GetNumber(0)
	//int window = arg.GetNumber(1)
	//int objectType = arg.GetNumber(2)
	//int objectType = arg.GetNumber(3)
	//pThis->GetEntity()->NotifyEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Accessible, Select)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "childId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "selectFlags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, Select)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int childId = arg.GetNumber(0)
	//int selectFlags = arg.GetNumber(1)
	//pThis->GetEntity()->Select();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Accessible, SetWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Accessible, SetWindow)
{
	Object_wx_Accessible *pThis = Object_wx_Accessible::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//pThis->GetEntity()->SetWindow();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxAccessible
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Accessible)
{
	Gura_AssignMethod(wx_Accessible, wxAccessible);
	Gura_AssignMethod(wx_Accessible, DoDefaultAction);
	Gura_AssignMethod(wx_Accessible, GetChild);
	Gura_AssignMethod(wx_Accessible, GetChildCount);
	Gura_AssignMethod(wx_Accessible, GetDefaultAction);
	Gura_AssignMethod(wx_Accessible, GetDescription);
	Gura_AssignMethod(wx_Accessible, GetFocus);
	Gura_AssignMethod(wx_Accessible, GetHelpText);
	Gura_AssignMethod(wx_Accessible, GetKeyboardShortcut);
	Gura_AssignMethod(wx_Accessible, GetLocation);
	Gura_AssignMethod(wx_Accessible, GetName);
	Gura_AssignMethod(wx_Accessible, GetParent);
	Gura_AssignMethod(wx_Accessible, GetRole);
	Gura_AssignMethod(wx_Accessible, GetSelections);
	Gura_AssignMethod(wx_Accessible, GetState);
	Gura_AssignMethod(wx_Accessible, GetValue);
	Gura_AssignMethod(wx_Accessible, GetWindow);
	Gura_AssignMethod(wx_Accessible, HitTest);
	Gura_AssignMethod(wx_Accessible, Navigate);
	Gura_AssignMethod(wx_Accessible, NotifyEvent);
	Gura_AssignMethod(wx_Accessible, Select);
	Gura_AssignMethod(wx_Accessible, SetWindow);
}

Gura_ImplementDescendantCreator(wx_Accessible)
{
	return new Object_wx_Accessible((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
