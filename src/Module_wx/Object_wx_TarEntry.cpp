//----------------------------------------------------------------------------
// wxTarEntry
// extracted from tarstrm.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_TarEntry: public wxTarEntry, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_TarEntry *_pObj;
public:
	inline wx_TarEntry(const wxString& name, const wxDateTime& dt, wxFileOffset size) : wxTarEntry(name, dt, size), _sig(NULL), _pObj(NULL) {}
	inline wx_TarEntry(const wxTarEntry& entry) : wxTarEntry(entry), _sig(NULL), _pObj(NULL) {}
	~wx_TarEntry();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_TarEntry *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_TarEntry::~wx_TarEntry()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_TarEntry::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxTarEntry
//----------------------------------------------------------------------------
Gura_DeclareFunction(TarEntry)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_TarEntry));
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "dt", VTYPE_wx_DateTime, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(TarEntry)
{
	wxString name = wxEmptyString;
	if (args.IsValid(0)) name = wxString::FromUTF8(args.GetString(0));
	wxDateTime *dt = (wxDateTime *)(&wxDateTime::Now());
	if (args.IsValid(1)) dt = Object_wx_DateTime::GetObject(args, 1)->GetEntity();
	wxFileOffset size = wxInvalidOffset;
	if (args.IsValid(2)) size = static_cast<wxFileOffset>(args.GetInt64(2));
	wx_TarEntry *pEntity = new wx_TarEntry(name, *dt, size);
	Object_wx_TarEntry *pObj = Object_wx_TarEntry::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_TarEntry(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareFunction(TarEntry_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_TarEntry));
	DeclareArg(env, "entry", VTYPE_wx_TarEntry, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(TarEntry_1)
{
	wxTarEntry *entry = Object_wx_TarEntry::GetObject(args, 0)->GetEntity();
	wx_TarEntry *pEntity = new wx_TarEntry(*entry);
	Object_wx_TarEntry *pObj = Object_wx_TarEntry::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_TarEntry(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_TarEntry, GetAccessTime)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TarEntry, GetAccessTime)
{
	Object_wx_TarEntry *pSelf = Object_wx_TarEntry::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxDateTime rtn = pSelf->GetEntity()->GetAccessTime();
	return ReturnValue(env, sig, args, Value(new Object_wx_DateTime(new wxDateTime(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_TarEntry, SetAccessTime)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dt", VTYPE_wx_DateTime, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarEntry, SetAccessTime)
{
	Object_wx_TarEntry *pSelf = Object_wx_TarEntry::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxDateTime *dt = Object_wx_DateTime::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetAccessTime(*dt);
	return Value::Null;
}

Gura_DeclareMethod(wx_TarEntry, GetCreateTime)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TarEntry, GetCreateTime)
{
	Object_wx_TarEntry *pSelf = Object_wx_TarEntry::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxDateTime rtn = pSelf->GetEntity()->GetCreateTime();
	return ReturnValue(env, sig, args, Value(new Object_wx_DateTime(new wxDateTime(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_TarEntry, SetCreateTime)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dt", VTYPE_wx_DateTime, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarEntry, SetCreateTime)
{
	Object_wx_TarEntry *pSelf = Object_wx_TarEntry::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxDateTime *dt = Object_wx_DateTime::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetCreateTime(*dt);
	return Value::Null;
}

Gura_DeclareMethod(wx_TarEntry, GetDevMajor)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TarEntry, GetDevMajor)
{
	Object_wx_TarEntry *pSelf = Object_wx_TarEntry::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetDevMajor();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TarEntry, GetDevMinor)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TarEntry, GetDevMinor)
{
	Object_wx_TarEntry *pSelf = Object_wx_TarEntry::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetDevMinor();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TarEntry, SetDevMajor)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dev", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarEntry, SetDevMajor)
{
	Object_wx_TarEntry *pSelf = Object_wx_TarEntry::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int dev = args.GetInt(0);
	pSelf->GetEntity()->SetDevMajor(dev);
	return Value::Null;
}

Gura_DeclareMethod(wx_TarEntry, SetDevMinor)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dev", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarEntry, SetDevMinor)
{
	Object_wx_TarEntry *pSelf = Object_wx_TarEntry::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int dev = args.GetInt(0);
	pSelf->GetEntity()->SetDevMinor(dev);
	return Value::Null;
}

Gura_DeclareMethod(wx_TarEntry, GetGroupId)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TarEntry, GetGroupId)
{
	Object_wx_TarEntry *pSelf = Object_wx_TarEntry::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetGroupId();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TarEntry, GetUserId)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TarEntry, GetUserId)
{
	Object_wx_TarEntry *pSelf = Object_wx_TarEntry::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetUserId();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TarEntry, SetGroupId)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarEntry, SetGroupId)
{
	Object_wx_TarEntry *pSelf = Object_wx_TarEntry::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int id = args.GetInt(0);
	pSelf->GetEntity()->SetGroupId(id);
	return Value::Null;
}

Gura_DeclareMethod(wx_TarEntry, SetUserId)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarEntry, SetUserId)
{
	Object_wx_TarEntry *pSelf = Object_wx_TarEntry::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int id = args.GetInt(0);
	pSelf->GetEntity()->SetUserId(id);
	return Value::Null;
}

Gura_DeclareMethod(wx_TarEntry, GetGroupName)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TarEntry, GetGroupName)
{
	Object_wx_TarEntry *pSelf = Object_wx_TarEntry::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetGroupName();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_TarEntry, GetUserName_)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TarEntry, GetUserName_)
{
	Object_wx_TarEntry *pSelf = Object_wx_TarEntry::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetUserName();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_TarEntry, SetGroupName)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "group", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarEntry, SetGroupName)
{
	Object_wx_TarEntry *pSelf = Object_wx_TarEntry::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString group = wxString::FromUTF8(args.GetString(0));
	pSelf->GetEntity()->SetGroupName(group);
	return Value::Null;
}

Gura_DeclareMethod(wx_TarEntry, SetUserName)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "user", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarEntry, SetUserName)
{
	Object_wx_TarEntry *pSelf = Object_wx_TarEntry::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString user = wxString::FromUTF8(args.GetString(0));
	pSelf->GetEntity()->SetUserName(user);
	return Value::Null;
}

Gura_DeclareMethod(wx_TarEntry, GetInternalName)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TarEntry, GetInternalName)
{
#if 0
	Object_wx_TarEntry *pSelf = Object_wx_TarEntry::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetInternalName();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_TarEntry, GetInternalName_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pIsDir", VTYPE_boolean, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TarEntry, GetInternalName_1)
{
#if 0
	Object_wx_TarEntry *pSelf = Object_wx_TarEntry::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	wxPathFormat format = wxPATH_NATIVE;
	if (args.IsValid(1)) format = static_cast<wxPathFormat>(args.GetInt(1));
	bool pIsDir = NULL;
	if (args.IsValid(2)) pIsDir = args.GetBoolean(2);
	wxString rtn = pSelf->GetEntity()->GetInternalName(name, format, pIsDir);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_TarEntry, GetLinkName)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TarEntry, GetLinkName)
{
	Object_wx_TarEntry *pSelf = Object_wx_TarEntry::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetLinkName();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_TarEntry, SetLinkName)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "link", VTYPE_string, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_TarEntry, SetLinkName)
{
#if 0
	Object_wx_TarEntry *pSelf = Object_wx_TarEntry::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString link = wxString::FromUTF8(args.GetString(0));
	pSelf->GetEntity()->SetLinkName(link);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_TarEntry, GetMode)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TarEntry, GetMode)
{
	Object_wx_TarEntry *pSelf = Object_wx_TarEntry::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetMode();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TarEntry, SetMode_)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarEntry, SetMode_)
{
	Object_wx_TarEntry *pSelf = Object_wx_TarEntry::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int mode = args.GetInt(0);
	pSelf->GetEntity()->SetMode(mode);
	return Value::Null;
}

Gura_DeclareMethod(wx_TarEntry, SetSize)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarEntry, SetSize)
{
	Object_wx_TarEntry *pSelf = Object_wx_TarEntry::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxFileOffset size = static_cast<wxFileOffset>(args.GetInt64(0));
	pSelf->GetEntity()->SetSize(size);
	return Value::Null;
}

Gura_DeclareMethod(wx_TarEntry, GetSize)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TarEntry, GetSize)
{
	Object_wx_TarEntry *pSelf = Object_wx_TarEntry::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxFileOffset rtn = pSelf->GetEntity()->GetSize();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TarEntry, GetTypeFlag)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TarEntry, GetTypeFlag)
{
	Object_wx_TarEntry *pSelf = Object_wx_TarEntry::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetTypeFlag();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TarEntry, SetTypeFlag)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarEntry, SetTypeFlag)
{
	Object_wx_TarEntry *pSelf = Object_wx_TarEntry::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int type = args.GetInt(0);
	pSelf->GetEntity()->SetTypeFlag(type);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxTarEntry
//----------------------------------------------------------------------------
Object_wx_TarEntry::~Object_wx_TarEntry()
{
}

Object *Object_wx_TarEntry::Clone() const
{
	return NULL;
}

String Object_wx_TarEntry::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.TarEntry:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_TarEntry::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(TarEntry);
	Gura_AssignFunction(TarEntry_1);
}

//----------------------------------------------------------------------------
// Class implementation for wxTarEntry
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TarEntry)
{
	Gura_AssignMethod(wx_TarEntry, GetAccessTime);
	Gura_AssignMethod(wx_TarEntry, SetAccessTime);
	Gura_AssignMethod(wx_TarEntry, GetCreateTime);
	Gura_AssignMethod(wx_TarEntry, SetCreateTime);
	Gura_AssignMethod(wx_TarEntry, GetDevMajor);
	Gura_AssignMethod(wx_TarEntry, GetDevMinor);
	Gura_AssignMethod(wx_TarEntry, SetDevMajor);
	Gura_AssignMethod(wx_TarEntry, SetDevMinor);
	Gura_AssignMethod(wx_TarEntry, GetGroupId);
	Gura_AssignMethod(wx_TarEntry, GetUserId);
	Gura_AssignMethod(wx_TarEntry, SetGroupId);
	Gura_AssignMethod(wx_TarEntry, SetUserId);
	Gura_AssignMethod(wx_TarEntry, GetGroupName);
	Gura_AssignMethodEx(wx_TarEntry, GetUserName_, "GetUserName");
	Gura_AssignMethod(wx_TarEntry, SetGroupName);
	Gura_AssignMethod(wx_TarEntry, SetUserName);
	Gura_AssignMethod(wx_TarEntry, GetInternalName);
	Gura_AssignMethod(wx_TarEntry, GetInternalName_1);
	Gura_AssignMethod(wx_TarEntry, GetLinkName);
	Gura_AssignMethod(wx_TarEntry, SetLinkName);
	Gura_AssignMethod(wx_TarEntry, GetMode);
	Gura_AssignMethodEx(wx_TarEntry, SetMode_, "SetMode");
	Gura_AssignMethod(wx_TarEntry, SetSize);
	Gura_AssignMethod(wx_TarEntry, GetSize);
	Gura_AssignMethod(wx_TarEntry, GetTypeFlag);
	Gura_AssignMethod(wx_TarEntry, SetTypeFlag);
}

Gura_ImplementDescendantCreator(wx_TarEntry)
{
	return new Object_wx_TarEntry((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
