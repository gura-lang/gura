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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__RibbonGallery, "RibbonGallery")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_RibbonGallery));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RibbonGallery)
{
	//wxRibbonGallery();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__RibbonGallery_1, "RibbonGallery_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RibbonGallery));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RibbonGallery_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//long style = arg.GetNumber(4)
	//wxRibbonGallery(parent, id, pos, size, style);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RibbonGallery, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonGallery, __Create)
{
	Object_wx_RibbonGallery *pThis = Object_wx_RibbonGallery::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//long style = arg.GetNumber(4)
	//pThis->GetEntity()->Create(parent, id, pos, size, style);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonGallery, __Clear, "Clear")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonGallery, __Clear)
{
	Object_wx_RibbonGallery *pThis = Object_wx_RibbonGallery::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonGallery, __IsEmpty, "IsEmpty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonGallery, __IsEmpty)
{
	Object_wx_RibbonGallery *pThis = Object_wx_RibbonGallery::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsEmpty();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonGallery, __GetCount, "GetCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonGallery, __GetCount)
{
	Object_wx_RibbonGallery *pThis = Object_wx_RibbonGallery::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonGallery, __GetItem, "GetItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonGallery, __GetItem)
{
	Object_wx_RibbonGallery *pThis = Object_wx_RibbonGallery::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int n = arg.GetNumber(0)
	//pThis->GetEntity()->GetItem(n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonGallery, __Append, "Append")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonGallery, __Append)
{
	Object_wx_RibbonGallery *pThis = Object_wx_RibbonGallery::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxBitmap& bitmap = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//pThis->GetEntity()->Append(bitmap, id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonGallery, __Append_1, "Append_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonGallery, __Append_1)
{
	Object_wx_RibbonGallery *pThis = Object_wx_RibbonGallery::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxBitmap& bitmap = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//void* clientData = arg.GetNumber(2)
	//pThis->GetEntity()->Append(bitmap, id, clientData);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonGallery, __Append_2, "Append_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonGallery, __Append_2)
{
	Object_wx_RibbonGallery *pThis = Object_wx_RibbonGallery::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxBitmap& bitmap = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//wxClientData* clientData = arg.GetNumber(2)
	//pThis->GetEntity()->Append(bitmap, id, clientData);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonGallery, __SetItemClientObject, "SetItemClientObject")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonGallery, __SetItemClientObject)
{
	Object_wx_RibbonGallery *pThis = Object_wx_RibbonGallery::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRibbonGalleryItem* item = arg.GetNumber(0)
	//wxClientData* data = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemClientObject(item, data);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonGallery, __GetItemClientObject, "GetItemClientObject")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonGallery, __GetItemClientObject)
{
	Object_wx_RibbonGallery *pThis = Object_wx_RibbonGallery::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRibbonGalleryItem* item = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemClientObject(item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonGallery, __SetItemClientData, "SetItemClientData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonGallery, __SetItemClientData)
{
	Object_wx_RibbonGallery *pThis = Object_wx_RibbonGallery::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRibbonGalleryItem* item = arg.GetNumber(0)
	//void* data = arg.GetNumber(1)
	//pThis->GetEntity()->SetItemClientData(item, data);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonGallery, __GetItemClientData, "GetItemClientData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonGallery, __GetItemClientData)
{
	Object_wx_RibbonGallery *pThis = Object_wx_RibbonGallery::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRibbonGalleryItem* item = arg.GetNumber(0)
	//pThis->GetEntity()->GetItemClientData(item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonGallery, __SetSelection, "SetSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonGallery, __SetSelection)
{
	Object_wx_RibbonGallery *pThis = Object_wx_RibbonGallery::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRibbonGalleryItem* item = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelection(item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonGallery, __GetSelection, "GetSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonGallery, __GetSelection)
{
	Object_wx_RibbonGallery *pThis = Object_wx_RibbonGallery::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonGallery, __GetHoveredItem, "GetHoveredItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonGallery, __GetHoveredItem)
{
	Object_wx_RibbonGallery *pThis = Object_wx_RibbonGallery::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHoveredItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonGallery, __GetActiveItem, "GetActiveItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonGallery, __GetActiveItem)
{
	Object_wx_RibbonGallery *pThis = Object_wx_RibbonGallery::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetActiveItem();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonGallery, __GetUpButtonState, "GetUpButtonState")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonGallery, __GetUpButtonState)
{
	Object_wx_RibbonGallery *pThis = Object_wx_RibbonGallery::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetUpButtonState();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonGallery, __GetDownButtonState, "GetDownButtonState")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonGallery, __GetDownButtonState)
{
	Object_wx_RibbonGallery *pThis = Object_wx_RibbonGallery::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDownButtonState();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonGallery, __GetExtensionButtonState, "GetExtensionButtonState")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonGallery, __GetExtensionButtonState)
{
	Object_wx_RibbonGallery *pThis = Object_wx_RibbonGallery::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetExtensionButtonState();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonGallery, __IsHovered, "IsHovered")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonGallery, __IsHovered)
{
	Object_wx_RibbonGallery *pThis = Object_wx_RibbonGallery::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsHovered();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonGallery, __ScrollLines, "ScrollLines")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lines", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonGallery, __ScrollLines)
{
	Object_wx_RibbonGallery *pThis = Object_wx_RibbonGallery::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int lines = arg.GetNumber(0)
	//pThis->GetEntity()->ScrollLines(lines);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonGallery, __ScrollPixels, "ScrollPixels")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pixels", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonGallery, __ScrollPixels)
{
	Object_wx_RibbonGallery *pThis = Object_wx_RibbonGallery::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pixels = arg.GetNumber(0)
	//pThis->GetEntity()->ScrollPixels(pixels);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RibbonGallery, __EnsureVisible, "EnsureVisible")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonGallery, __EnsureVisible)
{
	Object_wx_RibbonGallery *pThis = Object_wx_RibbonGallery::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRibbonGalleryItem* item = arg.GetNumber(0)
	//pThis->GetEntity()->EnsureVisible(item);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRibbonGallery
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RibbonGallery)
{
	// Constructor assignment
	Gura_AssignFunction(__RibbonGallery);
	Gura_AssignFunction(__RibbonGallery_1);
	// Method assignment
	Gura_AssignMethod(wx_RibbonGallery, __Create);
	Gura_AssignMethod(wx_RibbonGallery, __Clear);
	Gura_AssignMethod(wx_RibbonGallery, __IsEmpty);
	Gura_AssignMethod(wx_RibbonGallery, __GetCount);
	Gura_AssignMethod(wx_RibbonGallery, __GetItem);
	Gura_AssignMethod(wx_RibbonGallery, __Append);
	Gura_AssignMethod(wx_RibbonGallery, __Append_1);
	Gura_AssignMethod(wx_RibbonGallery, __Append_2);
	Gura_AssignMethod(wx_RibbonGallery, __SetItemClientObject);
	Gura_AssignMethod(wx_RibbonGallery, __GetItemClientObject);
	Gura_AssignMethod(wx_RibbonGallery, __SetItemClientData);
	Gura_AssignMethod(wx_RibbonGallery, __GetItemClientData);
	Gura_AssignMethod(wx_RibbonGallery, __SetSelection);
	Gura_AssignMethod(wx_RibbonGallery, __GetSelection);
	Gura_AssignMethod(wx_RibbonGallery, __GetHoveredItem);
	Gura_AssignMethod(wx_RibbonGallery, __GetActiveItem);
	Gura_AssignMethod(wx_RibbonGallery, __GetUpButtonState);
	Gura_AssignMethod(wx_RibbonGallery, __GetDownButtonState);
	Gura_AssignMethod(wx_RibbonGallery, __GetExtensionButtonState);
	Gura_AssignMethod(wx_RibbonGallery, __IsHovered);
	Gura_AssignMethod(wx_RibbonGallery, __ScrollLines);
	Gura_AssignMethod(wx_RibbonGallery, __ScrollPixels);
	Gura_AssignMethod(wx_RibbonGallery, __EnsureVisible);
}

Gura_ImplementDescendantCreator(wx_RibbonGallery)
{
	return new Object_wx_RibbonGallery((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
