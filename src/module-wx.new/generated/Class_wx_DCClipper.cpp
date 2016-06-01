//----------------------------------------------------------------------------
// wxDCClipper
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDCClipper
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDCClipper
//----------------------------------------------------------------------------
Object_wx_DCClipper::~Object_wx_DCClipper()
{
}

Object *Object_wx_DCClipper::Clone() const
{
	return nullptr;
}

String Object_wx_DCClipper::ToString(bool exprFlag)
{
	String rtn("<wx.DCClipper:");
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
Gura_DeclareMethod(wx_DCClipper, wxDCClipper)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "region", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DCClipper, wxDCClipper)
{
	Signal &sig = env.GetSignal();
	Object_wx_DCClipper *pThis = Object_wx_DCClipper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int region = arg.GetNumber(1)
	//pThis->GetEntity()->wxDCClipper();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DCClipper, wxDCClipper_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DCClipper, wxDCClipper_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_DCClipper *pThis = Object_wx_DCClipper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int rect = arg.GetNumber(1)
	//pThis->GetEntity()->wxDCClipper();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DCClipper, wxDCClipper_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "h", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DCClipper, wxDCClipper_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_DCClipper *pThis = Object_wx_DCClipper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int x = arg.GetNumber(1)
	//int y = arg.GetNumber(2)
	//int w = arg.GetNumber(3)
	//int h = arg.GetNumber(4)
	//pThis->GetEntity()->wxDCClipper();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DCClipper, ~wxDCClipper)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DCClipper, ~wxDCClipper)
{
	Signal &sig = env.GetSignal();
	Object_wx_DCClipper *pThis = Object_wx_DCClipper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxDCClipper();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDCClipper
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DCClipper)
{
	Gura_AssignMethod(wx_DCClipper, wxDCClipper);
	Gura_AssignMethod(wx_DCClipper, wxDCClipper_1);
	Gura_AssignMethod(wx_DCClipper, wxDCClipper_2);
	Gura_AssignMethod(wx_DCClipper, ~wxDCClipper);
}

Gura_ImplementDescendantCreator(wx_DCClipper)
{
	return new Object_wx_DCClipper((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
