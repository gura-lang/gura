//----------------------------------------------------------------------------
// wxZipEntry
// extracted from zipstrm.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ZipEntry: public wxZipEntry, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_ZipEntry *_pObj;
public:
	inline wx_ZipEntry(const wxString& name, const wxDateTime& dt, off_t size) : wxZipEntry(name, dt, size), _sig(NULL), _pObj(NULL) {}
	inline wx_ZipEntry(const wxZipEntry& entry) : wxZipEntry(entry), _sig(NULL), _pObj(NULL) {}
	~wx_ZipEntry();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ZipEntry *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ZipEntry::~wx_ZipEntry()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_ZipEntry::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxZipEntry
//----------------------------------------------------------------------------
Gura_DeclareFunction(ZipEntry)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_ZipEntry));
	DeclareArg(env, "name", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "dt", VTYPE_wx_DateTime, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ZipEntry)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString name = wxEmptyString;
	if (args.IsValid(0)) name = wxString::FromUTF8(args.GetString(0));
	wxDateTime dt = wxDateTime::Now();
	if (args.IsValid(1)) dt = *Object_wx_DateTime::GetObject(args, 1)->GetEntity();
	off_t size = wxInvalidOffset;
	if (args.IsValid(2)) size = static_cast<off_t>(args.GetLong(2));
	wx_ZipEntry *pEntity = new wx_ZipEntry(name, dt, size);
	Object_wx_ZipEntry *pObj = Object_wx_ZipEntry::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_ZipEntry(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(ZipEntry_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_ZipEntry));
	DeclareArg(env, "entry", VTYPE_wx_ZipEntry, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ZipEntry_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxZipEntry *entry = Object_wx_ZipEntry::GetObject(args, 0)->GetEntity();
	wx_ZipEntry *pEntity = new wx_ZipEntry(*entry);
	Object_wx_ZipEntry *pObj = Object_wx_ZipEntry::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_ZipEntry(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_ZipEntry, Clone)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ZipEntry, Clone)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxZipEntry *rtn = (wxZipEntry *)pThis->GetEntity()->Clone();
	return ReturnValue(env, sig, args, Value(new Object_wx_ZipEntry(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_ZipEntry, GetComment)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ZipEntry, GetComment)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetComment();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_ZipEntry, SetComment)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "comment", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_ZipEntry, SetComment)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString comment = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetComment(comment);
	return Value::Null;
}

Gura_DeclareMethod(wx_ZipEntry, GetCompressedSize)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ZipEntry, GetCompressedSize)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	off_t rtn = pThis->GetEntity()->GetCompressedSize();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ZipEntry, GetCrc)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ZipEntry, GetCrc)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxUint32 rtn = pThis->GetEntity()->GetCrc();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ZipEntry, GetExternalAttributes)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ZipEntry, GetExternalAttributes)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxUint32 rtn = pThis->GetEntity()->GetExternalAttributes();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ZipEntry, SetExternalAttributes)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ZipEntry, SetExternalAttributes)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxUint32 attr = static_cast<wxUint32>(args.GetULong(0));
	pThis->GetEntity()->SetExternalAttributes(attr);
	return Value::Null;
}

Gura_DeclareMethod(wx_ZipEntry, GetExtra)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ZipEntry, GetExtra)
{
#if 0
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	char rtn = pThis->GetEntity()->GetExtra();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_ZipEntry, GetExtraLen)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ZipEntry, GetExtraLen)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t rtn = pThis->GetEntity()->GetExtraLen();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ZipEntry, SetExtra)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "extra", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_ZipEntry, SetExtra)
{
#if 0
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	char extra = args.GetChar(0);
	size_t len = args.GetSizeT(1);
	pThis->GetEntity()->SetExtra(extra, len);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_ZipEntry, GetFlags)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ZipEntry, GetFlags)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetFlags();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ZipEntry, GetInternalName)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ZipEntry, GetInternalName)
{
#if 0
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetInternalName();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_ZipEntry, GetInternalName_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "pIsDir", VTYPE_boolean, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ZipEntry, GetInternalName_1)
{
#if 0
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	wxPathFormat format = wxPATH_NATIVE;
	if (args.IsValid(1)) format = static_cast<wxPathFormat>(args.GetInt(1));
	bool pIsDir = NULL;
	if (args.IsValid(2)) pIsDir = args.GetBoolean(2);
	wxString rtn = pThis->GetEntity()->GetInternalName(name, format, pIsDir);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_ZipEntry, GetLocalExtra)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ZipEntry, GetLocalExtra)
{
#if 0
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	char rtn = pThis->GetEntity()->GetLocalExtra();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_ZipEntry, GetLocalExtraLen)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ZipEntry, GetLocalExtraLen)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t rtn = pThis->GetEntity()->GetLocalExtraLen();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ZipEntry, SetLocalExtra)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "extra", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_ZipEntry, SetLocalExtra)
{
#if 0
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	char extra = args.GetChar(0);
	size_t len = args.GetSizeT(1);
	pThis->GetEntity()->SetLocalExtra(extra, len);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_ZipEntry, GetMethod)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ZipEntry, GetMethod)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetMethod();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ZipEntry, SetMethod)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "method", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ZipEntry, SetMethod)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int method = args.GetInt(0);
	pThis->GetEntity()->SetMethod(method);
	return Value::Null;
}

Gura_DeclareMethod(wx_ZipEntry, GetMode)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ZipEntry, GetMode)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetMode();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ZipEntry, SetMode_)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ZipEntry, SetMode_)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int mode = args.GetInt(0);
	pThis->GetEntity()->SetMode(mode);
	return Value::Null;
}

Gura_DeclareMethod(wx_ZipEntry, SetNotifier)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "notifier", VTYPE_wx_ZipNotifier, OCCUR_Once);
}

Gura_ImplementMethod(wx_ZipEntry, SetNotifier)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxZipNotifier *notifier = Object_wx_ZipNotifier::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetNotifier(*notifier);
	return Value::Null;
}

Gura_DeclareMethod(wx_ZipEntry, UnsetNotifier)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ZipEntry, UnsetNotifier)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->UnsetNotifier();
	return Value::Null;
}

Gura_DeclareMethod(wx_ZipEntry, GetSystemMadeBy)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ZipEntry, GetSystemMadeBy)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetSystemMadeBy();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ZipEntry, SetSystemMadeBy)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "system", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ZipEntry, SetSystemMadeBy)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int system = args.GetInt(0);
	pThis->GetEntity()->SetSystemMadeBy(system);
	return Value::Null;
}

Gura_DeclareMethod(wx_ZipEntry, IsMadeByUnix)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ZipEntry, IsMadeByUnix)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsMadeByUnix();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ZipEntry, IsText)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ZipEntry, IsText)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsText();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ZipEntry, SetIsText)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "isText", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ZipEntry, SetIsText)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool isText = true;
	if (args.IsValid(0)) isText = args.GetBoolean(0);
	pThis->GetEntity()->SetIsText(isText);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxZipEntry
//----------------------------------------------------------------------------
Object_wx_ZipEntry::~Object_wx_ZipEntry()
{
}

Object *Object_wx_ZipEntry::Clone() const
{
	return NULL;
}

String Object_wx_ZipEntry::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.ZipEntry:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_ZipEntry::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(ZipEntry);
	Gura_AssignFunction(ZipEntry_1);
}

//----------------------------------------------------------------------------
// Class implementation for wxZipEntry
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ZipEntry)
{
	Gura_AssignMethod(wx_ZipEntry, Clone);
	Gura_AssignMethod(wx_ZipEntry, GetComment);
	Gura_AssignMethod(wx_ZipEntry, SetComment);
	Gura_AssignMethod(wx_ZipEntry, GetCompressedSize);
	Gura_AssignMethod(wx_ZipEntry, GetCrc);
	Gura_AssignMethod(wx_ZipEntry, GetExternalAttributes);
	Gura_AssignMethod(wx_ZipEntry, SetExternalAttributes);
	Gura_AssignMethod(wx_ZipEntry, GetExtra);
	Gura_AssignMethod(wx_ZipEntry, GetExtraLen);
	Gura_AssignMethod(wx_ZipEntry, SetExtra);
	Gura_AssignMethod(wx_ZipEntry, GetFlags);
	Gura_AssignMethod(wx_ZipEntry, GetInternalName);
	Gura_AssignMethod(wx_ZipEntry, GetInternalName_1);
	Gura_AssignMethod(wx_ZipEntry, GetLocalExtra);
	Gura_AssignMethod(wx_ZipEntry, GetLocalExtraLen);
	Gura_AssignMethod(wx_ZipEntry, SetLocalExtra);
	Gura_AssignMethod(wx_ZipEntry, GetMethod);
	Gura_AssignMethod(wx_ZipEntry, SetMethod);
	Gura_AssignMethod(wx_ZipEntry, GetMode);
	Gura_AssignMethodEx(wx_ZipEntry, SetMode_, "SetMode");
	Gura_AssignMethod(wx_ZipEntry, SetNotifier);
	Gura_AssignMethod(wx_ZipEntry, UnsetNotifier);
	Gura_AssignMethod(wx_ZipEntry, GetSystemMadeBy);
	Gura_AssignMethod(wx_ZipEntry, SetSystemMadeBy);
	Gura_AssignMethod(wx_ZipEntry, IsMadeByUnix);
	Gura_AssignMethod(wx_ZipEntry, IsText);
	Gura_AssignMethod(wx_ZipEntry, SetIsText);
}

Gura_ImplementDescendantCreator(wx_ZipEntry)
{
	return new Object_wx_ZipEntry((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
