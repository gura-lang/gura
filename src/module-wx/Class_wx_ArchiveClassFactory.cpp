//----------------------------------------------------------------------------
// wxArchiveClassFactory
// extracted from archive.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ArchiveClassFactory: public wxArchiveClassFactory, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_ArchiveClassFactory *_pObj;
public:
	~wx_ArchiveClassFactory();
	inline void AssocWithGura(Object_wx_ArchiveClassFactory *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ArchiveClassFactory::~wx_ArchiveClassFactory()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_ArchiveClassFactory::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxArchiveClassFactory
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_ArchiveClassFactory, GetConv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ArchiveClassFactory, GetConv)
{
#if 0
	Object_wx_ArchiveClassFactory *pThis = Object_wx_ArchiveClassFactory::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxMBConv &rtn = pThis->GetEntity()->GetConv();
	return ReturnValue(env, args, Value(new Object_wx_MBConv(new wxMBConv(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_ArchiveClassFactory, SetConv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "conv", VTYPE_wx_MBConv, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArchiveClassFactory, SetConv)
{
	Object_wx_ArchiveClassFactory *pThis = Object_wx_ArchiveClassFactory::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxMBConv *conv = Object_wx_MBConv::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetConv(*conv);
	return Value::Null;
}

Gura_DeclareMethod(wx_ArchiveClassFactory, CanHandle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "protocol", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "type", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ArchiveClassFactory, CanHandle)
{
	Object_wx_ArchiveClassFactory *pThis = Object_wx_ArchiveClassFactory::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString protocol = wxString::FromUTF8(args.GetString(0));
	wxStreamProtocolType type = wxSTREAM_PROTOCOL;
	if (args.IsValid(1)) type = static_cast<wxStreamProtocolType>(args.GetInt(1));
	bool rtn = pThis->GetEntity()->CanHandle(protocol, type);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_ArchiveClassFactory, Find)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "protocol", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "type", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_ArchiveClassFactory, Find)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString protocol = wxString::FromUTF8(args.GetString(0));
	wxStreamProtocolType type = wxSTREAM_PROTOCOL;
	if (args.IsValid(1)) type = static_cast<wxStreamProtocolType>(args.GetInt(1));
	wxArchiveClassFactory *rtn = (wxArchiveClassFactory *)wxArchiveClassFactory::Find(protocol, type);
	return ReturnValue(env, args, Value(new Object_wx_ArchiveClassFactory(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareClassMethod(wx_ArchiveClassFactory, GetFirst)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_ArchiveClassFactory, GetFirst)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxArchiveClassFactory *rtn = (wxArchiveClassFactory *)wxArchiveClassFactory::GetFirst();
	return ReturnValue(env, args, Value(new Object_wx_ArchiveClassFactory(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_ArchiveClassFactory, GetNext)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ArchiveClassFactory, GetNext)
{
	Object_wx_ArchiveClassFactory *pThis = Object_wx_ArchiveClassFactory::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxArchiveClassFactory *rtn = (wxArchiveClassFactory *)pThis->GetEntity()->GetNext();
	return ReturnValue(env, args, Value(new Object_wx_ArchiveClassFactory(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_ArchiveClassFactory, GetInternalName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "format", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ArchiveClassFactory, GetInternalName)
{
	Object_wx_ArchiveClassFactory *pThis = Object_wx_ArchiveClassFactory::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString name = wxString::FromUTF8(args.GetString(0));
	wxPathFormat format = wxPATH_NATIVE;
	if (args.IsValid(1)) format = static_cast<wxPathFormat>(args.GetInt(1));
	wxString rtn = pThis->GetEntity()->GetInternalName(name, format);
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_ArchiveClassFactory, GetProtocol)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ArchiveClassFactory, GetProtocol)
{
	Object_wx_ArchiveClassFactory *pThis = Object_wx_ArchiveClassFactory::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetProtocol();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_ArchiveClassFactory, GetProtocols)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "type", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ArchiveClassFactory, GetProtocols)
{
#if 0
	Object_wx_ArchiveClassFactory *pThis = Object_wx_ArchiveClassFactory::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxStreamProtocolType type = wxSTREAM_PROTOCOL;
	if (args.IsValid(0)) type = static_cast<wxStreamProtocolType>(args.GetInt(0));
	wxChar rtn = pThis->GetEntity()->GetProtocols(type);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_ArchiveClassFactory, NewEntry)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ArchiveClassFactory, NewEntry)
{
	Object_wx_ArchiveClassFactory *pThis = Object_wx_ArchiveClassFactory::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxArchiveEntry *rtn = (wxArchiveEntry *)pThis->GetEntity()->NewEntry();
	return ReturnValue(env, args, Value(new Object_wx_ArchiveEntry(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_ArchiveClassFactory, NewStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_wx_InputStream, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ArchiveClassFactory, NewStream)
{
	Object_wx_ArchiveClassFactory *pThis = Object_wx_ArchiveClassFactory::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxInputStream *stream = Object_wx_InputStream::GetObject(args, 0)->GetEntity();
	wxArchiveInputStream *rtn = (wxArchiveInputStream *)pThis->GetEntity()->NewStream(*stream);
	return ReturnValue(env, args, Value(new Object_wx_ArchiveInputStream(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_ArchiveClassFactory, NewStream_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_wx_OutputStream, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ArchiveClassFactory, NewStream_1)
{
	Object_wx_ArchiveClassFactory *pThis = Object_wx_ArchiveClassFactory::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxOutputStream *stream = Object_wx_OutputStream::GetObject(args, 0)->GetEntity();
	wxArchiveOutputStream *rtn = (wxArchiveOutputStream *)pThis->GetEntity()->NewStream(*stream);
	return ReturnValue(env, args, Value(new Object_wx_ArchiveOutputStream(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_ArchiveClassFactory, NewStream_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_wx_InputStream, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ArchiveClassFactory, NewStream_2)
{
	Object_wx_ArchiveClassFactory *pThis = Object_wx_ArchiveClassFactory::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxInputStream *stream = Object_wx_InputStream::GetObject(args, 0)->GetEntity();
	wxArchiveInputStream *rtn = (wxArchiveInputStream *)pThis->GetEntity()->NewStream(stream);
	return ReturnValue(env, args, Value(new Object_wx_ArchiveInputStream(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_ArchiveClassFactory, NewStream_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_wx_OutputStream, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ArchiveClassFactory, NewStream_3)
{
	Object_wx_ArchiveClassFactory *pThis = Object_wx_ArchiveClassFactory::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxOutputStream *stream = Object_wx_OutputStream::GetObject(args, 0)->GetEntity();
	wxArchiveOutputStream *rtn = (wxArchiveOutputStream *)pThis->GetEntity()->NewStream(stream);
	return ReturnValue(env, args, Value(new Object_wx_ArchiveOutputStream(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_ArchiveClassFactory, PushFront)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ArchiveClassFactory, PushFront)
{
	Object_wx_ArchiveClassFactory *pThis = Object_wx_ArchiveClassFactory::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->PushFront();
	return Value::Null;
}

Gura_DeclareMethod(wx_ArchiveClassFactory, Remove)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ArchiveClassFactory, Remove)
{
	Object_wx_ArchiveClassFactory *pThis = Object_wx_ArchiveClassFactory::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Remove();
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxArchiveClassFactory
//----------------------------------------------------------------------------
Object_wx_ArchiveClassFactory::~Object_wx_ArchiveClassFactory()
{
}

Object *Object_wx_ArchiveClassFactory::Clone() const
{
	return nullptr;
}

String Object_wx_ArchiveClassFactory::ToString(bool exprFlag)
{
	String rtn("<wx.ArchiveClassFactory:");
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
// Class implementation for wxArchiveClassFactory
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ArchiveClassFactory)
{
	Gura_AssignMethod(wx_ArchiveClassFactory, GetConv);
	Gura_AssignMethod(wx_ArchiveClassFactory, SetConv);
	Gura_AssignMethod(wx_ArchiveClassFactory, CanHandle);
	Gura_AssignMethod(wx_ArchiveClassFactory, Find);
	Gura_AssignMethod(wx_ArchiveClassFactory, GetFirst);
	Gura_AssignMethod(wx_ArchiveClassFactory, GetNext);
	Gura_AssignMethod(wx_ArchiveClassFactory, GetInternalName);
	Gura_AssignMethod(wx_ArchiveClassFactory, GetProtocol);
	Gura_AssignMethod(wx_ArchiveClassFactory, GetProtocols);
	Gura_AssignMethod(wx_ArchiveClassFactory, NewEntry);
	Gura_AssignMethod(wx_ArchiveClassFactory, NewStream);
	Gura_AssignMethod(wx_ArchiveClassFactory, NewStream_1);
	Gura_AssignMethod(wx_ArchiveClassFactory, NewStream_2);
	Gura_AssignMethod(wx_ArchiveClassFactory, NewStream_3);
	Gura_AssignMethod(wx_ArchiveClassFactory, PushFront);
	Gura_AssignMethod(wx_ArchiveClassFactory, Remove);
}

Gura_ImplementDescendantCreator(wx_ArchiveClassFactory)
{
	return new Object_wx_ArchiveClassFactory((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
