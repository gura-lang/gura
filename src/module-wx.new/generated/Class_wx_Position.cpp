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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_Position, wxPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Position, wxPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_Position *pThis = Object_wx_Position::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Position, wxPosition_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Position, wxPosition_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Position *pThis = Object_wx_Position::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//pThis->GetEntity()->wxPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Position, GetCol)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Position, GetCol)
{
	Signal &sig = env.GetSignal();
	Object_wx_Position *pThis = Object_wx_Position::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetCol();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Position, GetColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Position, GetColumn)
{
	Signal &sig = env.GetSignal();
	Object_wx_Position *pThis = Object_wx_Position::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Position, GetRow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Position, GetRow)
{
	Signal &sig = env.GetSignal();
	Object_wx_Position *pThis = Object_wx_Position::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetRow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Position, SetCol)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Position, SetCol)
{
	Signal &sig = env.GetSignal();
	Object_wx_Position *pThis = Object_wx_Position::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int column = arg.GetNumber(0)
	//pThis->GetEntity()->SetCol();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Position, SetColumn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "column", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Position, SetColumn)
{
	Signal &sig = env.GetSignal();
	Object_wx_Position *pThis = Object_wx_Position::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int column = arg.GetNumber(0)
	//pThis->GetEntity()->SetColumn();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Position, SetRow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Position, SetRow)
{
	Signal &sig = env.GetSignal();
	Object_wx_Position *pThis = Object_wx_Position::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//pThis->GetEntity()->SetRow();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPosition
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Position)
{
	Gura_AssignMethod(wx_Position, wxPosition);
	Gura_AssignMethod(wx_Position, wxPosition_1);
	Gura_AssignMethod(wx_Position, GetCol);
	Gura_AssignMethod(wx_Position, GetColumn);
	Gura_AssignMethod(wx_Position, GetRow);
	Gura_AssignMethod(wx_Position, SetCol);
	Gura_AssignMethod(wx_Position, SetColumn);
	Gura_AssignMethod(wx_Position, SetRow);
}

Gura_ImplementDescendantCreator(wx_Position)
{
	return new Object_wx_Position((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
