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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_InfoBar, wxInfoBar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_InfoBar, wxInfoBar)
{
	Signal &sig = env.GetSignal();
	Object_wx_InfoBar *pThis = Object_wx_InfoBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxInfoBar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_InfoBar, wxInfoBar_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "winid", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_InfoBar, wxInfoBar_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_InfoBar *pThis = Object_wx_InfoBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int winid = arg.GetNumber(1)
	//pThis->GetEntity()->wxInfoBar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_InfoBar, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "winid", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_InfoBar, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_InfoBar *pThis = Object_wx_InfoBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int winid = arg.GetNumber(1)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_InfoBar, AddButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "btnid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_InfoBar, AddButton)
{
	Signal &sig = env.GetSignal();
	Object_wx_InfoBar *pThis = Object_wx_InfoBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int btnid = arg.GetNumber(0)
	//int label = arg.GetNumber(1)
	//pThis->GetEntity()->AddButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_InfoBar, Dismiss)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_InfoBar, Dismiss)
{
	Signal &sig = env.GetSignal();
	Object_wx_InfoBar *pThis = Object_wx_InfoBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Dismiss();
	return Value::Nil;
}

Gura_DeclareMethod(wx_InfoBar, RemoveButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "btnid", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_InfoBar, RemoveButton)
{
	Signal &sig = env.GetSignal();
	Object_wx_InfoBar *pThis = Object_wx_InfoBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int btnid = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_InfoBar, ShowMessage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "msg", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_InfoBar, ShowMessage)
{
	Signal &sig = env.GetSignal();
	Object_wx_InfoBar *pThis = Object_wx_InfoBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int msg = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->ShowMessage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_InfoBar, GetButtonCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_InfoBar, GetButtonCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_InfoBar *pThis = Object_wx_InfoBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetButtonCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_InfoBar, GetButtonId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_InfoBar, GetButtonId)
{
	Signal &sig = env.GetSignal();
	Object_wx_InfoBar *pThis = Object_wx_InfoBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int idx = arg.GetNumber(0)
	//pThis->GetEntity()->GetButtonId();
	return Value::Nil;
}

Gura_DeclareMethod(wx_InfoBar, HasButtonId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "btnid", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_InfoBar, HasButtonId)
{
	Signal &sig = env.GetSignal();
	Object_wx_InfoBar *pThis = Object_wx_InfoBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int btnid = arg.GetNumber(0)
	//pThis->GetEntity()->HasButtonId();
	return Value::Nil;
}

Gura_DeclareMethod(wx_InfoBar, SetShowHideEffects)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "showEffect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "hideEffect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_InfoBar, SetShowHideEffects)
{
	Signal &sig = env.GetSignal();
	Object_wx_InfoBar *pThis = Object_wx_InfoBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int showEffect = arg.GetNumber(0)
	//int hideEffect = arg.GetNumber(1)
	//pThis->GetEntity()->SetShowHideEffects();
	return Value::Nil;
}

Gura_DeclareMethod(wx_InfoBar, GetShowEffect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_InfoBar, GetShowEffect)
{
	Signal &sig = env.GetSignal();
	Object_wx_InfoBar *pThis = Object_wx_InfoBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetShowEffect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_InfoBar, GetHideEffect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_InfoBar, GetHideEffect)
{
	Signal &sig = env.GetSignal();
	Object_wx_InfoBar *pThis = Object_wx_InfoBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetHideEffect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_InfoBar, SetEffectDuration)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "duration", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_InfoBar, SetEffectDuration)
{
	Signal &sig = env.GetSignal();
	Object_wx_InfoBar *pThis = Object_wx_InfoBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int duration = arg.GetNumber(0)
	//pThis->GetEntity()->SetEffectDuration();
	return Value::Nil;
}

Gura_DeclareMethod(wx_InfoBar, GetEffectDuration)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_InfoBar, GetEffectDuration)
{
	Signal &sig = env.GetSignal();
	Object_wx_InfoBar *pThis = Object_wx_InfoBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetEffectDuration();
	return Value::Nil;
}

Gura_DeclareMethod(wx_InfoBar, SetFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_InfoBar, SetFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_InfoBar *pThis = Object_wx_InfoBar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int font = arg.GetNumber(0)
	//pThis->GetEntity()->SetFont();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxInfoBar
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_InfoBar)
{
	Gura_AssignMethod(wx_InfoBar, wxInfoBar);
	Gura_AssignMethod(wx_InfoBar, wxInfoBar_1);
	Gura_AssignMethod(wx_InfoBar, Create);
	Gura_AssignMethod(wx_InfoBar, AddButton);
	Gura_AssignMethod(wx_InfoBar, Dismiss);
	Gura_AssignMethod(wx_InfoBar, RemoveButton);
	Gura_AssignMethod(wx_InfoBar, ShowMessage);
	Gura_AssignMethod(wx_InfoBar, GetButtonCount);
	Gura_AssignMethod(wx_InfoBar, GetButtonId);
	Gura_AssignMethod(wx_InfoBar, HasButtonId);
	Gura_AssignMethod(wx_InfoBar, SetShowHideEffects);
	Gura_AssignMethod(wx_InfoBar, GetShowEffect);
	Gura_AssignMethod(wx_InfoBar, GetHideEffect);
	Gura_AssignMethod(wx_InfoBar, SetEffectDuration);
	Gura_AssignMethod(wx_InfoBar, GetEffectDuration);
	Gura_AssignMethod(wx_InfoBar, SetFont);
}

Gura_ImplementDescendantCreator(wx_InfoBar)
{
	return new Object_wx_InfoBar((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
