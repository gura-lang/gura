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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxMDIChildFrame, "wxMDIChildFrame")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(__wxMDIChildFrame)
{
	//wxMDIChildFrame();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxMDIChildFrame_1, "wxMDIChildFrame_1")
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

Gura_ImplementFunction(__wxMDIChildFrame_1)
{
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int title = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int name = arg.GetNumber(6)
	//wxMDIChildFrame();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_MDIChildFrame, __Activate, "Activate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MDIChildFrame, __Activate)
{
	Object_wx_MDIChildFrame *pThis = Object_wx_MDIChildFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Activate();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MDIChildFrame, __Create, "Create")
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

Gura_ImplementMethod(wx_MDIChildFrame, __Create)
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

Gura_DeclareMethodAlias(wx_MDIChildFrame, __GetMDIParent, "GetMDIParent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MDIChildFrame, __GetMDIParent)
{
	Object_wx_MDIChildFrame *pThis = Object_wx_MDIChildFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMDIParent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MDIChildFrame, __IsAlwaysMaximized, "IsAlwaysMaximized")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MDIChildFrame, __IsAlwaysMaximized)
{
	Object_wx_MDIChildFrame *pThis = Object_wx_MDIChildFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsAlwaysMaximized();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MDIChildFrame, __Maximize, "Maximize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "maximize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MDIChildFrame, __Maximize)
{
	Object_wx_MDIChildFrame *pThis = Object_wx_MDIChildFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int maximize = arg.GetNumber(0)
	//pThis->GetEntity()->Maximize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MDIChildFrame, __Restore, "Restore")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MDIChildFrame, __Restore)
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
	// Constructor assignment
	Gura_AssignFunction(__wxMDIChildFrame);
	Gura_AssignFunction(__wxMDIChildFrame_1);
	// Method assignment
	Gura_AssignMethod(wx_MDIChildFrame, __Activate);
	Gura_AssignMethod(wx_MDIChildFrame, __Create);
	Gura_AssignMethod(wx_MDIChildFrame, __GetMDIParent);
	Gura_AssignMethod(wx_MDIChildFrame, __IsAlwaysMaximized);
	Gura_AssignMethod(wx_MDIChildFrame, __Maximize);
	Gura_AssignMethod(wx_MDIChildFrame, __Restore);
}

Gura_ImplementDescendantCreator(wx_MDIChildFrame)
{
	return new Object_wx_MDIChildFrame((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
