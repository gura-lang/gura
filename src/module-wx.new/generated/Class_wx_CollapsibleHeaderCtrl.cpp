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
Gura_DeclareFunctionAlias(__wxCollapsibleHeaderCtrl, "wxCollapsibleHeaderCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_CollapsibleHeaderCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxCollapsibleHeaderCtrl)
{
	//wxCollapsibleHeaderCtrl();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxCollapsibleHeaderCtrl_1, "wxCollapsibleHeaderCtrl_1")
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
	SetClassToConstruct(Gura_UserClass(wx_CollapsibleHeaderCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxCollapsibleHeaderCtrl_1)
{
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int label = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int validator = arg.GetNumber(6)
	//int name = arg.GetNumber(7)
	//wxCollapsibleHeaderCtrl();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_CollapsibleHeaderCtrl, __Create, "Create")
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

Gura_ImplementMethod(wx_CollapsibleHeaderCtrl, __Create)
{
	Object_wx_CollapsibleHeaderCtrl *pThis = Object_wx_CollapsibleHeaderCtrl::GetObjectThis(arg);
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

Gura_DeclareMethodAlias(wx_CollapsibleHeaderCtrl, __SetCollapsed, "SetCollapsed")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "collapsed", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CollapsibleHeaderCtrl, __SetCollapsed)
{
	Object_wx_CollapsibleHeaderCtrl *pThis = Object_wx_CollapsibleHeaderCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int collapsed = arg.GetNumber(0)
	//pThis->GetEntity()->SetCollapsed();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CollapsibleHeaderCtrl, __IsCollapsed, "IsCollapsed")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CollapsibleHeaderCtrl, __IsCollapsed)
{
	Object_wx_CollapsibleHeaderCtrl *pThis = Object_wx_CollapsibleHeaderCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsCollapsed();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxCollapsibleHeaderCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CollapsibleHeaderCtrl)
{
	// Constructor assignment
	Gura_AssignFunction(__wxCollapsibleHeaderCtrl);
	Gura_AssignFunction(__wxCollapsibleHeaderCtrl_1);
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
