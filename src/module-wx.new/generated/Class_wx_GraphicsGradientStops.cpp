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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_GraphicsGradientStops, wxGraphicsGradientStops)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "startCol", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "endCol", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsGradientStops, wxGraphicsGradientStops)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsGradientStops *pThis = Object_wx_GraphicsGradientStops::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int startCol = arg.GetNumber(0)
	//int endCol = arg.GetNumber(1)
	//pThis->GetEntity()->wxGraphicsGradientStops();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsGradientStops, Add)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stop", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsGradientStops, Add)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsGradientStops *pThis = Object_wx_GraphicsGradientStops::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int stop = arg.GetNumber(0)
	//pThis->GetEntity()->Add();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsGradientStops, Add_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsGradientStops, Add_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsGradientStops *pThis = Object_wx_GraphicsGradientStops::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//pThis->GetEntity()->Add();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsGradientStops, Item)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsGradientStops, Item)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsGradientStops *pThis = Object_wx_GraphicsGradientStops::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->Item();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsGradientStops, GetCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsGradientStops, GetCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsGradientStops *pThis = Object_wx_GraphicsGradientStops::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsGradientStops, SetStartColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsGradientStops, SetStartColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsGradientStops *pThis = Object_wx_GraphicsGradientStops::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->SetStartColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsGradientStops, GetStartColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsGradientStops, GetStartColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsGradientStops *pThis = Object_wx_GraphicsGradientStops::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetStartColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsGradientStops, SetEndColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsGradientStops, SetEndColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsGradientStops *pThis = Object_wx_GraphicsGradientStops::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->SetEndColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GraphicsGradientStops, GetEndColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsGradientStops, GetEndColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_GraphicsGradientStops *pThis = Object_wx_GraphicsGradientStops::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetEndColour();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGraphicsGradientStops
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GraphicsGradientStops)
{
	Gura_AssignMethod(wx_GraphicsGradientStops, wxGraphicsGradientStops);
	Gura_AssignMethod(wx_GraphicsGradientStops, Add);
	Gura_AssignMethod(wx_GraphicsGradientStops, Add_1);
	Gura_AssignMethod(wx_GraphicsGradientStops, Item);
	Gura_AssignMethod(wx_GraphicsGradientStops, GetCount);
	Gura_AssignMethod(wx_GraphicsGradientStops, SetStartColour);
	Gura_AssignMethod(wx_GraphicsGradientStops, GetStartColour);
	Gura_AssignMethod(wx_GraphicsGradientStops, SetEndColour);
	Gura_AssignMethod(wx_GraphicsGradientStops, GetEndColour);
}

Gura_ImplementDescendantCreator(wx_GraphicsGradientStops)
{
	return new Object_wx_GraphicsGradientStops((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
