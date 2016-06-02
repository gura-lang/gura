//----------------------------------------------------------------------------
// wxPowerResource
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPowerResource
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPowerResource
//----------------------------------------------------------------------------
Object_wx_PowerResource::~Object_wx_PowerResource()
{
}

Object *Object_wx_PowerResource::Clone() const
{
	return nullptr;
}

String Object_wx_PowerResource::ToString(bool exprFlag)
{
	String rtn("<wx.PowerResource:");
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
Gura_DeclareMethod(wx_PowerResource, Acquire)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "kind", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "reason", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PowerResource, Acquire)
{
	Object_wx_PowerResource *pThis = Object_wx_PowerResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int kind = arg.GetNumber(0)
	//int reason = arg.GetNumber(1)
	//pThis->GetEntity()->Acquire();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PowerResource, Release)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "kind", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PowerResource, Release)
{
	Object_wx_PowerResource *pThis = Object_wx_PowerResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int kind = arg.GetNumber(0)
	//pThis->GetEntity()->Release();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPowerResource
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PowerResource)
{
	Gura_AssignMethod(wx_PowerResource, Acquire);
	Gura_AssignMethod(wx_PowerResource, Release);
}

Gura_ImplementDescendantCreator(wx_PowerResource)
{
	return new Object_wx_PowerResource((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
