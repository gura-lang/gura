//----------------------------------------------------------------------------
// wxDataViewItemAttr
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewItemAttr
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDataViewItemAttr
//----------------------------------------------------------------------------
Object_wx_DataViewItemAttr::~Object_wx_DataViewItemAttr()
{
}

Object *Object_wx_DataViewItemAttr::Clone() const
{
	return nullptr;
}

String Object_wx_DataViewItemAttr::ToString(bool exprFlag)
{
	String rtn("<wx.DataViewItemAttr:");
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
Gura_DeclareFunctionAlias(__DataViewItemAttr, "DataViewItemAttr")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_DataViewItemAttr));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DataViewItemAttr)
{
	//wxDataViewItemAttr();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_DataViewItemAttr, __SetBold, "SetBold")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "set", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewItemAttr, __SetBold)
{
	Object_wx_DataViewItemAttr *pThis = Object_wx_DataViewItemAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool set = arg.GetNumber(0)
	//pThis->GetEntity()->SetBold(set);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewItemAttr, __SetColour, "SetColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewItemAttr, __SetColour)
{
	Object_wx_DataViewItemAttr *pThis = Object_wx_DataViewItemAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& colour = arg.GetNumber(0)
	//pThis->GetEntity()->SetColour(colour);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewItemAttr, __SetBackgroundColour, "SetBackgroundColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewItemAttr, __SetBackgroundColour)
{
	Object_wx_DataViewItemAttr *pThis = Object_wx_DataViewItemAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& colour = arg.GetNumber(0)
	//pThis->GetEntity()->SetBackgroundColour(colour);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewItemAttr, __SetItalic, "SetItalic")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "set", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewItemAttr, __SetItalic)
{
	Object_wx_DataViewItemAttr *pThis = Object_wx_DataViewItemAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool set = arg.GetNumber(0)
	//pThis->GetEntity()->SetItalic(set);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewItemAttr, __HasColour, "HasColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewItemAttr, __HasColour)
{
	Object_wx_DataViewItemAttr *pThis = Object_wx_DataViewItemAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewItemAttr, __GetColour, "GetColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewItemAttr, __GetColour)
{
	Object_wx_DataViewItemAttr *pThis = Object_wx_DataViewItemAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& _rtn = pThis->GetEntity()->GetColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewItemAttr, __HasFont, "HasFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewItemAttr, __HasFont)
{
	Object_wx_DataViewItemAttr *pThis = Object_wx_DataViewItemAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasFont();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewItemAttr, __GetBold, "GetBold")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewItemAttr, __GetBold)
{
	Object_wx_DataViewItemAttr *pThis = Object_wx_DataViewItemAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->GetBold();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewItemAttr, __GetItalic, "GetItalic")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewItemAttr, __GetItalic)
{
	Object_wx_DataViewItemAttr *pThis = Object_wx_DataViewItemAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->GetItalic();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewItemAttr, __HasBackgroundColour, "HasBackgroundColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewItemAttr, __HasBackgroundColour)
{
	Object_wx_DataViewItemAttr *pThis = Object_wx_DataViewItemAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasBackgroundColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewItemAttr, __GetBackgroundColour, "GetBackgroundColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewItemAttr, __GetBackgroundColour)
{
	Object_wx_DataViewItemAttr *pThis = Object_wx_DataViewItemAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& _rtn = pThis->GetEntity()->GetBackgroundColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewItemAttr, __IsDefault, "IsDefault")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewItemAttr, __IsDefault)
{
	Object_wx_DataViewItemAttr *pThis = Object_wx_DataViewItemAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsDefault();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewItemAttr, __GetEffectiveFont, "GetEffectiveFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewItemAttr, __GetEffectiveFont)
{
	Object_wx_DataViewItemAttr *pThis = Object_wx_DataViewItemAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxFont& font = arg.GetNumber(0)
	//wxFont _rtn = pThis->GetEntity()->GetEffectiveFont(font);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDataViewItemAttr
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewItemAttr)
{
	// Constructor assignment
	Gura_AssignFunction(__DataViewItemAttr);
	// Method assignment
	Gura_AssignMethod(wx_DataViewItemAttr, __SetBold);
	Gura_AssignMethod(wx_DataViewItemAttr, __SetColour);
	Gura_AssignMethod(wx_DataViewItemAttr, __SetBackgroundColour);
	Gura_AssignMethod(wx_DataViewItemAttr, __SetItalic);
	Gura_AssignMethod(wx_DataViewItemAttr, __HasColour);
	Gura_AssignMethod(wx_DataViewItemAttr, __GetColour);
	Gura_AssignMethod(wx_DataViewItemAttr, __HasFont);
	Gura_AssignMethod(wx_DataViewItemAttr, __GetBold);
	Gura_AssignMethod(wx_DataViewItemAttr, __GetItalic);
	Gura_AssignMethod(wx_DataViewItemAttr, __HasBackgroundColour);
	Gura_AssignMethod(wx_DataViewItemAttr, __GetBackgroundColour);
	Gura_AssignMethod(wx_DataViewItemAttr, __IsDefault);
	Gura_AssignMethod(wx_DataViewItemAttr, __GetEffectiveFont);
}

Gura_ImplementDescendantCreator(wx_DataViewItemAttr)
{
	return new Object_wx_DataViewItemAttr((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
