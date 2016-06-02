//----------------------------------------------------------------------------
// wxBoxSizer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxBoxSizer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxBoxSizer
//----------------------------------------------------------------------------
Object_wx_BoxSizer::~Object_wx_BoxSizer()
{
}

Object *Object_wx_BoxSizer::Clone() const
{
	return nullptr;
}

String Object_wx_BoxSizer::ToString(bool exprFlag)
{
	String rtn("<wx.BoxSizer:");
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
Gura_DeclareMethod(wx_BoxSizer, wxBoxSizer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "orient", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BoxSizer, wxBoxSizer)
{
	Object_wx_BoxSizer *pThis = Object_wx_BoxSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int orient = arg.GetNumber(0)
	//pThis->GetEntity()->wxBoxSizer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_BoxSizer, AddSpacer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BoxSizer, AddSpacer)
{
	Object_wx_BoxSizer *pThis = Object_wx_BoxSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->AddSpacer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_BoxSizer, CalcMin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_BoxSizer, CalcMin)
{
	Object_wx_BoxSizer *pThis = Object_wx_BoxSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CalcMin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_BoxSizer, GetOrientation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_BoxSizer, GetOrientation)
{
	Object_wx_BoxSizer *pThis = Object_wx_BoxSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOrientation();
	return Value::Nil;
}

Gura_DeclareMethod(wx_BoxSizer, SetOrientation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "orient", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BoxSizer, SetOrientation)
{
	Object_wx_BoxSizer *pThis = Object_wx_BoxSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int orient = arg.GetNumber(0)
	//pThis->GetEntity()->SetOrientation();
	return Value::Nil;
}

Gura_DeclareMethod(wx_BoxSizer, RecalcSizes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_BoxSizer, RecalcSizes)
{
	Object_wx_BoxSizer *pThis = Object_wx_BoxSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->RecalcSizes();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxBoxSizer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_BoxSizer)
{
	Gura_AssignMethod(wx_BoxSizer, wxBoxSizer);
	Gura_AssignMethod(wx_BoxSizer, AddSpacer);
	Gura_AssignMethod(wx_BoxSizer, CalcMin);
	Gura_AssignMethod(wx_BoxSizer, GetOrientation);
	Gura_AssignMethod(wx_BoxSizer, SetOrientation);
	Gura_AssignMethod(wx_BoxSizer, RecalcSizes);
}

Gura_ImplementDescendantCreator(wx_BoxSizer)
{
	return new Object_wx_BoxSizer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
