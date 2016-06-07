//----------------------------------------------------------------------------
// wxTextAttr
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTextAttr
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTextAttr
//----------------------------------------------------------------------------
Object_wx_TextAttr::~Object_wx_TextAttr()
{
}

Object *Object_wx_TextAttr::Clone() const
{
	return nullptr;
}

String Object_wx_TextAttr::ToString(bool exprFlag)
{
	String rtn("<wx.TextAttr:");
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
Gura_DeclareFunctionAlias(__TextAttr, "TextAttr")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_TextAttr));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__TextAttr)
{
	//wxTextAttr();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__TextAttr_1, "TextAttr_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "colText", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "colBack", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "alignment", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_TextAttr));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__TextAttr_1)
{
	//const wxColour& colText = arg.GetNumber(0)
	//const wxColour& colBack = arg.GetNumber(1)
	//const wxFont& font = arg.GetNumber(2)
	//wxTextAttrAlignment alignment = arg.GetNumber(3)
	//wxTextAttr(colText, colBack, font, alignment);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__TextAttr_2, "TextAttr_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_TextAttr));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__TextAttr_2)
{
	//const wxTextAttr& attr = arg.GetNumber(0)
	//wxTextAttr(attr);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_TextAttr, __Apply, "Apply")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "compareWith", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, __Apply)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTextAttr& style = arg.GetNumber(0)
	//const wxTextAttr* compareWith = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->Apply(style, compareWith);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __Merge, "Merge")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "overlay", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, __Merge)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTextAttr& overlay = arg.GetNumber(0)
	//pThis->GetEntity()->Merge(overlay);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __Merge_1, "Merge_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "base", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "overlay", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, __Merge_1)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTextAttr& base = arg.GetNumber(0)
	//const wxTextAttr& overlay = arg.GetNumber(1)
	//wxTextAttr _rtn = pThis->GetEntity()->Merge(base, overlay);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __EqPartial, "EqPartial")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "weakTest", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, __EqPartial)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTextAttr& attr = arg.GetNumber(0)
	//bool weakTest = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->EqPartial(attr, weakTest);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __GetAlignment, "GetAlignment")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __GetAlignment)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxTextAttrAlignment _rtn = pThis->GetEntity()->GetAlignment();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __GetBackgroundColour, "GetBackgroundColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __GetBackgroundColour)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& _rtn = pThis->GetEntity()->GetBackgroundColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __GetBulletFont, "GetBulletFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __GetBulletFont)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& _rtn = pThis->GetEntity()->GetBulletFont();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __GetBulletName, "GetBulletName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __GetBulletName)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& _rtn = pThis->GetEntity()->GetBulletName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __GetBulletNumber, "GetBulletNumber")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __GetBulletNumber)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetBulletNumber();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __GetBulletStyle, "GetBulletStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __GetBulletStyle)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetBulletStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __GetBulletText, "GetBulletText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __GetBulletText)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& _rtn = pThis->GetEntity()->GetBulletText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __GetCharacterStyleName, "GetCharacterStyleName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __GetCharacterStyleName)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& _rtn = pThis->GetEntity()->GetCharacterStyleName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __GetFlags, "GetFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __GetFlags)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long _rtn = pThis->GetEntity()->GetFlags();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __GetFont, "GetFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __GetFont)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFont _rtn = pThis->GetEntity()->GetFont();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __GetFontAttributes, "GetFontAttributes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, __GetFontAttributes)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxFont& font = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->GetFontAttributes(font, flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __GetFontEncoding, "GetFontEncoding")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __GetFontEncoding)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFontEncoding _rtn = pThis->GetEntity()->GetFontEncoding();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __GetFontFaceName, "GetFontFaceName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __GetFontFaceName)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& _rtn = pThis->GetEntity()->GetFontFaceName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __GetFontFamily, "GetFontFamily")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __GetFontFamily)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFontFamily _rtn = pThis->GetEntity()->GetFontFamily();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __GetFontSize, "GetFontSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __GetFontSize)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetFontSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __GetFontStyle, "GetFontStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __GetFontStyle)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFontStyle _rtn = pThis->GetEntity()->GetFontStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __GetFontUnderlined, "GetFontUnderlined")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __GetFontUnderlined)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->GetFontUnderlined();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __GetFontWeight, "GetFontWeight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __GetFontWeight)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFontWeight _rtn = pThis->GetEntity()->GetFontWeight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __GetLeftIndent, "GetLeftIndent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __GetLeftIndent)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long _rtn = pThis->GetEntity()->GetLeftIndent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __GetLeftSubIndent, "GetLeftSubIndent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __GetLeftSubIndent)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long _rtn = pThis->GetEntity()->GetLeftSubIndent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __GetLineSpacing, "GetLineSpacing")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __GetLineSpacing)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetLineSpacing();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __GetListStyleName, "GetListStyleName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __GetListStyleName)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& _rtn = pThis->GetEntity()->GetListStyleName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __GetOutlineLevel, "GetOutlineLevel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __GetOutlineLevel)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetOutlineLevel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __GetParagraphSpacingAfter, "GetParagraphSpacingAfter")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __GetParagraphSpacingAfter)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetParagraphSpacingAfter();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __GetParagraphSpacingBefore, "GetParagraphSpacingBefore")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __GetParagraphSpacingBefore)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetParagraphSpacingBefore();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __GetParagraphStyleName, "GetParagraphStyleName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __GetParagraphStyleName)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& _rtn = pThis->GetEntity()->GetParagraphStyleName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __GetRightIndent, "GetRightIndent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __GetRightIndent)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long _rtn = pThis->GetEntity()->GetRightIndent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __GetTabs, "GetTabs")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __GetTabs)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxArrayInt& _rtn = pThis->GetEntity()->GetTabs();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __GetTextColour, "GetTextColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __GetTextColour)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& _rtn = pThis->GetEntity()->GetTextColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __GetTextEffectFlags, "GetTextEffectFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __GetTextEffectFlags)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetTextEffectFlags();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __GetTextEffects, "GetTextEffects")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __GetTextEffects)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetTextEffects();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __GetURL, "GetURL")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __GetURL)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& _rtn = pThis->GetEntity()->GetURL();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __HasAlignment, "HasAlignment")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __HasAlignment)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasAlignment();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __HasBackgroundColour, "HasBackgroundColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __HasBackgroundColour)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasBackgroundColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __HasBulletName, "HasBulletName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __HasBulletName)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasBulletName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __HasBulletNumber, "HasBulletNumber")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __HasBulletNumber)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasBulletNumber();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __HasBulletStyle, "HasBulletStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __HasBulletStyle)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasBulletStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __HasBulletText, "HasBulletText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __HasBulletText)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasBulletText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __HasCharacterStyleName, "HasCharacterStyleName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __HasCharacterStyleName)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasCharacterStyleName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __HasFlag, "HasFlag")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, __HasFlag)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long flag = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->HasFlag(flag);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __HasFont, "HasFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __HasFont)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasFont();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __HasFontEncoding, "HasFontEncoding")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __HasFontEncoding)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasFontEncoding();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __HasFontFaceName, "HasFontFaceName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __HasFontFaceName)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasFontFaceName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __HasFontFamily, "HasFontFamily")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __HasFontFamily)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasFontFamily();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __HasFontItalic, "HasFontItalic")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __HasFontItalic)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasFontItalic();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __HasFontSize, "HasFontSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __HasFontSize)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasFontSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __HasFontPointSize, "HasFontPointSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __HasFontPointSize)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasFontPointSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __HasFontPixelSize, "HasFontPixelSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __HasFontPixelSize)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasFontPixelSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __HasFontUnderlined, "HasFontUnderlined")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __HasFontUnderlined)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasFontUnderlined();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __HasFontWeight, "HasFontWeight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __HasFontWeight)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasFontWeight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __HasLeftIndent, "HasLeftIndent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __HasLeftIndent)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasLeftIndent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __HasLineSpacing, "HasLineSpacing")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __HasLineSpacing)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasLineSpacing();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __HasListStyleName, "HasListStyleName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __HasListStyleName)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasListStyleName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __HasOutlineLevel, "HasOutlineLevel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __HasOutlineLevel)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasOutlineLevel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __HasPageBreak, "HasPageBreak")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __HasPageBreak)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasPageBreak();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __HasParagraphSpacingAfter, "HasParagraphSpacingAfter")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __HasParagraphSpacingAfter)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasParagraphSpacingAfter();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __HasParagraphSpacingBefore, "HasParagraphSpacingBefore")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __HasParagraphSpacingBefore)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasParagraphSpacingBefore();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __HasParagraphStyleName, "HasParagraphStyleName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __HasParagraphStyleName)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasParagraphStyleName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __HasRightIndent, "HasRightIndent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __HasRightIndent)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasRightIndent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __HasTabs, "HasTabs")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __HasTabs)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasTabs();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __HasTextColour, "HasTextColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __HasTextColour)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasTextColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __HasTextEffects, "HasTextEffects")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __HasTextEffects)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasTextEffects();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __HasURL, "HasURL")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __HasURL)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasURL();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __IsCharacterStyle, "IsCharacterStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __IsCharacterStyle)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsCharacterStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __IsDefault, "IsDefault")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __IsDefault)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsDefault();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __IsParagraphStyle, "IsParagraphStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, __IsParagraphStyle)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsParagraphStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __SetAlignment, "SetAlignment")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "alignment", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, __SetAlignment)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxTextAttrAlignment alignment = arg.GetNumber(0)
	//pThis->GetEntity()->SetAlignment(alignment);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __SetBackgroundColour, "SetBackgroundColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colBack", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, __SetBackgroundColour)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& colBack = arg.GetNumber(0)
	//pThis->GetEntity()->SetBackgroundColour(colBack);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __SetBulletFont, "SetBulletFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, __SetBulletFont)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& font = arg.GetNumber(0)
	//pThis->GetEntity()->SetBulletFont(font);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __SetBulletName, "SetBulletName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, __SetBulletName)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//pThis->GetEntity()->SetBulletName(name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __SetBulletNumber, "SetBulletNumber")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, __SetBulletNumber)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->SetBulletNumber(n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __SetBulletStyle, "SetBulletStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, __SetBulletStyle)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->SetBulletStyle(style);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __SetBulletText, "SetBulletText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, __SetBulletText)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& text = arg.GetNumber(0)
	//pThis->GetEntity()->SetBulletText(text);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __SetCharacterStyleName, "SetCharacterStyleName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, __SetCharacterStyleName)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//pThis->GetEntity()->SetCharacterStyleName(name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __SetFlags, "SetFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, __SetFlags)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long flags = arg.GetNumber(0)
	//pThis->GetEntity()->SetFlags(flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __SetFont, "SetFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, __SetFont)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxFont& font = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->SetFont(font, flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __SetFontEncoding, "SetFontEncoding")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, __SetFontEncoding)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFontEncoding encoding = arg.GetNumber(0)
	//pThis->GetEntity()->SetFontEncoding(encoding);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __SetFontFaceName, "SetFontFaceName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "faceName", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, __SetFontFaceName)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& faceName = arg.GetNumber(0)
	//pThis->GetEntity()->SetFontFaceName(faceName);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __SetFontFamily, "SetFontFamily")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "family", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, __SetFontFamily)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFontFamily family = arg.GetNumber(0)
	//pThis->GetEntity()->SetFontFamily(family);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __SetFontSize, "SetFontSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pointSize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, __SetFontSize)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pointSize = arg.GetNumber(0)
	//pThis->GetEntity()->SetFontSize(pointSize);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __SetFontPointSize, "SetFontPointSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pointSize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, __SetFontPointSize)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pointSize = arg.GetNumber(0)
	//pThis->GetEntity()->SetFontPointSize(pointSize);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __SetFontPixelSize, "SetFontPixelSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pixelSize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, __SetFontPixelSize)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pixelSize = arg.GetNumber(0)
	//pThis->GetEntity()->SetFontPixelSize(pixelSize);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __SetFontStyle, "SetFontStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fontStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, __SetFontStyle)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFontStyle fontStyle = arg.GetNumber(0)
	//pThis->GetEntity()->SetFontStyle(fontStyle);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __SetFontUnderlined, "SetFontUnderlined")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "underlined", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, __SetFontUnderlined)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool underlined = arg.GetNumber(0)
	//pThis->GetEntity()->SetFontUnderlined(underlined);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __SetFontWeight, "SetFontWeight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fontWeight", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, __SetFontWeight)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFontWeight fontWeight = arg.GetNumber(0)
	//pThis->GetEntity()->SetFontWeight(fontWeight);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __SetLeftIndent, "SetLeftIndent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "indent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "subIndent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, __SetLeftIndent)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int indent = arg.GetNumber(0)
	//int subIndent = arg.GetNumber(1)
	//pThis->GetEntity()->SetLeftIndent(indent, subIndent);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __SetLineSpacing, "SetLineSpacing")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "spacing", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, __SetLineSpacing)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int spacing = arg.GetNumber(0)
	//pThis->GetEntity()->SetLineSpacing(spacing);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __SetListStyleName, "SetListStyleName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, __SetListStyleName)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//pThis->GetEntity()->SetListStyleName(name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __SetOutlineLevel, "SetOutlineLevel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, __SetOutlineLevel)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int level = arg.GetNumber(0)
	//pThis->GetEntity()->SetOutlineLevel(level);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __SetPageBreak, "SetPageBreak")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pageBreak", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, __SetPageBreak)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool pageBreak = arg.GetNumber(0)
	//pThis->GetEntity()->SetPageBreak(pageBreak);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __SetParagraphSpacingAfter, "SetParagraphSpacingAfter")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "spacing", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, __SetParagraphSpacingAfter)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int spacing = arg.GetNumber(0)
	//pThis->GetEntity()->SetParagraphSpacingAfter(spacing);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __SetParagraphSpacingBefore, "SetParagraphSpacingBefore")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "spacing", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, __SetParagraphSpacingBefore)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int spacing = arg.GetNumber(0)
	//pThis->GetEntity()->SetParagraphSpacingBefore(spacing);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __SetParagraphStyleName, "SetParagraphStyleName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, __SetParagraphStyleName)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//pThis->GetEntity()->SetParagraphStyleName(name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __SetRightIndent, "SetRightIndent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "indent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, __SetRightIndent)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int indent = arg.GetNumber(0)
	//pThis->GetEntity()->SetRightIndent(indent);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __SetTabs, "SetTabs")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tabs", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, __SetTabs)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxArrayInt& tabs = arg.GetNumber(0)
	//pThis->GetEntity()->SetTabs(tabs);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __SetTextColour, "SetTextColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colText", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, __SetTextColour)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& colText = arg.GetNumber(0)
	//pThis->GetEntity()->SetTextColour(colText);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __SetTextEffectFlags, "SetTextEffectFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, __SetTextEffectFlags)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->SetTextEffectFlags(flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __SetTextEffects, "SetTextEffects")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "effects", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, __SetTextEffects)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int effects = arg.GetNumber(0)
	//pThis->GetEntity()->SetTextEffects(effects);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextAttr, __SetURL, "SetURL")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "url", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, __SetURL)
{
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& url = arg.GetNumber(0)
	//pThis->GetEntity()->SetURL(url);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTextAttr
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextAttr)
{
	// Constructor assignment
	Gura_AssignFunction(__TextAttr);
	Gura_AssignFunction(__TextAttr_1);
	Gura_AssignFunction(__TextAttr_2);
	// Method assignment
	Gura_AssignMethod(wx_TextAttr, __Apply);
	Gura_AssignMethod(wx_TextAttr, __Merge);
	Gura_AssignMethod(wx_TextAttr, __Merge_1);
	Gura_AssignMethod(wx_TextAttr, __EqPartial);
	Gura_AssignMethod(wx_TextAttr, __GetAlignment);
	Gura_AssignMethod(wx_TextAttr, __GetBackgroundColour);
	Gura_AssignMethod(wx_TextAttr, __GetBulletFont);
	Gura_AssignMethod(wx_TextAttr, __GetBulletName);
	Gura_AssignMethod(wx_TextAttr, __GetBulletNumber);
	Gura_AssignMethod(wx_TextAttr, __GetBulletStyle);
	Gura_AssignMethod(wx_TextAttr, __GetBulletText);
	Gura_AssignMethod(wx_TextAttr, __GetCharacterStyleName);
	Gura_AssignMethod(wx_TextAttr, __GetFlags);
	Gura_AssignMethod(wx_TextAttr, __GetFont);
	Gura_AssignMethod(wx_TextAttr, __GetFontAttributes);
	Gura_AssignMethod(wx_TextAttr, __GetFontEncoding);
	Gura_AssignMethod(wx_TextAttr, __GetFontFaceName);
	Gura_AssignMethod(wx_TextAttr, __GetFontFamily);
	Gura_AssignMethod(wx_TextAttr, __GetFontSize);
	Gura_AssignMethod(wx_TextAttr, __GetFontStyle);
	Gura_AssignMethod(wx_TextAttr, __GetFontUnderlined);
	Gura_AssignMethod(wx_TextAttr, __GetFontWeight);
	Gura_AssignMethod(wx_TextAttr, __GetLeftIndent);
	Gura_AssignMethod(wx_TextAttr, __GetLeftSubIndent);
	Gura_AssignMethod(wx_TextAttr, __GetLineSpacing);
	Gura_AssignMethod(wx_TextAttr, __GetListStyleName);
	Gura_AssignMethod(wx_TextAttr, __GetOutlineLevel);
	Gura_AssignMethod(wx_TextAttr, __GetParagraphSpacingAfter);
	Gura_AssignMethod(wx_TextAttr, __GetParagraphSpacingBefore);
	Gura_AssignMethod(wx_TextAttr, __GetParagraphStyleName);
	Gura_AssignMethod(wx_TextAttr, __GetRightIndent);
	Gura_AssignMethod(wx_TextAttr, __GetTabs);
	Gura_AssignMethod(wx_TextAttr, __GetTextColour);
	Gura_AssignMethod(wx_TextAttr, __GetTextEffectFlags);
	Gura_AssignMethod(wx_TextAttr, __GetTextEffects);
	Gura_AssignMethod(wx_TextAttr, __GetURL);
	Gura_AssignMethod(wx_TextAttr, __HasAlignment);
	Gura_AssignMethod(wx_TextAttr, __HasBackgroundColour);
	Gura_AssignMethod(wx_TextAttr, __HasBulletName);
	Gura_AssignMethod(wx_TextAttr, __HasBulletNumber);
	Gura_AssignMethod(wx_TextAttr, __HasBulletStyle);
	Gura_AssignMethod(wx_TextAttr, __HasBulletText);
	Gura_AssignMethod(wx_TextAttr, __HasCharacterStyleName);
	Gura_AssignMethod(wx_TextAttr, __HasFlag);
	Gura_AssignMethod(wx_TextAttr, __HasFont);
	Gura_AssignMethod(wx_TextAttr, __HasFontEncoding);
	Gura_AssignMethod(wx_TextAttr, __HasFontFaceName);
	Gura_AssignMethod(wx_TextAttr, __HasFontFamily);
	Gura_AssignMethod(wx_TextAttr, __HasFontItalic);
	Gura_AssignMethod(wx_TextAttr, __HasFontSize);
	Gura_AssignMethod(wx_TextAttr, __HasFontPointSize);
	Gura_AssignMethod(wx_TextAttr, __HasFontPixelSize);
	Gura_AssignMethod(wx_TextAttr, __HasFontUnderlined);
	Gura_AssignMethod(wx_TextAttr, __HasFontWeight);
	Gura_AssignMethod(wx_TextAttr, __HasLeftIndent);
	Gura_AssignMethod(wx_TextAttr, __HasLineSpacing);
	Gura_AssignMethod(wx_TextAttr, __HasListStyleName);
	Gura_AssignMethod(wx_TextAttr, __HasOutlineLevel);
	Gura_AssignMethod(wx_TextAttr, __HasPageBreak);
	Gura_AssignMethod(wx_TextAttr, __HasParagraphSpacingAfter);
	Gura_AssignMethod(wx_TextAttr, __HasParagraphSpacingBefore);
	Gura_AssignMethod(wx_TextAttr, __HasParagraphStyleName);
	Gura_AssignMethod(wx_TextAttr, __HasRightIndent);
	Gura_AssignMethod(wx_TextAttr, __HasTabs);
	Gura_AssignMethod(wx_TextAttr, __HasTextColour);
	Gura_AssignMethod(wx_TextAttr, __HasTextEffects);
	Gura_AssignMethod(wx_TextAttr, __HasURL);
	Gura_AssignMethod(wx_TextAttr, __IsCharacterStyle);
	Gura_AssignMethod(wx_TextAttr, __IsDefault);
	Gura_AssignMethod(wx_TextAttr, __IsParagraphStyle);
	Gura_AssignMethod(wx_TextAttr, __SetAlignment);
	Gura_AssignMethod(wx_TextAttr, __SetBackgroundColour);
	Gura_AssignMethod(wx_TextAttr, __SetBulletFont);
	Gura_AssignMethod(wx_TextAttr, __SetBulletName);
	Gura_AssignMethod(wx_TextAttr, __SetBulletNumber);
	Gura_AssignMethod(wx_TextAttr, __SetBulletStyle);
	Gura_AssignMethod(wx_TextAttr, __SetBulletText);
	Gura_AssignMethod(wx_TextAttr, __SetCharacterStyleName);
	Gura_AssignMethod(wx_TextAttr, __SetFlags);
	Gura_AssignMethod(wx_TextAttr, __SetFont);
	Gura_AssignMethod(wx_TextAttr, __SetFontEncoding);
	Gura_AssignMethod(wx_TextAttr, __SetFontFaceName);
	Gura_AssignMethod(wx_TextAttr, __SetFontFamily);
	Gura_AssignMethod(wx_TextAttr, __SetFontSize);
	Gura_AssignMethod(wx_TextAttr, __SetFontPointSize);
	Gura_AssignMethod(wx_TextAttr, __SetFontPixelSize);
	Gura_AssignMethod(wx_TextAttr, __SetFontStyle);
	Gura_AssignMethod(wx_TextAttr, __SetFontUnderlined);
	Gura_AssignMethod(wx_TextAttr, __SetFontWeight);
	Gura_AssignMethod(wx_TextAttr, __SetLeftIndent);
	Gura_AssignMethod(wx_TextAttr, __SetLineSpacing);
	Gura_AssignMethod(wx_TextAttr, __SetListStyleName);
	Gura_AssignMethod(wx_TextAttr, __SetOutlineLevel);
	Gura_AssignMethod(wx_TextAttr, __SetPageBreak);
	Gura_AssignMethod(wx_TextAttr, __SetParagraphSpacingAfter);
	Gura_AssignMethod(wx_TextAttr, __SetParagraphSpacingBefore);
	Gura_AssignMethod(wx_TextAttr, __SetParagraphStyleName);
	Gura_AssignMethod(wx_TextAttr, __SetRightIndent);
	Gura_AssignMethod(wx_TextAttr, __SetTabs);
	Gura_AssignMethod(wx_TextAttr, __SetTextColour);
	Gura_AssignMethod(wx_TextAttr, __SetTextEffectFlags);
	Gura_AssignMethod(wx_TextAttr, __SetTextEffects);
	Gura_AssignMethod(wx_TextAttr, __SetURL);
}

Gura_ImplementDescendantCreator(wx_TextAttr)
{
	return new Object_wx_TextAttr((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
