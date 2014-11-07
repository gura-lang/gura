//----------------------------------------------------------------------------
// wxDatagramSocket
// extracted from dgramsocket.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DatagramSocket: public wxDatagramSocket, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_DatagramSocket *_pObj;
public:
	//inline wx_DatagramSocket(wxSocketFlags flags) : wxDatagramSocket(flags), _sig(NULL), _pObj(NULL) {}
	~wx_DatagramSocket();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_DatagramSocket *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DatagramSocket::~wx_DatagramSocket()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_DatagramSocket::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDatagramSocket
//----------------------------------------------------------------------------
Gura_DeclareFunction(DatagramSocket)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_DatagramSocket));
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(DatagramSocket)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxSocketFlags flags = wxSOCKET_NONE;
	if (args.IsValid(0)) flags = static_cast<wxSocketFlags>(args.GetInt(0));
	wx_DatagramSocket *pEntity = new wx_DatagramSocket(flags);
	Object_wx_DatagramSocket *pObj = Object_wx_DatagramSocket::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_DatagramSocket(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DatagramSocket, ReceiveFrom)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "address", VTYPE_wx_SockAddress, OCCUR_Once);
	DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "nbytes", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DatagramSocket, ReceiveFrom)
{
#if 0
	Object_wx_DatagramSocket *pThis = Object_wx_DatagramSocket::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSockAddress *address = Object_wx_SockAddress::GetObject(args, 0)->GetEntity();
	int buffer = args.GetInt(1);
	wxUint32 nbytes = static_cast<wxUint32>(args.GetULong(2));
	wxDatagramSocket &rtn = pThis->GetEntity()->ReceiveFrom(*address, buffer, nbytes);
	return ReturnValue(env, sig, args, Value(new Object_wx_DatagramSocket(new wxDatagramSocket(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DatagramSocket, SendTo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "address", VTYPE_wx_SockAddress, OCCUR_Once);
	DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "nbytes", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DatagramSocket, SendTo)
{
#if 0
	Object_wx_DatagramSocket *pThis = Object_wx_DatagramSocket::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSockAddress *address = Object_wx_SockAddress::GetObject(args, 0)->GetEntity();
	int buffer = args.GetInt(1);
	wxUint32 nbytes = static_cast<wxUint32>(args.GetULong(2));
	wxDatagramSocket &rtn = pThis->GetEntity()->SendTo(*address, buffer, nbytes);
	return ReturnValue(env, sig, args, Value(new Object_wx_DatagramSocket(new wxDatagramSocket(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxDatagramSocket
//----------------------------------------------------------------------------
Object_wx_DatagramSocket::~Object_wx_DatagramSocket()
{
}

Object *Object_wx_DatagramSocket::Clone() const
{
	return NULL;
}

String Object_wx_DatagramSocket::ToString(bool exprFlag)
{
	String rtn("<wx.DatagramSocket:");
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
// Class implementation for wxDatagramSocket
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DatagramSocket)
{
	Gura_AssignFunction(DatagramSocket);
	Gura_AssignMethod(wx_DatagramSocket, ReceiveFrom);
	Gura_AssignMethod(wx_DatagramSocket, SendTo);
}

Gura_ImplementDescendantCreator(wx_DatagramSocket)
{
	return new Object_wx_DatagramSocket((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
