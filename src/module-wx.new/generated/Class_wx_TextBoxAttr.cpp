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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxTextBoxAttr, "wxTextBoxAttr")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(__wxTextBoxAttr)
{
	//wxTextBoxAttr();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxTextBoxAttr_1, "wxTextBoxAttr_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxTextBoxAttr_1)
{
	//int attr = arg.GetNumber(0)
	//wxTextBoxAttr();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_TextBoxAttr, __Init, "Init")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __Init)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Init();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __Reset, "Reset")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __Reset)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Reset();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __EqPartial, "EqPartial")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "weakTest", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextBoxAttr, __EqPartial)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int attr = arg.GetNumber(0)
	//int weakTest = arg.GetNumber(1)
	//pThis->GetEntity()->EqPartial();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __Apply, "Apply")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "compareWith", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextBoxAttr, __Apply)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//int compareWith = arg.GetNumber(1)
	//pThis->GetEntity()->Apply();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __CollectCommonAttributes, "CollectCommonAttributes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clashingAttr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "absentAttr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextBoxAttr, __CollectCommonAttributes)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int attr = arg.GetNumber(0)
	//int clashingAttr = arg.GetNumber(1)
	//int absentAttr = arg.GetNumber(2)
	//pThis->GetEntity()->CollectCommonAttributes();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __RemoveStyle, "RemoveStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextBoxAttr, __RemoveStyle)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int attr = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __SetFlags, "SetFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextBoxAttr, __SetFlags)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->SetFlags();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetFlags, "GetFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetFlags)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFlags();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __HasFlag, "HasFlag")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextBoxAttr, __HasFlag)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->HasFlag();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __RemoveFlag, "RemoveFlag")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextBoxAttr, __RemoveFlag)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveFlag();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __AddFlag, "AddFlag")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextBoxAttr, __AddFlag)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->AddFlag();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __IsDefault, "IsDefault")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __IsDefault)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsDefault();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetFloatMode, "GetFloatMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetFloatMode)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFloatMode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __SetFloatMode, "SetFloatMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextBoxAttr, __SetFloatMode)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int mode = arg.GetNumber(0)
	//pThis->GetEntity()->SetFloatMode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __HasFloatMode, "HasFloatMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __HasFloatMode)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasFloatMode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __IsFloating, "IsFloating")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __IsFloating)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsFloating();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetClearMode, "GetClearMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetClearMode)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetClearMode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __SetClearMode, "SetClearMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextBoxAttr, __SetClearMode)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int mode = arg.GetNumber(0)
	//pThis->GetEntity()->SetClearMode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __HasClearMode, "HasClearMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __HasClearMode)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasClearMode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetCollapseBorders, "GetCollapseBorders")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetCollapseBorders)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCollapseBorders();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __SetCollapseBorders, "SetCollapseBorders")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "collapse", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextBoxAttr, __SetCollapseBorders)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int collapse = arg.GetNumber(0)
	//pThis->GetEntity()->SetCollapseBorders();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __HasCollapseBorders, "HasCollapseBorders")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __HasCollapseBorders)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasCollapseBorders();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetWhitespaceMode, "GetWhitespaceMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetWhitespaceMode)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWhitespaceMode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __SetWhitespaceMode, "SetWhitespaceMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "whitespace", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextBoxAttr, __SetWhitespaceMode)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int whitespace = arg.GetNumber(0)
	//pThis->GetEntity()->SetWhitespaceMode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __HasWhitespaceMode, "HasWhitespaceMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __HasWhitespaceMode)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasWhitespaceMode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __HasCornerRadius, "HasCornerRadius")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __HasCornerRadius)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasCornerRadius();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetCornerRadius, "GetCornerRadius")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetCornerRadius)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCornerRadius();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetCornerRadius_1, "GetCornerRadius_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetCornerRadius_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCornerRadius();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __SetCornerRadius, "SetCornerRadius")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dim", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextBoxAttr, __SetCornerRadius)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dim = arg.GetNumber(0)
	//pThis->GetEntity()->SetCornerRadius();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetVerticalAlignment, "GetVerticalAlignment")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetVerticalAlignment)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetVerticalAlignment();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __SetVerticalAlignment, "SetVerticalAlignment")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "verticalAlignment", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextBoxAttr, __SetVerticalAlignment)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int verticalAlignment = arg.GetNumber(0)
	//pThis->GetEntity()->SetVerticalAlignment();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __HasVerticalAlignment, "HasVerticalAlignment")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __HasVerticalAlignment)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasVerticalAlignment();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetMargins, "GetMargins")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetMargins)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMargins();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetMargins_1, "GetMargins_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetMargins_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMargins();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetLeftMargin, "GetLeftMargin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetLeftMargin)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLeftMargin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetLeftMargin_1, "GetLeftMargin_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetLeftMargin_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLeftMargin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetRightMargin, "GetRightMargin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetRightMargin)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRightMargin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetRightMargin_1, "GetRightMargin_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetRightMargin_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRightMargin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetTopMargin, "GetTopMargin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetTopMargin)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTopMargin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetTopMargin_1, "GetTopMargin_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetTopMargin_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTopMargin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetBottomMargin, "GetBottomMargin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetBottomMargin)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBottomMargin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetBottomMargin_1, "GetBottomMargin_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetBottomMargin_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBottomMargin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetPosition, "GetPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetPosition)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetPosition_1, "GetPosition_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetPosition_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetLeft, "GetLeft")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetLeft)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLeft();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetLeft_1, "GetLeft_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetLeft_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLeft();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetRight, "GetRight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetRight)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetRight_1, "GetRight_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetRight_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetTop, "GetTop")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetTop)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTop();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetTop_1, "GetTop_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetTop_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTop();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetBottom, "GetBottom")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetBottom)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBottom();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetBottom_1, "GetBottom_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetBottom_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBottom();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetPadding, "GetPadding")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetPadding)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPadding();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetPadding_1, "GetPadding_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetPadding_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPadding();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetLeftPadding, "GetLeftPadding")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetLeftPadding)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLeftPadding();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetLeftPadding_1, "GetLeftPadding_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetLeftPadding_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLeftPadding();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetRightPadding, "GetRightPadding")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetRightPadding)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRightPadding();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetRightPadding_1, "GetRightPadding_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetRightPadding_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRightPadding();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetTopPadding, "GetTopPadding")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetTopPadding)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTopPadding();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetTopPadding_1, "GetTopPadding_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetTopPadding_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTopPadding();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetBottomPadding, "GetBottomPadding")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetBottomPadding)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBottomPadding();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetBottomPadding_1, "GetBottomPadding_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetBottomPadding_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBottomPadding();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetBorder, "GetBorder")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetBorder)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBorder();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetBorder_1, "GetBorder_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetBorder_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBorder();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetLeftBorder, "GetLeftBorder")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetLeftBorder)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLeftBorder();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetLeftBorder_1, "GetLeftBorder_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetLeftBorder_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLeftBorder();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetTopBorder, "GetTopBorder")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetTopBorder)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTopBorder();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetTopBorder_1, "GetTopBorder_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetTopBorder_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTopBorder();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetRightBorder, "GetRightBorder")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetRightBorder)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRightBorder();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetRightBorder_1, "GetRightBorder_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetRightBorder_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRightBorder();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetBottomBorder, "GetBottomBorder")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetBottomBorder)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBottomBorder();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetBottomBorder_1, "GetBottomBorder_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetBottomBorder_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBottomBorder();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetOutline, "GetOutline")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetOutline)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOutline();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetOutline_1, "GetOutline_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetOutline_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOutline();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetLeftOutline, "GetLeftOutline")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetLeftOutline)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLeftOutline();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetLeftOutline_1, "GetLeftOutline_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetLeftOutline_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLeftOutline();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetTopOutline, "GetTopOutline")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetTopOutline)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTopOutline();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetTopOutline_1, "GetTopOutline_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetTopOutline_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTopOutline();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetRightOutline, "GetRightOutline")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetRightOutline)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRightOutline();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetRightOutline_1, "GetRightOutline_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetRightOutline_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRightOutline();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetBottomOutline, "GetBottomOutline")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetBottomOutline)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBottomOutline();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetBottomOutline_1, "GetBottomOutline_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetBottomOutline_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBottomOutline();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetSize, "GetSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetSize)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetSize_1, "GetSize_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetSize_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetMinSize, "GetMinSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetMinSize)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMinSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetMinSize_1, "GetMinSize_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetMinSize_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMinSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetMaxSize, "GetMaxSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetMaxSize)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMaxSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetMaxSize_1, "GetMaxSize_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetMaxSize_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMaxSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __SetSize, "SetSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextBoxAttr, __SetSize)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sz = arg.GetNumber(0)
	//pThis->GetEntity()->SetSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __SetMinSize, "SetMinSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextBoxAttr, __SetMinSize)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sz = arg.GetNumber(0)
	//pThis->GetEntity()->SetMinSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __SetMaxSize, "SetMaxSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextBoxAttr, __SetMaxSize)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sz = arg.GetNumber(0)
	//pThis->GetEntity()->SetMaxSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetWidth, "GetWidth")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetWidth)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWidth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetWidth_1, "GetWidth_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetWidth_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWidth();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetHeight, "GetHeight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetHeight)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHeight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetHeight_1, "GetHeight_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetHeight_1)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHeight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetBoxStyleName, "GetBoxStyleName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetBoxStyleName)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBoxStyleName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __SetBoxStyleName, "SetBoxStyleName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextBoxAttr, __SetBoxStyleName)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->SetBoxStyleName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __HasBoxStyleName, "HasBoxStyleName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __HasBoxStyleName)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasBoxStyleName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetShadow, "GetShadow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetShadow)
{
	Object_wx_TextBoxAttr *pThis = Object_wx_TextBoxAttr::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetShadow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextBoxAttr, __GetShadow_1, "GetShadow_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextBoxAttr, __GetShadow_1)
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
	// Constructor assignment
	Gura_AssignFunction(__wxTextBoxAttr);
	Gura_AssignFunction(__wxTextBoxAttr_1);
	// Method assignment
	Gura_AssignMethod(wx_TextBoxAttr, __Init);
	Gura_AssignMethod(wx_TextBoxAttr, __Reset);
	Gura_AssignMethod(wx_TextBoxAttr, __EqPartial);
	Gura_AssignMethod(wx_TextBoxAttr, __Apply);
	Gura_AssignMethod(wx_TextBoxAttr, __CollectCommonAttributes);
	Gura_AssignMethod(wx_TextBoxAttr, __RemoveStyle);
	Gura_AssignMethod(wx_TextBoxAttr, __SetFlags);
	Gura_AssignMethod(wx_TextBoxAttr, __GetFlags);
	Gura_AssignMethod(wx_TextBoxAttr, __HasFlag);
	Gura_AssignMethod(wx_TextBoxAttr, __RemoveFlag);
	Gura_AssignMethod(wx_TextBoxAttr, __AddFlag);
	Gura_AssignMethod(wx_TextBoxAttr, __IsDefault);
	Gura_AssignMethod(wx_TextBoxAttr, __GetFloatMode);
	Gura_AssignMethod(wx_TextBoxAttr, __SetFloatMode);
	Gura_AssignMethod(wx_TextBoxAttr, __HasFloatMode);
	Gura_AssignMethod(wx_TextBoxAttr, __IsFloating);
	Gura_AssignMethod(wx_TextBoxAttr, __GetClearMode);
	Gura_AssignMethod(wx_TextBoxAttr, __SetClearMode);
	Gura_AssignMethod(wx_TextBoxAttr, __HasClearMode);
	Gura_AssignMethod(wx_TextBoxAttr, __GetCollapseBorders);
	Gura_AssignMethod(wx_TextBoxAttr, __SetCollapseBorders);
	Gura_AssignMethod(wx_TextBoxAttr, __HasCollapseBorders);
	Gura_AssignMethod(wx_TextBoxAttr, __GetWhitespaceMode);
	Gura_AssignMethod(wx_TextBoxAttr, __SetWhitespaceMode);
	Gura_AssignMethod(wx_TextBoxAttr, __HasWhitespaceMode);
	Gura_AssignMethod(wx_TextBoxAttr, __HasCornerRadius);
	Gura_AssignMethod(wx_TextBoxAttr, __GetCornerRadius);
	Gura_AssignMethod(wx_TextBoxAttr, __GetCornerRadius_1);
	Gura_AssignMethod(wx_TextBoxAttr, __SetCornerRadius);
	Gura_AssignMethod(wx_TextBoxAttr, __GetVerticalAlignment);
	Gura_AssignMethod(wx_TextBoxAttr, __SetVerticalAlignment);
	Gura_AssignMethod(wx_TextBoxAttr, __HasVerticalAlignment);
	Gura_AssignMethod(wx_TextBoxAttr, __GetMargins);
	Gura_AssignMethod(wx_TextBoxAttr, __GetMargins_1);
	Gura_AssignMethod(wx_TextBoxAttr, __GetLeftMargin);
	Gura_AssignMethod(wx_TextBoxAttr, __GetLeftMargin_1);
	Gura_AssignMethod(wx_TextBoxAttr, __GetRightMargin);
	Gura_AssignMethod(wx_TextBoxAttr, __GetRightMargin_1);
	Gura_AssignMethod(wx_TextBoxAttr, __GetTopMargin);
	Gura_AssignMethod(wx_TextBoxAttr, __GetTopMargin_1);
	Gura_AssignMethod(wx_TextBoxAttr, __GetBottomMargin);
	Gura_AssignMethod(wx_TextBoxAttr, __GetBottomMargin_1);
	Gura_AssignMethod(wx_TextBoxAttr, __GetPosition);
	Gura_AssignMethod(wx_TextBoxAttr, __GetPosition_1);
	Gura_AssignMethod(wx_TextBoxAttr, __GetLeft);
	Gura_AssignMethod(wx_TextBoxAttr, __GetLeft_1);
	Gura_AssignMethod(wx_TextBoxAttr, __GetRight);
	Gura_AssignMethod(wx_TextBoxAttr, __GetRight_1);
	Gura_AssignMethod(wx_TextBoxAttr, __GetTop);
	Gura_AssignMethod(wx_TextBoxAttr, __GetTop_1);
	Gura_AssignMethod(wx_TextBoxAttr, __GetBottom);
	Gura_AssignMethod(wx_TextBoxAttr, __GetBottom_1);
	Gura_AssignMethod(wx_TextBoxAttr, __GetPadding);
	Gura_AssignMethod(wx_TextBoxAttr, __GetPadding_1);
	Gura_AssignMethod(wx_TextBoxAttr, __GetLeftPadding);
	Gura_AssignMethod(wx_TextBoxAttr, __GetLeftPadding_1);
	Gura_AssignMethod(wx_TextBoxAttr, __GetRightPadding);
	Gura_AssignMethod(wx_TextBoxAttr, __GetRightPadding_1);
	Gura_AssignMethod(wx_TextBoxAttr, __GetTopPadding);
	Gura_AssignMethod(wx_TextBoxAttr, __GetTopPadding_1);
	Gura_AssignMethod(wx_TextBoxAttr, __GetBottomPadding);
	Gura_AssignMethod(wx_TextBoxAttr, __GetBottomPadding_1);
	Gura_AssignMethod(wx_TextBoxAttr, __GetBorder);
	Gura_AssignMethod(wx_TextBoxAttr, __GetBorder_1);
	Gura_AssignMethod(wx_TextBoxAttr, __GetLeftBorder);
	Gura_AssignMethod(wx_TextBoxAttr, __GetLeftBorder_1);
	Gura_AssignMethod(wx_TextBoxAttr, __GetTopBorder);
	Gura_AssignMethod(wx_TextBoxAttr, __GetTopBorder_1);
	Gura_AssignMethod(wx_TextBoxAttr, __GetRightBorder);
	Gura_AssignMethod(wx_TextBoxAttr, __GetRightBorder_1);
	Gura_AssignMethod(wx_TextBoxAttr, __GetBottomBorder);
	Gura_AssignMethod(wx_TextBoxAttr, __GetBottomBorder_1);
	Gura_AssignMethod(wx_TextBoxAttr, __GetOutline);
	Gura_AssignMethod(wx_TextBoxAttr, __GetOutline_1);
	Gura_AssignMethod(wx_TextBoxAttr, __GetLeftOutline);
	Gura_AssignMethod(wx_TextBoxAttr, __GetLeftOutline_1);
	Gura_AssignMethod(wx_TextBoxAttr, __GetTopOutline);
	Gura_AssignMethod(wx_TextBoxAttr, __GetTopOutline_1);
	Gura_AssignMethod(wx_TextBoxAttr, __GetRightOutline);
	Gura_AssignMethod(wx_TextBoxAttr, __GetRightOutline_1);
	Gura_AssignMethod(wx_TextBoxAttr, __GetBottomOutline);
	Gura_AssignMethod(wx_TextBoxAttr, __GetBottomOutline_1);
	Gura_AssignMethod(wx_TextBoxAttr, __GetSize);
	Gura_AssignMethod(wx_TextBoxAttr, __GetSize_1);
	Gura_AssignMethod(wx_TextBoxAttr, __GetMinSize);
	Gura_AssignMethod(wx_TextBoxAttr, __GetMinSize_1);
	Gura_AssignMethod(wx_TextBoxAttr, __GetMaxSize);
	Gura_AssignMethod(wx_TextBoxAttr, __GetMaxSize_1);
	Gura_AssignMethod(wx_TextBoxAttr, __SetSize);
	Gura_AssignMethod(wx_TextBoxAttr, __SetMinSize);
	Gura_AssignMethod(wx_TextBoxAttr, __SetMaxSize);
	Gura_AssignMethod(wx_TextBoxAttr, __GetWidth);
	Gura_AssignMethod(wx_TextBoxAttr, __GetWidth_1);
	Gura_AssignMethod(wx_TextBoxAttr, __GetHeight);
	Gura_AssignMethod(wx_TextBoxAttr, __GetHeight_1);
	Gura_AssignMethod(wx_TextBoxAttr, __GetBoxStyleName);
	Gura_AssignMethod(wx_TextBoxAttr, __SetBoxStyleName);
	Gura_AssignMethod(wx_TextBoxAttr, __HasBoxStyleName);
	Gura_AssignMethod(wx_TextBoxAttr, __GetShadow);
	Gura_AssignMethod(wx_TextBoxAttr, __GetShadow_1);
}

Gura_ImplementDescendantCreator(wx_TextBoxAttr)
{
	return new Object_wx_TextBoxAttr((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
