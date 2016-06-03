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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__AuiPaneInfo, "AuiPaneInfo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_AuiPaneInfo));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__AuiPaneInfo)
{
	//wxAuiPaneInfo();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__AuiPaneInfo_1, "AuiPaneInfo_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_AuiPaneInfo));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__AuiPaneInfo_1)
{
	//const wxAuiPaneInfo& c = arg.GetNumber(0)
	//wxAuiPaneInfo();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_AuiPaneInfo, __BestSize, "BestSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __BestSize)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxSize& size = arg.GetNumber(0)
	//pThis->GetEntity()->BestSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __BestSize_1, "BestSize_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __BestSize_1)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->BestSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __Bottom, "Bottom")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __Bottom)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Bottom();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __BottomDockable, "BottomDockable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __BottomDockable)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool b = arg.GetNumber(0)
	//pThis->GetEntity()->BottomDockable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __Caption, "Caption")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __Caption)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& c = arg.GetNumber(0)
	//pThis->GetEntity()->Caption();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __CaptionVisible, "CaptionVisible")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "visible", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __CaptionVisible)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool visible = arg.GetNumber(0)
	//pThis->GetEntity()->CaptionVisible();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __Centre, "Centre")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __Centre)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Centre();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __Center, "Center")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __Center)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Center();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __CentrePane, "CentrePane")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __CentrePane)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CentrePane();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __CenterPane, "CenterPane")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __CenterPane)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CenterPane();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __CloseButton, "CloseButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "visible", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __CloseButton)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool visible = arg.GetNumber(0)
	//pThis->GetEntity()->CloseButton();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __DefaultPane, "DefaultPane")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __DefaultPane)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DefaultPane();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __DestroyOnClose, "DestroyOnClose")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __DestroyOnClose)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool b = arg.GetNumber(0)
	//pThis->GetEntity()->DestroyOnClose();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __Direction, "Direction")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "direction", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __Direction)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int direction = arg.GetNumber(0)
	//pThis->GetEntity()->Direction();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __Dock, "Dock")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __Dock)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Dock();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __DockFixed, "DockFixed")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __DockFixed)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool b = arg.GetNumber(0)
	//pThis->GetEntity()->DockFixed();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __Dockable, "Dockable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __Dockable)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool b = arg.GetNumber(0)
	//pThis->GetEntity()->Dockable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __Fixed, "Fixed")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __Fixed)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Fixed();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __Float, "Float")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __Float)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Float();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __Floatable, "Floatable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __Floatable)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool b = arg.GetNumber(0)
	//pThis->GetEntity()->Floatable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __FloatingPosition, "FloatingPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __FloatingPosition)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxPoint& pos = arg.GetNumber(0)
	//pThis->GetEntity()->FloatingPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __FloatingPosition_1, "FloatingPosition_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __FloatingPosition_1)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->FloatingPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __FloatingSize, "FloatingSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __FloatingSize)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxSize& size = arg.GetNumber(0)
	//pThis->GetEntity()->FloatingSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __FloatingSize_1, "FloatingSize_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __FloatingSize_1)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->FloatingSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __Gripper, "Gripper")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "visible", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __Gripper)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool visible = arg.GetNumber(0)
	//pThis->GetEntity()->Gripper();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __GripperTop, "GripperTop")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attop", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __GripperTop)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool attop = arg.GetNumber(0)
	//pThis->GetEntity()->GripperTop();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __HasBorder, "HasBorder")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __HasBorder)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasBorder();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __HasCaption, "HasCaption")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __HasCaption)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasCaption();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __HasCloseButton, "HasCloseButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __HasCloseButton)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasCloseButton();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __HasFlag, "HasFlag")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __HasFlag)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->HasFlag();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __HasGripper, "HasGripper")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __HasGripper)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasGripper();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __HasGripperTop, "HasGripperTop")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __HasGripperTop)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasGripperTop();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __HasMaximizeButton, "HasMaximizeButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __HasMaximizeButton)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasMaximizeButton();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __HasMinimizeButton, "HasMinimizeButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __HasMinimizeButton)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasMinimizeButton();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __HasPinButton, "HasPinButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __HasPinButton)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasPinButton();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __Hide, "Hide")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __Hide)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Hide();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __Icon, "Icon")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __Icon)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxBitmap& b = arg.GetNumber(0)
	//pThis->GetEntity()->Icon();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __IsBottomDockable, "IsBottomDockable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __IsBottomDockable)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsBottomDockable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __IsDockable, "IsDockable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __IsDockable)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsDockable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __IsDocked, "IsDocked")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __IsDocked)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsDocked();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __IsFixed, "IsFixed")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __IsFixed)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsFixed();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __IsFloatable, "IsFloatable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __IsFloatable)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsFloatable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __IsFloating, "IsFloating")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __IsFloating)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsFloating();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __IsLeftDockable, "IsLeftDockable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __IsLeftDockable)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsLeftDockable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __IsMovable, "IsMovable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __IsMovable)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsMovable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __IsOk, "IsOk")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __IsOk)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __IsResizable, "IsResizable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __IsResizable)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsResizable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __IsRightDockable, "IsRightDockable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __IsRightDockable)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsRightDockable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __IsShown, "IsShown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __IsShown)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsShown();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __IsToolbar, "IsToolbar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __IsToolbar)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsToolbar();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __IsTopDockable, "IsTopDockable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __IsTopDockable)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsTopDockable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __Layer, "Layer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "layer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __Layer)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int layer = arg.GetNumber(0)
	//pThis->GetEntity()->Layer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __Left, "Left")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __Left)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Left();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __LeftDockable, "LeftDockable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __LeftDockable)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool b = arg.GetNumber(0)
	//pThis->GetEntity()->LeftDockable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __MaxSize, "MaxSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __MaxSize)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxSize& size = arg.GetNumber(0)
	//pThis->GetEntity()->MaxSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __MaxSize_1, "MaxSize_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __MaxSize_1)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->MaxSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __MaximizeButton, "MaximizeButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "visible", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __MaximizeButton)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool visible = arg.GetNumber(0)
	//pThis->GetEntity()->MaximizeButton();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __MinSize, "MinSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __MinSize)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxSize& size = arg.GetNumber(0)
	//pThis->GetEntity()->MinSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __MinSize_1, "MinSize_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __MinSize_1)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->MinSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __MinimizeButton, "MinimizeButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "visible", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __MinimizeButton)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool visible = arg.GetNumber(0)
	//pThis->GetEntity()->MinimizeButton();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __Movable, "Movable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __Movable)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool b = arg.GetNumber(0)
	//pThis->GetEntity()->Movable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __Name, "Name")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __Name)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& n = arg.GetNumber(0)
	//pThis->GetEntity()->Name();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __PaneBorder, "PaneBorder")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "visible", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __PaneBorder)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool visible = arg.GetNumber(0)
	//pThis->GetEntity()->PaneBorder();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __PinButton, "PinButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "visible", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __PinButton)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool visible = arg.GetNumber(0)
	//pThis->GetEntity()->PinButton();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __Position, "Position")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __Position)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->Position();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __Resizable, "Resizable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "resizable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __Resizable)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool resizable = arg.GetNumber(0)
	//pThis->GetEntity()->Resizable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __Right, "Right")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __Right)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Right();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __RightDockable, "RightDockable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __RightDockable)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool b = arg.GetNumber(0)
	//pThis->GetEntity()->RightDockable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __Row, "Row")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __Row)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//pThis->GetEntity()->Row();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __SafeSet, "SafeSet")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "source", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __SafeSet)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxAuiPaneInfo source = arg.GetNumber(0)
	//pThis->GetEntity()->SafeSet();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __SetFlag, "SetFlag")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "option_state", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __SetFlag)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//bool option_state = arg.GetNumber(1)
	//pThis->GetEntity()->SetFlag();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __Show, "Show")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "show", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __Show)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool show = arg.GetNumber(0)
	//pThis->GetEntity()->Show();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __ToolbarPane, "ToolbarPane")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __ToolbarPane)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ToolbarPane();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __Top, "Top")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __Top)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Top();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __TopDockable, "TopDockable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "b", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __TopDockable)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool b = arg.GetNumber(0)
	//pThis->GetEntity()->TopDockable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiPaneInfo, __Window, "Window")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiPaneInfo, __Window)
{
	Object_wx_AuiPaneInfo *pThis = Object_wx_AuiPaneInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* w = arg.GetNumber(0)
	//pThis->GetEntity()->Window();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxAuiPaneInfo
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AuiPaneInfo)
{
	// Constructor assignment
	Gura_AssignFunction(__AuiPaneInfo);
	Gura_AssignFunction(__AuiPaneInfo_1);
	// Method assignment
	Gura_AssignMethod(wx_AuiPaneInfo, __BestSize);
	Gura_AssignMethod(wx_AuiPaneInfo, __BestSize_1);
	Gura_AssignMethod(wx_AuiPaneInfo, __Bottom);
	Gura_AssignMethod(wx_AuiPaneInfo, __BottomDockable);
	Gura_AssignMethod(wx_AuiPaneInfo, __Caption);
	Gura_AssignMethod(wx_AuiPaneInfo, __CaptionVisible);
	Gura_AssignMethod(wx_AuiPaneInfo, __Centre);
	Gura_AssignMethod(wx_AuiPaneInfo, __Center);
	Gura_AssignMethod(wx_AuiPaneInfo, __CentrePane);
	Gura_AssignMethod(wx_AuiPaneInfo, __CenterPane);
	Gura_AssignMethod(wx_AuiPaneInfo, __CloseButton);
	Gura_AssignMethod(wx_AuiPaneInfo, __DefaultPane);
	Gura_AssignMethod(wx_AuiPaneInfo, __DestroyOnClose);
	Gura_AssignMethod(wx_AuiPaneInfo, __Direction);
	Gura_AssignMethod(wx_AuiPaneInfo, __Dock);
	Gura_AssignMethod(wx_AuiPaneInfo, __DockFixed);
	Gura_AssignMethod(wx_AuiPaneInfo, __Dockable);
	Gura_AssignMethod(wx_AuiPaneInfo, __Fixed);
	Gura_AssignMethod(wx_AuiPaneInfo, __Float);
	Gura_AssignMethod(wx_AuiPaneInfo, __Floatable);
	Gura_AssignMethod(wx_AuiPaneInfo, __FloatingPosition);
	Gura_AssignMethod(wx_AuiPaneInfo, __FloatingPosition_1);
	Gura_AssignMethod(wx_AuiPaneInfo, __FloatingSize);
	Gura_AssignMethod(wx_AuiPaneInfo, __FloatingSize_1);
	Gura_AssignMethod(wx_AuiPaneInfo, __Gripper);
	Gura_AssignMethod(wx_AuiPaneInfo, __GripperTop);
	Gura_AssignMethod(wx_AuiPaneInfo, __HasBorder);
	Gura_AssignMethod(wx_AuiPaneInfo, __HasCaption);
	Gura_AssignMethod(wx_AuiPaneInfo, __HasCloseButton);
	Gura_AssignMethod(wx_AuiPaneInfo, __HasFlag);
	Gura_AssignMethod(wx_AuiPaneInfo, __HasGripper);
	Gura_AssignMethod(wx_AuiPaneInfo, __HasGripperTop);
	Gura_AssignMethod(wx_AuiPaneInfo, __HasMaximizeButton);
	Gura_AssignMethod(wx_AuiPaneInfo, __HasMinimizeButton);
	Gura_AssignMethod(wx_AuiPaneInfo, __HasPinButton);
	Gura_AssignMethod(wx_AuiPaneInfo, __Hide);
	Gura_AssignMethod(wx_AuiPaneInfo, __Icon);
	Gura_AssignMethod(wx_AuiPaneInfo, __IsBottomDockable);
	Gura_AssignMethod(wx_AuiPaneInfo, __IsDockable);
	Gura_AssignMethod(wx_AuiPaneInfo, __IsDocked);
	Gura_AssignMethod(wx_AuiPaneInfo, __IsFixed);
	Gura_AssignMethod(wx_AuiPaneInfo, __IsFloatable);
	Gura_AssignMethod(wx_AuiPaneInfo, __IsFloating);
	Gura_AssignMethod(wx_AuiPaneInfo, __IsLeftDockable);
	Gura_AssignMethod(wx_AuiPaneInfo, __IsMovable);
	Gura_AssignMethod(wx_AuiPaneInfo, __IsOk);
	Gura_AssignMethod(wx_AuiPaneInfo, __IsResizable);
	Gura_AssignMethod(wx_AuiPaneInfo, __IsRightDockable);
	Gura_AssignMethod(wx_AuiPaneInfo, __IsShown);
	Gura_AssignMethod(wx_AuiPaneInfo, __IsToolbar);
	Gura_AssignMethod(wx_AuiPaneInfo, __IsTopDockable);
	Gura_AssignMethod(wx_AuiPaneInfo, __Layer);
	Gura_AssignMethod(wx_AuiPaneInfo, __Left);
	Gura_AssignMethod(wx_AuiPaneInfo, __LeftDockable);
	Gura_AssignMethod(wx_AuiPaneInfo, __MaxSize);
	Gura_AssignMethod(wx_AuiPaneInfo, __MaxSize_1);
	Gura_AssignMethod(wx_AuiPaneInfo, __MaximizeButton);
	Gura_AssignMethod(wx_AuiPaneInfo, __MinSize);
	Gura_AssignMethod(wx_AuiPaneInfo, __MinSize_1);
	Gura_AssignMethod(wx_AuiPaneInfo, __MinimizeButton);
	Gura_AssignMethod(wx_AuiPaneInfo, __Movable);
	Gura_AssignMethod(wx_AuiPaneInfo, __Name);
	Gura_AssignMethod(wx_AuiPaneInfo, __PaneBorder);
	Gura_AssignMethod(wx_AuiPaneInfo, __PinButton);
	Gura_AssignMethod(wx_AuiPaneInfo, __Position);
	Gura_AssignMethod(wx_AuiPaneInfo, __Resizable);
	Gura_AssignMethod(wx_AuiPaneInfo, __Right);
	Gura_AssignMethod(wx_AuiPaneInfo, __RightDockable);
	Gura_AssignMethod(wx_AuiPaneInfo, __Row);
	Gura_AssignMethod(wx_AuiPaneInfo, __SafeSet);
	Gura_AssignMethod(wx_AuiPaneInfo, __SetFlag);
	Gura_AssignMethod(wx_AuiPaneInfo, __Show);
	Gura_AssignMethod(wx_AuiPaneInfo, __ToolbarPane);
	Gura_AssignMethod(wx_AuiPaneInfo, __Top);
	Gura_AssignMethod(wx_AuiPaneInfo, __TopDockable);
	Gura_AssignMethod(wx_AuiPaneInfo, __Window);
}

Gura_ImplementDescendantCreator(wx_AuiPaneInfo)
{
	return new Object_wx_AuiPaneInfo((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
