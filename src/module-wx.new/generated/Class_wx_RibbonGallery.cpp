//----------------------------------------------------------------------------
// wxRibbonGallery
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRibbonGallery
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRibbonGallery
//----------------------------------------------------------------------------
Object_wx_RibbonGallery::~Object_wx_RibbonGallery()
{
}

Object *Object_wx_RibbonGallery::Clone() const
{
	return nullptr;
}

String Object_wx_RibbonGallery::ToString(bool exprFlag)
{
	String rtn("<wx.RibbonGallery:");
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
Gura_DeclareMethod(wx_RibbonGallery, wxRibbonGallery)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonGallery, wxRibbonGallery)
{
	Object_wx_RibbonGallery *pThis = Object_wx_RibbonGallery::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxRibbonGallery();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonGallery, wxRibbonGallery_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonGallery, wxRibbonGallery_1)
{
	Object_wx_RibbonGallery *pThis = Object_wx_RibbonGallery::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//pThis->GetEntity()->wxRibbonGallery();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonGallery, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonGallery, Create)
{
	Object_wx_RibbonGallery *pThis = Object_wx_RibbonGallery::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonGallery, Clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonGallery, Clear)
{
	Object_wx_RibbonGallery *pThis = Object_wx_RibbonGallery::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonGallery, IsEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonGallery, IsEmpty)
{
	Object_wx_RibbonGallery *pThis = Object_wx_RibbonGallery::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsEmpty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonGallery, GetCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonGallery, GetCount)
{
	Object_wx_RibbonGallery *pThis = Object_wx_RibbonGallery::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonGallery, GetItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonGallery, GetItem)
{
	Object_wx_RibbonGallery *pThis = Object_wx_RibbonGallery::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->GetItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonGallery, Append)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonGallery, Append)
{
	Object_wx_RibbonGallery *pThis = Object_wx_RibbonGallery::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bitmap = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//pThis->GetEntity()->Append();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonGallery, Append_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonGallery, Append_1)
{
	Object_wx_RibbonGallery *pThis = Object_wx_RibbonGallery::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bitmap = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int clientData = arg.GetNumber(2)
	//pThis->GetEntity()->Append();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonGallery, Append_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonGallery, Append_2)
{
	Object_wx_RibbonGallery *pThis = Object_wx_RibbonGallery::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bitmap = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int clientData = arg.GetNumber(2)
	//pThis->GetEntity()->Append();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonGallery, SetItemClientObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonGallery, SetItemClientObject)
{
	Object_wx_RibbonGallery *pThis = Object_wx_RibbonGallery::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemClientObject();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonGallery, GetItemClientObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonGallery, GetItemClientObject)
{
	Object_wx_RibbonGallery *pThis = Object_wx_RibbonGallery::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemClientObject();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonGallery, SetItemClientData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonGallery, SetItemClientData)
{
	Object_wx_RibbonGallery *pThis = Object_wx_RibbonGallery::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemClientData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonGallery, GetItemClientData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonGallery, GetItemClientData)
{
	Object_wx_RibbonGallery *pThis = Object_wx_RibbonGallery::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemClientData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonGallery, SetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonGallery, SetSelection)
{
	Object_wx_RibbonGallery *pThis = Object_wx_RibbonGallery::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonGallery, GetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonGallery, GetSelection)
{
	Object_wx_RibbonGallery *pThis = Object_wx_RibbonGallery::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonGallery, GetHoveredItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonGallery, GetHoveredItem)
{
	Object_wx_RibbonGallery *pThis = Object_wx_RibbonGallery::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHoveredItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonGallery, GetActiveItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonGallery, GetActiveItem)
{
	Object_wx_RibbonGallery *pThis = Object_wx_RibbonGallery::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetActiveItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonGallery, GetUpButtonState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonGallery, GetUpButtonState)
{
	Object_wx_RibbonGallery *pThis = Object_wx_RibbonGallery::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetUpButtonState();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonGallery, GetDownButtonState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonGallery, GetDownButtonState)
{
	Object_wx_RibbonGallery *pThis = Object_wx_RibbonGallery::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDownButtonState();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonGallery, GetExtensionButtonState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonGallery, GetExtensionButtonState)
{
	Object_wx_RibbonGallery *pThis = Object_wx_RibbonGallery::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetExtensionButtonState();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonGallery, IsHovered)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonGallery, IsHovered)
{
	Object_wx_RibbonGallery *pThis = Object_wx_RibbonGallery::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsHovered();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonGallery, ScrollLines)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lines", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonGallery, ScrollLines)
{
	Object_wx_RibbonGallery *pThis = Object_wx_RibbonGallery::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int lines = arg.GetNumber(0)
	//pThis->GetEntity()->ScrollLines();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonGallery, ScrollPixels)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pixels", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonGallery, ScrollPixels)
{
	Object_wx_RibbonGallery *pThis = Object_wx_RibbonGallery::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pixels = arg.GetNumber(0)
	//pThis->GetEntity()->ScrollPixels();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonGallery, EnsureVisible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonGallery, EnsureVisible)
{
	Object_wx_RibbonGallery *pThis = Object_wx_RibbonGallery::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->EnsureVisible();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRibbonGallery
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RibbonGallery)
{
	Gura_AssignMethod(wx_RibbonGallery, wxRibbonGallery);
	Gura_AssignMethod(wx_RibbonGallery, wxRibbonGallery_1);
	Gura_AssignMethod(wx_RibbonGallery, Create);
	Gura_AssignMethod(wx_RibbonGallery, Clear);
	Gura_AssignMethod(wx_RibbonGallery, IsEmpty);
	Gura_AssignMethod(wx_RibbonGallery, GetCount);
	Gura_AssignMethod(wx_RibbonGallery, GetItem);
	Gura_AssignMethod(wx_RibbonGallery, Append);
	Gura_AssignMethod(wx_RibbonGallery, Append_1);
	Gura_AssignMethod(wx_RibbonGallery, Append_2);
	Gura_AssignMethod(wx_RibbonGallery, SetItemClientObject);
	Gura_AssignMethod(wx_RibbonGallery, GetItemClientObject);
	Gura_AssignMethod(wx_RibbonGallery, SetItemClientData);
	Gura_AssignMethod(wx_RibbonGallery, GetItemClientData);
	Gura_AssignMethod(wx_RibbonGallery, SetSelection);
	Gura_AssignMethod(wx_RibbonGallery, GetSelection);
	Gura_AssignMethod(wx_RibbonGallery, GetHoveredItem);
	Gura_AssignMethod(wx_RibbonGallery, GetActiveItem);
	Gura_AssignMethod(wx_RibbonGallery, GetUpButtonState);
	Gura_AssignMethod(wx_RibbonGallery, GetDownButtonState);
	Gura_AssignMethod(wx_RibbonGallery, GetExtensionButtonState);
	Gura_AssignMethod(wx_RibbonGallery, IsHovered);
	Gura_AssignMethod(wx_RibbonGallery, ScrollLines);
	Gura_AssignMethod(wx_RibbonGallery, ScrollPixels);
	Gura_AssignMethod(wx_RibbonGallery, EnsureVisible);
}

Gura_ImplementDescendantCreator(wx_RibbonGallery)
{
	return new Object_wx_RibbonGallery((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
