//----------------------------------------------------------------------------
// wxPlatformInfo
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPlatformInfo
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPlatformInfo
//----------------------------------------------------------------------------
Object_wx_PlatformInfo::~Object_wx_PlatformInfo()
{
}

Object *Object_wx_PlatformInfo::Clone() const
{
	return nullptr;
}

String Object_wx_PlatformInfo::ToString(bool exprFlag)
{
	String rtn("<wx.PlatformInfo:");
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
Gura_DeclareMethod(wx_PlatformInfo, wxPlatformInfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PlatformInfo, wxPlatformInfo)
{
	Signal &sig = env.GetSignal();
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxPlatformInfo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PlatformInfo, wxPlatformInfo_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tkMajor", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tkMinor", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "osMajor", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "osMinor", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "arch", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "endian", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PlatformInfo, wxPlatformInfo_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pid = arg.GetNumber(0)
	//int tkMajor = arg.GetNumber(1)
	//int tkMinor = arg.GetNumber(2)
	//int id = arg.GetNumber(3)
	//int osMajor = arg.GetNumber(4)
	//int osMinor = arg.GetNumber(5)
	//int arch = arg.GetNumber(6)
	//int endian = arg.GetNumber(7)
	//pThis->GetEntity()->wxPlatformInfo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PlatformInfo, CheckOSVersion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "major", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "minor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PlatformInfo, CheckOSVersion)
{
	Signal &sig = env.GetSignal();
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int major = arg.GetNumber(0)
	//int minor = arg.GetNumber(1)
	//pThis->GetEntity()->CheckOSVersion();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PlatformInfo, CheckToolkitVersion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "major", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "minor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PlatformInfo, CheckToolkitVersion)
{
	Signal &sig = env.GetSignal();
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int major = arg.GetNumber(0)
	//int minor = arg.GetNumber(1)
	//pThis->GetEntity()->CheckToolkitVersion();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PlatformInfo, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PlatformInfo, IsOk)
{
	Signal &sig = env.GetSignal();
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PlatformInfo, IsUsingUniversalWidgets)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PlatformInfo, IsUsingUniversalWidgets)
{
	Signal &sig = env.GetSignal();
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsUsingUniversalWidgets();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PlatformInfo, Get)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PlatformInfo, Get)
{
	Signal &sig = env.GetSignal();
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Get();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PlatformInfo, GetArch)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "arch", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PlatformInfo, GetArch)
{
	Signal &sig = env.GetSignal();
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int arch = arg.GetNumber(0)
	//pThis->GetEntity()->GetArch();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PlatformInfo, GetEndianness)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PlatformInfo, GetEndianness)
{
	Signal &sig = env.GetSignal();
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int end = arg.GetNumber(0)
	//pThis->GetEntity()->GetEndianness();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PlatformInfo, GetOperatingSystemId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PlatformInfo, GetOperatingSystemId)
{
	Signal &sig = env.GetSignal();
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->GetOperatingSystemId();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PlatformInfo, GetPortId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "portname", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PlatformInfo, GetPortId)
{
	Signal &sig = env.GetSignal();
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int portname = arg.GetNumber(0)
	//pThis->GetEntity()->GetPortId();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PlatformInfo, GetArchName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "arch", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PlatformInfo, GetArchName)
{
	Signal &sig = env.GetSignal();
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int arch = arg.GetNumber(0)
	//pThis->GetEntity()->GetArchName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PlatformInfo, GetEndiannessName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PlatformInfo, GetEndiannessName)
{
	Signal &sig = env.GetSignal();
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int end = arg.GetNumber(0)
	//pThis->GetEntity()->GetEndiannessName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PlatformInfo, GetOperatingSystemFamilyName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "os", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PlatformInfo, GetOperatingSystemFamilyName)
{
	Signal &sig = env.GetSignal();
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int os = arg.GetNumber(0)
	//pThis->GetEntity()->GetOperatingSystemFamilyName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PlatformInfo, GetOperatingSystemIdName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "os", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PlatformInfo, GetOperatingSystemIdName)
{
	Signal &sig = env.GetSignal();
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int os = arg.GetNumber(0)
	//pThis->GetEntity()->GetOperatingSystemIdName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PlatformInfo, GetPortIdName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "port", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "usingUniversal", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PlatformInfo, GetPortIdName)
{
	Signal &sig = env.GetSignal();
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int port = arg.GetNumber(0)
	//int usingUniversal = arg.GetNumber(1)
	//pThis->GetEntity()->GetPortIdName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PlatformInfo, GetPortIdShortName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "port", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "usingUniversal", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PlatformInfo, GetPortIdShortName)
{
	Signal &sig = env.GetSignal();
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int port = arg.GetNumber(0)
	//int usingUniversal = arg.GetNumber(1)
	//pThis->GetEntity()->GetPortIdShortName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PlatformInfo, GetOperatingSystemDirectory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PlatformInfo, GetOperatingSystemDirectory)
{
	Signal &sig = env.GetSignal();
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetOperatingSystemDirectory();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PlatformInfo, GetArchitecture)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PlatformInfo, GetArchitecture)
{
	Signal &sig = env.GetSignal();
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetArchitecture();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PlatformInfo, GetEndianness_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PlatformInfo, GetEndianness_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetEndianness();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PlatformInfo, GetOSMajorVersion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PlatformInfo, GetOSMajorVersion)
{
	Signal &sig = env.GetSignal();
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetOSMajorVersion();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PlatformInfo, GetOSMinorVersion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PlatformInfo, GetOSMinorVersion)
{
	Signal &sig = env.GetSignal();
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetOSMinorVersion();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PlatformInfo, GetOperatingSystemId_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PlatformInfo, GetOperatingSystemId_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetOperatingSystemId();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PlatformInfo, GetOperatingSystemDescription)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PlatformInfo, GetOperatingSystemDescription)
{
	Signal &sig = env.GetSignal();
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetOperatingSystemDescription();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PlatformInfo, GetPortId_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PlatformInfo, GetPortId_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPortId();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PlatformInfo, GetLinuxDistributionInfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PlatformInfo, GetLinuxDistributionInfo)
{
	Signal &sig = env.GetSignal();
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetLinuxDistributionInfo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PlatformInfo, GetDesktopEnvironment)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PlatformInfo, GetDesktopEnvironment)
{
	Signal &sig = env.GetSignal();
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetDesktopEnvironment();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PlatformInfo, GetToolkitMajorVersion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PlatformInfo, GetToolkitMajorVersion)
{
	Signal &sig = env.GetSignal();
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetToolkitMajorVersion();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PlatformInfo, GetToolkitMinorVersion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PlatformInfo, GetToolkitMinorVersion)
{
	Signal &sig = env.GetSignal();
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetToolkitMinorVersion();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PlatformInfo, GetArchName_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PlatformInfo, GetArchName_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetArchName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PlatformInfo, GetEndiannessName_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PlatformInfo, GetEndiannessName_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetEndiannessName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PlatformInfo, GetOperatingSystemFamilyName_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PlatformInfo, GetOperatingSystemFamilyName_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetOperatingSystemFamilyName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PlatformInfo, GetOperatingSystemIdName_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PlatformInfo, GetOperatingSystemIdName_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetOperatingSystemIdName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PlatformInfo, GetPortIdName_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PlatformInfo, GetPortIdName_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPortIdName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PlatformInfo, GetPortIdShortName_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PlatformInfo, GetPortIdShortName_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPortIdShortName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PlatformInfo, SetArchitecture)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PlatformInfo, SetArchitecture)
{
	Signal &sig = env.GetSignal();
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->SetArchitecture();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PlatformInfo, SetEndianness)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PlatformInfo, SetEndianness)
{
	Signal &sig = env.GetSignal();
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->SetEndianness();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PlatformInfo, SetOSVersion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "major", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "minor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PlatformInfo, SetOSVersion)
{
	Signal &sig = env.GetSignal();
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int major = arg.GetNumber(0)
	//int minor = arg.GetNumber(1)
	//pThis->GetEntity()->SetOSVersion();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PlatformInfo, SetOperatingSystemId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PlatformInfo, SetOperatingSystemId)
{
	Signal &sig = env.GetSignal();
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->SetOperatingSystemId();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PlatformInfo, SetPortId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PlatformInfo, SetPortId)
{
	Signal &sig = env.GetSignal();
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->SetPortId();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PlatformInfo, SetToolkitVersion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "major", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "minor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PlatformInfo, SetToolkitVersion)
{
	Signal &sig = env.GetSignal();
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int major = arg.GetNumber(0)
	//int minor = arg.GetNumber(1)
	//pThis->GetEntity()->SetToolkitVersion();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PlatformInfo, SetOperatingSystemDescription)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "desc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PlatformInfo, SetOperatingSystemDescription)
{
	Signal &sig = env.GetSignal();
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int desc = arg.GetNumber(0)
	//pThis->GetEntity()->SetOperatingSystemDescription();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PlatformInfo, SetDesktopEnvironment)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "de", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PlatformInfo, SetDesktopEnvironment)
{
	Signal &sig = env.GetSignal();
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int de = arg.GetNumber(0)
	//pThis->GetEntity()->SetDesktopEnvironment();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PlatformInfo, SetLinuxDistributionInfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "di", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PlatformInfo, SetLinuxDistributionInfo)
{
	Signal &sig = env.GetSignal();
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int di = arg.GetNumber(0)
	//pThis->GetEntity()->SetLinuxDistributionInfo();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPlatformInfo
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PlatformInfo)
{
	Gura_AssignMethod(wx_PlatformInfo, wxPlatformInfo);
	Gura_AssignMethod(wx_PlatformInfo, wxPlatformInfo_1);
	Gura_AssignMethod(wx_PlatformInfo, CheckOSVersion);
	Gura_AssignMethod(wx_PlatformInfo, CheckToolkitVersion);
	Gura_AssignMethod(wx_PlatformInfo, IsOk);
	Gura_AssignMethod(wx_PlatformInfo, IsUsingUniversalWidgets);
	Gura_AssignMethod(wx_PlatformInfo, Get);
	Gura_AssignMethod(wx_PlatformInfo, GetArch);
	Gura_AssignMethod(wx_PlatformInfo, GetEndianness);
	Gura_AssignMethod(wx_PlatformInfo, GetOperatingSystemId);
	Gura_AssignMethod(wx_PlatformInfo, GetPortId);
	Gura_AssignMethod(wx_PlatformInfo, GetArchName);
	Gura_AssignMethod(wx_PlatformInfo, GetEndiannessName);
	Gura_AssignMethod(wx_PlatformInfo, GetOperatingSystemFamilyName);
	Gura_AssignMethod(wx_PlatformInfo, GetOperatingSystemIdName);
	Gura_AssignMethod(wx_PlatformInfo, GetPortIdName);
	Gura_AssignMethod(wx_PlatformInfo, GetPortIdShortName);
	Gura_AssignMethod(wx_PlatformInfo, GetOperatingSystemDirectory);
	Gura_AssignMethod(wx_PlatformInfo, GetArchitecture);
	Gura_AssignMethod(wx_PlatformInfo, GetEndianness_1);
	Gura_AssignMethod(wx_PlatformInfo, GetOSMajorVersion);
	Gura_AssignMethod(wx_PlatformInfo, GetOSMinorVersion);
	Gura_AssignMethod(wx_PlatformInfo, GetOperatingSystemId_1);
	Gura_AssignMethod(wx_PlatformInfo, GetOperatingSystemDescription);
	Gura_AssignMethod(wx_PlatformInfo, GetPortId_1);
	Gura_AssignMethod(wx_PlatformInfo, GetLinuxDistributionInfo);
	Gura_AssignMethod(wx_PlatformInfo, GetDesktopEnvironment);
	Gura_AssignMethod(wx_PlatformInfo, GetToolkitMajorVersion);
	Gura_AssignMethod(wx_PlatformInfo, GetToolkitMinorVersion);
	Gura_AssignMethod(wx_PlatformInfo, GetArchName_1);
	Gura_AssignMethod(wx_PlatformInfo, GetEndiannessName_1);
	Gura_AssignMethod(wx_PlatformInfo, GetOperatingSystemFamilyName_1);
	Gura_AssignMethod(wx_PlatformInfo, GetOperatingSystemIdName_1);
	Gura_AssignMethod(wx_PlatformInfo, GetPortIdName_1);
	Gura_AssignMethod(wx_PlatformInfo, GetPortIdShortName_1);
	Gura_AssignMethod(wx_PlatformInfo, SetArchitecture);
	Gura_AssignMethod(wx_PlatformInfo, SetEndianness);
	Gura_AssignMethod(wx_PlatformInfo, SetOSVersion);
	Gura_AssignMethod(wx_PlatformInfo, SetOperatingSystemId);
	Gura_AssignMethod(wx_PlatformInfo, SetPortId);
	Gura_AssignMethod(wx_PlatformInfo, SetToolkitVersion);
	Gura_AssignMethod(wx_PlatformInfo, SetOperatingSystemDescription);
	Gura_AssignMethod(wx_PlatformInfo, SetDesktopEnvironment);
	Gura_AssignMethod(wx_PlatformInfo, SetLinuxDistributionInfo);
}

Gura_ImplementDescendantCreator(wx_PlatformInfo)
{
	return new Object_wx_PlatformInfo((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
