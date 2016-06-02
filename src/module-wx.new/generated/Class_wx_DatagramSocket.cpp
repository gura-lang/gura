//----------------------------------------------------------------------------
// wxDatagramSocket
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDatagramSocket
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDatagramSocket
//----------------------------------------------------------------------------
Object_wx_DatagramSocket::~Object_wx_DatagramSocket()
{
}

Object *Object_wx_DatagramSocket::Clone() const
{
	return nullptr;
}

String Object_wx_DatagramSocket::ToString(bool exprFlag)
{
	String rtn("<wx.DatagramSocket:");
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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_DatagramSocket, wxDatagramSocket)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "addr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DatagramSocket, wxDatagramSocket)
{
	Object_wx_DatagramSocket *pThis = Object_wx_DatagramSocket::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int addr = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->wxDatagramSocket();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DatagramSocket, SendTo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "address", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nbytes", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DatagramSocket, SendTo)
{
	Object_wx_DatagramSocket *pThis = Object_wx_DatagramSocket::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int address = arg.GetNumber(0)
	//int buffer = arg.GetNumber(1)
	//int nbytes = arg.GetNumber(2)
	//pThis->GetEntity()->SendTo();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDatagramSocket
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DatagramSocket)
{
	Gura_AssignMethod(wx_DatagramSocket, wxDatagramSocket);
	Gura_AssignMethod(wx_DatagramSocket, SendTo);
}

Gura_ImplementDescendantCreator(wx_DatagramSocket)
{
	return new Object_wx_DatagramSocket((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
