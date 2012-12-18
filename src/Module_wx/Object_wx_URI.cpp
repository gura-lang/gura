//----------------------------------------------------------------------------
// wxURI
// extracted from uri.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_URI: public wxURI, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_URI *_pObj;
public:
	inline wx_URI() : wxURI(), _sig(NULL), _pObj(NULL) {}
	inline wx_URI(const wxString& uri) : wxURI(uri), _sig(NULL), _pObj(NULL) {}
	inline wx_URI(const wxChar* uri) : wxURI(uri), _sig(NULL), _pObj(NULL) {}
	inline wx_URI(const wxURI& uri) : wxURI(uri), _sig(NULL), _pObj(NULL) {}
	~wx_URI();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_URI *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_URI::~wx_URI()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_URI::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxURI
//----------------------------------------------------------------------------
Gura_DeclareFunction(URIEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_URI));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(URIEmpty)
{
	wx_URI *pEntity = new wx_URI();
	Object_wx_URI *pObj = Object_wx_URI::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_URI(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareFunction(URI)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_URI));
	DeclareArg(env, "uri", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(URI)
{
	wxString uri = wxString::FromUTF8(args.GetString(0));
	wx_URI *pEntity = new wx_URI(uri);
	Object_wx_URI *pObj = Object_wx_URI::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_URI(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareFunction(URI_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_URI));
	DeclareArg(env, "uri", VTYPE_wx_URI, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(URI_1)
{
	wxURI *uri = Object_wx_URI::GetObject(args, 0)->GetEntity();
	wx_URI *pEntity = new wx_URI(*uri);
	Object_wx_URI *pObj = Object_wx_URI::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_URI(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_URI, BuildURI)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_URI, BuildURI)
{
	Object_wx_URI *pSelf = Object_wx_URI::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->BuildURI();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_URI, BuildUnescapedURI)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_URI, BuildUnescapedURI)
{
	Object_wx_URI *pSelf = Object_wx_URI::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->BuildUnescapedURI();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_URI, Create)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "uri", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_URI, Create)
{
#if 0
	Object_wx_URI *pSelf = Object_wx_URI::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString uri = wxString::FromUTF8(args.GetString(0));
	wxChar rtn = pSelf->GetEntity()->Create(uri);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_URI, GetFragment)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_URI, GetFragment)
{
	Object_wx_URI *pSelf = Object_wx_URI::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetFragment();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_URI, GetHostType)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_URI, GetHostType)
{
	Object_wx_URI *pSelf = Object_wx_URI::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
}

Gura_DeclareMethod(wx_URI, GetPassword)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_URI, GetPassword)
{
	Object_wx_URI *pSelf = Object_wx_URI::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetPassword();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_URI, GetPath)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_URI, GetPath)
{
	Object_wx_URI *pSelf = Object_wx_URI::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetPath();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_URI, GetPort)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_URI, GetPort)
{
	Object_wx_URI *pSelf = Object_wx_URI::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetPort();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_URI, GetQuery)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_URI, GetQuery)
{
	Object_wx_URI *pSelf = Object_wx_URI::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetQuery();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_URI, GetScheme)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_URI, GetScheme)
{
	Object_wx_URI *pSelf = Object_wx_URI::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetScheme();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_URI, GetServer)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_URI, GetServer)
{
	Object_wx_URI *pSelf = Object_wx_URI::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetServer();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_URI, GetUser)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_URI, GetUser)
{
	Object_wx_URI *pSelf = Object_wx_URI::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetUser();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_URI, GetUserInfo)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_URI, GetUserInfo)
{
	Object_wx_URI *pSelf = Object_wx_URI::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString rtn = pSelf->GetEntity()->GetUserInfo();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_URI, HasFragment)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_URI, HasFragment)
{
	Object_wx_URI *pSelf = Object_wx_URI::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->HasFragment();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_URI, HasPath)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_URI, HasPath)
{
	Object_wx_URI *pSelf = Object_wx_URI::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->HasPath();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_URI, HasPort)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_URI, HasPort)
{
	Object_wx_URI *pSelf = Object_wx_URI::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->HasPort();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_URI, HasQuery)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_URI, HasQuery)
{
	Object_wx_URI *pSelf = Object_wx_URI::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->HasQuery();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_URI, HasScheme)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_URI, HasScheme)
{
	Object_wx_URI *pSelf = Object_wx_URI::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->HasScheme();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_URI, HasServer)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_URI, HasServer)
{
	Object_wx_URI *pSelf = Object_wx_URI::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->HasServer();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_URI, HasUser)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_URI, HasUser)
{
#if 0
	Object_wx_URI *pSelf = Object_wx_URI::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->HasUser();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_URI, IsReference)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_URI, IsReference)
{
	Object_wx_URI *pSelf = Object_wx_URI::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsReference();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_URI, Resolve)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "base", VTYPE_wx_URI, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_URI, Resolve)
{
	Object_wx_URI *pSelf = Object_wx_URI::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxURI *base = Object_wx_URI::GetObject(args, 0)->GetEntity();
	int flags = wxURI_STRICT;
	if (args.IsValid(1)) flags = args.GetInt(1);
	pSelf->GetEntity()->Resolve(*base, flags);
	return Value::Null;
}

Gura_DeclareMethod(wx_URI, Unescape)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "uri", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_URI, Unescape)
{
	Object_wx_URI *pSelf = Object_wx_URI::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString uri = wxString::FromUTF8(args.GetString(0));
	wxString rtn = pSelf->GetEntity()->Unescape(uri);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

//----------------------------------------------------------------------------
// Object implementation for wxURI
//----------------------------------------------------------------------------
Object_wx_URI::~Object_wx_URI()
{
}

Object *Object_wx_URI::Clone() const
{
	return NULL;
}

String Object_wx_URI::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.URI:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_URI::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(URIEmpty);
	Gura_AssignFunction(URI);
	Gura_AssignFunction(URI_1);
}

//----------------------------------------------------------------------------
// Class implementation for wxURI
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_URI)
{
	Gura_AssignMethod(wx_URI, BuildURI);
	Gura_AssignMethod(wx_URI, BuildUnescapedURI);
	Gura_AssignMethod(wx_URI, Create);
	Gura_AssignMethod(wx_URI, GetFragment);
	Gura_AssignMethod(wx_URI, GetHostType);
	Gura_AssignMethod(wx_URI, GetPassword);
	Gura_AssignMethod(wx_URI, GetPath);
	Gura_AssignMethod(wx_URI, GetPort);
	Gura_AssignMethod(wx_URI, GetQuery);
	Gura_AssignMethod(wx_URI, GetScheme);
	Gura_AssignMethod(wx_URI, GetServer);
	Gura_AssignMethod(wx_URI, GetUser);
	Gura_AssignMethod(wx_URI, GetUserInfo);
	Gura_AssignMethod(wx_URI, HasFragment);
	Gura_AssignMethod(wx_URI, HasPath);
	Gura_AssignMethod(wx_URI, HasPort);
	Gura_AssignMethod(wx_URI, HasQuery);
	Gura_AssignMethod(wx_URI, HasScheme);
	Gura_AssignMethod(wx_URI, HasServer);
	Gura_AssignMethod(wx_URI, HasUser);
	Gura_AssignMethod(wx_URI, IsReference);
	Gura_AssignMethod(wx_URI, Resolve);
	Gura_AssignMethod(wx_URI, Unescape);
}

Gura_ImplementDescendantCreator(wx_URI)
{
	return new Object_wx_URI((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
