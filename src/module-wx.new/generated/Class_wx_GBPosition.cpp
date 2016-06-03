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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxGBPosition, "wxGBPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(__wxGBPosition)
{
	//wxGBPosition();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxGBPosition_1, "wxGBPosition_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxGBPosition_1)
{
	//int row = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//wxGBPosition();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_GBPosition, __GetCol, "GetCol")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GBPosition, __GetCol)
{
	Object_wx_GBPosition *pThis = Object_wx_GBPosition::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCol();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GBPosition, __GetRow, "GetRow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GBPosition, __GetRow)
{
	Object_wx_GBPosition *pThis = Object_wx_GBPosition::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GBPosition, __SetCol, "SetCol")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GBPosition, __SetCol)
{
	Object_wx_GBPosition *pThis = Object_wx_GBPosition::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->SetCol();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GBPosition, __SetRow, "SetRow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GBPosition, __SetRow)
{
	Object_wx_GBPosition *pThis = Object_wx_GBPosition::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int row = arg.GetNumber(0)
	//pThis->GetEntity()->SetRow();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGBPosition
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GBPosition)
{
	// Constructor assignment
	Gura_AssignFunction(__wxGBPosition);
	Gura_AssignFunction(__wxGBPosition_1);
	// Method assignment
	Gura_AssignMethod(wx_GBPosition, __GetCol);
	Gura_AssignMethod(wx_GBPosition, __GetRow);
	Gura_AssignMethod(wx_GBPosition, __SetCol);
	Gura_AssignMethod(wx_GBPosition, __SetRow);
}

Gura_ImplementDescendantCreator(wx_GBPosition)
{
	return new Object_wx_GBPosition((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
