//----------------------------------------------------------------------------
// wxGraphicsGradientStops
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGraphicsGradientStops
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGraphicsGradientStops
//----------------------------------------------------------------------------
Object_wx_GraphicsGradientStops::~Object_wx_GraphicsGradientStops()
{
}

Object *Object_wx_GraphicsGradientStops::Clone() const
{
	return nullptr;
}

String Object_wx_GraphicsGradientStops::ToString(bool exprFlag)
{
	String rtn("<wx.GraphicsGradientStops:");
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
Gura_DeclareFunctionAlias(__wxGraphicsGradientStops, "wxGraphicsGradientStops")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "startCol", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "endCol", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxGraphicsGradientStops)
{
	//int startCol = arg.GetNumber(0)
	//int endCol = arg.GetNumber(1)
	//wxGraphicsGradientStops();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_GraphicsGradientStops, __Add, "Add")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stop", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsGradientStops, __Add)
{
	Object_wx_GraphicsGradientStops *pThis = Object_wx_GraphicsGradientStops::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stop = arg.GetNumber(0)
	//pThis->GetEntity()->Add();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsGradientStops, __Add_1, "Add_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsGradientStops, __Add_1)
{
	Object_wx_GraphicsGradientStops *pThis = Object_wx_GraphicsGradientStops::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//pThis->GetEntity()->Add();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsGradientStops, __Item, "Item")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsGradientStops, __Item)
{
	Object_wx_GraphicsGradientStops *pThis = Object_wx_GraphicsGradientStops::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->Item();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsGradientStops, __GetCount, "GetCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsGradientStops, __GetCount)
{
	Object_wx_GraphicsGradientStops *pThis = Object_wx_GraphicsGradientStops::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsGradientStops, __SetStartColour, "SetStartColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsGradientStops, __SetStartColour)
{
	Object_wx_GraphicsGradientStops *pThis = Object_wx_GraphicsGradientStops::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->SetStartColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsGradientStops, __GetStartColour, "GetStartColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsGradientStops, __GetStartColour)
{
	Object_wx_GraphicsGradientStops *pThis = Object_wx_GraphicsGradientStops::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStartColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsGradientStops, __SetEndColour, "SetEndColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsGradientStops, __SetEndColour)
{
	Object_wx_GraphicsGradientStops *pThis = Object_wx_GraphicsGradientStops::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->SetEndColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsGradientStops, __GetEndColour, "GetEndColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsGradientStops, __GetEndColour)
{
	Object_wx_GraphicsGradientStops *pThis = Object_wx_GraphicsGradientStops::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEndColour();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGraphicsGradientStops
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GraphicsGradientStops)
{
	// Constructor assignment
	Gura_AssignFunction(__wxGraphicsGradientStops);
	// Method assignment
	Gura_AssignMethod(wx_GraphicsGradientStops, __Add);
	Gura_AssignMethod(wx_GraphicsGradientStops, __Add_1);
	Gura_AssignMethod(wx_GraphicsGradientStops, __Item);
	Gura_AssignMethod(wx_GraphicsGradientStops, __GetCount);
	Gura_AssignMethod(wx_GraphicsGradientStops, __SetStartColour);
	Gura_AssignMethod(wx_GraphicsGradientStops, __GetStartColour);
	Gura_AssignMethod(wx_GraphicsGradientStops, __SetEndColour);
	Gura_AssignMethod(wx_GraphicsGradientStops, __GetEndColour);
}

Gura_ImplementDescendantCreator(wx_GraphicsGradientStops)
{
	return new Object_wx_GraphicsGradientStops((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
