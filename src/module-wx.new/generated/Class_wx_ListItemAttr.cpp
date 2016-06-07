//----------------------------------------------------------------------------
// wxListItemAttr
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxListItemAttr
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxListItemAttr
//----------------------------------------------------------------------------
Object_wx_ListItemAttr::~Object_wx_ListItemAttr()
{
}

Object *Object_wx_ListItemAttr::Clone() const
{
	return nullptr;
}

String Object_wx_ListItemAttr::ToString(bool exprFlag)
{
	String rtn("<wx.ListItemAttr:");
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
Gura_DeclareFunctionAlias(__ListItemAttr, "ListItemAttr")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_ListItemAttr));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__ListItemAttr)
{
	//wxListItemAttr();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__ListItemAttr_1, "ListItemAttr_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "colText", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "colBack", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_ListItemAttr));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__ListItemAttr_1)
{
	//const wxColour& colText = arg.GetNumber(0)
	//const wxColour& colBack = arg.GetNumber(1)
	//const wxFont& font = arg.GetNumber(2)
	//wxListItemAttr(colText, colBack, font);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_ListItemAttr, __GetBackgroundColour, "GetBackgroundColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ListItemAttr, __GetBackgroundColour)
{
	Object_wx_ListItemAttr *pThis = Object_wx_ListItemAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& _rtn = pThis->GetEntity()->GetBackgroundColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListItemAttr, __GetFont, "GetFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ListItemAttr, __GetFont)
{
	Object_wx_ListItemAttr *pThis = Object_wx_ListItemAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxFont& _rtn = pThis->GetEntity()->GetFont();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListItemAttr, __GetTextColour, "GetTextColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ListItemAttr, __GetTextColour)
{
	Object_wx_ListItemAttr *pThis = Object_wx_ListItemAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& _rtn = pThis->GetEntity()->GetTextColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListItemAttr, __HasBackgroundColour, "HasBackgroundColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ListItemAttr, __HasBackgroundColour)
{
	Object_wx_ListItemAttr *pThis = Object_wx_ListItemAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasBackgroundColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListItemAttr, __HasFont, "HasFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ListItemAttr, __HasFont)
{
	Object_wx_ListItemAttr *pThis = Object_wx_ListItemAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasFont();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListItemAttr, __HasTextColour, "HasTextColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ListItemAttr, __HasTextColour)
{
	Object_wx_ListItemAttr *pThis = Object_wx_ListItemAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasTextColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListItemAttr, __SetBackgroundColour, "SetBackgroundColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListItemAttr, __SetBackgroundColour)
{
	Object_wx_ListItemAttr *pThis = Object_wx_ListItemAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& colour = arg.GetNumber(0)
	//pThis->GetEntity()->SetBackgroundColour(colour);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListItemAttr, __SetFont, "SetFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListItemAttr, __SetFont)
{
	Object_wx_ListItemAttr *pThis = Object_wx_ListItemAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxFont& font = arg.GetNumber(0)
	//pThis->GetEntity()->SetFont(font);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ListItemAttr, __SetTextColour, "SetTextColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ListItemAttr, __SetTextColour)
{
	Object_wx_ListItemAttr *pThis = Object_wx_ListItemAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& colour = arg.GetNumber(0)
	//pThis->GetEntity()->SetTextColour(colour);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxListItemAttr
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ListItemAttr)
{
	// Constructor assignment
	Gura_AssignFunction(__ListItemAttr);
	Gura_AssignFunction(__ListItemAttr_1);
	// Method assignment
	Gura_AssignMethod(wx_ListItemAttr, __GetBackgroundColour);
	Gura_AssignMethod(wx_ListItemAttr, __GetFont);
	Gura_AssignMethod(wx_ListItemAttr, __GetTextColour);
	Gura_AssignMethod(wx_ListItemAttr, __HasBackgroundColour);
	Gura_AssignMethod(wx_ListItemAttr, __HasFont);
	Gura_AssignMethod(wx_ListItemAttr, __HasTextColour);
	Gura_AssignMethod(wx_ListItemAttr, __SetBackgroundColour);
	Gura_AssignMethod(wx_ListItemAttr, __SetFont);
	Gura_AssignMethod(wx_ListItemAttr, __SetTextColour);
}

Gura_ImplementDescendantCreator(wx_ListItemAttr)
{
	return new Object_wx_ListItemAttr((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
