//----------------------------------------------------------------------------
// wxConfigBase
// extracted from config.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ConfigBase: public wxConfigBase, public GuraObjectObserver {
private:
	Gura::Signal *_pSig;
	Object_wx_ConfigBase *_pObj;
public:
	//inline wx_ConfigBase(const wxString& appName, const wxString& vendorName, const wxString& localFilename, const wxString& globalFilename, long style, wxMBConv& conv) : wxConfigBase(appName, vendorName, localFilename, globalFilename, style, conv), _pSig(nullptr), _pObj(nullptr) {}
	~wx_ConfigBase();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ConfigBase *pObj) {
		_pSig = &sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ConfigBase::~wx_ConfigBase()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_ConfigBase::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxConfigBase
//----------------------------------------------------------------------------
Gura_DeclareFunction(ConfigBase)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_ConfigBase));
	DeclareArg(env, "appName", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "vendorName", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "localFilename", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "globalFilename", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "conv", VTYPE_wx_MBConv, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(ConfigBase)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxString appName = wxEmptyString;
	if (args.IsValid(0)) appName = wxString::FromUTF8(args.GetString(0));
	wxString vendorName = wxEmptyString;
	if (args.IsValid(1)) vendorName = wxString::FromUTF8(args.GetString(1));
	wxString localFilename = wxEmptyString;
	if (args.IsValid(2)) localFilename = wxString::FromUTF8(args.GetString(2));
	wxString globalFilename = wxEmptyString;
	if (args.IsValid(3)) globalFilename = wxString::FromUTF8(args.GetString(3));
	long style = 0;
	if (args.IsValid(4)) style = args.GetLong(4);
	wxMBConv *conv = (wxMBConv *)(&wxConvUTF8);
	if (args.IsValid(5)) conv = Object_wx_MBConv::GetObject(args, 5)->GetEntity();
	wx_ConfigBase *pEntity = new wx_ConfigBase(appName, vendorName, localFilename, globalFilename, style, *conv);
	Object_wx_ConfigBase *pObj = Object_wx_ConfigBase::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_ConfigBase(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_ConfigBase, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_ConfigBase, Create)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxConfigBase *rtn = (wxConfigBase *)wxConfigBase::Create();
	return ReturnValue(env, args, Value(new Object_wx_ConfigBase(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_ConfigBase, DontCreateOnDemand)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ConfigBase, DontCreateOnDemand)
{
	Object_wx_ConfigBase *pThis = Object_wx_ConfigBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->DontCreateOnDemand();
	return Value::Null;
}

Gura_DeclareMethod(wx_ConfigBase, DeleteAll)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, DeleteAll)
{
	Object_wx_ConfigBase *pThis = Object_wx_ConfigBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->DeleteAll();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ConfigBase, DeleteEntry)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "key", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "bDeleteGroupIfEmpty", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, DeleteEntry)
{
	Object_wx_ConfigBase *pThis = Object_wx_ConfigBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString key = wxString::FromUTF8(args.GetString(0));
	bool bDeleteGroupIfEmpty = true;
	if (args.IsValid(1)) bDeleteGroupIfEmpty = args.GetBoolean(1);
	bool rtn = pThis->GetEntity()->DeleteEntry(key, bDeleteGroupIfEmpty);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ConfigBase, DeleteGroup)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "key", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, DeleteGroup)
{
	Object_wx_ConfigBase *pThis = Object_wx_ConfigBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString key = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->DeleteGroup(key);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ConfigBase, Exists)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "strName", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, Exists)
{
	Object_wx_ConfigBase *pThis = Object_wx_ConfigBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString strName = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->Exists(strName);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ConfigBase, Flush)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "bCurrentOnly", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, Flush)
{
	Object_wx_ConfigBase *pThis = Object_wx_ConfigBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool bCurrentOnly = false;
	if (args.IsValid(0)) bCurrentOnly = args.GetBoolean(0);
	bool rtn = pThis->GetEntity()->Flush(bCurrentOnly);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_ConfigBase, Get)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "CreateOnDemand", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_ConfigBase, Get)
{
	if (!CheckWxReady(sig)) return Value::Null;
	bool CreateOnDemand = true;
	if (args.IsValid(0)) CreateOnDemand = args.GetBoolean(0);
	wxConfigBase *rtn = (wxConfigBase *)wxConfigBase::Get(CreateOnDemand);
	return ReturnValue(env, args, Value(new Object_wx_ConfigBase(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_ConfigBase, GetAppName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, GetAppName)
{
	Object_wx_ConfigBase *pThis = Object_wx_ConfigBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetAppName();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_ConfigBase, GetEntryType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, GetEntryType)
{
	Object_wx_ConfigBase *pThis = Object_wx_ConfigBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
}

Gura_DeclareMethod(wx_ConfigBase, GetFirstGroup)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "str", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, GetFirstGroup)
{
	Object_wx_ConfigBase *pThis = Object_wx_ConfigBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString str = wxString::FromUTF8(args.GetString(0));
	long index = args.GetLong(1);
	bool rtn = pThis->GetEntity()->GetFirstGroup(str, index);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ConfigBase, GetFirstEntry)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "str", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, GetFirstEntry)
{
	Object_wx_ConfigBase *pThis = Object_wx_ConfigBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString str = wxString::FromUTF8(args.GetString(0));
	long index = args.GetLong(1);
	bool rtn = pThis->GetEntity()->GetFirstEntry(str, index);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ConfigBase, GetNextGroup)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "str", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, GetNextGroup)
{
	Object_wx_ConfigBase *pThis = Object_wx_ConfigBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString str = wxString::FromUTF8(args.GetString(0));
	long index = args.GetLong(1);
	bool rtn = pThis->GetEntity()->GetNextGroup(str, index);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ConfigBase, GetNextEntry)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "str", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, GetNextEntry)
{
	Object_wx_ConfigBase *pThis = Object_wx_ConfigBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString str = wxString::FromUTF8(args.GetString(0));
	long index = args.GetLong(1);
	bool rtn = pThis->GetEntity()->GetNextEntry(str, index);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ConfigBase, GetNumberOfEntries)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "bRecursive", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, GetNumberOfEntries)
{
	Object_wx_ConfigBase *pThis = Object_wx_ConfigBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool bRecursive = false;
	if (args.IsValid(0)) bRecursive = args.GetBoolean(0);
}

Gura_DeclareMethod(wx_ConfigBase, GetNumberOfGroups)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "bRecursive", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, GetNumberOfGroups)
{
	Object_wx_ConfigBase *pThis = Object_wx_ConfigBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool bRecursive = false;
	if (args.IsValid(0)) bRecursive = args.GetBoolean(0);
}

Gura_DeclareMethod(wx_ConfigBase, GetPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, GetPath)
{
	Object_wx_ConfigBase *pThis = Object_wx_ConfigBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetPath();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_ConfigBase, GetVendorName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, GetVendorName)
{
	Object_wx_ConfigBase *pThis = Object_wx_ConfigBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetVendorName();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_ConfigBase, HasEntry)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "strName", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, HasEntry)
{
	Object_wx_ConfigBase *pThis = Object_wx_ConfigBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString strName = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->HasEntry(strName);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ConfigBase, HasGroup)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "strName", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, HasGroup)
{
	Object_wx_ConfigBase *pThis = Object_wx_ConfigBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString strName = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->HasGroup(strName);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ConfigBase, IsExpandingEnvVars)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, IsExpandingEnvVars)
{
	Object_wx_ConfigBase *pThis = Object_wx_ConfigBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsExpandingEnvVars();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ConfigBase, IsRecordingDefaults)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, IsRecordingDefaults)
{
	Object_wx_ConfigBase *pThis = Object_wx_ConfigBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsRecordingDefaults();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ConfigBase, Read)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "key", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "str", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, Read)
{
#if 0
	Object_wx_ConfigBase *pThis = Object_wx_ConfigBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString key = wxString::FromUTF8(args.GetString(0));
	wxString str = wxString::FromUTF8(args.GetString(1));
	bool rtn = pThis->GetEntity()->Read(key, str);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_ConfigBase, Read_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "key", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "str", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "defaultVal", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, Read_1)
{
#if 0
	Object_wx_ConfigBase *pThis = Object_wx_ConfigBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString key = wxString::FromUTF8(args.GetString(0));
	wxString str = wxString::FromUTF8(args.GetString(1));
	wxString defaultVal = wxString::FromUTF8(args.GetString(2));
	bool rtn = pThis->GetEntity()->Read(key, str, defaultVal);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_ConfigBase, Read_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "key", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "defaultVal", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, Read_2)
{
	Object_wx_ConfigBase *pThis = Object_wx_ConfigBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString key = wxString::FromUTF8(args.GetString(0));
	wxString defaultVal = wxString::FromUTF8(args.GetString(1));
	wxString rtn = pThis->GetEntity()->Read(key, defaultVal);
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_ConfigBase, Read_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "key", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "l", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, Read_3)
{
	Object_wx_ConfigBase *pThis = Object_wx_ConfigBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString key = wxString::FromUTF8(args.GetString(0));
	long l = args.GetLong(1);
	bool rtn = pThis->GetEntity()->Read(key, l);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ConfigBase, Read_4)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "key", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "l", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "defaultVal", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, Read_4)
{
#if 0
	Object_wx_ConfigBase *pThis = Object_wx_ConfigBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString key = wxString::FromUTF8(args.GetString(0));
	long l = args.GetLong(1);
	long defaultVal = args.GetLong(2);
	bool rtn = pThis->GetEntity()->Read(key, l, defaultVal);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_ConfigBase, Read_5)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "key", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "defaultVal", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, Read_5)
{
	Object_wx_ConfigBase *pThis = Object_wx_ConfigBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString key = wxString::FromUTF8(args.GetString(0));
	long defaultVal = args.GetLong(1);
	long rtn = pThis->GetEntity()->Read(key, defaultVal);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ConfigBase, Read_6)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "key", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "d", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, Read_6)
{
	Object_wx_ConfigBase *pThis = Object_wx_ConfigBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString key = wxString::FromUTF8(args.GetString(0));
	double d = args.GetDouble(1);
	bool rtn = pThis->GetEntity()->Read(key, d);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ConfigBase, Read_7)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "key", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "d", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "defaultVal", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, Read_7)
{
#if 0
	Object_wx_ConfigBase *pThis = Object_wx_ConfigBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString key = wxString::FromUTF8(args.GetString(0));
	double d = args.GetDouble(1);
	double defaultVal = args.GetDouble(2);
	bool rtn = pThis->GetEntity()->Read(key, d, defaultVal);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_ConfigBase, Read_8)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "key", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "b", VTYPE_boolean, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, Read_8)
{
	Object_wx_ConfigBase *pThis = Object_wx_ConfigBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString key = wxString::FromUTF8(args.GetString(0));
	bool b = args.GetBoolean(1);
	bool rtn = pThis->GetEntity()->Read(key, b);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ConfigBase, Read_9)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "key", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "d", VTYPE_boolean, OCCUR_Once);
	DeclareArg(env, "defaultVal", VTYPE_boolean, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, Read_9)
{
#if 0
	Object_wx_ConfigBase *pThis = Object_wx_ConfigBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString key = wxString::FromUTF8(args.GetString(0));
	bool d = args.GetBoolean(1);
	bool defaultVal = args.GetBoolean(2);
	bool rtn = pThis->GetEntity()->Read(key, d, defaultVal);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_ConfigBase, RenameEntry)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "oldName", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "newName", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, RenameEntry)
{
	Object_wx_ConfigBase *pThis = Object_wx_ConfigBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString oldName = wxString::FromUTF8(args.GetString(0));
	wxString newName = wxString::FromUTF8(args.GetString(1));
	bool rtn = pThis->GetEntity()->RenameEntry(oldName, newName);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ConfigBase, RenameGroup)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "oldName", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "newName", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, RenameGroup)
{
	Object_wx_ConfigBase *pThis = Object_wx_ConfigBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString oldName = wxString::FromUTF8(args.GetString(0));
	wxString newName = wxString::FromUTF8(args.GetString(1));
	bool rtn = pThis->GetEntity()->RenameGroup(oldName, newName);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_ConfigBase, Set)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pConfig", VTYPE_wx_ConfigBase, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_ConfigBase, Set)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxConfigBase *pConfig = Object_wx_ConfigBase::GetObject(args, 0)->GetEntity();
	wxConfigBase *rtn = (wxConfigBase *)wxConfigBase::Set(pConfig);
	return ReturnValue(env, args, Value(new Object_wx_ConfigBase(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_ConfigBase, SetExpandEnvVars)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "bDoIt", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, SetExpandEnvVars)
{
	Object_wx_ConfigBase *pThis = Object_wx_ConfigBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool bDoIt = true;
	if (args.IsValid(0)) bDoIt = args.GetBoolean(0);
	pThis->GetEntity()->SetExpandEnvVars(bDoIt);
	return Value::Null;
}

Gura_DeclareMethod(wx_ConfigBase, SetPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "strPath", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_ConfigBase, SetPath)
{
	Object_wx_ConfigBase *pThis = Object_wx_ConfigBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString strPath = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetPath(strPath);
	return Value::Null;
}

Gura_DeclareMethod(wx_ConfigBase, SetRecordDefaults)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "bDoIt", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, SetRecordDefaults)
{
	Object_wx_ConfigBase *pThis = Object_wx_ConfigBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool bDoIt = true;
	if (args.IsValid(0)) bDoIt = args.GetBoolean(0);
	pThis->GetEntity()->SetRecordDefaults(bDoIt);
	return Value::Null;
}

Gura_DeclareMethod(wx_ConfigBase, Write)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "key", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, Write)
{
	Object_wx_ConfigBase *pThis = Object_wx_ConfigBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString key = wxString::FromUTF8(args.GetString(0));
	wxString value = wxString::FromUTF8(args.GetString(1));
	bool rtn = pThis->GetEntity()->Write(key, value);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ConfigBase, Write_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "key", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, Write_1)
{
	Object_wx_ConfigBase *pThis = Object_wx_ConfigBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString key = wxString::FromUTF8(args.GetString(0));
	long value = args.GetLong(1);
	bool rtn = pThis->GetEntity()->Write(key, value);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ConfigBase, Write_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "key", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, Write_2)
{
	Object_wx_ConfigBase *pThis = Object_wx_ConfigBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString key = wxString::FromUTF8(args.GetString(0));
	double value = args.GetDouble(1);
	bool rtn = pThis->GetEntity()->Write(key, value);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ConfigBase, Write_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "key", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_boolean, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, Write_3)
{
	Object_wx_ConfigBase *pThis = Object_wx_ConfigBase::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString key = wxString::FromUTF8(args.GetString(0));
	bool value = args.GetBoolean(1);
	bool rtn = pThis->GetEntity()->Write(key, value);
	return ReturnValue(env, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxConfigBase
//----------------------------------------------------------------------------
Object_wx_ConfigBase::~Object_wx_ConfigBase()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_ConfigBase::Clone() const
{
	return nullptr;
}

String Object_wx_ConfigBase::ToString(bool exprFlag)
{
	String rtn("<wx.ConfigBase:");
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
// Class implementation for wxConfigBase
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ConfigBase)
{
	Gura_AssignFunction(ConfigBase);
	Gura_AssignMethod(wx_ConfigBase, Create);
	Gura_AssignMethod(wx_ConfigBase, DontCreateOnDemand);
	Gura_AssignMethod(wx_ConfigBase, DeleteAll);
	Gura_AssignMethod(wx_ConfigBase, DeleteEntry);
	Gura_AssignMethod(wx_ConfigBase, DeleteGroup);
	Gura_AssignMethod(wx_ConfigBase, Exists);
	Gura_AssignMethod(wx_ConfigBase, Flush);
	Gura_AssignMethod(wx_ConfigBase, Get);
	Gura_AssignMethod(wx_ConfigBase, GetAppName);
	Gura_AssignMethod(wx_ConfigBase, GetEntryType);
	Gura_AssignMethod(wx_ConfigBase, GetFirstGroup);
	Gura_AssignMethod(wx_ConfigBase, GetFirstEntry);
	Gura_AssignMethod(wx_ConfigBase, GetNextGroup);
	Gura_AssignMethod(wx_ConfigBase, GetNextEntry);
	Gura_AssignMethod(wx_ConfigBase, GetNumberOfEntries);
	Gura_AssignMethod(wx_ConfigBase, GetNumberOfGroups);
	Gura_AssignMethod(wx_ConfigBase, GetPath);
	Gura_AssignMethod(wx_ConfigBase, GetVendorName);
	Gura_AssignMethod(wx_ConfigBase, HasEntry);
	Gura_AssignMethod(wx_ConfigBase, HasGroup);
	Gura_AssignMethod(wx_ConfigBase, IsExpandingEnvVars);
	Gura_AssignMethod(wx_ConfigBase, IsRecordingDefaults);
	Gura_AssignMethod(wx_ConfigBase, Read);
	Gura_AssignMethod(wx_ConfigBase, Read_1);
	Gura_AssignMethod(wx_ConfigBase, Read_2);
	Gura_AssignMethod(wx_ConfigBase, Read_3);
	Gura_AssignMethod(wx_ConfigBase, Read_4);
	Gura_AssignMethod(wx_ConfigBase, Read_5);
	Gura_AssignMethod(wx_ConfigBase, Read_6);
	Gura_AssignMethod(wx_ConfigBase, Read_7);
	Gura_AssignMethod(wx_ConfigBase, Read_8);
	Gura_AssignMethod(wx_ConfigBase, Read_9);
	Gura_AssignMethod(wx_ConfigBase, RenameEntry);
	Gura_AssignMethod(wx_ConfigBase, RenameGroup);
	Gura_AssignMethod(wx_ConfigBase, Set);
	Gura_AssignMethod(wx_ConfigBase, SetExpandEnvVars);
	Gura_AssignMethod(wx_ConfigBase, SetPath);
	Gura_AssignMethod(wx_ConfigBase, SetRecordDefaults);
	Gura_AssignMethod(wx_ConfigBase, Write);
	Gura_AssignMethod(wx_ConfigBase, Write_1);
	Gura_AssignMethod(wx_ConfigBase, Write_2);
	Gura_AssignMethod(wx_ConfigBase, Write_3);
}

Gura_ImplementDescendantCreator(wx_ConfigBase)
{
	return new Object_wx_ConfigBase((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
