//----------------------------------------------------------------------------
// wxSettableHeaderColumn
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSettableHeaderColumn
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSettableHeaderColumn
//----------------------------------------------------------------------------
Object_wx_SettableHeaderColumn::~Object_wx_SettableHeaderColumn()
{
}

Object *Object_wx_SettableHeaderColumn::Clone() const
{
	return nullptr;
}

String Object_wx_SettableHeaderColumn::ToString(bool exprFlag)
{
	String rtn("<wx.SettableHeaderColumn:");
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
Gura_DeclareMethodAlias(wx_SettableHeaderColumn, __SetTitle, "SetTitle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SettableHeaderColumn, __SetTitle)
{
	Object_wx_SettableHeaderColumn *pThis = Object_wx_SettableHeaderColumn::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int title = arg.GetNumber(0)
	//pThis->GetEntity()->SetTitle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SettableHeaderColumn, __SetBitmap, "SetBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SettableHeaderColumn, __SetBitmap)
{
	Object_wx_SettableHeaderColumn *pThis = Object_wx_SettableHeaderColumn::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bitmap = arg.GetNumber(0)
	//pThis->GetEntity()->SetBitmap();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SettableHeaderColumn, __SetWidth, "SetWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SettableHeaderColumn, __SetWidth)
{
	Object_wx_SettableHeaderColumn *pThis = Object_wx_SettableHeaderColumn::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//pThis->GetEntity()->SetWidth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SettableHeaderColumn, __SetMinWidth, "SetMinWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "minWidth", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SettableHeaderColumn, __SetMinWidth)
{
	Object_wx_SettableHeaderColumn *pThis = Object_wx_SettableHeaderColumn::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int minWidth = arg.GetNumber(0)
	//pThis->GetEntity()->SetMinWidth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SettableHeaderColumn, __SetAlignment, "SetAlignment")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SettableHeaderColumn, __SetAlignment)
{
	Object_wx_SettableHeaderColumn *pThis = Object_wx_SettableHeaderColumn::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int align = arg.GetNumber(0)
	//pThis->GetEntity()->SetAlignment();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SettableHeaderColumn, __SetFlags, "SetFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SettableHeaderColumn, __SetFlags)
{
	Object_wx_SettableHeaderColumn *pThis = Object_wx_SettableHeaderColumn::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->SetFlags();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SettableHeaderColumn, __ChangeFlag, "ChangeFlag")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "set", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SettableHeaderColumn, __ChangeFlag)
{
	Object_wx_SettableHeaderColumn *pThis = Object_wx_SettableHeaderColumn::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//int set = arg.GetNumber(1)
	//pThis->GetEntity()->ChangeFlag();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SettableHeaderColumn, __SetFlag, "SetFlag")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SettableHeaderColumn, __SetFlag)
{
	Object_wx_SettableHeaderColumn *pThis = Object_wx_SettableHeaderColumn::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->SetFlag();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SettableHeaderColumn, __ClearFlag, "ClearFlag")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SettableHeaderColumn, __ClearFlag)
{
	Object_wx_SettableHeaderColumn *pThis = Object_wx_SettableHeaderColumn::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->ClearFlag();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SettableHeaderColumn, __ToggleFlag, "ToggleFlag")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SettableHeaderColumn, __ToggleFlag)
{
	Object_wx_SettableHeaderColumn *pThis = Object_wx_SettableHeaderColumn::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->ToggleFlag();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SettableHeaderColumn, __SetResizeable, "SetResizeable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "resizable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SettableHeaderColumn, __SetResizeable)
{
	Object_wx_SettableHeaderColumn *pThis = Object_wx_SettableHeaderColumn::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int resizable = arg.GetNumber(0)
	//pThis->GetEntity()->SetResizeable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SettableHeaderColumn, __SetSortable, "SetSortable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sortable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SettableHeaderColumn, __SetSortable)
{
	Object_wx_SettableHeaderColumn *pThis = Object_wx_SettableHeaderColumn::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sortable = arg.GetNumber(0)
	//pThis->GetEntity()->SetSortable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SettableHeaderColumn, __SetReorderable, "SetReorderable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "reorderable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SettableHeaderColumn, __SetReorderable)
{
	Object_wx_SettableHeaderColumn *pThis = Object_wx_SettableHeaderColumn::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int reorderable = arg.GetNumber(0)
	//pThis->GetEntity()->SetReorderable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SettableHeaderColumn, __SetHidden, "SetHidden")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "hidden", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SettableHeaderColumn, __SetHidden)
{
	Object_wx_SettableHeaderColumn *pThis = Object_wx_SettableHeaderColumn::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int hidden = arg.GetNumber(0)
	//pThis->GetEntity()->SetHidden();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SettableHeaderColumn, __UnsetAsSortKey, "UnsetAsSortKey")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SettableHeaderColumn, __UnsetAsSortKey)
{
	Object_wx_SettableHeaderColumn *pThis = Object_wx_SettableHeaderColumn::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->UnsetAsSortKey();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SettableHeaderColumn, __SetSortOrder, "SetSortOrder")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ascending", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SettableHeaderColumn, __SetSortOrder)
{
	Object_wx_SettableHeaderColumn *pThis = Object_wx_SettableHeaderColumn::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ascending = arg.GetNumber(0)
	//pThis->GetEntity()->SetSortOrder();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SettableHeaderColumn, __ToggleSortOrder, "ToggleSortOrder")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SettableHeaderColumn, __ToggleSortOrder)
{
	Object_wx_SettableHeaderColumn *pThis = Object_wx_SettableHeaderColumn::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ToggleSortOrder();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSettableHeaderColumn
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SettableHeaderColumn)
{
	// Class assignment
	Gura_AssignValueEx("SettableHeaderColumn", Reference());
	// Method assignment
	Gura_AssignMethod(wx_SettableHeaderColumn, __SetTitle);
	Gura_AssignMethod(wx_SettableHeaderColumn, __SetBitmap);
	Gura_AssignMethod(wx_SettableHeaderColumn, __SetWidth);
	Gura_AssignMethod(wx_SettableHeaderColumn, __SetMinWidth);
	Gura_AssignMethod(wx_SettableHeaderColumn, __SetAlignment);
	Gura_AssignMethod(wx_SettableHeaderColumn, __SetFlags);
	Gura_AssignMethod(wx_SettableHeaderColumn, __ChangeFlag);
	Gura_AssignMethod(wx_SettableHeaderColumn, __SetFlag);
	Gura_AssignMethod(wx_SettableHeaderColumn, __ClearFlag);
	Gura_AssignMethod(wx_SettableHeaderColumn, __ToggleFlag);
	Gura_AssignMethod(wx_SettableHeaderColumn, __SetResizeable);
	Gura_AssignMethod(wx_SettableHeaderColumn, __SetSortable);
	Gura_AssignMethod(wx_SettableHeaderColumn, __SetReorderable);
	Gura_AssignMethod(wx_SettableHeaderColumn, __SetHidden);
	Gura_AssignMethod(wx_SettableHeaderColumn, __UnsetAsSortKey);
	Gura_AssignMethod(wx_SettableHeaderColumn, __SetSortOrder);
	Gura_AssignMethod(wx_SettableHeaderColumn, __ToggleSortOrder);
}

Gura_ImplementDescendantCreator(wx_SettableHeaderColumn)
{
	return new Object_wx_SettableHeaderColumn((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
