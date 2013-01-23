//----------------------------------------------------------------------------
// wxSocketEvent
// extracted from socket.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_SocketEvent: public wxSocketEvent, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_SocketEvent *_pObj;
public:
	inline wx_SocketEvent(int id) : wxSocketEvent(id), _sig(NULL), _pObj(NULL) {}
	~wx_SocketEvent();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_SocketEvent *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_SocketEvent::~wx_SocketEvent()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_SocketEvent::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxSocketEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(SocketEvent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_SocketEvent));
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(SocketEvent)
{
	if (!CheckWxReady(sig)) return Value::Null;
	int id = 0;
	if (args.IsValid(0)) id = args.GetInt(0);
	wx_SocketEvent *pEntity = new wx_SocketEvent(id);
	Object_wx_SocketEvent *pObj = Object_wx_SocketEvent::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_SocketEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_SocketEvent, GetClientData)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SocketEvent, GetClientData)
{
	Object_wx_SocketEvent *pSelf = Object_wx_SocketEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->GetClientData();
	return Value::Null;
}

Gura_DeclareMethod(wx_SocketEvent, GetSocket)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SocketEvent, GetSocket)
{
	Object_wx_SocketEvent *pSelf = Object_wx_SocketEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxSocketBase *rtn = (wxSocketBase *)pSelf->GetEntity()->GetSocket();
	return ReturnValue(env, sig, args, Value(new Object_wx_SocketBase(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_SocketEvent, GetSocketEvent)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SocketEvent, GetSocketEvent)
{
#if 0
	Object_wx_SocketEvent *pSelf = Object_wx_SocketEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxSocketNotify rtn = pSelf->GetEntity()->GetSocketEvent();
	return ReturnValue(env, sig, args, Value(new Object_wx_SocketNotify(new wxSocketNotify(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxSocketEvent
//----------------------------------------------------------------------------
Object_wx_SocketEvent::~Object_wx_SocketEvent()
{
}

Object *Object_wx_SocketEvent::Clone() const
{
	return NULL;
}

String Object_wx_SocketEvent::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.SocketEvent:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_SocketEvent::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(SocketEvent);
}

//----------------------------------------------------------------------------
// Class implementation for wxSocketEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SocketEvent)
{
	Gura_AssignMethod(wx_SocketEvent, GetClientData);
	Gura_AssignMethod(wx_SocketEvent, GetSocket);
	Gura_AssignMethod(wx_SocketEvent, GetSocketEvent);
}

Gura_ImplementDescendantCreator(wx_SocketEvent)
{
	return new Object_wx_SocketEvent((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
