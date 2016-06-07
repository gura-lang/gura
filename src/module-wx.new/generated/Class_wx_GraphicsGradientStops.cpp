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
Gura_DeclareFunctionAlias(__GraphicsGradientStops, "GraphicsGradientStops")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "startCol", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "endCol", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_GraphicsGradientStops));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__GraphicsGradientStops)
{
	//wxColour startCol = arg.GetNumber(0)
	//wxColour endCol = arg.GetNumber(1)
	//wxGraphicsGradientStops(startCol, endCol);
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
	//const wxGraphicsGradientStop& stop = arg.GetNumber(0)
	//pThis->GetEntity()->Add(stop);
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
	//wxColour col = arg.GetNumber(0)
	//float pos = arg.GetNumber(1)
	//pThis->GetEntity()->Add(col, pos);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsGradientStops, __Item, "Item")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsGradientStops, __Item)
{
	Object_wx_GraphicsGradientStops *pThis = Object_wx_GraphicsGradientStops::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned n = arg.GetNumber(0)
	//wxGraphicsGradientStop _rtn = pThis->GetEntity()->Item(n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsGradientStops, __GetCount, "GetCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsGradientStops, __GetCount)
{
	Object_wx_GraphicsGradientStops *pThis = Object_wx_GraphicsGradientStops::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t _rtn = pThis->GetEntity()->GetCount();
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
	//wxColour col = arg.GetNumber(0)
	//pThis->GetEntity()->SetStartColour(col);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsGradientStops, __GetStartColour, "GetStartColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsGradientStops, __GetStartColour)
{
	Object_wx_GraphicsGradientStops *pThis = Object_wx_GraphicsGradientStops::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxColour _rtn = pThis->GetEntity()->GetStartColour();
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
	//wxColour col = arg.GetNumber(0)
	//pThis->GetEntity()->SetEndColour(col);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GraphicsGradientStops, __GetEndColour, "GetEndColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsGradientStops, __GetEndColour)
{
	Object_wx_GraphicsGradientStops *pThis = Object_wx_GraphicsGradientStops::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxColour _rtn = pThis->GetEntity()->GetEndColour();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGraphicsGradientStops
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GraphicsGradientStops)
{
	// Constructor assignment
	Gura_AssignFunction(__GraphicsGradientStops);
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
