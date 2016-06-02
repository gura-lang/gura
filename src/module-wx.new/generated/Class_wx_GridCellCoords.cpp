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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_GridCellCoords, wxGridCellCoords)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridCellCoords, wxGridCellCoords)
{
	Object_wx_GridCellCoords *pThis = Object_wx_GridCellCoords::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxGridCellCoords();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellCoords, wxGridCellCoords_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellCoords, wxGridCellCoords_1)
{
	Object_wx_GridCellCoords *pThis = Object_wx_GridCellCoords::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//pThis->GetEntity()->wxGridCellCoords();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellCoords, GetRow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridCellCoords, GetRow)
{
	Object_wx_GridCellCoords *pThis = Object_wx_GridCellCoords::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellCoords, SetRow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellCoords, SetRow)
{
	Object_wx_GridCellCoords *pThis = Object_wx_GridCellCoords::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->SetRow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellCoords, GetCol)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridCellCoords, GetCol)
{
	Object_wx_GridCellCoords *pThis = Object_wx_GridCellCoords::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCol();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellCoords, SetCol)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellCoords, SetCol)
{
	Object_wx_GridCellCoords *pThis = Object_wx_GridCellCoords::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->SetCol();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridCellCoords, Set)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridCellCoords, Set)
{
	Object_wx_GridCellCoords *pThis = Object_wx_GridCellCoords::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//pThis->GetEntity()->Set();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGridCellCoords
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellCoords)
{
	Gura_AssignMethod(wx_GridCellCoords, wxGridCellCoords);
	Gura_AssignMethod(wx_GridCellCoords, wxGridCellCoords_1);
	Gura_AssignMethod(wx_GridCellCoords, GetRow);
	Gura_AssignMethod(wx_GridCellCoords, SetRow);
	Gura_AssignMethod(wx_GridCellCoords, GetCol);
	Gura_AssignMethod(wx_GridCellCoords, SetCol);
	Gura_AssignMethod(wx_GridCellCoords, Set);
}

Gura_ImplementDescendantCreator(wx_GridCellCoords)
{
	return new Object_wx_GridCellCoords((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
