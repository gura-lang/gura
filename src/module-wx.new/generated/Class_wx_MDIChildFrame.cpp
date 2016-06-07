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
Gura_DeclareFunctionAlias(__MDIChildFrame, "MDIChildFrame")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_MDIChildFrame));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__MDIChildFrame)
{
	//wxMDIChildFrame();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__MDIChildFrame_1, "MDIChildFrame_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_MDIChildFrame));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__MDIChildFrame_1)
{
	//wxMDIParentFrame* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxString& title = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//long style = arg.GetNumber(5)
	//const wxString& name = arg.GetNumber(6)
	//wxMDIChildFrame(parent, id, title, pos, size, style, name);
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
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
	//wxMDIParentFrame* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxString& title = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//long style = arg.GetNumber(5)
	//const wxString& name = arg.GetNumber(6)
	//bool _rtn = pThis->GetEntity()->Create(parent, id, title, pos, size, style, name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MDIChildFrame, __GetMDIParent, "GetMDIParent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_MDIChildFrame, __GetMDIParent)
{
	Object_wx_MDIChildFrame *pThis = Object_wx_MDIChildFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxMDIParentFrame* _rtn = pThis->GetEntity()->GetMDIParent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MDIChildFrame, __IsAlwaysMaximized, "IsAlwaysMaximized")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_MDIChildFrame, __IsAlwaysMaximized)
{
	Object_wx_MDIChildFrame *pThis = Object_wx_MDIChildFrame::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsAlwaysMaximized();
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
	//bool maximize = arg.GetNumber(0)
	//pThis->GetEntity()->Maximize(maximize);
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
	Gura_AssignFunction(__MDIChildFrame);
	Gura_AssignFunction(__MDIChildFrame_1);
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
