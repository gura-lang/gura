//----------------------------------------------------------------------------
// wxStatusBar
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxStatusBar
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxStatusBar
//----------------------------------------------------------------------------
Object_wx_StatusBar::~Object_wx_StatusBar()
{
}

Object *Object_wx_StatusBar::Clone() const
{
	return nullptr;
}

String Object_wx_StatusBar::ToString(bool exprFlag)
{
	String rtn("<wx.StatusBar:");
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
Gura_DeclareMethod(wx_StatusBar, wxStatusBar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StatusBar, wxStatusBar)
{
	Object_wx_StatusBar *pThis = Object_wx_StatusBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxStatusBar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StatusBar, wxStatusBar_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StatusBar, wxStatusBar_1)
{
	Object_wx_StatusBar *pThis = Object_wx_StatusBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int style = arg.GetNumber(2)
	//int name = arg.GetNumber(3)
	//pThis->GetEntity()->wxStatusBar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StatusBar, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StatusBar, Create)
{
	Object_wx_StatusBar *pThis = Object_wx_StatusBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int style = arg.GetNumber(2)
	//int name = arg.GetNumber(3)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StatusBar, GetFieldRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "i", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StatusBar, GetFieldRect)
{
	Object_wx_StatusBar *pThis = Object_wx_StatusBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int i = arg.GetNumber(0)
	//int rect = arg.GetNumber(1)
	//pThis->GetEntity()->GetFieldRect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StatusBar, GetFieldsCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StatusBar, GetFieldsCount)
{
	Object_wx_StatusBar *pThis = Object_wx_StatusBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFieldsCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StatusBar, GetField)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StatusBar, GetField)
{
	Object_wx_StatusBar *pThis = Object_wx_StatusBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->GetField();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StatusBar, GetBorders)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StatusBar, GetBorders)
{
	Object_wx_StatusBar *pThis = Object_wx_StatusBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBorders();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StatusBar, GetStatusText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "i", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StatusBar, GetStatusText)
{
	Object_wx_StatusBar *pThis = Object_wx_StatusBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int i = arg.GetNumber(0)
	//pThis->GetEntity()->GetStatusText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StatusBar, GetStatusWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StatusBar, GetStatusWidth)
{
	Object_wx_StatusBar *pThis = Object_wx_StatusBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->GetStatusWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StatusBar, GetStatusStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StatusBar, GetStatusStyle)
{
	Object_wx_StatusBar *pThis = Object_wx_StatusBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->GetStatusStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StatusBar, PopStatusText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "field", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StatusBar, PopStatusText)
{
	Object_wx_StatusBar *pThis = Object_wx_StatusBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int field = arg.GetNumber(0)
	//pThis->GetEntity()->PopStatusText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StatusBar, PushStatusText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "string", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "field", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StatusBar, PushStatusText)
{
	Object_wx_StatusBar *pThis = Object_wx_StatusBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int string = arg.GetNumber(0)
	//int field = arg.GetNumber(1)
	//pThis->GetEntity()->PushStatusText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StatusBar, SetFieldsCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "number", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "widths", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StatusBar, SetFieldsCount)
{
	Object_wx_StatusBar *pThis = Object_wx_StatusBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int number = arg.GetNumber(0)
	//int widths = arg.GetNumber(1)
	//pThis->GetEntity()->SetFieldsCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StatusBar, SetMinHeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StatusBar, SetMinHeight)
{
	Object_wx_StatusBar *pThis = Object_wx_StatusBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int height = arg.GetNumber(0)
	//pThis->GetEntity()->SetMinHeight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StatusBar, SetStatusStyles)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "styles", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StatusBar, SetStatusStyles)
{
	Object_wx_StatusBar *pThis = Object_wx_StatusBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//int styles = arg.GetNumber(1)
	//pThis->GetEntity()->SetStatusStyles();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StatusBar, SetStatusText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "i", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StatusBar, SetStatusText)
{
	Object_wx_StatusBar *pThis = Object_wx_StatusBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//int i = arg.GetNumber(1)
	//pThis->GetEntity()->SetStatusText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StatusBar, SetStatusWidths)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "widths_field", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StatusBar, SetStatusWidths)
{
	Object_wx_StatusBar *pThis = Object_wx_StatusBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//int widths_field = arg.GetNumber(1)
	//pThis->GetEntity()->SetStatusWidths();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxStatusBar
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StatusBar)
{
	Gura_AssignMethod(wx_StatusBar, wxStatusBar);
	Gura_AssignMethod(wx_StatusBar, wxStatusBar_1);
	Gura_AssignMethod(wx_StatusBar, Create);
	Gura_AssignMethod(wx_StatusBar, GetFieldRect);
	Gura_AssignMethod(wx_StatusBar, GetFieldsCount);
	Gura_AssignMethod(wx_StatusBar, GetField);
	Gura_AssignMethod(wx_StatusBar, GetBorders);
	Gura_AssignMethod(wx_StatusBar, GetStatusText);
	Gura_AssignMethod(wx_StatusBar, GetStatusWidth);
	Gura_AssignMethod(wx_StatusBar, GetStatusStyle);
	Gura_AssignMethod(wx_StatusBar, PopStatusText);
	Gura_AssignMethod(wx_StatusBar, PushStatusText);
	Gura_AssignMethod(wx_StatusBar, SetFieldsCount);
	Gura_AssignMethod(wx_StatusBar, SetMinHeight);
	Gura_AssignMethod(wx_StatusBar, SetStatusStyles);
	Gura_AssignMethod(wx_StatusBar, SetStatusText);
	Gura_AssignMethod(wx_StatusBar, SetStatusWidths);
}

Gura_ImplementDescendantCreator(wx_StatusBar)
{
	return new Object_wx_StatusBar((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
