//----------------------------------------------------------------------------
// wxVListBox
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxVListBox
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxVListBox
//----------------------------------------------------------------------------
Object_wx_VListBox::~Object_wx_VListBox()
{
}

Object *Object_wx_VListBox::Clone() const
{
	return nullptr;
}

String Object_wx_VListBox::ToString(bool exprFlag)
{
	String rtn("<wx.VListBox:");
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
Gura_DeclareFunctionAlias(__wxVListBox, "wxVListBox")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_VListBox));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxVListBox)
{
	//wxVListBox();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxVListBox_1, "wxVListBox_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_VListBox));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxVListBox_1)
{
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int name = arg.GetNumber(5)
	//wxVListBox();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_VListBox, __Clear, "Clear")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VListBox, __Clear)
{
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VListBox, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VListBox, __Create)
{
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int name = arg.GetNumber(5)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VListBox, __DeselectAll, "DeselectAll")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VListBox, __DeselectAll)
{
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DeselectAll();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VListBox, __GetFirstSelected, "GetFirstSelected")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cookie", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VListBox, __GetFirstSelected)
{
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int cookie = arg.GetNumber(0)
	//pThis->GetEntity()->GetFirstSelected();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VListBox, __GetItemCount, "GetItemCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VListBox, __GetItemCount)
{
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetItemCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VListBox, __GetMargins, "GetMargins")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VListBox, __GetMargins)
{
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMargins();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VListBox, __GetItemRect, "GetItemRect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VListBox, __GetItemRect)
{
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemRect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VListBox, __GetNextSelected, "GetNextSelected")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cookie", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VListBox, __GetNextSelected)
{
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int cookie = arg.GetNumber(0)
	//pThis->GetEntity()->GetNextSelected();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VListBox, __GetSelectedCount, "GetSelectedCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VListBox, __GetSelectedCount)
{
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelectedCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VListBox, __GetSelection, "GetSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VListBox, __GetSelection)
{
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VListBox, __GetSelectionBackground, "GetSelectionBackground")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VListBox, __GetSelectionBackground)
{
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelectionBackground();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VListBox, __HasMultipleSelection, "HasMultipleSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VListBox, __HasMultipleSelection)
{
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasMultipleSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VListBox, __IsCurrent, "IsCurrent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VListBox, __IsCurrent)
{
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->IsCurrent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VListBox, __IsSelected, "IsSelected")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VListBox, __IsSelected)
{
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->IsSelected();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VListBox, __Select, "Select")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "select", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VListBox, __Select)
{
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int select = arg.GetNumber(1)
	//pThis->GetEntity()->Select();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VListBox, __SelectAll, "SelectAll")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VListBox, __SelectAll)
{
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->SelectAll();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VListBox, __SelectRange, "SelectRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VListBox, __SelectRange)
{
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int from = arg.GetNumber(0)
	//int to = arg.GetNumber(1)
	//pThis->GetEntity()->SelectRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VListBox, __SetItemCount, "SetItemCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "count", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VListBox, __SetItemCount)
{
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int count = arg.GetNumber(0)
	//pThis->GetEntity()->SetItemCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VListBox, __SetMargins, "SetMargins")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VListBox, __SetMargins)
{
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pt = arg.GetNumber(0)
	//pThis->GetEntity()->SetMargins();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VListBox, __SetMargins_1, "SetMargins_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VListBox, __SetMargins_1)
{
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->SetMargins();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VListBox, __SetSelection, "SetSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "selection", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VListBox, __SetSelection)
{
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int selection = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VListBox, __SetSelectionBackground, "SetSelectionBackground")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VListBox, __SetSelectionBackground)
{
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelectionBackground();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VListBox, __Toggle, "Toggle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VListBox, __Toggle)
{
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->Toggle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VListBox, __OnDrawItem, "OnDrawItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VListBox, __OnDrawItem)
{
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int rect = arg.GetNumber(1)
	//int n = arg.GetNumber(2)
	//pThis->GetEntity()->OnDrawItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VListBox, __OnDrawBackground, "OnDrawBackground")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VListBox, __OnDrawBackground)
{
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int rect = arg.GetNumber(1)
	//int n = arg.GetNumber(2)
	//pThis->GetEntity()->OnDrawBackground();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VListBox, __OnDrawSeparator, "OnDrawSeparator")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VListBox, __OnDrawSeparator)
{
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int rect = arg.GetNumber(1)
	//int n = arg.GetNumber(2)
	//pThis->GetEntity()->OnDrawSeparator();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VListBox, __OnMeasureItem, "OnMeasureItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VListBox, __OnMeasureItem)
{
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->OnMeasureItem();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxVListBox
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_VListBox)
{
	// Constructor assignment
	Gura_AssignFunction(__wxVListBox);
	Gura_AssignFunction(__wxVListBox_1);
	// Method assignment
	Gura_AssignMethod(wx_VListBox, __Clear);
	Gura_AssignMethod(wx_VListBox, __Create);
	Gura_AssignMethod(wx_VListBox, __DeselectAll);
	Gura_AssignMethod(wx_VListBox, __GetFirstSelected);
	Gura_AssignMethod(wx_VListBox, __GetItemCount);
	Gura_AssignMethod(wx_VListBox, __GetMargins);
	Gura_AssignMethod(wx_VListBox, __GetItemRect);
	Gura_AssignMethod(wx_VListBox, __GetNextSelected);
	Gura_AssignMethod(wx_VListBox, __GetSelectedCount);
	Gura_AssignMethod(wx_VListBox, __GetSelection);
	Gura_AssignMethod(wx_VListBox, __GetSelectionBackground);
	Gura_AssignMethod(wx_VListBox, __HasMultipleSelection);
	Gura_AssignMethod(wx_VListBox, __IsCurrent);
	Gura_AssignMethod(wx_VListBox, __IsSelected);
	Gura_AssignMethod(wx_VListBox, __Select);
	Gura_AssignMethod(wx_VListBox, __SelectAll);
	Gura_AssignMethod(wx_VListBox, __SelectRange);
	Gura_AssignMethod(wx_VListBox, __SetItemCount);
	Gura_AssignMethod(wx_VListBox, __SetMargins);
	Gura_AssignMethod(wx_VListBox, __SetMargins_1);
	Gura_AssignMethod(wx_VListBox, __SetSelection);
	Gura_AssignMethod(wx_VListBox, __SetSelectionBackground);
	Gura_AssignMethod(wx_VListBox, __Toggle);
	Gura_AssignMethod(wx_VListBox, __OnDrawItem);
	Gura_AssignMethod(wx_VListBox, __OnDrawBackground);
	Gura_AssignMethod(wx_VListBox, __OnDrawSeparator);
	Gura_AssignMethod(wx_VListBox, __OnMeasureItem);
}

Gura_ImplementDescendantCreator(wx_VListBox)
{
	return new Object_wx_VListBox((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
