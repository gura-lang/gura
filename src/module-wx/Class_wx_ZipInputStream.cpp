//----------------------------------------------------------------------------
// wxZipInputStream
// extracted from zipstrm.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ZipInputStream: public wxZipInputStream, public GuraObjectObserver {
private:
	Gura::Signal *_pSig;
	Object_wx_ZipInputStream *_pObj;
public:
	inline wx_ZipInputStream(wxInputStream& stream, wxMBConv& conv) : wxZipInputStream(stream, conv), _pSig(nullptr), _pObj(nullptr) {}
	inline wx_ZipInputStream(wxInputStream* stream, wxMBConv& conv) : wxZipInputStream(stream, conv), _pSig(nullptr), _pObj(nullptr) {}
	//inline wx_ZipInputStream(const wxString& archive, const wxString& file) : wxZipInputStream(archive, file), _pSig(nullptr), _pObj(nullptr) {}
	~wx_ZipInputStream();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ZipInputStream *pObj) {
		_pSig = &sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ZipInputStream::~wx_ZipInputStream()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_ZipInputStream::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxZipInputStream
//----------------------------------------------------------------------------
Gura_DeclareFunction(ZipInputStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_ZipInputStream));
	DeclareArg(env, "stream", VTYPE_wx_InputStream, OCCUR_Once);
	DeclareArg(env, "conv", VTYPE_wx_MBConv, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ZipInputStream)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxInputStream *stream = Object_wx_InputStream::GetObject(args, 0)->GetEntity();
	wxMBConv *conv = (wxMBConv *)(&wxConvLocal);
	if (args.IsValid(1)) conv = Object_wx_MBConv::GetObject(args, 1)->GetEntity();
	wx_ZipInputStream *pEntity = new wx_ZipInputStream(*stream, *conv);
	Object_wx_ZipInputStream *pObj = Object_wx_ZipInputStream::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_ZipInputStream(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareFunction(ZipInputStream_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_ZipInputStream));
	DeclareArg(env, "stream", VTYPE_wx_InputStream, OCCUR_Once);
	DeclareArg(env, "conv", VTYPE_wx_MBConv, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ZipInputStream_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxInputStream *stream = Object_wx_InputStream::GetObject(args, 0)->GetEntity();
	wxMBConv *conv = (wxMBConv *)(&wxConvLocal);
	if (args.IsValid(1)) conv = Object_wx_MBConv::GetObject(args, 1)->GetEntity();
	wx_ZipInputStream *pEntity = new wx_ZipInputStream(stream, *conv);
	Object_wx_ZipInputStream *pObj = Object_wx_ZipInputStream::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_ZipInputStream(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, args, args.GetThis());
}

#if 0
Gura_DeclareFunction(ZipInputStream_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_ZipInputStream));
	DeclareArg(env, "archive", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "file", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ZipInputStream_2)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString archive = wxString::FromUTF8(args.GetString(0));
	wxString file = wxString::FromUTF8(args.GetString(1));
	wx_ZipInputStream *pEntity = new wx_ZipInputStream(archive, file);
	Object_wx_ZipInputStream *pObj = Object_wx_ZipInputStream::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_ZipInputStream(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, args, args.GetThis());
}
#endif

Gura_DeclareMethod(wx_ZipInputStream, CloseEntry)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ZipInputStream, CloseEntry)
{
	Object_wx_ZipInputStream *pThis = Object_wx_ZipInputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->CloseEntry();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ZipInputStream, GetComment)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ZipInputStream, GetComment)
{
	Object_wx_ZipInputStream *pThis = Object_wx_ZipInputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetComment();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_ZipInputStream, GetNextEntry)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ZipInputStream, GetNextEntry)
{
	Object_wx_ZipInputStream *pThis = Object_wx_ZipInputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxZipEntry *rtn = (wxZipEntry *)pThis->GetEntity()->GetNextEntry();
	return ReturnValue(env, args, Value(new Object_wx_ZipEntry(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_ZipInputStream, GetTotalEntries)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ZipInputStream, GetTotalEntries)
{
	Object_wx_ZipInputStream *pThis = Object_wx_ZipInputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetTotalEntries();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_ZipInputStream, OpenEntry)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "entry", VTYPE_wx_ZipEntry, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ZipInputStream, OpenEntry)
{
	Object_wx_ZipInputStream *pThis = Object_wx_ZipInputStream::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxZipEntry *entry = Object_wx_ZipEntry::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->OpenEntry(*entry);
	return ReturnValue(env, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxZipInputStream
//----------------------------------------------------------------------------
Object_wx_ZipInputStream::~Object_wx_ZipInputStream()
{
}

Object *Object_wx_ZipInputStream::Clone() const
{
	return nullptr;
}

String Object_wx_ZipInputStream::ToString(bool exprFlag)
{
	String rtn("<wx.ZipInputStream:");
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
// Class implementation for wxZipInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ZipInputStream)
{
	Gura_AssignFunction(ZipInputStream);
	Gura_AssignFunction(ZipInputStream_1);
	//Gura_AssignFunction(ZipInputStream_2);
	Gura_AssignMethod(wx_ZipInputStream, CloseEntry);
	Gura_AssignMethod(wx_ZipInputStream, GetComment);
	Gura_AssignMethod(wx_ZipInputStream, GetNextEntry);
	Gura_AssignMethod(wx_ZipInputStream, GetTotalEntries);
	Gura_AssignMethod(wx_ZipInputStream, OpenEntry);
}

Gura_ImplementDescendantCreator(wx_ZipInputStream)
{
	return new Object_wx_ZipInputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
