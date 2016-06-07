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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__PlatformInfo, "PlatformInfo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_PlatformInfo));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__PlatformInfo)
{
	//wxPlatformInfo();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__PlatformInfo_1, "PlatformInfo_1")
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
	SetClassToConstruct(Gura_UserClass(wx_PlatformInfo));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__PlatformInfo_1)
{
	//wxPortId pid = arg.GetNumber(0)
	//int tkMajor = arg.GetNumber(1)
	//int tkMinor = arg.GetNumber(2)
	//wxOperatingSystemId id = arg.GetNumber(3)
	//int osMajor = arg.GetNumber(4)
	//int osMinor = arg.GetNumber(5)
	//wxArchitecture arch = arg.GetNumber(6)
	//wxEndianness endian = arg.GetNumber(7)
	//wxPlatformInfo(pid, tkMajor, tkMinor, id, osMajor, osMinor, arch, endian);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_PlatformInfo, __CheckOSVersion, "CheckOSVersion")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "major", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "minor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PlatformInfo, __CheckOSVersion)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int major = arg.GetNumber(0)
	//int minor = arg.GetNumber(1)
	//pThis->GetEntity()->CheckOSVersion(major, minor);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PlatformInfo, __CheckToolkitVersion, "CheckToolkitVersion")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "major", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "minor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PlatformInfo, __CheckToolkitVersion)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int major = arg.GetNumber(0)
	//int minor = arg.GetNumber(1)
	//pThis->GetEntity()->CheckToolkitVersion(major, minor);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PlatformInfo, __IsOk, "IsOk")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PlatformInfo, __IsOk)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PlatformInfo, __IsUsingUniversalWidgets, "IsUsingUniversalWidgets")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PlatformInfo, __IsUsingUniversalWidgets)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsUsingUniversalWidgets();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PlatformInfo, __Get, "Get")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PlatformInfo, __Get)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Get();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PlatformInfo, __GetArch, "GetArch")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "arch", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PlatformInfo, __GetArch)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& arch = arg.GetNumber(0)
	//pThis->GetEntity()->GetArch(arch);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PlatformInfo, __GetEndianness, "GetEndianness")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PlatformInfo, __GetEndianness)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& end = arg.GetNumber(0)
	//pThis->GetEntity()->GetEndianness(end);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PlatformInfo, __GetOperatingSystemId, "GetOperatingSystemId")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PlatformInfo, __GetOperatingSystemId)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//pThis->GetEntity()->GetOperatingSystemId(name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PlatformInfo, __GetPortId, "GetPortId")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "portname", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PlatformInfo, __GetPortId)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& portname = arg.GetNumber(0)
	//pThis->GetEntity()->GetPortId(portname);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PlatformInfo, __GetArchName, "GetArchName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "arch", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PlatformInfo, __GetArchName)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxArchitecture arch = arg.GetNumber(0)
	//pThis->GetEntity()->GetArchName(arch);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PlatformInfo, __GetEndiannessName, "GetEndiannessName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PlatformInfo, __GetEndiannessName)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxEndianness end = arg.GetNumber(0)
	//pThis->GetEntity()->GetEndiannessName(end);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PlatformInfo, __GetOperatingSystemFamilyName, "GetOperatingSystemFamilyName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "os", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PlatformInfo, __GetOperatingSystemFamilyName)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxOperatingSystemId os = arg.GetNumber(0)
	//pThis->GetEntity()->GetOperatingSystemFamilyName(os);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PlatformInfo, __GetOperatingSystemIdName, "GetOperatingSystemIdName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "os", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PlatformInfo, __GetOperatingSystemIdName)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxOperatingSystemId os = arg.GetNumber(0)
	//pThis->GetEntity()->GetOperatingSystemIdName(os);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PlatformInfo, __GetPortIdName, "GetPortIdName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "port", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "usingUniversal", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PlatformInfo, __GetPortIdName)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPortId port = arg.GetNumber(0)
	//bool usingUniversal = arg.GetNumber(1)
	//pThis->GetEntity()->GetPortIdName(port, usingUniversal);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PlatformInfo, __GetPortIdShortName, "GetPortIdShortName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "port", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "usingUniversal", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PlatformInfo, __GetPortIdShortName)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPortId port = arg.GetNumber(0)
	//bool usingUniversal = arg.GetNumber(1)
	//pThis->GetEntity()->GetPortIdShortName(port, usingUniversal);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PlatformInfo, __GetOperatingSystemDirectory, "GetOperatingSystemDirectory")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PlatformInfo, __GetOperatingSystemDirectory)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOperatingSystemDirectory();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PlatformInfo, __GetArchitecture, "GetArchitecture")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PlatformInfo, __GetArchitecture)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetArchitecture();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PlatformInfo, __GetEndianness_1, "GetEndianness_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PlatformInfo, __GetEndianness_1)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEndianness();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PlatformInfo, __GetOSMajorVersion, "GetOSMajorVersion")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PlatformInfo, __GetOSMajorVersion)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOSMajorVersion();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PlatformInfo, __GetOSMinorVersion, "GetOSMinorVersion")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PlatformInfo, __GetOSMinorVersion)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOSMinorVersion();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PlatformInfo, __GetOperatingSystemId_1, "GetOperatingSystemId_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PlatformInfo, __GetOperatingSystemId_1)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOperatingSystemId();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PlatformInfo, __GetOperatingSystemDescription, "GetOperatingSystemDescription")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PlatformInfo, __GetOperatingSystemDescription)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOperatingSystemDescription();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PlatformInfo, __GetPortId_1, "GetPortId_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PlatformInfo, __GetPortId_1)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPortId();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PlatformInfo, __GetLinuxDistributionInfo, "GetLinuxDistributionInfo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PlatformInfo, __GetLinuxDistributionInfo)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLinuxDistributionInfo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PlatformInfo, __GetDesktopEnvironment, "GetDesktopEnvironment")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PlatformInfo, __GetDesktopEnvironment)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDesktopEnvironment();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PlatformInfo, __GetToolkitMajorVersion, "GetToolkitMajorVersion")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PlatformInfo, __GetToolkitMajorVersion)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetToolkitMajorVersion();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PlatformInfo, __GetToolkitMinorVersion, "GetToolkitMinorVersion")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PlatformInfo, __GetToolkitMinorVersion)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetToolkitMinorVersion();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PlatformInfo, __GetArchName_1, "GetArchName_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PlatformInfo, __GetArchName_1)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetArchName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PlatformInfo, __GetEndiannessName_1, "GetEndiannessName_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PlatformInfo, __GetEndiannessName_1)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEndiannessName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PlatformInfo, __GetOperatingSystemFamilyName_1, "GetOperatingSystemFamilyName_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PlatformInfo, __GetOperatingSystemFamilyName_1)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOperatingSystemFamilyName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PlatformInfo, __GetOperatingSystemIdName_1, "GetOperatingSystemIdName_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PlatformInfo, __GetOperatingSystemIdName_1)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOperatingSystemIdName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PlatformInfo, __GetPortIdName_1, "GetPortIdName_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PlatformInfo, __GetPortIdName_1)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPortIdName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PlatformInfo, __GetPortIdShortName_1, "GetPortIdShortName_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PlatformInfo, __GetPortIdShortName_1)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPortIdShortName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PlatformInfo, __SetArchitecture, "SetArchitecture")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PlatformInfo, __SetArchitecture)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxArchitecture n = arg.GetNumber(0)
	//pThis->GetEntity()->SetArchitecture(n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PlatformInfo, __SetEndianness, "SetEndianness")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PlatformInfo, __SetEndianness)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxEndianness n = arg.GetNumber(0)
	//pThis->GetEntity()->SetEndianness(n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PlatformInfo, __SetOSVersion, "SetOSVersion")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "major", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "minor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PlatformInfo, __SetOSVersion)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int major = arg.GetNumber(0)
	//int minor = arg.GetNumber(1)
	//pThis->GetEntity()->SetOSVersion(major, minor);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PlatformInfo, __SetOperatingSystemId, "SetOperatingSystemId")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PlatformInfo, __SetOperatingSystemId)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxOperatingSystemId n = arg.GetNumber(0)
	//pThis->GetEntity()->SetOperatingSystemId(n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PlatformInfo, __SetPortId, "SetPortId")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PlatformInfo, __SetPortId)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPortId n = arg.GetNumber(0)
	//pThis->GetEntity()->SetPortId(n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PlatformInfo, __SetToolkitVersion, "SetToolkitVersion")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "major", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "minor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PlatformInfo, __SetToolkitVersion)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int major = arg.GetNumber(0)
	//int minor = arg.GetNumber(1)
	//pThis->GetEntity()->SetToolkitVersion(major, minor);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PlatformInfo, __SetOperatingSystemDescription, "SetOperatingSystemDescription")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "desc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PlatformInfo, __SetOperatingSystemDescription)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& desc = arg.GetNumber(0)
	//pThis->GetEntity()->SetOperatingSystemDescription(desc);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PlatformInfo, __SetDesktopEnvironment, "SetDesktopEnvironment")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "de", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PlatformInfo, __SetDesktopEnvironment)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& de = arg.GetNumber(0)
	//pThis->GetEntity()->SetDesktopEnvironment(de);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PlatformInfo, __SetLinuxDistributionInfo, "SetLinuxDistributionInfo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "di", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PlatformInfo, __SetLinuxDistributionInfo)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxLinuxDistributionInfo& di = arg.GetNumber(0)
	//pThis->GetEntity()->SetLinuxDistributionInfo(di);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPlatformInfo
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PlatformInfo)
{
	// Constructor assignment
	Gura_AssignFunction(__PlatformInfo);
	Gura_AssignFunction(__PlatformInfo_1);
	// Method assignment
	Gura_AssignMethod(wx_PlatformInfo, __CheckOSVersion);
	Gura_AssignMethod(wx_PlatformInfo, __CheckToolkitVersion);
	Gura_AssignMethod(wx_PlatformInfo, __IsOk);
	Gura_AssignMethod(wx_PlatformInfo, __IsUsingUniversalWidgets);
	Gura_AssignMethod(wx_PlatformInfo, __Get);
	Gura_AssignMethod(wx_PlatformInfo, __GetArch);
	Gura_AssignMethod(wx_PlatformInfo, __GetEndianness);
	Gura_AssignMethod(wx_PlatformInfo, __GetOperatingSystemId);
	Gura_AssignMethod(wx_PlatformInfo, __GetPortId);
	Gura_AssignMethod(wx_PlatformInfo, __GetArchName);
	Gura_AssignMethod(wx_PlatformInfo, __GetEndiannessName);
	Gura_AssignMethod(wx_PlatformInfo, __GetOperatingSystemFamilyName);
	Gura_AssignMethod(wx_PlatformInfo, __GetOperatingSystemIdName);
	Gura_AssignMethod(wx_PlatformInfo, __GetPortIdName);
	Gura_AssignMethod(wx_PlatformInfo, __GetPortIdShortName);
	Gura_AssignMethod(wx_PlatformInfo, __GetOperatingSystemDirectory);
	Gura_AssignMethod(wx_PlatformInfo, __GetArchitecture);
	Gura_AssignMethod(wx_PlatformInfo, __GetEndianness_1);
	Gura_AssignMethod(wx_PlatformInfo, __GetOSMajorVersion);
	Gura_AssignMethod(wx_PlatformInfo, __GetOSMinorVersion);
	Gura_AssignMethod(wx_PlatformInfo, __GetOperatingSystemId_1);
	Gura_AssignMethod(wx_PlatformInfo, __GetOperatingSystemDescription);
	Gura_AssignMethod(wx_PlatformInfo, __GetPortId_1);
	Gura_AssignMethod(wx_PlatformInfo, __GetLinuxDistributionInfo);
	Gura_AssignMethod(wx_PlatformInfo, __GetDesktopEnvironment);
	Gura_AssignMethod(wx_PlatformInfo, __GetToolkitMajorVersion);
	Gura_AssignMethod(wx_PlatformInfo, __GetToolkitMinorVersion);
	Gura_AssignMethod(wx_PlatformInfo, __GetArchName_1);
	Gura_AssignMethod(wx_PlatformInfo, __GetEndiannessName_1);
	Gura_AssignMethod(wx_PlatformInfo, __GetOperatingSystemFamilyName_1);
	Gura_AssignMethod(wx_PlatformInfo, __GetOperatingSystemIdName_1);
	Gura_AssignMethod(wx_PlatformInfo, __GetPortIdName_1);
	Gura_AssignMethod(wx_PlatformInfo, __GetPortIdShortName_1);
	Gura_AssignMethod(wx_PlatformInfo, __SetArchitecture);
	Gura_AssignMethod(wx_PlatformInfo, __SetEndianness);
	Gura_AssignMethod(wx_PlatformInfo, __SetOSVersion);
	Gura_AssignMethod(wx_PlatformInfo, __SetOperatingSystemId);
	Gura_AssignMethod(wx_PlatformInfo, __SetPortId);
	Gura_AssignMethod(wx_PlatformInfo, __SetToolkitVersion);
	Gura_AssignMethod(wx_PlatformInfo, __SetOperatingSystemDescription);
	Gura_AssignMethod(wx_PlatformInfo, __SetDesktopEnvironment);
	Gura_AssignMethod(wx_PlatformInfo, __SetLinuxDistributionInfo);
}

Gura_ImplementDescendantCreator(wx_PlatformInfo)
{
	return new Object_wx_PlatformInfo((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
