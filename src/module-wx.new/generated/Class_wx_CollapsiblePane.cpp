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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__CollapsiblePane, "CollapsiblePane")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_CollapsiblePane));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__CollapsiblePane)
{
	//wxCollapsiblePane();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__CollapsiblePane_1, "CollapsiblePane_1")
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
	SetClassToConstruct(Gura_UserClass(wx_CollapsiblePane));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__CollapsiblePane_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxString& label = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//long style = arg.GetNumber(5)
	//const wxValidator& validator = arg.GetNumber(6)
	//const wxString& name = arg.GetNumber(7)
	//wxCollapsiblePane();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_CollapsiblePane, __Create, "Create")
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

Gura_ImplementMethod(wx_CollapsiblePane, __Create)
{
	Object_wx_CollapsiblePane *pThis = Object_wx_CollapsiblePane::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxString& label = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//long style = arg.GetNumber(5)
	//const wxValidator& validator = arg.GetNumber(6)
	//const wxString& name = arg.GetNumber(7)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CollapsiblePane, __Collapse, "Collapse")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "collapse", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CollapsiblePane, __Collapse)
{
	Object_wx_CollapsiblePane *pThis = Object_wx_CollapsiblePane::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool collapse = arg.GetNumber(0)
	//pThis->GetEntity()->Collapse();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CollapsiblePane, __Expand, "Expand")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CollapsiblePane, __Expand)
{
	Object_wx_CollapsiblePane *pThis = Object_wx_CollapsiblePane::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Expand();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CollapsiblePane, __GetPane, "GetPane")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CollapsiblePane, __GetPane)
{
	Object_wx_CollapsiblePane *pThis = Object_wx_CollapsiblePane::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPane();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CollapsiblePane, __IsCollapsed, "IsCollapsed")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CollapsiblePane, __IsCollapsed)
{
	Object_wx_CollapsiblePane *pThis = Object_wx_CollapsiblePane::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsCollapsed();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CollapsiblePane, __IsExpanded, "IsExpanded")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CollapsiblePane, __IsExpanded)
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
	// Constructor assignment
	Gura_AssignFunction(__CollapsiblePane);
	Gura_AssignFunction(__CollapsiblePane_1);
	// Method assignment
	Gura_AssignMethod(wx_CollapsiblePane, __Create);
	Gura_AssignMethod(wx_CollapsiblePane, __Collapse);
	Gura_AssignMethod(wx_CollapsiblePane, __Expand);
	Gura_AssignMethod(wx_CollapsiblePane, __GetPane);
	Gura_AssignMethod(wx_CollapsiblePane, __IsCollapsed);
	Gura_AssignMethod(wx_CollapsiblePane, __IsExpanded);
}

Gura_ImplementDescendantCreator(wx_CollapsiblePane)
{
	return new Object_wx_CollapsiblePane((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
