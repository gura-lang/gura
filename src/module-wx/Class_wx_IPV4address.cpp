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
	//Gura::Signal *_pSig;
	Object_wx_IPV4address *_pObj;
public:
	~wx_IPV4address();
	inline void AssocWithGura(Object_wx_IPV4address *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_IPV4address::~wx_IPV4address()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_IPV4address::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxIPV4address
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_IPV4address, Hostname)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "hostname", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_IPV4address, Hostname)
{
	Signal &sig = env.GetSignal();
	Object_wx_IPV4address *pThis = Object_wx_IPV4address::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString hostname = wxString::FromUTF8(arg.GetString(0));
	bool rtn = pThis->GetEntity()->Hostname(hostname);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_IPV4address, Hostname_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_IPV4address, Hostname_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_IPV4address *pThis = Object_wx_IPV4address::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->Hostname();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_IPV4address, IPAddress)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_IPV4address, IPAddress)
{
	Signal &sig = env.GetSignal();
	Object_wx_IPV4address *pThis = Object_wx_IPV4address::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->IPAddress();
	return ReturnValue(env, arg, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_IPV4address, Service)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "service", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_IPV4address, Service)
{
	Signal &sig = env.GetSignal();
	Object_wx_IPV4address *pThis = Object_wx_IPV4address::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString service = wxString::FromUTF8(arg.GetString(0));
	bool rtn = pThis->GetEntity()->Service(service);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_IPV4address, Service_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "service", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_IPV4address, Service_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_IPV4address *pThis = Object_wx_IPV4address::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned service = arg.GetInt(0);
	bool rtn = pThis->GetEntity()->Service(service);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_IPV4address, Service_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_IPV4address, Service_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_IPV4address *pThis = Object_wx_IPV4address::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	unsigned rtn = pThis->GetEntity()->Service();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_IPV4address, AnyAddress)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_IPV4address, AnyAddress)
{
	Signal &sig = env.GetSignal();
	Object_wx_IPV4address *pThis = Object_wx_IPV4address::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->AnyAddress();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_IPV4address, LocalHost)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_IPV4address, LocalHost)
{
	Signal &sig = env.GetSignal();
	Object_wx_IPV4address *pThis = Object_wx_IPV4address::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->LocalHost();
	return ReturnValue(env, arg, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxIPV4address
//----------------------------------------------------------------------------
Object_wx_IPV4address::~Object_wx_IPV4address()
{
}

Object *Object_wx_IPV4address::Clone() const
{
	return nullptr;
}

String Object_wx_IPV4address::ToString(bool exprFlag)
{
	String rtn("<wx.IPV4address:");
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
	return new Object_wx_IPV4address((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
