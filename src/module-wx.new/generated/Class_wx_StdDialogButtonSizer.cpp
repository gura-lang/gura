//----------------------------------------------------------------------------
// wxStdDialogButtonSizer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxStdDialogButtonSizer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxStdDialogButtonSizer
//----------------------------------------------------------------------------
Object_wx_StdDialogButtonSizer::~Object_wx_StdDialogButtonSizer()
{
}

Object *Object_wx_StdDialogButtonSizer::Clone() const
{
	return nullptr;
}

String Object_wx_StdDialogButtonSizer::ToString(bool exprFlag)
{
	String rtn("<wx.StdDialogButtonSizer:");
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
Gura_DeclareMethod(wx_StdDialogButtonSizer, wxStdDialogButtonSizer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StdDialogButtonSizer, wxStdDialogButtonSizer)
{
	Signal &sig = env.GetSignal();
	Object_wx_StdDialogButtonSizer *pThis = Object_wx_StdDialogButtonSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxStdDialogButtonSizer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StdDialogButtonSizer, AddButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "button", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StdDialogButtonSizer, AddButton)
{
	Signal &sig = env.GetSignal();
	Object_wx_StdDialogButtonSizer *pThis = Object_wx_StdDialogButtonSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int button = arg.GetNumber(0)
	//pThis->GetEntity()->AddButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StdDialogButtonSizer, Realize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StdDialogButtonSizer, Realize)
{
	Signal &sig = env.GetSignal();
	Object_wx_StdDialogButtonSizer *pThis = Object_wx_StdDialogButtonSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Realize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StdDialogButtonSizer, SetAffirmativeButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "button", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StdDialogButtonSizer, SetAffirmativeButton)
{
	Signal &sig = env.GetSignal();
	Object_wx_StdDialogButtonSizer *pThis = Object_wx_StdDialogButtonSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int button = arg.GetNumber(0)
	//pThis->GetEntity()->SetAffirmativeButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StdDialogButtonSizer, SetCancelButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "button", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StdDialogButtonSizer, SetCancelButton)
{
	Signal &sig = env.GetSignal();
	Object_wx_StdDialogButtonSizer *pThis = Object_wx_StdDialogButtonSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int button = arg.GetNumber(0)
	//pThis->GetEntity()->SetCancelButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StdDialogButtonSizer, SetNegativeButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "button", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StdDialogButtonSizer, SetNegativeButton)
{
	Signal &sig = env.GetSignal();
	Object_wx_StdDialogButtonSizer *pThis = Object_wx_StdDialogButtonSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int button = arg.GetNumber(0)
	//pThis->GetEntity()->SetNegativeButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StdDialogButtonSizer, RecalcSizes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StdDialogButtonSizer, RecalcSizes)
{
	Signal &sig = env.GetSignal();
	Object_wx_StdDialogButtonSizer *pThis = Object_wx_StdDialogButtonSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->RecalcSizes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StdDialogButtonSizer, CalcMin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StdDialogButtonSizer, CalcMin)
{
	Signal &sig = env.GetSignal();
	Object_wx_StdDialogButtonSizer *pThis = Object_wx_StdDialogButtonSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CalcMin();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxStdDialogButtonSizer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StdDialogButtonSizer)
{
	Gura_AssignMethod(wx_StdDialogButtonSizer, wxStdDialogButtonSizer);
	Gura_AssignMethod(wx_StdDialogButtonSizer, AddButton);
	Gura_AssignMethod(wx_StdDialogButtonSizer, Realize);
	Gura_AssignMethod(wx_StdDialogButtonSizer, SetAffirmativeButton);
	Gura_AssignMethod(wx_StdDialogButtonSizer, SetCancelButton);
	Gura_AssignMethod(wx_StdDialogButtonSizer, SetNegativeButton);
	Gura_AssignMethod(wx_StdDialogButtonSizer, RecalcSizes);
	Gura_AssignMethod(wx_StdDialogButtonSizer, CalcMin);
}

Gura_ImplementDescendantCreator(wx_StdDialogButtonSizer)
{
	return new Object_wx_StdDialogButtonSizer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
