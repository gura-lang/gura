//----------------------------------------------------------------------------
// wxArchiveEntry
// extracted from archive.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ArchiveEntry: public wxArchiveEntry, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_ArchiveEntry *_pObj;
public:
	~wx_ArchiveEntry();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ArchiveEntry *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ArchiveEntry::~wx_ArchiveEntry()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_ArchiveEntry::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxArchiveEntry
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_ArchiveEntry, Clone)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ArchiveEntry, Clone)
{
	Object_wx_ArchiveEntry *pThis = Object_wx_ArchiveEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxArchiveEntry *rtn = (wxArchiveEntry *)pThis->GetEntity()->Clone();
	return ReturnValue(env, sig, args, Value(new Object_wx_ArchiveEntry(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_ArchiveEntry, GetDateTime)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ArchiveEntry, GetDateTime)
{
	Object_wx_ArchiveEntry *pThis = Object_wx_ArchiveEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDateTime rtn = pThis->GetEntity()->GetDateTime();
	return ReturnValue(env, sig, args, Value(new Object_wx_DateTime(new wxDateTime(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_ArchiveEntry, SetDateTime)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dt", VTYPE_wx_DateTime, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArchiveEntry, SetDateTime)
{
	Object_wx_ArchiveEntry *pThis = Object_wx_ArchiveEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDateTime *dt = Object_wx_DateTime::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetDateTime(*dt);
	return Value::Null;
}

Gura_DeclareMethod(wx_ArchiveEntry, GetInternalFormat)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ArchiveEntry, GetInternalFormat)
{
	Object_wx_ArchiveEntry *pThis = Object_wx_ArchiveEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPathFormat rtn = pThis->GetEntity()->GetInternalFormat();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ArchiveEntry, GetInternalName)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ArchiveEntry, GetInternalName)
{
	Object_wx_ArchiveEntry *pThis = Object_wx_ArchiveEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetInternalName();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_ArchiveEntry, GetName)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ArchiveEntry, GetName)
{
	Object_wx_ArchiveEntry *pThis = Object_wx_ArchiveEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPathFormat format = wxPATH_NATIVE;
	if (args.IsValid(0)) format = static_cast<wxPathFormat>(args.GetInt(0));
	wxString rtn = pThis->GetEntity()->GetName(format);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_ArchiveEntry, SetName)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ArchiveEntry, SetName)
{
	Object_wx_ArchiveEntry *pThis = Object_wx_ArchiveEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	wxPathFormat format = wxPATH_NATIVE;
	if (args.IsValid(1)) format = static_cast<wxPathFormat>(args.GetInt(1));
	pThis->GetEntity()->SetName(name, format);
	return Value::Null;
}

Gura_DeclareMethod(wx_ArchiveEntry, GetOffset)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ArchiveEntry, GetOffset)
{
	Object_wx_ArchiveEntry *pThis = Object_wx_ArchiveEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	off_t rtn = pThis->GetEntity()->GetOffset();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ArchiveEntry, GetSize)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ArchiveEntry, GetSize)
{
	Object_wx_ArchiveEntry *pThis = Object_wx_ArchiveEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	off_t rtn = pThis->GetEntity()->GetSize();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ArchiveEntry, SetSize)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArchiveEntry, SetSize)
{
	Object_wx_ArchiveEntry *pThis = Object_wx_ArchiveEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	off_t size = static_cast<off_t>(args.GetLong(0));
	pThis->GetEntity()->SetSize(size);
	return Value::Null;
}

Gura_DeclareMethod(wx_ArchiveEntry, IsDir)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ArchiveEntry, IsDir)
{
	Object_wx_ArchiveEntry *pThis = Object_wx_ArchiveEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsDir();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ArchiveEntry, SetIsDir)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "isDir", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ArchiveEntry, SetIsDir)
{
	Object_wx_ArchiveEntry *pThis = Object_wx_ArchiveEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool isDir = true;
	if (args.IsValid(0)) isDir = args.GetBoolean(0);
	pThis->GetEntity()->SetIsDir(isDir);
	return Value::Null;
}

Gura_DeclareMethod(wx_ArchiveEntry, IsReadOnly)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ArchiveEntry, IsReadOnly)
{
	Object_wx_ArchiveEntry *pThis = Object_wx_ArchiveEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsReadOnly();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ArchiveEntry, SetIsReadOnly)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "isReadOnly", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ArchiveEntry, SetIsReadOnly)
{
	Object_wx_ArchiveEntry *pThis = Object_wx_ArchiveEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool isReadOnly = true;
	if (args.IsValid(0)) isReadOnly = args.GetBoolean(0);
	pThis->GetEntity()->SetIsReadOnly(isReadOnly);
	return Value::Null;
}

Gura_DeclareMethod(wx_ArchiveEntry, SetNotifier)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "notifier", VTYPE_wx_ArchiveNotifier, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArchiveEntry, SetNotifier)
{
	Object_wx_ArchiveEntry *pThis = Object_wx_ArchiveEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxArchiveNotifier *notifier = Object_wx_ArchiveNotifier::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetNotifier(*notifier);
	return Value::Null;
}

Gura_DeclareMethod(wx_ArchiveEntry, UnsetNotifier)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ArchiveEntry, UnsetNotifier)
{
	Object_wx_ArchiveEntry *pThis = Object_wx_ArchiveEntry::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->UnsetNotifier();
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxArchiveEntry
//----------------------------------------------------------------------------
Object_wx_ArchiveEntry::~Object_wx_ArchiveEntry()
{
}

Object *Object_wx_ArchiveEntry::Clone() const
{
	return NULL;
}

String Object_wx_ArchiveEntry::ToString(bool exprFlag)
{
	String rtn("<wx.ArchiveEntry:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

//----------------------------------------------------------------------------
// Class implementation for wxArchiveEntry
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ArchiveEntry)
{
	Gura_AssignMethod(wx_ArchiveEntry, Clone);
	Gura_AssignMethod(wx_ArchiveEntry, GetDateTime);
	Gura_AssignMethod(wx_ArchiveEntry, SetDateTime);
	Gura_AssignMethod(wx_ArchiveEntry, GetInternalFormat);
	Gura_AssignMethod(wx_ArchiveEntry, GetInternalName);
	Gura_AssignMethod(wx_ArchiveEntry, GetName);
	Gura_AssignMethod(wx_ArchiveEntry, SetName);
	Gura_AssignMethod(wx_ArchiveEntry, GetOffset);
	Gura_AssignMethod(wx_ArchiveEntry, GetSize);
	Gura_AssignMethod(wx_ArchiveEntry, SetSize);
	Gura_AssignMethod(wx_ArchiveEntry, IsDir);
	Gura_AssignMethod(wx_ArchiveEntry, SetIsDir);
	Gura_AssignMethod(wx_ArchiveEntry, IsReadOnly);
	Gura_AssignMethod(wx_ArchiveEntry, SetIsReadOnly);
	Gura_AssignMethod(wx_ArchiveEntry, SetNotifier);
	Gura_AssignMethod(wx_ArchiveEntry, UnsetNotifier);
}

Gura_ImplementDescendantCreator(wx_ArchiveEntry)
{
	return new Object_wx_ArchiveEntry((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
