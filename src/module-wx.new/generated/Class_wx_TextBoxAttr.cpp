//----------------------------------------------------------------------------
// wxTextBoxAttr
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTextBoxAttr
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTextBoxAttr
//----------------------------------------------------------------------------
Object_wx_TextBoxAttr::~Object_wx_TextBoxAttr()
{
}

Object *Object_wx_TextBoxAttr::Clone() const
{
	return nullptr;
}

String Object_wx_TextBoxAttr::ToString(bool exprFlag)
{
	String rtn("<wx.TextBoxAttr:");
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
Gura_DeclareMethod(wx_TextBoxAttr, wxTextBoxAttr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, wxTextBoxAttr)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxTextBoxAttr();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, wxTextBoxAttr_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextBoxAttr, wxTextBoxAttr_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int attr = arg.GetNumber(0)
	//pThis->GetEntity()->wxTextBoxAttr();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, Init)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, Init)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Init();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, Reset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, Reset)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Reset();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, EqPartial)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "weakTest", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextBoxAttr, EqPartial)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int attr = arg.GetNumber(0)
	//int weakTest = arg.GetNumber(1)
	//pThis->GetEntity()->EqPartial();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, Apply)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "compareWith", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextBoxAttr, Apply)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//int compareWith = arg.GetNumber(1)
	//pThis->GetEntity()->Apply();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, CollectCommonAttributes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clashingAttr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "absentAttr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextBoxAttr, CollectCommonAttributes)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int attr = arg.GetNumber(0)
	//int clashingAttr = arg.GetNumber(1)
	//int absentAttr = arg.GetNumber(2)
	//pThis->GetEntity()->CollectCommonAttributes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, RemoveStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextBoxAttr, RemoveStyle)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int attr = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, SetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextBoxAttr, SetFlags)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->SetFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetFlags)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, HasFlag)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextBoxAttr, HasFlag)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->HasFlag();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, RemoveFlag)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextBoxAttr, RemoveFlag)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveFlag();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, AddFlag)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextBoxAttr, AddFlag)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->AddFlag();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, IsDefault)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, IsDefault)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsDefault();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetFloatMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetFloatMode)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFloatMode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, SetFloatMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextBoxAttr, SetFloatMode)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int mode = arg.GetNumber(0)
	//pThis->GetEntity()->SetFloatMode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, HasFloatMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, HasFloatMode)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasFloatMode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, IsFloating)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, IsFloating)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsFloating();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetClearMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetClearMode)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetClearMode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, SetClearMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextBoxAttr, SetClearMode)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int mode = arg.GetNumber(0)
	//pThis->GetEntity()->SetClearMode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, HasClearMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, HasClearMode)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasClearMode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetCollapseBorders)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetCollapseBorders)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCollapseBorders();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, SetCollapseBorders)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "collapse", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextBoxAttr, SetCollapseBorders)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int collapse = arg.GetNumber(0)
	//pThis->GetEntity()->SetCollapseBorders();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, HasCollapseBorders)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, HasCollapseBorders)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasCollapseBorders();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetWhitespaceMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetWhitespaceMode)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWhitespaceMode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, SetWhitespaceMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "whitespace", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextBoxAttr, SetWhitespaceMode)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int whitespace = arg.GetNumber(0)
	//pThis->GetEntity()->SetWhitespaceMode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, HasWhitespaceMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, HasWhitespaceMode)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasWhitespaceMode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, HasCornerRadius)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, HasCornerRadius)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasCornerRadius();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetCornerRadius)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetCornerRadius)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCornerRadius();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetCornerRadius_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetCornerRadius_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCornerRadius();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, SetCornerRadius)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dim", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextBoxAttr, SetCornerRadius)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dim = arg.GetNumber(0)
	//pThis->GetEntity()->SetCornerRadius();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetVerticalAlignment)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetVerticalAlignment)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetVerticalAlignment();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, SetVerticalAlignment)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "verticalAlignment", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextBoxAttr, SetVerticalAlignment)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int verticalAlignment = arg.GetNumber(0)
	//pThis->GetEntity()->SetVerticalAlignment();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, HasVerticalAlignment)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, HasVerticalAlignment)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasVerticalAlignment();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetMargins)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetMargins)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMargins();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetMargins_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetMargins_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMargins();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetLeftMargin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetLeftMargin)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLeftMargin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetLeftMargin_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetLeftMargin_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLeftMargin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetRightMargin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetRightMargin)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRightMargin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetRightMargin_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetRightMargin_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRightMargin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetTopMargin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetTopMargin)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTopMargin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetTopMargin_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetTopMargin_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTopMargin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetBottomMargin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetBottomMargin)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBottomMargin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetBottomMargin_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetBottomMargin_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBottomMargin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetPosition)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetPosition_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetPosition_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetLeft)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetLeft)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLeft();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetLeft_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetLeft_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLeft();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetRight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetRight)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetRight_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetRight_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetTop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetTop)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTop();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetTop_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetTop_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTop();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetBottom)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetBottom)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBottom();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetBottom_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetBottom_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBottom();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetPadding)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetPadding)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPadding();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetPadding_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetPadding_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPadding();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetLeftPadding)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetLeftPadding)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLeftPadding();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetLeftPadding_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetLeftPadding_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLeftPadding();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetRightPadding)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetRightPadding)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRightPadding();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetRightPadding_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetRightPadding_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRightPadding();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetTopPadding)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetTopPadding)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTopPadding();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetTopPadding_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetTopPadding_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTopPadding();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetBottomPadding)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetBottomPadding)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBottomPadding();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetBottomPadding_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetBottomPadding_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBottomPadding();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetBorder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetBorder)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBorder();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetBorder_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetBorder_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBorder();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetLeftBorder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetLeftBorder)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLeftBorder();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetLeftBorder_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetLeftBorder_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLeftBorder();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetTopBorder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetTopBorder)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTopBorder();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetTopBorder_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetTopBorder_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTopBorder();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetRightBorder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetRightBorder)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRightBorder();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetRightBorder_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetRightBorder_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRightBorder();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetBottomBorder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetBottomBorder)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBottomBorder();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetBottomBorder_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetBottomBorder_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBottomBorder();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetOutline)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetOutline)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOutline();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetOutline_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetOutline_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOutline();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetLeftOutline)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetLeftOutline)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLeftOutline();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetLeftOutline_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetLeftOutline_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLeftOutline();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetTopOutline)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetTopOutline)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTopOutline();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetTopOutline_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetTopOutline_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTopOutline();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetRightOutline)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetRightOutline)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRightOutline();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetRightOutline_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetRightOutline_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRightOutline();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetBottomOutline)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetBottomOutline)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBottomOutline();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetBottomOutline_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetBottomOutline_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBottomOutline();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetSize)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetSize_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetSize_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetMinSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetMinSize)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMinSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetMinSize_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetMinSize_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMinSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetMaxSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetMaxSize)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMaxSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetMaxSize_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetMaxSize_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMaxSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, SetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextBoxAttr, SetSize)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sz = arg.GetNumber(0)
	//pThis->GetEntity()->SetSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, SetMinSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextBoxAttr, SetMinSize)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sz = arg.GetNumber(0)
	//pThis->GetEntity()->SetMinSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, SetMaxSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextBoxAttr, SetMaxSize)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sz = arg.GetNumber(0)
	//pThis->GetEntity()->SetMaxSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetWidth)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetWidth_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetWidth_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWidth();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetHeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetHeight)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHeight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetHeight_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetHeight_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHeight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetBoxStyleName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetBoxStyleName)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBoxStyleName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, SetBoxStyleName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextBoxAttr, SetBoxStyleName)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->SetBoxStyleName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, HasBoxStyleName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, HasBoxStyleName)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasBoxStyleName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetShadow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetShadow)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetShadow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextBoxAttr, GetShadow_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, GetShadow_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetShadow();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTextBoxAttr
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextBoxAttr)
{
	Gura_AssignMethod(wx_TextBoxAttr, wxTextBoxAttr);
	Gura_AssignMethod(wx_TextBoxAttr, wxTextBoxAttr_1);
	Gura_AssignMethod(wx_TextBoxAttr, Init);
	Gura_AssignMethod(wx_TextBoxAttr, Reset);
	Gura_AssignMethod(wx_TextBoxAttr, EqPartial);
	Gura_AssignMethod(wx_TextBoxAttr, Apply);
	Gura_AssignMethod(wx_TextBoxAttr, CollectCommonAttributes);
	Gura_AssignMethod(wx_TextBoxAttr, RemoveStyle);
	Gura_AssignMethod(wx_TextBoxAttr, SetFlags);
	Gura_AssignMethod(wx_TextBoxAttr, GetFlags);
	Gura_AssignMethod(wx_TextBoxAttr, HasFlag);
	Gura_AssignMethod(wx_TextBoxAttr, RemoveFlag);
	Gura_AssignMethod(wx_TextBoxAttr, AddFlag);
	Gura_AssignMethod(wx_TextBoxAttr, IsDefault);
	Gura_AssignMethod(wx_TextBoxAttr, GetFloatMode);
	Gura_AssignMethod(wx_TextBoxAttr, SetFloatMode);
	Gura_AssignMethod(wx_TextBoxAttr, HasFloatMode);
	Gura_AssignMethod(wx_TextBoxAttr, IsFloating);
	Gura_AssignMethod(wx_TextBoxAttr, GetClearMode);
	Gura_AssignMethod(wx_TextBoxAttr, SetClearMode);
	Gura_AssignMethod(wx_TextBoxAttr, HasClearMode);
	Gura_AssignMethod(wx_TextBoxAttr, GetCollapseBorders);
	Gura_AssignMethod(wx_TextBoxAttr, SetCollapseBorders);
	Gura_AssignMethod(wx_TextBoxAttr, HasCollapseBorders);
	Gura_AssignMethod(wx_TextBoxAttr, GetWhitespaceMode);
	Gura_AssignMethod(wx_TextBoxAttr, SetWhitespaceMode);
	Gura_AssignMethod(wx_TextBoxAttr, HasWhitespaceMode);
	Gura_AssignMethod(wx_TextBoxAttr, HasCornerRadius);
	Gura_AssignMethod(wx_TextBoxAttr, GetCornerRadius);
	Gura_AssignMethod(wx_TextBoxAttr, GetCornerRadius_1);
	Gura_AssignMethod(wx_TextBoxAttr, SetCornerRadius);
	Gura_AssignMethod(wx_TextBoxAttr, GetVerticalAlignment);
	Gura_AssignMethod(wx_TextBoxAttr, SetVerticalAlignment);
	Gura_AssignMethod(wx_TextBoxAttr, HasVerticalAlignment);
	Gura_AssignMethod(wx_TextBoxAttr, GetMargins);
	Gura_AssignMethod(wx_TextBoxAttr, GetMargins_1);
	Gura_AssignMethod(wx_TextBoxAttr, GetLeftMargin);
	Gura_AssignMethod(wx_TextBoxAttr, GetLeftMargin_1);
	Gura_AssignMethod(wx_TextBoxAttr, GetRightMargin);
	Gura_AssignMethod(wx_TextBoxAttr, GetRightMargin_1);
	Gura_AssignMethod(wx_TextBoxAttr, GetTopMargin);
	Gura_AssignMethod(wx_TextBoxAttr, GetTopMargin_1);
	Gura_AssignMethod(wx_TextBoxAttr, GetBottomMargin);
	Gura_AssignMethod(wx_TextBoxAttr, GetBottomMargin_1);
	Gura_AssignMethod(wx_TextBoxAttr, GetPosition);
	Gura_AssignMethod(wx_TextBoxAttr, GetPosition_1);
	Gura_AssignMethod(wx_TextBoxAttr, GetLeft);
	Gura_AssignMethod(wx_TextBoxAttr, GetLeft_1);
	Gura_AssignMethod(wx_TextBoxAttr, GetRight);
	Gura_AssignMethod(wx_TextBoxAttr, GetRight_1);
	Gura_AssignMethod(wx_TextBoxAttr, GetTop);
	Gura_AssignMethod(wx_TextBoxAttr, GetTop_1);
	Gura_AssignMethod(wx_TextBoxAttr, GetBottom);
	Gura_AssignMethod(wx_TextBoxAttr, GetBottom_1);
	Gura_AssignMethod(wx_TextBoxAttr, GetPadding);
	Gura_AssignMethod(wx_TextBoxAttr, GetPadding_1);
	Gura_AssignMethod(wx_TextBoxAttr, GetLeftPadding);
	Gura_AssignMethod(wx_TextBoxAttr, GetLeftPadding_1);
	Gura_AssignMethod(wx_TextBoxAttr, GetRightPadding);
	Gura_AssignMethod(wx_TextBoxAttr, GetRightPadding_1);
	Gura_AssignMethod(wx_TextBoxAttr, GetTopPadding);
	Gura_AssignMethod(wx_TextBoxAttr, GetTopPadding_1);
	Gura_AssignMethod(wx_TextBoxAttr, GetBottomPadding);
	Gura_AssignMethod(wx_TextBoxAttr, GetBottomPadding_1);
	Gura_AssignMethod(wx_TextBoxAttr, GetBorder);
	Gura_AssignMethod(wx_TextBoxAttr, GetBorder_1);
	Gura_AssignMethod(wx_TextBoxAttr, GetLeftBorder);
	Gura_AssignMethod(wx_TextBoxAttr, GetLeftBorder_1);
	Gura_AssignMethod(wx_TextBoxAttr, GetTopBorder);
	Gura_AssignMethod(wx_TextBoxAttr, GetTopBorder_1);
	Gura_AssignMethod(wx_TextBoxAttr, GetRightBorder);
	Gura_AssignMethod(wx_TextBoxAttr, GetRightBorder_1);
	Gura_AssignMethod(wx_TextBoxAttr, GetBottomBorder);
	Gura_AssignMethod(wx_TextBoxAttr, GetBottomBorder_1);
	Gura_AssignMethod(wx_TextBoxAttr, GetOutline);
	Gura_AssignMethod(wx_TextBoxAttr, GetOutline_1);
	Gura_AssignMethod(wx_TextBoxAttr, GetLeftOutline);
	Gura_AssignMethod(wx_TextBoxAttr, GetLeftOutline_1);
	Gura_AssignMethod(wx_TextBoxAttr, GetTopOutline);
	Gura_AssignMethod(wx_TextBoxAttr, GetTopOutline_1);
	Gura_AssignMethod(wx_TextBoxAttr, GetRightOutline);
	Gura_AssignMethod(wx_TextBoxAttr, GetRightOutline_1);
	Gura_AssignMethod(wx_TextBoxAttr, GetBottomOutline);
	Gura_AssignMethod(wx_TextBoxAttr, GetBottomOutline_1);
	Gura_AssignMethod(wx_TextBoxAttr, GetSize);
	Gura_AssignMethod(wx_TextBoxAttr, GetSize_1);
	Gura_AssignMethod(wx_TextBoxAttr, GetMinSize);
	Gura_AssignMethod(wx_TextBoxAttr, GetMinSize_1);
	Gura_AssignMethod(wx_TextBoxAttr, GetMaxSize);
	Gura_AssignMethod(wx_TextBoxAttr, GetMaxSize_1);
	Gura_AssignMethod(wx_TextBoxAttr, SetSize);
	Gura_AssignMethod(wx_TextBoxAttr, SetMinSize);
	Gura_AssignMethod(wx_TextBoxAttr, SetMaxSize);
	Gura_AssignMethod(wx_TextBoxAttr, GetWidth);
	Gura_AssignMethod(wx_TextBoxAttr, GetWidth_1);
	Gura_AssignMethod(wx_TextBoxAttr, GetHeight);
	Gura_AssignMethod(wx_TextBoxAttr, GetHeight_1);
	Gura_AssignMethod(wx_TextBoxAttr, GetBoxStyleName);
	Gura_AssignMethod(wx_TextBoxAttr, SetBoxStyleName);
	Gura_AssignMethod(wx_TextBoxAttr, HasBoxStyleName);
	Gura_AssignMethod(wx_TextBoxAttr, GetShadow);
	Gura_AssignMethod(wx_TextBoxAttr, GetShadow_1);
}

Gura_ImplementDescendantCreator(wx_TextBoxAttr)
{
	return new Object_wx_TextBoxAttr((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
