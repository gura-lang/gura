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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__AuiToolBarItem, "AuiToolBarItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_AuiToolBarItem));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__AuiToolBarItem)
{
	//wxAuiToolBarItem();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__AuiToolBarItem_1, "AuiToolBarItem_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_AuiToolBarItem));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__AuiToolBarItem_1)
{
	//const wxAuiToolBarItem& c = arg.GetNumber(0)
	//wxAuiToolBarItem(c);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_AuiToolBarItem, __Assign, "Assign")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarItem, __Assign)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxAuiToolBarItem& c = arg.GetNumber(0)
	//pThis->GetEntity()->Assign(c);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBarItem, __SetWindow, "SetWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarItem, __SetWindow)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* w = arg.GetNumber(0)
	//pThis->GetEntity()->SetWindow(w);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBarItem, __GetWindow, "GetWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBarItem, __GetWindow)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWindow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBarItem, __SetId, "SetId")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "new_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarItem, __SetId)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int new_id = arg.GetNumber(0)
	//pThis->GetEntity()->SetId(new_id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBarItem, __GetId, "GetId")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBarItem, __GetId)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetId();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBarItem, __SetKind, "SetKind")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "new_kind", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarItem, __SetKind)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int new_kind = arg.GetNumber(0)
	//pThis->GetEntity()->SetKind(new_kind);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBarItem, __GetKind, "GetKind")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBarItem, __GetKind)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetKind();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBarItem, __SetState, "SetState")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "new_state", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarItem, __SetState)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int new_state = arg.GetNumber(0)
	//pThis->GetEntity()->SetState(new_state);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBarItem, __GetState, "GetState")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBarItem, __GetState)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetState();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBarItem, __SetSizerItem, "SetSizerItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarItem, __SetSizerItem)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxSizerItem* s = arg.GetNumber(0)
	//pThis->GetEntity()->SetSizerItem(s);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBarItem, __GetSizerItem, "GetSizerItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBarItem, __GetSizerItem)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSizerItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBarItem, __SetLabel, "SetLabel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarItem, __SetLabel)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& s = arg.GetNumber(0)
	//pThis->GetEntity()->SetLabel(s);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBarItem, __GetLabel, "GetLabel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBarItem, __GetLabel)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLabel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBarItem, __SetBitmap, "SetBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bmp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarItem, __SetBitmap)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxBitmap& bmp = arg.GetNumber(0)
	//pThis->GetEntity()->SetBitmap(bmp);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBarItem, __GetBitmap, "GetBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBarItem, __GetBitmap)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBitmap();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBarItem, __SetDisabledBitmap, "SetDisabledBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bmp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarItem, __SetDisabledBitmap)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxBitmap& bmp = arg.GetNumber(0)
	//pThis->GetEntity()->SetDisabledBitmap(bmp);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBarItem, __GetDisabledBitmap, "GetDisabledBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBarItem, __GetDisabledBitmap)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDisabledBitmap();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBarItem, __SetHoverBitmap, "SetHoverBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bmp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarItem, __SetHoverBitmap)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxBitmap& bmp = arg.GetNumber(0)
	//pThis->GetEntity()->SetHoverBitmap(bmp);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBarItem, __GetHoverBitmap, "GetHoverBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBarItem, __GetHoverBitmap)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHoverBitmap();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBarItem, __SetShortHelp, "SetShortHelp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarItem, __SetShortHelp)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& s = arg.GetNumber(0)
	//pThis->GetEntity()->SetShortHelp(s);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBarItem, __GetShortHelp, "GetShortHelp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBarItem, __GetShortHelp)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetShortHelp();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBarItem, __SetLongHelp, "SetLongHelp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarItem, __SetLongHelp)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& s = arg.GetNumber(0)
	//pThis->GetEntity()->SetLongHelp(s);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBarItem, __GetLongHelp, "GetLongHelp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBarItem, __GetLongHelp)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLongHelp();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBarItem, __SetMinSize, "SetMinSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarItem, __SetMinSize)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxSize& s = arg.GetNumber(0)
	//pThis->GetEntity()->SetMinSize(s);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBarItem, __GetMinSize, "GetMinSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBarItem, __GetMinSize)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMinSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBarItem, __SetSpacerPixels, "SetSpacerPixels")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarItem, __SetSpacerPixels)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int s = arg.GetNumber(0)
	//pThis->GetEntity()->SetSpacerPixels(s);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBarItem, __GetSpacerPixels, "GetSpacerPixels")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBarItem, __GetSpacerPixels)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSpacerPixels();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBarItem, __SetProportion, "SetProportion")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "p", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarItem, __SetProportion)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int p = arg.GetNumber(0)
	//pThis->GetEntity()->SetProportion(p);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBarItem, __GetProportion, "GetProportion")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBarItem, __GetProportion)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetProportion();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBarItem, __SetActive, "SetActive")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarItem, __SetActive)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool b = arg.GetNumber(0)
	//pThis->GetEntity()->SetActive(b);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBarItem, __IsActive, "IsActive")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBarItem, __IsActive)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsActive();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBarItem, __SetHasDropDown, "SetHasDropDown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarItem, __SetHasDropDown)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool b = arg.GetNumber(0)
	//pThis->GetEntity()->SetHasDropDown(b);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBarItem, __HasDropDown, "HasDropDown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBarItem, __HasDropDown)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasDropDown();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBarItem, __SetSticky, "SetSticky")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarItem, __SetSticky)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool b = arg.GetNumber(0)
	//pThis->GetEntity()->SetSticky(b);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBarItem, __IsSticky, "IsSticky")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBarItem, __IsSticky)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsSticky();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBarItem, __SetUserData, "SetUserData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "l", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarItem, __SetUserData)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long l = arg.GetNumber(0)
	//pThis->GetEntity()->SetUserData(l);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBarItem, __GetUserData, "GetUserData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBarItem, __GetUserData)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetUserData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBarItem, __SetAlignment, "SetAlignment")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "l", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarItem, __SetAlignment)
{
	Object_wx_AuiToolBarItem *pThis = Object_wx_AuiToolBarItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int l = arg.GetNumber(0)
	//pThis->GetEntity()->SetAlignment(l);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBarItem, __GetAlignment, "GetAlignment")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBarItem, __GetAlignment)
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
	// Constructor assignment
	Gura_AssignFunction(__AuiToolBarItem);
	Gura_AssignFunction(__AuiToolBarItem_1);
	// Method assignment
	Gura_AssignMethod(wx_AuiToolBarItem, __Assign);
	Gura_AssignMethod(wx_AuiToolBarItem, __SetWindow);
	Gura_AssignMethod(wx_AuiToolBarItem, __GetWindow);
	Gura_AssignMethod(wx_AuiToolBarItem, __SetId);
	Gura_AssignMethod(wx_AuiToolBarItem, __GetId);
	Gura_AssignMethod(wx_AuiToolBarItem, __SetKind);
	Gura_AssignMethod(wx_AuiToolBarItem, __GetKind);
	Gura_AssignMethod(wx_AuiToolBarItem, __SetState);
	Gura_AssignMethod(wx_AuiToolBarItem, __GetState);
	Gura_AssignMethod(wx_AuiToolBarItem, __SetSizerItem);
	Gura_AssignMethod(wx_AuiToolBarItem, __GetSizerItem);
	Gura_AssignMethod(wx_AuiToolBarItem, __SetLabel);
	Gura_AssignMethod(wx_AuiToolBarItem, __GetLabel);
	Gura_AssignMethod(wx_AuiToolBarItem, __SetBitmap);
	Gura_AssignMethod(wx_AuiToolBarItem, __GetBitmap);
	Gura_AssignMethod(wx_AuiToolBarItem, __SetDisabledBitmap);
	Gura_AssignMethod(wx_AuiToolBarItem, __GetDisabledBitmap);
	Gura_AssignMethod(wx_AuiToolBarItem, __SetHoverBitmap);
	Gura_AssignMethod(wx_AuiToolBarItem, __GetHoverBitmap);
	Gura_AssignMethod(wx_AuiToolBarItem, __SetShortHelp);
	Gura_AssignMethod(wx_AuiToolBarItem, __GetShortHelp);
	Gura_AssignMethod(wx_AuiToolBarItem, __SetLongHelp);
	Gura_AssignMethod(wx_AuiToolBarItem, __GetLongHelp);
	Gura_AssignMethod(wx_AuiToolBarItem, __SetMinSize);
	Gura_AssignMethod(wx_AuiToolBarItem, __GetMinSize);
	Gura_AssignMethod(wx_AuiToolBarItem, __SetSpacerPixels);
	Gura_AssignMethod(wx_AuiToolBarItem, __GetSpacerPixels);
	Gura_AssignMethod(wx_AuiToolBarItem, __SetProportion);
	Gura_AssignMethod(wx_AuiToolBarItem, __GetProportion);
	Gura_AssignMethod(wx_AuiToolBarItem, __SetActive);
	Gura_AssignMethod(wx_AuiToolBarItem, __IsActive);
	Gura_AssignMethod(wx_AuiToolBarItem, __SetHasDropDown);
	Gura_AssignMethod(wx_AuiToolBarItem, __HasDropDown);
	Gura_AssignMethod(wx_AuiToolBarItem, __SetSticky);
	Gura_AssignMethod(wx_AuiToolBarItem, __IsSticky);
	Gura_AssignMethod(wx_AuiToolBarItem, __SetUserData);
	Gura_AssignMethod(wx_AuiToolBarItem, __GetUserData);
	Gura_AssignMethod(wx_AuiToolBarItem, __SetAlignment);
	Gura_AssignMethod(wx_AuiToolBarItem, __GetAlignment);
}

Gura_ImplementDescendantCreator(wx_AuiToolBarItem)
{
	return new Object_wx_AuiToolBarItem((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
