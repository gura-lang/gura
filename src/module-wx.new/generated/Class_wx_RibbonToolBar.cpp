//----------------------------------------------------------------------------
// wxRibbonToolBar
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRibbonToolBar
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRibbonToolBar
//----------------------------------------------------------------------------
Object_wx_RibbonToolBar::~Object_wx_RibbonToolBar()
{
}

Object *Object_wx_RibbonToolBar::Clone() const
{
	return nullptr;
}

String Object_wx_RibbonToolBar::ToString(bool exprFlag)
{
	String rtn("<wx.RibbonToolBar:");
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
Gura_DeclareMethod(wx_RibbonToolBar, wxRibbonToolBar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonToolBar, wxRibbonToolBar)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxRibbonToolBar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonToolBar, wxRibbonToolBar_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, wxRibbonToolBar_1)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//pThis->GetEntity()->wxRibbonToolBar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonToolBar, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, Create)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonToolBar, AddTool)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "help_string", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "kind", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, AddTool)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//int bitmap = arg.GetNumber(1)
	//int help_string = arg.GetNumber(2)
	//int kind = arg.GetNumber(3)
	//pThis->GetEntity()->AddTool();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonToolBar, AddDropdownTool)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "help_string", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, AddDropdownTool)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//int bitmap = arg.GetNumber(1)
	//int help_string = arg.GetNumber(2)
	//pThis->GetEntity()->AddDropdownTool();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonToolBar, AddHybridTool)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "help_string", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, AddHybridTool)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//int bitmap = arg.GetNumber(1)
	//int help_string = arg.GetNumber(2)
	//pThis->GetEntity()->AddHybridTool();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonToolBar, AddToggleTool)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "help_string", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, AddToggleTool)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//int bitmap = arg.GetNumber(1)
	//int help_string = arg.GetNumber(2)
	//pThis->GetEntity()->AddToggleTool();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonToolBar, AddTool_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap_disabled", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "help_string", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "kind", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "client_data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, AddTool_1)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//int bitmap = arg.GetNumber(1)
	//int bitmap_disabled = arg.GetNumber(2)
	//int help_string = arg.GetNumber(3)
	//int kind = arg.GetNumber(4)
	//int client_data = arg.GetNumber(5)
	//pThis->GetEntity()->AddTool();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonToolBar, AddSeparator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonToolBar, AddSeparator)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AddSeparator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonToolBar, InsertTool)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "help_string", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "kind", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, InsertTool)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int tool_id = arg.GetNumber(1)
	//int bitmap = arg.GetNumber(2)
	//int help_string = arg.GetNumber(3)
	//int kind = arg.GetNumber(4)
	//pThis->GetEntity()->InsertTool();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonToolBar, InsertDropdownTool)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "help_string", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, InsertDropdownTool)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int tool_id = arg.GetNumber(1)
	//int bitmap = arg.GetNumber(2)
	//int help_string = arg.GetNumber(3)
	//pThis->GetEntity()->InsertDropdownTool();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonToolBar, InsertHybridTool)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "help_string", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, InsertHybridTool)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int tool_id = arg.GetNumber(1)
	//int bitmap = arg.GetNumber(2)
	//int help_string = arg.GetNumber(3)
	//pThis->GetEntity()->InsertHybridTool();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonToolBar, InsertToggleTool)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "help_string", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, InsertToggleTool)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int tool_id = arg.GetNumber(1)
	//int bitmap = arg.GetNumber(2)
	//int help_string = arg.GetNumber(3)
	//pThis->GetEntity()->InsertToggleTool();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonToolBar, InsertTool_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap_disabled", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "help_string", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "kind", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "client_data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, InsertTool_1)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int tool_id = arg.GetNumber(1)
	//int bitmap = arg.GetNumber(2)
	//int bitmap_disabled = arg.GetNumber(3)
	//int help_string = arg.GetNumber(4)
	//int kind = arg.GetNumber(5)
	//int client_data = arg.GetNumber(6)
	//pThis->GetEntity()->InsertTool();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonToolBar, InsertSeparator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, InsertSeparator)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->InsertSeparator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonToolBar, ClearTools)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonToolBar, ClearTools)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ClearTools();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonToolBar, DeleteTool)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, DeleteTool)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteTool();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonToolBar, DeleteToolByPos)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, DeleteToolByPos)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteToolByPos();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonToolBar, FindById)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, FindById)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//pThis->GetEntity()->FindById();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonToolBar, GetToolByPos)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonToolBar, GetToolByPos)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetToolByPos();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonToolBar, GetToolId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, GetToolId)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool = arg.GetNumber(0)
	//pThis->GetEntity()->GetToolId();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonToolBar, GetToolClientData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, GetToolClientData)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//pThis->GetEntity()->GetToolClientData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonToolBar, GetToolEnabled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, GetToolEnabled)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//pThis->GetEntity()->GetToolEnabled();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonToolBar, GetToolHelpString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, GetToolHelpString)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//pThis->GetEntity()->GetToolHelpString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonToolBar, GetToolKind)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, GetToolKind)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//pThis->GetEntity()->GetToolKind();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonToolBar, GetToolPos)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, GetToolPos)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//pThis->GetEntity()->GetToolPos();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonToolBar, GetToolState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, GetToolState)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//pThis->GetEntity()->GetToolState();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonToolBar, Realize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonToolBar, Realize)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Realize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonToolBar, SetRows)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nMin", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nMax", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, SetRows)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int nMin = arg.GetNumber(0)
	//int nMax = arg.GetNumber(1)
	//pThis->GetEntity()->SetRows();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonToolBar, SetToolClientData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, SetToolClientData)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//int clientData = arg.GetNumber(1)
	//pThis->GetEntity()->SetToolClientData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonToolBar, SetToolDisabledBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, SetToolDisabledBitmap)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//int bitmap = arg.GetNumber(1)
	//pThis->GetEntity()->SetToolDisabledBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonToolBar, SetToolHelpString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "helpString", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, SetToolHelpString)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//int helpString = arg.GetNumber(1)
	//pThis->GetEntity()->SetToolHelpString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonToolBar, SetToolNormalBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, SetToolNormalBitmap)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//int bitmap = arg.GetNumber(1)
	//pThis->GetEntity()->SetToolNormalBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonToolBar, EnableTool)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, EnableTool)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//int enable = arg.GetNumber(1)
	//pThis->GetEntity()->EnableTool();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonToolBar, ToggleTool)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "checked", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, ToggleTool)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//int checked = arg.GetNumber(1)
	//pThis->GetEntity()->ToggleTool();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRibbonToolBar
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RibbonToolBar)
{
	Gura_AssignMethod(wx_RibbonToolBar, wxRibbonToolBar);
	Gura_AssignMethod(wx_RibbonToolBar, wxRibbonToolBar_1);
	Gura_AssignMethod(wx_RibbonToolBar, Create);
	Gura_AssignMethod(wx_RibbonToolBar, AddTool);
	Gura_AssignMethod(wx_RibbonToolBar, AddDropdownTool);
	Gura_AssignMethod(wx_RibbonToolBar, AddHybridTool);
	Gura_AssignMethod(wx_RibbonToolBar, AddToggleTool);
	Gura_AssignMethod(wx_RibbonToolBar, AddTool_1);
	Gura_AssignMethod(wx_RibbonToolBar, AddSeparator);
	Gura_AssignMethod(wx_RibbonToolBar, InsertTool);
	Gura_AssignMethod(wx_RibbonToolBar, InsertDropdownTool);
	Gura_AssignMethod(wx_RibbonToolBar, InsertHybridTool);
	Gura_AssignMethod(wx_RibbonToolBar, InsertToggleTool);
	Gura_AssignMethod(wx_RibbonToolBar, InsertTool_1);
	Gura_AssignMethod(wx_RibbonToolBar, InsertSeparator);
	Gura_AssignMethod(wx_RibbonToolBar, ClearTools);
	Gura_AssignMethod(wx_RibbonToolBar, DeleteTool);
	Gura_AssignMethod(wx_RibbonToolBar, DeleteToolByPos);
	Gura_AssignMethod(wx_RibbonToolBar, FindById);
	Gura_AssignMethod(wx_RibbonToolBar, GetToolByPos);
	Gura_AssignMethod(wx_RibbonToolBar, GetToolId);
	Gura_AssignMethod(wx_RibbonToolBar, GetToolClientData);
	Gura_AssignMethod(wx_RibbonToolBar, GetToolEnabled);
	Gura_AssignMethod(wx_RibbonToolBar, GetToolHelpString);
	Gura_AssignMethod(wx_RibbonToolBar, GetToolKind);
	Gura_AssignMethod(wx_RibbonToolBar, GetToolPos);
	Gura_AssignMethod(wx_RibbonToolBar, GetToolState);
	Gura_AssignMethod(wx_RibbonToolBar, Realize);
	Gura_AssignMethod(wx_RibbonToolBar, SetRows);
	Gura_AssignMethod(wx_RibbonToolBar, SetToolClientData);
	Gura_AssignMethod(wx_RibbonToolBar, SetToolDisabledBitmap);
	Gura_AssignMethod(wx_RibbonToolBar, SetToolHelpString);
	Gura_AssignMethod(wx_RibbonToolBar, SetToolNormalBitmap);
	Gura_AssignMethod(wx_RibbonToolBar, EnableTool);
	Gura_AssignMethod(wx_RibbonToolBar, ToggleTool);
}

Gura_ImplementDescendantCreator(wx_RibbonToolBar)
{
	return new Object_wx_RibbonToolBar((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
