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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__GridSizer, "GridSizer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cols", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "vgap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "hgap", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_GridSizer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__GridSizer)
{
	//int cols = arg.GetNumber(0)
	//int vgap = arg.GetNumber(1)
	//int hgap = arg.GetNumber(2)
	//wxGridSizer(cols, vgap, hgap);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__GridSizer_1, "GridSizer_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cols", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "gap", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_GridSizer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__GridSizer_1)
{
	//int cols = arg.GetNumber(0)
	//const wxSize& gap = arg.GetNumber(1)
	//wxGridSizer(cols, gap);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__GridSizer_2, "GridSizer_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rows", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cols", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "vgap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "hgap", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_GridSizer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__GridSizer_2)
{
	//int rows = arg.GetNumber(0)
	//int cols = arg.GetNumber(1)
	//int vgap = arg.GetNumber(2)
	//int hgap = arg.GetNumber(3)
	//wxGridSizer(rows, cols, vgap, hgap);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__GridSizer_3, "GridSizer_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rows", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cols", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "gap", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_GridSizer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__GridSizer_3)
{
	//int rows = arg.GetNumber(0)
	//int cols = arg.GetNumber(1)
	//const wxSize& gap = arg.GetNumber(2)
	//wxGridSizer(rows, cols, gap);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_GridSizer, __GetCols, "GetCols")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridSizer, __GetCols)
{
	Object_wx_GridSizer *pThis = Object_wx_GridSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCols();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridSizer, __GetRows, "GetRows")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridSizer, __GetRows)
{
	Object_wx_GridSizer *pThis = Object_wx_GridSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRows();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridSizer, __GetEffectiveColsCount, "GetEffectiveColsCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridSizer, __GetEffectiveColsCount)
{
	Object_wx_GridSizer *pThis = Object_wx_GridSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEffectiveColsCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridSizer, __GetEffectiveRowsCount, "GetEffectiveRowsCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridSizer, __GetEffectiveRowsCount)
{
	Object_wx_GridSizer *pThis = Object_wx_GridSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEffectiveRowsCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridSizer, __GetHGap, "GetHGap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridSizer, __GetHGap)
{
	Object_wx_GridSizer *pThis = Object_wx_GridSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHGap();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridSizer, __GetVGap, "GetVGap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridSizer, __GetVGap)
{
	Object_wx_GridSizer *pThis = Object_wx_GridSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetVGap();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridSizer, __SetCols, "SetCols")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cols", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridSizer, __SetCols)
{
	Object_wx_GridSizer *pThis = Object_wx_GridSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int cols = arg.GetNumber(0)
	//pThis->GetEntity()->SetCols(cols);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridSizer, __SetHGap, "SetHGap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "gap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridSizer, __SetHGap)
{
	Object_wx_GridSizer *pThis = Object_wx_GridSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int gap = arg.GetNumber(0)
	//pThis->GetEntity()->SetHGap(gap);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridSizer, __SetRows, "SetRows")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rows", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridSizer, __SetRows)
{
	Object_wx_GridSizer *pThis = Object_wx_GridSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rows = arg.GetNumber(0)
	//pThis->GetEntity()->SetRows(rows);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridSizer, __SetVGap, "SetVGap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "gap", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridSizer, __SetVGap)
{
	Object_wx_GridSizer *pThis = Object_wx_GridSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int gap = arg.GetNumber(0)
	//pThis->GetEntity()->SetVGap(gap);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridSizer, __CalcMin, "CalcMin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridSizer, __CalcMin)
{
	Object_wx_GridSizer *pThis = Object_wx_GridSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CalcMin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridSizer, __RecalcSizes, "RecalcSizes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridSizer, __RecalcSizes)
{
	Object_wx_GridSizer *pThis = Object_wx_GridSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->RecalcSizes();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGridSizer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridSizer)
{
	// Constructor assignment
	Gura_AssignFunction(__GridSizer);
	Gura_AssignFunction(__GridSizer_1);
	Gura_AssignFunction(__GridSizer_2);
	Gura_AssignFunction(__GridSizer_3);
	// Method assignment
	Gura_AssignMethod(wx_GridSizer, __GetCols);
	Gura_AssignMethod(wx_GridSizer, __GetRows);
	Gura_AssignMethod(wx_GridSizer, __GetEffectiveColsCount);
	Gura_AssignMethod(wx_GridSizer, __GetEffectiveRowsCount);
	Gura_AssignMethod(wx_GridSizer, __GetHGap);
	Gura_AssignMethod(wx_GridSizer, __GetVGap);
	Gura_AssignMethod(wx_GridSizer, __SetCols);
	Gura_AssignMethod(wx_GridSizer, __SetHGap);
	Gura_AssignMethod(wx_GridSizer, __SetRows);
	Gura_AssignMethod(wx_GridSizer, __SetVGap);
	Gura_AssignMethod(wx_GridSizer, __CalcMin);
	Gura_AssignMethod(wx_GridSizer, __RecalcSizes);
}

Gura_ImplementDescendantCreator(wx_GridSizer)
{
	return new Object_wx_GridSizer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
