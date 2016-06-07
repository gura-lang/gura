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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__SystemSettings, "SystemSettings")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_SystemSettings));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__SystemSettings)
{
	//wxSystemSettings();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_SystemSettings, __GetColour, "GetColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SystemSettings, __GetColour)
{
	Object_wx_SystemSettings *pThis = Object_wx_SystemSettings::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxSystemColour index = arg.GetNumber(0)
	//pThis->GetEntity()->GetColour(index);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SystemSettings, __GetFont, "GetFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SystemSettings, __GetFont)
{
	Object_wx_SystemSettings *pThis = Object_wx_SystemSettings::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxSystemFont index = arg.GetNumber(0)
	//pThis->GetEntity()->GetFont(index);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SystemSettings, __GetMetric, "GetMetric")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SystemSettings, __GetMetric)
{
	Object_wx_SystemSettings *pThis = Object_wx_SystemSettings::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxSystemMetric index = arg.GetNumber(0)
	//wxWindow* win = arg.GetNumber(1)
	//pThis->GetEntity()->GetMetric(index, win);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SystemSettings, __GetScreenType, "GetScreenType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SystemSettings, __GetScreenType)
{
	Object_wx_SystemSettings *pThis = Object_wx_SystemSettings::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetScreenType();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SystemSettings, __HasFeature, "HasFeature")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SystemSettings, __HasFeature)
{
	Object_wx_SystemSettings *pThis = Object_wx_SystemSettings::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxSystemFeature index = arg.GetNumber(0)
	//pThis->GetEntity()->HasFeature(index);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSystemSettings
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SystemSettings)
{
	// Constructor assignment
	Gura_AssignFunction(__SystemSettings);
	// Method assignment
	Gura_AssignMethod(wx_SystemSettings, __GetColour);
	Gura_AssignMethod(wx_SystemSettings, __GetFont);
	Gura_AssignMethod(wx_SystemSettings, __GetMetric);
	Gura_AssignMethod(wx_SystemSettings, __GetScreenType);
	Gura_AssignMethod(wx_SystemSettings, __HasFeature);
}

Gura_ImplementDescendantCreator(wx_SystemSettings)
{
	return new Object_wx_SystemSettings((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
