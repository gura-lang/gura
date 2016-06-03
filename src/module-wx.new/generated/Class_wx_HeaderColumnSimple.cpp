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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxHeaderColumnSimple, "wxHeaderColumnSimple")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxHeaderColumnSimple)
{
	//int title = arg.GetNumber(0)
	//int width = arg.GetNumber(1)
	//int align = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//wxHeaderColumnSimple();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxHeaderColumnSimple_1, "wxHeaderColumnSimple_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxHeaderColumnSimple_1)
{
	//int bitmap = arg.GetNumber(0)
	//int width = arg.GetNumber(1)
	//int align = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//wxHeaderColumnSimple();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_HeaderColumnSimple, __SetTitle, "SetTitle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderColumnSimple, __SetTitle)
{
	Object_wx_HeaderColumnSimple *pThis = Object_wx_HeaderColumnSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int title = arg.GetNumber(0)
	//pThis->GetEntity()->SetTitle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HeaderColumnSimple, __GetTitle, "GetTitle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HeaderColumnSimple, __GetTitle)
{
	Object_wx_HeaderColumnSimple *pThis = Object_wx_HeaderColumnSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTitle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HeaderColumnSimple, __SetBitmap, "SetBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderColumnSimple, __SetBitmap)
{
	Object_wx_HeaderColumnSimple *pThis = Object_wx_HeaderColumnSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bitmap = arg.GetNumber(0)
	//pThis->GetEntity()->SetBitmap();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HeaderColumnSimple, __GetBitmap, "GetBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HeaderColumnSimple, __GetBitmap)
{
	Object_wx_HeaderColumnSimple *pThis = Object_wx_HeaderColumnSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBitmap();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HeaderColumnSimple, __SetWidth, "SetWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderColumnSimple, __SetWidth)
{
	Object_wx_HeaderColumnSimple *pThis = Object_wx_HeaderColumnSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//pThis->GetEntity()->SetWidth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HeaderColumnSimple, __GetWidth, "GetWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HeaderColumnSimple, __GetWidth)
{
	Object_wx_HeaderColumnSimple *pThis = Object_wx_HeaderColumnSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWidth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HeaderColumnSimple, __SetMinWidth, "SetMinWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "minWidth", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderColumnSimple, __SetMinWidth)
{
	Object_wx_HeaderColumnSimple *pThis = Object_wx_HeaderColumnSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int minWidth = arg.GetNumber(0)
	//pThis->GetEntity()->SetMinWidth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HeaderColumnSimple, __GetMinWidth, "GetMinWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HeaderColumnSimple, __GetMinWidth)
{
	Object_wx_HeaderColumnSimple *pThis = Object_wx_HeaderColumnSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMinWidth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HeaderColumnSimple, __SetAlignment, "SetAlignment")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderColumnSimple, __SetAlignment)
{
	Object_wx_HeaderColumnSimple *pThis = Object_wx_HeaderColumnSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int align = arg.GetNumber(0)
	//pThis->GetEntity()->SetAlignment();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HeaderColumnSimple, __GetAlignment, "GetAlignment")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HeaderColumnSimple, __GetAlignment)
{
	Object_wx_HeaderColumnSimple *pThis = Object_wx_HeaderColumnSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAlignment();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HeaderColumnSimple, __SetFlags, "SetFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderColumnSimple, __SetFlags)
{
	Object_wx_HeaderColumnSimple *pThis = Object_wx_HeaderColumnSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->SetFlags();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HeaderColumnSimple, __GetFlags, "GetFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HeaderColumnSimple, __GetFlags)
{
	Object_wx_HeaderColumnSimple *pThis = Object_wx_HeaderColumnSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFlags();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HeaderColumnSimple, __IsSortKey, "IsSortKey")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HeaderColumnSimple, __IsSortKey)
{
	Object_wx_HeaderColumnSimple *pThis = Object_wx_HeaderColumnSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsSortKey();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HeaderColumnSimple, __SetSortOrder, "SetSortOrder")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ascending", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HeaderColumnSimple, __SetSortOrder)
{
	Object_wx_HeaderColumnSimple *pThis = Object_wx_HeaderColumnSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ascending = arg.GetNumber(0)
	//pThis->GetEntity()->SetSortOrder();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HeaderColumnSimple, __IsSortOrderAscending, "IsSortOrderAscending")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HeaderColumnSimple, __IsSortOrderAscending)
{
	Object_wx_HeaderColumnSimple *pThis = Object_wx_HeaderColumnSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsSortOrderAscending();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHeaderColumnSimple
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HeaderColumnSimple)
{
	// Constructor assignment
	Gura_AssignFunction(__wxHeaderColumnSimple);
	Gura_AssignFunction(__wxHeaderColumnSimple_1);
	// Method assignment
	Gura_AssignMethod(wx_HeaderColumnSimple, __SetTitle);
	Gura_AssignMethod(wx_HeaderColumnSimple, __GetTitle);
	Gura_AssignMethod(wx_HeaderColumnSimple, __SetBitmap);
	Gura_AssignMethod(wx_HeaderColumnSimple, __GetBitmap);
	Gura_AssignMethod(wx_HeaderColumnSimple, __SetWidth);
	Gura_AssignMethod(wx_HeaderColumnSimple, __GetWidth);
	Gura_AssignMethod(wx_HeaderColumnSimple, __SetMinWidth);
	Gura_AssignMethod(wx_HeaderColumnSimple, __GetMinWidth);
	Gura_AssignMethod(wx_HeaderColumnSimple, __SetAlignment);
	Gura_AssignMethod(wx_HeaderColumnSimple, __GetAlignment);
	Gura_AssignMethod(wx_HeaderColumnSimple, __SetFlags);
	Gura_AssignMethod(wx_HeaderColumnSimple, __GetFlags);
	Gura_AssignMethod(wx_HeaderColumnSimple, __IsSortKey);
	Gura_AssignMethod(wx_HeaderColumnSimple, __SetSortOrder);
	Gura_AssignMethod(wx_HeaderColumnSimple, __IsSortOrderAscending);
}

Gura_ImplementDescendantCreator(wx_HeaderColumnSimple)
{
	return new Object_wx_HeaderColumnSimple((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
