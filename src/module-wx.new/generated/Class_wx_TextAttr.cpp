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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_TextAttr, wxTextAttr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, wxTextAttr)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxTextAttr();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, wxTextAttr_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colText", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "colBack", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "alignment", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, wxTextAttr_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int colText = arg.GetNumber(0)
	//int colBack = arg.GetNumber(1)
	//int font = arg.GetNumber(2)
	//int alignment = arg.GetNumber(3)
	//pThis->GetEntity()->wxTextAttr();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, wxTextAttr_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, wxTextAttr_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int attr = arg.GetNumber(0)
	//pThis->GetEntity()->wxTextAttr();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, Apply)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "compareWith", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, Apply)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//int compareWith = arg.GetNumber(1)
	//pThis->GetEntity()->Apply();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, Merge)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "overlay", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, Merge)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int overlay = arg.GetNumber(0)
	//pThis->GetEntity()->Merge();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, Merge_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "base", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "overlay", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, Merge_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int base = arg.GetNumber(0)
	//int overlay = arg.GetNumber(1)
	//pThis->GetEntity()->Merge();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, EqPartial)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "weakTest", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, EqPartial)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int attr = arg.GetNumber(0)
	//int weakTest = arg.GetNumber(1)
	//pThis->GetEntity()->EqPartial();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, GetAlignment)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, GetAlignment)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetAlignment();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, GetBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, GetBackgroundColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetBackgroundColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, GetBulletFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, GetBulletFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetBulletFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, GetBulletName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, GetBulletName)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetBulletName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, GetBulletNumber)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, GetBulletNumber)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetBulletNumber();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, GetBulletStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, GetBulletStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetBulletStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, GetBulletText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, GetBulletText)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetBulletText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, GetCharacterStyleName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, GetCharacterStyleName)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetCharacterStyleName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, GetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, GetFlags)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, GetFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, GetFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, GetFontAttributes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, GetFontAttributes)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int font = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->GetFontAttributes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, GetFontEncoding)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, GetFontEncoding)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFontEncoding();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, GetFontFaceName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, GetFontFaceName)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFontFaceName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, GetFontFamily)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, GetFontFamily)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFontFamily();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, GetFontSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, GetFontSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFontSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, GetFontStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, GetFontStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFontStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, GetFontUnderlined)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, GetFontUnderlined)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFontUnderlined();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, GetFontWeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, GetFontWeight)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFontWeight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, GetLeftIndent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, GetLeftIndent)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetLeftIndent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, GetLeftSubIndent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, GetLeftSubIndent)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetLeftSubIndent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, GetLineSpacing)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, GetLineSpacing)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetLineSpacing();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, GetListStyleName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, GetListStyleName)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetListStyleName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, GetOutlineLevel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, GetOutlineLevel)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetOutlineLevel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, GetParagraphSpacingAfter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, GetParagraphSpacingAfter)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetParagraphSpacingAfter();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, GetParagraphSpacingBefore)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, GetParagraphSpacingBefore)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetParagraphSpacingBefore();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, GetParagraphStyleName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, GetParagraphStyleName)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetParagraphStyleName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, GetRightIndent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, GetRightIndent)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetRightIndent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, GetTabs)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, GetTabs)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetTabs();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, GetTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, GetTextColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetTextColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, GetTextEffectFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, GetTextEffectFlags)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetTextEffectFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, GetTextEffects)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, GetTextEffects)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetTextEffects();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, GetURL)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, GetURL)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetURL();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, HasAlignment)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, HasAlignment)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasAlignment();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, HasBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, HasBackgroundColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasBackgroundColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, HasBulletName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, HasBulletName)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasBulletName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, HasBulletNumber)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, HasBulletNumber)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasBulletNumber();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, HasBulletStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, HasBulletStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasBulletStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, HasBulletText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, HasBulletText)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasBulletText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, HasCharacterStyleName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, HasCharacterStyleName)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasCharacterStyleName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, HasFlag)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, HasFlag)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->HasFlag();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, HasFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, HasFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, HasFontEncoding)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, HasFontEncoding)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasFontEncoding();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, HasFontFaceName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, HasFontFaceName)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasFontFaceName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, HasFontFamily)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, HasFontFamily)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasFontFamily();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, HasFontItalic)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, HasFontItalic)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasFontItalic();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, HasFontSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, HasFontSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasFontSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, HasFontPointSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, HasFontPointSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasFontPointSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, HasFontPixelSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, HasFontPixelSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasFontPixelSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, HasFontUnderlined)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, HasFontUnderlined)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasFontUnderlined();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, HasFontWeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, HasFontWeight)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasFontWeight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, HasLeftIndent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, HasLeftIndent)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasLeftIndent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, HasLineSpacing)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, HasLineSpacing)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasLineSpacing();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, HasListStyleName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, HasListStyleName)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasListStyleName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, HasOutlineLevel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, HasOutlineLevel)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasOutlineLevel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, HasPageBreak)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, HasPageBreak)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasPageBreak();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, HasParagraphSpacingAfter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, HasParagraphSpacingAfter)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasParagraphSpacingAfter();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, HasParagraphSpacingBefore)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, HasParagraphSpacingBefore)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasParagraphSpacingBefore();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, HasParagraphStyleName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, HasParagraphStyleName)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasParagraphStyleName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, HasRightIndent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, HasRightIndent)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasRightIndent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, HasTabs)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, HasTabs)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasTabs();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, HasTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, HasTextColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasTextColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, HasTextEffects)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, HasTextEffects)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasTextEffects();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, HasURL)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, HasURL)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasURL();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, IsCharacterStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, IsCharacterStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsCharacterStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, IsDefault)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, IsDefault)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsDefault();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, IsParagraphStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextAttr, IsParagraphStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsParagraphStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, SetAlignment)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "alignment", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, SetAlignment)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int alignment = arg.GetNumber(0)
	//pThis->GetEntity()->SetAlignment();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, SetBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colBack", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, SetBackgroundColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int colBack = arg.GetNumber(0)
	//pThis->GetEntity()->SetBackgroundColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, SetBulletFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, SetBulletFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int font = arg.GetNumber(0)
	//pThis->GetEntity()->SetBulletFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, SetBulletName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, SetBulletName)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->SetBulletName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, SetBulletNumber)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, SetBulletNumber)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->SetBulletNumber();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, SetBulletStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, SetBulletStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->SetBulletStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, SetBulletText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, SetBulletText)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//pThis->GetEntity()->SetBulletText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, SetCharacterStyleName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, SetCharacterStyleName)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->SetCharacterStyleName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, SetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, SetFlags)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->SetFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, SetFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, SetFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int font = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->SetFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, SetFontEncoding)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "encoding", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, SetFontEncoding)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int encoding = arg.GetNumber(0)
	//pThis->GetEntity()->SetFontEncoding();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, SetFontFaceName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "faceName", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, SetFontFaceName)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int faceName = arg.GetNumber(0)
	//pThis->GetEntity()->SetFontFaceName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, SetFontFamily)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "family", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, SetFontFamily)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int family = arg.GetNumber(0)
	//pThis->GetEntity()->SetFontFamily();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, SetFontSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pointSize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, SetFontSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pointSize = arg.GetNumber(0)
	//pThis->GetEntity()->SetFontSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, SetFontPointSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pointSize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, SetFontPointSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pointSize = arg.GetNumber(0)
	//pThis->GetEntity()->SetFontPointSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, SetFontPixelSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pixelSize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, SetFontPixelSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pixelSize = arg.GetNumber(0)
	//pThis->GetEntity()->SetFontPixelSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, SetFontStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fontStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, SetFontStyle)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int fontStyle = arg.GetNumber(0)
	//pThis->GetEntity()->SetFontStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, SetFontUnderlined)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "underlined", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, SetFontUnderlined)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int underlined = arg.GetNumber(0)
	//pThis->GetEntity()->SetFontUnderlined();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, SetFontWeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fontWeight", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, SetFontWeight)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int fontWeight = arg.GetNumber(0)
	//pThis->GetEntity()->SetFontWeight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, SetLeftIndent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "indent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "subIndent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, SetLeftIndent)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int indent = arg.GetNumber(0)
	//int subIndent = arg.GetNumber(1)
	//pThis->GetEntity()->SetLeftIndent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, SetLineSpacing)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "spacing", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, SetLineSpacing)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int spacing = arg.GetNumber(0)
	//pThis->GetEntity()->SetLineSpacing();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, SetListStyleName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, SetListStyleName)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->SetListStyleName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, SetOutlineLevel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, SetOutlineLevel)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int level = arg.GetNumber(0)
	//pThis->GetEntity()->SetOutlineLevel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, SetPageBreak)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pageBreak", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, SetPageBreak)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pageBreak = arg.GetNumber(0)
	//pThis->GetEntity()->SetPageBreak();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, SetParagraphSpacingAfter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "spacing", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, SetParagraphSpacingAfter)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int spacing = arg.GetNumber(0)
	//pThis->GetEntity()->SetParagraphSpacingAfter();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, SetParagraphSpacingBefore)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "spacing", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, SetParagraphSpacingBefore)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int spacing = arg.GetNumber(0)
	//pThis->GetEntity()->SetParagraphSpacingBefore();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, SetParagraphStyleName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, SetParagraphStyleName)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->SetParagraphStyleName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, SetRightIndent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "indent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, SetRightIndent)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int indent = arg.GetNumber(0)
	//pThis->GetEntity()->SetRightIndent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, SetTabs)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tabs", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, SetTabs)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int tabs = arg.GetNumber(0)
	//pThis->GetEntity()->SetTabs();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, SetTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colText", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, SetTextColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int colText = arg.GetNumber(0)
	//pThis->GetEntity()->SetTextColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, SetTextEffectFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, SetTextEffectFlags)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->SetTextEffectFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, SetTextEffects)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "effects", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, SetTextEffects)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int effects = arg.GetNumber(0)
	//pThis->GetEntity()->SetTextEffects();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextAttr, SetURL)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "url", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextAttr, SetURL)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextAttr *pThis = Object_wx_TextAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int url = arg.GetNumber(0)
	//pThis->GetEntity()->SetURL();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTextAttr
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextAttr)
{
	Gura_AssignMethod(wx_TextAttr, wxTextAttr);
	Gura_AssignMethod(wx_TextAttr, wxTextAttr_1);
	Gura_AssignMethod(wx_TextAttr, wxTextAttr_2);
	Gura_AssignMethod(wx_TextAttr, Apply);
	Gura_AssignMethod(wx_TextAttr, Merge);
	Gura_AssignMethod(wx_TextAttr, Merge_1);
	Gura_AssignMethod(wx_TextAttr, EqPartial);
	Gura_AssignMethod(wx_TextAttr, GetAlignment);
	Gura_AssignMethod(wx_TextAttr, GetBackgroundColour);
	Gura_AssignMethod(wx_TextAttr, GetBulletFont);
	Gura_AssignMethod(wx_TextAttr, GetBulletName);
	Gura_AssignMethod(wx_TextAttr, GetBulletNumber);
	Gura_AssignMethod(wx_TextAttr, GetBulletStyle);
	Gura_AssignMethod(wx_TextAttr, GetBulletText);
	Gura_AssignMethod(wx_TextAttr, GetCharacterStyleName);
	Gura_AssignMethod(wx_TextAttr, GetFlags);
	Gura_AssignMethod(wx_TextAttr, GetFont);
	Gura_AssignMethod(wx_TextAttr, GetFontAttributes);
	Gura_AssignMethod(wx_TextAttr, GetFontEncoding);
	Gura_AssignMethod(wx_TextAttr, GetFontFaceName);
	Gura_AssignMethod(wx_TextAttr, GetFontFamily);
	Gura_AssignMethod(wx_TextAttr, GetFontSize);
	Gura_AssignMethod(wx_TextAttr, GetFontStyle);
	Gura_AssignMethod(wx_TextAttr, GetFontUnderlined);
	Gura_AssignMethod(wx_TextAttr, GetFontWeight);
	Gura_AssignMethod(wx_TextAttr, GetLeftIndent);
	Gura_AssignMethod(wx_TextAttr, GetLeftSubIndent);
	Gura_AssignMethod(wx_TextAttr, GetLineSpacing);
	Gura_AssignMethod(wx_TextAttr, GetListStyleName);
	Gura_AssignMethod(wx_TextAttr, GetOutlineLevel);
	Gura_AssignMethod(wx_TextAttr, GetParagraphSpacingAfter);
	Gura_AssignMethod(wx_TextAttr, GetParagraphSpacingBefore);
	Gura_AssignMethod(wx_TextAttr, GetParagraphStyleName);
	Gura_AssignMethod(wx_TextAttr, GetRightIndent);
	Gura_AssignMethod(wx_TextAttr, GetTabs);
	Gura_AssignMethod(wx_TextAttr, GetTextColour);
	Gura_AssignMethod(wx_TextAttr, GetTextEffectFlags);
	Gura_AssignMethod(wx_TextAttr, GetTextEffects);
	Gura_AssignMethod(wx_TextAttr, GetURL);
	Gura_AssignMethod(wx_TextAttr, HasAlignment);
	Gura_AssignMethod(wx_TextAttr, HasBackgroundColour);
	Gura_AssignMethod(wx_TextAttr, HasBulletName);
	Gura_AssignMethod(wx_TextAttr, HasBulletNumber);
	Gura_AssignMethod(wx_TextAttr, HasBulletStyle);
	Gura_AssignMethod(wx_TextAttr, HasBulletText);
	Gura_AssignMethod(wx_TextAttr, HasCharacterStyleName);
	Gura_AssignMethod(wx_TextAttr, HasFlag);
	Gura_AssignMethod(wx_TextAttr, HasFont);
	Gura_AssignMethod(wx_TextAttr, HasFontEncoding);
	Gura_AssignMethod(wx_TextAttr, HasFontFaceName);
	Gura_AssignMethod(wx_TextAttr, HasFontFamily);
	Gura_AssignMethod(wx_TextAttr, HasFontItalic);
	Gura_AssignMethod(wx_TextAttr, HasFontSize);
	Gura_AssignMethod(wx_TextAttr, HasFontPointSize);
	Gura_AssignMethod(wx_TextAttr, HasFontPixelSize);
	Gura_AssignMethod(wx_TextAttr, HasFontUnderlined);
	Gura_AssignMethod(wx_TextAttr, HasFontWeight);
	Gura_AssignMethod(wx_TextAttr, HasLeftIndent);
	Gura_AssignMethod(wx_TextAttr, HasLineSpacing);
	Gura_AssignMethod(wx_TextAttr, HasListStyleName);
	Gura_AssignMethod(wx_TextAttr, HasOutlineLevel);
	Gura_AssignMethod(wx_TextAttr, HasPageBreak);
	Gura_AssignMethod(wx_TextAttr, HasParagraphSpacingAfter);
	Gura_AssignMethod(wx_TextAttr, HasParagraphSpacingBefore);
	Gura_AssignMethod(wx_TextAttr, HasParagraphStyleName);
	Gura_AssignMethod(wx_TextAttr, HasRightIndent);
	Gura_AssignMethod(wx_TextAttr, HasTabs);
	Gura_AssignMethod(wx_TextAttr, HasTextColour);
	Gura_AssignMethod(wx_TextAttr, HasTextEffects);
	Gura_AssignMethod(wx_TextAttr, HasURL);
	Gura_AssignMethod(wx_TextAttr, IsCharacterStyle);
	Gura_AssignMethod(wx_TextAttr, IsDefault);
	Gura_AssignMethod(wx_TextAttr, IsParagraphStyle);
	Gura_AssignMethod(wx_TextAttr, SetAlignment);
	Gura_AssignMethod(wx_TextAttr, SetBackgroundColour);
	Gura_AssignMethod(wx_TextAttr, SetBulletFont);
	Gura_AssignMethod(wx_TextAttr, SetBulletName);
	Gura_AssignMethod(wx_TextAttr, SetBulletNumber);
	Gura_AssignMethod(wx_TextAttr, SetBulletStyle);
	Gura_AssignMethod(wx_TextAttr, SetBulletText);
	Gura_AssignMethod(wx_TextAttr, SetCharacterStyleName);
	Gura_AssignMethod(wx_TextAttr, SetFlags);
	Gura_AssignMethod(wx_TextAttr, SetFont);
	Gura_AssignMethod(wx_TextAttr, SetFontEncoding);
	Gura_AssignMethod(wx_TextAttr, SetFontFaceName);
	Gura_AssignMethod(wx_TextAttr, SetFontFamily);
	Gura_AssignMethod(wx_TextAttr, SetFontSize);
	Gura_AssignMethod(wx_TextAttr, SetFontPointSize);
	Gura_AssignMethod(wx_TextAttr, SetFontPixelSize);
	Gura_AssignMethod(wx_TextAttr, SetFontStyle);
	Gura_AssignMethod(wx_TextAttr, SetFontUnderlined);
	Gura_AssignMethod(wx_TextAttr, SetFontWeight);
	Gura_AssignMethod(wx_TextAttr, SetLeftIndent);
	Gura_AssignMethod(wx_TextAttr, SetLineSpacing);
	Gura_AssignMethod(wx_TextAttr, SetListStyleName);
	Gura_AssignMethod(wx_TextAttr, SetOutlineLevel);
	Gura_AssignMethod(wx_TextAttr, SetPageBreak);
	Gura_AssignMethod(wx_TextAttr, SetParagraphSpacingAfter);
	Gura_AssignMethod(wx_TextAttr, SetParagraphSpacingBefore);
	Gura_AssignMethod(wx_TextAttr, SetParagraphStyleName);
	Gura_AssignMethod(wx_TextAttr, SetRightIndent);
	Gura_AssignMethod(wx_TextAttr, SetTabs);
	Gura_AssignMethod(wx_TextAttr, SetTextColour);
	Gura_AssignMethod(wx_TextAttr, SetTextEffectFlags);
	Gura_AssignMethod(wx_TextAttr, SetTextEffects);
	Gura_AssignMethod(wx_TextAttr, SetURL);
}

Gura_ImplementDescendantCreator(wx_TextAttr)
{
	return new Object_wx_TextAttr((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
