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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxStdDialogButtonSizer, "wxStdDialogButtonSizer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(__wxStdDialogButtonSizer)
{
	//wxStdDialogButtonSizer();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_StdDialogButtonSizer, __AddButton, "AddButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "button", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StdDialogButtonSizer, __AddButton)
{
	Object_wx_StdDialogButtonSizer *pThis = Object_wx_StdDialogButtonSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int button = arg.GetNumber(0)
	//pThis->GetEntity()->AddButton();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StdDialogButtonSizer, __Realize, "Realize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StdDialogButtonSizer, __Realize)
{
	Object_wx_StdDialogButtonSizer *pThis = Object_wx_StdDialogButtonSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Realize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StdDialogButtonSizer, __SetAffirmativeButton, "SetAffirmativeButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "button", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StdDialogButtonSizer, __SetAffirmativeButton)
{
	Object_wx_StdDialogButtonSizer *pThis = Object_wx_StdDialogButtonSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int button = arg.GetNumber(0)
	//pThis->GetEntity()->SetAffirmativeButton();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StdDialogButtonSizer, __SetCancelButton, "SetCancelButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "button", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StdDialogButtonSizer, __SetCancelButton)
{
	Object_wx_StdDialogButtonSizer *pThis = Object_wx_StdDialogButtonSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int button = arg.GetNumber(0)
	//pThis->GetEntity()->SetCancelButton();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StdDialogButtonSizer, __SetNegativeButton, "SetNegativeButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "button", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StdDialogButtonSizer, __SetNegativeButton)
{
	Object_wx_StdDialogButtonSizer *pThis = Object_wx_StdDialogButtonSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int button = arg.GetNumber(0)
	//pThis->GetEntity()->SetNegativeButton();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StdDialogButtonSizer, __RecalcSizes, "RecalcSizes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StdDialogButtonSizer, __RecalcSizes)
{
	Object_wx_StdDialogButtonSizer *pThis = Object_wx_StdDialogButtonSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->RecalcSizes();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StdDialogButtonSizer, __CalcMin, "CalcMin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StdDialogButtonSizer, __CalcMin)
{
	Object_wx_StdDialogButtonSizer *pThis = Object_wx_StdDialogButtonSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CalcMin();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxStdDialogButtonSizer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StdDialogButtonSizer)
{
	// Constructor assignment
	Gura_AssignFunction(__wxStdDialogButtonSizer);
	// Method assignment
	Gura_AssignMethod(wx_StdDialogButtonSizer, __AddButton);
	Gura_AssignMethod(wx_StdDialogButtonSizer, __Realize);
	Gura_AssignMethod(wx_StdDialogButtonSizer, __SetAffirmativeButton);
	Gura_AssignMethod(wx_StdDialogButtonSizer, __SetCancelButton);
	Gura_AssignMethod(wx_StdDialogButtonSizer, __SetNegativeButton);
	Gura_AssignMethod(wx_StdDialogButtonSizer, __RecalcSizes);
	Gura_AssignMethod(wx_StdDialogButtonSizer, __CalcMin);
}

Gura_ImplementDescendantCreator(wx_StdDialogButtonSizer)
{
	return new Object_wx_StdDialogButtonSizer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
