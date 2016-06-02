//----------------------------------------------------------------------------
// wxVersionInfo
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxVersionInfo
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxVersionInfo
//----------------------------------------------------------------------------
Object_wx_VersionInfo::~Object_wx_VersionInfo()
{
}

Object *Object_wx_VersionInfo::Clone() const
{
	return nullptr;
}

String Object_wx_VersionInfo::ToString(bool exprFlag)
{
	String rtn("<wx.VersionInfo:");
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
Gura_DeclareMethod(wx_VersionInfo, wxVersionInfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "major", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "minor", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "micro", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "description", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "copyright", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_VersionInfo, wxVersionInfo)
{
	Object_wx_VersionInfo *pThis = Object_wx_VersionInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int major = arg.GetNumber(1)
	//int minor = arg.GetNumber(2)
	//int micro = arg.GetNumber(3)
	//int description = arg.GetNumber(4)
	//int copyright = arg.GetNumber(5)
	//pThis->GetEntity()->wxVersionInfo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VersionInfo, GetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VersionInfo, GetName)
{
	Object_wx_VersionInfo *pThis = Object_wx_VersionInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VersionInfo, GetMajor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VersionInfo, GetMajor)
{
	Object_wx_VersionInfo *pThis = Object_wx_VersionInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMajor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VersionInfo, GetMinor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VersionInfo, GetMinor)
{
	Object_wx_VersionInfo *pThis = Object_wx_VersionInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMinor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VersionInfo, GetMicro)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VersionInfo, GetMicro)
{
	Object_wx_VersionInfo *pThis = Object_wx_VersionInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMicro();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VersionInfo, ToString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VersionInfo, ToString)
{
	Object_wx_VersionInfo *pThis = Object_wx_VersionInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ToString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VersionInfo, GetVersionString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VersionInfo, GetVersionString)
{
	Object_wx_VersionInfo *pThis = Object_wx_VersionInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetVersionString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VersionInfo, HasDescription)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VersionInfo, HasDescription)
{
	Object_wx_VersionInfo *pThis = Object_wx_VersionInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasDescription();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VersionInfo, GetDescription)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VersionInfo, GetDescription)
{
	Object_wx_VersionInfo *pThis = Object_wx_VersionInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDescription();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VersionInfo, HasCopyright)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VersionInfo, HasCopyright)
{
	Object_wx_VersionInfo *pThis = Object_wx_VersionInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasCopyright();
	return Value::Nil;
}

Gura_DeclareMethod(wx_VersionInfo, GetCopyright)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_VersionInfo, GetCopyright)
{
	Object_wx_VersionInfo *pThis = Object_wx_VersionInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCopyright();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxVersionInfo
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_VersionInfo)
{
	Gura_AssignMethod(wx_VersionInfo, wxVersionInfo);
	Gura_AssignMethod(wx_VersionInfo, GetName);
	Gura_AssignMethod(wx_VersionInfo, GetMajor);
	Gura_AssignMethod(wx_VersionInfo, GetMinor);
	Gura_AssignMethod(wx_VersionInfo, GetMicro);
	Gura_AssignMethod(wx_VersionInfo, ToString);
	Gura_AssignMethod(wx_VersionInfo, GetVersionString);
	Gura_AssignMethod(wx_VersionInfo, HasDescription);
	Gura_AssignMethod(wx_VersionInfo, GetDescription);
	Gura_AssignMethod(wx_VersionInfo, HasCopyright);
	Gura_AssignMethod(wx_VersionInfo, GetCopyright);
}

Gura_ImplementDescendantCreator(wx_VersionInfo)
{
	return new Object_wx_VersionInfo((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
