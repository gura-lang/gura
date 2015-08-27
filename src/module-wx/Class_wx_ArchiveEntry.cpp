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
	//Gura::Signal *_pSig;
	Object_wx_ArchiveEntry *_pObj;
public:
	~wx_ArchiveEntry();
	inline void AssocWithGura(Object_wx_ArchiveEntry *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ArchiveEntry::~wx_ArchiveEntry()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_ArchiveEntry::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxArchiveEntry
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_ArchiveEntry, Clone)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ArchiveEntry, Clone)
{
	Signal &sig = env.GetSignal();
	Object_wx_ArchiveEntry *pThis = Object_wx_ArchiveEntry::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxArchiveEntry *rtn = (wxArchiveEntry *)pThis->GetEntity()->Clone();
	return ReturnValue(env, args, Value(new Object_wx_ArchiveEntry(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_ArchiveEntry, GetDateTime)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ArchiveEntry, GetDateTime)
{
	Signal &sig = env.GetSignal();
	Object_wx_ArchiveEntry *pThis = Object_wx_ArchiveEntry::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDateTime rtn = pThis->GetEntity()->GetDateTime();
	return ReturnValue(env, args, Value(new Object_wx_DateTime(new wxDateTime(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_ArchiveEntry, SetDateTime)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dt", VTYPE_wx_DateTime, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArchiveEntry, SetDateTime)
{
	Signal &sig = env.GetSignal();
	Object_wx_ArchiveEntry *pThis = Object_wx_ArchiveEntry::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDateTime *dt = Object_wx_DateTime::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetDateTime(*dt);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArchiveEntry, GetInternalFormat)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ArchiveEntry, GetInternalFormat)
{
	Signal &sig = env.GetSignal();
	Object_wx_ArchiveEntry *pThis = Object_wx_ArchiveEntry::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPathFormat rtn = pThis->GetEntity()->GetInternalFormat();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ArchiveEntry, GetInternalName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ArchiveEntry, GetInternalName)
{
	Signal &sig = env.GetSignal();
	Object_wx_ArchiveEntry *pThis = Object_wx_ArchiveEntry::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetInternalName();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_ArchiveEntry, GetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ArchiveEntry, GetName)
{
	Signal &sig = env.GetSignal();
	Object_wx_ArchiveEntry *pThis = Object_wx_ArchiveEntry::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPathFormat format = wxPATH_NATIVE;
	if (args.IsValid(0)) format = static_cast<wxPathFormat>(args.GetInt(0));
	wxString rtn = pThis->GetEntity()->GetName(format);
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_ArchiveEntry, SetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ArchiveEntry, SetName)
{
	Signal &sig = env.GetSignal();
	Object_wx_ArchiveEntry *pThis = Object_wx_ArchiveEntry::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(args.GetString(0));
	wxPathFormat format = wxPATH_NATIVE;
	if (args.IsValid(1)) format = static_cast<wxPathFormat>(args.GetInt(1));
	pThis->GetEntity()->SetName(name, format);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArchiveEntry, GetOffset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ArchiveEntry, GetOffset)
{
	Signal &sig = env.GetSignal();
	Object_wx_ArchiveEntry *pThis = Object_wx_ArchiveEntry::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	off_t rtn = pThis->GetEntity()->GetOffset();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ArchiveEntry, GetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ArchiveEntry, GetSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_ArchiveEntry *pThis = Object_wx_ArchiveEntry::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	off_t rtn = pThis->GetEntity()->GetSize();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ArchiveEntry, SetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArchiveEntry, SetSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_ArchiveEntry *pThis = Object_wx_ArchiveEntry::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	off_t size = static_cast<off_t>(args.GetLong(0));
	pThis->GetEntity()->SetSize(size);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArchiveEntry, IsDir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ArchiveEntry, IsDir)
{
	Signal &sig = env.GetSignal();
	Object_wx_ArchiveEntry *pThis = Object_wx_ArchiveEntry::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsDir();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ArchiveEntry, SetIsDir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "isDir", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ArchiveEntry, SetIsDir)
{
	Signal &sig = env.GetSignal();
	Object_wx_ArchiveEntry *pThis = Object_wx_ArchiveEntry::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool isDir = true;
	if (args.IsValid(0)) isDir = args.GetBoolean(0);
	pThis->GetEntity()->SetIsDir(isDir);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArchiveEntry, IsReadOnly)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ArchiveEntry, IsReadOnly)
{
	Signal &sig = env.GetSignal();
	Object_wx_ArchiveEntry *pThis = Object_wx_ArchiveEntry::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsReadOnly();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ArchiveEntry, SetIsReadOnly)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "isReadOnly", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ArchiveEntry, SetIsReadOnly)
{
	Signal &sig = env.GetSignal();
	Object_wx_ArchiveEntry *pThis = Object_wx_ArchiveEntry::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool isReadOnly = true;
	if (args.IsValid(0)) isReadOnly = args.GetBoolean(0);
	pThis->GetEntity()->SetIsReadOnly(isReadOnly);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArchiveEntry, SetNotifier)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "notifier", VTYPE_wx_ArchiveNotifier, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArchiveEntry, SetNotifier)
{
	Signal &sig = env.GetSignal();
	Object_wx_ArchiveEntry *pThis = Object_wx_ArchiveEntry::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxArchiveNotifier *notifier = Object_wx_ArchiveNotifier::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetNotifier(*notifier);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArchiveEntry, UnsetNotifier)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ArchiveEntry, UnsetNotifier)
{
	Signal &sig = env.GetSignal();
	Object_wx_ArchiveEntry *pThis = Object_wx_ArchiveEntry::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->UnsetNotifier();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxArchiveEntry
//----------------------------------------------------------------------------
Object_wx_ArchiveEntry::~Object_wx_ArchiveEntry()
{
}

Object *Object_wx_ArchiveEntry::Clone() const
{
	return nullptr;
}

String Object_wx_ArchiveEntry::ToString(bool exprFlag)
{
	String rtn("<wx.ArchiveEntry:");
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
	return new Object_wx_ArchiveEntry((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
