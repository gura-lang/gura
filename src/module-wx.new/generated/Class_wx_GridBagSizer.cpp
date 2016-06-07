//----------------------------------------------------------------------------
// wxGridBagSizer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGridBagSizer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridBagSizer
//----------------------------------------------------------------------------
Object_wx_GridBagSizer::~Object_wx_GridBagSizer()
{
}

Object *Object_wx_GridBagSizer::Clone() const
{
	return nullptr;
}

String Object_wx_GridBagSizer::ToString(bool exprFlag)
{
	String rtn("<wx.GridBagSizer:");
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
Gura_DeclareFunctionAlias(__GridBagSizer, "GridBagSizer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "vgap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "hgap", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_GridBagSizer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__GridBagSizer)
{
	//int vgap = arg.GetNumber(0)
	//int hgap = arg.GetNumber(1)
	//wxGridBagSizer(vgap, hgap);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_GridBagSizer, __Add, "Add")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "span", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "border", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "userData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridBagSizer, __Add)
{
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* window = arg.GetNumber(0)
	//const wxGBPosition& pos = arg.GetNumber(1)
	//const wxGBSpan& span = arg.GetNumber(2)
	//int flag = arg.GetNumber(3)
	//int border = arg.GetNumber(4)
	//wxObject* userData = arg.GetNumber(5)
	//pThis->GetEntity()->Add(window, pos, span, flag, border, userData);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridBagSizer, __Add_1, "Add_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "span", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "border", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "userData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridBagSizer, __Add_1)
{
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxSizer* sizer = arg.GetNumber(0)
	//const wxGBPosition& pos = arg.GetNumber(1)
	//const wxGBSpan& span = arg.GetNumber(2)
	//int flag = arg.GetNumber(3)
	//int border = arg.GetNumber(4)
	//wxObject* userData = arg.GetNumber(5)
	//pThis->GetEntity()->Add(sizer, pos, span, flag, border, userData);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridBagSizer, __Add_2, "Add_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridBagSizer, __Add_2)
{
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxGBSizerItem* item = arg.GetNumber(0)
	//pThis->GetEntity()->Add(item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridBagSizer, __Add_3, "Add_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "span", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "border", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "userData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridBagSizer, __Add_3)
{
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//int height = arg.GetNumber(1)
	//const wxGBPosition& pos = arg.GetNumber(2)
	//const wxGBSpan& span = arg.GetNumber(3)
	//int flag = arg.GetNumber(4)
	//int border = arg.GetNumber(5)
	//wxObject* userData = arg.GetNumber(6)
	//pThis->GetEntity()->Add(width, height, pos, span, flag, border, userData);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridBagSizer, __CalcMin, "CalcMin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridBagSizer, __CalcMin)
{
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CalcMin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridBagSizer, __CheckForIntersection, "CheckForIntersection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "excludeItem", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridBagSizer, __CheckForIntersection)
{
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxGBSizerItem* item = arg.GetNumber(0)
	//wxGBSizerItem* excludeItem = arg.GetNumber(1)
	//pThis->GetEntity()->CheckForIntersection(item, excludeItem);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridBagSizer, __CheckForIntersection_1, "CheckForIntersection_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "span", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "excludeItem", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridBagSizer, __CheckForIntersection_1)
{
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxGBPosition& pos = arg.GetNumber(0)
	//const wxGBSpan& span = arg.GetNumber(1)
	//wxGBSizerItem* excludeItem = arg.GetNumber(2)
	//pThis->GetEntity()->CheckForIntersection(pos, span, excludeItem);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridBagSizer, __FindItem, "FindItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridBagSizer, __FindItem)
{
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* window = arg.GetNumber(0)
	//pThis->GetEntity()->FindItem(window);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridBagSizer, __FindItem_1, "FindItem_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridBagSizer, __FindItem_1)
{
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxSizer* sizer = arg.GetNumber(0)
	//pThis->GetEntity()->FindItem(sizer);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridBagSizer, __FindItemAtPoint, "FindItemAtPoint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridBagSizer, __FindItemAtPoint)
{
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint& pt = arg.GetNumber(0)
	//pThis->GetEntity()->FindItemAtPoint(pt);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridBagSizer, __FindItemAtPosition, "FindItemAtPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridBagSizer, __FindItemAtPosition)
{
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxGBPosition& pos = arg.GetNumber(0)
	//pThis->GetEntity()->FindItemAtPosition(pos);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridBagSizer, __FindItemWithData, "FindItemWithData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "userData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridBagSizer, __FindItemWithData)
{
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxObject* userData = arg.GetNumber(0)
	//pThis->GetEntity()->FindItemWithData(userData);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridBagSizer, __GetCellSize, "GetCellSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridBagSizer, __GetCellSize)
{
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//pThis->GetEntity()->GetCellSize(row, col);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridBagSizer, __GetEmptyCellSize, "GetEmptyCellSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridBagSizer, __GetEmptyCellSize)
{
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEmptyCellSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridBagSizer, __GetItemPosition, "GetItemPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridBagSizer, __GetItemPosition)
{
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* window = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemPosition(window);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridBagSizer, __GetItemPosition_1, "GetItemPosition_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridBagSizer, __GetItemPosition_1)
{
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxSizer* sizer = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemPosition(sizer);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridBagSizer, __GetItemPosition_2, "GetItemPosition_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridBagSizer, __GetItemPosition_2)
{
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t index = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemPosition(index);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridBagSizer, __GetItemSpan, "GetItemSpan")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridBagSizer, __GetItemSpan)
{
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* window = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemSpan(window);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridBagSizer, __GetItemSpan_1, "GetItemSpan_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridBagSizer, __GetItemSpan_1)
{
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxSizer* sizer = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemSpan(sizer);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridBagSizer, __GetItemSpan_2, "GetItemSpan_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridBagSizer, __GetItemSpan_2)
{
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t index = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemSpan(index);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridBagSizer, __RecalcSizes, "RecalcSizes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridBagSizer, __RecalcSizes)
{
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->RecalcSizes();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridBagSizer, __SetEmptyCellSize, "SetEmptyCellSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridBagSizer, __SetEmptyCellSize)
{
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxSize& sz = arg.GetNumber(0)
	//pThis->GetEntity()->SetEmptyCellSize(sz);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridBagSizer, __SetItemPosition, "SetItemPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridBagSizer, __SetItemPosition)
{
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* window = arg.GetNumber(0)
	//const wxGBPosition& pos = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemPosition(window, pos);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridBagSizer, __SetItemPosition_1, "SetItemPosition_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridBagSizer, __SetItemPosition_1)
{
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxSizer* sizer = arg.GetNumber(0)
	//const wxGBPosition& pos = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemPosition(sizer, pos);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridBagSizer, __SetItemPosition_2, "SetItemPosition_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridBagSizer, __SetItemPosition_2)
{
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t index = arg.GetNumber(0)
	//const wxGBPosition& pos = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemPosition(index, pos);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridBagSizer, __SetItemSpan, "SetItemSpan")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "span", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridBagSizer, __SetItemSpan)
{
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* window = arg.GetNumber(0)
	//const wxGBSpan& span = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemSpan(window, span);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridBagSizer, __SetItemSpan_1, "SetItemSpan_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "span", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridBagSizer, __SetItemSpan_1)
{
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxSizer* sizer = arg.GetNumber(0)
	//const wxGBSpan& span = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemSpan(sizer, span);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridBagSizer, __SetItemSpan_2, "SetItemSpan_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "span", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridBagSizer, __SetItemSpan_2)
{
	Object_wx_GridBagSizer *pThis = Object_wx_GridBagSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t index = arg.GetNumber(0)
	//const wxGBSpan& span = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemSpan(index, span);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGridBagSizer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridBagSizer)
{
	// Constructor assignment
	Gura_AssignFunction(__GridBagSizer);
	// Method assignment
	Gura_AssignMethod(wx_GridBagSizer, __Add);
	Gura_AssignMethod(wx_GridBagSizer, __Add_1);
	Gura_AssignMethod(wx_GridBagSizer, __Add_2);
	Gura_AssignMethod(wx_GridBagSizer, __Add_3);
	Gura_AssignMethod(wx_GridBagSizer, __CalcMin);
	Gura_AssignMethod(wx_GridBagSizer, __CheckForIntersection);
	Gura_AssignMethod(wx_GridBagSizer, __CheckForIntersection_1);
	Gura_AssignMethod(wx_GridBagSizer, __FindItem);
	Gura_AssignMethod(wx_GridBagSizer, __FindItem_1);
	Gura_AssignMethod(wx_GridBagSizer, __FindItemAtPoint);
	Gura_AssignMethod(wx_GridBagSizer, __FindItemAtPosition);
	Gura_AssignMethod(wx_GridBagSizer, __FindItemWithData);
	Gura_AssignMethod(wx_GridBagSizer, __GetCellSize);
	Gura_AssignMethod(wx_GridBagSizer, __GetEmptyCellSize);
	Gura_AssignMethod(wx_GridBagSizer, __GetItemPosition);
	Gura_AssignMethod(wx_GridBagSizer, __GetItemPosition_1);
	Gura_AssignMethod(wx_GridBagSizer, __GetItemPosition_2);
	Gura_AssignMethod(wx_GridBagSizer, __GetItemSpan);
	Gura_AssignMethod(wx_GridBagSizer, __GetItemSpan_1);
	Gura_AssignMethod(wx_GridBagSizer, __GetItemSpan_2);
	Gura_AssignMethod(wx_GridBagSizer, __RecalcSizes);
	Gura_AssignMethod(wx_GridBagSizer, __SetEmptyCellSize);
	Gura_AssignMethod(wx_GridBagSizer, __SetItemPosition);
	Gura_AssignMethod(wx_GridBagSizer, __SetItemPosition_1);
	Gura_AssignMethod(wx_GridBagSizer, __SetItemPosition_2);
	Gura_AssignMethod(wx_GridBagSizer, __SetItemSpan);
	Gura_AssignMethod(wx_GridBagSizer, __SetItemSpan_1);
	Gura_AssignMethod(wx_GridBagSizer, __SetItemSpan_2);
}

Gura_ImplementDescendantCreator(wx_GridBagSizer)
{
	return new Object_wx_GridBagSizer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
