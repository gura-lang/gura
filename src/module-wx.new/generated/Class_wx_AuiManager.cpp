//----------------------------------------------------------------------------
// wxAuiManager
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAuiManager
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAuiManager
//----------------------------------------------------------------------------
Object_wx_AuiManager::~Object_wx_AuiManager()
{
}

Object *Object_wx_AuiManager::Clone() const
{
	return nullptr;
}

String Object_wx_AuiManager::ToString(bool exprFlag)
{
	String rtn("<wx.AuiManager:");
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
Gura_DeclareFunctionAlias(__AuiManager, "AuiManager")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "managed_wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_AuiManager));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__AuiManager)
{
	//wxWindow* managed_wnd = arg.GetNumber(0)
	//unsigned int flags = arg.GetNumber(1)
	//wxAuiManager();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_AuiManager, __AddPane, "AddPane")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pane_info", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManager, __AddPane)
{
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* window = arg.GetNumber(0)
	//const wxAuiPaneInfo& pane_info = arg.GetNumber(1)
	//pThis->GetEntity()->AddPane();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiManager, __AddPane_1, "AddPane_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "direction", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "caption", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManager, __AddPane_1)
{
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* window = arg.GetNumber(0)
	//int direction = arg.GetNumber(1)
	//const wxString& caption = arg.GetNumber(2)
	//pThis->GetEntity()->AddPane();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiManager, __AddPane_2, "AddPane_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pane_info", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "drop_pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManager, __AddPane_2)
{
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* window = arg.GetNumber(0)
	//const wxAuiPaneInfo& pane_info = arg.GetNumber(1)
	//const wxPoint& drop_pos = arg.GetNumber(2)
	//pThis->GetEntity()->AddPane();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiManager, __DetachPane, "DetachPane")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManager, __DetachPane)
{
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* window = arg.GetNumber(0)
	//pThis->GetEntity()->DetachPane();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiManager, __GetAllPanes, "GetAllPanes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiManager, __GetAllPanes)
{
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAllPanes();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiManager, __GetArtProvider, "GetArtProvider")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiManager, __GetArtProvider)
{
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetArtProvider();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiManager, __GetDockSizeConstraint, "GetDockSizeConstraint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "widthpct", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "heightpct", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManager, __GetDockSizeConstraint)
{
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//double* widthpct = arg.GetNumber(0)
	//double* heightpct = arg.GetNumber(1)
	//pThis->GetEntity()->GetDockSizeConstraint();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiManager, __GetFlags, "GetFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiManager, __GetFlags)
{
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFlags();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiManager, __GetManagedWindow, "GetManagedWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiManager, __GetManagedWindow)
{
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetManagedWindow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiManager, __GetManager, "GetManager")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManager, __GetManager)
{
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* window = arg.GetNumber(0)
	//pThis->GetEntity()->GetManager();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiManager, __GetPane, "GetPane")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManager, __GetPane)
{
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* window = arg.GetNumber(0)
	//pThis->GetEntity()->GetPane();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiManager, __GetPane_1, "GetPane_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManager, __GetPane_1)
{
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//pThis->GetEntity()->GetPane();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiManager, __HideHint, "HideHint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiManager, __HideHint)
{
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HideHint();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiManager, __InsertPane, "InsertPane")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "insert_location", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "insert_level", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManager, __InsertPane)
{
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* window = arg.GetNumber(0)
	//const wxAuiPaneInfo& insert_location = arg.GetNumber(1)
	//int insert_level = arg.GetNumber(2)
	//pThis->GetEntity()->InsertPane();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiManager, __LoadPaneInfo, "LoadPaneInfo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pane_part", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pane", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManager, __LoadPaneInfo)
{
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString pane_part = arg.GetNumber(0)
	//wxAuiPaneInfo& pane = arg.GetNumber(1)
	//pThis->GetEntity()->LoadPaneInfo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiManager, __LoadPerspective, "LoadPerspective")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "perspective", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "update", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManager, __LoadPerspective)
{
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& perspective = arg.GetNumber(0)
	//bool update = arg.GetNumber(1)
	//pThis->GetEntity()->LoadPerspective();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiManager, __SavePaneInfo, "SavePaneInfo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pane", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManager, __SavePaneInfo)
{
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxAuiPaneInfo& pane = arg.GetNumber(0)
	//pThis->GetEntity()->SavePaneInfo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiManager, __SavePerspective, "SavePerspective")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiManager, __SavePerspective)
{
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->SavePerspective();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiManager, __SetArtProvider, "SetArtProvider")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "art_provider", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManager, __SetArtProvider)
{
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxAuiDockArt* art_provider = arg.GetNumber(0)
	//pThis->GetEntity()->SetArtProvider();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiManager, __SetDockSizeConstraint, "SetDockSizeConstraint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "widthpct", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "heightpct", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManager, __SetDockSizeConstraint)
{
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//double widthpct = arg.GetNumber(0)
	//double heightpct = arg.GetNumber(1)
	//pThis->GetEntity()->SetDockSizeConstraint();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiManager, __SetFlags, "SetFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManager, __SetFlags)
{
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int flags = arg.GetNumber(0)
	//pThis->GetEntity()->SetFlags();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiManager, __SetManagedWindow, "SetManagedWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "managed_wnd", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManager, __SetManagedWindow)
{
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* managed_wnd = arg.GetNumber(0)
	//pThis->GetEntity()->SetManagedWindow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiManager, __ShowHint, "ShowHint")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManager, __ShowHint)
{
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRect& rect = arg.GetNumber(0)
	//pThis->GetEntity()->ShowHint();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiManager, __UnInit, "UnInit")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiManager, __UnInit)
{
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->UnInit();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiManager, __Update, "Update")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiManager, __Update)
{
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Update();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiManager, __ProcessDockResult, "ProcessDockResult")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "target", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "new_pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManager, __ProcessDockResult)
{
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxAuiPaneInfo& target = arg.GetNumber(0)
	//const wxAuiPaneInfo& new_pos = arg.GetNumber(1)
	//pThis->GetEntity()->ProcessDockResult();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxAuiManager
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AuiManager)
{
	// Constructor assignment
	Gura_AssignFunction(__AuiManager);
	// Method assignment
	Gura_AssignMethod(wx_AuiManager, __AddPane);
	Gura_AssignMethod(wx_AuiManager, __AddPane_1);
	Gura_AssignMethod(wx_AuiManager, __AddPane_2);
	Gura_AssignMethod(wx_AuiManager, __DetachPane);
	Gura_AssignMethod(wx_AuiManager, __GetAllPanes);
	Gura_AssignMethod(wx_AuiManager, __GetArtProvider);
	Gura_AssignMethod(wx_AuiManager, __GetDockSizeConstraint);
	Gura_AssignMethod(wx_AuiManager, __GetFlags);
	Gura_AssignMethod(wx_AuiManager, __GetManagedWindow);
	Gura_AssignMethod(wx_AuiManager, __GetManager);
	Gura_AssignMethod(wx_AuiManager, __GetPane);
	Gura_AssignMethod(wx_AuiManager, __GetPane_1);
	Gura_AssignMethod(wx_AuiManager, __HideHint);
	Gura_AssignMethod(wx_AuiManager, __InsertPane);
	Gura_AssignMethod(wx_AuiManager, __LoadPaneInfo);
	Gura_AssignMethod(wx_AuiManager, __LoadPerspective);
	Gura_AssignMethod(wx_AuiManager, __SavePaneInfo);
	Gura_AssignMethod(wx_AuiManager, __SavePerspective);
	Gura_AssignMethod(wx_AuiManager, __SetArtProvider);
	Gura_AssignMethod(wx_AuiManager, __SetDockSizeConstraint);
	Gura_AssignMethod(wx_AuiManager, __SetFlags);
	Gura_AssignMethod(wx_AuiManager, __SetManagedWindow);
	Gura_AssignMethod(wx_AuiManager, __ShowHint);
	Gura_AssignMethod(wx_AuiManager, __UnInit);
	Gura_AssignMethod(wx_AuiManager, __Update);
	Gura_AssignMethod(wx_AuiManager, __ProcessDockResult);
}

Gura_ImplementDescendantCreator(wx_AuiManager)
{
	return new Object_wx_AuiManager((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
