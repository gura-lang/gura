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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_ToolBar, wxToolBar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBar, wxToolBar)
{
	Signal &sig = env.GetSignal();
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxToolBar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBar, wxToolBar_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, wxToolBar_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int name = arg.GetNumber(5)
	//pThis->GetEntity()->wxToolBar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBar, ~wxToolBar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBar, ~wxToolBar)
{
	Signal &sig = env.GetSignal();
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxToolBar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBar, AddCheckTool)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "toolId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bmpDisabled", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "shortHelp", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "longHelp", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, AddCheckTool)
{
	Signal &sig = env.GetSignal();
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int toolId = arg.GetNumber(0)
	//int label = arg.GetNumber(1)
	//int bitmap1 = arg.GetNumber(2)
	//int bmpDisabled = arg.GetNumber(3)
	//int shortHelp = arg.GetNumber(4)
	//int longHelp = arg.GetNumber(5)
	//int clientData = arg.GetNumber(6)
	//pThis->GetEntity()->AddCheckTool();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBar, AddControl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "control", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, AddControl)
{
	Signal &sig = env.GetSignal();
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int control = arg.GetNumber(0)
	//int label = arg.GetNumber(1)
	//pThis->GetEntity()->AddControl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBar, AddRadioTool)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "toolId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bmpDisabled", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "shortHelp", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "longHelp", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, AddRadioTool)
{
	Signal &sig = env.GetSignal();
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int toolId = arg.GetNumber(0)
	//int label = arg.GetNumber(1)
	//int bitmap1 = arg.GetNumber(2)
	//int bmpDisabled = arg.GetNumber(3)
	//int shortHelp = arg.GetNumber(4)
	//int longHelp = arg.GetNumber(5)
	//int clientData = arg.GetNumber(6)
	//pThis->GetEntity()->AddRadioTool();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBar, AddSeparator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBar, AddSeparator)
{
	Signal &sig = env.GetSignal();
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->AddSeparator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBar, AddStretchableSpace)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBar, AddStretchableSpace)
{
	Signal &sig = env.GetSignal();
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->AddStretchableSpace();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBar, AddTool)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tool", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, AddTool)
{
	Signal &sig = env.GetSignal();
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int tool = arg.GetNumber(0)
	//pThis->GetEntity()->AddTool();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBar, AddTool_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "toolId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "shortHelp", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "kind", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, AddTool_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int toolId = arg.GetNumber(0)
	//int label = arg.GetNumber(1)
	//int bitmap = arg.GetNumber(2)
	//int shortHelp = arg.GetNumber(3)
	//int kind = arg.GetNumber(4)
	//pThis->GetEntity()->AddTool();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBar, AddTool_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "toolId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bmpDisabled", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "kind", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "shortHelpString", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "longHelpString", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, AddTool_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int toolId = arg.GetNumber(0)
	//int label = arg.GetNumber(1)
	//int bitmap = arg.GetNumber(2)
	//int bmpDisabled = arg.GetNumber(3)
	//int kind = arg.GetNumber(4)
	//int shortHelpString = arg.GetNumber(5)
	//int longHelpString = arg.GetNumber(6)
	//int clientData = arg.GetNumber(7)
	//pThis->GetEntity()->AddTool();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBar, ClearTools)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBar, ClearTools)
{
	Signal &sig = env.GetSignal();
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->ClearTools();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBar, DeleteTool)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "toolId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, DeleteTool)
{
	Signal &sig = env.GetSignal();
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int toolId = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteTool();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBar, DeleteToolByPos)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, DeleteToolByPos)
{
	Signal &sig = env.GetSignal();
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteToolByPos();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBar, EnableTool)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "toolId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, EnableTool)
{
	Signal &sig = env.GetSignal();
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int toolId = arg.GetNumber(0)
	//int enable = arg.GetNumber(1)
	//pThis->GetEntity()->EnableTool();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBar, FindById)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, FindById)
{
	Signal &sig = env.GetSignal();
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->FindById();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBar, FindControl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, FindControl)
{
	Signal &sig = env.GetSignal();
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->FindControl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBar, FindToolForPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, FindToolForPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->FindToolForPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBar, GetMargins)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBar, GetMargins)
{
	Signal &sig = env.GetSignal();
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetMargins();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBar, GetToolBitmapSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBar, GetToolBitmapSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetToolBitmapSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBar, GetToolByPos)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, GetToolByPos)
{
	Signal &sig = env.GetSignal();
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->GetToolByPos();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBar, GetToolClientData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "toolId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, GetToolClientData)
{
	Signal &sig = env.GetSignal();
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int toolId = arg.GetNumber(0)
	//pThis->GetEntity()->GetToolClientData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBar, GetToolEnabled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "toolId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, GetToolEnabled)
{
	Signal &sig = env.GetSignal();
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int toolId = arg.GetNumber(0)
	//pThis->GetEntity()->GetToolEnabled();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBar, GetToolLongHelp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "toolId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, GetToolLongHelp)
{
	Signal &sig = env.GetSignal();
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int toolId = arg.GetNumber(0)
	//pThis->GetEntity()->GetToolLongHelp();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBar, GetToolPacking)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBar, GetToolPacking)
{
	Signal &sig = env.GetSignal();
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetToolPacking();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBar, GetToolPos)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "toolId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, GetToolPos)
{
	Signal &sig = env.GetSignal();
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int toolId = arg.GetNumber(0)
	//pThis->GetEntity()->GetToolPos();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBar, GetToolSeparation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBar, GetToolSeparation)
{
	Signal &sig = env.GetSignal();
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetToolSeparation();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBar, GetToolShortHelp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "toolId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, GetToolShortHelp)
{
	Signal &sig = env.GetSignal();
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int toolId = arg.GetNumber(0)
	//pThis->GetEntity()->GetToolShortHelp();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBar, GetToolSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBar, GetToolSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetToolSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBar, GetToolState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "toolId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, GetToolState)
{
	Signal &sig = env.GetSignal();
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int toolId = arg.GetNumber(0)
	//pThis->GetEntity()->GetToolState();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBar, GetToolsCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBar, GetToolsCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetToolsCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBar, InsertControl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "control", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, InsertControl)
{
	Signal &sig = env.GetSignal();
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int control = arg.GetNumber(1)
	//int label = arg.GetNumber(2)
	//pThis->GetEntity()->InsertControl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBar, InsertSeparator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, InsertSeparator)
{
	Signal &sig = env.GetSignal();
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->InsertSeparator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBar, InsertStretchableSpace)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, InsertStretchableSpace)
{
	Signal &sig = env.GetSignal();
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->InsertStretchableSpace();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBar, InsertTool)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
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

Gura_ImplementMethod(wx_ToolBar, InsertTool)
{
	Signal &sig = env.GetSignal();
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int toolId = arg.GetNumber(1)
	//int label = arg.GetNumber(2)
	//int bitmap = arg.GetNumber(3)
	//int bmpDisabled = arg.GetNumber(4)
	//int kind = arg.GetNumber(5)
	//int shortHelp = arg.GetNumber(6)
	//int longHelp = arg.GetNumber(7)
	//int clientData = arg.GetNumber(8)
	//pThis->GetEntity()->InsertTool();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBar, InsertTool_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tool", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, InsertTool_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int tool = arg.GetNumber(1)
	//pThis->GetEntity()->InsertTool();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBar, OnLeftClick)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "toolId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "toggleDown", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, OnLeftClick)
{
	Signal &sig = env.GetSignal();
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int toolId = arg.GetNumber(0)
	//int toggleDown = arg.GetNumber(1)
	//pThis->GetEntity()->OnLeftClick();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBar, OnMouseEnter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "toolId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, OnMouseEnter)
{
	Signal &sig = env.GetSignal();
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int toolId = arg.GetNumber(0)
	//pThis->GetEntity()->OnMouseEnter();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBar, OnRightClick)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "toolId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, OnRightClick)
{
	Signal &sig = env.GetSignal();
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int toolId = arg.GetNumber(0)
	//int x = arg.GetNumber(1)
	//int y = arg.GetNumber(2)
	//pThis->GetEntity()->OnRightClick();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBar, Realize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBar, Realize)
{
	Signal &sig = env.GetSignal();
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Realize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBar, RemoveTool)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, RemoveTool)
{
	Signal &sig = env.GetSignal();
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveTool();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBar, SetDropdownMenu)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "menu", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, SetDropdownMenu)
{
	Signal &sig = env.GetSignal();
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int menu = arg.GetNumber(1)
	//pThis->GetEntity()->SetDropdownMenu();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBar, SetMargins)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, SetMargins)
{
	Signal &sig = env.GetSignal();
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->SetMargins();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBar, SetMargins_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, SetMargins_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->SetMargins();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBar, SetToolBitmapSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, SetToolBitmapSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->SetToolBitmapSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBar, SetToolClientData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, SetToolClientData)
{
	Signal &sig = env.GetSignal();
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int clientData = arg.GetNumber(1)
	//pThis->GetEntity()->SetToolClientData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBar, SetToolDisabledBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, SetToolDisabledBitmap)
{
	Signal &sig = env.GetSignal();
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int bitmap = arg.GetNumber(1)
	//pThis->GetEntity()->SetToolDisabledBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBar, SetToolLongHelp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "toolId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "helpString", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, SetToolLongHelp)
{
	Signal &sig = env.GetSignal();
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int toolId = arg.GetNumber(0)
	//int helpString = arg.GetNumber(1)
	//pThis->GetEntity()->SetToolLongHelp();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBar, SetToolNormalBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, SetToolNormalBitmap)
{
	Signal &sig = env.GetSignal();
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int bitmap = arg.GetNumber(1)
	//pThis->GetEntity()->SetToolNormalBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBar, SetToolPacking)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "packing", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, SetToolPacking)
{
	Signal &sig = env.GetSignal();
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int packing = arg.GetNumber(0)
	//pThis->GetEntity()->SetToolPacking();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBar, SetToolSeparation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "separation", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, SetToolSeparation)
{
	Signal &sig = env.GetSignal();
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int separation = arg.GetNumber(0)
	//pThis->GetEntity()->SetToolSeparation();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBar, SetToolShortHelp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "toolId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "helpString", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, SetToolShortHelp)
{
	Signal &sig = env.GetSignal();
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int toolId = arg.GetNumber(0)
	//int helpString = arg.GetNumber(1)
	//pThis->GetEntity()->SetToolShortHelp();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBar, ToggleTool)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "toolId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "toggle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, ToggleTool)
{
	Signal &sig = env.GetSignal();
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int toolId = arg.GetNumber(0)
	//int toggle = arg.GetNumber(1)
	//pThis->GetEntity()->ToggleTool();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBar, CreateTool)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "toolId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bmpNormal", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bmpDisabled", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "kind", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "shortHelp", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "longHelp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, CreateTool)
{
	Signal &sig = env.GetSignal();
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int toolId = arg.GetNumber(0)
	//int label = arg.GetNumber(1)
	//int bmpNormal = arg.GetNumber(2)
	//int bmpDisabled = arg.GetNumber(3)
	//int kind = arg.GetNumber(4)
	//int clientData = arg.GetNumber(5)
	//int shortHelp = arg.GetNumber(6)
	//int longHelp = arg.GetNumber(7)
	//pThis->GetEntity()->CreateTool();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBar, CreateTool_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "control", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBar, CreateTool_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int control = arg.GetNumber(0)
	//int label = arg.GetNumber(1)
	//pThis->GetEntity()->CreateTool();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBar, CreateSeparator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBar, CreateSeparator)
{
	Signal &sig = env.GetSignal();
	Object_wx_ToolBar *pThis = Object_wx_ToolBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CreateSeparator();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxToolBar
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ToolBar)
{
	Gura_AssignMethod(wx_ToolBar, wxToolBar);
	Gura_AssignMethod(wx_ToolBar, wxToolBar_1);
	Gura_AssignMethod(wx_ToolBar, ~wxToolBar);
	Gura_AssignMethod(wx_ToolBar, AddCheckTool);
	Gura_AssignMethod(wx_ToolBar, AddControl);
	Gura_AssignMethod(wx_ToolBar, AddRadioTool);
	Gura_AssignMethod(wx_ToolBar, AddSeparator);
	Gura_AssignMethod(wx_ToolBar, AddStretchableSpace);
	Gura_AssignMethod(wx_ToolBar, AddTool);
	Gura_AssignMethod(wx_ToolBar, AddTool_1);
	Gura_AssignMethod(wx_ToolBar, AddTool_2);
	Gura_AssignMethod(wx_ToolBar, ClearTools);
	Gura_AssignMethod(wx_ToolBar, DeleteTool);
	Gura_AssignMethod(wx_ToolBar, DeleteToolByPos);
	Gura_AssignMethod(wx_ToolBar, EnableTool);
	Gura_AssignMethod(wx_ToolBar, FindById);
	Gura_AssignMethod(wx_ToolBar, FindControl);
	Gura_AssignMethod(wx_ToolBar, FindToolForPosition);
	Gura_AssignMethod(wx_ToolBar, GetMargins);
	Gura_AssignMethod(wx_ToolBar, GetToolBitmapSize);
	Gura_AssignMethod(wx_ToolBar, GetToolByPos);
	Gura_AssignMethod(wx_ToolBar, GetToolClientData);
	Gura_AssignMethod(wx_ToolBar, GetToolEnabled);
	Gura_AssignMethod(wx_ToolBar, GetToolLongHelp);
	Gura_AssignMethod(wx_ToolBar, GetToolPacking);
	Gura_AssignMethod(wx_ToolBar, GetToolPos);
	Gura_AssignMethod(wx_ToolBar, GetToolSeparation);
	Gura_AssignMethod(wx_ToolBar, GetToolShortHelp);
	Gura_AssignMethod(wx_ToolBar, GetToolSize);
	Gura_AssignMethod(wx_ToolBar, GetToolState);
	Gura_AssignMethod(wx_ToolBar, GetToolsCount);
	Gura_AssignMethod(wx_ToolBar, InsertControl);
	Gura_AssignMethod(wx_ToolBar, InsertSeparator);
	Gura_AssignMethod(wx_ToolBar, InsertStretchableSpace);
	Gura_AssignMethod(wx_ToolBar, InsertTool);
	Gura_AssignMethod(wx_ToolBar, InsertTool_1);
	Gura_AssignMethod(wx_ToolBar, OnLeftClick);
	Gura_AssignMethod(wx_ToolBar, OnMouseEnter);
	Gura_AssignMethod(wx_ToolBar, OnRightClick);
	Gura_AssignMethod(wx_ToolBar, Realize);
	Gura_AssignMethod(wx_ToolBar, RemoveTool);
	Gura_AssignMethod(wx_ToolBar, SetDropdownMenu);
	Gura_AssignMethod(wx_ToolBar, SetMargins);
	Gura_AssignMethod(wx_ToolBar, SetMargins_1);
	Gura_AssignMethod(wx_ToolBar, SetToolBitmapSize);
	Gura_AssignMethod(wx_ToolBar, SetToolClientData);
	Gura_AssignMethod(wx_ToolBar, SetToolDisabledBitmap);
	Gura_AssignMethod(wx_ToolBar, SetToolLongHelp);
	Gura_AssignMethod(wx_ToolBar, SetToolNormalBitmap);
	Gura_AssignMethod(wx_ToolBar, SetToolPacking);
	Gura_AssignMethod(wx_ToolBar, SetToolSeparation);
	Gura_AssignMethod(wx_ToolBar, SetToolShortHelp);
	Gura_AssignMethod(wx_ToolBar, ToggleTool);
	Gura_AssignMethod(wx_ToolBar, CreateTool);
	Gura_AssignMethod(wx_ToolBar, CreateTool_1);
	Gura_AssignMethod(wx_ToolBar, CreateSeparator);
}

Gura_ImplementDescendantCreator(wx_ToolBar)
{
	return new Object_wx_ToolBar((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
