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
Gura_DeclareMethodAlias(wx_TaskBarButton, __SetProgressRange, "SetProgressRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TaskBarButton, __SetProgressRange)
{
	Object_wx_TaskBarButton *pThis = Object_wx_TaskBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//pThis->GetEntity()->SetProgressRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TaskBarButton, __SetProgressValue, "SetProgressValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TaskBarButton, __SetProgressValue)
{
	Object_wx_TaskBarButton *pThis = Object_wx_TaskBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//pThis->GetEntity()->SetProgressValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TaskBarButton, __PulseProgress, "PulseProgress")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TaskBarButton, __PulseProgress)
{
	Object_wx_TaskBarButton *pThis = Object_wx_TaskBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->PulseProgress();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TaskBarButton, __Show, "Show")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "show", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TaskBarButton, __Show)
{
	Object_wx_TaskBarButton *pThis = Object_wx_TaskBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool show = arg.GetNumber(0)
	//pThis->GetEntity()->Show();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TaskBarButton, __Hide, "Hide")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TaskBarButton, __Hide)
{
	Object_wx_TaskBarButton *pThis = Object_wx_TaskBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Hide();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TaskBarButton, __SetThumbnailTooltip, "SetThumbnailTooltip")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tooltip", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TaskBarButton, __SetThumbnailTooltip)
{
	Object_wx_TaskBarButton *pThis = Object_wx_TaskBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& tooltip = arg.GetNumber(0)
	//pThis->GetEntity()->SetThumbnailTooltip();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TaskBarButton, __SetProgressState, "SetProgressState")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "state", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TaskBarButton, __SetProgressState)
{
	Object_wx_TaskBarButton *pThis = Object_wx_TaskBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxTaskBarButtonState state = arg.GetNumber(0)
	//pThis->GetEntity()->SetProgressState();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TaskBarButton, __SetOverlayIcon, "SetOverlayIcon")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "description", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TaskBarButton, __SetOverlayIcon)
{
	Object_wx_TaskBarButton *pThis = Object_wx_TaskBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxIcon& icon = arg.GetNumber(0)
	//const wxString& description = arg.GetNumber(1)
	//pThis->GetEntity()->SetOverlayIcon();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TaskBarButton, __SetThumbnailClip, "SetThumbnailClip")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TaskBarButton, __SetThumbnailClip)
{
	Object_wx_TaskBarButton *pThis = Object_wx_TaskBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRect& rect = arg.GetNumber(0)
	//pThis->GetEntity()->SetThumbnailClip();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TaskBarButton, __SetThumbnailContents, "SetThumbnailContents")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "child", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TaskBarButton, __SetThumbnailContents)
{
	Object_wx_TaskBarButton *pThis = Object_wx_TaskBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxWindow* child = arg.GetNumber(0)
	//pThis->GetEntity()->SetThumbnailContents();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TaskBarButton, __InsertThumbBarButton, "InsertThumbBarButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "button", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TaskBarButton, __InsertThumbBarButton)
{
	Object_wx_TaskBarButton *pThis = Object_wx_TaskBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t pos = arg.GetNumber(0)
	//wxThumbBarButton* button = arg.GetNumber(1)
	//pThis->GetEntity()->InsertThumbBarButton();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TaskBarButton, __AppendThumbBarButton, "AppendThumbBarButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "button", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TaskBarButton, __AppendThumbBarButton)
{
	Object_wx_TaskBarButton *pThis = Object_wx_TaskBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxThumbBarButton* button = arg.GetNumber(0)
	//pThis->GetEntity()->AppendThumbBarButton();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TaskBarButton, __AppendSeparatorInThumbBar, "AppendSeparatorInThumbBar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TaskBarButton, __AppendSeparatorInThumbBar)
{
	Object_wx_TaskBarButton *pThis = Object_wx_TaskBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AppendSeparatorInThumbBar();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TaskBarButton, __RemoveThumbBarButton, "RemoveThumbBarButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "button", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TaskBarButton, __RemoveThumbBarButton)
{
	Object_wx_TaskBarButton *pThis = Object_wx_TaskBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxThumbBarButton* button = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveThumbBarButton();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TaskBarButton, __RemoveThumbBarButton_1, "RemoveThumbBarButton_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TaskBarButton, __RemoveThumbBarButton_1)
{
	Object_wx_TaskBarButton *pThis = Object_wx_TaskBarButton::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveThumbBarButton();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTaskBarButton
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TaskBarButton)
{
	// Class assignment
	Gura_AssignValueEx("TaskBarButton", Reference());
	// Method assignment
	Gura_AssignMethod(wx_TaskBarButton, __SetProgressRange);
	Gura_AssignMethod(wx_TaskBarButton, __SetProgressValue);
	Gura_AssignMethod(wx_TaskBarButton, __PulseProgress);
	Gura_AssignMethod(wx_TaskBarButton, __Show);
	Gura_AssignMethod(wx_TaskBarButton, __Hide);
	Gura_AssignMethod(wx_TaskBarButton, __SetThumbnailTooltip);
	Gura_AssignMethod(wx_TaskBarButton, __SetProgressState);
	Gura_AssignMethod(wx_TaskBarButton, __SetOverlayIcon);
	Gura_AssignMethod(wx_TaskBarButton, __SetThumbnailClip);
	Gura_AssignMethod(wx_TaskBarButton, __SetThumbnailContents);
	Gura_AssignMethod(wx_TaskBarButton, __InsertThumbBarButton);
	Gura_AssignMethod(wx_TaskBarButton, __AppendThumbBarButton);
	Gura_AssignMethod(wx_TaskBarButton, __AppendSeparatorInThumbBar);
	Gura_AssignMethod(wx_TaskBarButton, __RemoveThumbBarButton);
	Gura_AssignMethod(wx_TaskBarButton, __RemoveThumbBarButton_1);
}

Gura_ImplementDescendantCreator(wx_TaskBarButton)
{
	return new Object_wx_TaskBarButton((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
