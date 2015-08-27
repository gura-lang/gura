//----------------------------------------------------------------------------
// wxURI
// extracted from uri.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_URI: public wxURI, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_URI *_pObj;
public:
	inline wx_URI() : wxURI(), _pObj(nullptr) {}
	inline wx_URI(const wxString& uri) : wxURI(uri), _pObj(nullptr) {}
	inline wx_URI(const wxChar* uri) : wxURI(uri), _pObj(nullptr) {}
	inline wx_URI(const wxURI& uri) : wxURI(uri), _pObj(nullptr) {}
	~wx_URI();
	inline void AssocWithGura(Object_wx_URI *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_URI::~wx_URI()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_URI::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxURI
//----------------------------------------------------------------------------
Gura_DeclareFunction(URIEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_URI));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(URIEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_URI *pEntity = new wx_URI();
	Object_wx_URI *pObj = Object_wx_URI::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_URI(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareFunction(URI)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_URI));
	DeclareArg(env, "uri", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(URI)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxString uri = wxString::FromUTF8(args.GetString(0));
	wx_URI *pEntity = new wx_URI(uri);
	Object_wx_URI *pObj = Object_wx_URI::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_URI(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareFunction(URI_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_URI));
	DeclareArg(env, "uri", VTYPE_wx_URI, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(URI_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxURI *uri = Object_wx_URI::GetObject(args, 0)->GetEntity();
	wx_URI *pEntity = new wx_URI(*uri);
	Object_wx_URI *pObj = Object_wx_URI::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_URI(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareMethod(wx_URI, BuildURI)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_URI, BuildURI)
{
	Signal &sig = env.GetSignal();
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->BuildURI();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_URI, BuildUnescapedURI)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_URI, BuildUnescapedURI)
{
	Signal &sig = env.GetSignal();
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->BuildUnescapedURI();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_URI, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "uri", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_URI, Create)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString uri = wxString::FromUTF8(args.GetString(0));
	wxChar rtn = pThis->GetEntity()->Create(uri);
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_URI, GetFragment)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_URI, GetFragment)
{
	Signal &sig = env.GetSignal();
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetFragment();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_URI, GetHostType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_URI, GetHostType)
{
	Signal &sig = env.GetSignal();
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
}

Gura_DeclareMethod(wx_URI, GetPassword)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_URI, GetPassword)
{
	Signal &sig = env.GetSignal();
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetPassword();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_URI, GetPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_URI, GetPath)
{
	Signal &sig = env.GetSignal();
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetPath();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_URI, GetPort)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_URI, GetPort)
{
	Signal &sig = env.GetSignal();
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetPort();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_URI, GetQuery)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_URI, GetQuery)
{
	Signal &sig = env.GetSignal();
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetQuery();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_URI, GetScheme)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_URI, GetScheme)
{
	Signal &sig = env.GetSignal();
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetScheme();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_URI, GetServer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_URI, GetServer)
{
	Signal &sig = env.GetSignal();
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetServer();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_URI, GetUser)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_URI, GetUser)
{
	Signal &sig = env.GetSignal();
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetUser();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_URI, GetUserInfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_URI, GetUserInfo)
{
	Signal &sig = env.GetSignal();
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetUserInfo();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_URI, HasFragment)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_URI, HasFragment)
{
	Signal &sig = env.GetSignal();
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->HasFragment();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_URI, HasPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_URI, HasPath)
{
	Signal &sig = env.GetSignal();
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->HasPath();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_URI, HasPort)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_URI, HasPort)
{
	Signal &sig = env.GetSignal();
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->HasPort();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_URI, HasQuery)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_URI, HasQuery)
{
	Signal &sig = env.GetSignal();
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->HasQuery();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_URI, HasScheme)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_URI, HasScheme)
{
	Signal &sig = env.GetSignal();
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->HasScheme();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_URI, HasServer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_URI, HasServer)
{
	Signal &sig = env.GetSignal();
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->HasServer();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_URI, HasUser)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_URI, HasUser)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->HasUser();
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_URI, IsReference)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_URI, IsReference)
{
	Signal &sig = env.GetSignal();
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsReference();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_URI, Resolve)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "base", VTYPE_wx_URI, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_URI, Resolve)
{
	Signal &sig = env.GetSignal();
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxURI *base = Object_wx_URI::GetObject(args, 0)->GetEntity();
	int flags = wxURI_STRICT;
	if (args.IsValid(1)) flags = args.GetInt(1);
	pThis->GetEntity()->Resolve(*base, flags);
	return Value::Nil;
}

Gura_DeclareMethod(wx_URI, Unescape)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "uri", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_URI, Unescape)
{
	Signal &sig = env.GetSignal();
	Object_wx_URI *pThis = Object_wx_URI::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString uri = wxString::FromUTF8(args.GetString(0));
	wxString rtn = pThis->GetEntity()->Unescape(uri);
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

//----------------------------------------------------------------------------
// Object implementation for wxURI
//----------------------------------------------------------------------------
Object_wx_URI::~Object_wx_URI()
{
}

Object *Object_wx_URI::Clone() const
{
	return nullptr;
}

String Object_wx_URI::ToString(bool exprFlag)
{
	String rtn("<wx.URI:");
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
// Class implementation for wxURI
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_URI)
{
	Gura_AssignFunction(URIEmpty);
	Gura_AssignFunction(URI);
	Gura_AssignFunction(URI_1);
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
	return new Object_wx_URI((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
