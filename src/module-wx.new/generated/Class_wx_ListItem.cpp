//----------------------------------------------------------------------------
// wxListItem
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxListItem
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxListItem
//----------------------------------------------------------------------------
Object_wx_ListItem::~Object_wx_ListItem()
{
}

Object *Object_wx_ListItem::Clone() const
{
	return nullptr;
}

String Object_wx_ListItem::ToString(bool exprFlag)
{
	String rtn("<wx.ListItem:");
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
Gura_DeclareMethod(wx_ListItem, wxListItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListItem, wxListItem)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxListItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListItem, Clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListItem, Clear)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListItem, GetAlign)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListItem, GetAlign)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAlign();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListItem, GetBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListItem, GetBackgroundColour)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBackgroundColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListItem, GetColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListItem, GetColumn)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListItem, GetData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListItem, GetData)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListItem, GetFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListItem, GetFont)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListItem, GetId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListItem, GetId)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetId();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListItem, GetImage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListItem, GetImage)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetImage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListItem, GetMask)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListItem, GetMask)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMask();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListItem, GetState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListItem, GetState)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetState();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListItem, GetText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListItem, GetText)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListItem, GetTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListItem, GetTextColour)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTextColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListItem, GetWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListItem, GetWidth)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListItem, SetAlign)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListItem, SetAlign)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int align = arg.GetNumber(0)
	//pThis->GetEntity()->SetAlign();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListItem, SetBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colBack", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListItem, SetBackgroundColour)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int colBack = arg.GetNumber(0)
	//pThis->GetEntity()->SetBackgroundColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListItem, SetColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListItem, SetColumn)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->SetColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListItem, SetData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListItem, SetData)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->SetData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListItem, SetData_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListItem, SetData_1)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->SetData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListItem, SetFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListItem, SetFont)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int font = arg.GetNumber(0)
	//pThis->GetEntity()->SetFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListItem, SetId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListItem, SetId)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->SetId();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListItem, SetImage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListItem, SetImage)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int image = arg.GetNumber(0)
	//pThis->GetEntity()->SetImage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListItem, SetMask)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mask", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListItem, SetMask)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int mask = arg.GetNumber(0)
	//pThis->GetEntity()->SetMask();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListItem, SetState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "state", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListItem, SetState)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int state = arg.GetNumber(0)
	//pThis->GetEntity()->SetState();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListItem, SetStateMask)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stateMask", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListItem, SetStateMask)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stateMask = arg.GetNumber(0)
	//pThis->GetEntity()->SetStateMask();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListItem, SetText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListItem, SetText)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//pThis->GetEntity()->SetText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListItem, SetTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colText", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListItem, SetTextColour)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int colText = arg.GetNumber(0)
	//pThis->GetEntity()->SetTextColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ListItem, SetWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListItem, SetWidth)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//pThis->GetEntity()->SetWidth();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxListItem
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ListItem)
{
	Gura_AssignMethod(wx_ListItem, wxListItem);
	Gura_AssignMethod(wx_ListItem, Clear);
	Gura_AssignMethod(wx_ListItem, GetAlign);
	Gura_AssignMethod(wx_ListItem, GetBackgroundColour);
	Gura_AssignMethod(wx_ListItem, GetColumn);
	Gura_AssignMethod(wx_ListItem, GetData);
	Gura_AssignMethod(wx_ListItem, GetFont);
	Gura_AssignMethod(wx_ListItem, GetId);
	Gura_AssignMethod(wx_ListItem, GetImage);
	Gura_AssignMethod(wx_ListItem, GetMask);
	Gura_AssignMethod(wx_ListItem, GetState);
	Gura_AssignMethod(wx_ListItem, GetText);
	Gura_AssignMethod(wx_ListItem, GetTextColour);
	Gura_AssignMethod(wx_ListItem, GetWidth);
	Gura_AssignMethod(wx_ListItem, SetAlign);
	Gura_AssignMethod(wx_ListItem, SetBackgroundColour);
	Gura_AssignMethod(wx_ListItem, SetColumn);
	Gura_AssignMethod(wx_ListItem, SetData);
	Gura_AssignMethod(wx_ListItem, SetData_1);
	Gura_AssignMethod(wx_ListItem, SetFont);
	Gura_AssignMethod(wx_ListItem, SetId);
	Gura_AssignMethod(wx_ListItem, SetImage);
	Gura_AssignMethod(wx_ListItem, SetMask);
	Gura_AssignMethod(wx_ListItem, SetState);
	Gura_AssignMethod(wx_ListItem, SetStateMask);
	Gura_AssignMethod(wx_ListItem, SetText);
	Gura_AssignMethod(wx_ListItem, SetTextColour);
	Gura_AssignMethod(wx_ListItem, SetWidth);
}

Gura_ImplementDescendantCreator(wx_ListItem)
{
	return new Object_wx_ListItem((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
