//----------------------------------------------------------------------------
// wxRearrangeCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRearrangeCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRearrangeCtrl
//----------------------------------------------------------------------------
Object_wx_RearrangeCtrl::~Object_wx_RearrangeCtrl()
{
}

Object *Object_wx_RearrangeCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_RearrangeCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.RearrangeCtrl:");
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
Gura_DeclareMethodAlias(wx_RearrangeCtrl, __wxRearrangeCtrl, "wxRearrangeCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RearrangeCtrl, __wxRearrangeCtrl)
{
	Object_wx_RearrangeCtrl *pThis = Object_wx_RearrangeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxRearrangeCtrl();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RearrangeCtrl, __wxRearrangeCtrl_1, "wxRearrangeCtrl_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "order", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RearrangeCtrl, __wxRearrangeCtrl_1)
{
	Object_wx_RearrangeCtrl *pThis = Object_wx_RearrangeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int order = arg.GetNumber(4)
	//int items = arg.GetNumber(5)
	//int style = arg.GetNumber(6)
	//int validator = arg.GetNumber(7)
	//int name = arg.GetNumber(8)
	//pThis->GetEntity()->wxRearrangeCtrl();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RearrangeCtrl, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "order", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RearrangeCtrl, __Create)
{
	Object_wx_RearrangeCtrl *pThis = Object_wx_RearrangeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int order = arg.GetNumber(4)
	//int items = arg.GetNumber(5)
	//int style = arg.GetNumber(6)
	//int validator = arg.GetNumber(7)
	//int name = arg.GetNumber(8)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RearrangeCtrl, __GetList, "GetList")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RearrangeCtrl, __GetList)
{
	Object_wx_RearrangeCtrl *pThis = Object_wx_RearrangeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetList();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRearrangeCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RearrangeCtrl)
{
	Gura_AssignMethod(wx_RearrangeCtrl, __wxRearrangeCtrl);
	Gura_AssignMethod(wx_RearrangeCtrl, __wxRearrangeCtrl_1);
	Gura_AssignMethod(wx_RearrangeCtrl, __Create);
	Gura_AssignMethod(wx_RearrangeCtrl, __GetList);
}

Gura_ImplementDescendantCreator(wx_RearrangeCtrl)
{
	return new Object_wx_RearrangeCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
