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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_MDIParentFrame, wxMDIParentFrame)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MDIParentFrame, wxMDIParentFrame)
{
	Object_wx_MDIParentFrame *pThis = Object_wx_MDIParentFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxMDIParentFrame();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MDIParentFrame, wxMDIParentFrame_1)
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

Gura_ImplementMethod(wx_MDIParentFrame, wxMDIParentFrame_1)
{
	Object_wx_MDIParentFrame *pThis = Object_wx_MDIParentFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int title = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int name = arg.GetNumber(6)
	//pThis->GetEntity()->wxMDIParentFrame();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MDIParentFrame, ActivateNext)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MDIParentFrame, ActivateNext)
{
	Object_wx_MDIParentFrame *pThis = Object_wx_MDIParentFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ActivateNext();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MDIParentFrame, ActivatePrevious)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MDIParentFrame, ActivatePrevious)
{
	Object_wx_MDIParentFrame *pThis = Object_wx_MDIParentFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ActivatePrevious();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MDIParentFrame, ArrangeIcons)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MDIParentFrame, ArrangeIcons)
{
	Object_wx_MDIParentFrame *pThis = Object_wx_MDIParentFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ArrangeIcons();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MDIParentFrame, Cascade)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MDIParentFrame, Cascade)
{
	Object_wx_MDIParentFrame *pThis = Object_wx_MDIParentFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Cascade();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MDIParentFrame, Create)
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

Gura_ImplementMethod(wx_MDIParentFrame, Create)
{
	Object_wx_MDIParentFrame *pThis = Object_wx_MDIParentFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int title = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int name = arg.GetNumber(6)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MDIParentFrame, GetActiveChild)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MDIParentFrame, GetActiveChild)
{
	Object_wx_MDIParentFrame *pThis = Object_wx_MDIParentFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetActiveChild();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MDIParentFrame, GetClientWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MDIParentFrame, GetClientWindow)
{
	Object_wx_MDIParentFrame *pThis = Object_wx_MDIParentFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetClientWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MDIParentFrame, GetWindowMenu)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MDIParentFrame, GetWindowMenu)
{
	Object_wx_MDIParentFrame *pThis = Object_wx_MDIParentFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWindowMenu();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MDIParentFrame, IsTDI)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MDIParentFrame, IsTDI)
{
	Object_wx_MDIParentFrame *pThis = Object_wx_MDIParentFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsTDI();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MDIParentFrame, OnCreateClient)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MDIParentFrame, OnCreateClient)
{
	Object_wx_MDIParentFrame *pThis = Object_wx_MDIParentFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->OnCreateClient();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MDIParentFrame, SetWindowMenu)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "menu", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MDIParentFrame, SetWindowMenu)
{
	Object_wx_MDIParentFrame *pThis = Object_wx_MDIParentFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int menu = arg.GetNumber(0)
	//pThis->GetEntity()->SetWindowMenu();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MDIParentFrame, Tile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "orient", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MDIParentFrame, Tile)
{
	Object_wx_MDIParentFrame *pThis = Object_wx_MDIParentFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int orient = arg.GetNumber(0)
	//pThis->GetEntity()->Tile();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxMDIParentFrame
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MDIParentFrame)
{
	Gura_AssignMethod(wx_MDIParentFrame, wxMDIParentFrame);
	Gura_AssignMethod(wx_MDIParentFrame, wxMDIParentFrame_1);
	Gura_AssignMethod(wx_MDIParentFrame, ActivateNext);
	Gura_AssignMethod(wx_MDIParentFrame, ActivatePrevious);
	Gura_AssignMethod(wx_MDIParentFrame, ArrangeIcons);
	Gura_AssignMethod(wx_MDIParentFrame, Cascade);
	Gura_AssignMethod(wx_MDIParentFrame, Create);
	Gura_AssignMethod(wx_MDIParentFrame, GetActiveChild);
	Gura_AssignMethod(wx_MDIParentFrame, GetClientWindow);
	Gura_AssignMethod(wx_MDIParentFrame, GetWindowMenu);
	Gura_AssignMethod(wx_MDIParentFrame, IsTDI);
	Gura_AssignMethod(wx_MDIParentFrame, OnCreateClient);
	Gura_AssignMethod(wx_MDIParentFrame, SetWindowMenu);
	Gura_AssignMethod(wx_MDIParentFrame, Tile);
}

Gura_ImplementDescendantCreator(wx_MDIParentFrame)
{
	return new Object_wx_MDIParentFrame((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
