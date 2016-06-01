//----------------------------------------------------------------------------
// wxHeaderColumn
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHeaderColumn
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHeaderColumn
//----------------------------------------------------------------------------
Object_wx_HeaderColumn::~Object_wx_HeaderColumn()
{
}

Object *Object_wx_HeaderColumn::Clone() const
{
	return nullptr;
}

String Object_wx_HeaderColumn::ToString(bool exprFlag)
{
	String rtn("<wx.HeaderColumn:");
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
Gura_DeclareMethod(wx_HeaderColumn, GetTitle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HeaderColumn, GetTitle)
{
	Signal &sig = env.GetSignal();
	Object_wx_HeaderColumn *pThis = Object_wx_HeaderColumn::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetTitle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderColumn, GetBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HeaderColumn, GetBitmap)
{
	Signal &sig = env.GetSignal();
	Object_wx_HeaderColumn *pThis = Object_wx_HeaderColumn::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderColumn, GetWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HeaderColumn, GetWidth)
{
	Signal &sig = env.GetSignal();
	Object_wx_HeaderColumn *pThis = Object_wx_HeaderColumn::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderColumn, GetMinWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HeaderColumn, GetMinWidth)
{
	Signal &sig = env.GetSignal();
	Object_wx_HeaderColumn *pThis = Object_wx_HeaderColumn::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetMinWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderColumn, GetAlignment)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HeaderColumn, GetAlignment)
{
	Signal &sig = env.GetSignal();
	Object_wx_HeaderColumn *pThis = Object_wx_HeaderColumn::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetAlignment();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderColumn, GetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HeaderColumn, GetFlags)
{
	Signal &sig = env.GetSignal();
	Object_wx_HeaderColumn *pThis = Object_wx_HeaderColumn::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderColumn, HasFlag)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderColumn, HasFlag)
{
	Signal &sig = env.GetSignal();
	Object_wx_HeaderColumn *pThis = Object_wx_HeaderColumn::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->HasFlag();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderColumn, IsResizeable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HeaderColumn, IsResizeable)
{
	Signal &sig = env.GetSignal();
	Object_wx_HeaderColumn *pThis = Object_wx_HeaderColumn::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsResizeable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderColumn, IsSortable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HeaderColumn, IsSortable)
{
	Signal &sig = env.GetSignal();
	Object_wx_HeaderColumn *pThis = Object_wx_HeaderColumn::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsSortable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderColumn, IsReorderable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HeaderColumn, IsReorderable)
{
	Signal &sig = env.GetSignal();
	Object_wx_HeaderColumn *pThis = Object_wx_HeaderColumn::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsReorderable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderColumn, IsHidden)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HeaderColumn, IsHidden)
{
	Signal &sig = env.GetSignal();
	Object_wx_HeaderColumn *pThis = Object_wx_HeaderColumn::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsHidden();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderColumn, IsShown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HeaderColumn, IsShown)
{
	Signal &sig = env.GetSignal();
	Object_wx_HeaderColumn *pThis = Object_wx_HeaderColumn::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsShown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderColumn, IsSortKey)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HeaderColumn, IsSortKey)
{
	Signal &sig = env.GetSignal();
	Object_wx_HeaderColumn *pThis = Object_wx_HeaderColumn::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsSortKey();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderColumn, IsSortOrderAscending)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HeaderColumn, IsSortOrderAscending)
{
	Signal &sig = env.GetSignal();
	Object_wx_HeaderColumn *pThis = Object_wx_HeaderColumn::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsSortOrderAscending();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHeaderColumn
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HeaderColumn)
{
	Gura_AssignMethod(wx_HeaderColumn, GetTitle);
	Gura_AssignMethod(wx_HeaderColumn, GetBitmap);
	Gura_AssignMethod(wx_HeaderColumn, GetWidth);
	Gura_AssignMethod(wx_HeaderColumn, GetMinWidth);
	Gura_AssignMethod(wx_HeaderColumn, GetAlignment);
	Gura_AssignMethod(wx_HeaderColumn, GetFlags);
	Gura_AssignMethod(wx_HeaderColumn, HasFlag);
	Gura_AssignMethod(wx_HeaderColumn, IsResizeable);
	Gura_AssignMethod(wx_HeaderColumn, IsSortable);
	Gura_AssignMethod(wx_HeaderColumn, IsReorderable);
	Gura_AssignMethod(wx_HeaderColumn, IsHidden);
	Gura_AssignMethod(wx_HeaderColumn, IsShown);
	Gura_AssignMethod(wx_HeaderColumn, IsSortKey);
	Gura_AssignMethod(wx_HeaderColumn, IsSortOrderAscending);
}

Gura_ImplementDescendantCreator(wx_HeaderColumn)
{
	return new Object_wx_HeaderColumn((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
