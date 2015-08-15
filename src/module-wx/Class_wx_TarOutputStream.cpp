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
	//Gura::Signal *_pSig;
	Object_wx_TarOutputStream *_pObj;
public:
	inline wx_TarOutputStream(wxOutputStream& stream, wxTarFormat format, wxMBConv& conv) : wxTarOutputStream(stream, format, conv), _pObj(nullptr) {}
	inline wx_TarOutputStream(wxOutputStream* stream, wxTarFormat format, wxMBConv& conv) : wxTarOutputStream(stream, format, conv), _pObj(nullptr) {}
	~wx_TarOutputStream();
	inline void AssocWithGura(Object_wx_TarOutputStream *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_TarOutputStream::~wx_TarOutputStream()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_TarOutputStream::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxTarOutputStream
//----------------------------------------------------------------------------
Gura_DeclareFunction(TarOutputStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_TarOutputStream));
	DeclareArg(env, "stream", VTYPE_wx_OutputStream, OCCUR_Once);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "conv", VTYPE_wx_MBConv, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(TarOutputStream)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxOutputStream *stream = Object_wx_OutputStream::GetObject(args, 0)->GetEntity();
	wxTarFormat format = wxTAR_PAX;
	if (args.IsValid(1)) format = static_cast<wxTarFormat>(args.GetInt(1));
	wxMBConv *conv = (wxMBConv *)(&wxConvLocal);
	if (args.IsValid(2)) conv = Object_wx_MBConv::GetObject(args, 2)->GetEntity();
	wx_TarOutputStream *pEntity = new wx_TarOutputStream(*stream, format, *conv);
	Object_wx_TarOutputStream *pObj = Object_wx_TarOutputStream::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_TarOutputStream(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareFunction(TarOutputStream_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_TarOutputStream));
	DeclareArg(env, "stream", VTYPE_wx_OutputStream, OCCUR_Once);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "conv", VTYPE_wx_MBConv, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(TarOutputStream_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxOutputStream *stream = Object_wx_OutputStream::GetObject(args, 0)->GetEntity();
	wxTarFormat format = wxTAR_PAX;
	if (args.IsValid(1)) format = static_cast<wxTarFormat>(args.GetInt(1));
	wxMBConv *conv = (wxMBConv *)(&wxConvLocal);
	if (args.IsValid(2)) conv = Object_wx_MBConv::GetObject(args, 2)->GetEntity();
	wx_TarOutputStream *pEntity = new wx_TarOutputStream(stream, format, *conv);
	Object_wx_TarOutputStream *pObj = Object_wx_TarOutputStream::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_TarOutputStream(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_TarOutputStream, Close)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TarOutputStream, Close)
{
	Signal &sig = env.GetSignal();
	Object_wx_TarOutputStream *pThis = Object_wx_TarOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->Close();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TarOutputStream, CloseEntry)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TarOutputStream, CloseEntry)
{
	Signal &sig = env.GetSignal();
	Object_wx_TarOutputStream *pThis = Object_wx_TarOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->CloseEntry();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TarOutputStream, CopyArchiveMetaData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "s", VTYPE_wx_TarInputStream, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TarOutputStream, CopyArchiveMetaData)
{
	Signal &sig = env.GetSignal();
	Object_wx_TarOutputStream *pThis = Object_wx_TarOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxTarInputStream *s = Object_wx_TarInputStream::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->CopyArchiveMetaData(*s);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TarOutputStream, CopyEntry)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "entry", VTYPE_wx_TarEntry, OCCUR_Once);
	DeclareArg(env, "inputStream", VTYPE_wx_TarInputStream, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TarOutputStream, CopyEntry)
{
	Signal &sig = env.GetSignal();
	Object_wx_TarOutputStream *pThis = Object_wx_TarOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxTarEntry *entry = Object_wx_TarEntry::GetObject(args, 0)->GetEntity();
	wxTarInputStream *inputStream = Object_wx_TarInputStream::GetObject(args, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->CopyEntry(entry, *inputStream);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TarOutputStream, GetBlockingFactor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TarOutputStream, GetBlockingFactor)
{
	Signal &sig = env.GetSignal();
	Object_wx_TarOutputStream *pThis = Object_wx_TarOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetBlockingFactor();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TarOutputStream, SetBlockingFactor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "factor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarOutputStream, SetBlockingFactor)
{
	Signal &sig = env.GetSignal();
	Object_wx_TarOutputStream *pThis = Object_wx_TarOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int factor = args.GetInt(0);
	pThis->GetEntity()->SetBlockingFactor(factor);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TarOutputStream, PutNextDirEntry)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "dt", VTYPE_wx_DateTime, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TarOutputStream, PutNextDirEntry)
{
	Signal &sig = env.GetSignal();
	Object_wx_TarOutputStream *pThis = Object_wx_TarOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(args.GetString(0));
	wxDateTime dt = wxDateTime::Now();
	if (args.IsValid(1)) dt = *Object_wx_DateTime::GetObject(args, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->PutNextDirEntry(name, dt);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TarOutputStream, PutNextEntry)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "entry", VTYPE_wx_TarEntry, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TarOutputStream, PutNextEntry)
{
	Signal &sig = env.GetSignal();
	Object_wx_TarOutputStream *pThis = Object_wx_TarOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxTarEntry *entry = Object_wx_TarEntry::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->PutNextEntry(entry);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TarOutputStream, PutNextEntry_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "dt", VTYPE_wx_DateTime, OCCUR_ZeroOrOnce);
	DeclareArg(env, "size", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TarOutputStream, PutNextEntry_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_TarOutputStream *pThis = Object_wx_TarOutputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString name = wxString::FromUTF8(args.GetString(0));
	wxDateTime dt = wxDateTime::Now();
	if (args.IsValid(1)) dt = *Object_wx_DateTime::GetObject(args, 1)->GetEntity();
	wxFileOffset size = wxInvalidOffset;
	if (args.IsValid(2)) size = static_cast<wxFileOffset>(args.GetInt64(2));
	bool rtn = pThis->GetEntity()->PutNextEntry(name, dt, size);
	return ReturnValue(env, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxTarOutputStream
//----------------------------------------------------------------------------
Object_wx_TarOutputStream::~Object_wx_TarOutputStream()
{
}

Object *Object_wx_TarOutputStream::Clone() const
{
	return nullptr;
}

String Object_wx_TarOutputStream::ToString(bool exprFlag)
{
	String rtn("<wx.TarOutputStream:");
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
	return new Object_wx_TarOutputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
