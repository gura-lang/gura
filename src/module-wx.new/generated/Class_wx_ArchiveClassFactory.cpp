//----------------------------------------------------------------------------
// wxArchiveClassFactory
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxArchiveClassFactory
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxArchiveClassFactory
//----------------------------------------------------------------------------
Object_wx_ArchiveClassFactory::~Object_wx_ArchiveClassFactory()
{
}

Object *Object_wx_ArchiveClassFactory::Clone() const
{
	return nullptr;
}

String Object_wx_ArchiveClassFactory::ToString(bool exprFlag)
{
	String rtn("<wx.ArchiveClassFactory:");
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
Gura_DeclareMethod(wx_ArchiveClassFactory, CanHandle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "protocol", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArchiveClassFactory, CanHandle)
{
	Signal &sig = env.GetSignal();
	Object_wx_ArchiveClassFactory *pThis = Object_wx_ArchiveClassFactory::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int protocol = arg.GetNumber(0)
	//int type = arg.GetNumber(1)
	//pThis->GetEntity()->CanHandle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArchiveClassFactory, Find)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "protocol", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArchiveClassFactory, Find)
{
	Signal &sig = env.GetSignal();
	Object_wx_ArchiveClassFactory *pThis = Object_wx_ArchiveClassFactory::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int protocol = arg.GetNumber(0)
	//int type = arg.GetNumber(1)
	//pThis->GetEntity()->Find();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArchiveClassFactory, GetConv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ArchiveClassFactory, GetConv)
{
	Signal &sig = env.GetSignal();
	Object_wx_ArchiveClassFactory *pThis = Object_wx_ArchiveClassFactory::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetConv();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArchiveClassFactory, SetConv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArchiveClassFactory, SetConv)
{
	Signal &sig = env.GetSignal();
	Object_wx_ArchiveClassFactory *pThis = Object_wx_ArchiveClassFactory::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int conv = arg.GetNumber(0)
	//pThis->GetEntity()->SetConv();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArchiveClassFactory, GetFirst)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ArchiveClassFactory, GetFirst)
{
	Signal &sig = env.GetSignal();
	Object_wx_ArchiveClassFactory *pThis = Object_wx_ArchiveClassFactory::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFirst();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArchiveClassFactory, GetNext)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ArchiveClassFactory, GetNext)
{
	Signal &sig = env.GetSignal();
	Object_wx_ArchiveClassFactory *pThis = Object_wx_ArchiveClassFactory::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetNext();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArchiveClassFactory, GetInternalName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArchiveClassFactory, GetInternalName)
{
	Signal &sig = env.GetSignal();
	Object_wx_ArchiveClassFactory *pThis = Object_wx_ArchiveClassFactory::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int format = arg.GetNumber(1)
	//pThis->GetEntity()->GetInternalName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArchiveClassFactory, GetProtocol)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ArchiveClassFactory, GetProtocol)
{
	Signal &sig = env.GetSignal();
	Object_wx_ArchiveClassFactory *pThis = Object_wx_ArchiveClassFactory::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetProtocol();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArchiveClassFactory, GetProtocols)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArchiveClassFactory, GetProtocols)
{
	Signal &sig = env.GetSignal();
	Object_wx_ArchiveClassFactory *pThis = Object_wx_ArchiveClassFactory::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int type = arg.GetNumber(0)
	//pThis->GetEntity()->GetProtocols();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArchiveClassFactory, NewEntry)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ArchiveClassFactory, NewEntry)
{
	Signal &sig = env.GetSignal();
	Object_wx_ArchiveClassFactory *pThis = Object_wx_ArchiveClassFactory::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->NewEntry();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArchiveClassFactory, NewStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArchiveClassFactory, NewStream)
{
	Signal &sig = env.GetSignal();
	Object_wx_ArchiveClassFactory *pThis = Object_wx_ArchiveClassFactory::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//pThis->GetEntity()->NewStream();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArchiveClassFactory, NewStream_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArchiveClassFactory, NewStream_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_ArchiveClassFactory *pThis = Object_wx_ArchiveClassFactory::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//pThis->GetEntity()->NewStream();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArchiveClassFactory, NewStream_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArchiveClassFactory, NewStream_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_ArchiveClassFactory *pThis = Object_wx_ArchiveClassFactory::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//pThis->GetEntity()->NewStream();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArchiveClassFactory, NewStream_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArchiveClassFactory, NewStream_3)
{
	Signal &sig = env.GetSignal();
	Object_wx_ArchiveClassFactory *pThis = Object_wx_ArchiveClassFactory::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//pThis->GetEntity()->NewStream();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArchiveClassFactory, PushFront)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ArchiveClassFactory, PushFront)
{
	Signal &sig = env.GetSignal();
	Object_wx_ArchiveClassFactory *pThis = Object_wx_ArchiveClassFactory::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->PushFront();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArchiveClassFactory, Remove)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ArchiveClassFactory, Remove)
{
	Signal &sig = env.GetSignal();
	Object_wx_ArchiveClassFactory *pThis = Object_wx_ArchiveClassFactory::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Remove();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxArchiveClassFactory
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ArchiveClassFactory)
{
	Gura_AssignMethod(wx_ArchiveClassFactory, CanHandle);
	Gura_AssignMethod(wx_ArchiveClassFactory, Find);
	Gura_AssignMethod(wx_ArchiveClassFactory, GetConv);
	Gura_AssignMethod(wx_ArchiveClassFactory, SetConv);
	Gura_AssignMethod(wx_ArchiveClassFactory, GetFirst);
	Gura_AssignMethod(wx_ArchiveClassFactory, GetNext);
	Gura_AssignMethod(wx_ArchiveClassFactory, GetInternalName);
	Gura_AssignMethod(wx_ArchiveClassFactory, GetProtocol);
	Gura_AssignMethod(wx_ArchiveClassFactory, GetProtocols);
	Gura_AssignMethod(wx_ArchiveClassFactory, NewEntry);
	Gura_AssignMethod(wx_ArchiveClassFactory, NewStream);
	Gura_AssignMethod(wx_ArchiveClassFactory, NewStream_1);
	Gura_AssignMethod(wx_ArchiveClassFactory, NewStream_2);
	Gura_AssignMethod(wx_ArchiveClassFactory, NewStream_3);
	Gura_AssignMethod(wx_ArchiveClassFactory, PushFront);
	Gura_AssignMethod(wx_ArchiveClassFactory, Remove);
}

Gura_ImplementDescendantCreator(wx_ArchiveClassFactory)
{
	return new Object_wx_ArchiveClassFactory((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
