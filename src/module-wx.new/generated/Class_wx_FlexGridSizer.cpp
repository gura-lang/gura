//----------------------------------------------------------------------------
// wxFlexGridSizer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFlexGridSizer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFlexGridSizer
//----------------------------------------------------------------------------
Object_wx_FlexGridSizer::~Object_wx_FlexGridSizer()
{
}

Object *Object_wx_FlexGridSizer::Clone() const
{
	return nullptr;
}

String Object_wx_FlexGridSizer::ToString(bool exprFlag)
{
	String rtn("<wx.FlexGridSizer:");
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
Gura_DeclareMethod(wx_FlexGridSizer, wxFlexGridSizer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cols", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "vgap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "hgap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FlexGridSizer, wxFlexGridSizer)
{
	Signal &sig = env.GetSignal();
	Object_wx_FlexGridSizer *pThis = Object_wx_FlexGridSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int cols = arg.GetNumber(0)
	//int vgap = arg.GetNumber(1)
	//int hgap = arg.GetNumber(2)
	//pThis->GetEntity()->wxFlexGridSizer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FlexGridSizer, wxFlexGridSizer_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cols", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "gap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FlexGridSizer, wxFlexGridSizer_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_FlexGridSizer *pThis = Object_wx_FlexGridSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int cols = arg.GetNumber(0)
	//int gap = arg.GetNumber(1)
	//pThis->GetEntity()->wxFlexGridSizer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FlexGridSizer, wxFlexGridSizer_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rows", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cols", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "vgap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "hgap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FlexGridSizer, wxFlexGridSizer_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_FlexGridSizer *pThis = Object_wx_FlexGridSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int rows = arg.GetNumber(0)
	//int cols = arg.GetNumber(1)
	//int vgap = arg.GetNumber(2)
	//int hgap = arg.GetNumber(3)
	//pThis->GetEntity()->wxFlexGridSizer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FlexGridSizer, wxFlexGridSizer_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rows", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cols", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "gap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FlexGridSizer, wxFlexGridSizer_3)
{
	Signal &sig = env.GetSignal();
	Object_wx_FlexGridSizer *pThis = Object_wx_FlexGridSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int rows = arg.GetNumber(0)
	//int cols = arg.GetNumber(1)
	//int gap = arg.GetNumber(2)
	//pThis->GetEntity()->wxFlexGridSizer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FlexGridSizer, AddGrowableCol)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "proportion", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FlexGridSizer, AddGrowableCol)
{
	Signal &sig = env.GetSignal();
	Object_wx_FlexGridSizer *pThis = Object_wx_FlexGridSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int idx = arg.GetNumber(0)
	//int proportion = arg.GetNumber(1)
	//pThis->GetEntity()->AddGrowableCol();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FlexGridSizer, AddGrowableRow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "proportion", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FlexGridSizer, AddGrowableRow)
{
	Signal &sig = env.GetSignal();
	Object_wx_FlexGridSizer *pThis = Object_wx_FlexGridSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int idx = arg.GetNumber(0)
	//int proportion = arg.GetNumber(1)
	//pThis->GetEntity()->AddGrowableRow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FlexGridSizer, GetFlexibleDirection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FlexGridSizer, GetFlexibleDirection)
{
	Signal &sig = env.GetSignal();
	Object_wx_FlexGridSizer *pThis = Object_wx_FlexGridSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFlexibleDirection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FlexGridSizer, GetNonFlexibleGrowMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FlexGridSizer, GetNonFlexibleGrowMode)
{
	Signal &sig = env.GetSignal();
	Object_wx_FlexGridSizer *pThis = Object_wx_FlexGridSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetNonFlexibleGrowMode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FlexGridSizer, IsColGrowable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FlexGridSizer, IsColGrowable)
{
	Signal &sig = env.GetSignal();
	Object_wx_FlexGridSizer *pThis = Object_wx_FlexGridSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int idx = arg.GetNumber(0)
	//pThis->GetEntity()->IsColGrowable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FlexGridSizer, IsRowGrowable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FlexGridSizer, IsRowGrowable)
{
	Signal &sig = env.GetSignal();
	Object_wx_FlexGridSizer *pThis = Object_wx_FlexGridSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int idx = arg.GetNumber(0)
	//pThis->GetEntity()->IsRowGrowable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FlexGridSizer, RemoveGrowableCol)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FlexGridSizer, RemoveGrowableCol)
{
	Signal &sig = env.GetSignal();
	Object_wx_FlexGridSizer *pThis = Object_wx_FlexGridSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int idx = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveGrowableCol();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FlexGridSizer, RemoveGrowableRow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FlexGridSizer, RemoveGrowableRow)
{
	Signal &sig = env.GetSignal();
	Object_wx_FlexGridSizer *pThis = Object_wx_FlexGridSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int idx = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveGrowableRow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FlexGridSizer, SetFlexibleDirection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "direction", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FlexGridSizer, SetFlexibleDirection)
{
	Signal &sig = env.GetSignal();
	Object_wx_FlexGridSizer *pThis = Object_wx_FlexGridSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int direction = arg.GetNumber(0)
	//pThis->GetEntity()->SetFlexibleDirection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FlexGridSizer, SetNonFlexibleGrowMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FlexGridSizer, SetNonFlexibleGrowMode)
{
	Signal &sig = env.GetSignal();
	Object_wx_FlexGridSizer *pThis = Object_wx_FlexGridSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int mode = arg.GetNumber(0)
	//pThis->GetEntity()->SetNonFlexibleGrowMode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FlexGridSizer, GetRowHeights)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FlexGridSizer, GetRowHeights)
{
	Signal &sig = env.GetSignal();
	Object_wx_FlexGridSizer *pThis = Object_wx_FlexGridSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetRowHeights();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FlexGridSizer, GetColWidths)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FlexGridSizer, GetColWidths)
{
	Signal &sig = env.GetSignal();
	Object_wx_FlexGridSizer *pThis = Object_wx_FlexGridSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetColWidths();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FlexGridSizer, RecalcSizes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FlexGridSizer, RecalcSizes)
{
	Signal &sig = env.GetSignal();
	Object_wx_FlexGridSizer *pThis = Object_wx_FlexGridSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->RecalcSizes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FlexGridSizer, CalcMin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FlexGridSizer, CalcMin)
{
	Signal &sig = env.GetSignal();
	Object_wx_FlexGridSizer *pThis = Object_wx_FlexGridSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CalcMin();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFlexGridSizer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FlexGridSizer)
{
	Gura_AssignMethod(wx_FlexGridSizer, wxFlexGridSizer);
	Gura_AssignMethod(wx_FlexGridSizer, wxFlexGridSizer_1);
	Gura_AssignMethod(wx_FlexGridSizer, wxFlexGridSizer_2);
	Gura_AssignMethod(wx_FlexGridSizer, wxFlexGridSizer_3);
	Gura_AssignMethod(wx_FlexGridSizer, AddGrowableCol);
	Gura_AssignMethod(wx_FlexGridSizer, AddGrowableRow);
	Gura_AssignMethod(wx_FlexGridSizer, GetFlexibleDirection);
	Gura_AssignMethod(wx_FlexGridSizer, GetNonFlexibleGrowMode);
	Gura_AssignMethod(wx_FlexGridSizer, IsColGrowable);
	Gura_AssignMethod(wx_FlexGridSizer, IsRowGrowable);
	Gura_AssignMethod(wx_FlexGridSizer, RemoveGrowableCol);
	Gura_AssignMethod(wx_FlexGridSizer, RemoveGrowableRow);
	Gura_AssignMethod(wx_FlexGridSizer, SetFlexibleDirection);
	Gura_AssignMethod(wx_FlexGridSizer, SetNonFlexibleGrowMode);
	Gura_AssignMethod(wx_FlexGridSizer, GetRowHeights);
	Gura_AssignMethod(wx_FlexGridSizer, GetColWidths);
	Gura_AssignMethod(wx_FlexGridSizer, RecalcSizes);
	Gura_AssignMethod(wx_FlexGridSizer, CalcMin);
}

Gura_ImplementDescendantCreator(wx_FlexGridSizer)
{
	return new Object_wx_FlexGridSizer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
