//----------------------------------------------------------------------------
// wxIPaddress
// extracted from ipaddr.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

Gura_DeclarePrivUserSymbol(Hostname);
Gura_DeclarePrivUserSymbol(Hostname_1);
Gura_DeclarePrivUserSymbol(IPAddress);
Gura_DeclarePrivUserSymbol(Service);
Gura_DeclarePrivUserSymbol(Service_1);
Gura_DeclarePrivUserSymbol(Service_2);
Gura_DeclarePrivUserSymbol(AnyAddress);
Gura_DeclarePrivUserSymbol(LocalHost);
Gura_DeclarePrivUserSymbol(IsLocalHost);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_IPaddress: public wxIPaddress, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_IPaddress *_pObj;
public:
	//virtual bool Hostname(const wxString& hostname);
	//virtual wxString Hostname();
	//virtual wxString IPAddress();
	//virtual bool Service(const wxString& service);
	//virtual bool Service(unsigned short service);
	//virtual unsigned short Service();
	//virtual bool AnyAddress();
	//virtual bool LocalHost();
	//virtual bool IsLocalHost();
	~wx_IPaddress();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_IPaddress *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_IPaddress::~wx_IPaddress()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_IPaddress::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxIPaddress
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_IPaddress, Hostname)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "hostname", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_IPaddress, Hostname)
{
	Object_wx_IPaddress *pThis = Object_wx_IPaddress::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString hostname = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->Hostname(hostname);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_IPaddress, Hostname_1)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_IPaddress, Hostname_1)
{
	Object_wx_IPaddress *pThis = Object_wx_IPaddress::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->Hostname();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_IPaddress, IPAddress)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_IPaddress, IPAddress)
{
	Object_wx_IPaddress *pThis = Object_wx_IPaddress::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->IPAddress();
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_IPaddress, Service)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "service", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_IPaddress, Service)
{
	Object_wx_IPaddress *pThis = Object_wx_IPaddress::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString service = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->Service(service);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_IPaddress, Service_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "service", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_IPaddress, Service_1)
{
	Object_wx_IPaddress *pThis = Object_wx_IPaddress::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	unsigned service = args.GetInt(0);
	bool rtn = pThis->GetEntity()->Service(service);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_IPaddress, Service_2)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_IPaddress, Service_2)
{
	Object_wx_IPaddress *pThis = Object_wx_IPaddress::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	unsigned rtn = pThis->GetEntity()->Service();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_IPaddress, AnyAddress)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_IPaddress, AnyAddress)
{
	Object_wx_IPaddress *pThis = Object_wx_IPaddress::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->AnyAddress();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_IPaddress, LocalHost)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_IPaddress, LocalHost)
{
	Object_wx_IPaddress *pThis = Object_wx_IPaddress::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->LocalHost();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_IPaddress, IsLocalHost)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_IPaddress, IsLocalHost)
{
	Object_wx_IPaddress *pThis = Object_wx_IPaddress::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsLocalHost();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxIPaddress
//----------------------------------------------------------------------------
Object_wx_IPaddress::~Object_wx_IPaddress()
{
}

Object *Object_wx_IPaddress::Clone() const
{
	return NULL;
}

String Object_wx_IPaddress::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.IPaddress:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_IPaddress::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_RealizeUserSymbol(Hostname);
	Gura_RealizeUserSymbol(Hostname_1);
	Gura_RealizeUserSymbol(IPAddress);
	Gura_RealizeUserSymbol(Service);
	Gura_RealizeUserSymbol(Service_1);
	Gura_RealizeUserSymbol(Service_2);
	Gura_RealizeUserSymbol(AnyAddress);
	Gura_RealizeUserSymbol(LocalHost);
	Gura_RealizeUserSymbol(IsLocalHost);
}

//----------------------------------------------------------------------------
// Class implementation for wxIPaddress
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_IPaddress)
{
	Gura_AssignMethod(wx_IPaddress, Hostname);
	Gura_AssignMethod(wx_IPaddress, Hostname_1);
	Gura_AssignMethod(wx_IPaddress, IPAddress);
	Gura_AssignMethod(wx_IPaddress, Service);
	Gura_AssignMethod(wx_IPaddress, Service_1);
	Gura_AssignMethod(wx_IPaddress, Service_2);
	Gura_AssignMethod(wx_IPaddress, AnyAddress);
	Gura_AssignMethod(wx_IPaddress, LocalHost);
	Gura_AssignMethod(wx_IPaddress, IsLocalHost);
}

Gura_ImplementDescendantCreator(wx_IPaddress)
{
	return new Object_wx_IPaddress((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
