//----------------------------------------------------------------------------
// wxZipOutputStream
// extracted from zipstrm.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ZipOutputStream: public wxZipOutputStream, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_ZipOutputStream *_pObj;
public:
	inline wx_ZipOutputStream(wxOutputStream& stream, int level, wxMBConv& conv) : wxZipOutputStream(stream, level, conv), _sig(NULL), _pObj(NULL) {}
	inline wx_ZipOutputStream(wxOutputStream* stream, int level, wxMBConv& conv) : wxZipOutputStream(stream, level, conv), _sig(NULL), _pObj(NULL) {}
	~wx_ZipOutputStream();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ZipOutputStream *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ZipOutputStream::~wx_ZipOutputStream()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_ZipOutputStream::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxZipOutputStream
//----------------------------------------------------------------------------
Gura_DeclareFunction(ZipOutputStream)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_ZipOutputStream));
	DeclareArg(env, "stream", VTYPE_wx_OutputStream, OCCUR_Once);
	DeclareArg(env, "level", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "conv", VTYPE_wx_MBConv, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ZipOutputStream)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxOutputStream *stream = Object_wx_OutputStream::GetObject(args, 0)->GetEntity();
	int level = -1;
	if (args.IsValid(1)) level = args.GetInt(1);
	wxMBConv *conv = (wxMBConv *)(&wxConvLocal);
	if (args.IsValid(2)) conv = Object_wx_MBConv::GetObject(args, 2)->GetEntity();
	wx_ZipOutputStream *pEntity = new wx_ZipOutputStream(*stream, level, *conv);
	Object_wx_ZipOutputStream *pObj = Object_wx_ZipOutputStream::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_ZipOutputStream(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareFunction(ZipOutputStream_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_ZipOutputStream));
	DeclareArg(env, "stream", VTYPE_wx_OutputStream, OCCUR_Once);
	DeclareArg(env, "level", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "conv", VTYPE_wx_MBConv, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ZipOutputStream_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxOutputStream *stream = Object_wx_OutputStream::GetObject(args, 0)->GetEntity();
	int level = -1;
	if (args.IsValid(1)) level = args.GetInt(1);
	wxMBConv *conv = (wxMBConv *)(&wxConvLocal);
	if (args.IsValid(2)) conv = Object_wx_MBConv::GetObject(args, 2)->GetEntity();
	wx_ZipOutputStream *pEntity = new wx_ZipOutputStream(stream, level, *conv);
	Object_wx_ZipOutputStream *pObj = Object_wx_ZipOutputStream::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_ZipOutputStream(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_ZipOutputStream, Close)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ZipOutputStream, Close)
{
	Object_wx_ZipOutputStream *pSelf = Object_wx_ZipOutputStream::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->Close();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ZipOutputStream, CloseEntry)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ZipOutputStream, CloseEntry)
{
	Object_wx_ZipOutputStream *pSelf = Object_wx_ZipOutputStream::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->CloseEntry();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ZipOutputStream, CopyArchiveMetaData)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "inputStream", VTYPE_wx_ZipInputStream, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ZipOutputStream, CopyArchiveMetaData)
{
	Object_wx_ZipOutputStream *pSelf = Object_wx_ZipOutputStream::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxZipInputStream *inputStream = Object_wx_ZipInputStream::GetObject(args, 0)->GetEntity();
	bool rtn = pSelf->GetEntity()->CopyArchiveMetaData(*inputStream);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ZipOutputStream, CopyEntry)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "entry", VTYPE_wx_ZipEntry, OCCUR_Once);
	DeclareArg(env, "inputStream", VTYPE_wx_ZipInputStream, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ZipOutputStream, CopyEntry)
{
	Object_wx_ZipOutputStream *pSelf = Object_wx_ZipOutputStream::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxZipEntry *entry = Object_wx_ZipEntry::GetObject(args, 0)->GetEntity();
	wxZipInputStream *inputStream = Object_wx_ZipInputStream::GetObject(args, 1)->GetEntity();
	bool rtn = pSelf->GetEntity()->CopyEntry(entry, *inputStream);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ZipOutputStream, GetLevel)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ZipOutputStream, GetLevel)
{
	Object_wx_ZipOutputStream *pSelf = Object_wx_ZipOutputStream::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetLevel();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ZipOutputStream, SetLevel)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ZipOutputStream, SetLevel)
{
	Object_wx_ZipOutputStream *pSelf = Object_wx_ZipOutputStream::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int level = args.GetInt(0);
	pSelf->GetEntity()->SetLevel(level);
	return Value::Null;
}

Gura_DeclareMethod(wx_ZipOutputStream, PutNextDirEntry)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "dt", VTYPE_wx_DateTime, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ZipOutputStream, PutNextDirEntry)
{
	Object_wx_ZipOutputStream *pSelf = Object_wx_ZipOutputStream::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	wxDateTime dt = wxDateTime::Now();
	if (args.IsValid(1)) dt = *Object_wx_DateTime::GetObject(args, 1)->GetEntity();
	bool rtn = pSelf->GetEntity()->PutNextDirEntry(name, dt);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ZipOutputStream, PutNextEntry)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "entry", VTYPE_wx_ZipEntry, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ZipOutputStream, PutNextEntry)
{
	Object_wx_ZipOutputStream *pSelf = Object_wx_ZipOutputStream::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxZipEntry *entry = Object_wx_ZipEntry::GetObject(args, 0)->GetEntity();
	bool rtn = pSelf->GetEntity()->PutNextEntry(entry);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ZipOutputStream, PutNextEntry_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "dt", VTYPE_wx_DateTime, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ZipOutputStream, PutNextEntry_1)
{
	Object_wx_ZipOutputStream *pSelf = Object_wx_ZipOutputStream::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	wxDateTime dt = wxDateTime::Now();
	if (args.IsValid(1)) dt = *Object_wx_DateTime::GetObject(args, 1)->GetEntity();
	off_t size = wxInvalidOffset;
	if (args.IsValid(2)) size = static_cast<off_t>(args.GetLong(2));
	bool rtn = pSelf->GetEntity()->PutNextEntry(name, dt, size);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ZipOutputStream, SetComment)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "comment", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_ZipOutputStream, SetComment)
{
	Object_wx_ZipOutputStream *pSelf = Object_wx_ZipOutputStream::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString comment = wxString::FromUTF8(args.GetString(0));
	pSelf->GetEntity()->SetComment(comment);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxZipOutputStream
//----------------------------------------------------------------------------
Object_wx_ZipOutputStream::~Object_wx_ZipOutputStream()
{
}

Object *Object_wx_ZipOutputStream::Clone() const
{
	return NULL;
}

String Object_wx_ZipOutputStream::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.ZipOutputStream:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_ZipOutputStream::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(ZipOutputStream);
	Gura_AssignFunction(ZipOutputStream_1);
}

//----------------------------------------------------------------------------
// Class implementation for wxZipOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ZipOutputStream)
{
	Gura_AssignMethod(wx_ZipOutputStream, Close);
	Gura_AssignMethod(wx_ZipOutputStream, CloseEntry);
	Gura_AssignMethod(wx_ZipOutputStream, CopyArchiveMetaData);
	Gura_AssignMethod(wx_ZipOutputStream, CopyEntry);
	Gura_AssignMethod(wx_ZipOutputStream, GetLevel);
	Gura_AssignMethod(wx_ZipOutputStream, SetLevel);
	Gura_AssignMethod(wx_ZipOutputStream, PutNextDirEntry);
	Gura_AssignMethod(wx_ZipOutputStream, PutNextEntry);
	Gura_AssignMethod(wx_ZipOutputStream, PutNextEntry_1);
	Gura_AssignMethod(wx_ZipOutputStream, SetComment);
}

Gura_ImplementDescendantCreator(wx_ZipOutputStream)
{
	return new Object_wx_ZipOutputStream((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
