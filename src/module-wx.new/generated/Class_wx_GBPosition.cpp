//----------------------------------------------------------------------------
// wxGBPosition
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGBPosition
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGBPosition
//----------------------------------------------------------------------------
Object_wx_GBPosition::~Object_wx_GBPosition()
{
}

Object *Object_wx_GBPosition::Clone() const
{
	return nullptr;
}

String Object_wx_GBPosition::ToString(bool exprFlag)
{
	String rtn("<wx.GBPosition:");
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
Gura_DeclareMethod(wx_GBPosition, wxGBPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GBPosition, wxGBPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_GBPosition *pThis = Object_wx_GBPosition::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxGBPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GBPosition, wxGBPosition_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GBPosition, wxGBPosition_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_GBPosition *pThis = Object_wx_GBPosition::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//pThis->GetEntity()->wxGBPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GBPosition, GetCol)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GBPosition, GetCol)
{
	Signal &sig = env.GetSignal();
	Object_wx_GBPosition *pThis = Object_wx_GBPosition::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetCol();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GBPosition, GetRow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GBPosition, GetRow)
{
	Signal &sig = env.GetSignal();
	Object_wx_GBPosition *pThis = Object_wx_GBPosition::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetRow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GBPosition, SetCol)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GBPosition, SetCol)
{
	Signal &sig = env.GetSignal();
	Object_wx_GBPosition *pThis = Object_wx_GBPosition::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->SetCol();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GBPosition, SetRow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GBPosition, SetRow)
{
	Signal &sig = env.GetSignal();
	Object_wx_GBPosition *pThis = Object_wx_GBPosition::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//pThis->GetEntity()->SetRow();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGBPosition
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GBPosition)
{
	Gura_AssignMethod(wx_GBPosition, wxGBPosition);
	Gura_AssignMethod(wx_GBPosition, wxGBPosition_1);
	Gura_AssignMethod(wx_GBPosition, GetCol);
	Gura_AssignMethod(wx_GBPosition, GetRow);
	Gura_AssignMethod(wx_GBPosition, SetCol);
	Gura_AssignMethod(wx_GBPosition, SetRow);
}

Gura_ImplementDescendantCreator(wx_GBPosition)
{
	return new Object_wx_GBPosition((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
