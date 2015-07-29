//----------------------------------------------------------------------------
// wxProtocol
// extracted from protocol.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Protocol: public wxProtocol, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_Protocol *_pObj;
public:
	~wx_Protocol();
	inline void AssocWithGura(Object_wx_Protocol *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Protocol::~wx_Protocol()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_Protocol::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxProtocol
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_Protocol, Reconnect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Protocol, Reconnect)
{
	Signal &sig = env.GetSignal();
	Object_wx_Protocol *pThis = Object_wx_Protocol::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->Reconnect();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Protocol, GetInputStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "path", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Protocol, GetInputStream)
{
	Signal &sig = env.GetSignal();
	Object_wx_Protocol *pThis = Object_wx_Protocol::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString path = wxString::FromUTF8(args.GetString(0));
	wxInputStream *rtn = (wxInputStream *)pThis->GetEntity()->GetInputStream(path);
	return ReturnValue(env, args, Value(new Object_wx_InputStream(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Protocol, Abort)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Protocol, Abort)
{
	Signal &sig = env.GetSignal();
	Object_wx_Protocol *pThis = Object_wx_Protocol::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->Abort();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Protocol, GetError)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Protocol, GetError)
{
	Signal &sig = env.GetSignal();
	Object_wx_Protocol *pThis = Object_wx_Protocol::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxProtocolError rtn = pThis->GetEntity()->GetError();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Protocol, GetContentType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Protocol, GetContentType)
{
	Signal &sig = env.GetSignal();
	Object_wx_Protocol *pThis = Object_wx_Protocol::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetContentType();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_Protocol, SetUser)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "user", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Protocol, SetUser)
{
	Signal &sig = env.GetSignal();
	Object_wx_Protocol *pThis = Object_wx_Protocol::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString user = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetUser(user);
	return Value::Null;
}

Gura_DeclareMethod(wx_Protocol, SetPassword)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "user", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Protocol, SetPassword)
{
	Signal &sig = env.GetSignal();
	Object_wx_Protocol *pThis = Object_wx_Protocol::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString user = wxString::FromUTF8(args.GetString(0));
	pThis->GetEntity()->SetPassword(user);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxProtocol
//----------------------------------------------------------------------------
Object_wx_Protocol::~Object_wx_Protocol()
{
}

Object *Object_wx_Protocol::Clone() const
{
	return nullptr;
}

String Object_wx_Protocol::ToString(bool exprFlag)
{
	String rtn("<wx.Protocol:");
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
// Class implementation for wxProtocol
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Protocol)
{
	Gura_AssignMethod(wx_Protocol, Reconnect);
	Gura_AssignMethod(wx_Protocol, GetInputStream);
	Gura_AssignMethod(wx_Protocol, Abort);
	Gura_AssignMethod(wx_Protocol, GetError);
	Gura_AssignMethod(wx_Protocol, GetContentType);
	Gura_AssignMethod(wx_Protocol, SetUser);
	Gura_AssignMethod(wx_Protocol, SetPassword);
}

Gura_ImplementDescendantCreator(wx_Protocol)
{
	return new Object_wx_Protocol((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
