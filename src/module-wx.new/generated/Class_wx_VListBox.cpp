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
Gura_DeclareFunctionAlias(__VListBox, "VListBox")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_VListBox));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__VListBox)
{
	//wxVListBox();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__VListBox_1, "VListBox_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_VListBox));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__VListBox_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//long style = arg.GetNumber(4)
	//const wxString& name = arg.GetNumber(5)
	//wxVListBox(parent, id, pos, size, style, name);
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
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
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//long style = arg.GetNumber(4)
	//const wxString& name = arg.GetNumber(5)
	//bool _rtn = pThis->GetEntity()->Create(parent, id, pos, size, style, name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VListBox, __DeselectAll, "DeselectAll")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_VListBox, __DeselectAll)
{
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->DeselectAll();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VListBox, __GetFirstSelected, "GetFirstSelected")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "cookie", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VListBox, __GetFirstSelected)
{
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned long& cookie = arg.GetNumber(0)
	//int _rtn = pThis->GetEntity()->GetFirstSelected(cookie);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VListBox, __GetItemCount, "GetItemCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_VListBox, __GetItemCount)
{
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t _rtn = pThis->GetEntity()->GetItemCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VListBox, __GetMargins, "GetMargins")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_VListBox, __GetMargins)
{
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPoint _rtn = pThis->GetEntity()->GetMargins();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VListBox, __GetItemRect, "GetItemRect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VListBox, __GetItemRect)
{
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t item = arg.GetNumber(0)
	//wxRect _rtn = pThis->GetEntity()->GetItemRect(item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VListBox, __GetNextSelected, "GetNextSelected")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "cookie", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VListBox, __GetNextSelected)
{
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned long& cookie = arg.GetNumber(0)
	//int _rtn = pThis->GetEntity()->GetNextSelected(cookie);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VListBox, __GetSelectedCount, "GetSelectedCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_VListBox, __GetSelectedCount)
{
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t _rtn = pThis->GetEntity()->GetSelectedCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VListBox, __GetSelection, "GetSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_VListBox, __GetSelection)
{
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VListBox, __GetSelectionBackground, "GetSelectionBackground")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_VListBox, __GetSelectionBackground)
{
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& _rtn = pThis->GetEntity()->GetSelectionBackground();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VListBox, __HasMultipleSelection, "HasMultipleSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_VListBox, __HasMultipleSelection)
{
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasMultipleSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VListBox, __IsCurrent, "IsCurrent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VListBox, __IsCurrent)
{
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t item = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->IsCurrent(item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VListBox, __IsSelected, "IsSelected")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VListBox, __IsSelected)
{
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t item = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->IsSelected(item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VListBox, __Select, "Select")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "select", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VListBox, __Select)
{
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t item = arg.GetNumber(0)
	//bool select = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->Select(item, select);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VListBox, __SelectAll, "SelectAll")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_VListBox, __SelectAll)
{
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->SelectAll();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VListBox, __SelectRange, "SelectRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VListBox, __SelectRange)
{
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t from = arg.GetNumber(0)
	//size_t to = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->SelectRange(from, to);
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
	//size_t count = arg.GetNumber(0)
	//pThis->GetEntity()->SetItemCount(count);
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
	//const wxPoint& pt = arg.GetNumber(0)
	//pThis->GetEntity()->SetMargins(pt);
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
	//wxCoord x = arg.GetNumber(0)
	//wxCoord y = arg.GetNumber(1)
	//pThis->GetEntity()->SetMargins(x, y);
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
	//pThis->GetEntity()->SetSelection(selection);
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
	//const wxColour& col = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelectionBackground(col);
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
	//size_t item = arg.GetNumber(0)
	//pThis->GetEntity()->Toggle(item);
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
	//wxDC& dc = arg.GetNumber(0)
	//const wxRect& rect = arg.GetNumber(1)
	//size_t n = arg.GetNumber(2)
	//pThis->GetEntity()->OnDrawItem(dc, rect, n);
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
	//wxDC& dc = arg.GetNumber(0)
	//const wxRect& rect = arg.GetNumber(1)
	//size_t n = arg.GetNumber(2)
	//pThis->GetEntity()->OnDrawBackground(dc, rect, n);
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
	//wxDC& dc = arg.GetNumber(0)
	//wxRect& rect = arg.GetNumber(1)
	//size_t n = arg.GetNumber(2)
	//pThis->GetEntity()->OnDrawSeparator(dc, rect, n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VListBox, __OnMeasureItem, "OnMeasureItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VListBox, __OnMeasureItem)
{
	Object_wx_VListBox *pThis = Object_wx_VListBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t n = arg.GetNumber(0)
	//wxCoord _rtn = pThis->GetEntity()->OnMeasureItem(n);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxVListBox
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_VListBox)
{
	// Constructor assignment
	Gura_AssignFunction(__VListBox);
	Gura_AssignFunction(__VListBox_1);
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
