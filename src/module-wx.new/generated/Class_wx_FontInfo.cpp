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
Gura_DeclareFunctionAlias(__FontInfo, "FontInfo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_FontInfo));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__FontInfo)
{
	//wxFontInfo();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__FontInfo_1, "FontInfo_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pointSize", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_FontInfo));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__FontInfo_1)
{
	//int pointSize = arg.GetNumber(0)
	//explicit _rtn = wxFontInfo(pointSize);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__FontInfo_2, "FontInfo_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pixelSize", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_FontInfo));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__FontInfo_2)
{
	//const wxSize& pixelSize = arg.GetNumber(0)
	//explicit _rtn = wxFontInfo(pixelSize);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_FontInfo, __Family, "Family")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "family", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontInfo, __Family)
{
	Object_wx_FontInfo *pThis = Object_wx_FontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFontFamily family = arg.GetNumber(0)
	//wxFontInfo& _rtn = pThis->GetEntity()->Family(family);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FontInfo, __FaceName, "FaceName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "faceName", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontInfo, __FaceName)
{
	Object_wx_FontInfo *pThis = Object_wx_FontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& faceName = arg.GetNumber(0)
	//wxFontInfo& _rtn = pThis->GetEntity()->FaceName(faceName);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FontInfo, __Bold, "Bold")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "bold", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontInfo, __Bold)
{
	Object_wx_FontInfo *pThis = Object_wx_FontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool bold = arg.GetNumber(0)
	//wxFontInfo& _rtn = pThis->GetEntity()->Bold(bold);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FontInfo, __Light, "Light")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "light", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontInfo, __Light)
{
	Object_wx_FontInfo *pThis = Object_wx_FontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool light = arg.GetNumber(0)
	//wxFontInfo& _rtn = pThis->GetEntity()->Light(light);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FontInfo, __Italic, "Italic")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "italic", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontInfo, __Italic)
{
	Object_wx_FontInfo *pThis = Object_wx_FontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool italic = arg.GetNumber(0)
	//wxFontInfo& _rtn = pThis->GetEntity()->Italic(italic);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FontInfo, __Slant, "Slant")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "slant", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontInfo, __Slant)
{
	Object_wx_FontInfo *pThis = Object_wx_FontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool slant = arg.GetNumber(0)
	//wxFontInfo& _rtn = pThis->GetEntity()->Slant(slant);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FontInfo, __AntiAliased, "AntiAliased")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "antiAliased", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontInfo, __AntiAliased)
{
	Object_wx_FontInfo *pThis = Object_wx_FontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool antiAliased = arg.GetNumber(0)
	//wxFontInfo& _rtn = pThis->GetEntity()->AntiAliased(antiAliased);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FontInfo, __Underlined, "Underlined")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "underlined", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontInfo, __Underlined)
{
	Object_wx_FontInfo *pThis = Object_wx_FontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool underlined = arg.GetNumber(0)
	//wxFontInfo& _rtn = pThis->GetEntity()->Underlined(underlined);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FontInfo, __Strikethrough, "Strikethrough")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "strikethrough", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontInfo, __Strikethrough)
{
	Object_wx_FontInfo *pThis = Object_wx_FontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool strikethrough = arg.GetNumber(0)
	//wxFontInfo& _rtn = pThis->GetEntity()->Strikethrough(strikethrough);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FontInfo, __Encoding, "Encoding")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontInfo, __Encoding)
{
	Object_wx_FontInfo *pThis = Object_wx_FontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFontEncoding encoding = arg.GetNumber(0)
	//wxFontInfo& _rtn = pThis->GetEntity()->Encoding(encoding);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FontInfo, __AllFlags, "AllFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FontInfo, __AllFlags)
{
	Object_wx_FontInfo *pThis = Object_wx_FontInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//wxFontInfo& _rtn = pThis->GetEntity()->AllFlags(flags);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFontInfo
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FontInfo)
{
	// Constructor assignment
	Gura_AssignFunction(__FontInfo);
	Gura_AssignFunction(__FontInfo_1);
	Gura_AssignFunction(__FontInfo_2);
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
