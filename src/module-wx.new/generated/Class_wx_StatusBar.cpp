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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__StatusBar, "StatusBar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_StatusBar));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__StatusBar)
{
	//wxStatusBar();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__StatusBar_1, "StatusBar_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_StatusBar));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__StatusBar_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//long style = arg.GetNumber(2)
	//const wxString& name = arg.GetNumber(3)
	//wxStatusBar();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_StatusBar, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StatusBar, __Create)
{
	Object_wx_StatusBar *pThis = Object_wx_StatusBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//long style = arg.GetNumber(2)
	//const wxString& name = arg.GetNumber(3)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StatusBar, __GetFieldRect, "GetFieldRect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "i", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StatusBar, __GetFieldRect)
{
	Object_wx_StatusBar *pThis = Object_wx_StatusBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int i = arg.GetNumber(0)
	//wxRect& rect = arg.GetNumber(1)
	//pThis->GetEntity()->GetFieldRect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StatusBar, __GetFieldsCount, "GetFieldsCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StatusBar, __GetFieldsCount)
{
	Object_wx_StatusBar *pThis = Object_wx_StatusBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFieldsCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StatusBar, __GetField, "GetField")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StatusBar, __GetField)
{
	Object_wx_StatusBar *pThis = Object_wx_StatusBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->GetField();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StatusBar, __GetBorders, "GetBorders")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StatusBar, __GetBorders)
{
	Object_wx_StatusBar *pThis = Object_wx_StatusBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBorders();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StatusBar, __GetStatusText, "GetStatusText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "i", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StatusBar, __GetStatusText)
{
	Object_wx_StatusBar *pThis = Object_wx_StatusBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int i = arg.GetNumber(0)
	//pThis->GetEntity()->GetStatusText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StatusBar, __GetStatusWidth, "GetStatusWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StatusBar, __GetStatusWidth)
{
	Object_wx_StatusBar *pThis = Object_wx_StatusBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->GetStatusWidth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StatusBar, __GetStatusStyle, "GetStatusStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StatusBar, __GetStatusStyle)
{
	Object_wx_StatusBar *pThis = Object_wx_StatusBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->GetStatusStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StatusBar, __PopStatusText, "PopStatusText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "field", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StatusBar, __PopStatusText)
{
	Object_wx_StatusBar *pThis = Object_wx_StatusBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int field = arg.GetNumber(0)
	//pThis->GetEntity()->PopStatusText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StatusBar, __PushStatusText, "PushStatusText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "string", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "field", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StatusBar, __PushStatusText)
{
	Object_wx_StatusBar *pThis = Object_wx_StatusBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& string = arg.GetNumber(0)
	//int field = arg.GetNumber(1)
	//pThis->GetEntity()->PushStatusText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StatusBar, __SetFieldsCount, "SetFieldsCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "number", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "widths", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StatusBar, __SetFieldsCount)
{
	Object_wx_StatusBar *pThis = Object_wx_StatusBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int number = arg.GetNumber(0)
	//const int* widths = arg.GetNumber(1)
	//pThis->GetEntity()->SetFieldsCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StatusBar, __SetMinHeight, "SetMinHeight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StatusBar, __SetMinHeight)
{
	Object_wx_StatusBar *pThis = Object_wx_StatusBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int height = arg.GetNumber(0)
	//pThis->GetEntity()->SetMinHeight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StatusBar, __SetStatusStyles, "SetStatusStyles")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "styles", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StatusBar, __SetStatusStyles)
{
	Object_wx_StatusBar *pThis = Object_wx_StatusBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//const int* styles = arg.GetNumber(1)
	//pThis->GetEntity()->SetStatusStyles();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StatusBar, __SetStatusText, "SetStatusText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "i", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StatusBar, __SetStatusText)
{
	Object_wx_StatusBar *pThis = Object_wx_StatusBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& text = arg.GetNumber(0)
	//int i = arg.GetNumber(1)
	//pThis->GetEntity()->SetStatusText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StatusBar, __SetStatusWidths, "SetStatusWidths")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "widths_field", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StatusBar, __SetStatusWidths)
{
	Object_wx_StatusBar *pThis = Object_wx_StatusBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//const int* widths_field = arg.GetNumber(1)
	//pThis->GetEntity()->SetStatusWidths();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxStatusBar
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StatusBar)
{
	// Constructor assignment
	Gura_AssignFunction(__StatusBar);
	Gura_AssignFunction(__StatusBar_1);
	// Method assignment
	Gura_AssignMethod(wx_StatusBar, __Create);
	Gura_AssignMethod(wx_StatusBar, __GetFieldRect);
	Gura_AssignMethod(wx_StatusBar, __GetFieldsCount);
	Gura_AssignMethod(wx_StatusBar, __GetField);
	Gura_AssignMethod(wx_StatusBar, __GetBorders);
	Gura_AssignMethod(wx_StatusBar, __GetStatusText);
	Gura_AssignMethod(wx_StatusBar, __GetStatusWidth);
	Gura_AssignMethod(wx_StatusBar, __GetStatusStyle);
	Gura_AssignMethod(wx_StatusBar, __PopStatusText);
	Gura_AssignMethod(wx_StatusBar, __PushStatusText);
	Gura_AssignMethod(wx_StatusBar, __SetFieldsCount);
	Gura_AssignMethod(wx_StatusBar, __SetMinHeight);
	Gura_AssignMethod(wx_StatusBar, __SetStatusStyles);
	Gura_AssignMethod(wx_StatusBar, __SetStatusText);
	Gura_AssignMethod(wx_StatusBar, __SetStatusWidths);
}

Gura_ImplementDescendantCreator(wx_StatusBar)
{
	return new Object_wx_StatusBar((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
