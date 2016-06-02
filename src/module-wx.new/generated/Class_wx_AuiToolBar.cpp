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
Gura_DeclareMethod(wx_AuiToolBar, wxAuiToolBar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBar, wxAuiToolBar)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxAuiToolBar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, wxAuiToolBar_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, wxAuiToolBar_1)
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

Gura_DeclareMethod(wx_AuiToolBar, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, Create)
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

Gura_DeclareMethod(wx_AuiToolBar, SetWindowStyleFlag)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, SetWindowStyleFlag)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->SetWindowStyleFlag();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, GetWindowStyleFlag)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBar, GetWindowStyleFlag)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWindowStyleFlag();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, SetArtProvider)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "art", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, SetArtProvider)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int art = arg.GetNumber(0)
	//pThis->GetEntity()->SetArtProvider();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, GetArtProvider)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBar, GetArtProvider)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetArtProvider();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, SetFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, SetFont)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int font = arg.GetNumber(0)
	//pThis->GetEntity()->SetFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, AddTool)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "short_help_string", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "kind", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, AddTool)
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

Gura_DeclareMethod(wx_AuiToolBar, AddTool_1)
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

Gura_ImplementMethod(wx_AuiToolBar, AddTool_1)
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

Gura_DeclareMethod(wx_AuiToolBar, AddTool_2)
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

Gura_ImplementMethod(wx_AuiToolBar, AddTool_2)
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

Gura_DeclareMethod(wx_AuiToolBar, AddLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, AddLabel)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//int label = arg.GetNumber(1)
	//int width = arg.GetNumber(2)
	//pThis->GetEntity()->AddLabel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, AddControl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "control", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, AddControl)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int control = arg.GetNumber(0)
	//int label = arg.GetNumber(1)
	//pThis->GetEntity()->AddControl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, AddSeparator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBar, AddSeparator)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AddSeparator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, AddSpacer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pixels", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, AddSpacer)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pixels = arg.GetNumber(0)
	//pThis->GetEntity()->AddSpacer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, AddStretchSpacer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "proportion", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, AddStretchSpacer)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int proportion = arg.GetNumber(0)
	//pThis->GetEntity()->AddStretchSpacer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, Realize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBar, Realize)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Realize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, FindControl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, FindControl)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int window_id = arg.GetNumber(0)
	//pThis->GetEntity()->FindControl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, FindToolByPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, FindToolByPosition)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->FindToolByPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, FindToolByIndex)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, FindToolByIndex)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int idx = arg.GetNumber(0)
	//pThis->GetEntity()->FindToolByIndex();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, FindTool)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, FindTool)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//pThis->GetEntity()->FindTool();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, ClearTools)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBar, ClearTools)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ClearTools();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, Clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBar, Clear)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, DeleteTool)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, DeleteTool)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteTool();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, DeleteByIndex)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, DeleteByIndex)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteByIndex();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, GetToolCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBar, GetToolCount)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetToolCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, GetToolPos)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, GetToolPos)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//pThis->GetEntity()->GetToolPos();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, GetToolIndex)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, GetToolIndex)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//pThis->GetEntity()->GetToolIndex();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, GetToolFits)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, GetToolFits)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//pThis->GetEntity()->GetToolFits();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, GetToolRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, GetToolRect)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//pThis->GetEntity()->GetToolRect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, GetToolFitsByIndex)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, GetToolFitsByIndex)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//pThis->GetEntity()->GetToolFitsByIndex();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, GetToolBarFits)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBar, GetToolBarFits)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetToolBarFits();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, SetMargins)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, SetMargins)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->SetMargins();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, SetMargins_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, SetMargins_1)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->SetMargins();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, SetMargins_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "left", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "right", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "top", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bottom", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, SetMargins_2)
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

Gura_DeclareMethod(wx_AuiToolBar, SetToolBitmapSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, SetToolBitmapSize)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->SetToolBitmapSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, GetToolBitmapSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBar, GetToolBitmapSize)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetToolBitmapSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, GetOverflowVisible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBar, GetOverflowVisible)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOverflowVisible();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, SetOverflowVisible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "visible", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, SetOverflowVisible)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int visible = arg.GetNumber(0)
	//pThis->GetEntity()->SetOverflowVisible();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, GetGripperVisible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBar, GetGripperVisible)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetGripperVisible();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, SetGripperVisible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "visible", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, SetGripperVisible)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int visible = arg.GetNumber(0)
	//pThis->GetEntity()->SetGripperVisible();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, ToggleTool)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "state", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, ToggleTool)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//int state = arg.GetNumber(1)
	//pThis->GetEntity()->ToggleTool();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, GetToolToggled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, GetToolToggled)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//pThis->GetEntity()->GetToolToggled();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, EnableTool)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "state", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, EnableTool)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//int state = arg.GetNumber(1)
	//pThis->GetEntity()->EnableTool();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, GetToolEnabled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, GetToolEnabled)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//pThis->GetEntity()->GetToolEnabled();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, SetToolDropDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dropdown", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, SetToolDropDown)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//int dropdown = arg.GetNumber(1)
	//pThis->GetEntity()->SetToolDropDown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, GetToolDropDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, GetToolDropDown)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//pThis->GetEntity()->GetToolDropDown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, SetToolBorderPadding)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "padding", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, SetToolBorderPadding)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int padding = arg.GetNumber(0)
	//pThis->GetEntity()->SetToolBorderPadding();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, GetToolBorderPadding)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBar, GetToolBorderPadding)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetToolBorderPadding();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, SetToolTextOrientation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "orientation", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, SetToolTextOrientation)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int orientation = arg.GetNumber(0)
	//pThis->GetEntity()->SetToolTextOrientation();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, GetToolTextOrientation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBar, GetToolTextOrientation)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetToolTextOrientation();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, SetToolPacking)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "packing", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, SetToolPacking)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int packing = arg.GetNumber(0)
	//pThis->GetEntity()->SetToolPacking();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, GetToolPacking)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBar, GetToolPacking)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetToolPacking();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, SetToolProportion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "proportion", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, SetToolProportion)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//int proportion = arg.GetNumber(1)
	//pThis->GetEntity()->SetToolProportion();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, GetToolProportion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, GetToolProportion)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//pThis->GetEntity()->GetToolProportion();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, SetToolSeparation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "separation", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, SetToolSeparation)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int separation = arg.GetNumber(0)
	//pThis->GetEntity()->SetToolSeparation();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, GetToolSeparation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBar, GetToolSeparation)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetToolSeparation();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, SetToolSticky)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sticky", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, SetToolSticky)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//int sticky = arg.GetNumber(1)
	//pThis->GetEntity()->SetToolSticky();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, GetToolSticky)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, GetToolSticky)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//pThis->GetEntity()->GetToolSticky();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, GetToolLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, GetToolLabel)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//pThis->GetEntity()->GetToolLabel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, SetToolLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, SetToolLabel)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//int label = arg.GetNumber(1)
	//pThis->GetEntity()->SetToolLabel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, GetToolBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, GetToolBitmap)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//pThis->GetEntity()->GetToolBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, SetToolBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, SetToolBitmap)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//int bitmap = arg.GetNumber(1)
	//pThis->GetEntity()->SetToolBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, GetToolShortHelp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, GetToolShortHelp)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//pThis->GetEntity()->GetToolShortHelp();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, SetToolShortHelp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "help_string", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, SetToolShortHelp)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//int help_string = arg.GetNumber(1)
	//pThis->GetEntity()->SetToolShortHelp();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, GetToolLongHelp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, GetToolLongHelp)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//pThis->GetEntity()->GetToolLongHelp();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, SetToolLongHelp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "help_string", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, SetToolLongHelp)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//int help_string = arg.GetNumber(1)
	//pThis->GetEntity()->SetToolLongHelp();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, SetCustomOverflowItems)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "prepend", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "append", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, SetCustomOverflowItems)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int prepend = arg.GetNumber(0)
	//int append = arg.GetNumber(1)
	//pThis->GetEntity()->SetCustomOverflowItems();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, GetHintSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dock_direction", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, GetHintSize)
{
	Object_wx_AuiToolBar *pThis = Object_wx_AuiToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dock_direction = arg.GetNumber(0)
	//pThis->GetEntity()->GetHintSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBar, IsPaneValid)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pane", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBar, IsPaneValid)
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
	Gura_AssignMethod(wx_AuiToolBar, wxAuiToolBar);
	Gura_AssignMethod(wx_AuiToolBar, wxAuiToolBar_1);
	Gura_AssignMethod(wx_AuiToolBar, Create);
	Gura_AssignMethod(wx_AuiToolBar, SetWindowStyleFlag);
	Gura_AssignMethod(wx_AuiToolBar, GetWindowStyleFlag);
	Gura_AssignMethod(wx_AuiToolBar, SetArtProvider);
	Gura_AssignMethod(wx_AuiToolBar, GetArtProvider);
	Gura_AssignMethod(wx_AuiToolBar, SetFont);
	Gura_AssignMethod(wx_AuiToolBar, AddTool);
	Gura_AssignMethod(wx_AuiToolBar, AddTool_1);
	Gura_AssignMethod(wx_AuiToolBar, AddTool_2);
	Gura_AssignMethod(wx_AuiToolBar, AddLabel);
	Gura_AssignMethod(wx_AuiToolBar, AddControl);
	Gura_AssignMethod(wx_AuiToolBar, AddSeparator);
	Gura_AssignMethod(wx_AuiToolBar, AddSpacer);
	Gura_AssignMethod(wx_AuiToolBar, AddStretchSpacer);
	Gura_AssignMethod(wx_AuiToolBar, Realize);
	Gura_AssignMethod(wx_AuiToolBar, FindControl);
	Gura_AssignMethod(wx_AuiToolBar, FindToolByPosition);
	Gura_AssignMethod(wx_AuiToolBar, FindToolByIndex);
	Gura_AssignMethod(wx_AuiToolBar, FindTool);
	Gura_AssignMethod(wx_AuiToolBar, ClearTools);
	Gura_AssignMethod(wx_AuiToolBar, Clear);
	Gura_AssignMethod(wx_AuiToolBar, DeleteTool);
	Gura_AssignMethod(wx_AuiToolBar, DeleteByIndex);
	Gura_AssignMethod(wx_AuiToolBar, GetToolCount);
	Gura_AssignMethod(wx_AuiToolBar, GetToolPos);
	Gura_AssignMethod(wx_AuiToolBar, GetToolIndex);
	Gura_AssignMethod(wx_AuiToolBar, GetToolFits);
	Gura_AssignMethod(wx_AuiToolBar, GetToolRect);
	Gura_AssignMethod(wx_AuiToolBar, GetToolFitsByIndex);
	Gura_AssignMethod(wx_AuiToolBar, GetToolBarFits);
	Gura_AssignMethod(wx_AuiToolBar, SetMargins);
	Gura_AssignMethod(wx_AuiToolBar, SetMargins_1);
	Gura_AssignMethod(wx_AuiToolBar, SetMargins_2);
	Gura_AssignMethod(wx_AuiToolBar, SetToolBitmapSize);
	Gura_AssignMethod(wx_AuiToolBar, GetToolBitmapSize);
	Gura_AssignMethod(wx_AuiToolBar, GetOverflowVisible);
	Gura_AssignMethod(wx_AuiToolBar, SetOverflowVisible);
	Gura_AssignMethod(wx_AuiToolBar, GetGripperVisible);
	Gura_AssignMethod(wx_AuiToolBar, SetGripperVisible);
	Gura_AssignMethod(wx_AuiToolBar, ToggleTool);
	Gura_AssignMethod(wx_AuiToolBar, GetToolToggled);
	Gura_AssignMethod(wx_AuiToolBar, EnableTool);
	Gura_AssignMethod(wx_AuiToolBar, GetToolEnabled);
	Gura_AssignMethod(wx_AuiToolBar, SetToolDropDown);
	Gura_AssignMethod(wx_AuiToolBar, GetToolDropDown);
	Gura_AssignMethod(wx_AuiToolBar, SetToolBorderPadding);
	Gura_AssignMethod(wx_AuiToolBar, GetToolBorderPadding);
	Gura_AssignMethod(wx_AuiToolBar, SetToolTextOrientation);
	Gura_AssignMethod(wx_AuiToolBar, GetToolTextOrientation);
	Gura_AssignMethod(wx_AuiToolBar, SetToolPacking);
	Gura_AssignMethod(wx_AuiToolBar, GetToolPacking);
	Gura_AssignMethod(wx_AuiToolBar, SetToolProportion);
	Gura_AssignMethod(wx_AuiToolBar, GetToolProportion);
	Gura_AssignMethod(wx_AuiToolBar, SetToolSeparation);
	Gura_AssignMethod(wx_AuiToolBar, GetToolSeparation);
	Gura_AssignMethod(wx_AuiToolBar, SetToolSticky);
	Gura_AssignMethod(wx_AuiToolBar, GetToolSticky);
	Gura_AssignMethod(wx_AuiToolBar, GetToolLabel);
	Gura_AssignMethod(wx_AuiToolBar, SetToolLabel);
	Gura_AssignMethod(wx_AuiToolBar, GetToolBitmap);
	Gura_AssignMethod(wx_AuiToolBar, SetToolBitmap);
	Gura_AssignMethod(wx_AuiToolBar, GetToolShortHelp);
	Gura_AssignMethod(wx_AuiToolBar, SetToolShortHelp);
	Gura_AssignMethod(wx_AuiToolBar, GetToolLongHelp);
	Gura_AssignMethod(wx_AuiToolBar, SetToolLongHelp);
	Gura_AssignMethod(wx_AuiToolBar, SetCustomOverflowItems);
	Gura_AssignMethod(wx_AuiToolBar, GetHintSize);
	Gura_AssignMethod(wx_AuiToolBar, IsPaneValid);
}

Gura_ImplementDescendantCreator(wx_AuiToolBar)
{
	return new Object_wx_AuiToolBar((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
