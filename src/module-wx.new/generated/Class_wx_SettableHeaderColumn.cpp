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
Gura_DeclareMethod(wx_SettableHeaderColumn, SetTitle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SettableHeaderColumn, SetTitle)
{
	Signal &sig = env.GetSignal();
	Object_wx_SettableHeaderColumn *pThis = Object_wx_SettableHeaderColumn::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int title = arg.GetNumber(0)
	//pThis->GetEntity()->SetTitle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SettableHeaderColumn, SetBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SettableHeaderColumn, SetBitmap)
{
	Signal &sig = env.GetSignal();
	Object_wx_SettableHeaderColumn *pThis = Object_wx_SettableHeaderColumn::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int bitmap = arg.GetNumber(0)
	//pThis->GetEntity()->SetBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SettableHeaderColumn, SetWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SettableHeaderColumn, SetWidth)
{
	Signal &sig = env.GetSignal();
	Object_wx_SettableHeaderColumn *pThis = Object_wx_SettableHeaderColumn::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//pThis->GetEntity()->SetWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SettableHeaderColumn, SetMinWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "minWidth", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SettableHeaderColumn, SetMinWidth)
{
	Signal &sig = env.GetSignal();
	Object_wx_SettableHeaderColumn *pThis = Object_wx_SettableHeaderColumn::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int minWidth = arg.GetNumber(0)
	//pThis->GetEntity()->SetMinWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SettableHeaderColumn, SetAlignment)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SettableHeaderColumn, SetAlignment)
{
	Signal &sig = env.GetSignal();
	Object_wx_SettableHeaderColumn *pThis = Object_wx_SettableHeaderColumn::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int align = arg.GetNumber(0)
	//pThis->GetEntity()->SetAlignment();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SettableHeaderColumn, SetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SettableHeaderColumn, SetFlags)
{
	Signal &sig = env.GetSignal();
	Object_wx_SettableHeaderColumn *pThis = Object_wx_SettableHeaderColumn::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->SetFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SettableHeaderColumn, ChangeFlag)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "set", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SettableHeaderColumn, ChangeFlag)
{
	Signal &sig = env.GetSignal();
	Object_wx_SettableHeaderColumn *pThis = Object_wx_SettableHeaderColumn::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//int set = arg.GetNumber(1)
	//pThis->GetEntity()->ChangeFlag();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SettableHeaderColumn, SetFlag)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SettableHeaderColumn, SetFlag)
{
	Signal &sig = env.GetSignal();
	Object_wx_SettableHeaderColumn *pThis = Object_wx_SettableHeaderColumn::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->SetFlag();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SettableHeaderColumn, ClearFlag)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SettableHeaderColumn, ClearFlag)
{
	Signal &sig = env.GetSignal();
	Object_wx_SettableHeaderColumn *pThis = Object_wx_SettableHeaderColumn::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->ClearFlag();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SettableHeaderColumn, ToggleFlag)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SettableHeaderColumn, ToggleFlag)
{
	Signal &sig = env.GetSignal();
	Object_wx_SettableHeaderColumn *pThis = Object_wx_SettableHeaderColumn::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->ToggleFlag();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SettableHeaderColumn, SetResizeable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "resizable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SettableHeaderColumn, SetResizeable)
{
	Signal &sig = env.GetSignal();
	Object_wx_SettableHeaderColumn *pThis = Object_wx_SettableHeaderColumn::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int resizable = arg.GetNumber(0)
	//pThis->GetEntity()->SetResizeable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SettableHeaderColumn, SetSortable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sortable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SettableHeaderColumn, SetSortable)
{
	Signal &sig = env.GetSignal();
	Object_wx_SettableHeaderColumn *pThis = Object_wx_SettableHeaderColumn::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int sortable = arg.GetNumber(0)
	//pThis->GetEntity()->SetSortable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SettableHeaderColumn, SetReorderable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "reorderable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SettableHeaderColumn, SetReorderable)
{
	Signal &sig = env.GetSignal();
	Object_wx_SettableHeaderColumn *pThis = Object_wx_SettableHeaderColumn::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int reorderable = arg.GetNumber(0)
	//pThis->GetEntity()->SetReorderable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SettableHeaderColumn, SetHidden)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "hidden", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SettableHeaderColumn, SetHidden)
{
	Signal &sig = env.GetSignal();
	Object_wx_SettableHeaderColumn *pThis = Object_wx_SettableHeaderColumn::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int hidden = arg.GetNumber(0)
	//pThis->GetEntity()->SetHidden();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SettableHeaderColumn, UnsetAsSortKey)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SettableHeaderColumn, UnsetAsSortKey)
{
	Signal &sig = env.GetSignal();
	Object_wx_SettableHeaderColumn *pThis = Object_wx_SettableHeaderColumn::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->UnsetAsSortKey();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SettableHeaderColumn, SetSortOrder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ascending", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SettableHeaderColumn, SetSortOrder)
{
	Signal &sig = env.GetSignal();
	Object_wx_SettableHeaderColumn *pThis = Object_wx_SettableHeaderColumn::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int ascending = arg.GetNumber(0)
	//pThis->GetEntity()->SetSortOrder();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SettableHeaderColumn, ToggleSortOrder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SettableHeaderColumn, ToggleSortOrder)
{
	Signal &sig = env.GetSignal();
	Object_wx_SettableHeaderColumn *pThis = Object_wx_SettableHeaderColumn::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->ToggleSortOrder();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSettableHeaderColumn
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SettableHeaderColumn)
{
	Gura_AssignMethod(wx_SettableHeaderColumn, SetTitle);
	Gura_AssignMethod(wx_SettableHeaderColumn, SetBitmap);
	Gura_AssignMethod(wx_SettableHeaderColumn, SetWidth);
	Gura_AssignMethod(wx_SettableHeaderColumn, SetMinWidth);
	Gura_AssignMethod(wx_SettableHeaderColumn, SetAlignment);
	Gura_AssignMethod(wx_SettableHeaderColumn, SetFlags);
	Gura_AssignMethod(wx_SettableHeaderColumn, ChangeFlag);
	Gura_AssignMethod(wx_SettableHeaderColumn, SetFlag);
	Gura_AssignMethod(wx_SettableHeaderColumn, ClearFlag);
	Gura_AssignMethod(wx_SettableHeaderColumn, ToggleFlag);
	Gura_AssignMethod(wx_SettableHeaderColumn, SetResizeable);
	Gura_AssignMethod(wx_SettableHeaderColumn, SetSortable);
	Gura_AssignMethod(wx_SettableHeaderColumn, SetReorderable);
	Gura_AssignMethod(wx_SettableHeaderColumn, SetHidden);
	Gura_AssignMethod(wx_SettableHeaderColumn, UnsetAsSortKey);
	Gura_AssignMethod(wx_SettableHeaderColumn, SetSortOrder);
	Gura_AssignMethod(wx_SettableHeaderColumn, ToggleSortOrder);
}

Gura_ImplementDescendantCreator(wx_SettableHeaderColumn)
{
	return new Object_wx_SettableHeaderColumn((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
