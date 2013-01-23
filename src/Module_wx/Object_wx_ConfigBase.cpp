//----------------------------------------------------------------------------
// wxConfigBase
// extracted from config.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ConfigBase: public wxConfigBase, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_ConfigBase *_pObj;
public:
	//inline wx_ConfigBase(const wxString& appName, const wxString& vendorName, const wxString& localFilename, const wxString& globalFilename, long style, wxMBConv& conv) : wxConfigBase(appName, vendorName, localFilename, globalFilename, style, conv), _sig(NULL), _pObj(NULL) {}
	~wx_ConfigBase();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ConfigBase *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ConfigBase::~wx_ConfigBase()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_ConfigBase::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxConfigBase
//----------------------------------------------------------------------------
Gura_DeclareFunction(ConfigBase)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	Object_wx_ConfigBase *pObj = Object_wx_ConfigBase::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_ConfigBase(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_ConfigBase, Create)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_ConfigBase, Create)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxConfigBase *rtn = (wxConfigBase *)wxConfigBase::Create();
	return ReturnValue(env, sig, args, Value(new Object_wx_ConfigBase(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_ConfigBase, DontCreateOnDemand)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ConfigBase, DontCreateOnDemand)
{
	Object_wx_ConfigBase *pSelf = Object_wx_ConfigBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->DontCreateOnDemand();
	return Value::Null;
}

Gura_DeclareMethod(wx_ConfigBase, DeleteAll)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, DeleteAll)
{
	Object_wx_ConfigBase *pSelf = Object_wx_ConfigBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->DeleteAll();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ConfigBase, DeleteEntry)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "key", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "bDeleteGroupIfEmpty", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, DeleteEntry)
{
	Object_wx_ConfigBase *pSelf = Object_wx_ConfigBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString key = wxString::FromUTF8(args.GetString(0));
	bool bDeleteGroupIfEmpty = true;
	if (args.IsValid(1)) bDeleteGroupIfEmpty = args.GetBoolean(1);
	bool rtn = pSelf->GetEntity()->DeleteEntry(key, bDeleteGroupIfEmpty);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ConfigBase, DeleteGroup)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "key", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, DeleteGroup)
{
	Object_wx_ConfigBase *pSelf = Object_wx_ConfigBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString key = wxString::FromUTF8(args.GetString(0));
	bool rtn = pSelf->GetEntity()->DeleteGroup(key);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ConfigBase, Exists)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "strName", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, Exists)
{
	Object_wx_ConfigBase *pSelf = Object_wx_ConfigBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString strName = wxString::FromUTF8(args.GetString(0));
	bool rtn = pSelf->GetEntity()->Exists(strName);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ConfigBase, Flush)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "bCurrentOnly", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, Flush)
{
	Object_wx_ConfigBase *pSelf = Object_wx_ConfigBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool bCurrentOnly = false;
	if (args.IsValid(0)) bCurrentOnly = args.GetBoolean(0);
	bool rtn = pSelf->GetEntity()->Flush(bCurrentOnly);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_ConfigBase, Get)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "CreateOnDemand", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_ConfigBase, Get)
{
	if (!CheckWxReady(sig)) return Value::Null;
	bool CreateOnDemand = true;
	if (args.IsValid(0)) CreateOnDemand = args.GetBoolean(0);
	wxConfigBase *rtn = (wxConfigBase *)wxConfigBase::Get(CreateOnDemand);
	return ReturnValue(env, sig, args, Value(new Object_wx_ConfigBase(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_ConfigBase, GetAppName)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, GetAppName)
{
	Object_wx_ConfigBase *pSelf = Object_wx_ConfigBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetAppName();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_ConfigBase, GetEntryType)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, GetEntryType)
{
	Object_wx_ConfigBase *pSelf = Object_wx_ConfigBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
}

Gura_DeclareMethod(wx_ConfigBase, GetFirstGroup)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "str", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, GetFirstGroup)
{
	Object_wx_ConfigBase *pSelf = Object_wx_ConfigBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString str = wxString::FromUTF8(args.GetString(0));
	long index = args.GetLong(1);
	bool rtn = pSelf->GetEntity()->GetFirstGroup(str, index);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ConfigBase, GetFirstEntry)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "str", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, GetFirstEntry)
{
	Object_wx_ConfigBase *pSelf = Object_wx_ConfigBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString str = wxString::FromUTF8(args.GetString(0));
	long index = args.GetLong(1);
	bool rtn = pSelf->GetEntity()->GetFirstEntry(str, index);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ConfigBase, GetNextGroup)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "str", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, GetNextGroup)
{
	Object_wx_ConfigBase *pSelf = Object_wx_ConfigBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString str = wxString::FromUTF8(args.GetString(0));
	long index = args.GetLong(1);
	bool rtn = pSelf->GetEntity()->GetNextGroup(str, index);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ConfigBase, GetNextEntry)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "str", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, GetNextEntry)
{
	Object_wx_ConfigBase *pSelf = Object_wx_ConfigBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString str = wxString::FromUTF8(args.GetString(0));
	long index = args.GetLong(1);
	bool rtn = pSelf->GetEntity()->GetNextEntry(str, index);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ConfigBase, GetNumberOfEntries)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "bRecursive", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, GetNumberOfEntries)
{
	Object_wx_ConfigBase *pSelf = Object_wx_ConfigBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool bRecursive = false;
	if (args.IsValid(0)) bRecursive = args.GetBoolean(0);
}

Gura_DeclareMethod(wx_ConfigBase, GetNumberOfGroups)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "bRecursive", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, GetNumberOfGroups)
{
	Object_wx_ConfigBase *pSelf = Object_wx_ConfigBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool bRecursive = false;
	if (args.IsValid(0)) bRecursive = args.GetBoolean(0);
}

Gura_DeclareMethod(wx_ConfigBase, GetPath)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, GetPath)
{
	Object_wx_ConfigBase *pSelf = Object_wx_ConfigBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetPath();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_ConfigBase, GetVendorName)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, GetVendorName)
{
	Object_wx_ConfigBase *pSelf = Object_wx_ConfigBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetVendorName();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_ConfigBase, HasEntry)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "strName", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, HasEntry)
{
	Object_wx_ConfigBase *pSelf = Object_wx_ConfigBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString strName = wxString::FromUTF8(args.GetString(0));
	bool rtn = pSelf->GetEntity()->HasEntry(strName);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ConfigBase, HasGroup)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "strName", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, HasGroup)
{
	Object_wx_ConfigBase *pSelf = Object_wx_ConfigBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString strName = wxString::FromUTF8(args.GetString(0));
	bool rtn = pSelf->GetEntity()->HasGroup(strName);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ConfigBase, IsExpandingEnvVars)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, IsExpandingEnvVars)
{
	Object_wx_ConfigBase *pSelf = Object_wx_ConfigBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsExpandingEnvVars();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ConfigBase, IsRecordingDefaults)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, IsRecordingDefaults)
{
	Object_wx_ConfigBase *pSelf = Object_wx_ConfigBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsRecordingDefaults();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ConfigBase, Read)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "key", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "str", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, Read)
{
	Object_wx_ConfigBase *pSelf = Object_wx_ConfigBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString key = wxString::FromUTF8(args.GetString(0));
	wxString str = wxString::FromUTF8(args.GetString(1));
	bool rtn = pSelf->GetEntity()->Read(key, str);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ConfigBase, Read_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	Object_wx_ConfigBase *pSelf = Object_wx_ConfigBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString key = wxString::FromUTF8(args.GetString(0));
	wxString str = wxString::FromUTF8(args.GetString(1));
	wxString defaultVal = wxString::FromUTF8(args.GetString(2));
	bool rtn = pSelf->GetEntity()->Read(key, str, defaultVal);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_ConfigBase, Read_2)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "key", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "defaultVal", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, Read_2)
{
	Object_wx_ConfigBase *pSelf = Object_wx_ConfigBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString key = wxString::FromUTF8(args.GetString(0));
	wxString defaultVal = wxString::FromUTF8(args.GetString(1));
	wxString rtn = pSelf->GetEntity()->Read(key, defaultVal);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_ConfigBase, Read_3)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "key", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "l", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, Read_3)
{
	Object_wx_ConfigBase *pSelf = Object_wx_ConfigBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString key = wxString::FromUTF8(args.GetString(0));
	long l = args.GetLong(1);
	bool rtn = pSelf->GetEntity()->Read(key, l);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ConfigBase, Read_4)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	Object_wx_ConfigBase *pSelf = Object_wx_ConfigBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString key = wxString::FromUTF8(args.GetString(0));
	long l = args.GetLong(1);
	long defaultVal = args.GetLong(2);
	bool rtn = pSelf->GetEntity()->Read(key, l, defaultVal);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_ConfigBase, Read_5)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "key", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "defaultVal", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, Read_5)
{
	Object_wx_ConfigBase *pSelf = Object_wx_ConfigBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString key = wxString::FromUTF8(args.GetString(0));
	long defaultVal = args.GetLong(1);
	long rtn = pSelf->GetEntity()->Read(key, defaultVal);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ConfigBase, Read_6)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "key", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "d", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, Read_6)
{
	Object_wx_ConfigBase *pSelf = Object_wx_ConfigBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString key = wxString::FromUTF8(args.GetString(0));
	double d = args.GetDouble(1);
	bool rtn = pSelf->GetEntity()->Read(key, d);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ConfigBase, Read_7)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	Object_wx_ConfigBase *pSelf = Object_wx_ConfigBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString key = wxString::FromUTF8(args.GetString(0));
	double d = args.GetDouble(1);
	double defaultVal = args.GetDouble(2);
	bool rtn = pSelf->GetEntity()->Read(key, d, defaultVal);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_ConfigBase, Read_8)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "key", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "b", VTYPE_boolean, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, Read_8)
{
	Object_wx_ConfigBase *pSelf = Object_wx_ConfigBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString key = wxString::FromUTF8(args.GetString(0));
	bool b = args.GetBoolean(1);
	bool rtn = pSelf->GetEntity()->Read(key, b);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ConfigBase, Read_9)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	Object_wx_ConfigBase *pSelf = Object_wx_ConfigBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString key = wxString::FromUTF8(args.GetString(0));
	bool d = args.GetBoolean(1);
	bool defaultVal = args.GetBoolean(2);
	bool rtn = pSelf->GetEntity()->Read(key, d, defaultVal);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_ConfigBase, RenameEntry)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "oldName", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "newName", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, RenameEntry)
{
	Object_wx_ConfigBase *pSelf = Object_wx_ConfigBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString oldName = wxString::FromUTF8(args.GetString(0));
	wxString newName = wxString::FromUTF8(args.GetString(1));
	bool rtn = pSelf->GetEntity()->RenameEntry(oldName, newName);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ConfigBase, RenameGroup)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "oldName", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "newName", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, RenameGroup)
{
	Object_wx_ConfigBase *pSelf = Object_wx_ConfigBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString oldName = wxString::FromUTF8(args.GetString(0));
	wxString newName = wxString::FromUTF8(args.GetString(1));
	bool rtn = pSelf->GetEntity()->RenameGroup(oldName, newName);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_ConfigBase, Set)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pConfig", VTYPE_wx_ConfigBase, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_ConfigBase, Set)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxConfigBase *pConfig = Object_wx_ConfigBase::GetObject(args, 0)->GetEntity();
	wxConfigBase *rtn = (wxConfigBase *)wxConfigBase::Set(pConfig);
	return ReturnValue(env, sig, args, Value(new Object_wx_ConfigBase(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_ConfigBase, SetExpandEnvVars)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "bDoIt", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, SetExpandEnvVars)
{
	Object_wx_ConfigBase *pSelf = Object_wx_ConfigBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool bDoIt = true;
	if (args.IsValid(0)) bDoIt = args.GetBoolean(0);
	pSelf->GetEntity()->SetExpandEnvVars(bDoIt);
	return Value::Null;
}

Gura_DeclareMethod(wx_ConfigBase, SetPath)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "strPath", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_ConfigBase, SetPath)
{
	Object_wx_ConfigBase *pSelf = Object_wx_ConfigBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString strPath = wxString::FromUTF8(args.GetString(0));
	pSelf->GetEntity()->SetPath(strPath);
	return Value::Null;
}

Gura_DeclareMethod(wx_ConfigBase, SetRecordDefaults)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "bDoIt", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, SetRecordDefaults)
{
	Object_wx_ConfigBase *pSelf = Object_wx_ConfigBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool bDoIt = true;
	if (args.IsValid(0)) bDoIt = args.GetBoolean(0);
	pSelf->GetEntity()->SetRecordDefaults(bDoIt);
	return Value::Null;
}

Gura_DeclareMethod(wx_ConfigBase, Write)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "key", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, Write)
{
	Object_wx_ConfigBase *pSelf = Object_wx_ConfigBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString key = wxString::FromUTF8(args.GetString(0));
	wxString value = wxString::FromUTF8(args.GetString(1));
	bool rtn = pSelf->GetEntity()->Write(key, value);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ConfigBase, Write_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "key", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, Write_1)
{
	Object_wx_ConfigBase *pSelf = Object_wx_ConfigBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString key = wxString::FromUTF8(args.GetString(0));
	long value = args.GetLong(1);
	bool rtn = pSelf->GetEntity()->Write(key, value);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ConfigBase, Write_2)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "key", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, Write_2)
{
	Object_wx_ConfigBase *pSelf = Object_wx_ConfigBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString key = wxString::FromUTF8(args.GetString(0));
	double value = args.GetDouble(1);
	bool rtn = pSelf->GetEntity()->Write(key, value);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ConfigBase, Write_3)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "key", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "value", VTYPE_boolean, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ConfigBase, Write_3)
{
	Object_wx_ConfigBase *pSelf = Object_wx_ConfigBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString key = wxString::FromUTF8(args.GetString(0));
	bool value = args.GetBoolean(1);
	bool rtn = pSelf->GetEntity()->Write(key, value);
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxConfigBase
//----------------------------------------------------------------------------
Object_wx_ConfigBase::~Object_wx_ConfigBase()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_ConfigBase::Clone() const
{
	return NULL;
}

String Object_wx_ConfigBase::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.ConfigBase:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_ConfigBase::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(ConfigBase);
}

//----------------------------------------------------------------------------
// Class implementation for wxConfigBase
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ConfigBase)
{
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
	return new Object_wx_ConfigBase((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
