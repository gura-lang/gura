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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_Font, wxFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Font, wxFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, wxFont_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, wxFont_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int font = arg.GetNumber(0)
	//pThis->GetEntity()->wxFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, wxFont_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, wxFont_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int font = arg.GetNumber(0)
	//pThis->GetEntity()->wxFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, wxFont_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pointSize", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "family", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "weight", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "underline", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "faceName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, wxFont_3)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pointSize = arg.GetNumber(0)
	//int family = arg.GetNumber(1)
	//int style = arg.GetNumber(2)
	//int weight = arg.GetNumber(3)
	//int underline = arg.GetNumber(4)
	//int faceName = arg.GetNumber(5)
	//int encoding = arg.GetNumber(6)
	//pThis->GetEntity()->wxFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, wxFont_4)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pixelSize", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "family", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "weight", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "underline", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "faceName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, wxFont_4)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pixelSize = arg.GetNumber(0)
	//int family = arg.GetNumber(1)
	//int style = arg.GetNumber(2)
	//int weight = arg.GetNumber(3)
	//int underline = arg.GetNumber(4)
	//int faceName = arg.GetNumber(5)
	//int encoding = arg.GetNumber(6)
	//pThis->GetEntity()->wxFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, wxFont_5)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nativeInfoString", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, wxFont_5)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int nativeInfoString = arg.GetNumber(0)
	//pThis->GetEntity()->wxFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, wxFont_6)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nativeInfo", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, wxFont_6)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int nativeInfo = arg.GetNumber(0)
	//pThis->GetEntity()->wxFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, ~wxFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Font, ~wxFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, GetBaseFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Font, GetBaseFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetBaseFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, GetEncoding)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Font, GetEncoding)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetEncoding();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, GetFaceName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Font, GetFaceName)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFaceName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, GetFamily)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Font, GetFamily)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFamily();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, GetNativeFontInfoDesc)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Font, GetNativeFontInfoDesc)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetNativeFontInfoDesc();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, GetNativeFontInfoUserDesc)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Font, GetNativeFontInfoUserDesc)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetNativeFontInfoUserDesc();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, GetNativeFontInfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Font, GetNativeFontInfo)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetNativeFontInfo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, GetPointSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Font, GetPointSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPointSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, GetPixelSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Font, GetPixelSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPixelSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, GetStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Font, GetStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, GetUnderlined)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Font, GetUnderlined)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetUnderlined();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, GetStrikethrough)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Font, GetStrikethrough)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetStrikethrough();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, GetWeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Font, GetWeight)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetWeight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, IsFixedWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Font, IsFixedWidth)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsFixedWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Font, IsOk)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, Bold)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Font, Bold)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Bold();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, Italic)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Font, Italic)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Italic();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, Larger)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Font, Larger)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Larger();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, Smaller)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Font, Smaller)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Smaller();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, Underlined)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Font, Underlined)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Underlined();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, Strikethrough)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Font, Strikethrough)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Strikethrough();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, MakeBold)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Font, MakeBold)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->MakeBold();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, MakeItalic)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Font, MakeItalic)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->MakeItalic();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, MakeLarger)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Font, MakeLarger)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->MakeLarger();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, MakeSmaller)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Font, MakeSmaller)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->MakeSmaller();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, MakeUnderlined)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Font, MakeUnderlined)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->MakeUnderlined();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, MakeStrikethrough)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Font, MakeStrikethrough)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->MakeStrikethrough();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, Scale)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, Scale)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//pThis->GetEntity()->Scale();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, Scaled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, Scaled)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//pThis->GetEntity()->Scaled();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, SetEncoding)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, SetEncoding)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int encoding = arg.GetNumber(0)
	//pThis->GetEntity()->SetEncoding();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, SetFaceName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "faceName", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, SetFaceName)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int faceName = arg.GetNumber(0)
	//pThis->GetEntity()->SetFaceName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, SetFamily)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "family", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, SetFamily)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int family = arg.GetNumber(0)
	//pThis->GetEntity()->SetFamily();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, SetNativeFontInfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "info", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, SetNativeFontInfo)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int info = arg.GetNumber(0)
	//pThis->GetEntity()->SetNativeFontInfo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, SetNativeFontInfoUserDesc)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "info", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, SetNativeFontInfoUserDesc)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int info = arg.GetNumber(0)
	//pThis->GetEntity()->SetNativeFontInfoUserDesc();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, SetNativeFontInfo_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "info", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, SetNativeFontInfo_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int info = arg.GetNumber(0)
	//pThis->GetEntity()->SetNativeFontInfo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, SetPointSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pointSize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, SetPointSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pointSize = arg.GetNumber(0)
	//pThis->GetEntity()->SetPointSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, SetPixelSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pixelSize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, SetPixelSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pixelSize = arg.GetNumber(0)
	//pThis->GetEntity()->SetPixelSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, SetStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, SetStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->SetStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, SetSymbolicSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, SetSymbolicSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->SetSymbolicSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, SetSymbolicSizeRelativeTo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "base", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, SetSymbolicSizeRelativeTo)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//int base = arg.GetNumber(1)
	//pThis->GetEntity()->SetSymbolicSizeRelativeTo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, SetUnderlined)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "underlined", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, SetUnderlined)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int underlined = arg.GetNumber(0)
	//pThis->GetEntity()->SetUnderlined();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, SetStrikethrough)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "strikethrough", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, SetStrikethrough)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int strikethrough = arg.GetNumber(0)
	//pThis->GetEntity()->SetStrikethrough();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, SetWeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "weight", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, SetWeight)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int weight = arg.GetNumber(0)
	//pThis->GetEntity()->SetWeight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, GetDefaultEncoding)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Font, GetDefaultEncoding)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetDefaultEncoding();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, SetDefaultEncoding)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, SetDefaultEncoding)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int encoding = arg.GetNumber(0)
	//pThis->GetEntity()->SetDefaultEncoding();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, New)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pointSize", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "family", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "weight", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "underline", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "faceName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, New)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pointSize = arg.GetNumber(0)
	//int family = arg.GetNumber(1)
	//int style = arg.GetNumber(2)
	//int weight = arg.GetNumber(3)
	//int underline = arg.GetNumber(4)
	//int faceName = arg.GetNumber(5)
	//int encoding = arg.GetNumber(6)
	//pThis->GetEntity()->New();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, New_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pointSize", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "family", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "faceName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, New_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pointSize = arg.GetNumber(0)
	//int family = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//int faceName = arg.GetNumber(3)
	//int encoding = arg.GetNumber(4)
	//pThis->GetEntity()->New();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, New_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pixelSize", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "family", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "weight", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "underline", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "faceName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, New_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pixelSize = arg.GetNumber(0)
	//int family = arg.GetNumber(1)
	//int style = arg.GetNumber(2)
	//int weight = arg.GetNumber(3)
	//int underline = arg.GetNumber(4)
	//int faceName = arg.GetNumber(5)
	//int encoding = arg.GetNumber(6)
	//pThis->GetEntity()->New();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, New_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pixelSize", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "family", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "faceName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, New_3)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pixelSize = arg.GetNumber(0)
	//int family = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//int faceName = arg.GetNumber(3)
	//int encoding = arg.GetNumber(4)
	//pThis->GetEntity()->New();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, New_4)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nativeInfo", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, New_4)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int nativeInfo = arg.GetNumber(0)
	//pThis->GetEntity()->New();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Font, New_5)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nativeInfoString", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Font, New_5)
{
	Signal &sig = env.GetSignal();
	Object_wx_Font *pThis = Object_wx_Font::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int nativeInfoString = arg.GetNumber(0)
	//pThis->GetEntity()->New();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFont
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Font)
{
	Gura_AssignMethod(wx_Font, wxFont);
	Gura_AssignMethod(wx_Font, wxFont_1);
	Gura_AssignMethod(wx_Font, wxFont_2);
	Gura_AssignMethod(wx_Font, wxFont_3);
	Gura_AssignMethod(wx_Font, wxFont_4);
	Gura_AssignMethod(wx_Font, wxFont_5);
	Gura_AssignMethod(wx_Font, wxFont_6);
	Gura_AssignMethod(wx_Font, ~wxFont);
	Gura_AssignMethod(wx_Font, GetBaseFont);
	Gura_AssignMethod(wx_Font, GetEncoding);
	Gura_AssignMethod(wx_Font, GetFaceName);
	Gura_AssignMethod(wx_Font, GetFamily);
	Gura_AssignMethod(wx_Font, GetNativeFontInfoDesc);
	Gura_AssignMethod(wx_Font, GetNativeFontInfoUserDesc);
	Gura_AssignMethod(wx_Font, GetNativeFontInfo);
	Gura_AssignMethod(wx_Font, GetPointSize);
	Gura_AssignMethod(wx_Font, GetPixelSize);
	Gura_AssignMethod(wx_Font, GetStyle);
	Gura_AssignMethod(wx_Font, GetUnderlined);
	Gura_AssignMethod(wx_Font, GetStrikethrough);
	Gura_AssignMethod(wx_Font, GetWeight);
	Gura_AssignMethod(wx_Font, IsFixedWidth);
	Gura_AssignMethod(wx_Font, IsOk);
	Gura_AssignMethod(wx_Font, Bold);
	Gura_AssignMethod(wx_Font, Italic);
	Gura_AssignMethod(wx_Font, Larger);
	Gura_AssignMethod(wx_Font, Smaller);
	Gura_AssignMethod(wx_Font, Underlined);
	Gura_AssignMethod(wx_Font, Strikethrough);
	Gura_AssignMethod(wx_Font, MakeBold);
	Gura_AssignMethod(wx_Font, MakeItalic);
	Gura_AssignMethod(wx_Font, MakeLarger);
	Gura_AssignMethod(wx_Font, MakeSmaller);
	Gura_AssignMethod(wx_Font, MakeUnderlined);
	Gura_AssignMethod(wx_Font, MakeStrikethrough);
	Gura_AssignMethod(wx_Font, Scale);
	Gura_AssignMethod(wx_Font, Scaled);
	Gura_AssignMethod(wx_Font, SetEncoding);
	Gura_AssignMethod(wx_Font, SetFaceName);
	Gura_AssignMethod(wx_Font, SetFamily);
	Gura_AssignMethod(wx_Font, SetNativeFontInfo);
	Gura_AssignMethod(wx_Font, SetNativeFontInfoUserDesc);
	Gura_AssignMethod(wx_Font, SetNativeFontInfo_1);
	Gura_AssignMethod(wx_Font, SetPointSize);
	Gura_AssignMethod(wx_Font, SetPixelSize);
	Gura_AssignMethod(wx_Font, SetStyle);
	Gura_AssignMethod(wx_Font, SetSymbolicSize);
	Gura_AssignMethod(wx_Font, SetSymbolicSizeRelativeTo);
	Gura_AssignMethod(wx_Font, SetUnderlined);
	Gura_AssignMethod(wx_Font, SetStrikethrough);
	Gura_AssignMethod(wx_Font, SetWeight);
	Gura_AssignMethod(wx_Font, GetDefaultEncoding);
	Gura_AssignMethod(wx_Font, SetDefaultEncoding);
	Gura_AssignMethod(wx_Font, New);
	Gura_AssignMethod(wx_Font, New_1);
	Gura_AssignMethod(wx_Font, New_2);
	Gura_AssignMethod(wx_Font, New_3);
	Gura_AssignMethod(wx_Font, New_4);
	Gura_AssignMethod(wx_Font, New_5);
}

Gura_ImplementDescendantCreator(wx_Font)
{
	return new Object_wx_Font((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
