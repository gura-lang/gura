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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__FlexGridSizer, "FlexGridSizer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cols", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "vgap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "hgap", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_FlexGridSizer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__FlexGridSizer)
{
	//int cols = arg.GetNumber(0)
	//int vgap = arg.GetNumber(1)
	//int hgap = arg.GetNumber(2)
	//wxFlexGridSizer(cols, vgap, hgap);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__FlexGridSizer_1, "FlexGridSizer_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cols", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "gap", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_FlexGridSizer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__FlexGridSizer_1)
{
	//int cols = arg.GetNumber(0)
	//const wxSize& gap = arg.GetNumber(1)
	//wxFlexGridSizer(cols, gap);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__FlexGridSizer_2, "FlexGridSizer_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rows", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cols", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "vgap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "hgap", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_FlexGridSizer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__FlexGridSizer_2)
{
	//int rows = arg.GetNumber(0)
	//int cols = arg.GetNumber(1)
	//int vgap = arg.GetNumber(2)
	//int hgap = arg.GetNumber(3)
	//wxFlexGridSizer(rows, cols, vgap, hgap);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__FlexGridSizer_3, "FlexGridSizer_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rows", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cols", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "gap", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_FlexGridSizer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__FlexGridSizer_3)
{
	//int rows = arg.GetNumber(0)
	//int cols = arg.GetNumber(1)
	//const wxSize& gap = arg.GetNumber(2)
	//wxFlexGridSizer(rows, cols, gap);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_FlexGridSizer, __AddGrowableCol, "AddGrowableCol")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "proportion", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FlexGridSizer, __AddGrowableCol)
{
	Object_wx_FlexGridSizer *pThis = Object_wx_FlexGridSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t idx = arg.GetNumber(0)
	//int proportion = arg.GetNumber(1)
	//pThis->GetEntity()->AddGrowableCol(idx, proportion);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FlexGridSizer, __AddGrowableRow, "AddGrowableRow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "proportion", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FlexGridSizer, __AddGrowableRow)
{
	Object_wx_FlexGridSizer *pThis = Object_wx_FlexGridSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t idx = arg.GetNumber(0)
	//int proportion = arg.GetNumber(1)
	//pThis->GetEntity()->AddGrowableRow(idx, proportion);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FlexGridSizer, __GetFlexibleDirection, "GetFlexibleDirection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FlexGridSizer, __GetFlexibleDirection)
{
	Object_wx_FlexGridSizer *pThis = Object_wx_FlexGridSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFlexibleDirection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FlexGridSizer, __GetNonFlexibleGrowMode, "GetNonFlexibleGrowMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FlexGridSizer, __GetNonFlexibleGrowMode)
{
	Object_wx_FlexGridSizer *pThis = Object_wx_FlexGridSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetNonFlexibleGrowMode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FlexGridSizer, __IsColGrowable, "IsColGrowable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FlexGridSizer, __IsColGrowable)
{
	Object_wx_FlexGridSizer *pThis = Object_wx_FlexGridSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t idx = arg.GetNumber(0)
	//pThis->GetEntity()->IsColGrowable(idx);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FlexGridSizer, __IsRowGrowable, "IsRowGrowable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FlexGridSizer, __IsRowGrowable)
{
	Object_wx_FlexGridSizer *pThis = Object_wx_FlexGridSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t idx = arg.GetNumber(0)
	//pThis->GetEntity()->IsRowGrowable(idx);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FlexGridSizer, __RemoveGrowableCol, "RemoveGrowableCol")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FlexGridSizer, __RemoveGrowableCol)
{
	Object_wx_FlexGridSizer *pThis = Object_wx_FlexGridSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t idx = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveGrowableCol(idx);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FlexGridSizer, __RemoveGrowableRow, "RemoveGrowableRow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "idx", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FlexGridSizer, __RemoveGrowableRow)
{
	Object_wx_FlexGridSizer *pThis = Object_wx_FlexGridSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t idx = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveGrowableRow(idx);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FlexGridSizer, __SetFlexibleDirection, "SetFlexibleDirection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "direction", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FlexGridSizer, __SetFlexibleDirection)
{
	Object_wx_FlexGridSizer *pThis = Object_wx_FlexGridSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int direction = arg.GetNumber(0)
	//pThis->GetEntity()->SetFlexibleDirection(direction);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FlexGridSizer, __SetNonFlexibleGrowMode, "SetNonFlexibleGrowMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FlexGridSizer, __SetNonFlexibleGrowMode)
{
	Object_wx_FlexGridSizer *pThis = Object_wx_FlexGridSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFlexSizerGrowMode mode = arg.GetNumber(0)
	//pThis->GetEntity()->SetNonFlexibleGrowMode(mode);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FlexGridSizer, __GetRowHeights, "GetRowHeights")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FlexGridSizer, __GetRowHeights)
{
	Object_wx_FlexGridSizer *pThis = Object_wx_FlexGridSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRowHeights();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FlexGridSizer, __GetColWidths, "GetColWidths")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FlexGridSizer, __GetColWidths)
{
	Object_wx_FlexGridSizer *pThis = Object_wx_FlexGridSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetColWidths();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FlexGridSizer, __RecalcSizes, "RecalcSizes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FlexGridSizer, __RecalcSizes)
{
	Object_wx_FlexGridSizer *pThis = Object_wx_FlexGridSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->RecalcSizes();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FlexGridSizer, __CalcMin, "CalcMin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FlexGridSizer, __CalcMin)
{
	Object_wx_FlexGridSizer *pThis = Object_wx_FlexGridSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CalcMin();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFlexGridSizer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FlexGridSizer)
{
	// Constructor assignment
	Gura_AssignFunction(__FlexGridSizer);
	Gura_AssignFunction(__FlexGridSizer_1);
	Gura_AssignFunction(__FlexGridSizer_2);
	Gura_AssignFunction(__FlexGridSizer_3);
	// Method assignment
	Gura_AssignMethod(wx_FlexGridSizer, __AddGrowableCol);
	Gura_AssignMethod(wx_FlexGridSizer, __AddGrowableRow);
	Gura_AssignMethod(wx_FlexGridSizer, __GetFlexibleDirection);
	Gura_AssignMethod(wx_FlexGridSizer, __GetNonFlexibleGrowMode);
	Gura_AssignMethod(wx_FlexGridSizer, __IsColGrowable);
	Gura_AssignMethod(wx_FlexGridSizer, __IsRowGrowable);
	Gura_AssignMethod(wx_FlexGridSizer, __RemoveGrowableCol);
	Gura_AssignMethod(wx_FlexGridSizer, __RemoveGrowableRow);
	Gura_AssignMethod(wx_FlexGridSizer, __SetFlexibleDirection);
	Gura_AssignMethod(wx_FlexGridSizer, __SetNonFlexibleGrowMode);
	Gura_AssignMethod(wx_FlexGridSizer, __GetRowHeights);
	Gura_AssignMethod(wx_FlexGridSizer, __GetColWidths);
	Gura_AssignMethod(wx_FlexGridSizer, __RecalcSizes);
	Gura_AssignMethod(wx_FlexGridSizer, __CalcMin);
}

Gura_ImplementDescendantCreator(wx_FlexGridSizer)
{
	return new Object_wx_FlexGridSizer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
