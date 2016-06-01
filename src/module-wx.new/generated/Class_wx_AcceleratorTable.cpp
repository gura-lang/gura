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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_AcceleratorTable, wxAcceleratorTable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AcceleratorTable, wxAcceleratorTable)
{
	Signal &sig = env.GetSignal();
	Object_wx_AcceleratorTable *pThis = Object_wx_AcceleratorTable::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxAcceleratorTable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AcceleratorTable, wxAcceleratorTable_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "entries", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AcceleratorTable, wxAcceleratorTable_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_AcceleratorTable *pThis = Object_wx_AcceleratorTable::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//int entries = arg.GetNumber(1)
	//pThis->GetEntity()->wxAcceleratorTable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AcceleratorTable, wxAcceleratorTable_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "resource", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AcceleratorTable, wxAcceleratorTable_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_AcceleratorTable *pThis = Object_wx_AcceleratorTable::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int resource = arg.GetNumber(0)
	//pThis->GetEntity()->wxAcceleratorTable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AcceleratorTable, ~wxAcceleratorTable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AcceleratorTable, ~wxAcceleratorTable)
{
	Signal &sig = env.GetSignal();
	Object_wx_AcceleratorTable *pThis = Object_wx_AcceleratorTable::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxAcceleratorTable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AcceleratorTable, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AcceleratorTable, IsOk)
{
	Signal &sig = env.GetSignal();
	Object_wx_AcceleratorTable *pThis = Object_wx_AcceleratorTable::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxAcceleratorTable
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AcceleratorTable)
{
	Gura_AssignMethod(wx_AcceleratorTable, wxAcceleratorTable);
	Gura_AssignMethod(wx_AcceleratorTable, wxAcceleratorTable_1);
	Gura_AssignMethod(wx_AcceleratorTable, wxAcceleratorTable_2);
	Gura_AssignMethod(wx_AcceleratorTable, ~wxAcceleratorTable);
	Gura_AssignMethod(wx_AcceleratorTable, IsOk);
}

Gura_ImplementDescendantCreator(wx_AcceleratorTable)
{
	return new Object_wx_AcceleratorTable((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
