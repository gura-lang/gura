//----------------------------------------------------------------------------
// wxCollapsiblePane
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxCollapsiblePane
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxCollapsiblePane
//----------------------------------------------------------------------------
Object_wx_CollapsiblePane::~Object_wx_CollapsiblePane()
{
}

Object *Object_wx_CollapsiblePane::Clone() const
{
	return nullptr;
}

String Object_wx_CollapsiblePane::ToString(bool exprFlag)
{
	String rtn("<wx.CollapsiblePane:");
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
Gura_DeclareMethod(wx_CollapsiblePane, wxCollapsiblePane)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CollapsiblePane, wxCollapsiblePane)
{
	Object_wx_CollapsiblePane *pThis = Object_wx_CollapsiblePane::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxCollapsiblePane();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CollapsiblePane, wxCollapsiblePane_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CollapsiblePane, wxCollapsiblePane_1)
{
	Object_wx_CollapsiblePane *pThis = Object_wx_CollapsiblePane::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int label = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int validator = arg.GetNumber(6)
	//int name = arg.GetNumber(7)
	//pThis->GetEntity()->wxCollapsiblePane();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CollapsiblePane, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CollapsiblePane, Create)
{
	Object_wx_CollapsiblePane *pThis = Object_wx_CollapsiblePane::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int label = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int validator = arg.GetNumber(6)
	//int name = arg.GetNumber(7)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CollapsiblePane, Collapse)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "collapse", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CollapsiblePane, Collapse)
{
	Object_wx_CollapsiblePane *pThis = Object_wx_CollapsiblePane::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int collapse = arg.GetNumber(0)
	//pThis->GetEntity()->Collapse();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CollapsiblePane, Expand)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CollapsiblePane, Expand)
{
	Object_wx_CollapsiblePane *pThis = Object_wx_CollapsiblePane::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Expand();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CollapsiblePane, GetPane)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CollapsiblePane, GetPane)
{
	Object_wx_CollapsiblePane *pThis = Object_wx_CollapsiblePane::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPane();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CollapsiblePane, IsCollapsed)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CollapsiblePane, IsCollapsed)
{
	Object_wx_CollapsiblePane *pThis = Object_wx_CollapsiblePane::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsCollapsed();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CollapsiblePane, IsExpanded)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CollapsiblePane, IsExpanded)
{
	Object_wx_CollapsiblePane *pThis = Object_wx_CollapsiblePane::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsExpanded();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxCollapsiblePane
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CollapsiblePane)
{
	Gura_AssignMethod(wx_CollapsiblePane, wxCollapsiblePane);
	Gura_AssignMethod(wx_CollapsiblePane, wxCollapsiblePane_1);
	Gura_AssignMethod(wx_CollapsiblePane, Create);
	Gura_AssignMethod(wx_CollapsiblePane, Collapse);
	Gura_AssignMethod(wx_CollapsiblePane, Expand);
	Gura_AssignMethod(wx_CollapsiblePane, GetPane);
	Gura_AssignMethod(wx_CollapsiblePane, IsCollapsed);
	Gura_AssignMethod(wx_CollapsiblePane, IsExpanded);
}

Gura_ImplementDescendantCreator(wx_CollapsiblePane)
{
	return new Object_wx_CollapsiblePane((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
