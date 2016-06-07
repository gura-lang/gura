//----------------------------------------------------------------------------
// wxSystemOptions
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSystemOptions
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSystemOptions
//----------------------------------------------------------------------------
Object_wx_SystemOptions::~Object_wx_SystemOptions()
{
}

Object *Object_wx_SystemOptions::Clone() const
{
	return nullptr;
}

String Object_wx_SystemOptions::ToString(bool exprFlag)
{
	String rtn("<wx.SystemOptions:");
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
Gura_DeclareFunctionAlias(__SystemOptions, "SystemOptions")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_SystemOptions));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__SystemOptions)
{
	//wxSystemOptions();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_SystemOptions, __GetOption, "GetOption")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SystemOptions, __GetOption)
{
	Object_wx_SystemOptions *pThis = Object_wx_SystemOptions::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//wxString _rtn = pThis->GetEntity()->GetOption(name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SystemOptions, __GetOptionInt, "GetOptionInt")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SystemOptions, __GetOptionInt)
{
	Object_wx_SystemOptions *pThis = Object_wx_SystemOptions::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//int _rtn = pThis->GetEntity()->GetOptionInt(name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SystemOptions, __HasOption, "HasOption")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SystemOptions, __HasOption)
{
	Object_wx_SystemOptions *pThis = Object_wx_SystemOptions::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->HasOption(name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SystemOptions, __IsFalse, "IsFalse")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SystemOptions, __IsFalse)
{
	Object_wx_SystemOptions *pThis = Object_wx_SystemOptions::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->IsFalse(name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SystemOptions, __SetOption, "SetOption")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SystemOptions, __SetOption)
{
	Object_wx_SystemOptions *pThis = Object_wx_SystemOptions::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//const wxString& value = arg.GetNumber(1)
	//pThis->GetEntity()->SetOption(name, value);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SystemOptions, __SetOption_1, "SetOption_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SystemOptions, __SetOption_1)
{
	Object_wx_SystemOptions *pThis = Object_wx_SystemOptions::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//int value = arg.GetNumber(1)
	//pThis->GetEntity()->SetOption(name, value);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSystemOptions
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SystemOptions)
{
	// Constructor assignment
	Gura_AssignFunction(__SystemOptions);
	// Method assignment
	Gura_AssignMethod(wx_SystemOptions, __GetOption);
	Gura_AssignMethod(wx_SystemOptions, __GetOptionInt);
	Gura_AssignMethod(wx_SystemOptions, __HasOption);
	Gura_AssignMethod(wx_SystemOptions, __IsFalse);
	Gura_AssignMethod(wx_SystemOptions, __SetOption);
	Gura_AssignMethod(wx_SystemOptions, __SetOption_1);
}

Gura_ImplementDescendantCreator(wx_SystemOptions)
{
	return new Object_wx_SystemOptions((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
