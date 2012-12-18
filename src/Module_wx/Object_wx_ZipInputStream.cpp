//----------------------------------------------------------------------------
// wxZipInputStream
// extracted from zipstrm.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ZipInputStream: public wxZipInputStream, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_ZipInputStream *_pObj;
public:
	inline wx_ZipInputStream(wxInputStream& stream, wxMBConv& conv) : wxZipInputStream(stream, conv), _sig(NULL), _pObj(NULL) {}
	inline wx_ZipInputStream(wxInputStream* stream, wxMBConv& conv) : wxZipInputStream(stream, conv), _sig(NULL), _pObj(NULL) {}
	inline wx_ZipInputStream(const wxString& archive, const wxString& file) : wxZipInputStream(archive, file), _sig(NULL), _pObj(NULL) {}
	~wx_ZipInputStream();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ZipInputStream *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ZipInputStream::~wx_ZipInputStream()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_ZipInputStream::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxZipInputStream
//----------------------------------------------------------------------------
Gura_DeclareFunction(ZipInputStream)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_ZipInputStream));
	DeclareArg(env, "stream", VTYPE_wx_InputStream, OCCUR_Once);
	DeclareArg(env, "conv", VTYPE_wx_MBConv, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ZipInputStream)
{
	wxInputStream *stream = Object_wx_InputStream::GetObject(args, 0)->GetEntity();
	wxMBConv *conv = (wxMBConv *)(&wxConvLocal);
	if (args.IsValid(1)) conv = Object_wx_MBConv::GetObject(args, 1)->GetEntity();
	wx_ZipInputStream *pEntity = new wx_ZipInputStream(*stream, *conv);
	Object_wx_ZipInputStream *pObj = Object_wx_ZipInputStream::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_ZipInputStream(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareFunction(ZipInputStream_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_ZipInputStream));
	DeclareArg(env, "stream", VTYPE_wx_InputStream, OCCUR_Once);
	DeclareArg(env, "conv", VTYPE_wx_MBConv, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ZipInputStream_1)
{
	wxInputStream *stream = Object_wx_InputStream::GetObject(args, 0)->GetEntity();
	wxMBConv *conv = (wxMBConv *)(&wxConvLocal);
	if (args.IsValid(1)) conv = Object_wx_MBConv::GetObject(args, 1)->GetEntity();
	wx_ZipInputStream *pEntity = new wx_ZipInputStream(stream, *conv);
	Object_wx_ZipInputStream *pObj = Object_wx_ZipInputStream::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_ZipInputStream(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareFunction(ZipInputStream_2)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_ZipInputStream));
	DeclareArg(env, "archive", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "file", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ZipInputStream_2)
{
	wxString archive = wxString::FromUTF8(args.GetString(0));
	wxString file = wxString::FromUTF8(args.GetString(1));
	wx_ZipInputStream *pEntity = new wx_ZipInputStream(archive, file);
	Object_wx_ZipInputStream *pObj = Object_wx_ZipInputStream::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_ZipInputStream(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_ZipInputStream, CloseEntry)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ZipInputStream, CloseEntry)
{
	Object_wx_ZipInputStream *pSelf = Object_wx_ZipInputStream::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->CloseEntry();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ZipInputStream, GetComment)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ZipInputStream, GetComment)
{
	Object_wx_ZipInputStream *pSelf = Object_wx_ZipInputStream::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetComment();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_ZipInputStream, GetNextEntry)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ZipInputStream, GetNextEntry)
{
	Object_wx_ZipInputStream *pSelf = Object_wx_ZipInputStream::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxZipEntry *rtn = (wxZipEntry *)pSelf->GetEntity()->GetNextEntry();
	return ReturnValue(env, sig, args, Value(new Object_wx_ZipEntry(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_ZipInputStream, GetTotalEntries)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ZipInputStream, GetTotalEntries)
{
	Object_wx_ZipInputStream *pSelf = Object_wx_ZipInputStream::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int rtn = pSelf->GetEntity()->GetTotalEntries();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_ZipInputStream, OpenEntry)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "entry", VTYPE_wx_ZipEntry, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ZipInputStream, OpenEntry)
{
	Object_wx_ZipInputStream *pSelf = Object_wx_ZipInputStream::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxZipEntry *entry = Object_wx_ZipEntry::GetObject(args, 0)->GetEntity();
	bool rtn = pSelf->GetEntity()->OpenEntry(*entry);
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxZipInputStream
//----------------------------------------------------------------------------
Object_wx_ZipInputStream::~Object_wx_ZipInputStream()
{
}

Object *Object_wx_ZipInputStream::Clone() const
{
	return NULL;
}

String Object_wx_ZipInputStream::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.ZipInputStream:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_ZipInputStream::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(ZipInputStream);
	Gura_AssignFunction(ZipInputStream_1);
	Gura_AssignFunction(ZipInputStream_2);
}

//----------------------------------------------------------------------------
// Class implementation for wxZipInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ZipInputStream)
{
	Gura_AssignMethod(wx_ZipInputStream, CloseEntry);
	Gura_AssignMethod(wx_ZipInputStream, GetComment);
	Gura_AssignMethod(wx_ZipInputStream, GetNextEntry);
	Gura_AssignMethod(wx_ZipInputStream, GetTotalEntries);
	Gura_AssignMethod(wx_ZipInputStream, OpenEntry);
}

Gura_ImplementDescendantCreator(wx_ZipInputStream)
{
	return new Object_wx_ZipInputStream((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
