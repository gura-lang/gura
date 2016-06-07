//----------------------------------------------------------------------------
// wxGridCellCoords
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGridCellCoords
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridCellCoords
//----------------------------------------------------------------------------
Object_wx_GridCellCoords::~Object_wx_GridCellCoords()
{
}

Object *Object_wx_GridCellCoords::Clone() const
{
	return nullptr;
}

String Object_wx_GridCellCoords::ToString(bool exprFlag)
{
	String rtn("<wx.GridCellCoords:");
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
Gura_DeclareFunctionAlias(__GridCellCoords, "GridCellCoords")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_GridCellCoords));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__GridCellCoords)
{
	//wxGridCellCoords();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__GridCellCoords_1, "GridCellCoords_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_GridCellCoords));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__GridCellCoords_1)
{
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//wxGridCellCoords(row, col);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_GridCellCoords, __GetRow, "GetRow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridCellCoords, __GetRow)
{
	Object_wx_GridCellCoords *pThis = Object_wx_GridCellCoords::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridCellCoords, __SetRow, "SetRow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellCoords, __SetRow)
{
	Object_wx_GridCellCoords *pThis = Object_wx_GridCellCoords::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->SetRow(n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridCellCoords, __GetCol, "GetCol")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridCellCoords, __GetCol)
{
	Object_wx_GridCellCoords *pThis = Object_wx_GridCellCoords::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCol();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridCellCoords, __SetCol, "SetCol")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellCoords, __SetCol)
{
	Object_wx_GridCellCoords *pThis = Object_wx_GridCellCoords::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->SetCol(n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridCellCoords, __Set, "Set")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellCoords, __Set)
{
	Object_wx_GridCellCoords *pThis = Object_wx_GridCellCoords::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//pThis->GetEntity()->Set(row, col);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGridCellCoords
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellCoords)
{
	// Constructor assignment
	Gura_AssignFunction(__GridCellCoords);
	Gura_AssignFunction(__GridCellCoords_1);
	// Method assignment
	Gura_AssignMethod(wx_GridCellCoords, __GetRow);
	Gura_AssignMethod(wx_GridCellCoords, __SetRow);
	Gura_AssignMethod(wx_GridCellCoords, __GetCol);
	Gura_AssignMethod(wx_GridCellCoords, __SetCol);
	Gura_AssignMethod(wx_GridCellCoords, __Set);
}

Gura_ImplementDescendantCreator(wx_GridCellCoords)
{
	return new Object_wx_GridCellCoords((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
