//----------------------------------------------------------------------------
// wxPowerResourceBlocker
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPowerResourceBlocker
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPowerResourceBlocker
//----------------------------------------------------------------------------
Object_wx_PowerResourceBlocker::~Object_wx_PowerResourceBlocker()
{
}

Object *Object_wx_PowerResourceBlocker::Clone() const
{
	return nullptr;
}

String Object_wx_PowerResourceBlocker::ToString(bool exprFlag)
{
	String rtn("<wx.PowerResourceBlocker:");
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
Gura_DeclareMethod(wx_PowerResourceBlocker, wxPowerResourceBlocker)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "kind", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "reason", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PowerResourceBlocker, wxPowerResourceBlocker)
{
	Object_wx_PowerResourceBlocker *pThis = Object_wx_PowerResourceBlocker::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int kind = arg.GetNumber(0)
	//int reason = arg.GetNumber(1)
	//pThis->GetEntity()->wxPowerResourceBlocker();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PowerResourceBlocker, IsInEffect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PowerResourceBlocker, IsInEffect)
{
	Object_wx_PowerResourceBlocker *pThis = Object_wx_PowerResourceBlocker::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsInEffect();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPowerResourceBlocker
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PowerResourceBlocker)
{
	Gura_AssignMethod(wx_PowerResourceBlocker, wxPowerResourceBlocker);
	Gura_AssignMethod(wx_PowerResourceBlocker, IsInEffect);
}

Gura_ImplementDescendantCreator(wx_PowerResourceBlocker)
{
	return new Object_wx_PowerResourceBlocker((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
