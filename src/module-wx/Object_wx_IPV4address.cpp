//----------------------------------------------------------------------------
// wxIPV4address
// extracted from ipvaddr.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_IPV4address: public wxIPV4address, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_IPV4address *_pObj;
public:
	~wx_IPV4address();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_IPV4address *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_IPV4address::~wx_IPV4address()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_IPV4address::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxIPV4address
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_IPV4address, Hostname)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "hostname", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_IPV4address, Hostname)
{
	Object_wx_IPV4address *pThis = Object_wx_IPV4address::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString hostname = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->Hostname(hostname);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_IPV4address, Hostname_1)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_IPV4address, Hostname_1)
{
	Object_wx_IPV4address *pThis = Object_wx_IPV4address::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->Hostname();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_IPV4address, IPAddress)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_IPV4address, IPAddress)
{
	Object_wx_IPV4address *pThis = Object_wx_IPV4address::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->IPAddress();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_IPV4address, Service)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "service", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_IPV4address, Service)
{
	Object_wx_IPV4address *pThis = Object_wx_IPV4address::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString service = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->Service(service);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_IPV4address, Service_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "service", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_IPV4address, Service_1)
{
	Object_wx_IPV4address *pThis = Object_wx_IPV4address::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	unsigned service = args.GetInt(0);
	bool rtn = pThis->GetEntity()->Service(service);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_IPV4address, Service_2)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_IPV4address, Service_2)
{
	Object_wx_IPV4address *pThis = Object_wx_IPV4address::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	unsigned rtn = pThis->GetEntity()->Service();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_IPV4address, AnyAddress)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_IPV4address, AnyAddress)
{
	Object_wx_IPV4address *pThis = Object_wx_IPV4address::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->AnyAddress();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_IPV4address, LocalHost)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_IPV4address, LocalHost)
{
	Object_wx_IPV4address *pThis = Object_wx_IPV4address::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->LocalHost();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxIPV4address
//----------------------------------------------------------------------------
Object_wx_IPV4address::~Object_wx_IPV4address()
{
}

Object *Object_wx_IPV4address::Clone() const
{
	return NULL;
}

String Object_wx_IPV4address::ToString(bool exprFlag)
{
	String rtn("<wx.IPV4address:");
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
// Class implementation for wxIPV4address
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_IPV4address)
{
	Gura_AssignMethod(wx_IPV4address, Hostname);
	Gura_AssignMethod(wx_IPV4address, Hostname_1);
	Gura_AssignMethod(wx_IPV4address, IPAddress);
	Gura_AssignMethod(wx_IPV4address, Service);
	Gura_AssignMethod(wx_IPV4address, Service_1);
	Gura_AssignMethod(wx_IPV4address, Service_2);
	Gura_AssignMethod(wx_IPV4address, AnyAddress);
	Gura_AssignMethod(wx_IPV4address, LocalHost);
}

Gura_ImplementDescendantCreator(wx_IPV4address)
{
	return new Object_wx_IPV4address((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
