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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__RearrangeList, "RearrangeList")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_RearrangeList));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RearrangeList)
{
	//wxRearrangeList();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__RearrangeList_1, "RearrangeList_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "order", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RearrangeList));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RearrangeList_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//const wxArrayInt& order = arg.GetNumber(4)
	//const wxArrayString& items = arg.GetNumber(5)
	//long style = arg.GetNumber(6)
	//const wxValidator& validator = arg.GetNumber(7)
	//const wxString& name = arg.GetNumber(8)
	//wxRearrangeList(parent, id, pos, size, order, items, style, validator, name);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RearrangeList, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
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

Gura_ImplementMethod(wx_RearrangeList, __Create)
{
	Object_wx_RearrangeList *pThis = Object_wx_RearrangeList::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//const wxArrayInt& order = arg.GetNumber(4)
	//const wxArrayString& items = arg.GetNumber(5)
	//long style = arg.GetNumber(6)
	//const wxValidator& validator = arg.GetNumber(7)
	//const wxString& name = arg.GetNumber(8)
	//bool _rtn = pThis->GetEntity()->Create(parent, id, pos, size, order, items, style, validator, name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RearrangeList, __GetCurrentOrder, "GetCurrentOrder")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RearrangeList, __GetCurrentOrder)
{
	Object_wx_RearrangeList *pThis = Object_wx_RearrangeList::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxArrayInt& _rtn = pThis->GetEntity()->GetCurrentOrder();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RearrangeList, __CanMoveCurrentUp, "CanMoveCurrentUp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RearrangeList, __CanMoveCurrentUp)
{
	Object_wx_RearrangeList *pThis = Object_wx_RearrangeList::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->CanMoveCurrentUp();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RearrangeList, __CanMoveCurrentDown, "CanMoveCurrentDown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RearrangeList, __CanMoveCurrentDown)
{
	Object_wx_RearrangeList *pThis = Object_wx_RearrangeList::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->CanMoveCurrentDown();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RearrangeList, __MoveCurrentUp, "MoveCurrentUp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RearrangeList, __MoveCurrentUp)
{
	Object_wx_RearrangeList *pThis = Object_wx_RearrangeList::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->MoveCurrentUp();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RearrangeList, __MoveCurrentDown, "MoveCurrentDown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RearrangeList, __MoveCurrentDown)
{
	Object_wx_RearrangeList *pThis = Object_wx_RearrangeList::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->MoveCurrentDown();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRearrangeList
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RearrangeList)
{
	// Constructor assignment
	Gura_AssignFunction(__RearrangeList);
	Gura_AssignFunction(__RearrangeList_1);
	// Method assignment
	Gura_AssignMethod(wx_RearrangeList, __Create);
	Gura_AssignMethod(wx_RearrangeList, __GetCurrentOrder);
	Gura_AssignMethod(wx_RearrangeList, __CanMoveCurrentUp);
	Gura_AssignMethod(wx_RearrangeList, __CanMoveCurrentDown);
	Gura_AssignMethod(wx_RearrangeList, __MoveCurrentUp);
	Gura_AssignMethod(wx_RearrangeList, __MoveCurrentDown);
}

Gura_ImplementDescendantCreator(wx_RearrangeList)
{
	return new Object_wx_RearrangeList((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
