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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxRibbonToolBar, "wxRibbonToolBar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(__wxRibbonToolBar)
{
	//wxRibbonToolBar();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxRibbonToolBar_1, "wxRibbonToolBar_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxRibbonToolBar_1)
{
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//wxRibbonToolBar();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RibbonToolBar, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, __Create)
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

Gura_DeclareMethodAlias(wx_RibbonToolBar, __AddTool, "AddTool")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "help_string", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "kind", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, __AddTool)
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

Gura_DeclareMethodAlias(wx_RibbonToolBar, __AddDropdownTool, "AddDropdownTool")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "help_string", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, __AddDropdownTool)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//int bitmap = arg.GetNumber(1)
	//int help_string = arg.GetNumber(2)
	//pThis->GetEntity()->AddDropdownTool();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonToolBar, __AddHybridTool, "AddHybridTool")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "help_string", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, __AddHybridTool)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//int bitmap = arg.GetNumber(1)
	//int help_string = arg.GetNumber(2)
	//pThis->GetEntity()->AddHybridTool();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonToolBar, __AddToggleTool, "AddToggleTool")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "help_string", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, __AddToggleTool)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//int bitmap = arg.GetNumber(1)
	//int help_string = arg.GetNumber(2)
	//pThis->GetEntity()->AddToggleTool();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonToolBar, __AddTool_1, "AddTool_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap_disabled", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "help_string", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "kind", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "client_data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, __AddTool_1)
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

Gura_DeclareMethodAlias(wx_RibbonToolBar, __AddSeparator, "AddSeparator")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonToolBar, __AddSeparator)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AddSeparator();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonToolBar, __InsertTool, "InsertTool")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "help_string", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "kind", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, __InsertTool)
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

Gura_DeclareMethodAlias(wx_RibbonToolBar, __InsertDropdownTool, "InsertDropdownTool")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "help_string", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, __InsertDropdownTool)
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

Gura_DeclareMethodAlias(wx_RibbonToolBar, __InsertHybridTool, "InsertHybridTool")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "help_string", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, __InsertHybridTool)
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

Gura_DeclareMethodAlias(wx_RibbonToolBar, __InsertToggleTool, "InsertToggleTool")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "help_string", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, __InsertToggleTool)
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

Gura_DeclareMethodAlias(wx_RibbonToolBar, __InsertTool_1, "InsertTool_1")
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

Gura_ImplementMethod(wx_RibbonToolBar, __InsertTool_1)
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

Gura_DeclareMethodAlias(wx_RibbonToolBar, __InsertSeparator, "InsertSeparator")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, __InsertSeparator)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->InsertSeparator();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonToolBar, __ClearTools, "ClearTools")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonToolBar, __ClearTools)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ClearTools();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonToolBar, __DeleteTool, "DeleteTool")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, __DeleteTool)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteTool();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonToolBar, __DeleteToolByPos, "DeleteToolByPos")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, __DeleteToolByPos)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteToolByPos();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonToolBar, __FindById, "FindById")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, __FindById)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//pThis->GetEntity()->FindById();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonToolBar, __GetToolByPos, "GetToolByPos")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonToolBar, __GetToolByPos)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetToolByPos();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonToolBar, __GetToolId, "GetToolId")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, __GetToolId)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool = arg.GetNumber(0)
	//pThis->GetEntity()->GetToolId();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonToolBar, __GetToolClientData, "GetToolClientData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, __GetToolClientData)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//pThis->GetEntity()->GetToolClientData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonToolBar, __GetToolEnabled, "GetToolEnabled")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, __GetToolEnabled)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//pThis->GetEntity()->GetToolEnabled();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonToolBar, __GetToolHelpString, "GetToolHelpString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, __GetToolHelpString)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//pThis->GetEntity()->GetToolHelpString();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonToolBar, __GetToolKind, "GetToolKind")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, __GetToolKind)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//pThis->GetEntity()->GetToolKind();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonToolBar, __GetToolPos, "GetToolPos")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, __GetToolPos)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//pThis->GetEntity()->GetToolPos();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonToolBar, __GetToolState, "GetToolState")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, __GetToolState)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//pThis->GetEntity()->GetToolState();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonToolBar, __Realize, "Realize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonToolBar, __Realize)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Realize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonToolBar, __SetRows, "SetRows")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nMin", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nMax", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, __SetRows)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int nMin = arg.GetNumber(0)
	//int nMax = arg.GetNumber(1)
	//pThis->GetEntity()->SetRows();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonToolBar, __SetToolClientData, "SetToolClientData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, __SetToolClientData)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//int clientData = arg.GetNumber(1)
	//pThis->GetEntity()->SetToolClientData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonToolBar, __SetToolDisabledBitmap, "SetToolDisabledBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, __SetToolDisabledBitmap)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//int bitmap = arg.GetNumber(1)
	//pThis->GetEntity()->SetToolDisabledBitmap();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonToolBar, __SetToolHelpString, "SetToolHelpString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "helpString", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, __SetToolHelpString)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//int helpString = arg.GetNumber(1)
	//pThis->GetEntity()->SetToolHelpString();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonToolBar, __SetToolNormalBitmap, "SetToolNormalBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, __SetToolNormalBitmap)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//int bitmap = arg.GetNumber(1)
	//pThis->GetEntity()->SetToolNormalBitmap();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonToolBar, __EnableTool, "EnableTool")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, __EnableTool)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//int enable = arg.GetNumber(1)
	//pThis->GetEntity()->EnableTool();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonToolBar, __ToggleTool, "ToggleTool")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "checked", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, __ToggleTool)
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
	// Constructor assignment
	Gura_AssignFunction(__wxRibbonToolBar);
	Gura_AssignFunction(__wxRibbonToolBar_1);
	// Method assignment
	Gura_AssignMethod(wx_RibbonToolBar, __Create);
	Gura_AssignMethod(wx_RibbonToolBar, __AddTool);
	Gura_AssignMethod(wx_RibbonToolBar, __AddDropdownTool);
	Gura_AssignMethod(wx_RibbonToolBar, __AddHybridTool);
	Gura_AssignMethod(wx_RibbonToolBar, __AddToggleTool);
	Gura_AssignMethod(wx_RibbonToolBar, __AddTool_1);
	Gura_AssignMethod(wx_RibbonToolBar, __AddSeparator);
	Gura_AssignMethod(wx_RibbonToolBar, __InsertTool);
	Gura_AssignMethod(wx_RibbonToolBar, __InsertDropdownTool);
	Gura_AssignMethod(wx_RibbonToolBar, __InsertHybridTool);
	Gura_AssignMethod(wx_RibbonToolBar, __InsertToggleTool);
	Gura_AssignMethod(wx_RibbonToolBar, __InsertTool_1);
	Gura_AssignMethod(wx_RibbonToolBar, __InsertSeparator);
	Gura_AssignMethod(wx_RibbonToolBar, __ClearTools);
	Gura_AssignMethod(wx_RibbonToolBar, __DeleteTool);
	Gura_AssignMethod(wx_RibbonToolBar, __DeleteToolByPos);
	Gura_AssignMethod(wx_RibbonToolBar, __FindById);
	Gura_AssignMethod(wx_RibbonToolBar, __GetToolByPos);
	Gura_AssignMethod(wx_RibbonToolBar, __GetToolId);
	Gura_AssignMethod(wx_RibbonToolBar, __GetToolClientData);
	Gura_AssignMethod(wx_RibbonToolBar, __GetToolEnabled);
	Gura_AssignMethod(wx_RibbonToolBar, __GetToolHelpString);
	Gura_AssignMethod(wx_RibbonToolBar, __GetToolKind);
	Gura_AssignMethod(wx_RibbonToolBar, __GetToolPos);
	Gura_AssignMethod(wx_RibbonToolBar, __GetToolState);
	Gura_AssignMethod(wx_RibbonToolBar, __Realize);
	Gura_AssignMethod(wx_RibbonToolBar, __SetRows);
	Gura_AssignMethod(wx_RibbonToolBar, __SetToolClientData);
	Gura_AssignMethod(wx_RibbonToolBar, __SetToolDisabledBitmap);
	Gura_AssignMethod(wx_RibbonToolBar, __SetToolHelpString);
	Gura_AssignMethod(wx_RibbonToolBar, __SetToolNormalBitmap);
	Gura_AssignMethod(wx_RibbonToolBar, __EnableTool);
	Gura_AssignMethod(wx_RibbonToolBar, __ToggleTool);
}

Gura_ImplementDescendantCreator(wx_RibbonToolBar)
{
	return new Object_wx_RibbonToolBar((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
