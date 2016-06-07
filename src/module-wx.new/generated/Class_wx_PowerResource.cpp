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
Gura_DeclareMethodAlias(wx_PowerResource, __Acquire, "Acquire")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "kind", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "reason", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PowerResource, __Acquire)
{
	Object_wx_PowerResource *pThis = Object_wx_PowerResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPowerResourceKind kind = arg.GetNumber(0)
	//const wxString& reason = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->Acquire(kind, reason);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PowerResource, __Release, "Release")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "kind", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PowerResource, __Release)
{
	Object_wx_PowerResource *pThis = Object_wx_PowerResource::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPowerResourceKind kind = arg.GetNumber(0)
	//pThis->GetEntity()->Release(kind);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPowerResource
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PowerResource)
{
	// Class assignment
	Gura_AssignValueEx("PowerResource", Reference());
	// Method assignment
	Gura_AssignMethod(wx_PowerResource, __Acquire);
	Gura_AssignMethod(wx_PowerResource, __Release);
}

Gura_ImplementDescendantCreator(wx_PowerResource)
{
	return new Object_wx_PowerResource((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
