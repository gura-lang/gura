//----------------------------------------------------------------------------
// wxToolBar
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxToolBar
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxToolBar
//----------------------------------------------------------------------------
Object_wx_ToolBar::~Object_wx_ToolBar()
{
}

Object *Object_wx_ToolBar::Clone() const
{
	return nullptr;
}

String Object_wx_ToolBar::ToString(bool exprFlag)
{
	String rtn("<wx.ToolBar:");
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
Gura_DeclareFunctionAlias(__ToolBar, "ToolBar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_ToolBar));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__ToolBar)
{
	//wxToolBar();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__ToolBar_1, "ToolBar_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_ToolBar));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__ToolBar_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//long style = arg.GetNumber(4)
	//const wxString& name = arg.GetNumber(5)
	//wxToolBar(parent, id, pos, size, style, name);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_ToolBar, __AddCheckTool, "AddCheckTool")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "toolId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bmpDisabled", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "shortHelp", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "longHelp", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, __AddCheckTool)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int toolId = arg.GetNumber(0)
	//const wxString& label = arg.GetNumber(1)
	//const wxBitmap& bitmap1 = arg.GetNumber(2)
	//const wxBitmap& bmpDisabled = arg.GetNumber(3)
	//const wxString& shortHelp = arg.GetNumber(4)
	//const wxString& longHelp = arg.GetNumber(5)
	//wxObject* clientData = arg.GetNumber(6)
	//wxToolBarToolBase* _rtn = pThis->GetEntity()->AddCheckTool(toolId, label, bitmap1, bmpDisabled, shortHelp, longHelp, clientData);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBar, __AddControl, "AddControl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "control", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, __AddControl)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxControl* control = arg.GetNumber(0)
	//const wxString& label = arg.GetNumber(1)
	//wxToolBarToolBase* _rtn = pThis->GetEntity()->AddControl(control, label);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBar, __AddRadioTool, "AddRadioTool")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "toolId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bmpDisabled", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "shortHelp", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "longHelp", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, __AddRadioTool)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int toolId = arg.GetNumber(0)
	//const wxString& label = arg.GetNumber(1)
	//const wxBitmap& bitmap1 = arg.GetNumber(2)
	//const wxBitmap& bmpDisabled = arg.GetNumber(3)
	//const wxString& shortHelp = arg.GetNumber(4)
	//const wxString& longHelp = arg.GetNumber(5)
	//wxObject* clientData = arg.GetNumber(6)
	//wxToolBarToolBase* _rtn = pThis->GetEntity()->AddRadioTool(toolId, label, bitmap1, bmpDisabled, shortHelp, longHelp, clientData);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBar, __AddSeparator, "AddSeparator")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBar, __AddSeparator)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxToolBarToolBase* _rtn = pThis->GetEntity()->AddSeparator();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBar, __AddStretchableSpace, "AddStretchableSpace")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBar, __AddStretchableSpace)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxToolBarToolBase* _rtn = pThis->GetEntity()->AddStretchableSpace();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBar, __AddTool, "AddTool")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "tool", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, __AddTool)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxToolBarToolBase* tool = arg.GetNumber(0)
	//wxToolBarToolBase* _rtn = pThis->GetEntity()->AddTool(tool);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBar, __AddTool_1, "AddTool_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "toolId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "shortHelp", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "kind", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, __AddTool_1)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int toolId = arg.GetNumber(0)
	//const wxString& label = arg.GetNumber(1)
	//const wxBitmap& bitmap = arg.GetNumber(2)
	//const wxString& shortHelp = arg.GetNumber(3)
	//wxItemKind kind = arg.GetNumber(4)
	//wxToolBarToolBase* _rtn = pThis->GetEntity()->AddTool(toolId, label, bitmap, shortHelp, kind);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBar, __AddTool_2, "AddTool_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "toolId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bmpDisabled", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "kind", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "shortHelpString", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "longHelpString", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, __AddTool_2)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int toolId = arg.GetNumber(0)
	//const wxString& label = arg.GetNumber(1)
	//const wxBitmap& bitmap = arg.GetNumber(2)
	//const wxBitmap& bmpDisabled = arg.GetNumber(3)
	//wxItemKind kind = arg.GetNumber(4)
	//const wxString& shortHelpString = arg.GetNumber(5)
	//const wxString& longHelpString = arg.GetNumber(6)
	//wxObject* clientData = arg.GetNumber(7)
	//wxToolBarToolBase* _rtn = pThis->GetEntity()->AddTool(toolId, label, bitmap, bmpDisabled, kind, shortHelpString, longHelpString, clientData);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBar, __ClearTools, "ClearTools")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBar, __ClearTools)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ClearTools();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBar, __DeleteTool, "DeleteTool")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "toolId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, __DeleteTool)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int toolId = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->DeleteTool(toolId);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBar, __DeleteToolByPos, "DeleteToolByPos")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, __DeleteToolByPos)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t pos = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->DeleteToolByPos(pos);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBar, __EnableTool, "EnableTool")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "toolId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, __EnableTool)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int toolId = arg.GetNumber(0)
	//bool enable = arg.GetNumber(1)
	//pThis->GetEntity()->EnableTool(toolId, enable);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBar, __FindById, "FindById")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, __FindById)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//wxToolBarToolBase* _rtn = pThis->GetEntity()->FindById(id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBar, __FindControl, "FindControl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, __FindControl)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//wxControl* _rtn = pThis->GetEntity()->FindControl(id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBar, __FindToolForPosition, "FindToolForPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, __FindToolForPosition)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCoord x = arg.GetNumber(0)
	//wxCoord y = arg.GetNumber(1)
	//wxToolBarToolBase* _rtn = pThis->GetEntity()->FindToolForPosition(x, y);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBar, __GetMargins, "GetMargins")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBar, __GetMargins)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxSize _rtn = pThis->GetEntity()->GetMargins();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBar, __GetToolBitmapSize, "GetToolBitmapSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBar, __GetToolBitmapSize)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxSize _rtn = pThis->GetEntity()->GetToolBitmapSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBar, __GetToolByPos, "GetToolByPos")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, __GetToolByPos)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//const wxToolBarToolBase* _rtn = pThis->GetEntity()->GetToolByPos(pos);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBar, __GetToolClientData, "GetToolClientData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "toolId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, __GetToolClientData)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int toolId = arg.GetNumber(0)
	//wxObject* _rtn = pThis->GetEntity()->GetToolClientData(toolId);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBar, __GetToolEnabled, "GetToolEnabled")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "toolId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, __GetToolEnabled)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int toolId = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->GetToolEnabled(toolId);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBar, __GetToolLongHelp, "GetToolLongHelp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "toolId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, __GetToolLongHelp)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int toolId = arg.GetNumber(0)
	//wxString _rtn = pThis->GetEntity()->GetToolLongHelp(toolId);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBar, __GetToolPacking, "GetToolPacking")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBar, __GetToolPacking)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetToolPacking();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBar, __GetToolPos, "GetToolPos")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "toolId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, __GetToolPos)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int toolId = arg.GetNumber(0)
	//int _rtn = pThis->GetEntity()->GetToolPos(toolId);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBar, __GetToolSeparation, "GetToolSeparation")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBar, __GetToolSeparation)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetToolSeparation();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBar, __GetToolShortHelp, "GetToolShortHelp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "toolId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, __GetToolShortHelp)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int toolId = arg.GetNumber(0)
	//wxString _rtn = pThis->GetEntity()->GetToolShortHelp(toolId);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBar, __GetToolSize, "GetToolSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBar, __GetToolSize)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxSize _rtn = pThis->GetEntity()->GetToolSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBar, __GetToolState, "GetToolState")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "toolId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, __GetToolState)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int toolId = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->GetToolState(toolId);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBar, __GetToolsCount, "GetToolsCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBar, __GetToolsCount)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t _rtn = pThis->GetEntity()->GetToolsCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBar, __InsertControl, "InsertControl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "control", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, __InsertControl)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t pos = arg.GetNumber(0)
	//wxControl* control = arg.GetNumber(1)
	//const wxString& label = arg.GetNumber(2)
	//wxToolBarToolBase* _rtn = pThis->GetEntity()->InsertControl(pos, control, label);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBar, __InsertSeparator, "InsertSeparator")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, __InsertSeparator)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t pos = arg.GetNumber(0)
	//wxToolBarToolBase* _rtn = pThis->GetEntity()->InsertSeparator(pos);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBar, __InsertStretchableSpace, "InsertStretchableSpace")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, __InsertStretchableSpace)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t pos = arg.GetNumber(0)
	//wxToolBarToolBase* _rtn = pThis->GetEntity()->InsertStretchableSpace(pos);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBar, __InsertTool, "InsertTool")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "toolId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bmpDisabled", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "kind", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "shortHelp", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "longHelp", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, __InsertTool)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t pos = arg.GetNumber(0)
	//int toolId = arg.GetNumber(1)
	//const wxString& label = arg.GetNumber(2)
	//const wxBitmap& bitmap = arg.GetNumber(3)
	//const wxBitmap& bmpDisabled = arg.GetNumber(4)
	//wxItemKind kind = arg.GetNumber(5)
	//const wxString& shortHelp = arg.GetNumber(6)
	//const wxString& longHelp = arg.GetNumber(7)
	//wxObject* clientData = arg.GetNumber(8)
	//wxToolBarToolBase* _rtn = pThis->GetEntity()->InsertTool(pos, toolId, label, bitmap, bmpDisabled, kind, shortHelp, longHelp, clientData);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBar, __InsertTool_1, "InsertTool_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tool", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, __InsertTool_1)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t pos = arg.GetNumber(0)
	//wxToolBarToolBase* tool = arg.GetNumber(1)
	//wxToolBarToolBase* _rtn = pThis->GetEntity()->InsertTool(pos, tool);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBar, __OnLeftClick, "OnLeftClick")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "toolId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "toggleDown", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, __OnLeftClick)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int toolId = arg.GetNumber(0)
	//bool toggleDown = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->OnLeftClick(toolId, toggleDown);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBar, __OnMouseEnter, "OnMouseEnter")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "toolId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, __OnMouseEnter)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int toolId = arg.GetNumber(0)
	//pThis->GetEntity()->OnMouseEnter(toolId);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBar, __OnRightClick, "OnRightClick")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "toolId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, __OnRightClick)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int toolId = arg.GetNumber(0)
	//long x = arg.GetNumber(1)
	//long y = arg.GetNumber(2)
	//pThis->GetEntity()->OnRightClick(toolId, x, y);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBar, __Realize, "Realize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBar, __Realize)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->Realize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBar, __RemoveTool, "RemoveTool")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, __RemoveTool)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//wxToolBarToolBase* _rtn = pThis->GetEntity()->RemoveTool(id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBar, __SetDropdownMenu, "SetDropdownMenu")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "menu", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, __SetDropdownMenu)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//wxMenu* menu = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->SetDropdownMenu(id, menu);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBar, __SetMargins, "SetMargins")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, __SetMargins)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->SetMargins(x, y);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBar, __SetMargins_1, "SetMargins_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, __SetMargins_1)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxSize& size = arg.GetNumber(0)
	//pThis->GetEntity()->SetMargins(size);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBar, __SetToolBitmapSize, "SetToolBitmapSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, __SetToolBitmapSize)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxSize& size = arg.GetNumber(0)
	//pThis->GetEntity()->SetToolBitmapSize(size);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBar, __SetToolClientData, "SetToolClientData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, __SetToolClientData)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//wxObject* clientData = arg.GetNumber(1)
	//pThis->GetEntity()->SetToolClientData(id, clientData);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBar, __SetToolDisabledBitmap, "SetToolDisabledBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, __SetToolDisabledBitmap)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//const wxBitmap& bitmap = arg.GetNumber(1)
	//pThis->GetEntity()->SetToolDisabledBitmap(id, bitmap);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBar, __SetToolLongHelp, "SetToolLongHelp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "toolId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "helpString", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, __SetToolLongHelp)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int toolId = arg.GetNumber(0)
	//const wxString& helpString = arg.GetNumber(1)
	//pThis->GetEntity()->SetToolLongHelp(toolId, helpString);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBar, __SetToolNormalBitmap, "SetToolNormalBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, __SetToolNormalBitmap)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//const wxBitmap& bitmap = arg.GetNumber(1)
	//pThis->GetEntity()->SetToolNormalBitmap(id, bitmap);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBar, __SetToolPacking, "SetToolPacking")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "packing", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, __SetToolPacking)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int packing = arg.GetNumber(0)
	//pThis->GetEntity()->SetToolPacking(packing);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBar, __SetToolSeparation, "SetToolSeparation")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "separation", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, __SetToolSeparation)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int separation = arg.GetNumber(0)
	//pThis->GetEntity()->SetToolSeparation(separation);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBar, __SetToolShortHelp, "SetToolShortHelp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "toolId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "helpString", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, __SetToolShortHelp)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int toolId = arg.GetNumber(0)
	//const wxString& helpString = arg.GetNumber(1)
	//pThis->GetEntity()->SetToolShortHelp(toolId, helpString);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBar, __ToggleTool, "ToggleTool")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "toolId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "toggle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, __ToggleTool)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int toolId = arg.GetNumber(0)
	//bool toggle = arg.GetNumber(1)
	//pThis->GetEntity()->ToggleTool(toolId, toggle);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBar, __CreateTool, "CreateTool")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "toolId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bmpNormal", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bmpDisabled", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "kind", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "shortHelp", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "longHelp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, __CreateTool)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int toolId = arg.GetNumber(0)
	//const wxString& label = arg.GetNumber(1)
	//const wxBitmap& bmpNormal = arg.GetNumber(2)
	//const wxBitmap& bmpDisabled = arg.GetNumber(3)
	//wxItemKind kind = arg.GetNumber(4)
	//wxObject* clientData = arg.GetNumber(5)
	//const wxString& shortHelp = arg.GetNumber(6)
	//const wxString& longHelp = arg.GetNumber(7)
	//wxToolBarToolBase* _rtn = pThis->GetEntity()->CreateTool(toolId, label, bmpNormal, bmpDisabled, kind, clientData, shortHelp, longHelp);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBar, __CreateTool_1, "CreateTool_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "control", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, __CreateTool_1)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxControl* control = arg.GetNumber(0)
	//const wxString& label = arg.GetNumber(1)
	//wxToolBarToolBase* _rtn = pThis->GetEntity()->CreateTool(control, label);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBar, __CreateSeparator, "CreateSeparator")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBar, __CreateSeparator)
{
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxToolBarToolBase* _rtn = pThis->GetEntity()->CreateSeparator();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxToolBar
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ToolBar)
{
	// Constructor assignment
	Gura_AssignFunction(__ToolBar);
	Gura_AssignFunction(__ToolBar_1);
	// Method assignment
	Gura_AssignMethod(wx_ToolBar, __AddCheckTool);
	Gura_AssignMethod(wx_ToolBar, __AddControl);
	Gura_AssignMethod(wx_ToolBar, __AddRadioTool);
	Gura_AssignMethod(wx_ToolBar, __AddSeparator);
	Gura_AssignMethod(wx_ToolBar, __AddStretchableSpace);
	Gura_AssignMethod(wx_ToolBar, __AddTool);
	Gura_AssignMethod(wx_ToolBar, __AddTool_1);
	Gura_AssignMethod(wx_ToolBar, __AddTool_2);
	Gura_AssignMethod(wx_ToolBar, __ClearTools);
	Gura_AssignMethod(wx_ToolBar, __DeleteTool);
	Gura_AssignMethod(wx_ToolBar, __DeleteToolByPos);
	Gura_AssignMethod(wx_ToolBar, __EnableTool);
	Gura_AssignMethod(wx_ToolBar, __FindById);
	Gura_AssignMethod(wx_ToolBar, __FindControl);
	Gura_AssignMethod(wx_ToolBar, __FindToolForPosition);
	Gura_AssignMethod(wx_ToolBar, __GetMargins);
	Gura_AssignMethod(wx_ToolBar, __GetToolBitmapSize);
	Gura_AssignMethod(wx_ToolBar, __GetToolByPos);
	Gura_AssignMethod(wx_ToolBar, __GetToolClientData);
	Gura_AssignMethod(wx_ToolBar, __GetToolEnabled);
	Gura_AssignMethod(wx_ToolBar, __GetToolLongHelp);
	Gura_AssignMethod(wx_ToolBar, __GetToolPacking);
	Gura_AssignMethod(wx_ToolBar, __GetToolPos);
	Gura_AssignMethod(wx_ToolBar, __GetToolSeparation);
	Gura_AssignMethod(wx_ToolBar, __GetToolShortHelp);
	Gura_AssignMethod(wx_ToolBar, __GetToolSize);
	Gura_AssignMethod(wx_ToolBar, __GetToolState);
	Gura_AssignMethod(wx_ToolBar, __GetToolsCount);
	Gura_AssignMethod(wx_ToolBar, __InsertControl);
	Gura_AssignMethod(wx_ToolBar, __InsertSeparator);
	Gura_AssignMethod(wx_ToolBar, __InsertStretchableSpace);
	Gura_AssignMethod(wx_ToolBar, __InsertTool);
	Gura_AssignMethod(wx_ToolBar, __InsertTool_1);
	Gura_AssignMethod(wx_ToolBar, __OnLeftClick);
	Gura_AssignMethod(wx_ToolBar, __OnMouseEnter);
	Gura_AssignMethod(wx_ToolBar, __OnRightClick);
	Gura_AssignMethod(wx_ToolBar, __Realize);
	Gura_AssignMethod(wx_ToolBar, __RemoveTool);
	Gura_AssignMethod(wx_ToolBar, __SetDropdownMenu);
	Gura_AssignMethod(wx_ToolBar, __SetMargins);
	Gura_AssignMethod(wx_ToolBar, __SetMargins_1);
	Gura_AssignMethod(wx_ToolBar, __SetToolBitmapSize);
	Gura_AssignMethod(wx_ToolBar, __SetToolClientData);
	Gura_AssignMethod(wx_ToolBar, __SetToolDisabledBitmap);
	Gura_AssignMethod(wx_ToolBar, __SetToolLongHelp);
	Gura_AssignMethod(wx_ToolBar, __SetToolNormalBitmap);
	Gura_AssignMethod(wx_ToolBar, __SetToolPacking);
	Gura_AssignMethod(wx_ToolBar, __SetToolSeparation);
	Gura_AssignMethod(wx_ToolBar, __SetToolShortHelp);
	Gura_AssignMethod(wx_ToolBar, __ToggleTool);
	Gura_AssignMethod(wx_ToolBar, __CreateTool);
	Gura_AssignMethod(wx_ToolBar, __CreateTool_1);
	Gura_AssignMethod(wx_ToolBar, __CreateSeparator);
}

Gura_ImplementDescendantCreator(wx_ToolBar)
{
	return new Object_wx_ToolBar((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
