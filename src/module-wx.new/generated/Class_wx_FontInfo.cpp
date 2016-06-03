//----------------------------------------------------------------------------
// wxFontInfo
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFontInfo
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFontInfo
//----------------------------------------------------------------------------
Object_wx_FontInfo::~Object_wx_FontInfo()
{
}

Object *Object_wx_FontInfo::Clone() const
{
	return nullptr;
}

String Object_wx_FontInfo::ToString(bool exprFlag)
{
	String rtn("<wx.FontInfo:");
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
Gura_DeclareFunctionAlias(__wxFontInfo, "wxFontInfo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(__wxFontInfo)
{
	//wxFontInfo();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxFontInfo_1, "wxFontInfo_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pointSize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxFontInfo_1)
{
	//int pointSize = arg.GetNumber(0)
	//wxFontInfo();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxFontInfo_2, "wxFontInfo_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pixelSize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxFontInfo_2)
{
	//int pixelSize = arg.GetNumber(0)
	//wxFontInfo();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_FontInfo, __Family, "Family")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "family", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontInfo, __Family)
{
	Object_wx_FontInfo *pThis = Object_wx_FontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int family = arg.GetNumber(0)
	//pThis->GetEntity()->Family();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FontInfo, __FaceName, "FaceName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "faceName", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontInfo, __FaceName)
{
	Object_wx_FontInfo *pThis = Object_wx_FontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int faceName = arg.GetNumber(0)
	//pThis->GetEntity()->FaceName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FontInfo, __Bold, "Bold")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bold", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontInfo, __Bold)
{
	Object_wx_FontInfo *pThis = Object_wx_FontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bold = arg.GetNumber(0)
	//pThis->GetEntity()->Bold();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FontInfo, __Light, "Light")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "light", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontInfo, __Light)
{
	Object_wx_FontInfo *pThis = Object_wx_FontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int light = arg.GetNumber(0)
	//pThis->GetEntity()->Light();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FontInfo, __Italic, "Italic")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "italic", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontInfo, __Italic)
{
	Object_wx_FontInfo *pThis = Object_wx_FontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int italic = arg.GetNumber(0)
	//pThis->GetEntity()->Italic();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FontInfo, __Slant, "Slant")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "slant", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontInfo, __Slant)
{
	Object_wx_FontInfo *pThis = Object_wx_FontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int slant = arg.GetNumber(0)
	//pThis->GetEntity()->Slant();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FontInfo, __AntiAliased, "AntiAliased")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "antiAliased", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontInfo, __AntiAliased)
{
	Object_wx_FontInfo *pThis = Object_wx_FontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int antiAliased = arg.GetNumber(0)
	//pThis->GetEntity()->AntiAliased();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FontInfo, __Underlined, "Underlined")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "underlined", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontInfo, __Underlined)
{
	Object_wx_FontInfo *pThis = Object_wx_FontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int underlined = arg.GetNumber(0)
	//pThis->GetEntity()->Underlined();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FontInfo, __Strikethrough, "Strikethrough")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "strikethrough", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontInfo, __Strikethrough)
{
	Object_wx_FontInfo *pThis = Object_wx_FontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int strikethrough = arg.GetNumber(0)
	//pThis->GetEntity()->Strikethrough();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FontInfo, __Encoding, "Encoding")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontInfo, __Encoding)
{
	Object_wx_FontInfo *pThis = Object_wx_FontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int encoding = arg.GetNumber(0)
	//pThis->GetEntity()->Encoding();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FontInfo, __AllFlags, "AllFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontInfo, __AllFlags)
{
	Object_wx_FontInfo *pThis = Object_wx_FontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->AllFlags();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFontInfo
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FontInfo)
{
	// Constructor assignment
	Gura_AssignFunction(__wxFontInfo);
	Gura_AssignFunction(__wxFontInfo_1);
	Gura_AssignFunction(__wxFontInfo_2);
	// Method assignment
	Gura_AssignMethod(wx_FontInfo, __Family);
	Gura_AssignMethod(wx_FontInfo, __FaceName);
	Gura_AssignMethod(wx_FontInfo, __Bold);
	Gura_AssignMethod(wx_FontInfo, __Light);
	Gura_AssignMethod(wx_FontInfo, __Italic);
	Gura_AssignMethod(wx_FontInfo, __Slant);
	Gura_AssignMethod(wx_FontInfo, __AntiAliased);
	Gura_AssignMethod(wx_FontInfo, __Underlined);
	Gura_AssignMethod(wx_FontInfo, __Strikethrough);
	Gura_AssignMethod(wx_FontInfo, __Encoding);
	Gura_AssignMethod(wx_FontInfo, __AllFlags);
}

Gura_ImplementDescendantCreator(wx_FontInfo)
{
	return new Object_wx_FontInfo((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
