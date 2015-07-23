//----------------------------------------------------------------------------
// wxFilterClassFactory
// extracted from fltfactory.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_FilterClassFactory: public wxFilterClassFactory, public GuraObjectObserver {
private:
	Gura::Signal *_pSig;
	Object_wx_FilterClassFactory *_pObj;
public:
	~wx_FilterClassFactory();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_FilterClassFactory *pObj) {
		_pSig = &sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_FilterClassFactory::~wx_FilterClassFactory()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_FilterClassFactory::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxFilterClassFactory
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_FilterClassFactory, CanHandle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "protocol", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "type", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FilterClassFactory, CanHandle)
{
	Object_wx_FilterClassFactory *pThis = Object_wx_FilterClassFactory::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString protocol = wxString::FromUTF8(args.GetString(0));
	wxStreamProtocolType type = wxSTREAM_PROTOCOL;
	if (args.IsValid(1)) type = static_cast<wxStreamProtocolType>(args.GetInt(1));
	bool rtn = pThis->GetEntity()->CanHandle(protocol, type);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_FilterClassFactory, Find)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "protocol", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "type", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FilterClassFactory, Find)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString protocol = wxString::FromUTF8(args.GetString(0));
	wxStreamProtocolType type = wxSTREAM_PROTOCOL;
	if (args.IsValid(1)) type = static_cast<wxStreamProtocolType>(args.GetInt(1));
	wxFilterClassFactory *rtn = (wxFilterClassFactory *)wxFilterClassFactory::Find(protocol, type);
	return ReturnValue(env, args, Value(new Object_wx_FilterClassFactory(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareClassMethod(wx_FilterClassFactory, GetFirst)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_FilterClassFactory, GetFirst)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxFilterClassFactory *rtn = (wxFilterClassFactory *)wxFilterClassFactory::GetFirst();
	return ReturnValue(env, args, Value(new Object_wx_FilterClassFactory(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_FilterClassFactory, GetNext)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FilterClassFactory, GetNext)
{
	Object_wx_FilterClassFactory *pThis = Object_wx_FilterClassFactory::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFilterClassFactory *rtn = (wxFilterClassFactory *)pThis->GetEntity()->GetNext();
	return ReturnValue(env, args, Value(new Object_wx_FilterClassFactory(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_FilterClassFactory, GetProtocol)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FilterClassFactory, GetProtocol)
{
	Object_wx_FilterClassFactory *pThis = Object_wx_FilterClassFactory::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetProtocol();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_FilterClassFactory, GetProtocols)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "type", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FilterClassFactory, GetProtocols)
{
#if 0
	Object_wx_FilterClassFactory *pThis = Object_wx_FilterClassFactory::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxStreamProtocolType type = wxSTREAM_PROTOCOL;
	if (args.IsValid(0)) type = static_cast<wxStreamProtocolType>(args.GetInt(0));
	wxChar rtn = pThis->GetEntity()->GetProtocols(type);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_FilterClassFactory, NewStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_wx_InputStream, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FilterClassFactory, NewStream)
{
	Object_wx_FilterClassFactory *pThis = Object_wx_FilterClassFactory::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxInputStream *stream = Object_wx_InputStream::GetObject(args, 0)->GetEntity();
	wxFilterInputStream *rtn = (wxFilterInputStream *)pThis->GetEntity()->NewStream(*stream);
	return ReturnValue(env, args, Value(new Object_wx_FilterInputStream(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_FilterClassFactory, NewStream_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_wx_OutputStream, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FilterClassFactory, NewStream_1)
{
	Object_wx_FilterClassFactory *pThis = Object_wx_FilterClassFactory::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxOutputStream *stream = Object_wx_OutputStream::GetObject(args, 0)->GetEntity();
	wxFilterOutputStream *rtn = (wxFilterOutputStream *)pThis->GetEntity()->NewStream(*stream);
	return ReturnValue(env, args, Value(new Object_wx_FilterOutputStream(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_FilterClassFactory, NewStream_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_wx_InputStream, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FilterClassFactory, NewStream_2)
{
	Object_wx_FilterClassFactory *pThis = Object_wx_FilterClassFactory::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxInputStream *stream = Object_wx_InputStream::GetObject(args, 0)->GetEntity();
	wxFilterInputStream *rtn = (wxFilterInputStream *)pThis->GetEntity()->NewStream(stream);
	return ReturnValue(env, args, Value(new Object_wx_FilterInputStream(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_FilterClassFactory, NewStream_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_wx_OutputStream, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FilterClassFactory, NewStream_3)
{
	Object_wx_FilterClassFactory *pThis = Object_wx_FilterClassFactory::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxOutputStream *stream = Object_wx_OutputStream::GetObject(args, 0)->GetEntity();
	wxFilterOutputStream *rtn = (wxFilterOutputStream *)pThis->GetEntity()->NewStream(stream);
	return ReturnValue(env, args, Value(new Object_wx_FilterOutputStream(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_FilterClassFactory, PopExtension)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "location", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_FilterClassFactory, PopExtension)
{
	Object_wx_FilterClassFactory *pThis = Object_wx_FilterClassFactory::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString location = wxString::FromUTF8(args.GetString(0));
	wxString rtn = pThis->GetEntity()->PopExtension(location);
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_FilterClassFactory, PushFront)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FilterClassFactory, PushFront)
{
	Object_wx_FilterClassFactory *pThis = Object_wx_FilterClassFactory::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->PushFront();
	return Value::Null;
}

Gura_DeclareMethod(wx_FilterClassFactory, Remove)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FilterClassFactory, Remove)
{
	Object_wx_FilterClassFactory *pThis = Object_wx_FilterClassFactory::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Remove();
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxFilterClassFactory
//----------------------------------------------------------------------------
Object_wx_FilterClassFactory::~Object_wx_FilterClassFactory()
{
}

Object *Object_wx_FilterClassFactory::Clone() const
{
	return nullptr;
}

String Object_wx_FilterClassFactory::ToString(bool exprFlag)
{
	String rtn("<wx.FilterClassFactory:");
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
// Class implementation for wxFilterClassFactory
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FilterClassFactory)
{
	Gura_AssignMethod(wx_FilterClassFactory, CanHandle);
	Gura_AssignMethod(wx_FilterClassFactory, Find);
	Gura_AssignMethod(wx_FilterClassFactory, GetFirst);
	Gura_AssignMethod(wx_FilterClassFactory, GetNext);
	Gura_AssignMethod(wx_FilterClassFactory, GetProtocol);
	Gura_AssignMethod(wx_FilterClassFactory, GetProtocols);
	Gura_AssignMethod(wx_FilterClassFactory, NewStream);
	Gura_AssignMethod(wx_FilterClassFactory, NewStream_1);
	Gura_AssignMethod(wx_FilterClassFactory, NewStream_2);
	Gura_AssignMethod(wx_FilterClassFactory, NewStream_3);
	Gura_AssignMethod(wx_FilterClassFactory, PopExtension);
	Gura_AssignMethod(wx_FilterClassFactory, PushFront);
	Gura_AssignMethod(wx_FilterClassFactory, Remove);
}

Gura_ImplementDescendantCreator(wx_FilterClassFactory)
{
	return new Object_wx_FilterClassFactory((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
