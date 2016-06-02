//----------------------------------------------------------------------------
// wxMDIChildFrame
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMDIChildFrame
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMDIChildFrame
//----------------------------------------------------------------------------
Object_wx_MDIChildFrame::~Object_wx_MDIChildFrame()
{
}

Object *Object_wx_MDIChildFrame::Clone() const
{
	return nullptr;
}

String Object_wx_MDIChildFrame::ToString(bool exprFlag)
{
	String rtn("<wx.MDIChildFrame:");
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
Gura_DeclareMethod(wx_MDIChildFrame, wxMDIChildFrame)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MDIChildFrame, wxMDIChildFrame)
{
	Object_wx_MDIChildFrame *pThis = Object_wx_MDIChildFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxMDIChildFrame();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MDIChildFrame, wxMDIChildFrame_1)
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

Gura_ImplementMethod(wx_MDIChildFrame, wxMDIChildFrame_1)
{
	Object_wx_MDIChildFrame *pThis = Object_wx_MDIChildFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int title = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int name = arg.GetNumber(6)
	//pThis->GetEntity()->wxMDIChildFrame();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MDIChildFrame, Activate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MDIChildFrame, Activate)
{
	Object_wx_MDIChildFrame *pThis = Object_wx_MDIChildFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Activate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MDIChildFrame, Create)
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

Gura_ImplementMethod(wx_MDIChildFrame, Create)
{
	Object_wx_MDIChildFrame *pThis = Object_wx_MDIChildFrame::GetObjectThis(arg);
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

Gura_DeclareMethod(wx_MDIChildFrame, GetMDIParent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MDIChildFrame, GetMDIParent)
{
	Object_wx_MDIChildFrame *pThis = Object_wx_MDIChildFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMDIParent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MDIChildFrame, IsAlwaysMaximized)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MDIChildFrame, IsAlwaysMaximized)
{
	Object_wx_MDIChildFrame *pThis = Object_wx_MDIChildFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsAlwaysMaximized();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MDIChildFrame, Maximize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "maximize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MDIChildFrame, Maximize)
{
	Object_wx_MDIChildFrame *pThis = Object_wx_MDIChildFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int maximize = arg.GetNumber(0)
	//pThis->GetEntity()->Maximize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MDIChildFrame, Restore)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MDIChildFrame, Restore)
{
	Object_wx_MDIChildFrame *pThis = Object_wx_MDIChildFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Restore();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxMDIChildFrame
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MDIChildFrame)
{
	Gura_AssignMethod(wx_MDIChildFrame, wxMDIChildFrame);
	Gura_AssignMethod(wx_MDIChildFrame, wxMDIChildFrame_1);
	Gura_AssignMethod(wx_MDIChildFrame, Activate);
	Gura_AssignMethod(wx_MDIChildFrame, Create);
	Gura_AssignMethod(wx_MDIChildFrame, GetMDIParent);
	Gura_AssignMethod(wx_MDIChildFrame, IsAlwaysMaximized);
	Gura_AssignMethod(wx_MDIChildFrame, Maximize);
	Gura_AssignMethod(wx_MDIChildFrame, Restore);
}

Gura_ImplementDescendantCreator(wx_MDIChildFrame)
{
	return new Object_wx_MDIChildFrame((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
