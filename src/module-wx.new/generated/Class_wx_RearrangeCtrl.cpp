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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__RearrangeCtrl, "RearrangeCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_RearrangeCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RearrangeCtrl)
{
	//wxRearrangeCtrl();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__RearrangeCtrl_1, "RearrangeCtrl_1")
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
	SetClassToConstruct(Gura_UserClass(wx_RearrangeCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RearrangeCtrl_1)
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
	//wxRearrangeCtrl(parent, id, pos, size, order, items, style, validator, name);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RearrangeCtrl, __Create, "Create")
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

Gura_ImplementMethod(wx_RearrangeCtrl, __Create)
{
	Object_wx_RearrangeCtrl *pThis = Object_wx_RearrangeCtrl::GetObjectThis(arg);
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

Gura_DeclareMethodAlias(wx_RearrangeCtrl, __GetList, "GetList")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RearrangeCtrl, __GetList)
{
	Object_wx_RearrangeCtrl *pThis = Object_wx_RearrangeCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRearrangeList* _rtn = pThis->GetEntity()->GetList();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRearrangeCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RearrangeCtrl)
{
	// Constructor assignment
	Gura_AssignFunction(__RearrangeCtrl);
	Gura_AssignFunction(__RearrangeCtrl_1);
	// Method assignment
	Gura_AssignMethod(wx_RearrangeCtrl, __Create);
	Gura_AssignMethod(wx_RearrangeCtrl, __GetList);
}

Gura_ImplementDescendantCreator(wx_RearrangeCtrl)
{
	return new Object_wx_RearrangeCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
