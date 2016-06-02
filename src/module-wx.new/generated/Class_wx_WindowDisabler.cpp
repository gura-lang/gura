//----------------------------------------------------------------------------
// wxWindowDisabler
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxWindowDisabler
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxWindowDisabler
//----------------------------------------------------------------------------
Object_wx_WindowDisabler::~Object_wx_WindowDisabler()
{
}

Object *Object_wx_WindowDisabler::Clone() const
{
	return nullptr;
}

String Object_wx_WindowDisabler::ToString(bool exprFlag)
{
	String rtn("<wx.WindowDisabler:");
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
Gura_DeclareMethod(wx_WindowDisabler, wxWindowDisabler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "disable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WindowDisabler, wxWindowDisabler)
{
	Object_wx_WindowDisabler *pThis = Object_wx_WindowDisabler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int disable = arg.GetNumber(0)
	//pThis->GetEntity()->wxWindowDisabler();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WindowDisabler, wxWindowDisabler_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "winToSkip", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WindowDisabler, wxWindowDisabler_1)
{
	Object_wx_WindowDisabler *pThis = Object_wx_WindowDisabler::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int winToSkip = arg.GetNumber(0)
	//pThis->GetEntity()->wxWindowDisabler();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxWindowDisabler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WindowDisabler)
{
	Gura_AssignMethod(wx_WindowDisabler, wxWindowDisabler);
	Gura_AssignMethod(wx_WindowDisabler, wxWindowDisabler_1);
}

Gura_ImplementDescendantCreator(wx_WindowDisabler)
{
	return new Object_wx_WindowDisabler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
