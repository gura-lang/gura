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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxFontData, "wxFontData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(__wxFontData)
{
	//wxFontData();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_FontData, __EnableEffects, "EnableEffects")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontData, __EnableEffects)
{
	Object_wx_FontData *pThis = Object_wx_FontData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int enable = arg.GetNumber(0)
	//pThis->GetEntity()->EnableEffects();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FontData, __GetAllowSymbols, "GetAllowSymbols")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FontData, __GetAllowSymbols)
{
	Object_wx_FontData *pThis = Object_wx_FontData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAllowSymbols();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FontData, __GetChosenFont, "GetChosenFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FontData, __GetChosenFont)
{
	Object_wx_FontData *pThis = Object_wx_FontData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetChosenFont();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FontData, __GetColour, "GetColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FontData, __GetColour)
{
	Object_wx_FontData *pThis = Object_wx_FontData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FontData, __GetEnableEffects, "GetEnableEffects")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FontData, __GetEnableEffects)
{
	Object_wx_FontData *pThis = Object_wx_FontData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEnableEffects();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FontData, __GetInitialFont, "GetInitialFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FontData, __GetInitialFont)
{
	Object_wx_FontData *pThis = Object_wx_FontData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetInitialFont();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FontData, __GetShowHelp, "GetShowHelp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FontData, __GetShowHelp)
{
	Object_wx_FontData *pThis = Object_wx_FontData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetShowHelp();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FontData, __SetAllowSymbols, "SetAllowSymbols")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "allowSymbols", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontData, __SetAllowSymbols)
{
	Object_wx_FontData *pThis = Object_wx_FontData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int allowSymbols = arg.GetNumber(0)
	//pThis->GetEntity()->SetAllowSymbols();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FontData, __SetChosenFont, "SetChosenFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontData, __SetChosenFont)
{
	Object_wx_FontData *pThis = Object_wx_FontData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int font = arg.GetNumber(0)
	//pThis->GetEntity()->SetChosenFont();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FontData, __SetColour, "SetColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontData, __SetColour)
{
	Object_wx_FontData *pThis = Object_wx_FontData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int colour = arg.GetNumber(0)
	//pThis->GetEntity()->SetColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FontData, __SetInitialFont, "SetInitialFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontData, __SetInitialFont)
{
	Object_wx_FontData *pThis = Object_wx_FontData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int font = arg.GetNumber(0)
	//pThis->GetEntity()->SetInitialFont();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FontData, __SetRange, "SetRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "min", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "max", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontData, __SetRange)
{
	Object_wx_FontData *pThis = Object_wx_FontData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int min = arg.GetNumber(0)
	//int max = arg.GetNumber(1)
	//pThis->GetEntity()->SetRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FontData, __SetShowHelp, "SetShowHelp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "showHelp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontData, __SetShowHelp)
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
	// Constructor assignment
	Gura_AssignFunction(__wxFontData);
	// Method assignment
	Gura_AssignMethod(wx_FontData, __EnableEffects);
	Gura_AssignMethod(wx_FontData, __GetAllowSymbols);
	Gura_AssignMethod(wx_FontData, __GetChosenFont);
	Gura_AssignMethod(wx_FontData, __GetColour);
	Gura_AssignMethod(wx_FontData, __GetEnableEffects);
	Gura_AssignMethod(wx_FontData, __GetInitialFont);
	Gura_AssignMethod(wx_FontData, __GetShowHelp);
	Gura_AssignMethod(wx_FontData, __SetAllowSymbols);
	Gura_AssignMethod(wx_FontData, __SetChosenFont);
	Gura_AssignMethod(wx_FontData, __SetColour);
	Gura_AssignMethod(wx_FontData, __SetInitialFont);
	Gura_AssignMethod(wx_FontData, __SetRange);
	Gura_AssignMethod(wx_FontData, __SetShowHelp);
}

Gura_ImplementDescendantCreator(wx_FontData)
{
	return new Object_wx_FontData((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
