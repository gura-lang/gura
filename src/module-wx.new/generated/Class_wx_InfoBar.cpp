//----------------------------------------------------------------------------
// wxInfoBar
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxInfoBar
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxInfoBar
//----------------------------------------------------------------------------
Object_wx_InfoBar::~Object_wx_InfoBar()
{
}

Object *Object_wx_InfoBar::Clone() const
{
	return nullptr;
}

String Object_wx_InfoBar::ToString(bool exprFlag)
{
	String rtn("<wx.InfoBar:");
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
Gura_DeclareFunctionAlias(__wxInfoBar, "wxInfoBar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(__wxInfoBar)
{
	//wxInfoBar();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxInfoBar_1, "wxInfoBar_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "winid", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxInfoBar_1)
{
	//int parent = arg.GetNumber(0)
	//int winid = arg.GetNumber(1)
	//wxInfoBar();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_InfoBar, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "winid", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_InfoBar, __Create)
{
	Object_wx_InfoBar *pThis = Object_wx_InfoBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int winid = arg.GetNumber(1)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_InfoBar, __AddButton, "AddButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "btnid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_InfoBar, __AddButton)
{
	Object_wx_InfoBar *pThis = Object_wx_InfoBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int btnid = arg.GetNumber(0)
	//int label = arg.GetNumber(1)
	//pThis->GetEntity()->AddButton();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_InfoBar, __Dismiss, "Dismiss")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_InfoBar, __Dismiss)
{
	Object_wx_InfoBar *pThis = Object_wx_InfoBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Dismiss();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_InfoBar, __RemoveButton, "RemoveButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "btnid", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_InfoBar, __RemoveButton)
{
	Object_wx_InfoBar *pThis = Object_wx_InfoBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int btnid = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveButton();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_InfoBar, __ShowMessage, "ShowMessage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "msg", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_InfoBar, __ShowMessage)
{
	Object_wx_InfoBar *pThis = Object_wx_InfoBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int msg = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->ShowMessage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_InfoBar, __GetButtonCount, "GetButtonCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_InfoBar, __GetButtonCount)
{
	Object_wx_InfoBar *pThis = Object_wx_InfoBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetButtonCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_InfoBar, __GetButtonId, "GetButtonId")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_InfoBar, __GetButtonId)
{
	Object_wx_InfoBar *pThis = Object_wx_InfoBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int idx = arg.GetNumber(0)
	//pThis->GetEntity()->GetButtonId();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_InfoBar, __HasButtonId, "HasButtonId")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "btnid", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_InfoBar, __HasButtonId)
{
	Object_wx_InfoBar *pThis = Object_wx_InfoBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int btnid = arg.GetNumber(0)
	//pThis->GetEntity()->HasButtonId();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_InfoBar, __SetShowHideEffects, "SetShowHideEffects")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "showEffect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "hideEffect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_InfoBar, __SetShowHideEffects)
{
	Object_wx_InfoBar *pThis = Object_wx_InfoBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int showEffect = arg.GetNumber(0)
	//int hideEffect = arg.GetNumber(1)
	//pThis->GetEntity()->SetShowHideEffects();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_InfoBar, __GetShowEffect, "GetShowEffect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_InfoBar, __GetShowEffect)
{
	Object_wx_InfoBar *pThis = Object_wx_InfoBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetShowEffect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_InfoBar, __GetHideEffect, "GetHideEffect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_InfoBar, __GetHideEffect)
{
	Object_wx_InfoBar *pThis = Object_wx_InfoBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHideEffect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_InfoBar, __SetEffectDuration, "SetEffectDuration")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "duration", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_InfoBar, __SetEffectDuration)
{
	Object_wx_InfoBar *pThis = Object_wx_InfoBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int duration = arg.GetNumber(0)
	//pThis->GetEntity()->SetEffectDuration();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_InfoBar, __GetEffectDuration, "GetEffectDuration")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_InfoBar, __GetEffectDuration)
{
	Object_wx_InfoBar *pThis = Object_wx_InfoBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEffectDuration();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_InfoBar, __SetFont, "SetFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_InfoBar, __SetFont)
{
	Object_wx_InfoBar *pThis = Object_wx_InfoBar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int font = arg.GetNumber(0)
	//pThis->GetEntity()->SetFont();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxInfoBar
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_InfoBar)
{
	// Constructor assignment
	Gura_AssignFunction(__wxInfoBar);
	Gura_AssignFunction(__wxInfoBar_1);
	// Method assignment
	Gura_AssignMethod(wx_InfoBar, __Create);
	Gura_AssignMethod(wx_InfoBar, __AddButton);
	Gura_AssignMethod(wx_InfoBar, __Dismiss);
	Gura_AssignMethod(wx_InfoBar, __RemoveButton);
	Gura_AssignMethod(wx_InfoBar, __ShowMessage);
	Gura_AssignMethod(wx_InfoBar, __GetButtonCount);
	Gura_AssignMethod(wx_InfoBar, __GetButtonId);
	Gura_AssignMethod(wx_InfoBar, __HasButtonId);
	Gura_AssignMethod(wx_InfoBar, __SetShowHideEffects);
	Gura_AssignMethod(wx_InfoBar, __GetShowEffect);
	Gura_AssignMethod(wx_InfoBar, __GetHideEffect);
	Gura_AssignMethod(wx_InfoBar, __SetEffectDuration);
	Gura_AssignMethod(wx_InfoBar, __GetEffectDuration);
	Gura_AssignMethod(wx_InfoBar, __SetFont);
}

Gura_ImplementDescendantCreator(wx_InfoBar)
{
	return new Object_wx_InfoBar((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
