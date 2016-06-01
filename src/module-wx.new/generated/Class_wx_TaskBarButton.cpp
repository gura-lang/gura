//----------------------------------------------------------------------------
// wxTaskBarButton
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTaskBarButton
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTaskBarButton
//----------------------------------------------------------------------------
Object_wx_TaskBarButton::~Object_wx_TaskBarButton()
{
}

Object *Object_wx_TaskBarButton::Clone() const
{
	return nullptr;
}

String Object_wx_TaskBarButton::ToString(bool exprFlag)
{
	String rtn("<wx.TaskBarButton:");
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
Gura_DeclareMethod(wx_TaskBarButton, SetProgressRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TaskBarButton, SetProgressRange)
{
	Signal &sig = env.GetSignal();
	Object_wx_TaskBarButton *pThis = Object_wx_TaskBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//pThis->GetEntity()->SetProgressRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TaskBarButton, SetProgressValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TaskBarButton, SetProgressValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_TaskBarButton *pThis = Object_wx_TaskBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//pThis->GetEntity()->SetProgressValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TaskBarButton, PulseProgress)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TaskBarButton, PulseProgress)
{
	Signal &sig = env.GetSignal();
	Object_wx_TaskBarButton *pThis = Object_wx_TaskBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->PulseProgress();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TaskBarButton, Show)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "show", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TaskBarButton, Show)
{
	Signal &sig = env.GetSignal();
	Object_wx_TaskBarButton *pThis = Object_wx_TaskBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int show = arg.GetNumber(0)
	//pThis->GetEntity()->Show();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TaskBarButton, Hide)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TaskBarButton, Hide)
{
	Signal &sig = env.GetSignal();
	Object_wx_TaskBarButton *pThis = Object_wx_TaskBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Hide();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TaskBarButton, SetThumbnailTooltip)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tooltip", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TaskBarButton, SetThumbnailTooltip)
{
	Signal &sig = env.GetSignal();
	Object_wx_TaskBarButton *pThis = Object_wx_TaskBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int tooltip = arg.GetNumber(0)
	//pThis->GetEntity()->SetThumbnailTooltip();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TaskBarButton, SetProgressState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "state", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TaskBarButton, SetProgressState)
{
	Signal &sig = env.GetSignal();
	Object_wx_TaskBarButton *pThis = Object_wx_TaskBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int state = arg.GetNumber(0)
	//pThis->GetEntity()->SetProgressState();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TaskBarButton, SetOverlayIcon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "description", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TaskBarButton, SetOverlayIcon)
{
	Signal &sig = env.GetSignal();
	Object_wx_TaskBarButton *pThis = Object_wx_TaskBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int icon = arg.GetNumber(0)
	//int description = arg.GetNumber(1)
	//pThis->GetEntity()->SetOverlayIcon();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TaskBarButton, SetThumbnailClip)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TaskBarButton, SetThumbnailClip)
{
	Signal &sig = env.GetSignal();
	Object_wx_TaskBarButton *pThis = Object_wx_TaskBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//pThis->GetEntity()->SetThumbnailClip();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TaskBarButton, SetThumbnailContents)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "child", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TaskBarButton, SetThumbnailContents)
{
	Signal &sig = env.GetSignal();
	Object_wx_TaskBarButton *pThis = Object_wx_TaskBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int child = arg.GetNumber(0)
	//pThis->GetEntity()->SetThumbnailContents();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TaskBarButton, InsertThumbBarButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "button", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TaskBarButton, InsertThumbBarButton)
{
	Signal &sig = env.GetSignal();
	Object_wx_TaskBarButton *pThis = Object_wx_TaskBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int button = arg.GetNumber(1)
	//pThis->GetEntity()->InsertThumbBarButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TaskBarButton, AppendThumbBarButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "button", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TaskBarButton, AppendThumbBarButton)
{
	Signal &sig = env.GetSignal();
	Object_wx_TaskBarButton *pThis = Object_wx_TaskBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int button = arg.GetNumber(0)
	//pThis->GetEntity()->AppendThumbBarButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TaskBarButton, AppendSeparatorInThumbBar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TaskBarButton, AppendSeparatorInThumbBar)
{
	Signal &sig = env.GetSignal();
	Object_wx_TaskBarButton *pThis = Object_wx_TaskBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->AppendSeparatorInThumbBar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TaskBarButton, RemoveThumbBarButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "button", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TaskBarButton, RemoveThumbBarButton)
{
	Signal &sig = env.GetSignal();
	Object_wx_TaskBarButton *pThis = Object_wx_TaskBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int button = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveThumbBarButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TaskBarButton, RemoveThumbBarButton_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TaskBarButton, RemoveThumbBarButton_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_TaskBarButton *pThis = Object_wx_TaskBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveThumbBarButton();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTaskBarButton
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TaskBarButton)
{
	Gura_AssignMethod(wx_TaskBarButton, SetProgressRange);
	Gura_AssignMethod(wx_TaskBarButton, SetProgressValue);
	Gura_AssignMethod(wx_TaskBarButton, PulseProgress);
	Gura_AssignMethod(wx_TaskBarButton, Show);
	Gura_AssignMethod(wx_TaskBarButton, Hide);
	Gura_AssignMethod(wx_TaskBarButton, SetThumbnailTooltip);
	Gura_AssignMethod(wx_TaskBarButton, SetProgressState);
	Gura_AssignMethod(wx_TaskBarButton, SetOverlayIcon);
	Gura_AssignMethod(wx_TaskBarButton, SetThumbnailClip);
	Gura_AssignMethod(wx_TaskBarButton, SetThumbnailContents);
	Gura_AssignMethod(wx_TaskBarButton, InsertThumbBarButton);
	Gura_AssignMethod(wx_TaskBarButton, AppendThumbBarButton);
	Gura_AssignMethod(wx_TaskBarButton, AppendSeparatorInThumbBar);
	Gura_AssignMethod(wx_TaskBarButton, RemoveThumbBarButton);
	Gura_AssignMethod(wx_TaskBarButton, RemoveThumbBarButton_1);
}

Gura_ImplementDescendantCreator(wx_TaskBarButton)
{
	return new Object_wx_TaskBarButton((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
