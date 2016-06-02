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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_TextAttrBorder, wxTextAttrBorder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrBorder, wxTextAttrBorder)
{
	Object_wx_TextAttrBorder *pThis = Object_wx_TextAttrBorder::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxTextAttrBorder();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrBorder, Reset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrBorder, Reset)
{
	Object_wx_TextAttrBorder *pThis = Object_wx_TextAttrBorder::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Reset();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrBorder, EqPartial)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "border", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "weakTest", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrBorder, EqPartial)
{
	Object_wx_TextAttrBorder *pThis = Object_wx_TextAttrBorder::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int border = arg.GetNumber(0)
	//int weakTest = arg.GetNumber(1)
	//pThis->GetEntity()->EqPartial();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrBorder, Apply)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "border", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "compareWith", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrBorder, Apply)
{
	Object_wx_TextAttrBorder *pThis = Object_wx_TextAttrBorder::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int border = arg.GetNumber(0)
	//int compareWith = arg.GetNumber(1)
	//pThis->GetEntity()->Apply();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrBorder, RemoveStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrBorder, RemoveStyle)
{
	Object_wx_TextAttrBorder *pThis = Object_wx_TextAttrBorder::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int attr = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrBorder, CollectCommonAttributes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clashingAttr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "absentAttr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrBorder, CollectCommonAttributes)
{
	Object_wx_TextAttrBorder *pThis = Object_wx_TextAttrBorder::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int attr = arg.GetNumber(0)
	//int clashingAttr = arg.GetNumber(1)
	//int absentAttr = arg.GetNumber(2)
	//pThis->GetEntity()->CollectCommonAttributes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrBorder, SetStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrBorder, SetStyle)
{
	Object_wx_TextAttrBorder *pThis = Object_wx_TextAttrBorder::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->SetStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrBorder, GetStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrBorder, GetStyle)
{
	Object_wx_TextAttrBorder *pThis = Object_wx_TextAttrBorder::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrBorder, SetColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrBorder, SetColour)
{
	Object_wx_TextAttrBorder *pThis = Object_wx_TextAttrBorder::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int colour = arg.GetNumber(0)
	//pThis->GetEntity()->SetColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrBorder, SetColour_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrBorder, SetColour_1)
{
	Object_wx_TextAttrBorder *pThis = Object_wx_TextAttrBorder::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int colour = arg.GetNumber(0)
	//pThis->GetEntity()->SetColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrBorder, GetColourLong)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrBorder, GetColourLong)
{
	Object_wx_TextAttrBorder *pThis = Object_wx_TextAttrBorder::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetColourLong();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrBorder, GetColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrBorder, GetColour)
{
	Object_wx_TextAttrBorder *pThis = Object_wx_TextAttrBorder::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrBorder, GetWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrBorder, GetWidth)
{
	Object_wx_TextAttrBorder *pThis = Object_wx_TextAttrBorder::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrBorder, GetWidth_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrBorder, GetWidth_1)
{
	Object_wx_TextAttrBorder *pThis = Object_wx_TextAttrBorder::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrBorder, SetWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrBorder, SetWidth)
{
	Object_wx_TextAttrBorder *pThis = Object_wx_TextAttrBorder::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int width = arg.GetNumber(0)
	//pThis->GetEntity()->SetWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrBorder, SetWidth_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "units", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrBorder, SetWidth_1)
{
	Object_wx_TextAttrBorder *pThis = Object_wx_TextAttrBorder::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//int units = arg.GetNumber(1)
	//pThis->GetEntity()->SetWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrBorder, HasStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrBorder, HasStyle)
{
	Object_wx_TextAttrBorder *pThis = Object_wx_TextAttrBorder::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrBorder, HasColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrBorder, HasColour)
{
	Object_wx_TextAttrBorder *pThis = Object_wx_TextAttrBorder::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrBorder, HasWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrBorder, HasWidth)
{
	Object_wx_TextAttrBorder *pThis = Object_wx_TextAttrBorder::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrBorder, IsValid)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrBorder, IsValid)
{
	Object_wx_TextAttrBorder *pThis = Object_wx_TextAttrBorder::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsValid();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrBorder, IsDefault)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrBorder, IsDefault)
{
	Object_wx_TextAttrBorder *pThis = Object_wx_TextAttrBorder::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsDefault();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrBorder, MakeValid)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrBorder, MakeValid)
{
	Object_wx_TextAttrBorder *pThis = Object_wx_TextAttrBorder::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->MakeValid();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrBorder, GetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttrBorder, GetFlags)
{
	Object_wx_TextAttrBorder *pThis = Object_wx_TextAttrBorder::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrBorder, SetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrBorder, SetFlags)
{
	Object_wx_TextAttrBorder *pThis = Object_wx_TextAttrBorder::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->SetFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrBorder, AddFlag)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrBorder, AddFlag)
{
	Object_wx_TextAttrBorder *pThis = Object_wx_TextAttrBorder::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->AddFlag();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttrBorder, RemoveFlag)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttrBorder, RemoveFlag)
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
	Gura_AssignMethod(wx_TextAttrBorder, wxTextAttrBorder);
	Gura_AssignMethod(wx_TextAttrBorder, Reset);
	Gura_AssignMethod(wx_TextAttrBorder, EqPartial);
	Gura_AssignMethod(wx_TextAttrBorder, Apply);
	Gura_AssignMethod(wx_TextAttrBorder, RemoveStyle);
	Gura_AssignMethod(wx_TextAttrBorder, CollectCommonAttributes);
	Gura_AssignMethod(wx_TextAttrBorder, SetStyle);
	Gura_AssignMethod(wx_TextAttrBorder, GetStyle);
	Gura_AssignMethod(wx_TextAttrBorder, SetColour);
	Gura_AssignMethod(wx_TextAttrBorder, SetColour_1);
	Gura_AssignMethod(wx_TextAttrBorder, GetColourLong);
	Gura_AssignMethod(wx_TextAttrBorder, GetColour);
	Gura_AssignMethod(wx_TextAttrBorder, GetWidth);
	Gura_AssignMethod(wx_TextAttrBorder, GetWidth_1);
	Gura_AssignMethod(wx_TextAttrBorder, SetWidth);
	Gura_AssignMethod(wx_TextAttrBorder, SetWidth_1);
	Gura_AssignMethod(wx_TextAttrBorder, HasStyle);
	Gura_AssignMethod(wx_TextAttrBorder, HasColour);
	Gura_AssignMethod(wx_TextAttrBorder, HasWidth);
	Gura_AssignMethod(wx_TextAttrBorder, IsValid);
	Gura_AssignMethod(wx_TextAttrBorder, IsDefault);
	Gura_AssignMethod(wx_TextAttrBorder, MakeValid);
	Gura_AssignMethod(wx_TextAttrBorder, GetFlags);
	Gura_AssignMethod(wx_TextAttrBorder, SetFlags);
	Gura_AssignMethod(wx_TextAttrBorder, AddFlag);
	Gura_AssignMethod(wx_TextAttrBorder, RemoveFlag);
}

Gura_ImplementDescendantCreator(wx_TextAttrBorder)
{
	return new Object_wx_TextAttrBorder((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
