//----------------------------------------------------------------------------
// wxPosition
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPosition
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPosition
//----------------------------------------------------------------------------
Object_wx_Position::~Object_wx_Position()
{
}

Object *Object_wx_Position::Clone() const
{
	return nullptr;
}

String Object_wx_Position::ToString(bool exprFlag)
{
	String rtn("<wx.Position:");
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
Gura_DeclareFunctionAlias(__Position, "Position")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Position));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Position)
{
	//wxPosition();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Position_1, "Position_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Position));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Position_1)
{
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//wxPosition();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Position, __GetCol, "GetCol")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Position, __GetCol)
{
	Object_wx_Position *pThis = Object_wx_Position::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCol();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Position, __GetColumn, "GetColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Position, __GetColumn)
{
	Object_wx_Position *pThis = Object_wx_Position::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetColumn();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Position, __GetRow, "GetRow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Position, __GetRow)
{
	Object_wx_Position *pThis = Object_wx_Position::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Position, __SetCol, "SetCol")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Position, __SetCol)
{
	Object_wx_Position *pThis = Object_wx_Position::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int column = arg.GetNumber(0)
	//pThis->GetEntity()->SetCol();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Position, __SetColumn, "SetColumn")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Position, __SetColumn)
{
	Object_wx_Position *pThis = Object_wx_Position::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int column = arg.GetNumber(0)
	//pThis->GetEntity()->SetColumn();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Position, __SetRow, "SetRow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Position, __SetRow)
{
	Object_wx_Position *pThis = Object_wx_Position::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//pThis->GetEntity()->SetRow();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPosition
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Position)
{
	// Constructor assignment
	Gura_AssignFunction(__Position);
	Gura_AssignFunction(__Position_1);
	// Method assignment
	Gura_AssignMethod(wx_Position, __GetCol);
	Gura_AssignMethod(wx_Position, __GetColumn);
	Gura_AssignMethod(wx_Position, __GetRow);
	Gura_AssignMethod(wx_Position, __SetCol);
	Gura_AssignMethod(wx_Position, __SetColumn);
	Gura_AssignMethod(wx_Position, __SetRow);
}

Gura_ImplementDescendantCreator(wx_Position)
{
	return new Object_wx_Position((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
