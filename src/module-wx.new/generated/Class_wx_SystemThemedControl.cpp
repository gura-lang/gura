//----------------------------------------------------------------------------
// wxSystemThemedControl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSystemThemedControl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSystemThemedControl
//----------------------------------------------------------------------------
Object_wx_SystemThemedControl::~Object_wx_SystemThemedControl()
{
}

Object *Object_wx_SystemThemedControl::Clone() const
{
	return nullptr;
}

String Object_wx_SystemThemedControl::ToString(bool exprFlag)
{
	String rtn("<wx.SystemThemedControl:");
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
Gura_DeclareMethodAlias(wx_SystemThemedControl, __wxSystemThemedControl, "wxSystemThemedControl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SystemThemedControl, __wxSystemThemedControl)
{
	Object_wx_SystemThemedControl *pThis = Object_wx_SystemThemedControl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxSystemThemedControl();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SystemThemedControl, __EnableSystemTheme, "EnableSystemTheme")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SystemThemedControl, __EnableSystemTheme)
{
	Object_wx_SystemThemedControl *pThis = Object_wx_SystemThemedControl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int enable = arg.GetNumber(0)
	//pThis->GetEntity()->EnableSystemTheme();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSystemThemedControl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SystemThemedControl)
{
	Gura_AssignMethod(wx_SystemThemedControl, __wxSystemThemedControl);
	Gura_AssignMethod(wx_SystemThemedControl, __EnableSystemTheme);
}

Gura_ImplementDescendantCreator(wx_SystemThemedControl)
{
	return new Object_wx_SystemThemedControl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
