//----------------------------------------------------------------------------
// wxURL
// extracted from url.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_URL: public wxURL, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_URL *_pObj;
public:
	inline wx_URL(const wxString& url) : wxURL(url), _sig(NULL), _pObj(NULL) {}
	~wx_URL();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_URL *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_URL::~wx_URL()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_URL::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxURL
//----------------------------------------------------------------------------
Gura_DeclareFunction(URL)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_URL));
	DeclareArg(env, "url", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(URL)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString url = wxEmptyString;
	if (args.IsValid(0)) url = wxString::FromUTF8(args.GetString(0));
	wx_URL *pEntity = new wx_URL(url);
	Object_wx_URL *pObj = Object_wx_URL::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_URL(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_URL, GetProtocol)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_URL, GetProtocol)
{
#if 0
	Object_wx_URL *pThis = Object_wx_URL::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxProtocol &rtn = pThis->GetEntity()->GetProtocol();
	return ReturnValue(env, sig, args, Value(new Object_wx_Protocol(new wxProtocol(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_URL, GetError)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_URL, GetError)
{
	Object_wx_URL *pThis = Object_wx_URL::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxURLError rtn = pThis->GetEntity()->GetError();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_URL, GetInputStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_URL, GetInputStream)
{
	Object_wx_URL *pThis = Object_wx_URL::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxInputStream *rtn = (wxInputStream *)pThis->GetEntity()->GetInputStream();
	return ReturnValue(env, sig, args, Value(new Object_wx_InputStream(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_URL, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_URL, IsOk)
{
	Object_wx_URL *pThis = Object_wx_URL::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsOk();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_URL, SetDefaultProxy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "url_proxy", VTYPE_string, OCCUR_Once);
}

Gura_ImplementClassMethod(wx_URL, SetDefaultProxy)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString url_proxy = wxString::FromUTF8(args.GetString(0));
	wxURL::SetDefaultProxy(url_proxy);
	return Value::Null;
}

Gura_DeclareMethod(wx_URL, SetProxy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "url_proxy", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_URL, SetProxy)
{
	Object_wx_URL *pThis = Object_wx_URL::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString url_proxy = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetProxy(url_proxy);
	return Value::Null;
}

Gura_DeclareMethod(wx_URL, SetURL)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "url", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_URL, SetURL)
{
	Object_wx_URL *pThis = Object_wx_URL::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString url = wxString::FromUTF8(args.GetString(0));
	wxURLError rtn = pThis->GetEntity()->SetURL(url);
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxURL
//----------------------------------------------------------------------------
Object_wx_URL::~Object_wx_URL()
{
}

Object *Object_wx_URL::Clone() const
{
	return NULL;
}

String Object_wx_URL::ToString(bool exprFlag)
{
	String rtn("<wx.URL:");
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
// Class implementation for wxURL
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_URL)
{
	Gura_AssignFunction(URL);
	Gura_AssignMethod(wx_URL, GetProtocol);
	Gura_AssignMethod(wx_URL, GetError);
	Gura_AssignMethod(wx_URL, GetInputStream);
	Gura_AssignMethod(wx_URL, IsOk);
	Gura_AssignMethod(wx_URL, SetDefaultProxy);
	Gura_AssignMethod(wx_URL, SetProxy);
	Gura_AssignMethod(wx_URL, SetURL);
}

Gura_ImplementDescendantCreator(wx_URL)
{
	return new Object_wx_URL((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
