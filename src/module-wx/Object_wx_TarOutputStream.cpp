//----------------------------------------------------------------------------
// wxTarOutputStream
// extracted from tarstrm.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_TarOutputStream: public wxTarOutputStream, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_TarOutputStream *_pObj;
public:
	inline wx_TarOutputStream(wxOutputStream& stream, wxTarFormat format, wxMBConv& conv) : wxTarOutputStream(stream, format, conv), _sig(NULL), _pObj(NULL) {}
	inline wx_TarOutputStream(wxOutputStream* stream, wxTarFormat format, wxMBConv& conv) : wxTarOutputStream(stream, format, conv), _sig(NULL), _pObj(NULL) {}
	~wx_TarOutputStream();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_TarOutputStream *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_TarOutputStream::~wx_TarOutputStream()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_TarOutputStream::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxTarOutputStream
//----------------------------------------------------------------------------
Gura_DeclareFunction(TarOutputStream)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_TarOutputStream));
	DeclareArg(env, "stream", VTYPE_wx_OutputStream, OCCUR_Once);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "conv", VTYPE_wx_MBConv, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(TarOutputStream)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxOutputStream *stream = Object_wx_OutputStream::GetObject(args, 0)->GetEntity();
	wxTarFormat format = wxTAR_PAX;
	if (args.IsValid(1)) format = static_cast<wxTarFormat>(args.GetInt(1));
	wxMBConv *conv = (wxMBConv *)(&wxConvLocal);
	if (args.IsValid(2)) conv = Object_wx_MBConv::GetObject(args, 2)->GetEntity();
	wx_TarOutputStream *pEntity = new wx_TarOutputStream(*stream, format, *conv);
	Object_wx_TarOutputStream *pObj = Object_wx_TarOutputStream::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_TarOutputStream(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(TarOutputStream_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_TarOutputStream));
	DeclareArg(env, "stream", VTYPE_wx_OutputStream, OCCUR_Once);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "conv", VTYPE_wx_MBConv, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(TarOutputStream_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxOutputStream *stream = Object_wx_OutputStream::GetObject(args, 0)->GetEntity();
	wxTarFormat format = wxTAR_PAX;
	if (args.IsValid(1)) format = static_cast<wxTarFormat>(args.GetInt(1));
	wxMBConv *conv = (wxMBConv *)(&wxConvLocal);
	if (args.IsValid(2)) conv = Object_wx_MBConv::GetObject(args, 2)->GetEntity();
	wx_TarOutputStream *pEntity = new wx_TarOutputStream(stream, format, *conv);
	Object_wx_TarOutputStream *pObj = Object_wx_TarOutputStream::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_TarOutputStream(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_TarOutputStream, Close)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TarOutputStream, Close)
{
	Object_wx_TarOutputStream *pThis = Object_wx_TarOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->Close();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TarOutputStream, CloseEntry)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TarOutputStream, CloseEntry)
{
	Object_wx_TarOutputStream *pThis = Object_wx_TarOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->CloseEntry();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TarOutputStream, CopyArchiveMetaData)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "s", VTYPE_wx_TarInputStream, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TarOutputStream, CopyArchiveMetaData)
{
	Object_wx_TarOutputStream *pThis = Object_wx_TarOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTarInputStream *s = Object_wx_TarInputStream::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->CopyArchiveMetaData(*s);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TarOutputStream, CopyEntry)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "entry", VTYPE_wx_TarEntry, OCCUR_Once);
	DeclareArg(env, "inputStream", VTYPE_wx_TarInputStream, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TarOutputStream, CopyEntry)
{
	Object_wx_TarOutputStream *pThis = Object_wx_TarOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTarEntry *entry = Object_wx_TarEntry::GetObject(args, 0)->GetEntity();
	wxTarInputStream *inputStream = Object_wx_TarInputStream::GetObject(args, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->CopyEntry(entry, *inputStream);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TarOutputStream, GetBlockingFactor)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TarOutputStream, GetBlockingFactor)
{
	Object_wx_TarOutputStream *pThis = Object_wx_TarOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetBlockingFactor();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TarOutputStream, SetBlockingFactor)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "factor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarOutputStream, SetBlockingFactor)
{
	Object_wx_TarOutputStream *pThis = Object_wx_TarOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int factor = args.GetInt(0);
	pThis->GetEntity()->SetBlockingFactor(factor);
	return Value::Null;
}

Gura_DeclareMethod(wx_TarOutputStream, PutNextDirEntry)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "dt", VTYPE_wx_DateTime, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TarOutputStream, PutNextDirEntry)
{
	Object_wx_TarOutputStream *pThis = Object_wx_TarOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	wxDateTime dt = wxDateTime::Now();
	if (args.IsValid(1)) dt = *Object_wx_DateTime::GetObject(args, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->PutNextDirEntry(name, dt);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TarOutputStream, PutNextEntry)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "entry", VTYPE_wx_TarEntry, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TarOutputStream, PutNextEntry)
{
	Object_wx_TarOutputStream *pThis = Object_wx_TarOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTarEntry *entry = Object_wx_TarEntry::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->PutNextEntry(entry);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TarOutputStream, PutNextEntry_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "dt", VTYPE_wx_DateTime, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TarOutputStream, PutNextEntry_1)
{
	Object_wx_TarOutputStream *pThis = Object_wx_TarOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	wxDateTime dt = wxDateTime::Now();
	if (args.IsValid(1)) dt = *Object_wx_DateTime::GetObject(args, 1)->GetEntity();
	wxFileOffset size = wxInvalidOffset;
	if (args.IsValid(2)) size = static_cast<wxFileOffset>(args.GetInt64(2));
	bool rtn = pThis->GetEntity()->PutNextEntry(name, dt, size);
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxTarOutputStream
//----------------------------------------------------------------------------
Object_wx_TarOutputStream::~Object_wx_TarOutputStream()
{
}

Object *Object_wx_TarOutputStream::Clone() const
{
	return NULL;
}

String Object_wx_TarOutputStream::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.TarOutputStream:");
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
// Class implementation for wxTarOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TarOutputStream)
{
	Gura_AssignFunction(TarOutputStream);
	Gura_AssignFunction(TarOutputStream_1);
	Gura_AssignMethod(wx_TarOutputStream, Close);
	Gura_AssignMethod(wx_TarOutputStream, CloseEntry);
	Gura_AssignMethod(wx_TarOutputStream, CopyArchiveMetaData);
	Gura_AssignMethod(wx_TarOutputStream, CopyEntry);
	Gura_AssignMethod(wx_TarOutputStream, GetBlockingFactor);
	Gura_AssignMethod(wx_TarOutputStream, SetBlockingFactor);
	Gura_AssignMethod(wx_TarOutputStream, PutNextDirEntry);
	Gura_AssignMethod(wx_TarOutputStream, PutNextEntry);
	Gura_AssignMethod(wx_TarOutputStream, PutNextEntry_1);
}

Gura_ImplementDescendantCreator(wx_TarOutputStream)
{
	return new Object_wx_TarOutputStream((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
