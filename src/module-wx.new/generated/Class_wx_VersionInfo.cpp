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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__VersionInfo, "VersionInfo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "major", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "minor", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "micro", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "description", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "copyright", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_VersionInfo));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__VersionInfo)
{
	//const wxString& name = arg.GetNumber(0)
	//int major = arg.GetNumber(1)
	//int minor = arg.GetNumber(2)
	//int micro = arg.GetNumber(3)
	//const wxString& description = arg.GetNumber(4)
	//const wxString& copyright = arg.GetNumber(5)
	//wxVersionInfo(name, major, minor, micro, description, copyright);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_VersionInfo, __GetName, "GetName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_VersionInfo, __GetName)
{
	Object_wx_VersionInfo *pThis = Object_wx_VersionInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& _rtn = pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VersionInfo, __GetMajor, "GetMajor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_VersionInfo, __GetMajor)
{
	Object_wx_VersionInfo *pThis = Object_wx_VersionInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetMajor();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VersionInfo, __GetMinor, "GetMinor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_VersionInfo, __GetMinor)
{
	Object_wx_VersionInfo *pThis = Object_wx_VersionInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetMinor();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VersionInfo, __GetMicro, "GetMicro")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_VersionInfo, __GetMicro)
{
	Object_wx_VersionInfo *pThis = Object_wx_VersionInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetMicro();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VersionInfo, __ToString, "ToString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_VersionInfo, __ToString)
{
	Object_wx_VersionInfo *pThis = Object_wx_VersionInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->ToString();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VersionInfo, __GetVersionString, "GetVersionString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_VersionInfo, __GetVersionString)
{
	Object_wx_VersionInfo *pThis = Object_wx_VersionInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetVersionString();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VersionInfo, __HasDescription, "HasDescription")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_VersionInfo, __HasDescription)
{
	Object_wx_VersionInfo *pThis = Object_wx_VersionInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasDescription();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VersionInfo, __GetDescription, "GetDescription")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_VersionInfo, __GetDescription)
{
	Object_wx_VersionInfo *pThis = Object_wx_VersionInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& _rtn = pThis->GetEntity()->GetDescription();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VersionInfo, __HasCopyright, "HasCopyright")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_VersionInfo, __HasCopyright)
{
	Object_wx_VersionInfo *pThis = Object_wx_VersionInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasCopyright();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_VersionInfo, __GetCopyright, "GetCopyright")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_VersionInfo, __GetCopyright)
{
	Object_wx_VersionInfo *pThis = Object_wx_VersionInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& _rtn = pThis->GetEntity()->GetCopyright();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxVersionInfo
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_VersionInfo)
{
	// Constructor assignment
	Gura_AssignFunction(__VersionInfo);
	// Method assignment
	Gura_AssignMethod(wx_VersionInfo, __GetName);
	Gura_AssignMethod(wx_VersionInfo, __GetMajor);
	Gura_AssignMethod(wx_VersionInfo, __GetMinor);
	Gura_AssignMethod(wx_VersionInfo, __GetMicro);
	Gura_AssignMethod(wx_VersionInfo, __ToString);
	Gura_AssignMethod(wx_VersionInfo, __GetVersionString);
	Gura_AssignMethod(wx_VersionInfo, __HasDescription);
	Gura_AssignMethod(wx_VersionInfo, __GetDescription);
	Gura_AssignMethod(wx_VersionInfo, __HasCopyright);
	Gura_AssignMethod(wx_VersionInfo, __GetCopyright);
}

Gura_ImplementDescendantCreator(wx_VersionInfo)
{
	return new Object_wx_VersionInfo((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
