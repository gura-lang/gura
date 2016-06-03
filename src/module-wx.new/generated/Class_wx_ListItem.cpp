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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__ListItem, "ListItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_ListItem));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__ListItem)
{
	//wxListItem();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_ListItem, __Clear, "Clear")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListItem, __Clear)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListItem, __GetAlign, "GetAlign")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListItem, __GetAlign)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAlign();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListItem, __GetBackgroundColour, "GetBackgroundColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListItem, __GetBackgroundColour)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBackgroundColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListItem, __GetColumn, "GetColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListItem, __GetColumn)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetColumn();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListItem, __GetData, "GetData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListItem, __GetData)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListItem, __GetFont, "GetFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListItem, __GetFont)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFont();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListItem, __GetId, "GetId")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListItem, __GetId)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetId();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListItem, __GetImage, "GetImage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListItem, __GetImage)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetImage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListItem, __GetMask, "GetMask")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListItem, __GetMask)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMask();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListItem, __GetState, "GetState")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListItem, __GetState)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetState();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListItem, __GetText, "GetText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListItem, __GetText)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListItem, __GetTextColour, "GetTextColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListItem, __GetTextColour)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTextColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListItem, __GetWidth, "GetWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ListItem, __GetWidth)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWidth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListItem, __SetAlign, "SetAlign")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListItem, __SetAlign)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxListColumnFormat align = arg.GetNumber(0)
	//pThis->GetEntity()->SetAlign();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListItem, __SetBackgroundColour, "SetBackgroundColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colBack", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListItem, __SetBackgroundColour)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& colBack = arg.GetNumber(0)
	//pThis->GetEntity()->SetBackgroundColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListItem, __SetColumn, "SetColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListItem, __SetColumn)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->SetColumn();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListItem, __SetData, "SetData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListItem, __SetData)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long data = arg.GetNumber(0)
	//pThis->GetEntity()->SetData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListItem, __SetData_1, "SetData_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListItem, __SetData_1)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//void* data = arg.GetNumber(0)
	//pThis->GetEntity()->SetData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListItem, __SetFont, "SetFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListItem, __SetFont)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxFont& font = arg.GetNumber(0)
	//pThis->GetEntity()->SetFont();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListItem, __SetId, "SetId")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListItem, __SetId)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long id = arg.GetNumber(0)
	//pThis->GetEntity()->SetId();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListItem, __SetImage, "SetImage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "image", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListItem, __SetImage)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int image = arg.GetNumber(0)
	//pThis->GetEntity()->SetImage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListItem, __SetMask, "SetMask")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mask", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListItem, __SetMask)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long mask = arg.GetNumber(0)
	//pThis->GetEntity()->SetMask();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListItem, __SetState, "SetState")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "state", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListItem, __SetState)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long state = arg.GetNumber(0)
	//pThis->GetEntity()->SetState();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListItem, __SetStateMask, "SetStateMask")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stateMask", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListItem, __SetStateMask)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long stateMask = arg.GetNumber(0)
	//pThis->GetEntity()->SetStateMask();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListItem, __SetText, "SetText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListItem, __SetText)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& text = arg.GetNumber(0)
	//pThis->GetEntity()->SetText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListItem, __SetTextColour, "SetTextColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colText", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListItem, __SetTextColour)
{
	Object_wx_ListItem *pThis = Object_wx_ListItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& colText = arg.GetNumber(0)
	//pThis->GetEntity()->SetTextColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListItem, __SetWidth, "SetWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListItem, __SetWidth)
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
	// Constructor assignment
	Gura_AssignFunction(__ListItem);
	// Method assignment
	Gura_AssignMethod(wx_ListItem, __Clear);
	Gura_AssignMethod(wx_ListItem, __GetAlign);
	Gura_AssignMethod(wx_ListItem, __GetBackgroundColour);
	Gura_AssignMethod(wx_ListItem, __GetColumn);
	Gura_AssignMethod(wx_ListItem, __GetData);
	Gura_AssignMethod(wx_ListItem, __GetFont);
	Gura_AssignMethod(wx_ListItem, __GetId);
	Gura_AssignMethod(wx_ListItem, __GetImage);
	Gura_AssignMethod(wx_ListItem, __GetMask);
	Gura_AssignMethod(wx_ListItem, __GetState);
	Gura_AssignMethod(wx_ListItem, __GetText);
	Gura_AssignMethod(wx_ListItem, __GetTextColour);
	Gura_AssignMethod(wx_ListItem, __GetWidth);
	Gura_AssignMethod(wx_ListItem, __SetAlign);
	Gura_AssignMethod(wx_ListItem, __SetBackgroundColour);
	Gura_AssignMethod(wx_ListItem, __SetColumn);
	Gura_AssignMethod(wx_ListItem, __SetData);
	Gura_AssignMethod(wx_ListItem, __SetData_1);
	Gura_AssignMethod(wx_ListItem, __SetFont);
	Gura_AssignMethod(wx_ListItem, __SetId);
	Gura_AssignMethod(wx_ListItem, __SetImage);
	Gura_AssignMethod(wx_ListItem, __SetMask);
	Gura_AssignMethod(wx_ListItem, __SetState);
	Gura_AssignMethod(wx_ListItem, __SetStateMask);
	Gura_AssignMethod(wx_ListItem, __SetText);
	Gura_AssignMethod(wx_ListItem, __SetTextColour);
	Gura_AssignMethod(wx_ListItem, __SetWidth);
}

Gura_ImplementDescendantCreator(wx_ListItem)
{
	return new Object_wx_ListItem((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
