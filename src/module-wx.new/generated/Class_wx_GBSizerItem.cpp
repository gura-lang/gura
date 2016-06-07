//----------------------------------------------------------------------------
// wxGBSizerItem
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGBSizerItem
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGBSizerItem
//----------------------------------------------------------------------------
Object_wx_GBSizerItem::~Object_wx_GBSizerItem()
{
}

Object *Object_wx_GBSizerItem::Clone() const
{
	return nullptr;
}

String Object_wx_GBSizerItem::ToString(bool exprFlag)
{
	String rtn("<wx.GBSizerItem:");
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
Gura_DeclareFunctionAlias(__GBSizerItem, "GBSizerItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "span", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "border", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "userData", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_GBSizerItem));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__GBSizerItem)
{
	//int width = arg.GetNumber(0)
	//int height = arg.GetNumber(1)
	//const wxGBPosition& pos = arg.GetNumber(2)
	//const wxGBSpan& span = arg.GetNumber(3)
	//int flag = arg.GetNumber(4)
	//int border = arg.GetNumber(5)
	//wxObject* userData = arg.GetNumber(6)
	//wxGBSizerItem(width, height, pos, span, flag, border, userData);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__GBSizerItem_1, "GBSizerItem_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "span", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "border", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "userData", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_GBSizerItem));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__GBSizerItem_1)
{
	//wxWindow* window = arg.GetNumber(0)
	//const wxGBPosition& pos = arg.GetNumber(1)
	//const wxGBSpan& span = arg.GetNumber(2)
	//int flag = arg.GetNumber(3)
	//int border = arg.GetNumber(4)
	//wxObject* userData = arg.GetNumber(5)
	//wxGBSizerItem(window, pos, span, flag, border, userData);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__GBSizerItem_2, "GBSizerItem_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "sizer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "span", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "border", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "userData", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_GBSizerItem));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__GBSizerItem_2)
{
	//wxSizer* sizer = arg.GetNumber(0)
	//const wxGBPosition& pos = arg.GetNumber(1)
	//const wxGBSpan& span = arg.GetNumber(2)
	//int flag = arg.GetNumber(3)
	//int border = arg.GetNumber(4)
	//wxObject* userData = arg.GetNumber(5)
	//wxGBSizerItem(sizer, pos, span, flag, border, userData);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_GBSizerItem, __GetEndPos, "GetEndPos")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GBSizerItem, __GetEndPos)
{
	Object_wx_GBSizerItem *pThis = Object_wx_GBSizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int& row = arg.GetNumber(0)
	//int& col = arg.GetNumber(1)
	//pThis->GetEntity()->GetEndPos(row, col);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GBSizerItem, __GetPos, "GetPos")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_GBSizerItem, __GetPos)
{
	Object_wx_GBSizerItem *pThis = Object_wx_GBSizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxGBPosition _rtn = pThis->GetEntity()->GetPos();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GBSizerItem, __GetPos_1, "GetPos_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GBSizerItem, __GetPos_1)
{
	Object_wx_GBSizerItem *pThis = Object_wx_GBSizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int& row = arg.GetNumber(0)
	//int& col = arg.GetNumber(1)
	//pThis->GetEntity()->GetPos(row, col);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GBSizerItem, __GetSpan, "GetSpan")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_GBSizerItem, __GetSpan)
{
	Object_wx_GBSizerItem *pThis = Object_wx_GBSizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxGBSpan _rtn = pThis->GetEntity()->GetSpan();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GBSizerItem, __GetSpan_1, "GetSpan_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rowspan", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "colspan", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GBSizerItem, __GetSpan_1)
{
	Object_wx_GBSizerItem *pThis = Object_wx_GBSizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int& rowspan = arg.GetNumber(0)
	//int& colspan = arg.GetNumber(1)
	//pThis->GetEntity()->GetSpan(rowspan, colspan);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GBSizerItem, __Intersects, "Intersects")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "other", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GBSizerItem, __Intersects)
{
	Object_wx_GBSizerItem *pThis = Object_wx_GBSizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxGBSizerItem& other = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->Intersects(other);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GBSizerItem, __Intersects_1, "Intersects_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "span", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GBSizerItem, __Intersects_1)
{
	Object_wx_GBSizerItem *pThis = Object_wx_GBSizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxGBPosition& pos = arg.GetNumber(0)
	//const wxGBSpan& span = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->Intersects(pos, span);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GBSizerItem, __SetPos, "SetPos")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GBSizerItem, __SetPos)
{
	Object_wx_GBSizerItem *pThis = Object_wx_GBSizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxGBPosition& pos = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->SetPos(pos);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GBSizerItem, __SetSpan, "SetSpan")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "span", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GBSizerItem, __SetSpan)
{
	Object_wx_GBSizerItem *pThis = Object_wx_GBSizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxGBSpan& span = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->SetSpan(span);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GBSizerItem, __GetGBSizer, "GetGBSizer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_GBSizerItem, __GetGBSizer)
{
	Object_wx_GBSizerItem *pThis = Object_wx_GBSizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxGridBagSizer* _rtn = pThis->GetEntity()->GetGBSizer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GBSizerItem, __SetGBSizer, "SetGBSizer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GBSizerItem, __SetGBSizer)
{
	Object_wx_GBSizerItem *pThis = Object_wx_GBSizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxGridBagSizer* sizer = arg.GetNumber(0)
	//pThis->GetEntity()->SetGBSizer(sizer);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGBSizerItem
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GBSizerItem)
{
	// Constructor assignment
	Gura_AssignFunction(__GBSizerItem);
	Gura_AssignFunction(__GBSizerItem_1);
	Gura_AssignFunction(__GBSizerItem_2);
	// Method assignment
	Gura_AssignMethod(wx_GBSizerItem, __GetEndPos);
	Gura_AssignMethod(wx_GBSizerItem, __GetPos);
	Gura_AssignMethod(wx_GBSizerItem, __GetPos_1);
	Gura_AssignMethod(wx_GBSizerItem, __GetSpan);
	Gura_AssignMethod(wx_GBSizerItem, __GetSpan_1);
	Gura_AssignMethod(wx_GBSizerItem, __Intersects);
	Gura_AssignMethod(wx_GBSizerItem, __Intersects_1);
	Gura_AssignMethod(wx_GBSizerItem, __SetPos);
	Gura_AssignMethod(wx_GBSizerItem, __SetSpan);
	Gura_AssignMethod(wx_GBSizerItem, __GetGBSizer);
	Gura_AssignMethod(wx_GBSizerItem, __SetGBSizer);
}

Gura_ImplementDescendantCreator(wx_GBSizerItem)
{
	return new Object_wx_GBSizerItem((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
