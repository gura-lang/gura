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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_CollapsibleHeaderCtrl, wxCollapsibleHeaderCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CollapsibleHeaderCtrl, wxCollapsibleHeaderCtrl)
{
	Object_wx_CollapsibleHeaderCtrl *pThis = Object_wx_CollapsibleHeaderCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxCollapsibleHeaderCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CollapsibleHeaderCtrl, wxCollapsibleHeaderCtrl_1)
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

Gura_ImplementMethod(wx_CollapsibleHeaderCtrl, wxCollapsibleHeaderCtrl_1)
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
	//pThis->GetEntity()->wxCollapsibleHeaderCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CollapsibleHeaderCtrl, Create)
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

Gura_ImplementMethod(wx_CollapsibleHeaderCtrl, Create)
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

Gura_DeclareMethod(wx_CollapsibleHeaderCtrl, SetCollapsed)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "collapsed", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CollapsibleHeaderCtrl, SetCollapsed)
{
	Object_wx_CollapsibleHeaderCtrl *pThis = Object_wx_CollapsibleHeaderCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int collapsed = arg.GetNumber(0)
	//pThis->GetEntity()->SetCollapsed();
	return Value::Nil;
}

Gura_DeclareMethod(wx_CollapsibleHeaderCtrl, IsCollapsed)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_CollapsibleHeaderCtrl, IsCollapsed)
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
	Gura_AssignMethod(wx_CollapsibleHeaderCtrl, wxCollapsibleHeaderCtrl);
	Gura_AssignMethod(wx_CollapsibleHeaderCtrl, wxCollapsibleHeaderCtrl_1);
	Gura_AssignMethod(wx_CollapsibleHeaderCtrl, Create);
	Gura_AssignMethod(wx_CollapsibleHeaderCtrl, SetCollapsed);
	Gura_AssignMethod(wx_CollapsibleHeaderCtrl, IsCollapsed);
}

Gura_ImplementDescendantCreator(wx_CollapsibleHeaderCtrl)
{
	return new Object_wx_CollapsibleHeaderCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
