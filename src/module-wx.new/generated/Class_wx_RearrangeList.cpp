//----------------------------------------------------------------------------
// wxRearrangeList
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRearrangeList
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRearrangeList
//----------------------------------------------------------------------------
Object_wx_RearrangeList::~Object_wx_RearrangeList()
{
}

Object *Object_wx_RearrangeList::Clone() const
{
	return nullptr;
}

String Object_wx_RearrangeList::ToString(bool exprFlag)
{
	String rtn("<wx.RearrangeList:");
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
Gura_DeclareMethod(wx_RearrangeList, wxRearrangeList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RearrangeList, wxRearrangeList)
{
	Object_wx_RearrangeList *pThis = Object_wx_RearrangeList::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxRearrangeList();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RearrangeList, wxRearrangeList_1)
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

Gura_ImplementMethod(wx_RearrangeList, wxRearrangeList_1)
{
	Object_wx_RearrangeList *pThis = Object_wx_RearrangeList::GetObjectThis(arg);
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
	//pThis->GetEntity()->wxRearrangeList();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RearrangeList, Create)
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

Gura_ImplementMethod(wx_RearrangeList, Create)
{
	Object_wx_RearrangeList *pThis = Object_wx_RearrangeList::GetObjectThis(arg);
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

Gura_DeclareMethod(wx_RearrangeList, GetCurrentOrder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RearrangeList, GetCurrentOrder)
{
	Object_wx_RearrangeList *pThis = Object_wx_RearrangeList::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCurrentOrder();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RearrangeList, CanMoveCurrentUp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RearrangeList, CanMoveCurrentUp)
{
	Object_wx_RearrangeList *pThis = Object_wx_RearrangeList::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanMoveCurrentUp();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RearrangeList, CanMoveCurrentDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RearrangeList, CanMoveCurrentDown)
{
	Object_wx_RearrangeList *pThis = Object_wx_RearrangeList::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanMoveCurrentDown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RearrangeList, MoveCurrentUp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RearrangeList, MoveCurrentUp)
{
	Object_wx_RearrangeList *pThis = Object_wx_RearrangeList::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->MoveCurrentUp();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RearrangeList, MoveCurrentDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RearrangeList, MoveCurrentDown)
{
	Object_wx_RearrangeList *pThis = Object_wx_RearrangeList::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->MoveCurrentDown();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRearrangeList
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RearrangeList)
{
	Gura_AssignMethod(wx_RearrangeList, wxRearrangeList);
	Gura_AssignMethod(wx_RearrangeList, wxRearrangeList_1);
	Gura_AssignMethod(wx_RearrangeList, Create);
	Gura_AssignMethod(wx_RearrangeList, GetCurrentOrder);
	Gura_AssignMethod(wx_RearrangeList, CanMoveCurrentUp);
	Gura_AssignMethod(wx_RearrangeList, CanMoveCurrentDown);
	Gura_AssignMethod(wx_RearrangeList, MoveCurrentUp);
	Gura_AssignMethod(wx_RearrangeList, MoveCurrentDown);
}

Gura_ImplementDescendantCreator(wx_RearrangeList)
{
	return new Object_wx_RearrangeList((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
