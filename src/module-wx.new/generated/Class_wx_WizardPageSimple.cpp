//----------------------------------------------------------------------------
// wxWizardPageSimple
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxWizardPageSimple
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxWizardPageSimple
//----------------------------------------------------------------------------
Object_wx_WizardPageSimple::~Object_wx_WizardPageSimple()
{
}

Object *Object_wx_WizardPageSimple::Clone() const
{
	return nullptr;
}

String Object_wx_WizardPageSimple::ToString(bool exprFlag)
{
	String rtn("<wx.WizardPageSimple:");
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
Gura_DeclareMethod(wx_WizardPageSimple, wxWizardPageSimple)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WizardPageSimple, wxWizardPageSimple)
{
	Signal &sig = env.GetSignal();
	Object_wx_WizardPageSimple *pThis = Object_wx_WizardPageSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxWizardPageSimple();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WizardPageSimple, wxWizardPageSimple_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "prev", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "next", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WizardPageSimple, wxWizardPageSimple_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_WizardPageSimple *pThis = Object_wx_WizardPageSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int prev = arg.GetNumber(1)
	//int next = arg.GetNumber(2)
	//int bitmap = arg.GetNumber(3)
	//pThis->GetEntity()->wxWizardPageSimple();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WizardPageSimple, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "prev", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "next", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WizardPageSimple, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_WizardPageSimple *pThis = Object_wx_WizardPageSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int prev = arg.GetNumber(1)
	//int next = arg.GetNumber(2)
	//int bitmap = arg.GetNumber(3)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WizardPageSimple, Chain)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "next", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WizardPageSimple, Chain)
{
	Signal &sig = env.GetSignal();
	Object_wx_WizardPageSimple *pThis = Object_wx_WizardPageSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int next = arg.GetNumber(0)
	//pThis->GetEntity()->Chain();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WizardPageSimple, Chain_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "first", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "second", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WizardPageSimple, Chain_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_WizardPageSimple *pThis = Object_wx_WizardPageSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int first = arg.GetNumber(0)
	//int second = arg.GetNumber(1)
	//pThis->GetEntity()->Chain();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WizardPageSimple, SetNext)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "next", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WizardPageSimple, SetNext)
{
	Signal &sig = env.GetSignal();
	Object_wx_WizardPageSimple *pThis = Object_wx_WizardPageSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int next = arg.GetNumber(0)
	//pThis->GetEntity()->SetNext();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WizardPageSimple, SetPrev)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "prev", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WizardPageSimple, SetPrev)
{
	Signal &sig = env.GetSignal();
	Object_wx_WizardPageSimple *pThis = Object_wx_WizardPageSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int prev = arg.GetNumber(0)
	//pThis->GetEntity()->SetPrev();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxWizardPageSimple
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WizardPageSimple)
{
	Gura_AssignMethod(wx_WizardPageSimple, wxWizardPageSimple);
	Gura_AssignMethod(wx_WizardPageSimple, wxWizardPageSimple_1);
	Gura_AssignMethod(wx_WizardPageSimple, Create);
	Gura_AssignMethod(wx_WizardPageSimple, Chain);
	Gura_AssignMethod(wx_WizardPageSimple, Chain_1);
	Gura_AssignMethod(wx_WizardPageSimple, SetNext);
	Gura_AssignMethod(wx_WizardPageSimple, SetPrev);
}

Gura_ImplementDescendantCreator(wx_WizardPageSimple)
{
	return new Object_wx_WizardPageSimple((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
