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
Gura_DeclareFunctionAlias(__RibbonToolBar, "RibbonToolBar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_RibbonToolBar));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RibbonToolBar)
{
	//wxRibbonToolBar();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__RibbonToolBar_1, "RibbonToolBar_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RibbonToolBar));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RibbonToolBar_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//long style = arg.GetNumber(4)
	//wxRibbonToolBar(parent, id, pos, size, style);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RibbonToolBar, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
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
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//long style = arg.GetNumber(4)
	//bool _rtn = pThis->GetEntity()->Create(parent, id, pos, size, style);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonToolBar, __AddTool, "AddTool")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
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
	//const wxBitmap& bitmap = arg.GetNumber(1)
	//const wxString& help_string = arg.GetNumber(2)
	//wxRibbonButtonKind kind = arg.GetNumber(3)
	//wxRibbonToolBarToolBase* _rtn = pThis->GetEntity()->AddTool(tool_id, bitmap, help_string, kind);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonToolBar, __AddDropdownTool, "AddDropdownTool")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "help_string", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, __AddDropdownTool)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//const wxBitmap& bitmap = arg.GetNumber(1)
	//const wxString& help_string = arg.GetNumber(2)
	//wxRibbonToolBarToolBase* _rtn = pThis->GetEntity()->AddDropdownTool(tool_id, bitmap, help_string);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonToolBar, __AddHybridTool, "AddHybridTool")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "help_string", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, __AddHybridTool)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//const wxBitmap& bitmap = arg.GetNumber(1)
	//const wxString& help_string = arg.GetNumber(2)
	//wxRibbonToolBarToolBase* _rtn = pThis->GetEntity()->AddHybridTool(tool_id, bitmap, help_string);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonToolBar, __AddToggleTool, "AddToggleTool")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "help_string", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, __AddToggleTool)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//const wxBitmap& bitmap = arg.GetNumber(1)
	//const wxString& help_string = arg.GetNumber(2)
	//wxRibbonToolBarToolBase* _rtn = pThis->GetEntity()->AddToggleTool(tool_id, bitmap, help_string);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonToolBar, __AddTool_1, "AddTool_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
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
	//const wxBitmap& bitmap = arg.GetNumber(1)
	//const wxBitmap& bitmap_disabled = arg.GetNumber(2)
	//const wxString& help_string = arg.GetNumber(3)
	//wxRibbonButtonKind kind = arg.GetNumber(4)
	//wxObject* client_data = arg.GetNumber(5)
	//wxRibbonToolBarToolBase* _rtn = pThis->GetEntity()->AddTool(tool_id, bitmap, bitmap_disabled, help_string, kind, client_data);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonToolBar, __AddSeparator, "AddSeparator")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonToolBar, __AddSeparator)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRibbonToolBarToolBase* _rtn = pThis->GetEntity()->AddSeparator();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonToolBar, __InsertTool, "InsertTool")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
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
	//size_t pos = arg.GetNumber(0)
	//int tool_id = arg.GetNumber(1)
	//const wxBitmap& bitmap = arg.GetNumber(2)
	//const wxString& help_string = arg.GetNumber(3)
	//wxRibbonButtonKind kind = arg.GetNumber(4)
	//wxRibbonToolBarToolBase* _rtn = pThis->GetEntity()->InsertTool(pos, tool_id, bitmap, help_string, kind);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonToolBar, __InsertDropdownTool, "InsertDropdownTool")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "help_string", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, __InsertDropdownTool)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t pos = arg.GetNumber(0)
	//int tool_id = arg.GetNumber(1)
	//const wxBitmap& bitmap = arg.GetNumber(2)
	//const wxString& help_string = arg.GetNumber(3)
	//wxRibbonToolBarToolBase* _rtn = pThis->GetEntity()->InsertDropdownTool(pos, tool_id, bitmap, help_string);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonToolBar, __InsertHybridTool, "InsertHybridTool")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "help_string", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, __InsertHybridTool)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t pos = arg.GetNumber(0)
	//int tool_id = arg.GetNumber(1)
	//const wxBitmap& bitmap = arg.GetNumber(2)
	//const wxString& help_string = arg.GetNumber(3)
	//wxRibbonToolBarToolBase* _rtn = pThis->GetEntity()->InsertHybridTool(pos, tool_id, bitmap, help_string);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonToolBar, __InsertToggleTool, "InsertToggleTool")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "help_string", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, __InsertToggleTool)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t pos = arg.GetNumber(0)
	//int tool_id = arg.GetNumber(1)
	//const wxBitmap& bitmap = arg.GetNumber(2)
	//const wxString& help_string = arg.GetNumber(3)
	//wxRibbonToolBarToolBase* _rtn = pThis->GetEntity()->InsertToggleTool(pos, tool_id, bitmap, help_string);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonToolBar, __InsertTool_1, "InsertTool_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
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
	//size_t pos = arg.GetNumber(0)
	//int tool_id = arg.GetNumber(1)
	//const wxBitmap& bitmap = arg.GetNumber(2)
	//const wxBitmap& bitmap_disabled = arg.GetNumber(3)
	//const wxString& help_string = arg.GetNumber(4)
	//wxRibbonButtonKind kind = arg.GetNumber(5)
	//wxObject* client_data = arg.GetNumber(6)
	//wxRibbonToolBarToolBase* _rtn = pThis->GetEntity()->InsertTool(pos, tool_id, bitmap, bitmap_disabled, help_string, kind, client_data);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonToolBar, __InsertSeparator, "InsertSeparator")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, __InsertSeparator)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t pos = arg.GetNumber(0)
	//wxRibbonToolBarToolBase* _rtn = pThis->GetEntity()->InsertSeparator(pos);
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, __DeleteTool)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->DeleteTool(tool_id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonToolBar, __DeleteToolByPos, "DeleteToolByPos")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, __DeleteToolByPos)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t pos = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->DeleteToolByPos(pos);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonToolBar, __FindById, "FindById")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, __FindById)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//wxRibbonToolBarToolBase* _rtn = pThis->GetEntity()->FindById(tool_id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonToolBar, __GetToolByPos, "GetToolByPos")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, __GetToolByPos)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t pos = arg.GetNumber(0)
	//wxRibbonToolBarToolBase* _rtn = pThis->GetEntity()->GetToolByPos(pos);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonToolBar, __GetToolCount, "GetToolCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonToolBar, __GetToolCount)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t _rtn = pThis->GetEntity()->GetToolCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonToolBar, __GetToolId, "GetToolId")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "tool", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, __GetToolId)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRibbonToolBarToolBase* tool = arg.GetNumber(0)
	//int _rtn = pThis->GetEntity()->GetToolId(tool);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonToolBar, __GetToolClientData, "GetToolClientData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, __GetToolClientData)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//wxObject* _rtn = pThis->GetEntity()->GetToolClientData(tool_id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonToolBar, __GetToolEnabled, "GetToolEnabled")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, __GetToolEnabled)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->GetToolEnabled(tool_id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonToolBar, __GetToolHelpString, "GetToolHelpString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, __GetToolHelpString)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//wxString _rtn = pThis->GetEntity()->GetToolHelpString(tool_id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonToolBar, __GetToolKind, "GetToolKind")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, __GetToolKind)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//wxRibbonButtonKind _rtn = pThis->GetEntity()->GetToolKind(tool_id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonToolBar, __GetToolPos, "GetToolPos")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, __GetToolPos)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//int _rtn = pThis->GetEntity()->GetToolPos(tool_id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonToolBar, __GetToolState, "GetToolState")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "tool_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonToolBar, __GetToolState)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tool_id = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->GetToolState(tool_id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonToolBar, __Realize, "Realize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonToolBar, __Realize)
{
	Object_wx_RibbonToolBar *pThis = Object_wx_RibbonToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->Realize();
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
	//pThis->GetEntity()->SetRows(nMin, nMax);
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
	//wxObject* clientData = arg.GetNumber(1)
	//pThis->GetEntity()->SetToolClientData(tool_id, clientData);
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
	//const wxBitmap& bitmap = arg.GetNumber(1)
	//pThis->GetEntity()->SetToolDisabledBitmap(tool_id, bitmap);
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
	//const wxString& helpString = arg.GetNumber(1)
	//pThis->GetEntity()->SetToolHelpString(tool_id, helpString);
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
	//const wxBitmap& bitmap = arg.GetNumber(1)
	//pThis->GetEntity()->SetToolNormalBitmap(tool_id, bitmap);
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
	//bool enable = arg.GetNumber(1)
	//pThis->GetEntity()->EnableTool(tool_id, enable);
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
	//bool checked = arg.GetNumber(1)
	//pThis->GetEntity()->ToggleTool(tool_id, checked);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRibbonToolBar
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RibbonToolBar)
{
	// Constructor assignment
	Gura_AssignFunction(__RibbonToolBar);
	Gura_AssignFunction(__RibbonToolBar_1);
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
	Gura_AssignMethod(wx_RibbonToolBar, __GetToolCount);
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
