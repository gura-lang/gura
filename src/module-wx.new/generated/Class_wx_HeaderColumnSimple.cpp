//----------------------------------------------------------------------------
// wxHeaderColumnSimple
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHeaderColumnSimple
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHeaderColumnSimple
//----------------------------------------------------------------------------
Object_wx_HeaderColumnSimple::~Object_wx_HeaderColumnSimple()
{
}

Object *Object_wx_HeaderColumnSimple::Clone() const
{
	return nullptr;
}

String Object_wx_HeaderColumnSimple::ToString(bool exprFlag)
{
	String rtn("<wx.HeaderColumnSimple:");
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
Gura_DeclareMethod(wx_HeaderColumnSimple, wxHeaderColumnSimple)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderColumnSimple, wxHeaderColumnSimple)
{
	Signal &sig = env.GetSignal();
	Object_wx_HeaderColumnSimple *pThis = Object_wx_HeaderColumnSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int title = arg.GetNumber(0)
	//int width = arg.GetNumber(1)
	//int align = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//pThis->GetEntity()->wxHeaderColumnSimple();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderColumnSimple, wxHeaderColumnSimple_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderColumnSimple, wxHeaderColumnSimple_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_HeaderColumnSimple *pThis = Object_wx_HeaderColumnSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int bitmap = arg.GetNumber(0)
	//int width = arg.GetNumber(1)
	//int align = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//pThis->GetEntity()->wxHeaderColumnSimple();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderColumnSimple, SetTitle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderColumnSimple, SetTitle)
{
	Signal &sig = env.GetSignal();
	Object_wx_HeaderColumnSimple *pThis = Object_wx_HeaderColumnSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int title = arg.GetNumber(0)
	//pThis->GetEntity()->SetTitle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderColumnSimple, GetTitle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HeaderColumnSimple, GetTitle)
{
	Signal &sig = env.GetSignal();
	Object_wx_HeaderColumnSimple *pThis = Object_wx_HeaderColumnSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetTitle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderColumnSimple, SetBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderColumnSimple, SetBitmap)
{
	Signal &sig = env.GetSignal();
	Object_wx_HeaderColumnSimple *pThis = Object_wx_HeaderColumnSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int bitmap = arg.GetNumber(0)
	//pThis->GetEntity()->SetBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderColumnSimple, GetBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HeaderColumnSimple, GetBitmap)
{
	Signal &sig = env.GetSignal();
	Object_wx_HeaderColumnSimple *pThis = Object_wx_HeaderColumnSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderColumnSimple, SetWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderColumnSimple, SetWidth)
{
	Signal &sig = env.GetSignal();
	Object_wx_HeaderColumnSimple *pThis = Object_wx_HeaderColumnSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//pThis->GetEntity()->SetWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderColumnSimple, GetWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HeaderColumnSimple, GetWidth)
{
	Signal &sig = env.GetSignal();
	Object_wx_HeaderColumnSimple *pThis = Object_wx_HeaderColumnSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderColumnSimple, SetMinWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "minWidth", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderColumnSimple, SetMinWidth)
{
	Signal &sig = env.GetSignal();
	Object_wx_HeaderColumnSimple *pThis = Object_wx_HeaderColumnSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int minWidth = arg.GetNumber(0)
	//pThis->GetEntity()->SetMinWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderColumnSimple, GetMinWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HeaderColumnSimple, GetMinWidth)
{
	Signal &sig = env.GetSignal();
	Object_wx_HeaderColumnSimple *pThis = Object_wx_HeaderColumnSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetMinWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderColumnSimple, SetAlignment)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderColumnSimple, SetAlignment)
{
	Signal &sig = env.GetSignal();
	Object_wx_HeaderColumnSimple *pThis = Object_wx_HeaderColumnSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int align = arg.GetNumber(0)
	//pThis->GetEntity()->SetAlignment();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderColumnSimple, GetAlignment)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HeaderColumnSimple, GetAlignment)
{
	Signal &sig = env.GetSignal();
	Object_wx_HeaderColumnSimple *pThis = Object_wx_HeaderColumnSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetAlignment();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderColumnSimple, SetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderColumnSimple, SetFlags)
{
	Signal &sig = env.GetSignal();
	Object_wx_HeaderColumnSimple *pThis = Object_wx_HeaderColumnSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->SetFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderColumnSimple, GetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HeaderColumnSimple, GetFlags)
{
	Signal &sig = env.GetSignal();
	Object_wx_HeaderColumnSimple *pThis = Object_wx_HeaderColumnSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderColumnSimple, IsSortKey)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HeaderColumnSimple, IsSortKey)
{
	Signal &sig = env.GetSignal();
	Object_wx_HeaderColumnSimple *pThis = Object_wx_HeaderColumnSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsSortKey();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderColumnSimple, SetSortOrder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ascending", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderColumnSimple, SetSortOrder)
{
	Signal &sig = env.GetSignal();
	Object_wx_HeaderColumnSimple *pThis = Object_wx_HeaderColumnSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int ascending = arg.GetNumber(0)
	//pThis->GetEntity()->SetSortOrder();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HeaderColumnSimple, IsSortOrderAscending)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HeaderColumnSimple, IsSortOrderAscending)
{
	Signal &sig = env.GetSignal();
	Object_wx_HeaderColumnSimple *pThis = Object_wx_HeaderColumnSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsSortOrderAscending();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHeaderColumnSimple
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HeaderColumnSimple)
{
	Gura_AssignMethod(wx_HeaderColumnSimple, wxHeaderColumnSimple);
	Gura_AssignMethod(wx_HeaderColumnSimple, wxHeaderColumnSimple_1);
	Gura_AssignMethod(wx_HeaderColumnSimple, SetTitle);
	Gura_AssignMethod(wx_HeaderColumnSimple, GetTitle);
	Gura_AssignMethod(wx_HeaderColumnSimple, SetBitmap);
	Gura_AssignMethod(wx_HeaderColumnSimple, GetBitmap);
	Gura_AssignMethod(wx_HeaderColumnSimple, SetWidth);
	Gura_AssignMethod(wx_HeaderColumnSimple, GetWidth);
	Gura_AssignMethod(wx_HeaderColumnSimple, SetMinWidth);
	Gura_AssignMethod(wx_HeaderColumnSimple, GetMinWidth);
	Gura_AssignMethod(wx_HeaderColumnSimple, SetAlignment);
	Gura_AssignMethod(wx_HeaderColumnSimple, GetAlignment);
	Gura_AssignMethod(wx_HeaderColumnSimple, SetFlags);
	Gura_AssignMethod(wx_HeaderColumnSimple, GetFlags);
	Gura_AssignMethod(wx_HeaderColumnSimple, IsSortKey);
	Gura_AssignMethod(wx_HeaderColumnSimple, SetSortOrder);
	Gura_AssignMethod(wx_HeaderColumnSimple, IsSortOrderAscending);
}

Gura_ImplementDescendantCreator(wx_HeaderColumnSimple)
{
	return new Object_wx_HeaderColumnSimple((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
