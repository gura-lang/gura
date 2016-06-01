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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_RearrangeDialog, wxRearrangeDialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RearrangeDialog, wxRearrangeDialog)
{
	Signal &sig = env.GetSignal();
	Object_wx_RearrangeDialog *pThis = Object_wx_RearrangeDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxRearrangeDialog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RearrangeDialog, wxRearrangeDialog_1)
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

Gura_ImplementMethod(wx_RearrangeDialog, wxRearrangeDialog_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_RearrangeDialog *pThis = Object_wx_RearrangeDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int message = arg.GetNumber(1)
	//int title = arg.GetNumber(2)
	//int order = arg.GetNumber(3)
	//int items = arg.GetNumber(4)
	//int pos = arg.GetNumber(5)
	//int name = arg.GetNumber(6)
	//pThis->GetEntity()->wxRearrangeDialog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RearrangeDialog, Create)
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

Gura_ImplementMethod(wx_RearrangeDialog, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_RearrangeDialog *pThis = Object_wx_RearrangeDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int message = arg.GetNumber(1)
	//int title = arg.GetNumber(2)
	//int order = arg.GetNumber(3)
	//int items = arg.GetNumber(4)
	//int pos = arg.GetNumber(5)
	//int name = arg.GetNumber(6)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RearrangeDialog, AddExtraControls)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RearrangeDialog, AddExtraControls)
{
	Signal &sig = env.GetSignal();
	Object_wx_RearrangeDialog *pThis = Object_wx_RearrangeDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//pThis->GetEntity()->AddExtraControls();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RearrangeDialog, GetList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RearrangeDialog, GetList)
{
	Signal &sig = env.GetSignal();
	Object_wx_RearrangeDialog *pThis = Object_wx_RearrangeDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetList();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RearrangeDialog, GetOrder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RearrangeDialog, GetOrder)
{
	Signal &sig = env.GetSignal();
	Object_wx_RearrangeDialog *pThis = Object_wx_RearrangeDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetOrder();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRearrangeDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RearrangeDialog)
{
	Gura_AssignMethod(wx_RearrangeDialog, wxRearrangeDialog);
	Gura_AssignMethod(wx_RearrangeDialog, wxRearrangeDialog_1);
	Gura_AssignMethod(wx_RearrangeDialog, Create);
	Gura_AssignMethod(wx_RearrangeDialog, AddExtraControls);
	Gura_AssignMethod(wx_RearrangeDialog, GetList);
	Gura_AssignMethod(wx_RearrangeDialog, GetOrder);
}

Gura_ImplementDescendantCreator(wx_RearrangeDialog)
{
	return new Object_wx_RearrangeDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
