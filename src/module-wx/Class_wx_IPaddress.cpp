//----------------------------------------------------------------------------
// wxIPaddress
// extracted from ipaddr.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

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
	//Gura::Signal *_pSig;
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
	inline void AssocWithGura(Object_wx_IPaddress *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_IPaddress::~wx_IPaddress()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_IPaddress::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxIPaddress
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_IPaddress, Hostname)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "hostname", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_IPaddress, Hostname)
{
	Signal &sig = env.GetSignal();
	Object_wx_IPaddress *pThis = Object_wx_IPaddress::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString hostname = wxString::FromUTF8(arg.GetString(0));
	bool rtn = pThis->GetEntity()->Hostname(hostname);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_IPaddress, Hostname_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_IPaddress, Hostname_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_IPaddress *pThis = Object_wx_IPaddress::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->Hostname();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_IPaddress, IPAddress)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_IPaddress, IPAddress)
{
	Signal &sig = env.GetSignal();
	Object_wx_IPaddress *pThis = Object_wx_IPaddress::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->IPAddress();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_IPaddress, Service)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "service", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_IPaddress, Service)
{
	Signal &sig = env.GetSignal();
	Object_wx_IPaddress *pThis = Object_wx_IPaddress::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString service = wxString::FromUTF8(arg.GetString(0));
	bool rtn = pThis->GetEntity()->Service(service);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_IPaddress, Service_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "service", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_IPaddress, Service_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_IPaddress *pThis = Object_wx_IPaddress::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned service = arg.GetInt(0);
	bool rtn = pThis->GetEntity()->Service(service);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_IPaddress, Service_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_IPaddress, Service_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_IPaddress *pThis = Object_wx_IPaddress::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned rtn = pThis->GetEntity()->Service();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_IPaddress, AnyAddress)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_IPaddress, AnyAddress)
{
	Signal &sig = env.GetSignal();
	Object_wx_IPaddress *pThis = Object_wx_IPaddress::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->AnyAddress();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_IPaddress, LocalHost)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_IPaddress, LocalHost)
{
	Signal &sig = env.GetSignal();
	Object_wx_IPaddress *pThis = Object_wx_IPaddress::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->LocalHost();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_IPaddress, IsLocalHost)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_IPaddress, IsLocalHost)
{
	Signal &sig = env.GetSignal();
	Object_wx_IPaddress *pThis = Object_wx_IPaddress::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsLocalHost();
	return ReturnValue(env, arg, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxIPaddress
//----------------------------------------------------------------------------
Object_wx_IPaddress::~Object_wx_IPaddress()
{
}

Object *Object_wx_IPaddress::Clone() const
{
	return nullptr;
}

String Object_wx_IPaddress::ToString(bool exprFlag)
{
	String rtn("<wx.IPaddress:");
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
// Class implementation for wxIPaddress
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_IPaddress)
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
	return new Object_wx_IPaddress((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
