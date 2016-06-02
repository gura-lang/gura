//----------------------------------------------------------------------------
// wxRibbonButtonBar
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRibbonButtonBar
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRibbonButtonBar
//----------------------------------------------------------------------------
Object_wx_RibbonButtonBar::~Object_wx_RibbonButtonBar()
{
}

Object *Object_wx_RibbonButtonBar::Clone() const
{
	return nullptr;
}

String Object_wx_RibbonButtonBar::ToString(bool exprFlag)
{
	String rtn("<wx.RibbonButtonBar:");
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
Gura_DeclareMethod(wx_RibbonButtonBar, wxRibbonButtonBar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonButtonBar, wxRibbonButtonBar)
{
	Object_wx_RibbonButtonBar *pThis = Object_wx_RibbonButtonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxRibbonButtonBar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonButtonBar, wxRibbonButtonBar_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonButtonBar, wxRibbonButtonBar_1)
{
	Object_wx_RibbonButtonBar *pThis = Object_wx_RibbonButtonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//pThis->GetEntity()->wxRibbonButtonBar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonButtonBar, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonButtonBar, Create)
{
	Object_wx_RibbonButtonBar *pThis = Object_wx_RibbonButtonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonButtonBar, AddButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "button_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "help_string", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "kind", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonButtonBar, AddButton)
{
	Object_wx_RibbonButtonBar *pThis = Object_wx_RibbonButtonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int button_id = arg.GetNumber(0)
	//int label = arg.GetNumber(1)
	//int bitmap = arg.GetNumber(2)
	//int help_string = arg.GetNumber(3)
	//int kind = arg.GetNumber(4)
	//pThis->GetEntity()->AddButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonButtonBar, AddDropdownButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "button_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "help_string", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonButtonBar, AddDropdownButton)
{
	Object_wx_RibbonButtonBar *pThis = Object_wx_RibbonButtonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int button_id = arg.GetNumber(0)
	//int label = arg.GetNumber(1)
	//int bitmap = arg.GetNumber(2)
	//int help_string = arg.GetNumber(3)
	//pThis->GetEntity()->AddDropdownButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonButtonBar, AddHybridButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "button_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "help_string", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonButtonBar, AddHybridButton)
{
	Object_wx_RibbonButtonBar *pThis = Object_wx_RibbonButtonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int button_id = arg.GetNumber(0)
	//int label = arg.GetNumber(1)
	//int bitmap = arg.GetNumber(2)
	//int help_string = arg.GetNumber(3)
	//pThis->GetEntity()->AddHybridButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonButtonBar, AddToggleButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "button_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "help_string", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonButtonBar, AddToggleButton)
{
	Object_wx_RibbonButtonBar *pThis = Object_wx_RibbonButtonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int button_id = arg.GetNumber(0)
	//int label = arg.GetNumber(1)
	//int bitmap = arg.GetNumber(2)
	//int help_string = arg.GetNumber(3)
	//pThis->GetEntity()->AddToggleButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonButtonBar, AddButton_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "button_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap_small", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap_disabled", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap_small_disabled", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "kind", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "help_string", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonButtonBar, AddButton_1)
{
	Object_wx_RibbonButtonBar *pThis = Object_wx_RibbonButtonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int button_id = arg.GetNumber(0)
	//int label = arg.GetNumber(1)
	//int bitmap = arg.GetNumber(2)
	//int bitmap_small = arg.GetNumber(3)
	//int bitmap_disabled = arg.GetNumber(4)
	//int bitmap_small_disabled = arg.GetNumber(5)
	//int kind = arg.GetNumber(6)
	//int help_string = arg.GetNumber(7)
	//pThis->GetEntity()->AddButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonButtonBar, InsertButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "button_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "help_string", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "kind", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonButtonBar, InsertButton)
{
	Object_wx_RibbonButtonBar *pThis = Object_wx_RibbonButtonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int button_id = arg.GetNumber(1)
	//int label = arg.GetNumber(2)
	//int bitmap = arg.GetNumber(3)
	//int help_string = arg.GetNumber(4)
	//int kind = arg.GetNumber(5)
	//pThis->GetEntity()->InsertButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonButtonBar, InsertDropdownButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "button_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "help_string", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonButtonBar, InsertDropdownButton)
{
	Object_wx_RibbonButtonBar *pThis = Object_wx_RibbonButtonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int button_id = arg.GetNumber(1)
	//int label = arg.GetNumber(2)
	//int bitmap = arg.GetNumber(3)
	//int help_string = arg.GetNumber(4)
	//pThis->GetEntity()->InsertDropdownButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonButtonBar, InsertHybridButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "button_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "help_string", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonButtonBar, InsertHybridButton)
{
	Object_wx_RibbonButtonBar *pThis = Object_wx_RibbonButtonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int button_id = arg.GetNumber(1)
	//int label = arg.GetNumber(2)
	//int bitmap = arg.GetNumber(3)
	//int help_string = arg.GetNumber(4)
	//pThis->GetEntity()->InsertHybridButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonButtonBar, InsertToggleButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "button_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "help_string", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonButtonBar, InsertToggleButton)
{
	Object_wx_RibbonButtonBar *pThis = Object_wx_RibbonButtonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int button_id = arg.GetNumber(1)
	//int label = arg.GetNumber(2)
	//int bitmap = arg.GetNumber(3)
	//int help_string = arg.GetNumber(4)
	//pThis->GetEntity()->InsertToggleButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonButtonBar, InsertButton_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "button_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap_small", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap_disabled", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap_small_disabled", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "kind", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "help_string", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonButtonBar, InsertButton_1)
{
	Object_wx_RibbonButtonBar *pThis = Object_wx_RibbonButtonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int button_id = arg.GetNumber(1)
	//int label = arg.GetNumber(2)
	//int bitmap = arg.GetNumber(3)
	//int bitmap_small = arg.GetNumber(4)
	//int bitmap_disabled = arg.GetNumber(5)
	//int bitmap_small_disabled = arg.GetNumber(6)
	//int kind = arg.GetNumber(7)
	//int help_string = arg.GetNumber(8)
	//pThis->GetEntity()->InsertButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonButtonBar, GetButtonCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonButtonBar, GetButtonCount)
{
	Object_wx_RibbonButtonBar *pThis = Object_wx_RibbonButtonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetButtonCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonButtonBar, SetItemClientObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonButtonBar, SetItemClientObject)
{
	Object_wx_RibbonButtonBar *pThis = Object_wx_RibbonButtonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemClientObject();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonButtonBar, GetItemClientObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonButtonBar, GetItemClientObject)
{
	Object_wx_RibbonButtonBar *pThis = Object_wx_RibbonButtonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemClientObject();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonButtonBar, SetItemClientData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonButtonBar, SetItemClientData)
{
	Object_wx_RibbonButtonBar *pThis = Object_wx_RibbonButtonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemClientData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonButtonBar, GetItemClientData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonButtonBar, GetItemClientData)
{
	Object_wx_RibbonButtonBar *pThis = Object_wx_RibbonButtonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemClientData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonButtonBar, GetItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonButtonBar, GetItem)
{
	Object_wx_RibbonButtonBar *pThis = Object_wx_RibbonButtonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->GetItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonButtonBar, GetItemById)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonButtonBar, GetItemById)
{
	Object_wx_RibbonButtonBar *pThis = Object_wx_RibbonButtonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemById();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonButtonBar, GetItemId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonButtonBar, GetItemId)
{
	Object_wx_RibbonButtonBar *pThis = Object_wx_RibbonButtonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetItemId();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonButtonBar, Realize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonButtonBar, Realize)
{
	Object_wx_RibbonButtonBar *pThis = Object_wx_RibbonButtonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Realize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonButtonBar, ClearButtons)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonButtonBar, ClearButtons)
{
	Object_wx_RibbonButtonBar *pThis = Object_wx_RibbonButtonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ClearButtons();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonButtonBar, DeleteButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "button_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonButtonBar, DeleteButton)
{
	Object_wx_RibbonButtonBar *pThis = Object_wx_RibbonButtonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int button_id = arg.GetNumber(0)
	//pThis->GetEntity()->DeleteButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonButtonBar, EnableButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "button_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonButtonBar, EnableButton)
{
	Object_wx_RibbonButtonBar *pThis = Object_wx_RibbonButtonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int button_id = arg.GetNumber(0)
	//int enable = arg.GetNumber(1)
	//pThis->GetEntity()->EnableButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonButtonBar, ToggleButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "button_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "checked", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonButtonBar, ToggleButton)
{
	Object_wx_RibbonButtonBar *pThis = Object_wx_RibbonButtonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int button_id = arg.GetNumber(0)
	//int checked = arg.GetNumber(1)
	//pThis->GetEntity()->ToggleButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonButtonBar, GetActiveItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonButtonBar, GetActiveItem)
{
	Object_wx_RibbonButtonBar *pThis = Object_wx_RibbonButtonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetActiveItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonButtonBar, GetHoveredItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonButtonBar, GetHoveredItem)
{
	Object_wx_RibbonButtonBar *pThis = Object_wx_RibbonButtonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHoveredItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonButtonBar, SetShowToolTipsForDisabled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "show", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonButtonBar, SetShowToolTipsForDisabled)
{
	Object_wx_RibbonButtonBar *pThis = Object_wx_RibbonButtonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int show = arg.GetNumber(0)
	//pThis->GetEntity()->SetShowToolTipsForDisabled();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonButtonBar, GetShowToolTipsForDisabled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonButtonBar, GetShowToolTipsForDisabled)
{
	Object_wx_RibbonButtonBar *pThis = Object_wx_RibbonButtonBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetShowToolTipsForDisabled();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRibbonButtonBar
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RibbonButtonBar)
{
	Gura_AssignMethod(wx_RibbonButtonBar, wxRibbonButtonBar);
	Gura_AssignMethod(wx_RibbonButtonBar, wxRibbonButtonBar_1);
	Gura_AssignMethod(wx_RibbonButtonBar, Create);
	Gura_AssignMethod(wx_RibbonButtonBar, AddButton);
	Gura_AssignMethod(wx_RibbonButtonBar, AddDropdownButton);
	Gura_AssignMethod(wx_RibbonButtonBar, AddHybridButton);
	Gura_AssignMethod(wx_RibbonButtonBar, AddToggleButton);
	Gura_AssignMethod(wx_RibbonButtonBar, AddButton_1);
	Gura_AssignMethod(wx_RibbonButtonBar, InsertButton);
	Gura_AssignMethod(wx_RibbonButtonBar, InsertDropdownButton);
	Gura_AssignMethod(wx_RibbonButtonBar, InsertHybridButton);
	Gura_AssignMethod(wx_RibbonButtonBar, InsertToggleButton);
	Gura_AssignMethod(wx_RibbonButtonBar, InsertButton_1);
	Gura_AssignMethod(wx_RibbonButtonBar, GetButtonCount);
	Gura_AssignMethod(wx_RibbonButtonBar, SetItemClientObject);
	Gura_AssignMethod(wx_RibbonButtonBar, GetItemClientObject);
	Gura_AssignMethod(wx_RibbonButtonBar, SetItemClientData);
	Gura_AssignMethod(wx_RibbonButtonBar, GetItemClientData);
	Gura_AssignMethod(wx_RibbonButtonBar, GetItem);
	Gura_AssignMethod(wx_RibbonButtonBar, GetItemById);
	Gura_AssignMethod(wx_RibbonButtonBar, GetItemId);
	Gura_AssignMethod(wx_RibbonButtonBar, Realize);
	Gura_AssignMethod(wx_RibbonButtonBar, ClearButtons);
	Gura_AssignMethod(wx_RibbonButtonBar, DeleteButton);
	Gura_AssignMethod(wx_RibbonButtonBar, EnableButton);
	Gura_AssignMethod(wx_RibbonButtonBar, ToggleButton);
	Gura_AssignMethod(wx_RibbonButtonBar, GetActiveItem);
	Gura_AssignMethod(wx_RibbonButtonBar, GetHoveredItem);
	Gura_AssignMethod(wx_RibbonButtonBar, SetShowToolTipsForDisabled);
	Gura_AssignMethod(wx_RibbonButtonBar, GetShowToolTipsForDisabled);
}

Gura_ImplementDescendantCreator(wx_RibbonButtonBar)
{
	return new Object_wx_RibbonButtonBar((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
