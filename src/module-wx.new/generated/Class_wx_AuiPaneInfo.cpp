//----------------------------------------------------------------------------
// wxAuiPaneInfo
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAuiPaneInfo
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAuiPaneInfo
//----------------------------------------------------------------------------
Object_wx_AuiPaneInfo::~Object_wx_AuiPaneInfo()
{
}

Object *Object_wx_AuiPaneInfo::Clone() const
{
	return nullptr;
}

String Object_wx_AuiPaneInfo::ToString(bool exprFlag)
{
	String rtn("<wx.AuiPaneInfo:");
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
Gura_DeclareMethod(wx_AuiPaneInfo, wxAuiPaneInfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, wxAuiPaneInfo)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxAuiPaneInfo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, wxAuiPaneInfo_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, wxAuiPaneInfo_1)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int c = arg.GetNumber(0)
	//pThis->GetEntity()->wxAuiPaneInfo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, BestSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, BestSize)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->BestSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, BestSize_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, BestSize_1)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->BestSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, Bottom)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Bottom)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Bottom();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, BottomDockable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, BottomDockable)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int b = arg.GetNumber(0)
	//pThis->GetEntity()->BottomDockable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, Caption)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Caption)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int c = arg.GetNumber(0)
	//pThis->GetEntity()->Caption();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, CaptionVisible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "visible", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, CaptionVisible)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int visible = arg.GetNumber(0)
	//pThis->GetEntity()->CaptionVisible();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, Centre)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Centre)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Centre();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, Center)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Center)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Center();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, CentrePane)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, CentrePane)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CentrePane();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, CenterPane)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, CenterPane)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CenterPane();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, CloseButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "visible", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, CloseButton)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int visible = arg.GetNumber(0)
	//pThis->GetEntity()->CloseButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, DefaultPane)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, DefaultPane)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DefaultPane();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, DestroyOnClose)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, DestroyOnClose)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int b = arg.GetNumber(0)
	//pThis->GetEntity()->DestroyOnClose();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, Direction)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "direction", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Direction)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int direction = arg.GetNumber(0)
	//pThis->GetEntity()->Direction();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, Dock)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Dock)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Dock();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, DockFixed)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, DockFixed)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int b = arg.GetNumber(0)
	//pThis->GetEntity()->DockFixed();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, Dockable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Dockable)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int b = arg.GetNumber(0)
	//pThis->GetEntity()->Dockable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, Fixed)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Fixed)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Fixed();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, Float)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Float)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Float();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, Floatable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Floatable)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int b = arg.GetNumber(0)
	//pThis->GetEntity()->Floatable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, FloatingPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, FloatingPosition)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->FloatingPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, FloatingPosition_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, FloatingPosition_1)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->FloatingPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, FloatingSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, FloatingSize)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->FloatingSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, FloatingSize_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, FloatingSize_1)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->FloatingSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, Gripper)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "visible", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Gripper)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int visible = arg.GetNumber(0)
	//pThis->GetEntity()->Gripper();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, GripperTop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attop", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, GripperTop)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int attop = arg.GetNumber(0)
	//pThis->GetEntity()->GripperTop();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, HasBorder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, HasBorder)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasBorder();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, HasCaption)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, HasCaption)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasCaption();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, HasCloseButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, HasCloseButton)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasCloseButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, HasFlag)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, HasFlag)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->HasFlag();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, HasGripper)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, HasGripper)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasGripper();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, HasGripperTop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, HasGripperTop)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasGripperTop();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, HasMaximizeButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, HasMaximizeButton)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasMaximizeButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, HasMinimizeButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, HasMinimizeButton)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasMinimizeButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, HasPinButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, HasPinButton)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasPinButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, Hide)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Hide)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Hide();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, Icon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Icon)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int b = arg.GetNumber(0)
	//pThis->GetEntity()->Icon();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, IsBottomDockable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, IsBottomDockable)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsBottomDockable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, IsDockable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, IsDockable)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsDockable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, IsDocked)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, IsDocked)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsDocked();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, IsFixed)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, IsFixed)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsFixed();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, IsFloatable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, IsFloatable)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsFloatable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, IsFloating)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, IsFloating)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsFloating();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, IsLeftDockable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, IsLeftDockable)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsLeftDockable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, IsMovable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, IsMovable)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsMovable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, IsOk)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, IsResizable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, IsResizable)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsResizable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, IsRightDockable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, IsRightDockable)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsRightDockable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, IsShown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, IsShown)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsShown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, IsToolbar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, IsToolbar)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsToolbar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, IsTopDockable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, IsTopDockable)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsTopDockable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, Layer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "layer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Layer)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int layer = arg.GetNumber(0)
	//pThis->GetEntity()->Layer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, Left)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Left)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Left();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, LeftDockable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, LeftDockable)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int b = arg.GetNumber(0)
	//pThis->GetEntity()->LeftDockable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, MaxSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, MaxSize)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->MaxSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, MaxSize_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, MaxSize_1)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->MaxSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, MaximizeButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "visible", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, MaximizeButton)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int visible = arg.GetNumber(0)
	//pThis->GetEntity()->MaximizeButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, MinSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, MinSize)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->MinSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, MinSize_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, MinSize_1)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->MinSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, MinimizeButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "visible", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, MinimizeButton)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int visible = arg.GetNumber(0)
	//pThis->GetEntity()->MinimizeButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, Movable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Movable)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int b = arg.GetNumber(0)
	//pThis->GetEntity()->Movable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, Name)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Name)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->Name();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, PaneBorder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "visible", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, PaneBorder)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int visible = arg.GetNumber(0)
	//pThis->GetEntity()->PaneBorder();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, PinButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "visible", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, PinButton)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int visible = arg.GetNumber(0)
	//pThis->GetEntity()->PinButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, Position)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Position)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->Position();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, Resizable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "resizable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Resizable)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int resizable = arg.GetNumber(0)
	//pThis->GetEntity()->Resizable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, Right)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Right)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Right();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, RightDockable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, RightDockable)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int b = arg.GetNumber(0)
	//pThis->GetEntity()->RightDockable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, Row)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Row)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//pThis->GetEntity()->Row();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, SafeSet)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "source", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, SafeSet)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int source = arg.GetNumber(0)
	//pThis->GetEntity()->SafeSet();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, SetFlag)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "option_state", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, SetFlag)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//int option_state = arg.GetNumber(1)
	//pThis->GetEntity()->SetFlag();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, Show)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "show", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Show)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int show = arg.GetNumber(0)
	//pThis->GetEntity()->Show();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, ToolbarPane)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, ToolbarPane)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ToolbarPane();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, Top)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Top)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Top();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, TopDockable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, TopDockable)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int b = arg.GetNumber(0)
	//pThis->GetEntity()->TopDockable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiPaneInfo, Window)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, Window)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int w = arg.GetNumber(0)
	//pThis->GetEntity()->Window();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxAuiPaneInfo
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AuiPaneInfo)
{
	Gura_AssignMethod(wx_AuiPaneInfo, wxAuiPaneInfo);
	Gura_AssignMethod(wx_AuiPaneInfo, wxAuiPaneInfo_1);
	Gura_AssignMethod(wx_AuiPaneInfo, BestSize);
	Gura_AssignMethod(wx_AuiPaneInfo, BestSize_1);
	Gura_AssignMethod(wx_AuiPaneInfo, Bottom);
	Gura_AssignMethod(wx_AuiPaneInfo, BottomDockable);
	Gura_AssignMethod(wx_AuiPaneInfo, Caption);
	Gura_AssignMethod(wx_AuiPaneInfo, CaptionVisible);
	Gura_AssignMethod(wx_AuiPaneInfo, Centre);
	Gura_AssignMethod(wx_AuiPaneInfo, Center);
	Gura_AssignMethod(wx_AuiPaneInfo, CentrePane);
	Gura_AssignMethod(wx_AuiPaneInfo, CenterPane);
	Gura_AssignMethod(wx_AuiPaneInfo, CloseButton);
	Gura_AssignMethod(wx_AuiPaneInfo, DefaultPane);
	Gura_AssignMethod(wx_AuiPaneInfo, DestroyOnClose);
	Gura_AssignMethod(wx_AuiPaneInfo, Direction);
	Gura_AssignMethod(wx_AuiPaneInfo, Dock);
	Gura_AssignMethod(wx_AuiPaneInfo, DockFixed);
	Gura_AssignMethod(wx_AuiPaneInfo, Dockable);
	Gura_AssignMethod(wx_AuiPaneInfo, Fixed);
	Gura_AssignMethod(wx_AuiPaneInfo, Float);
	Gura_AssignMethod(wx_AuiPaneInfo, Floatable);
	Gura_AssignMethod(wx_AuiPaneInfo, FloatingPosition);
	Gura_AssignMethod(wx_AuiPaneInfo, FloatingPosition_1);
	Gura_AssignMethod(wx_AuiPaneInfo, FloatingSize);
	Gura_AssignMethod(wx_AuiPaneInfo, FloatingSize_1);
	Gura_AssignMethod(wx_AuiPaneInfo, Gripper);
	Gura_AssignMethod(wx_AuiPaneInfo, GripperTop);
	Gura_AssignMethod(wx_AuiPaneInfo, HasBorder);
	Gura_AssignMethod(wx_AuiPaneInfo, HasCaption);
	Gura_AssignMethod(wx_AuiPaneInfo, HasCloseButton);
	Gura_AssignMethod(wx_AuiPaneInfo, HasFlag);
	Gura_AssignMethod(wx_AuiPaneInfo, HasGripper);
	Gura_AssignMethod(wx_AuiPaneInfo, HasGripperTop);
	Gura_AssignMethod(wx_AuiPaneInfo, HasMaximizeButton);
	Gura_AssignMethod(wx_AuiPaneInfo, HasMinimizeButton);
	Gura_AssignMethod(wx_AuiPaneInfo, HasPinButton);
	Gura_AssignMethod(wx_AuiPaneInfo, Hide);
	Gura_AssignMethod(wx_AuiPaneInfo, Icon);
	Gura_AssignMethod(wx_AuiPaneInfo, IsBottomDockable);
	Gura_AssignMethod(wx_AuiPaneInfo, IsDockable);
	Gura_AssignMethod(wx_AuiPaneInfo, IsDocked);
	Gura_AssignMethod(wx_AuiPaneInfo, IsFixed);
	Gura_AssignMethod(wx_AuiPaneInfo, IsFloatable);
	Gura_AssignMethod(wx_AuiPaneInfo, IsFloating);
	Gura_AssignMethod(wx_AuiPaneInfo, IsLeftDockable);
	Gura_AssignMethod(wx_AuiPaneInfo, IsMovable);
	Gura_AssignMethod(wx_AuiPaneInfo, IsOk);
	Gura_AssignMethod(wx_AuiPaneInfo, IsResizable);
	Gura_AssignMethod(wx_AuiPaneInfo, IsRightDockable);
	Gura_AssignMethod(wx_AuiPaneInfo, IsShown);
	Gura_AssignMethod(wx_AuiPaneInfo, IsToolbar);
	Gura_AssignMethod(wx_AuiPaneInfo, IsTopDockable);
	Gura_AssignMethod(wx_AuiPaneInfo, Layer);
	Gura_AssignMethod(wx_AuiPaneInfo, Left);
	Gura_AssignMethod(wx_AuiPaneInfo, LeftDockable);
	Gura_AssignMethod(wx_AuiPaneInfo, MaxSize);
	Gura_AssignMethod(wx_AuiPaneInfo, MaxSize_1);
	Gura_AssignMethod(wx_AuiPaneInfo, MaximizeButton);
	Gura_AssignMethod(wx_AuiPaneInfo, MinSize);
	Gura_AssignMethod(wx_AuiPaneInfo, MinSize_1);
	Gura_AssignMethod(wx_AuiPaneInfo, MinimizeButton);
	Gura_AssignMethod(wx_AuiPaneInfo, Movable);
	Gura_AssignMethod(wx_AuiPaneInfo, Name);
	Gura_AssignMethod(wx_AuiPaneInfo, PaneBorder);
	Gura_AssignMethod(wx_AuiPaneInfo, PinButton);
	Gura_AssignMethod(wx_AuiPaneInfo, Position);
	Gura_AssignMethod(wx_AuiPaneInfo, Resizable);
	Gura_AssignMethod(wx_AuiPaneInfo, Right);
	Gura_AssignMethod(wx_AuiPaneInfo, RightDockable);
	Gura_AssignMethod(wx_AuiPaneInfo, Row);
	Gura_AssignMethod(wx_AuiPaneInfo, SafeSet);
	Gura_AssignMethod(wx_AuiPaneInfo, SetFlag);
	Gura_AssignMethod(wx_AuiPaneInfo, Show);
	Gura_AssignMethod(wx_AuiPaneInfo, ToolbarPane);
	Gura_AssignMethod(wx_AuiPaneInfo, Top);
	Gura_AssignMethod(wx_AuiPaneInfo, TopDockable);
	Gura_AssignMethod(wx_AuiPaneInfo, Window);
}

Gura_ImplementDescendantCreator(wx_AuiPaneInfo)
{
	return new Object_wx_AuiPaneInfo((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
