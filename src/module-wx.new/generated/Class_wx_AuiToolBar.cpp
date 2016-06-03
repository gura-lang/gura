//----------------------------------------------------------------------------
// wxAuiToolBar
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAuiToolBar
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAuiToolBar
//----------------------------------------------------------------------------
Object_wx_AuiToolBar::~Object_wx_AuiToolBar()
{
}

Object *Object_wx_AuiToolBar::Clone() const
{
	return nullptr;
}

String Object_wx_AuiToolBar::ToString(bool exprFlag)
{
	String rtn("<wx.AuiToolBar:");
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
Gura_DeclareMethodAlias(wx_AuiToolBar, __wxAuiToolBar, "wxAuiToolBar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBar, __wxAuiToolBar)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxAuiToolBar();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __wxAuiToolBar_1, "wxAuiToolBar_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, __wxAuiToolBar_1)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int position = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//pThis->GetEntity()->wxAuiToolBar();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, __Create)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __SetWindowStyleFlag, "SetWindowStyleFlag")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, __SetWindowStyleFlag)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->SetWindowStyleFlag();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __GetWindowStyleFlag, "GetWindowStyleFlag")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBar, __GetWindowStyleFlag)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWindowStyleFlag();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __SetArtProvider, "SetArtProvider")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "art", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, __SetArtProvider)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int art = arg.GetNumber(0)
	//pThis->GetEntity()->SetArtProvider();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __GetArtProvider, "GetArtProvider")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBar, __GetArtProvider)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetArtProvider();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __SetFont, "SetFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, __SetFont)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int font = arg.GetNumber(0)
	//pThis->GetEntity()->SetFont();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __AddTool, "AddTool")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "short_help_string", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "kind", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, __AddTool)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//int label = arg.GetNumber(1)
	//int bitmap = arg.GetNumber(2)
	//int short_help_string = arg.GetNumber(3)
	//int kind = arg.GetNumber(4)
	//pThis->GetEntity()->AddTool();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __AddTool_1, "AddTool_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "disabled_bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "kind", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "short_help_string", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "long_help_string", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "client_data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, __AddTool_1)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//int label = arg.GetNumber(1)
	//int bitmap = arg.GetNumber(2)
	//int disabled_bitmap = arg.GetNumber(3)
	//int kind = arg.GetNumber(4)
	//int short_help_string = arg.GetNumber(5)
	//int long_help_string = arg.GetNumber(6)
	//int client_data = arg.GetNumber(7)
	//pThis->GetEntity()->AddTool();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __AddTool_2, "AddTool_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "disabled_bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "toggle", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "client_data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "short_help_string", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "long_help_string", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, __AddTool_2)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//int bitmap = arg.GetNumber(1)
	//int disabled_bitmap = arg.GetNumber(2)
	//int toggle = arg.GetNumber(3)
	//int client_data = arg.GetNumber(4)
	//int short_help_string = arg.GetNumber(5)
	//int long_help_string = arg.GetNumber(6)
	//pThis->GetEntity()->AddTool();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __AddLabel, "AddLabel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, __AddLabel)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//int label = arg.GetNumber(1)
	//int width = arg.GetNumber(2)
	//pThis->GetEntity()->AddLabel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __AddControl, "AddControl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "control", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, __AddControl)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int control = arg.GetNumber(0)
	//int label = arg.GetNumber(1)
	//pThis->GetEntity()->AddControl();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __AddSeparator, "AddSeparator")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBar, __AddSeparator)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AddSeparator();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __AddSpacer, "AddSpacer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pixels", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, __AddSpacer)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pixels = arg.GetNumber(0)
	//pThis->GetEntity()->AddSpacer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __AddStretchSpacer, "AddStretchSpacer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "proportion", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, __AddStretchSpacer)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int proportion = arg.GetNumber(0)
	//pThis->GetEntity()->AddStretchSpacer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __Realize, "Realize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBar, __Realize)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Realize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __FindControl, "FindControl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, __FindControl)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int window_id = arg.GetNumber(0)
	//pThis->GetEntity()->FindControl();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __FindToolByPosition, "FindToolByPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, __FindToolByPosition)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->FindToolByPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __FindToolByIndex, "FindToolByIndex")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, __FindToolByIndex)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int idx = arg.GetNumber(0)
	//pThis->GetEntity()->FindToolByIndex();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __FindTool, "FindTool")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, __FindTool)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//pThis->GetEntity()->FindTool();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __ClearTools, "ClearTools")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBar, __ClearTools)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ClearTools();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __Clear, "Clear")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBar, __Clear)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __DeleteTool, "DeleteTool")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, __DeleteTool)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteTool();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __DeleteByIndex, "DeleteByIndex")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, __DeleteByIndex)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteByIndex();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __GetToolCount, "GetToolCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBar, __GetToolCount)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetToolCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __GetToolPos, "GetToolPos")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, __GetToolPos)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//pThis->GetEntity()->GetToolPos();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __GetToolIndex, "GetToolIndex")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, __GetToolIndex)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//pThis->GetEntity()->GetToolIndex();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __GetToolFits, "GetToolFits")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, __GetToolFits)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//pThis->GetEntity()->GetToolFits();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __GetToolRect, "GetToolRect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, __GetToolRect)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//pThis->GetEntity()->GetToolRect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __GetToolFitsByIndex, "GetToolFitsByIndex")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, __GetToolFitsByIndex)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//pThis->GetEntity()->GetToolFitsByIndex();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __GetToolBarFits, "GetToolBarFits")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBar, __GetToolBarFits)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetToolBarFits();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __SetMargins, "SetMargins")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, __SetMargins)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->SetMargins();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __SetMargins_1, "SetMargins_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, __SetMargins_1)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->SetMargins();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __SetMargins_2, "SetMargins_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "left", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "right", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "top", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bottom", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, __SetMargins_2)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int left = arg.GetNumber(0)
	//int right = arg.GetNumber(1)
	//int top = arg.GetNumber(2)
	//int bottom = arg.GetNumber(3)
	//pThis->GetEntity()->SetMargins();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __SetToolBitmapSize, "SetToolBitmapSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, __SetToolBitmapSize)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->SetToolBitmapSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __GetToolBitmapSize, "GetToolBitmapSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBar, __GetToolBitmapSize)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetToolBitmapSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __GetOverflowVisible, "GetOverflowVisible")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBar, __GetOverflowVisible)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOverflowVisible();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __SetOverflowVisible, "SetOverflowVisible")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "visible", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, __SetOverflowVisible)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int visible = arg.GetNumber(0)
	//pThis->GetEntity()->SetOverflowVisible();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __GetGripperVisible, "GetGripperVisible")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBar, __GetGripperVisible)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetGripperVisible();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __SetGripperVisible, "SetGripperVisible")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "visible", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, __SetGripperVisible)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int visible = arg.GetNumber(0)
	//pThis->GetEntity()->SetGripperVisible();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __ToggleTool, "ToggleTool")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "state", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, __ToggleTool)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//int state = arg.GetNumber(1)
	//pThis->GetEntity()->ToggleTool();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __GetToolToggled, "GetToolToggled")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, __GetToolToggled)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//pThis->GetEntity()->GetToolToggled();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __EnableTool, "EnableTool")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "state", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, __EnableTool)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//int state = arg.GetNumber(1)
	//pThis->GetEntity()->EnableTool();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __GetToolEnabled, "GetToolEnabled")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, __GetToolEnabled)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//pThis->GetEntity()->GetToolEnabled();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __SetToolDropDown, "SetToolDropDown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dropdown", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, __SetToolDropDown)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//int dropdown = arg.GetNumber(1)
	//pThis->GetEntity()->SetToolDropDown();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __GetToolDropDown, "GetToolDropDown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, __GetToolDropDown)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//pThis->GetEntity()->GetToolDropDown();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __SetToolBorderPadding, "SetToolBorderPadding")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "padding", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, __SetToolBorderPadding)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int padding = arg.GetNumber(0)
	//pThis->GetEntity()->SetToolBorderPadding();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __GetToolBorderPadding, "GetToolBorderPadding")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBar, __GetToolBorderPadding)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetToolBorderPadding();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __SetToolTextOrientation, "SetToolTextOrientation")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "orientation", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, __SetToolTextOrientation)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int orientation = arg.GetNumber(0)
	//pThis->GetEntity()->SetToolTextOrientation();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __GetToolTextOrientation, "GetToolTextOrientation")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBar, __GetToolTextOrientation)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetToolTextOrientation();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __SetToolPacking, "SetToolPacking")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "packing", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, __SetToolPacking)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int packing = arg.GetNumber(0)
	//pThis->GetEntity()->SetToolPacking();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __GetToolPacking, "GetToolPacking")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBar, __GetToolPacking)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetToolPacking();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __SetToolProportion, "SetToolProportion")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "proportion", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, __SetToolProportion)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//int proportion = arg.GetNumber(1)
	//pThis->GetEntity()->SetToolProportion();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __GetToolProportion, "GetToolProportion")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, __GetToolProportion)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//pThis->GetEntity()->GetToolProportion();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __SetToolSeparation, "SetToolSeparation")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "separation", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, __SetToolSeparation)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int separation = arg.GetNumber(0)
	//pThis->GetEntity()->SetToolSeparation();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __GetToolSeparation, "GetToolSeparation")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBar, __GetToolSeparation)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetToolSeparation();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __SetToolSticky, "SetToolSticky")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sticky", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, __SetToolSticky)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//int sticky = arg.GetNumber(1)
	//pThis->GetEntity()->SetToolSticky();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __GetToolSticky, "GetToolSticky")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, __GetToolSticky)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//pThis->GetEntity()->GetToolSticky();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __GetToolLabel, "GetToolLabel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, __GetToolLabel)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//pThis->GetEntity()->GetToolLabel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __SetToolLabel, "SetToolLabel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, __SetToolLabel)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//int label = arg.GetNumber(1)
	//pThis->GetEntity()->SetToolLabel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __GetToolBitmap, "GetToolBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, __GetToolBitmap)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//pThis->GetEntity()->GetToolBitmap();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __SetToolBitmap, "SetToolBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, __SetToolBitmap)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//int bitmap = arg.GetNumber(1)
	//pThis->GetEntity()->SetToolBitmap();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __GetToolShortHelp, "GetToolShortHelp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, __GetToolShortHelp)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//pThis->GetEntity()->GetToolShortHelp();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __SetToolShortHelp, "SetToolShortHelp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "help_string", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, __SetToolShortHelp)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//int help_string = arg.GetNumber(1)
	//pThis->GetEntity()->SetToolShortHelp();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __GetToolLongHelp, "GetToolLongHelp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, __GetToolLongHelp)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//pThis->GetEntity()->GetToolLongHelp();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __SetToolLongHelp, "SetToolLongHelp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "help_string", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, __SetToolLongHelp)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//int help_string = arg.GetNumber(1)
	//pThis->GetEntity()->SetToolLongHelp();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __SetCustomOverflowItems, "SetCustomOverflowItems")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "prepend", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "append", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, __SetCustomOverflowItems)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int prepend = arg.GetNumber(0)
	//int append = arg.GetNumber(1)
	//pThis->GetEntity()->SetCustomOverflowItems();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __GetHintSize, "GetHintSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dock_direction", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, __GetHintSize)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dock_direction = arg.GetNumber(0)
	//pThis->GetEntity()->GetHintSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBar, __IsPaneValid, "IsPaneValid")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pane", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, __IsPaneValid)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pane = arg.GetNumber(0)
	//pThis->GetEntity()->IsPaneValid();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxAuiToolBar
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AuiToolBar)
{
	Gura_AssignMethod(wx_AuiToolBar, __wxAuiToolBar);
	Gura_AssignMethod(wx_AuiToolBar, __wxAuiToolBar_1);
	Gura_AssignMethod(wx_AuiToolBar, __Create);
	Gura_AssignMethod(wx_AuiToolBar, __SetWindowStyleFlag);
	Gura_AssignMethod(wx_AuiToolBar, __GetWindowStyleFlag);
	Gura_AssignMethod(wx_AuiToolBar, __SetArtProvider);
	Gura_AssignMethod(wx_AuiToolBar, __GetArtProvider);
	Gura_AssignMethod(wx_AuiToolBar, __SetFont);
	Gura_AssignMethod(wx_AuiToolBar, __AddTool);
	Gura_AssignMethod(wx_AuiToolBar, __AddTool_1);
	Gura_AssignMethod(wx_AuiToolBar, __AddTool_2);
	Gura_AssignMethod(wx_AuiToolBar, __AddLabel);
	Gura_AssignMethod(wx_AuiToolBar, __AddControl);
	Gura_AssignMethod(wx_AuiToolBar, __AddSeparator);
	Gura_AssignMethod(wx_AuiToolBar, __AddSpacer);
	Gura_AssignMethod(wx_AuiToolBar, __AddStretchSpacer);
	Gura_AssignMethod(wx_AuiToolBar, __Realize);
	Gura_AssignMethod(wx_AuiToolBar, __FindControl);
	Gura_AssignMethod(wx_AuiToolBar, __FindToolByPosition);
	Gura_AssignMethod(wx_AuiToolBar, __FindToolByIndex);
	Gura_AssignMethod(wx_AuiToolBar, __FindTool);
	Gura_AssignMethod(wx_AuiToolBar, __ClearTools);
	Gura_AssignMethod(wx_AuiToolBar, __Clear);
	Gura_AssignMethod(wx_AuiToolBar, __DeleteTool);
	Gura_AssignMethod(wx_AuiToolBar, __DeleteByIndex);
	Gura_AssignMethod(wx_AuiToolBar, __GetToolCount);
	Gura_AssignMethod(wx_AuiToolBar, __GetToolPos);
	Gura_AssignMethod(wx_AuiToolBar, __GetToolIndex);
	Gura_AssignMethod(wx_AuiToolBar, __GetToolFits);
	Gura_AssignMethod(wx_AuiToolBar, __GetToolRect);
	Gura_AssignMethod(wx_AuiToolBar, __GetToolFitsByIndex);
	Gura_AssignMethod(wx_AuiToolBar, __GetToolBarFits);
	Gura_AssignMethod(wx_AuiToolBar, __SetMargins);
	Gura_AssignMethod(wx_AuiToolBar, __SetMargins_1);
	Gura_AssignMethod(wx_AuiToolBar, __SetMargins_2);
	Gura_AssignMethod(wx_AuiToolBar, __SetToolBitmapSize);
	Gura_AssignMethod(wx_AuiToolBar, __GetToolBitmapSize);
	Gura_AssignMethod(wx_AuiToolBar, __GetOverflowVisible);
	Gura_AssignMethod(wx_AuiToolBar, __SetOverflowVisible);
	Gura_AssignMethod(wx_AuiToolBar, __GetGripperVisible);
	Gura_AssignMethod(wx_AuiToolBar, __SetGripperVisible);
	Gura_AssignMethod(wx_AuiToolBar, __ToggleTool);
	Gura_AssignMethod(wx_AuiToolBar, __GetToolToggled);
	Gura_AssignMethod(wx_AuiToolBar, __EnableTool);
	Gura_AssignMethod(wx_AuiToolBar, __GetToolEnabled);
	Gura_AssignMethod(wx_AuiToolBar, __SetToolDropDown);
	Gura_AssignMethod(wx_AuiToolBar, __GetToolDropDown);
	Gura_AssignMethod(wx_AuiToolBar, __SetToolBorderPadding);
	Gura_AssignMethod(wx_AuiToolBar, __GetToolBorderPadding);
	Gura_AssignMethod(wx_AuiToolBar, __SetToolTextOrientation);
	Gura_AssignMethod(wx_AuiToolBar, __GetToolTextOrientation);
	Gura_AssignMethod(wx_AuiToolBar, __SetToolPacking);
	Gura_AssignMethod(wx_AuiToolBar, __GetToolPacking);
	Gura_AssignMethod(wx_AuiToolBar, __SetToolProportion);
	Gura_AssignMethod(wx_AuiToolBar, __GetToolProportion);
	Gura_AssignMethod(wx_AuiToolBar, __SetToolSeparation);
	Gura_AssignMethod(wx_AuiToolBar, __GetToolSeparation);
	Gura_AssignMethod(wx_AuiToolBar, __SetToolSticky);
	Gura_AssignMethod(wx_AuiToolBar, __GetToolSticky);
	Gura_AssignMethod(wx_AuiToolBar, __GetToolLabel);
	Gura_AssignMethod(wx_AuiToolBar, __SetToolLabel);
	Gura_AssignMethod(wx_AuiToolBar, __GetToolBitmap);
	Gura_AssignMethod(wx_AuiToolBar, __SetToolBitmap);
	Gura_AssignMethod(wx_AuiToolBar, __GetToolShortHelp);
	Gura_AssignMethod(wx_AuiToolBar, __SetToolShortHelp);
	Gura_AssignMethod(wx_AuiToolBar, __GetToolLongHelp);
	Gura_AssignMethod(wx_AuiToolBar, __SetToolLongHelp);
	Gura_AssignMethod(wx_AuiToolBar, __SetCustomOverflowItems);
	Gura_AssignMethod(wx_AuiToolBar, __GetHintSize);
	Gura_AssignMethod(wx_AuiToolBar, __IsPaneValid);
}

Gura_ImplementDescendantCreator(wx_AuiToolBar)
{
	return new Object_wx_AuiToolBar((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
