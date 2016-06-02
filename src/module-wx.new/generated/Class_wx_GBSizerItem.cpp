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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_GBSizerItem, wxGBSizerItem)
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

Gura_ImplementMethod(wx_GBSizerItem, wxGBSizerItem)
{
	Object_wx_GBSizerItem *pThis = Object_wx_GBSizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//int height = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int span = arg.GetNumber(3)
	//int flag = arg.GetNumber(4)
	//int border = arg.GetNumber(5)
	//int userData = arg.GetNumber(6)
	//pThis->GetEntity()->wxGBSizerItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GBSizerItem, wxGBSizerItem_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "span", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "border", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "userData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GBSizerItem, wxGBSizerItem_1)
{
	Object_wx_GBSizerItem *pThis = Object_wx_GBSizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//int span = arg.GetNumber(2)
	//int flag = arg.GetNumber(3)
	//int border = arg.GetNumber(4)
	//int userData = arg.GetNumber(5)
	//pThis->GetEntity()->wxGBSizerItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GBSizerItem, wxGBSizerItem_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "span", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "border", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "userData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GBSizerItem, wxGBSizerItem_2)
{
	Object_wx_GBSizerItem *pThis = Object_wx_GBSizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sizer = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//int span = arg.GetNumber(2)
	//int flag = arg.GetNumber(3)
	//int border = arg.GetNumber(4)
	//int userData = arg.GetNumber(5)
	//pThis->GetEntity()->wxGBSizerItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GBSizerItem, GetEndPos)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GBSizerItem, GetEndPos)
{
	Object_wx_GBSizerItem *pThis = Object_wx_GBSizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//pThis->GetEntity()->GetEndPos();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GBSizerItem, GetPos)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GBSizerItem, GetPos)
{
	Object_wx_GBSizerItem *pThis = Object_wx_GBSizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPos();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GBSizerItem, GetPos_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GBSizerItem, GetPos_1)
{
	Object_wx_GBSizerItem *pThis = Object_wx_GBSizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//pThis->GetEntity()->GetPos();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GBSizerItem, GetSpan)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GBSizerItem, GetSpan)
{
	Object_wx_GBSizerItem *pThis = Object_wx_GBSizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSpan();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GBSizerItem, GetSpan_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rowspan", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "colspan", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GBSizerItem, GetSpan_1)
{
	Object_wx_GBSizerItem *pThis = Object_wx_GBSizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rowspan = arg.GetNumber(0)
	//int colspan = arg.GetNumber(1)
	//pThis->GetEntity()->GetSpan();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GBSizerItem, Intersects)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "other", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GBSizerItem, Intersects)
{
	Object_wx_GBSizerItem *pThis = Object_wx_GBSizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int other = arg.GetNumber(0)
	//pThis->GetEntity()->Intersects();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GBSizerItem, Intersects_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "span", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GBSizerItem, Intersects_1)
{
	Object_wx_GBSizerItem *pThis = Object_wx_GBSizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int span = arg.GetNumber(1)
	//pThis->GetEntity()->Intersects();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GBSizerItem, SetPos)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GBSizerItem, SetPos)
{
	Object_wx_GBSizerItem *pThis = Object_wx_GBSizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->SetPos();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GBSizerItem, SetSpan)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "span", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GBSizerItem, SetSpan)
{
	Object_wx_GBSizerItem *pThis = Object_wx_GBSizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int span = arg.GetNumber(0)
	//pThis->GetEntity()->SetSpan();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GBSizerItem, GetGBSizer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GBSizerItem, GetGBSizer)
{
	Object_wx_GBSizerItem *pThis = Object_wx_GBSizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetGBSizer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GBSizerItem, SetGBSizer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GBSizerItem, SetGBSizer)
{
	Object_wx_GBSizerItem *pThis = Object_wx_GBSizerItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sizer = arg.GetNumber(0)
	//pThis->GetEntity()->SetGBSizer();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGBSizerItem
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GBSizerItem)
{
	Gura_AssignMethod(wx_GBSizerItem, wxGBSizerItem);
	Gura_AssignMethod(wx_GBSizerItem, wxGBSizerItem_1);
	Gura_AssignMethod(wx_GBSizerItem, wxGBSizerItem_2);
	Gura_AssignMethod(wx_GBSizerItem, GetEndPos);
	Gura_AssignMethod(wx_GBSizerItem, GetPos);
	Gura_AssignMethod(wx_GBSizerItem, GetPos_1);
	Gura_AssignMethod(wx_GBSizerItem, GetSpan);
	Gura_AssignMethod(wx_GBSizerItem, GetSpan_1);
	Gura_AssignMethod(wx_GBSizerItem, Intersects);
	Gura_AssignMethod(wx_GBSizerItem, Intersects_1);
	Gura_AssignMethod(wx_GBSizerItem, SetPos);
	Gura_AssignMethod(wx_GBSizerItem, SetSpan);
	Gura_AssignMethod(wx_GBSizerItem, GetGBSizer);
	Gura_AssignMethod(wx_GBSizerItem, SetGBSizer);
}

Gura_ImplementDescendantCreator(wx_GBSizerItem)
{
	return new Object_wx_GBSizerItem((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
