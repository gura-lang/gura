//----------------------------------------------------------------------------
// wxAcceleratorTable
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAcceleratorTable
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAcceleratorTable
//----------------------------------------------------------------------------
Object_wx_AcceleratorTable::~Object_wx_AcceleratorTable()
{
}

Object *Object_wx_AcceleratorTable::Clone() const
{
	return nullptr;
}

String Object_wx_AcceleratorTable::ToString(bool exprFlag)
{
	String rtn("<wx.AcceleratorTable:");
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
Gura_DeclareFunctionAlias(__wxAcceleratorTable, "wxAcceleratorTable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(__wxAcceleratorTable)
{
	//wxAcceleratorTable();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxAcceleratorTable_1, "wxAcceleratorTable_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "entries", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxAcceleratorTable_1)
{
	//int n = arg.GetNumber(0)
	//int entries = arg.GetNumber(1)
	//wxAcceleratorTable();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxAcceleratorTable_2, "wxAcceleratorTable_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "resource", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxAcceleratorTable_2)
{
	//int resource = arg.GetNumber(0)
	//wxAcceleratorTable();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_AcceleratorTable, __IsOk, "IsOk")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AcceleratorTable, __IsOk)
{
	Object_wx_AcceleratorTable *pThis = Object_wx_AcceleratorTable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxAcceleratorTable
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AcceleratorTable)
{
	// Constructor assignment
	Gura_AssignFunction(__wxAcceleratorTable);
	Gura_AssignFunction(__wxAcceleratorTable_1);
	Gura_AssignFunction(__wxAcceleratorTable_2);
	// Method assignment
	Gura_AssignMethod(wx_AcceleratorTable, __IsOk);
}

Gura_ImplementDescendantCreator(wx_AcceleratorTable)
{
	return new Object_wx_AcceleratorTable((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
