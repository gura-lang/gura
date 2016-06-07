//----------------------------------------------------------------------------
// wxCollapsibleHeaderCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxCollapsibleHeaderCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxCollapsibleHeaderCtrl
//----------------------------------------------------------------------------
Object_wx_CollapsibleHeaderCtrl::~Object_wx_CollapsibleHeaderCtrl()
{
}

Object *Object_wx_CollapsibleHeaderCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_CollapsibleHeaderCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.CollapsibleHeaderCtrl:");
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
Gura_DeclareFunctionAlias(__CollapsibleHeaderCtrl, "CollapsibleHeaderCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_CollapsibleHeaderCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__CollapsibleHeaderCtrl)
{
	//wxCollapsibleHeaderCtrl();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__CollapsibleHeaderCtrl_1, "CollapsibleHeaderCtrl_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_CollapsibleHeaderCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__CollapsibleHeaderCtrl_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxString& label = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//long style = arg.GetNumber(5)
	//const wxValidator& validator = arg.GetNumber(6)
	//const wxString& name = arg.GetNumber(7)
	//wxCollapsibleHeaderCtrl(parent, id, label, pos, size, style, validator, name);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_CollapsibleHeaderCtrl, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CollapsibleHeaderCtrl, __Create)
{
	Object_wx_CollapsibleHeaderCtrl *pThis = Object_wx_CollapsibleHeaderCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxString& label = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//long style = arg.GetNumber(5)
	//const wxValidator& validator = arg.GetNumber(6)
	//const wxString& name = arg.GetNumber(7)
	//bool _rtn = pThis->GetEntity()->Create(parent, id, label, pos, size, style, validator, name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CollapsibleHeaderCtrl, __SetCollapsed, "SetCollapsed")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "collapsed", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CollapsibleHeaderCtrl, __SetCollapsed)
{
	Object_wx_CollapsibleHeaderCtrl *pThis = Object_wx_CollapsibleHeaderCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool collapsed = arg.GetNumber(0)
	//pThis->GetEntity()->SetCollapsed(collapsed);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CollapsibleHeaderCtrl, __IsCollapsed, "IsCollapsed")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_CollapsibleHeaderCtrl, __IsCollapsed)
{
	Object_wx_CollapsibleHeaderCtrl *pThis = Object_wx_CollapsibleHeaderCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsCollapsed();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxCollapsibleHeaderCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CollapsibleHeaderCtrl)
{
	// Constructor assignment
	Gura_AssignFunction(__CollapsibleHeaderCtrl);
	Gura_AssignFunction(__CollapsibleHeaderCtrl_1);
	// Method assignment
	Gura_AssignMethod(wx_CollapsibleHeaderCtrl, __Create);
	Gura_AssignMethod(wx_CollapsibleHeaderCtrl, __SetCollapsed);
	Gura_AssignMethod(wx_CollapsibleHeaderCtrl, __IsCollapsed);
}

Gura_ImplementDescendantCreator(wx_CollapsibleHeaderCtrl)
{
	return new Object_wx_CollapsibleHeaderCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
