//----------------------------------------------------------------------------
// wxRearrangeDialog
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRearrangeDialog
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRearrangeDialog
//----------------------------------------------------------------------------
Object_wx_RearrangeDialog::~Object_wx_RearrangeDialog()
{
}

Object *Object_wx_RearrangeDialog::Clone() const
{
	return nullptr;
}

String Object_wx_RearrangeDialog::ToString(bool exprFlag)
{
	String rtn("<wx.RearrangeDialog:");
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
Gura_DeclareFunctionAlias(__RearrangeDialog, "RearrangeDialog")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_RearrangeDialog));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RearrangeDialog)
{
	//wxRearrangeDialog();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__RearrangeDialog_1, "RearrangeDialog_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "message", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "order", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RearrangeDialog));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RearrangeDialog_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//const wxString& message = arg.GetNumber(1)
	//const wxString& title = arg.GetNumber(2)
	//const wxArrayInt& order = arg.GetNumber(3)
	//const wxArrayString& items = arg.GetNumber(4)
	//const wxPoint& pos = arg.GetNumber(5)
	//const wxString& name = arg.GetNumber(6)
	//wxRearrangeDialog();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RearrangeDialog, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "message", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "order", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RearrangeDialog, __Create)
{
	Object_wx_RearrangeDialog *pThis = Object_wx_RearrangeDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//const wxString& message = arg.GetNumber(1)
	//const wxString& title = arg.GetNumber(2)
	//const wxArrayInt& order = arg.GetNumber(3)
	//const wxArrayString& items = arg.GetNumber(4)
	//const wxPoint& pos = arg.GetNumber(5)
	//const wxString& name = arg.GetNumber(6)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RearrangeDialog, __AddExtraControls, "AddExtraControls")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RearrangeDialog, __AddExtraControls)
{
	Object_wx_RearrangeDialog *pThis = Object_wx_RearrangeDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* win = arg.GetNumber(0)
	//pThis->GetEntity()->AddExtraControls();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RearrangeDialog, __GetList, "GetList")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RearrangeDialog, __GetList)
{
	Object_wx_RearrangeDialog *pThis = Object_wx_RearrangeDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetList();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RearrangeDialog, __GetOrder, "GetOrder")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RearrangeDialog, __GetOrder)
{
	Object_wx_RearrangeDialog *pThis = Object_wx_RearrangeDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOrder();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRearrangeDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RearrangeDialog)
{
	// Constructor assignment
	Gura_AssignFunction(__RearrangeDialog);
	Gura_AssignFunction(__RearrangeDialog_1);
	// Method assignment
	Gura_AssignMethod(wx_RearrangeDialog, __Create);
	Gura_AssignMethod(wx_RearrangeDialog, __AddExtraControls);
	Gura_AssignMethod(wx_RearrangeDialog, __GetList);
	Gura_AssignMethod(wx_RearrangeDialog, __GetOrder);
}

Gura_ImplementDescendantCreator(wx_RearrangeDialog)
{
	return new Object_wx_RearrangeDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
