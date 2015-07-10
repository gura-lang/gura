//----------------------------------------------------------------------------
// wxPlatformInfo
// extracted from platinfo.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_PlatformInfo: public wxPlatformInfo, public GuraObjectObserver {
private:
	Gura::Signal *_pSig;
	Object_wx_PlatformInfo *_pObj;
public:
	inline wx_PlatformInfo() : wxPlatformInfo(), _pSig(nullptr), _pObj(nullptr) {}
	inline wx_PlatformInfo(wxPortId pid, int tkMajor, int tkMinor, wxOperatingSystemId id, int osMajor, int osMinor, wxArchitecture arch, wxEndianness endian) : wxPlatformInfo(pid, tkMajor, tkMinor, id, osMajor, osMinor, arch, endian), _pSig(nullptr), _pObj(nullptr) {}
	~wx_PlatformInfo();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_PlatformInfo *pObj) {
		_pSig = &sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_PlatformInfo::~wx_PlatformInfo()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_PlatformInfo::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxPlatformInfo
//----------------------------------------------------------------------------
Gura_DeclareFunction(PlatformInfoEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_PlatformInfo));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(PlatformInfoEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_PlatformInfo *pEntity = new wx_PlatformInfo();
	Object_wx_PlatformInfo *pObj = Object_wx_PlatformInfo::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_PlatformInfo(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(PlatformInfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_PlatformInfo));
	DeclareArg(env, "pid", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "tkMajor", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "tkMinor", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "osMajor", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "osMinor", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "arch", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "endian", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(PlatformInfo)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxPortId pid = wxPORT_UNKNOWN;
	if (args.IsValid(0)) pid = static_cast<wxPortId>(args.GetInt(0));
	int tkMajor = -1;
	if (args.IsValid(1)) tkMajor = args.GetInt(1);
	int tkMinor = -1;
	if (args.IsValid(2)) tkMinor = args.GetInt(2);
	wxOperatingSystemId id = wxOS_UNKNOWN;
	if (args.IsValid(3)) id = static_cast<wxOperatingSystemId>(args.GetInt(3));
	int osMajor = -1;
	if (args.IsValid(4)) osMajor = args.GetInt(4);
	int osMinor = -1;
	if (args.IsValid(5)) osMinor = args.GetInt(5);
	wxArchitecture arch = wxARCH_INVALID;
	if (args.IsValid(6)) arch = static_cast<wxArchitecture>(args.GetInt(6));
	wxEndianness endian = wxENDIAN_INVALID;
	if (args.IsValid(7)) endian = static_cast<wxEndianness>(args.GetInt(7));
	wx_PlatformInfo *pEntity = new wx_PlatformInfo(pid, tkMajor, tkMinor, id, osMajor, osMinor, arch, endian);
	Object_wx_PlatformInfo *pObj = Object_wx_PlatformInfo::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_PlatformInfo(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_PlatformInfo, CheckOSVersion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "major", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "minor", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PlatformInfo, CheckOSVersion)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int major = args.GetInt(0);
	int minor = args.GetInt(1);
	bool rtn = pThis->GetEntity()->CheckOSVersion(major, minor);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PlatformInfo, CheckToolkitVersion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "major", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "minor", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PlatformInfo, CheckToolkitVersion)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int major = args.GetInt(0);
	int minor = args.GetInt(1);
	bool rtn = pThis->GetEntity()->CheckToolkitVersion(major, minor);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_PlatformInfo, Get)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_PlatformInfo, Get)
{
	if (!CheckWxReady(sig)) return Value::Null;
	const wxPlatformInfo &rtn = wxPlatformInfo::Get();
	return ReturnValue(env, sig, args, Value(new Object_wx_PlatformInfo(new wxPlatformInfo(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareClassMethod(wx_PlatformInfo, GetArch)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "arch", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_PlatformInfo, GetArch)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString arch = wxString::FromUTF8(args.GetString(0));
	wxArchitecture rtn = wxPlatformInfo::GetArch(arch);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_PlatformInfo, GetArchName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "arch", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_PlatformInfo, GetArchName)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxArchitecture arch = static_cast<wxArchitecture>(args.GetInt(0));
	wxString rtn = wxPlatformInfo::GetArchName(arch);
	return ReturnValue(env, sig, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_PlatformInfo, GetArchName_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PlatformInfo, GetArchName_1)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetArchName();
	return ReturnValue(env, sig, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_PlatformInfo, GetArchitecture)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PlatformInfo, GetArchitecture)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxArchitecture rtn = pThis->GetEntity()->GetArchitecture();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_PlatformInfo, GetEndianness)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "end", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_PlatformInfo, GetEndianness)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString end = wxString::FromUTF8(args.GetString(0));
	wxEndianness rtn = wxPlatformInfo::GetEndianness(end);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PlatformInfo, GetEndianness_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PlatformInfo, GetEndianness_1)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxEndianness rtn = pThis->GetEntity()->GetEndianness();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_PlatformInfo, GetEndiannessName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_PlatformInfo, GetEndiannessName)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxEndianness end = static_cast<wxEndianness>(args.GetInt(0));
	wxString rtn = wxPlatformInfo::GetEndiannessName(end);
	return ReturnValue(env, sig, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_PlatformInfo, GetEndiannessName_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PlatformInfo, GetEndiannessName_1)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetEndiannessName();
	return ReturnValue(env, sig, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_PlatformInfo, GetOSMajorVersion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PlatformInfo, GetOSMajorVersion)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetOSMajorVersion();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PlatformInfo, GetOSMinorVersion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PlatformInfo, GetOSMinorVersion)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetOSMinorVersion();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_PlatformInfo, GetOperatingSystemFamilyName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "os", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_PlatformInfo, GetOperatingSystemFamilyName)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxOperatingSystemId os = static_cast<wxOperatingSystemId>(args.GetInt(0));
	wxString rtn = wxPlatformInfo::GetOperatingSystemFamilyName(os);
	return ReturnValue(env, sig, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_PlatformInfo, GetOperatingSystemFamilyName_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PlatformInfo, GetOperatingSystemFamilyName_1)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetOperatingSystemFamilyName();
	return ReturnValue(env, sig, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareClassMethod(wx_PlatformInfo, GetOperatingSystemId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_PlatformInfo, GetOperatingSystemId)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	wxOperatingSystemId rtn = wxPlatformInfo::GetOperatingSystemId(name);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PlatformInfo, GetOperatingSystemId_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PlatformInfo, GetOperatingSystemId_1)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxOperatingSystemId rtn = pThis->GetEntity()->GetOperatingSystemId();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_PlatformInfo, GetOperatingSystemIdName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "os", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_PlatformInfo, GetOperatingSystemIdName)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxOperatingSystemId os = static_cast<wxOperatingSystemId>(args.GetInt(0));
	wxString rtn = wxPlatformInfo::GetOperatingSystemIdName(os);
	return ReturnValue(env, sig, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_PlatformInfo, GetOperatingSystemIdName_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PlatformInfo, GetOperatingSystemIdName_1)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetOperatingSystemIdName();
	return ReturnValue(env, sig, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareClassMethod(wx_PlatformInfo, GetPortId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "portname", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_PlatformInfo, GetPortId)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString portname = wxString::FromUTF8(args.GetString(0));
	wxPortId rtn = wxPlatformInfo::GetPortId(portname);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PlatformInfo, GetPortId_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PlatformInfo, GetPortId_1)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPortId rtn = pThis->GetEntity()->GetPortId();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_PlatformInfo, GetPortIdName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "port", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "usingUniversal", VTYPE_boolean, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_PlatformInfo, GetPortIdName)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxPortId port = static_cast<wxPortId>(args.GetInt(0));
	bool usingUniversal = args.GetBoolean(1);
	wxString rtn = wxPlatformInfo::GetPortIdName(port, usingUniversal);
	return ReturnValue(env, sig, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_PlatformInfo, GetPortIdName_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PlatformInfo, GetPortIdName_1)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetPortIdName();
	return ReturnValue(env, sig, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareClassMethod(wx_PlatformInfo, GetPortIdShortName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "port", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "usingUniversal", VTYPE_boolean, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_PlatformInfo, GetPortIdShortName)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxPortId port = static_cast<wxPortId>(args.GetInt(0));
	bool usingUniversal = args.GetBoolean(1);
	wxString rtn = wxPlatformInfo::GetPortIdShortName(port, usingUniversal);
	return ReturnValue(env, sig, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_PlatformInfo, GetPortIdShortName_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PlatformInfo, GetPortIdShortName_1)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetPortIdShortName();
	return ReturnValue(env, sig, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_PlatformInfo, GetToolkitMajorVersion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PlatformInfo, GetToolkitMajorVersion)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetToolkitMajorVersion();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PlatformInfo, GetToolkitMinorVersion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PlatformInfo, GetToolkitMinorVersion)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetToolkitMinorVersion();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PlatformInfo, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PlatformInfo, IsOk)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsOk();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PlatformInfo, IsUsingUniversalWidgets)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_PlatformInfo, IsUsingUniversalWidgets)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsUsingUniversalWidgets();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_PlatformInfo, SetArchitecture)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PlatformInfo, SetArchitecture)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxArchitecture n = static_cast<wxArchitecture>(args.GetInt(0));
	pThis->GetEntity()->SetArchitecture(n);
	return Value::Null;
}

Gura_DeclareMethod(wx_PlatformInfo, SetEndianness)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PlatformInfo, SetEndianness)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxEndianness n = static_cast<wxEndianness>(args.GetInt(0));
	pThis->GetEntity()->SetEndianness(n);
	return Value::Null;
}

Gura_DeclareMethod(wx_PlatformInfo, SetOSVersion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "major", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "minor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PlatformInfo, SetOSVersion)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int major = args.GetInt(0);
	int minor = args.GetInt(1);
	pThis->GetEntity()->SetOSVersion(major, minor);
	return Value::Null;
}

Gura_DeclareMethod(wx_PlatformInfo, SetOperatingSystemId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PlatformInfo, SetOperatingSystemId)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxOperatingSystemId n = static_cast<wxOperatingSystemId>(args.GetInt(0));
	pThis->GetEntity()->SetOperatingSystemId(n);
	return Value::Null;
}

Gura_DeclareMethod(wx_PlatformInfo, SetPortId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PlatformInfo, SetPortId)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPortId n = static_cast<wxPortId>(args.GetInt(0));
	pThis->GetEntity()->SetPortId(n);
	return Value::Null;
}

Gura_DeclareMethod(wx_PlatformInfo, SetToolkitVersion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "major", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "minor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PlatformInfo, SetToolkitVersion)
{
	Object_wx_PlatformInfo *pThis = Object_wx_PlatformInfo::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int major = args.GetInt(0);
	int minor = args.GetInt(1);
	pThis->GetEntity()->SetToolkitVersion(major, minor);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxPlatformInfo
//----------------------------------------------------------------------------
Object_wx_PlatformInfo::~Object_wx_PlatformInfo()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
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
// Class implementation for wxPlatformInfo
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PlatformInfo)
{
	Gura_AssignFunction(PlatformInfoEmpty);
	Gura_AssignFunction(PlatformInfo);
	Gura_AssignMethod(wx_PlatformInfo, CheckOSVersion);
	Gura_AssignMethod(wx_PlatformInfo, CheckToolkitVersion);
	Gura_AssignMethod(wx_PlatformInfo, Get);
	Gura_AssignMethod(wx_PlatformInfo, GetArch);
	Gura_AssignMethod(wx_PlatformInfo, GetArchName);
	Gura_AssignMethod(wx_PlatformInfo, GetArchName_1);
	Gura_AssignMethod(wx_PlatformInfo, GetArchitecture);
	Gura_AssignMethod(wx_PlatformInfo, GetEndianness);
	Gura_AssignMethod(wx_PlatformInfo, GetEndianness_1);
	Gura_AssignMethod(wx_PlatformInfo, GetEndiannessName);
	Gura_AssignMethod(wx_PlatformInfo, GetEndiannessName_1);
	Gura_AssignMethod(wx_PlatformInfo, GetOSMajorVersion);
	Gura_AssignMethod(wx_PlatformInfo, GetOSMinorVersion);
	Gura_AssignMethod(wx_PlatformInfo, GetOperatingSystemFamilyName);
	Gura_AssignMethod(wx_PlatformInfo, GetOperatingSystemFamilyName_1);
	Gura_AssignMethod(wx_PlatformInfo, GetOperatingSystemId);
	Gura_AssignMethod(wx_PlatformInfo, GetOperatingSystemId_1);
	Gura_AssignMethod(wx_PlatformInfo, GetOperatingSystemIdName);
	Gura_AssignMethod(wx_PlatformInfo, GetOperatingSystemIdName_1);
	Gura_AssignMethod(wx_PlatformInfo, GetPortId);
	Gura_AssignMethod(wx_PlatformInfo, GetPortId_1);
	Gura_AssignMethod(wx_PlatformInfo, GetPortIdName);
	Gura_AssignMethod(wx_PlatformInfo, GetPortIdName_1);
	Gura_AssignMethod(wx_PlatformInfo, GetPortIdShortName);
	Gura_AssignMethod(wx_PlatformInfo, GetPortIdShortName_1);
	Gura_AssignMethod(wx_PlatformInfo, GetToolkitMajorVersion);
	Gura_AssignMethod(wx_PlatformInfo, GetToolkitMinorVersion);
	Gura_AssignMethod(wx_PlatformInfo, IsOk);
	Gura_AssignMethod(wx_PlatformInfo, IsUsingUniversalWidgets);
	Gura_AssignMethod(wx_PlatformInfo, SetArchitecture);
	Gura_AssignMethod(wx_PlatformInfo, SetEndianness);
	Gura_AssignMethod(wx_PlatformInfo, SetOSVersion);
	Gura_AssignMethod(wx_PlatformInfo, SetOperatingSystemId);
	Gura_AssignMethod(wx_PlatformInfo, SetPortId);
	Gura_AssignMethod(wx_PlatformInfo, SetToolkitVersion);
}

Gura_ImplementDescendantCreator(wx_PlatformInfo)
{
	return new Object_wx_PlatformInfo((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
