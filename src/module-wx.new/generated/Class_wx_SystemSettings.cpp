//----------------------------------------------------------------------------
// wxSystemSettings
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSystemSettings
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSystemSettings
//----------------------------------------------------------------------------
Object_wx_SystemSettings::~Object_wx_SystemSettings()
{
}

Object *Object_wx_SystemSettings::Clone() const
{
	return nullptr;
}

String Object_wx_SystemSettings::ToString(bool exprFlag)
{
	String rtn("<wx.SystemSettings:");
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
Gura_DeclareMethod(wx_SystemSettings, wxSystemSettings)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SystemSettings, wxSystemSettings)
{
	Signal &sig = env.GetSignal();
	Object_wx_SystemSettings *pThis = Object_wx_SystemSettings::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxSystemSettings();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SystemSettings, GetColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SystemSettings, GetColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_SystemSettings *pThis = Object_wx_SystemSettings::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//pThis->GetEntity()->GetColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SystemSettings, GetFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SystemSettings, GetFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_SystemSettings *pThis = Object_wx_SystemSettings::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//pThis->GetEntity()->GetFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SystemSettings, GetMetric)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SystemSettings, GetMetric)
{
	Signal &sig = env.GetSignal();
	Object_wx_SystemSettings *pThis = Object_wx_SystemSettings::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//int win = arg.GetNumber(1)
	//pThis->GetEntity()->GetMetric();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SystemSettings, GetScreenType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SystemSettings, GetScreenType)
{
	Signal &sig = env.GetSignal();
	Object_wx_SystemSettings *pThis = Object_wx_SystemSettings::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetScreenType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SystemSettings, HasFeature)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SystemSettings, HasFeature)
{
	Signal &sig = env.GetSignal();
	Object_wx_SystemSettings *pThis = Object_wx_SystemSettings::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int index = arg.GetNumber(0)
	//pThis->GetEntity()->HasFeature();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSystemSettings
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SystemSettings)
{
	Gura_AssignMethod(wx_SystemSettings, wxSystemSettings);
	Gura_AssignMethod(wx_SystemSettings, GetColour);
	Gura_AssignMethod(wx_SystemSettings, GetFont);
	Gura_AssignMethod(wx_SystemSettings, GetMetric);
	Gura_AssignMethod(wx_SystemSettings, GetScreenType);
	Gura_AssignMethod(wx_SystemSettings, HasFeature);
}

Gura_ImplementDescendantCreator(wx_SystemSettings)
{
	return new Object_wx_SystemSettings((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
