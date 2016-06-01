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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_AuiManager, wxAuiManager)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "managed_wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManager, wxAuiManager)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int managed_wnd = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->wxAuiManager();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiManager, ~wxAuiManager)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiManager, ~wxAuiManager)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxAuiManager();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiManager, AddPane)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pane_info", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManager, AddPane)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//int pane_info = arg.GetNumber(1)
	//pThis->GetEntity()->AddPane();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiManager, AddPane_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "direction", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "caption", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManager, AddPane_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//int direction = arg.GetNumber(1)
	//int caption = arg.GetNumber(2)
	//pThis->GetEntity()->AddPane();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiManager, AddPane_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pane_info", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "drop_pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManager, AddPane_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//int pane_info = arg.GetNumber(1)
	//int drop_pos = arg.GetNumber(2)
	//pThis->GetEntity()->AddPane();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiManager, DetachPane)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManager, DetachPane)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//pThis->GetEntity()->DetachPane();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiManager, GetAllPanes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiManager, GetAllPanes)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetAllPanes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiManager, GetArtProvider)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiManager, GetArtProvider)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetArtProvider();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiManager, GetDockSizeConstraint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "widthpct", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "heightpct", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManager, GetDockSizeConstraint)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int widthpct = arg.GetNumber(0)
	//int heightpct = arg.GetNumber(1)
	//pThis->GetEntity()->GetDockSizeConstraint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiManager, GetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiManager, GetFlags)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiManager, GetManagedWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiManager, GetManagedWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetManagedWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiManager, GetManager)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManager, GetManager)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//pThis->GetEntity()->GetManager();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiManager, GetPane)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManager, GetPane)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//pThis->GetEntity()->GetPane();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiManager, GetPane_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManager, GetPane_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->GetPane();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiManager, HideHint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiManager, HideHint)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HideHint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiManager, InsertPane)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "insert_location", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "insert_level", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManager, InsertPane)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//int insert_location = arg.GetNumber(1)
	//int insert_level = arg.GetNumber(2)
	//pThis->GetEntity()->InsertPane();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiManager, LoadPaneInfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pane_part", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pane", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManager, LoadPaneInfo)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pane_part = arg.GetNumber(0)
	//int pane = arg.GetNumber(1)
	//pThis->GetEntity()->LoadPaneInfo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiManager, LoadPerspective)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "perspective", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "update", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManager, LoadPerspective)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int perspective = arg.GetNumber(0)
	//int update = arg.GetNumber(1)
	//pThis->GetEntity()->LoadPerspective();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiManager, SavePaneInfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pane", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManager, SavePaneInfo)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pane = arg.GetNumber(0)
	//pThis->GetEntity()->SavePaneInfo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiManager, SavePerspective)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiManager, SavePerspective)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->SavePerspective();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiManager, SetArtProvider)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "art_provider", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManager, SetArtProvider)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int art_provider = arg.GetNumber(0)
	//pThis->GetEntity()->SetArtProvider();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiManager, SetDockSizeConstraint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "widthpct", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "heightpct", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManager, SetDockSizeConstraint)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int widthpct = arg.GetNumber(0)
	//int heightpct = arg.GetNumber(1)
	//pThis->GetEntity()->SetDockSizeConstraint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiManager, SetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManager, SetFlags)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->SetFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiManager, SetManagedWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "managed_wnd", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManager, SetManagedWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int managed_wnd = arg.GetNumber(0)
	//pThis->GetEntity()->SetManagedWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiManager, ShowHint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManager, ShowHint)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//pThis->GetEntity()->ShowHint();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiManager, UnInit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiManager, UnInit)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->UnInit();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiManager, Update)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiManager, Update)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Update();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiManager, ProcessDockResult)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "target", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "new_pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiManager, ProcessDockResult)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiManager *pThis = Object_wx_AuiManager::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int target = arg.GetNumber(0)
	//int new_pos = arg.GetNumber(1)
	//pThis->GetEntity()->ProcessDockResult();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxAuiManager
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AuiManager)
{
	Gura_AssignMethod(wx_AuiManager, wxAuiManager);
	Gura_AssignMethod(wx_AuiManager, ~wxAuiManager);
	Gura_AssignMethod(wx_AuiManager, AddPane);
	Gura_AssignMethod(wx_AuiManager, AddPane_1);
	Gura_AssignMethod(wx_AuiManager, AddPane_2);
	Gura_AssignMethod(wx_AuiManager, DetachPane);
	Gura_AssignMethod(wx_AuiManager, GetAllPanes);
	Gura_AssignMethod(wx_AuiManager, GetArtProvider);
	Gura_AssignMethod(wx_AuiManager, GetDockSizeConstraint);
	Gura_AssignMethod(wx_AuiManager, GetFlags);
	Gura_AssignMethod(wx_AuiManager, GetManagedWindow);
	Gura_AssignMethod(wx_AuiManager, GetManager);
	Gura_AssignMethod(wx_AuiManager, GetPane);
	Gura_AssignMethod(wx_AuiManager, GetPane_1);
	Gura_AssignMethod(wx_AuiManager, HideHint);
	Gura_AssignMethod(wx_AuiManager, InsertPane);
	Gura_AssignMethod(wx_AuiManager, LoadPaneInfo);
	Gura_AssignMethod(wx_AuiManager, LoadPerspective);
	Gura_AssignMethod(wx_AuiManager, SavePaneInfo);
	Gura_AssignMethod(wx_AuiManager, SavePerspective);
	Gura_AssignMethod(wx_AuiManager, SetArtProvider);
	Gura_AssignMethod(wx_AuiManager, SetDockSizeConstraint);
	Gura_AssignMethod(wx_AuiManager, SetFlags);
	Gura_AssignMethod(wx_AuiManager, SetManagedWindow);
	Gura_AssignMethod(wx_AuiManager, ShowHint);
	Gura_AssignMethod(wx_AuiManager, UnInit);
	Gura_AssignMethod(wx_AuiManager, Update);
	Gura_AssignMethod(wx_AuiManager, ProcessDockResult);
}

Gura_ImplementDescendantCreator(wx_AuiManager)
{
	return new Object_wx_AuiManager((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
