//----------------------------------------------------------------------------
// wxGridSizer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGridSizer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridSizer
//----------------------------------------------------------------------------
Object_wx_GridSizer::~Object_wx_GridSizer()
{
}

Object *Object_wx_GridSizer::Clone() const
{
	return nullptr;
}

String Object_wx_GridSizer::ToString(bool exprFlag)
{
	String rtn("<wx.GridSizer:");
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
Gura_DeclareMethod(wx_GridSizer, wxGridSizer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cols", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "vgap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "hgap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridSizer, wxGridSizer)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridSizer *pThis = Object_wx_GridSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int cols = arg.GetNumber(0)
	//int vgap = arg.GetNumber(1)
	//int hgap = arg.GetNumber(2)
	//pThis->GetEntity()->wxGridSizer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridSizer, wxGridSizer_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cols", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "gap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridSizer, wxGridSizer_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridSizer *pThis = Object_wx_GridSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int cols = arg.GetNumber(0)
	//int gap = arg.GetNumber(1)
	//pThis->GetEntity()->wxGridSizer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridSizer, wxGridSizer_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rows", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cols", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "vgap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "hgap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridSizer, wxGridSizer_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridSizer *pThis = Object_wx_GridSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int rows = arg.GetNumber(0)
	//int cols = arg.GetNumber(1)
	//int vgap = arg.GetNumber(2)
	//int hgap = arg.GetNumber(3)
	//pThis->GetEntity()->wxGridSizer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridSizer, wxGridSizer_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rows", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cols", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "gap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridSizer, wxGridSizer_3)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridSizer *pThis = Object_wx_GridSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int rows = arg.GetNumber(0)
	//int cols = arg.GetNumber(1)
	//int gap = arg.GetNumber(2)
	//pThis->GetEntity()->wxGridSizer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridSizer, GetCols)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridSizer, GetCols)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridSizer *pThis = Object_wx_GridSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetCols();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridSizer, GetRows)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridSizer, GetRows)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridSizer *pThis = Object_wx_GridSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetRows();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridSizer, GetEffectiveColsCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridSizer, GetEffectiveColsCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridSizer *pThis = Object_wx_GridSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetEffectiveColsCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridSizer, GetEffectiveRowsCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridSizer, GetEffectiveRowsCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridSizer *pThis = Object_wx_GridSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetEffectiveRowsCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridSizer, GetHGap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridSizer, GetHGap)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridSizer *pThis = Object_wx_GridSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetHGap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridSizer, GetVGap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridSizer, GetVGap)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridSizer *pThis = Object_wx_GridSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetVGap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridSizer, SetCols)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cols", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridSizer, SetCols)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridSizer *pThis = Object_wx_GridSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int cols = arg.GetNumber(0)
	//pThis->GetEntity()->SetCols();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridSizer, SetHGap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "gap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridSizer, SetHGap)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridSizer *pThis = Object_wx_GridSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int gap = arg.GetNumber(0)
	//pThis->GetEntity()->SetHGap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridSizer, SetRows)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rows", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridSizer, SetRows)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridSizer *pThis = Object_wx_GridSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int rows = arg.GetNumber(0)
	//pThis->GetEntity()->SetRows();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridSizer, SetVGap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "gap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridSizer, SetVGap)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridSizer *pThis = Object_wx_GridSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int gap = arg.GetNumber(0)
	//pThis->GetEntity()->SetVGap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridSizer, CalcMin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridSizer, CalcMin)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridSizer *pThis = Object_wx_GridSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CalcMin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridSizer, RecalcSizes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridSizer, RecalcSizes)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridSizer *pThis = Object_wx_GridSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->RecalcSizes();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGridSizer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridSizer)
{
	Gura_AssignMethod(wx_GridSizer, wxGridSizer);
	Gura_AssignMethod(wx_GridSizer, wxGridSizer_1);
	Gura_AssignMethod(wx_GridSizer, wxGridSizer_2);
	Gura_AssignMethod(wx_GridSizer, wxGridSizer_3);
	Gura_AssignMethod(wx_GridSizer, GetCols);
	Gura_AssignMethod(wx_GridSizer, GetRows);
	Gura_AssignMethod(wx_GridSizer, GetEffectiveColsCount);
	Gura_AssignMethod(wx_GridSizer, GetEffectiveRowsCount);
	Gura_AssignMethod(wx_GridSizer, GetHGap);
	Gura_AssignMethod(wx_GridSizer, GetVGap);
	Gura_AssignMethod(wx_GridSizer, SetCols);
	Gura_AssignMethod(wx_GridSizer, SetHGap);
	Gura_AssignMethod(wx_GridSizer, SetRows);
	Gura_AssignMethod(wx_GridSizer, SetVGap);
	Gura_AssignMethod(wx_GridSizer, CalcMin);
	Gura_AssignMethod(wx_GridSizer, RecalcSizes);
}

Gura_ImplementDescendantCreator(wx_GridSizer)
{
	return new Object_wx_GridSizer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
