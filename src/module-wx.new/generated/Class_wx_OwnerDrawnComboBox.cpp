//----------------------------------------------------------------------------
// wxOwnerDrawnComboBox
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxOwnerDrawnComboBox
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxOwnerDrawnComboBox
//----------------------------------------------------------------------------
Object_wx_OwnerDrawnComboBox::~Object_wx_OwnerDrawnComboBox()
{
}

Object *Object_wx_OwnerDrawnComboBox::Clone() const
{
	return nullptr;
}

String Object_wx_OwnerDrawnComboBox::ToString(bool exprFlag)
{
	String rtn("<wx.OwnerDrawnComboBox:");
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
Gura_DeclareFunctionAlias(__OwnerDrawnComboBox, "OwnerDrawnComboBox")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_OwnerDrawnComboBox));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__OwnerDrawnComboBox)
{
	//wxOwnerDrawnComboBox();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__OwnerDrawnComboBox_1, "OwnerDrawnComboBox_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "_arg6", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_OwnerDrawnComboBox));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__OwnerDrawnComboBox_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxString& value = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//int n = arg.GetNumber(5)
	//const wxString choices[] _arg6 = arg.GetNumber(6)
	//long style = arg.GetNumber(7)
	//const wxValidator& validator = arg.GetNumber(8)
	//const wxString& name = arg.GetNumber(9)
	//wxOwnerDrawnComboBox(parent, id, value, pos, size, n, _arg6, style, validator, name);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__OwnerDrawnComboBox_2, "OwnerDrawnComboBox_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "choices", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_OwnerDrawnComboBox));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__OwnerDrawnComboBox_2)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxString& value = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//const wxArrayString& choices = arg.GetNumber(5)
	//long style = arg.GetNumber(6)
	//const wxValidator& validator = arg.GetNumber(7)
	//const wxString& name = arg.GetNumber(8)
	//wxOwnerDrawnComboBox(parent, id, value, pos, size, choices, style, validator, name);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_OwnerDrawnComboBox, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_OwnerDrawnComboBox, __Create)
{
	Object_wx_OwnerDrawnComboBox *pThis = Object_wx_OwnerDrawnComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxString& value = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//long style = arg.GetNumber(5)
	//const wxValidator& validator = arg.GetNumber(6)
	//const wxString& name = arg.GetNumber(7)
	//bool _rtn = pThis->GetEntity()->Create(parent, id, value, pos, size, style, validator, name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_OwnerDrawnComboBox, __Create_1, "Create_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "choices", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_OwnerDrawnComboBox, __Create_1)
{
	Object_wx_OwnerDrawnComboBox *pThis = Object_wx_OwnerDrawnComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxString& value = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//int n = arg.GetNumber(5)
	//const wxString choices = arg.GetNumber(6)
	//long style = arg.GetNumber(7)
	//const wxValidator& validator = arg.GetNumber(8)
	//const wxString& name = arg.GetNumber(9)
	//bool _rtn = pThis->GetEntity()->Create(parent, id, value, pos, size, n, choices, style, validator, name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_OwnerDrawnComboBox, __Create_2, "Create_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "choices", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_OwnerDrawnComboBox, __Create_2)
{
	Object_wx_OwnerDrawnComboBox *pThis = Object_wx_OwnerDrawnComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxString& value = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//const wxArrayString& choices = arg.GetNumber(5)
	//long style = arg.GetNumber(6)
	//const wxValidator& validator = arg.GetNumber(7)
	//const wxString& name = arg.GetNumber(8)
	//bool _rtn = pThis->GetEntity()->Create(parent, id, value, pos, size, choices, style, validator, name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_OwnerDrawnComboBox, __IsEmpty, "IsEmpty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_OwnerDrawnComboBox, __IsEmpty)
{
	Object_wx_OwnerDrawnComboBox *pThis = Object_wx_OwnerDrawnComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsEmpty();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_OwnerDrawnComboBox, __IsListEmpty, "IsListEmpty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_OwnerDrawnComboBox, __IsListEmpty)
{
	Object_wx_OwnerDrawnComboBox *pThis = Object_wx_OwnerDrawnComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsListEmpty();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_OwnerDrawnComboBox, __IsTextEmpty, "IsTextEmpty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_OwnerDrawnComboBox, __IsTextEmpty)
{
	Object_wx_OwnerDrawnComboBox *pThis = Object_wx_OwnerDrawnComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsTextEmpty();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_OwnerDrawnComboBox, __GetWidestItem, "GetWidestItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_OwnerDrawnComboBox, __GetWidestItem)
{
	Object_wx_OwnerDrawnComboBox *pThis = Object_wx_OwnerDrawnComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetWidestItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_OwnerDrawnComboBox, __GetWidestItemWidth, "GetWidestItemWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_OwnerDrawnComboBox, __GetWidestItemWidth)
{
	Object_wx_OwnerDrawnComboBox *pThis = Object_wx_OwnerDrawnComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetWidestItemWidth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_OwnerDrawnComboBox, __OnDrawBackground, "OnDrawBackground")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_OwnerDrawnComboBox, __OnDrawBackground)
{
	Object_wx_OwnerDrawnComboBox *pThis = Object_wx_OwnerDrawnComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//const wxRect& rect = arg.GetNumber(1)
	//int item = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//pThis->GetEntity()->OnDrawBackground(dc, rect, item, flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_OwnerDrawnComboBox, __OnDrawItem, "OnDrawItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_OwnerDrawnComboBox, __OnDrawItem)
{
	Object_wx_OwnerDrawnComboBox *pThis = Object_wx_OwnerDrawnComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//const wxRect& rect = arg.GetNumber(1)
	//int item = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//pThis->GetEntity()->OnDrawItem(dc, rect, item, flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_OwnerDrawnComboBox, __OnMeasureItem, "OnMeasureItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_OwnerDrawnComboBox, __OnMeasureItem)
{
	Object_wx_OwnerDrawnComboBox *pThis = Object_wx_OwnerDrawnComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t item = arg.GetNumber(0)
	//wxCoord _rtn = pThis->GetEntity()->OnMeasureItem(item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_OwnerDrawnComboBox, __OnMeasureItemWidth, "OnMeasureItemWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_OwnerDrawnComboBox, __OnMeasureItemWidth)
{
	Object_wx_OwnerDrawnComboBox *pThis = Object_wx_OwnerDrawnComboBox::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t item = arg.GetNumber(0)
	//wxCoord _rtn = pThis->GetEntity()->OnMeasureItemWidth(item);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxOwnerDrawnComboBox
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_OwnerDrawnComboBox)
{
	// Constructor assignment
	Gura_AssignFunction(__OwnerDrawnComboBox);
	Gura_AssignFunction(__OwnerDrawnComboBox_1);
	Gura_AssignFunction(__OwnerDrawnComboBox_2);
	// Method assignment
	Gura_AssignMethod(wx_OwnerDrawnComboBox, __Create);
	Gura_AssignMethod(wx_OwnerDrawnComboBox, __Create_1);
	Gura_AssignMethod(wx_OwnerDrawnComboBox, __Create_2);
	Gura_AssignMethod(wx_OwnerDrawnComboBox, __IsEmpty);
	Gura_AssignMethod(wx_OwnerDrawnComboBox, __IsListEmpty);
	Gura_AssignMethod(wx_OwnerDrawnComboBox, __IsTextEmpty);
	Gura_AssignMethod(wx_OwnerDrawnComboBox, __GetWidestItem);
	Gura_AssignMethod(wx_OwnerDrawnComboBox, __GetWidestItemWidth);
	Gura_AssignMethod(wx_OwnerDrawnComboBox, __OnDrawBackground);
	Gura_AssignMethod(wx_OwnerDrawnComboBox, __OnDrawItem);
	Gura_AssignMethod(wx_OwnerDrawnComboBox, __OnMeasureItem);
	Gura_AssignMethod(wx_OwnerDrawnComboBox, __OnMeasureItemWidth);
}

Gura_ImplementDescendantCreator(wx_OwnerDrawnComboBox)
{
	return new Object_wx_OwnerDrawnComboBox((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
