//----------------------------------------------------------------------------
// wxWrapSizer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxWrapSizer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxWrapSizer
//----------------------------------------------------------------------------
Object_wx_WrapSizer::~Object_wx_WrapSizer()
{
}

Object *Object_wx_WrapSizer::Clone() const
{
	return nullptr;
}

String Object_wx_WrapSizer::ToString(bool exprFlag)
{
	String rtn("<wx.WrapSizer:");
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
Gura_DeclareMethod(wx_WrapSizer, wxWrapSizer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "orient", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WrapSizer, wxWrapSizer)
{
	Signal &sig = env.GetSignal();
	Object_wx_WrapSizer *pThis = Object_wx_WrapSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int orient = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->wxWrapSizer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WrapSizer, InformFirstDirection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "direction", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "availableOtherDir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WrapSizer, InformFirstDirection)
{
	Signal &sig = env.GetSignal();
	Object_wx_WrapSizer *pThis = Object_wx_WrapSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int direction = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//int availableOtherDir = arg.GetNumber(2)
	//pThis->GetEntity()->InformFirstDirection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WrapSizer, RecalcSizes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WrapSizer, RecalcSizes)
{
	Signal &sig = env.GetSignal();
	Object_wx_WrapSizer *pThis = Object_wx_WrapSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->RecalcSizes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WrapSizer, CalcMin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WrapSizer, CalcMin)
{
	Signal &sig = env.GetSignal();
	Object_wx_WrapSizer *pThis = Object_wx_WrapSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CalcMin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WrapSizer, IsSpaceItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WrapSizer, IsSpaceItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_WrapSizer *pThis = Object_wx_WrapSizer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->IsSpaceItem();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxWrapSizer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WrapSizer)
{
	Gura_AssignMethod(wx_WrapSizer, wxWrapSizer);
	Gura_AssignMethod(wx_WrapSizer, InformFirstDirection);
	Gura_AssignMethod(wx_WrapSizer, RecalcSizes);
	Gura_AssignMethod(wx_WrapSizer, CalcMin);
	Gura_AssignMethod(wx_WrapSizer, IsSpaceItem);
}

Gura_ImplementDescendantCreator(wx_WrapSizer)
{
	return new Object_wx_WrapSizer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
