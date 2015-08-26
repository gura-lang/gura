//----------------------------------------------------------------------------
// wxZipOutputStream
// extracted from zipstrm.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ZipOutputStream: public wxZipOutputStream, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_ZipOutputStream *_pObj;
public:
	inline wx_ZipOutputStream(wxOutputStream& stream, int level, wxMBConv& conv) : wxZipOutputStream(stream, level, conv), _pObj(nullptr) {}
	inline wx_ZipOutputStream(wxOutputStream* stream, int level, wxMBConv& conv) : wxZipOutputStream(stream, level, conv), _pObj(nullptr) {}
	~wx_ZipOutputStream();
	inline void AssocWithGura(Object_wx_ZipOutputStream *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ZipOutputStream::~wx_ZipOutputStream()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_ZipOutputStream::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxZipOutputStream
//----------------------------------------------------------------------------
Gura_DeclareFunction(ZipOutputStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_ZipOutputStream));
	DeclareArg(env, "stream", VTYPE_wx_OutputStream, OCCUR_Once);
	DeclareArg(env, "level", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "conv", VTYPE_wx_MBConv, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ZipOutputStream)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxOutputStream *stream = Object_wx_OutputStream::GetObject(args, 0)->GetEntity();
	int level = -1;
	if (args.IsValid(1)) level = args.GetInt(1);
	wxMBConv *conv = (wxMBConv *)(&wxConvLocal);
	if (args.IsValid(2)) conv = Object_wx_MBConv::GetObject(args, 2)->GetEntity();
	wx_ZipOutputStream *pEntity = new wx_ZipOutputStream(*stream, level, *conv);
	Object_wx_ZipOutputStream *pObj = Object_wx_ZipOutputStream::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_ZipOutputStream(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareFunction(ZipOutputStream_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_ZipOutputStream));
	DeclareArg(env, "stream", VTYPE_wx_OutputStream, OCCUR_Once);
	DeclareArg(env, "level", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "conv", VTYPE_wx_MBConv, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ZipOutputStream_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxOutputStream *stream = Object_wx_OutputStream::GetObject(args, 0)->GetEntity();
	int level = -1;
	if (args.IsValid(1)) level = args.GetInt(1);
	wxMBConv *conv = (wxMBConv *)(&wxConvLocal);
	if (args.IsValid(2)) conv = Object_wx_MBConv::GetObject(args, 2)->GetEntity();
	wx_ZipOutputStream *pEntity = new wx_ZipOutputStream(stream, level, *conv);
	Object_wx_ZipOutputStream *pObj = Object_wx_ZipOutputStream::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_ZipOutputStream(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareMethod(wx_ZipOutputStream, Close)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ZipOutputStream, Close)
{
	Signal &sig = env.GetSignal();
	Object_wx_ZipOutputStream *pThis = Object_wx_ZipOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->Close();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ZipOutputStream, CloseEntry)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ZipOutputStream, CloseEntry)
{
	Signal &sig = env.GetSignal();
	Object_wx_ZipOutputStream *pThis = Object_wx_ZipOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->CloseEntry();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ZipOutputStream, CopyArchiveMetaData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "inputStream", VTYPE_wx_ZipInputStream, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ZipOutputStream, CopyArchiveMetaData)
{
	Signal &sig = env.GetSignal();
	Object_wx_ZipOutputStream *pThis = Object_wx_ZipOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxZipInputStream *inputStream = Object_wx_ZipInputStream::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->CopyArchiveMetaData(*inputStream);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ZipOutputStream, CopyEntry)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "entry", VTYPE_wx_ZipEntry, OCCUR_Once);
	DeclareArg(env, "inputStream", VTYPE_wx_ZipInputStream, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ZipOutputStream, CopyEntry)
{
	Signal &sig = env.GetSignal();
	Object_wx_ZipOutputStream *pThis = Object_wx_ZipOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxZipEntry *entry = Object_wx_ZipEntry::GetObject(args, 0)->GetEntity();
	wxZipInputStream *inputStream = Object_wx_ZipInputStream::GetObject(args, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->CopyEntry(entry, *inputStream);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ZipOutputStream, GetLevel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ZipOutputStream, GetLevel)
{
	Signal &sig = env.GetSignal();
	Object_wx_ZipOutputStream *pThis = Object_wx_ZipOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetLevel();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ZipOutputStream, SetLevel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ZipOutputStream, SetLevel)
{
	Signal &sig = env.GetSignal();
	Object_wx_ZipOutputStream *pThis = Object_wx_ZipOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int level = args.GetInt(0);
	pThis->GetEntity()->SetLevel(level);
	return Value::Nil;
}

Gura_DeclareMethod(wx_ZipOutputStream, PutNextDirEntry)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "dt", VTYPE_wx_DateTime, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ZipOutputStream, PutNextDirEntry)
{
	Signal &sig = env.GetSignal();
	Object_wx_ZipOutputStream *pThis = Object_wx_ZipOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(args.GetString(0));
	wxDateTime dt = wxDateTime::Now();
	if (args.IsValid(1)) dt = *Object_wx_DateTime::GetObject(args, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->PutNextDirEntry(name, dt);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ZipOutputStream, PutNextEntry)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "entry", VTYPE_wx_ZipEntry, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ZipOutputStream, PutNextEntry)
{
	Signal &sig = env.GetSignal();
	Object_wx_ZipOutputStream *pThis = Object_wx_ZipOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxZipEntry *entry = Object_wx_ZipEntry::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->PutNextEntry(entry);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ZipOutputStream, PutNextEntry_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "dt", VTYPE_wx_DateTime, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ZipOutputStream, PutNextEntry_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_ZipOutputStream *pThis = Object_wx_ZipOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(args.GetString(0));
	wxDateTime dt = wxDateTime::Now();
	if (args.IsValid(1)) dt = *Object_wx_DateTime::GetObject(args, 1)->GetEntity();
	off_t size = wxInvalidOffset;
	if (args.IsValid(2)) size = static_cast<off_t>(args.GetLong(2));
	bool rtn = pThis->GetEntity()->PutNextEntry(name, dt, size);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ZipOutputStream, SetComment)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "comment", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_ZipOutputStream, SetComment)
{
	Signal &sig = env.GetSignal();
	Object_wx_ZipOutputStream *pThis = Object_wx_ZipOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString comment = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetComment(comment);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxZipOutputStream
//----------------------------------------------------------------------------
Object_wx_ZipOutputStream::~Object_wx_ZipOutputStream()
{
}

Object *Object_wx_ZipOutputStream::Clone() const
{
	return nullptr;
}

String Object_wx_ZipOutputStream::ToString(bool exprFlag)
{
	String rtn("<wx.ZipOutputStream:");
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
// Class implementation for wxZipOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ZipOutputStream)
{
	Gura_AssignFunction(ZipOutputStream);
	Gura_AssignFunction(ZipOutputStream_1);
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
	return new Object_wx_ZipOutputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
