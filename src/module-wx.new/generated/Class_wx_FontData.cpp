//----------------------------------------------------------------------------
// wxFontData
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFontData
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFontData
//----------------------------------------------------------------------------
Object_wx_FontData::~Object_wx_FontData()
{
}

Object *Object_wx_FontData::Clone() const
{
	return nullptr;
}

String Object_wx_FontData::ToString(bool exprFlag)
{
	String rtn("<wx.FontData:");
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
Gura_DeclareMethod(wx_FontData, wxFontData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FontData, wxFontData)
{
	Object_wx_FontData *pThis = Object_wx_FontData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxFontData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontData, EnableEffects)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontData, EnableEffects)
{
	Object_wx_FontData *pThis = Object_wx_FontData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int enable = arg.GetNumber(0)
	//pThis->GetEntity()->EnableEffects();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontData, GetAllowSymbols)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FontData, GetAllowSymbols)
{
	Object_wx_FontData *pThis = Object_wx_FontData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAllowSymbols();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontData, GetChosenFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FontData, GetChosenFont)
{
	Object_wx_FontData *pThis = Object_wx_FontData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetChosenFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontData, GetColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FontData, GetColour)
{
	Object_wx_FontData *pThis = Object_wx_FontData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontData, GetEnableEffects)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FontData, GetEnableEffects)
{
	Object_wx_FontData *pThis = Object_wx_FontData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEnableEffects();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontData, GetInitialFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FontData, GetInitialFont)
{
	Object_wx_FontData *pThis = Object_wx_FontData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetInitialFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontData, GetShowHelp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FontData, GetShowHelp)
{
	Object_wx_FontData *pThis = Object_wx_FontData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetShowHelp();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontData, SetAllowSymbols)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "allowSymbols", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontData, SetAllowSymbols)
{
	Object_wx_FontData *pThis = Object_wx_FontData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int allowSymbols = arg.GetNumber(0)
	//pThis->GetEntity()->SetAllowSymbols();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontData, SetChosenFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontData, SetChosenFont)
{
	Object_wx_FontData *pThis = Object_wx_FontData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int font = arg.GetNumber(0)
	//pThis->GetEntity()->SetChosenFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontData, SetColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontData, SetColour)
{
	Object_wx_FontData *pThis = Object_wx_FontData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int colour = arg.GetNumber(0)
	//pThis->GetEntity()->SetColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontData, SetInitialFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontData, SetInitialFont)
{
	Object_wx_FontData *pThis = Object_wx_FontData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int font = arg.GetNumber(0)
	//pThis->GetEntity()->SetInitialFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontData, SetRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "min", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "max", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontData, SetRange)
{
	Object_wx_FontData *pThis = Object_wx_FontData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int min = arg.GetNumber(0)
	//int max = arg.GetNumber(1)
	//pThis->GetEntity()->SetRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FontData, SetShowHelp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "showHelp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontData, SetShowHelp)
{
	Object_wx_FontData *pThis = Object_wx_FontData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int showHelp = arg.GetNumber(0)
	//pThis->GetEntity()->SetShowHelp();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFontData
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FontData)
{
	Gura_AssignMethod(wx_FontData, wxFontData);
	Gura_AssignMethod(wx_FontData, EnableEffects);
	Gura_AssignMethod(wx_FontData, GetAllowSymbols);
	Gura_AssignMethod(wx_FontData, GetChosenFont);
	Gura_AssignMethod(wx_FontData, GetColour);
	Gura_AssignMethod(wx_FontData, GetEnableEffects);
	Gura_AssignMethod(wx_FontData, GetInitialFont);
	Gura_AssignMethod(wx_FontData, GetShowHelp);
	Gura_AssignMethod(wx_FontData, SetAllowSymbols);
	Gura_AssignMethod(wx_FontData, SetChosenFont);
	Gura_AssignMethod(wx_FontData, SetColour);
	Gura_AssignMethod(wx_FontData, SetInitialFont);
	Gura_AssignMethod(wx_FontData, SetRange);
	Gura_AssignMethod(wx_FontData, SetShowHelp);
}

Gura_ImplementDescendantCreator(wx_FontData)
{
	return new Object_wx_FontData((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
