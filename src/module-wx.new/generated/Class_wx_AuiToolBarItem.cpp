//----------------------------------------------------------------------------
// wxAuiToolBarItem
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAuiToolBarItem
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAuiToolBarItem
//----------------------------------------------------------------------------
Object_wx_AuiToolBarItem::~Object_wx_AuiToolBarItem()
{
}

Object *Object_wx_AuiToolBarItem::Clone() const
{
	return nullptr;
}

String Object_wx_AuiToolBarItem::ToString(bool exprFlag)
{
	String rtn("<wx.AuiToolBarItem:");
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
Gura_DeclareMethod(wx_AuiToolBarItem, wxAuiToolBarItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBarItem, wxAuiToolBarItem)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxAuiToolBarItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBarItem, wxAuiToolBarItem_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarItem, wxAuiToolBarItem_1)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int c = arg.GetNumber(0)
	//pThis->GetEntity()->wxAuiToolBarItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBarItem, Assign)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarItem, Assign)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int c = arg.GetNumber(0)
	//pThis->GetEntity()->Assign();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBarItem, SetWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarItem, SetWindow)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int w = arg.GetNumber(0)
	//pThis->GetEntity()->SetWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBarItem, GetWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBarItem, GetWindow)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBarItem, SetId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "new_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarItem, SetId)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int new_id = arg.GetNumber(0)
	//pThis->GetEntity()->SetId();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBarItem, GetId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBarItem, GetId)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetId();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBarItem, SetKind)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "new_kind", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarItem, SetKind)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int new_kind = arg.GetNumber(0)
	//pThis->GetEntity()->SetKind();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBarItem, GetKind)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBarItem, GetKind)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetKind();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBarItem, SetState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "new_state", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarItem, SetState)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int new_state = arg.GetNumber(0)
	//pThis->GetEntity()->SetState();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBarItem, GetState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBarItem, GetState)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetState();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBarItem, SetSizerItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarItem, SetSizerItem)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int s = arg.GetNumber(0)
	//pThis->GetEntity()->SetSizerItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBarItem, GetSizerItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBarItem, GetSizerItem)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSizerItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBarItem, SetLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarItem, SetLabel)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int s = arg.GetNumber(0)
	//pThis->GetEntity()->SetLabel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBarItem, GetLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBarItem, GetLabel)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLabel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBarItem, SetBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bmp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarItem, SetBitmap)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bmp = arg.GetNumber(0)
	//pThis->GetEntity()->SetBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBarItem, GetBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBarItem, GetBitmap)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBarItem, SetDisabledBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bmp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarItem, SetDisabledBitmap)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bmp = arg.GetNumber(0)
	//pThis->GetEntity()->SetDisabledBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBarItem, GetDisabledBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBarItem, GetDisabledBitmap)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDisabledBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBarItem, SetHoverBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bmp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarItem, SetHoverBitmap)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bmp = arg.GetNumber(0)
	//pThis->GetEntity()->SetHoverBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBarItem, GetHoverBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBarItem, GetHoverBitmap)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHoverBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBarItem, SetShortHelp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarItem, SetShortHelp)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int s = arg.GetNumber(0)
	//pThis->GetEntity()->SetShortHelp();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBarItem, GetShortHelp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBarItem, GetShortHelp)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetShortHelp();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBarItem, SetLongHelp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarItem, SetLongHelp)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int s = arg.GetNumber(0)
	//pThis->GetEntity()->SetLongHelp();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBarItem, GetLongHelp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBarItem, GetLongHelp)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLongHelp();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBarItem, SetMinSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarItem, SetMinSize)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int s = arg.GetNumber(0)
	//pThis->GetEntity()->SetMinSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBarItem, GetMinSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBarItem, GetMinSize)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMinSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBarItem, SetSpacerPixels)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarItem, SetSpacerPixels)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int s = arg.GetNumber(0)
	//pThis->GetEntity()->SetSpacerPixels();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBarItem, GetSpacerPixels)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBarItem, GetSpacerPixels)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSpacerPixels();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBarItem, SetProportion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "p", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarItem, SetProportion)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int p = arg.GetNumber(0)
	//pThis->GetEntity()->SetProportion();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBarItem, GetProportion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBarItem, GetProportion)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetProportion();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBarItem, SetActive)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarItem, SetActive)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int b = arg.GetNumber(0)
	//pThis->GetEntity()->SetActive();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBarItem, IsActive)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBarItem, IsActive)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsActive();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBarItem, SetHasDropDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarItem, SetHasDropDown)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int b = arg.GetNumber(0)
	//pThis->GetEntity()->SetHasDropDown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBarItem, HasDropDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBarItem, HasDropDown)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasDropDown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBarItem, SetSticky)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarItem, SetSticky)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int b = arg.GetNumber(0)
	//pThis->GetEntity()->SetSticky();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBarItem, IsSticky)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBarItem, IsSticky)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsSticky();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBarItem, SetUserData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "l", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarItem, SetUserData)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int l = arg.GetNumber(0)
	//pThis->GetEntity()->SetUserData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBarItem, GetUserData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBarItem, GetUserData)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetUserData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBarItem, SetAlignment)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "l", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarItem, SetAlignment)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int l = arg.GetNumber(0)
	//pThis->GetEntity()->SetAlignment();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBarItem, GetAlignment)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBarItem, GetAlignment)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAlignment();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxAuiToolBarItem
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AuiToolBarItem)
{
	Gura_AssignMethod(wx_AuiToolBarItem, wxAuiToolBarItem);
	Gura_AssignMethod(wx_AuiToolBarItem, wxAuiToolBarItem_1);
	Gura_AssignMethod(wx_AuiToolBarItem, Assign);
	Gura_AssignMethod(wx_AuiToolBarItem, SetWindow);
	Gura_AssignMethod(wx_AuiToolBarItem, GetWindow);
	Gura_AssignMethod(wx_AuiToolBarItem, SetId);
	Gura_AssignMethod(wx_AuiToolBarItem, GetId);
	Gura_AssignMethod(wx_AuiToolBarItem, SetKind);
	Gura_AssignMethod(wx_AuiToolBarItem, GetKind);
	Gura_AssignMethod(wx_AuiToolBarItem, SetState);
	Gura_AssignMethod(wx_AuiToolBarItem, GetState);
	Gura_AssignMethod(wx_AuiToolBarItem, SetSizerItem);
	Gura_AssignMethod(wx_AuiToolBarItem, GetSizerItem);
	Gura_AssignMethod(wx_AuiToolBarItem, SetLabel);
	Gura_AssignMethod(wx_AuiToolBarItem, GetLabel);
	Gura_AssignMethod(wx_AuiToolBarItem, SetBitmap);
	Gura_AssignMethod(wx_AuiToolBarItem, GetBitmap);
	Gura_AssignMethod(wx_AuiToolBarItem, SetDisabledBitmap);
	Gura_AssignMethod(wx_AuiToolBarItem, GetDisabledBitmap);
	Gura_AssignMethod(wx_AuiToolBarItem, SetHoverBitmap);
	Gura_AssignMethod(wx_AuiToolBarItem, GetHoverBitmap);
	Gura_AssignMethod(wx_AuiToolBarItem, SetShortHelp);
	Gura_AssignMethod(wx_AuiToolBarItem, GetShortHelp);
	Gura_AssignMethod(wx_AuiToolBarItem, SetLongHelp);
	Gura_AssignMethod(wx_AuiToolBarItem, GetLongHelp);
	Gura_AssignMethod(wx_AuiToolBarItem, SetMinSize);
	Gura_AssignMethod(wx_AuiToolBarItem, GetMinSize);
	Gura_AssignMethod(wx_AuiToolBarItem, SetSpacerPixels);
	Gura_AssignMethod(wx_AuiToolBarItem, GetSpacerPixels);
	Gura_AssignMethod(wx_AuiToolBarItem, SetProportion);
	Gura_AssignMethod(wx_AuiToolBarItem, GetProportion);
	Gura_AssignMethod(wx_AuiToolBarItem, SetActive);
	Gura_AssignMethod(wx_AuiToolBarItem, IsActive);
	Gura_AssignMethod(wx_AuiToolBarItem, SetHasDropDown);
	Gura_AssignMethod(wx_AuiToolBarItem, HasDropDown);
	Gura_AssignMethod(wx_AuiToolBarItem, SetSticky);
	Gura_AssignMethod(wx_AuiToolBarItem, IsSticky);
	Gura_AssignMethod(wx_AuiToolBarItem, SetUserData);
	Gura_AssignMethod(wx_AuiToolBarItem, GetUserData);
	Gura_AssignMethod(wx_AuiToolBarItem, SetAlignment);
	Gura_AssignMethod(wx_AuiToolBarItem, GetAlignment);
}

Gura_ImplementDescendantCreator(wx_AuiToolBarItem)
{
	return new Object_wx_AuiToolBarItem((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
