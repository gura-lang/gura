//----------------------------------------------------------------------------
// wxFont
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFont
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFont
//----------------------------------------------------------------------------
Object_wx_Font::~Object_wx_Font()
{
}

Object *Object_wx_Font::Clone() const
{
	return nullptr;
}

String Object_wx_Font::ToString(bool exprFlag)
{
	String rtn("<wx.Font:");
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
Gura_DeclareFunctionAlias(__Font, "Font")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Font));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Font)
{
	//wxFont();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Font_1, "Font_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Font));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Font_1)
{
	//const wxFont& font = arg.GetNumber(0)
	//wxFont(font);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Font_2, "Font_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Font));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Font_2)
{
	//const wxFontInfo& font = arg.GetNumber(0)
	//wxFont(font);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Font_3, "Font_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pointSize", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "family", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "weight", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "underline", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "faceName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Font));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Font_3)
{
	//int pointSize = arg.GetNumber(0)
	//wxFontFamily family = arg.GetNumber(1)
	//wxFontStyle style = arg.GetNumber(2)
	//wxFontWeight weight = arg.GetNumber(3)
	//bool underline = arg.GetNumber(4)
	//const wxString& faceName = arg.GetNumber(5)
	//wxFontEncoding encoding = arg.GetNumber(6)
	//wxFont(pointSize, family, style, weight, underline, faceName, encoding);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Font_4, "Font_4")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pixelSize", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "family", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "weight", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "underline", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "faceName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Font));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Font_4)
{
	//const wxSize& pixelSize = arg.GetNumber(0)
	//wxFontFamily family = arg.GetNumber(1)
	//wxFontStyle style = arg.GetNumber(2)
	//wxFontWeight weight = arg.GetNumber(3)
	//bool underline = arg.GetNumber(4)
	//const wxString& faceName = arg.GetNumber(5)
	//wxFontEncoding encoding = arg.GetNumber(6)
	//wxFont(pixelSize, family, style, weight, underline, faceName, encoding);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Font_5, "Font_5")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "nativeInfoString", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Font));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Font_5)
{
	//const wxString& nativeInfoString = arg.GetNumber(0)
	//wxFont(nativeInfoString);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Font_6, "Font_6")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "nativeInfo", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Font));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Font_6)
{
	//const wxNativeFontInfo& nativeInfo = arg.GetNumber(0)
	//wxFont(nativeInfo);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Font, __GetBaseFont, "GetBaseFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Font, __GetBaseFont)
{
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFont _rtn = pThis->GetEntity()->GetBaseFont();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Font, __GetEncoding, "GetEncoding")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Font, __GetEncoding)
{
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFontEncoding _rtn = pThis->GetEntity()->GetEncoding();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Font, __GetFaceName, "GetFaceName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Font, __GetFaceName)
{
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetFaceName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Font, __GetFamily, "GetFamily")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Font, __GetFamily)
{
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFontFamily _rtn = pThis->GetEntity()->GetFamily();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Font, __GetNativeFontInfoDesc, "GetNativeFontInfoDesc")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Font, __GetNativeFontInfoDesc)
{
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetNativeFontInfoDesc();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Font, __GetNativeFontInfoUserDesc, "GetNativeFontInfoUserDesc")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Font, __GetNativeFontInfoUserDesc)
{
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetNativeFontInfoUserDesc();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Font, __GetNativeFontInfo, "GetNativeFontInfo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Font, __GetNativeFontInfo)
{
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxNativeFontInfo* _rtn = pThis->GetEntity()->GetNativeFontInfo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Font, __GetPointSize, "GetPointSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Font, __GetPointSize)
{
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetPointSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Font, __GetPixelSize, "GetPixelSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Font, __GetPixelSize)
{
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxSize _rtn = pThis->GetEntity()->GetPixelSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Font, __GetStyle, "GetStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Font, __GetStyle)
{
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFontStyle _rtn = pThis->GetEntity()->GetStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Font, __GetUnderlined, "GetUnderlined")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Font, __GetUnderlined)
{
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->GetUnderlined();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Font, __GetStrikethrough, "GetStrikethrough")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Font, __GetStrikethrough)
{
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->GetStrikethrough();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Font, __GetWeight, "GetWeight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Font, __GetWeight)
{
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFontWeight _rtn = pThis->GetEntity()->GetWeight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Font, __IsFixedWidth, "IsFixedWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Font, __IsFixedWidth)
{
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsFixedWidth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Font, __IsOk, "IsOk")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Font, __IsOk)
{
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Font, __Bold, "Bold")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Font, __Bold)
{
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFont _rtn = pThis->GetEntity()->Bold();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Font, __Italic, "Italic")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Font, __Italic)
{
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFont _rtn = pThis->GetEntity()->Italic();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Font, __Larger, "Larger")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Font, __Larger)
{
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFont _rtn = pThis->GetEntity()->Larger();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Font, __Smaller, "Smaller")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Font, __Smaller)
{
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFont _rtn = pThis->GetEntity()->Smaller();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Font, __Underlined, "Underlined")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Font, __Underlined)
{
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFont _rtn = pThis->GetEntity()->Underlined();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Font, __Strikethrough, "Strikethrough")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Font, __Strikethrough)
{
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFont _rtn = pThis->GetEntity()->Strikethrough();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Font, __MakeBold, "MakeBold")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Font, __MakeBold)
{
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFont& _rtn = pThis->GetEntity()->MakeBold();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Font, __MakeItalic, "MakeItalic")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Font, __MakeItalic)
{
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFont& _rtn = pThis->GetEntity()->MakeItalic();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Font, __MakeLarger, "MakeLarger")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Font, __MakeLarger)
{
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFont& _rtn = pThis->GetEntity()->MakeLarger();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Font, __MakeSmaller, "MakeSmaller")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Font, __MakeSmaller)
{
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFont& _rtn = pThis->GetEntity()->MakeSmaller();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Font, __MakeUnderlined, "MakeUnderlined")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Font, __MakeUnderlined)
{
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFont& _rtn = pThis->GetEntity()->MakeUnderlined();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Font, __MakeStrikethrough, "MakeStrikethrough")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Font, __MakeStrikethrough)
{
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFont& _rtn = pThis->GetEntity()->MakeStrikethrough();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Font, __Scale, "Scale")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, __Scale)
{
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//float x = arg.GetNumber(0)
	//wxFont& _rtn = pThis->GetEntity()->Scale(x);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Font, __Scaled, "Scaled")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, __Scaled)
{
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//float x = arg.GetNumber(0)
	//wxFont _rtn = pThis->GetEntity()->Scaled(x);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Font, __SetEncoding, "SetEncoding")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, __SetEncoding)
{
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFontEncoding encoding = arg.GetNumber(0)
	//pThis->GetEntity()->SetEncoding(encoding);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Font, __SetFaceName, "SetFaceName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "faceName", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, __SetFaceName)
{
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& faceName = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->SetFaceName(faceName);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Font, __SetFamily, "SetFamily")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "family", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, __SetFamily)
{
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFontFamily family = arg.GetNumber(0)
	//pThis->GetEntity()->SetFamily(family);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Font, __SetNativeFontInfo, "SetNativeFontInfo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "info", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, __SetNativeFontInfo)
{
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& info = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->SetNativeFontInfo(info);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Font, __SetNativeFontInfoUserDesc, "SetNativeFontInfoUserDesc")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "info", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, __SetNativeFontInfoUserDesc)
{
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& info = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->SetNativeFontInfoUserDesc(info);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Font, __SetNativeFontInfo_1, "SetNativeFontInfo_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "info", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, __SetNativeFontInfo_1)
{
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxNativeFontInfo& info = arg.GetNumber(0)
	//pThis->GetEntity()->SetNativeFontInfo(info);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Font, __SetPointSize, "SetPointSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pointSize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, __SetPointSize)
{
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pointSize = arg.GetNumber(0)
	//pThis->GetEntity()->SetPointSize(pointSize);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Font, __SetPixelSize, "SetPixelSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pixelSize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, __SetPixelSize)
{
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxSize& pixelSize = arg.GetNumber(0)
	//pThis->GetEntity()->SetPixelSize(pixelSize);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Font, __SetStyle, "SetStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, __SetStyle)
{
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFontStyle style = arg.GetNumber(0)
	//pThis->GetEntity()->SetStyle(style);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Font, __SetSymbolicSize, "SetSymbolicSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, __SetSymbolicSize)
{
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFontSymbolicSize size = arg.GetNumber(0)
	//pThis->GetEntity()->SetSymbolicSize(size);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Font, __SetSymbolicSizeRelativeTo, "SetSymbolicSizeRelativeTo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "base", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, __SetSymbolicSizeRelativeTo)
{
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFontSymbolicSize size = arg.GetNumber(0)
	//int base = arg.GetNumber(1)
	//pThis->GetEntity()->SetSymbolicSizeRelativeTo(size, base);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Font, __SetUnderlined, "SetUnderlined")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "underlined", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, __SetUnderlined)
{
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool underlined = arg.GetNumber(0)
	//pThis->GetEntity()->SetUnderlined(underlined);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Font, __SetStrikethrough, "SetStrikethrough")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "strikethrough", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, __SetStrikethrough)
{
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool strikethrough = arg.GetNumber(0)
	//pThis->GetEntity()->SetStrikethrough(strikethrough);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Font, __SetWeight, "SetWeight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "weight", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, __SetWeight)
{
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFontWeight weight = arg.GetNumber(0)
	//pThis->GetEntity()->SetWeight(weight);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Font, __GetDefaultEncoding, "GetDefaultEncoding")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Font, __GetDefaultEncoding)
{
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFontEncoding _rtn = pThis->GetEntity()->GetDefaultEncoding();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Font, __SetDefaultEncoding, "SetDefaultEncoding")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, __SetDefaultEncoding)
{
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFontEncoding encoding = arg.GetNumber(0)
	//pThis->GetEntity()->SetDefaultEncoding(encoding);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Font, __New, "New")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pointSize", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "family", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "weight", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "underline", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "faceName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, __New)
{
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pointSize = arg.GetNumber(0)
	//wxFontFamily family = arg.GetNumber(1)
	//wxFontStyle style = arg.GetNumber(2)
	//wxFontWeight weight = arg.GetNumber(3)
	//bool underline = arg.GetNumber(4)
	//const wxString& faceName = arg.GetNumber(5)
	//wxFontEncoding encoding = arg.GetNumber(6)
	//wxFont* _rtn = pThis->GetEntity()->New(pointSize, family, style, weight, underline, faceName, encoding);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Font, __New_1, "New_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pointSize", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "family", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "faceName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, __New_1)
{
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pointSize = arg.GetNumber(0)
	//wxFontFamily family = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//const wxString& faceName = arg.GetNumber(3)
	//wxFontEncoding encoding = arg.GetNumber(4)
	//wxFont* _rtn = pThis->GetEntity()->New(pointSize, family, flags, faceName, encoding);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Font, __New_2, "New_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pixelSize", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "family", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "weight", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "underline", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "faceName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, __New_2)
{
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxSize& pixelSize = arg.GetNumber(0)
	//wxFontFamily family = arg.GetNumber(1)
	//wxFontStyle style = arg.GetNumber(2)
	//wxFontWeight weight = arg.GetNumber(3)
	//bool underline = arg.GetNumber(4)
	//const wxString& faceName = arg.GetNumber(5)
	//wxFontEncoding encoding = arg.GetNumber(6)
	//wxFont* _rtn = pThis->GetEntity()->New(pixelSize, family, style, weight, underline, faceName, encoding);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Font, __New_3, "New_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pixelSize", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "family", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "faceName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, __New_3)
{
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxSize& pixelSize = arg.GetNumber(0)
	//wxFontFamily family = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//const wxString& faceName = arg.GetNumber(3)
	//wxFontEncoding encoding = arg.GetNumber(4)
	//wxFont* _rtn = pThis->GetEntity()->New(pixelSize, family, flags, faceName, encoding);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Font, __New_4, "New_4")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "nativeInfo", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, __New_4)
{
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxNativeFontInfo& nativeInfo = arg.GetNumber(0)
	//wxFont* _rtn = pThis->GetEntity()->New(nativeInfo);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Font, __New_5, "New_5")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "nativeInfoString", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, __New_5)
{
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& nativeInfoString = arg.GetNumber(0)
	//wxFont* _rtn = pThis->GetEntity()->New(nativeInfoString);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFont
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Font)
{
	// Constructor assignment
	Gura_AssignFunction(__Font);
	Gura_AssignFunction(__Font_1);
	Gura_AssignFunction(__Font_2);
	Gura_AssignFunction(__Font_3);
	Gura_AssignFunction(__Font_4);
	Gura_AssignFunction(__Font_5);
	Gura_AssignFunction(__Font_6);
	// Method assignment
	Gura_AssignMethod(wx_Font, __GetBaseFont);
	Gura_AssignMethod(wx_Font, __GetEncoding);
	Gura_AssignMethod(wx_Font, __GetFaceName);
	Gura_AssignMethod(wx_Font, __GetFamily);
	Gura_AssignMethod(wx_Font, __GetNativeFontInfoDesc);
	Gura_AssignMethod(wx_Font, __GetNativeFontInfoUserDesc);
	Gura_AssignMethod(wx_Font, __GetNativeFontInfo);
	Gura_AssignMethod(wx_Font, __GetPointSize);
	Gura_AssignMethod(wx_Font, __GetPixelSize);
	Gura_AssignMethod(wx_Font, __GetStyle);
	Gura_AssignMethod(wx_Font, __GetUnderlined);
	Gura_AssignMethod(wx_Font, __GetStrikethrough);
	Gura_AssignMethod(wx_Font, __GetWeight);
	Gura_AssignMethod(wx_Font, __IsFixedWidth);
	Gura_AssignMethod(wx_Font, __IsOk);
	Gura_AssignMethod(wx_Font, __Bold);
	Gura_AssignMethod(wx_Font, __Italic);
	Gura_AssignMethod(wx_Font, __Larger);
	Gura_AssignMethod(wx_Font, __Smaller);
	Gura_AssignMethod(wx_Font, __Underlined);
	Gura_AssignMethod(wx_Font, __Strikethrough);
	Gura_AssignMethod(wx_Font, __MakeBold);
	Gura_AssignMethod(wx_Font, __MakeItalic);
	Gura_AssignMethod(wx_Font, __MakeLarger);
	Gura_AssignMethod(wx_Font, __MakeSmaller);
	Gura_AssignMethod(wx_Font, __MakeUnderlined);
	Gura_AssignMethod(wx_Font, __MakeStrikethrough);
	Gura_AssignMethod(wx_Font, __Scale);
	Gura_AssignMethod(wx_Font, __Scaled);
	Gura_AssignMethod(wx_Font, __SetEncoding);
	Gura_AssignMethod(wx_Font, __SetFaceName);
	Gura_AssignMethod(wx_Font, __SetFamily);
	Gura_AssignMethod(wx_Font, __SetNativeFontInfo);
	Gura_AssignMethod(wx_Font, __SetNativeFontInfoUserDesc);
	Gura_AssignMethod(wx_Font, __SetNativeFontInfo_1);
	Gura_AssignMethod(wx_Font, __SetPointSize);
	Gura_AssignMethod(wx_Font, __SetPixelSize);
	Gura_AssignMethod(wx_Font, __SetStyle);
	Gura_AssignMethod(wx_Font, __SetSymbolicSize);
	Gura_AssignMethod(wx_Font, __SetSymbolicSizeRelativeTo);
	Gura_AssignMethod(wx_Font, __SetUnderlined);
	Gura_AssignMethod(wx_Font, __SetStrikethrough);
	Gura_AssignMethod(wx_Font, __SetWeight);
	Gura_AssignMethod(wx_Font, __GetDefaultEncoding);
	Gura_AssignMethod(wx_Font, __SetDefaultEncoding);
	Gura_AssignMethod(wx_Font, __New);
	Gura_AssignMethod(wx_Font, __New_1);
	Gura_AssignMethod(wx_Font, __New_2);
	Gura_AssignMethod(wx_Font, __New_3);
	Gura_AssignMethod(wx_Font, __New_4);
	Gura_AssignMethod(wx_Font, __New_5);
}

Gura_ImplementDescendantCreator(wx_Font)
{
	return new Object_wx_Font((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
