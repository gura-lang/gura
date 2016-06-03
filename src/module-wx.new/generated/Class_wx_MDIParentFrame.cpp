//----------------------------------------------------------------------------
// wxMDIParentFrame
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMDIParentFrame
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMDIParentFrame
//----------------------------------------------------------------------------
Object_wx_MDIParentFrame::~Object_wx_MDIParentFrame()
{
}

Object *Object_wx_MDIParentFrame::Clone() const
{
	return nullptr;
}

String Object_wx_MDIParentFrame::ToString(bool exprFlag)
{
	String rtn("<wx.MDIParentFrame:");
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
Gura_DeclareFunctionAlias(__MDIParentFrame, "MDIParentFrame")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_MDIParentFrame));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__MDIParentFrame)
{
	//wxMDIParentFrame();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__MDIParentFrame_1, "MDIParentFrame_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_MDIParentFrame));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__MDIParentFrame_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxString& title = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//long style = arg.GetNumber(5)
	//const wxString& name = arg.GetNumber(6)
	//wxMDIParentFrame();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_MDIParentFrame, __ActivateNext, "ActivateNext")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MDIParentFrame, __ActivateNext)
{
	Object_wx_MDIParentFrame *pThis = Object_wx_MDIParentFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ActivateNext();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MDIParentFrame, __ActivatePrevious, "ActivatePrevious")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MDIParentFrame, __ActivatePrevious)
{
	Object_wx_MDIParentFrame *pThis = Object_wx_MDIParentFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ActivatePrevious();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MDIParentFrame, __ArrangeIcons, "ArrangeIcons")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MDIParentFrame, __ArrangeIcons)
{
	Object_wx_MDIParentFrame *pThis = Object_wx_MDIParentFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ArrangeIcons();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MDIParentFrame, __Cascade, "Cascade")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MDIParentFrame, __Cascade)
{
	Object_wx_MDIParentFrame *pThis = Object_wx_MDIParentFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Cascade();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MDIParentFrame, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MDIParentFrame, __Create)
{
	Object_wx_MDIParentFrame *pThis = Object_wx_MDIParentFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxString& title = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//long style = arg.GetNumber(5)
	//const wxString& name = arg.GetNumber(6)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MDIParentFrame, __GetActiveChild, "GetActiveChild")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MDIParentFrame, __GetActiveChild)
{
	Object_wx_MDIParentFrame *pThis = Object_wx_MDIParentFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetActiveChild();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MDIParentFrame, __GetClientWindow, "GetClientWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MDIParentFrame, __GetClientWindow)
{
	Object_wx_MDIParentFrame *pThis = Object_wx_MDIParentFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetClientWindow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MDIParentFrame, __GetWindowMenu, "GetWindowMenu")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MDIParentFrame, __GetWindowMenu)
{
	Object_wx_MDIParentFrame *pThis = Object_wx_MDIParentFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWindowMenu();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MDIParentFrame, __IsTDI, "IsTDI")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MDIParentFrame, __IsTDI)
{
	Object_wx_MDIParentFrame *pThis = Object_wx_MDIParentFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsTDI();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MDIParentFrame, __OnCreateClient, "OnCreateClient")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MDIParentFrame, __OnCreateClient)
{
	Object_wx_MDIParentFrame *pThis = Object_wx_MDIParentFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->OnCreateClient();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MDIParentFrame, __SetWindowMenu, "SetWindowMenu")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "menu", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MDIParentFrame, __SetWindowMenu)
{
	Object_wx_MDIParentFrame *pThis = Object_wx_MDIParentFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxMenu* menu = arg.GetNumber(0)
	//pThis->GetEntity()->SetWindowMenu();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MDIParentFrame, __Tile, "Tile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "orient", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MDIParentFrame, __Tile)
{
	Object_wx_MDIParentFrame *pThis = Object_wx_MDIParentFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxOrientation orient = arg.GetNumber(0)
	//pThis->GetEntity()->Tile();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxMDIParentFrame
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MDIParentFrame)
{
	// Constructor assignment
	Gura_AssignFunction(__MDIParentFrame);
	Gura_AssignFunction(__MDIParentFrame_1);
	// Method assignment
	Gura_AssignMethod(wx_MDIParentFrame, __ActivateNext);
	Gura_AssignMethod(wx_MDIParentFrame, __ActivatePrevious);
	Gura_AssignMethod(wx_MDIParentFrame, __ArrangeIcons);
	Gura_AssignMethod(wx_MDIParentFrame, __Cascade);
	Gura_AssignMethod(wx_MDIParentFrame, __Create);
	Gura_AssignMethod(wx_MDIParentFrame, __GetActiveChild);
	Gura_AssignMethod(wx_MDIParentFrame, __GetClientWindow);
	Gura_AssignMethod(wx_MDIParentFrame, __GetWindowMenu);
	Gura_AssignMethod(wx_MDIParentFrame, __IsTDI);
	Gura_AssignMethod(wx_MDIParentFrame, __OnCreateClient);
	Gura_AssignMethod(wx_MDIParentFrame, __SetWindowMenu);
	Gura_AssignMethod(wx_MDIParentFrame, __Tile);
}

Gura_ImplementDescendantCreator(wx_MDIParentFrame)
{
	return new Object_wx_MDIParentFrame((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
