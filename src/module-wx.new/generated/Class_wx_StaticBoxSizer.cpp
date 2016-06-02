//----------------------------------------------------------------------------
// wxStaticBoxSizer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxStaticBoxSizer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxStaticBoxSizer
//----------------------------------------------------------------------------
Object_wx_StaticBoxSizer::~Object_wx_StaticBoxSizer()
{
}

Object *Object_wx_StaticBoxSizer::Clone() const
{
	return nullptr;
}

String Object_wx_StaticBoxSizer::ToString(bool exprFlag)
{
	String rtn("<wx.StaticBoxSizer:");
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
Gura_DeclareMethod(wx_StaticBoxSizer, wxStaticBoxSizer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "box", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "orient", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StaticBoxSizer, wxStaticBoxSizer)
{
	Object_wx_StaticBoxSizer *pThis = Object_wx_StaticBoxSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int box = arg.GetNumber(0)
	//int orient = arg.GetNumber(1)
	//pThis->GetEntity()->wxStaticBoxSizer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StaticBoxSizer, wxStaticBoxSizer_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "orient", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StaticBoxSizer, wxStaticBoxSizer_1)
{
	Object_wx_StaticBoxSizer *pThis = Object_wx_StaticBoxSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int orient = arg.GetNumber(0)
	//int parent = arg.GetNumber(1)
	//int label = arg.GetNumber(2)
	//pThis->GetEntity()->wxStaticBoxSizer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StaticBoxSizer, GetStaticBox)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StaticBoxSizer, GetStaticBox)
{
	Object_wx_StaticBoxSizer *pThis = Object_wx_StaticBoxSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStaticBox();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StaticBoxSizer, CalcMin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StaticBoxSizer, CalcMin)
{
	Object_wx_StaticBoxSizer *pThis = Object_wx_StaticBoxSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CalcMin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StaticBoxSizer, RecalcSizes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StaticBoxSizer, RecalcSizes)
{
	Object_wx_StaticBoxSizer *pThis = Object_wx_StaticBoxSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->RecalcSizes();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxStaticBoxSizer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StaticBoxSizer)
{
	Gura_AssignMethod(wx_StaticBoxSizer, wxStaticBoxSizer);
	Gura_AssignMethod(wx_StaticBoxSizer, wxStaticBoxSizer_1);
	Gura_AssignMethod(wx_StaticBoxSizer, GetStaticBox);
	Gura_AssignMethod(wx_StaticBoxSizer, CalcMin);
	Gura_AssignMethod(wx_StaticBoxSizer, RecalcSizes);
}

Gura_ImplementDescendantCreator(wx_StaticBoxSizer)
{
	return new Object_wx_StaticBoxSizer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
