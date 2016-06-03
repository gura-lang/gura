//----------------------------------------------------------------------------
// wxTextAttrBorder
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTextAttrBorder
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTextAttrBorder
//----------------------------------------------------------------------------
Object_wx_TextAttrBorder::~Object_wx_TextAttrBorder()
{
}

Object *Object_wx_TextAttrBorder::Clone() const
{
	return nullptr;
}

String Object_wx_TextAttrBorder::ToString(bool exprFlag)
{
	String rtn("<wx.TextAttrBorder:");
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
Gura_DeclareFunctionAlias(__TextAttrBorder, "TextAttrBorder")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_TextAttrBorder));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__TextAttrBorder)
{
	//wxTextAttrBorder();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_TextAttrBorder, __Reset, "Reset")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrBorder, __Reset)
{
	Object_wx_TextAttrBorder *pThis = Object_wx_TextAttrBorder::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Reset();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrBorder, __EqPartial, "EqPartial")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "border", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "weakTest", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrBorder, __EqPartial)
{
	Object_wx_TextAttrBorder *pThis = Object_wx_TextAttrBorder::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTextAttrBorder& border = arg.GetNumber(0)
	//bool weakTest = arg.GetNumber(1)
	//pThis->GetEntity()->EqPartial();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrBorder, __Apply, "Apply")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "border", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "compareWith", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrBorder, __Apply)
{
	Object_wx_TextAttrBorder *pThis = Object_wx_TextAttrBorder::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTextAttrBorder& border = arg.GetNumber(0)
	//const wxTextAttrBorder* compareWith = arg.GetNumber(1)
	//pThis->GetEntity()->Apply();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrBorder, __RemoveStyle, "RemoveStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrBorder, __RemoveStyle)
{
	Object_wx_TextAttrBorder *pThis = Object_wx_TextAttrBorder::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTextAttrBorder& attr = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrBorder, __CollectCommonAttributes, "CollectCommonAttributes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clashingAttr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "absentAttr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrBorder, __CollectCommonAttributes)
{
	Object_wx_TextAttrBorder *pThis = Object_wx_TextAttrBorder::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTextAttrBorder& attr = arg.GetNumber(0)
	//wxTextAttrBorder& clashingAttr = arg.GetNumber(1)
	//wxTextAttrBorder& absentAttr = arg.GetNumber(2)
	//pThis->GetEntity()->CollectCommonAttributes();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrBorder, __SetStyle, "SetStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrBorder, __SetStyle)
{
	Object_wx_TextAttrBorder *pThis = Object_wx_TextAttrBorder::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->SetStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrBorder, __GetStyle, "GetStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrBorder, __GetStyle)
{
	Object_wx_TextAttrBorder *pThis = Object_wx_TextAttrBorder::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrBorder, __SetColour, "SetColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrBorder, __SetColour)
{
	Object_wx_TextAttrBorder *pThis = Object_wx_TextAttrBorder::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned long colour = arg.GetNumber(0)
	//pThis->GetEntity()->SetColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrBorder, __SetColour_1, "SetColour_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrBorder, __SetColour_1)
{
	Object_wx_TextAttrBorder *pThis = Object_wx_TextAttrBorder::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& colour = arg.GetNumber(0)
	//pThis->GetEntity()->SetColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrBorder, __GetColourLong, "GetColourLong")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrBorder, __GetColourLong)
{
	Object_wx_TextAttrBorder *pThis = Object_wx_TextAttrBorder::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetColourLong();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrBorder, __GetColour, "GetColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrBorder, __GetColour)
{
	Object_wx_TextAttrBorder *pThis = Object_wx_TextAttrBorder::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrBorder, __GetWidth, "GetWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrBorder, __GetWidth)
{
	Object_wx_TextAttrBorder *pThis = Object_wx_TextAttrBorder::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWidth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrBorder, __GetWidth_1, "GetWidth_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrBorder, __GetWidth_1)
{
	Object_wx_TextAttrBorder *pThis = Object_wx_TextAttrBorder::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWidth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrBorder, __SetWidth, "SetWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrBorder, __SetWidth)
{
	Object_wx_TextAttrBorder *pThis = Object_wx_TextAttrBorder::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTextAttrDimension& width = arg.GetNumber(0)
	//pThis->GetEntity()->SetWidth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrBorder, __SetWidth_1, "SetWidth_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "units", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrBorder, __SetWidth_1)
{
	Object_wx_TextAttrBorder *pThis = Object_wx_TextAttrBorder::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//wxTextAttrUnits units = arg.GetNumber(1)
	//pThis->GetEntity()->SetWidth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrBorder, __HasStyle, "HasStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrBorder, __HasStyle)
{
	Object_wx_TextAttrBorder *pThis = Object_wx_TextAttrBorder::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrBorder, __HasColour, "HasColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrBorder, __HasColour)
{
	Object_wx_TextAttrBorder *pThis = Object_wx_TextAttrBorder::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrBorder, __HasWidth, "HasWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrBorder, __HasWidth)
{
	Object_wx_TextAttrBorder *pThis = Object_wx_TextAttrBorder::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasWidth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrBorder, __IsValid, "IsValid")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrBorder, __IsValid)
{
	Object_wx_TextAttrBorder *pThis = Object_wx_TextAttrBorder::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsValid();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrBorder, __IsDefault, "IsDefault")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrBorder, __IsDefault)
{
	Object_wx_TextAttrBorder *pThis = Object_wx_TextAttrBorder::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsDefault();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrBorder, __MakeValid, "MakeValid")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrBorder, __MakeValid)
{
	Object_wx_TextAttrBorder *pThis = Object_wx_TextAttrBorder::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->MakeValid();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrBorder, __GetFlags, "GetFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrBorder, __GetFlags)
{
	Object_wx_TextAttrBorder *pThis = Object_wx_TextAttrBorder::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFlags();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrBorder, __SetFlags, "SetFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrBorder, __SetFlags)
{
	Object_wx_TextAttrBorder *pThis = Object_wx_TextAttrBorder::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->SetFlags();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrBorder, __AddFlag, "AddFlag")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrBorder, __AddFlag)
{
	Object_wx_TextAttrBorder *pThis = Object_wx_TextAttrBorder::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->AddFlag();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttrBorder, __RemoveFlag, "RemoveFlag")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrBorder, __RemoveFlag)
{
	Object_wx_TextAttrBorder *pThis = Object_wx_TextAttrBorder::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveFlag();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTextAttrBorder
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextAttrBorder)
{
	// Constructor assignment
	Gura_AssignFunction(__TextAttrBorder);
	// Method assignment
	Gura_AssignMethod(wx_TextAttrBorder, __Reset);
	Gura_AssignMethod(wx_TextAttrBorder, __EqPartial);
	Gura_AssignMethod(wx_TextAttrBorder, __Apply);
	Gura_AssignMethod(wx_TextAttrBorder, __RemoveStyle);
	Gura_AssignMethod(wx_TextAttrBorder, __CollectCommonAttributes);
	Gura_AssignMethod(wx_TextAttrBorder, __SetStyle);
	Gura_AssignMethod(wx_TextAttrBorder, __GetStyle);
	Gura_AssignMethod(wx_TextAttrBorder, __SetColour);
	Gura_AssignMethod(wx_TextAttrBorder, __SetColour_1);
	Gura_AssignMethod(wx_TextAttrBorder, __GetColourLong);
	Gura_AssignMethod(wx_TextAttrBorder, __GetColour);
	Gura_AssignMethod(wx_TextAttrBorder, __GetWidth);
	Gura_AssignMethod(wx_TextAttrBorder, __GetWidth_1);
	Gura_AssignMethod(wx_TextAttrBorder, __SetWidth);
	Gura_AssignMethod(wx_TextAttrBorder, __SetWidth_1);
	Gura_AssignMethod(wx_TextAttrBorder, __HasStyle);
	Gura_AssignMethod(wx_TextAttrBorder, __HasColour);
	Gura_AssignMethod(wx_TextAttrBorder, __HasWidth);
	Gura_AssignMethod(wx_TextAttrBorder, __IsValid);
	Gura_AssignMethod(wx_TextAttrBorder, __IsDefault);
	Gura_AssignMethod(wx_TextAttrBorder, __MakeValid);
	Gura_AssignMethod(wx_TextAttrBorder, __GetFlags);
	Gura_AssignMethod(wx_TextAttrBorder, __SetFlags);
	Gura_AssignMethod(wx_TextAttrBorder, __AddFlag);
	Gura_AssignMethod(wx_TextAttrBorder, __RemoveFlag);
}

Gura_ImplementDescendantCreator(wx_TextAttrBorder)
{
	return new Object_wx_TextAttrBorder((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
