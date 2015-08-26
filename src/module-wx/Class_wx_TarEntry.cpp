//----------------------------------------------------------------------------
// wxTarEntry
// extracted from tarstrm.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_TarEntry: public wxTarEntry, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_TarEntry *_pObj;
public:
	inline wx_TarEntry(const wxString& name, const wxDateTime& dt, wxFileOffset size) : wxTarEntry(name, dt, size), _pObj(nullptr) {}
	inline wx_TarEntry(const wxTarEntry& entry) : wxTarEntry(entry), _pObj(nullptr) {}
	~wx_TarEntry();
	inline void AssocWithGura(Object_wx_TarEntry *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_TarEntry::~wx_TarEntry()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_TarEntry::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxTarEntry
//----------------------------------------------------------------------------
Gura_DeclareFunction(TarEntry)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_TarEntry));
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "dt", VTYPE_wx_DateTime, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(TarEntry)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString name = wxEmptyString;
	if (args.IsValid(0)) name = wxString::FromUTF8(args.GetString(0));
	wxDateTime dt = wxDateTime::Now();
	if (args.IsValid(1)) dt = *Object_wx_DateTime::GetObject(args, 1)->GetEntity();
	wxFileOffset size = wxInvalidOffset;
	if (args.IsValid(2)) size = static_cast<wxFileOffset>(args.GetInt64(2));
	wx_TarEntry *pEntity = new wx_TarEntry(name, dt, size);
	Object_wx_TarEntry *pObj = Object_wx_TarEntry::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_TarEntry(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareFunction(TarEntry_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_TarEntry));
	DeclareArg(env, "entry", VTYPE_wx_TarEntry, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(TarEntry_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxTarEntry *entry = Object_wx_TarEntry::GetObject(args, 0)->GetEntity();
	wx_TarEntry *pEntity = new wx_TarEntry(*entry);
	Object_wx_TarEntry *pObj = Object_wx_TarEntry::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_TarEntry(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareMethod(wx_TarEntry, GetAccessTime)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TarEntry, GetAccessTime)
{
	Signal &sig = env.GetSignal();
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDateTime rtn = pThis->GetEntity()->GetAccessTime();
	return ReturnValue(env, args, Value(new Object_wx_DateTime(new wxDateTime(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_TarEntry, SetAccessTime)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dt", VTYPE_wx_DateTime, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarEntry, SetAccessTime)
{
	Signal &sig = env.GetSignal();
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDateTime *dt = Object_wx_DateTime::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetAccessTime(*dt);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TarEntry, GetCreateTime)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TarEntry, GetCreateTime)
{
	Signal &sig = env.GetSignal();
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDateTime rtn = pThis->GetEntity()->GetCreateTime();
	return ReturnValue(env, args, Value(new Object_wx_DateTime(new wxDateTime(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_TarEntry, SetCreateTime)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dt", VTYPE_wx_DateTime, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarEntry, SetCreateTime)
{
	Signal &sig = env.GetSignal();
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDateTime *dt = Object_wx_DateTime::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetCreateTime(*dt);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TarEntry, GetDevMajor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TarEntry, GetDevMajor)
{
	Signal &sig = env.GetSignal();
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetDevMajor();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TarEntry, GetDevMinor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TarEntry, GetDevMinor)
{
	Signal &sig = env.GetSignal();
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetDevMinor();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TarEntry, SetDevMajor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dev", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarEntry, SetDevMajor)
{
	Signal &sig = env.GetSignal();
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int dev = args.GetInt(0);
	pThis->GetEntity()->SetDevMajor(dev);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TarEntry, SetDevMinor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dev", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarEntry, SetDevMinor)
{
	Signal &sig = env.GetSignal();
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int dev = args.GetInt(0);
	pThis->GetEntity()->SetDevMinor(dev);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TarEntry, GetGroupId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TarEntry, GetGroupId)
{
	Signal &sig = env.GetSignal();
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetGroupId();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TarEntry, GetUserId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TarEntry, GetUserId)
{
	Signal &sig = env.GetSignal();
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetUserId();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TarEntry, SetGroupId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarEntry, SetGroupId)
{
	Signal &sig = env.GetSignal();
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int id = args.GetInt(0);
	pThis->GetEntity()->SetGroupId(id);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TarEntry, SetUserId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarEntry, SetUserId)
{
	Signal &sig = env.GetSignal();
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int id = args.GetInt(0);
	pThis->GetEntity()->SetUserId(id);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TarEntry, GetGroupName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TarEntry, GetGroupName)
{
	Signal &sig = env.GetSignal();
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetGroupName();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethodAlias(wx_TarEntry, GetUserName_, "GetUserName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TarEntry, GetUserName_)
{
	Signal &sig = env.GetSignal();
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetUserName();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_TarEntry, SetGroupName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "group", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarEntry, SetGroupName)
{
	Signal &sig = env.GetSignal();
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString group = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetGroupName(group);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TarEntry, SetUserName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "user", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarEntry, SetUserName)
{
	Signal &sig = env.GetSignal();
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString user = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetUserName(user);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TarEntry, GetInternalName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TarEntry, GetInternalName)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetInternalName();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TarEntry, GetInternalName_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pIsDir", VTYPE_boolean, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TarEntry, GetInternalName_1)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(args.GetString(0));
	wxPathFormat format = wxPATH_NATIVE;
	if (args.IsValid(1)) format = static_cast<wxPathFormat>(args.GetInt(1));
	bool pIsDir = nullptr;
	if (args.IsValid(2)) pIsDir = args.GetBoolean(2);
	wxString rtn = pThis->GetEntity()->GetInternalName(name, format, pIsDir);
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TarEntry, GetLinkName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TarEntry, GetLinkName)
{
	Signal &sig = env.GetSignal();
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetLinkName();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_TarEntry, SetLinkName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "link", VTYPE_string, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_TarEntry, SetLinkName)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString link = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetLinkName(link);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TarEntry, GetMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TarEntry, GetMode)
{
	Signal &sig = env.GetSignal();
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetMode();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethodAlias(wx_TarEntry, SetMode_, "SetMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarEntry, SetMode_)
{
	Signal &sig = env.GetSignal();
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int mode = args.GetInt(0);
	pThis->GetEntity()->SetMode(mode);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TarEntry, SetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarEntry, SetSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFileOffset size = static_cast<wxFileOffset>(args.GetInt64(0));
	pThis->GetEntity()->SetSize(size);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TarEntry, GetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TarEntry, GetSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFileOffset rtn = pThis->GetEntity()->GetSize();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TarEntry, GetTypeFlag)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TarEntry, GetTypeFlag)
{
	Signal &sig = env.GetSignal();
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetTypeFlag();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TarEntry, SetTypeFlag)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarEntry, SetTypeFlag)
{
	Signal &sig = env.GetSignal();
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int type = args.GetInt(0);
	pThis->GetEntity()->SetTypeFlag(type);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxTarEntry
//----------------------------------------------------------------------------
Object_wx_TarEntry::~Object_wx_TarEntry()
{
}

Object *Object_wx_TarEntry::Clone() const
{
	return nullptr;
}

String Object_wx_TarEntry::ToString(bool exprFlag)
{
	String rtn("<wx.TarEntry:");
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
// Class implementation for wxTarEntry
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TarEntry)
{
	Gura_AssignFunction(TarEntry);
	Gura_AssignFunction(TarEntry_1);
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
	Gura_AssignMethod(wx_TarEntry, GetUserName_);
	Gura_AssignMethod(wx_TarEntry, SetGroupName);
	Gura_AssignMethod(wx_TarEntry, SetUserName);
	Gura_AssignMethod(wx_TarEntry, GetInternalName);
	Gura_AssignMethod(wx_TarEntry, GetInternalName_1);
	Gura_AssignMethod(wx_TarEntry, GetLinkName);
	Gura_AssignMethod(wx_TarEntry, SetLinkName);
	Gura_AssignMethod(wx_TarEntry, GetMode);
	Gura_AssignMethod(wx_TarEntry, SetMode_);
	Gura_AssignMethod(wx_TarEntry, SetSize);
	Gura_AssignMethod(wx_TarEntry, GetSize);
	Gura_AssignMethod(wx_TarEntry, GetTypeFlag);
	Gura_AssignMethod(wx_TarEntry, SetTypeFlag);
}

Gura_ImplementDescendantCreator(wx_TarEntry)
{
	return new Object_wx_TarEntry((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
