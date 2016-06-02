//----------------------------------------------------------------------------
// wxFilterClassFactory
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFilterClassFactory
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFilterClassFactory
//----------------------------------------------------------------------------
Object_wx_FilterClassFactory::~Object_wx_FilterClassFactory()
{
}

Object *Object_wx_FilterClassFactory::Clone() const
{
	return nullptr;
}

String Object_wx_FilterClassFactory::ToString(bool exprFlag)
{
	String rtn("<wx.FilterClassFactory:");
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
Gura_DeclareMethod(wx_FilterClassFactory, CanHandle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "protocol", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FilterClassFactory, CanHandle)
{
	Object_wx_FilterClassFactory *pThis = Object_wx_FilterClassFactory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int protocol = arg.GetNumber(0)
	//int type = arg.GetNumber(1)
	//pThis->GetEntity()->CanHandle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FilterClassFactory, Find)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "protocol", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FilterClassFactory, Find)
{
	Object_wx_FilterClassFactory *pThis = Object_wx_FilterClassFactory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int protocol = arg.GetNumber(0)
	//int type = arg.GetNumber(1)
	//pThis->GetEntity()->Find();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FilterClassFactory, GetFirst)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FilterClassFactory, GetFirst)
{
	Object_wx_FilterClassFactory *pThis = Object_wx_FilterClassFactory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFirst();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FilterClassFactory, GetNext)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FilterClassFactory, GetNext)
{
	Object_wx_FilterClassFactory *pThis = Object_wx_FilterClassFactory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetNext();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FilterClassFactory, GetProtocol)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FilterClassFactory, GetProtocol)
{
	Object_wx_FilterClassFactory *pThis = Object_wx_FilterClassFactory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetProtocol();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FilterClassFactory, GetProtocols)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FilterClassFactory, GetProtocols)
{
	Object_wx_FilterClassFactory *pThis = Object_wx_FilterClassFactory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int type = arg.GetNumber(0)
	//pThis->GetEntity()->GetProtocols();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FilterClassFactory, NewStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FilterClassFactory, NewStream)
{
	Object_wx_FilterClassFactory *pThis = Object_wx_FilterClassFactory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//pThis->GetEntity()->NewStream();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FilterClassFactory, NewStream_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FilterClassFactory, NewStream_1)
{
	Object_wx_FilterClassFactory *pThis = Object_wx_FilterClassFactory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//pThis->GetEntity()->NewStream();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FilterClassFactory, NewStream_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FilterClassFactory, NewStream_2)
{
	Object_wx_FilterClassFactory *pThis = Object_wx_FilterClassFactory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//pThis->GetEntity()->NewStream();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FilterClassFactory, NewStream_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FilterClassFactory, NewStream_3)
{
	Object_wx_FilterClassFactory *pThis = Object_wx_FilterClassFactory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//pThis->GetEntity()->NewStream();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FilterClassFactory, PopExtension)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "location", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FilterClassFactory, PopExtension)
{
	Object_wx_FilterClassFactory *pThis = Object_wx_FilterClassFactory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int location = arg.GetNumber(0)
	//pThis->GetEntity()->PopExtension();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FilterClassFactory, PushFront)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FilterClassFactory, PushFront)
{
	Object_wx_FilterClassFactory *pThis = Object_wx_FilterClassFactory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->PushFront();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FilterClassFactory, Remove)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FilterClassFactory, Remove)
{
	Object_wx_FilterClassFactory *pThis = Object_wx_FilterClassFactory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Remove();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFilterClassFactory
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FilterClassFactory)
{
	Gura_AssignMethod(wx_FilterClassFactory, CanHandle);
	Gura_AssignMethod(wx_FilterClassFactory, Find);
	Gura_AssignMethod(wx_FilterClassFactory, GetFirst);
	Gura_AssignMethod(wx_FilterClassFactory, GetNext);
	Gura_AssignMethod(wx_FilterClassFactory, GetProtocol);
	Gura_AssignMethod(wx_FilterClassFactory, GetProtocols);
	Gura_AssignMethod(wx_FilterClassFactory, NewStream);
	Gura_AssignMethod(wx_FilterClassFactory, NewStream_1);
	Gura_AssignMethod(wx_FilterClassFactory, NewStream_2);
	Gura_AssignMethod(wx_FilterClassFactory, NewStream_3);
	Gura_AssignMethod(wx_FilterClassFactory, PopExtension);
	Gura_AssignMethod(wx_FilterClassFactory, PushFront);
	Gura_AssignMethod(wx_FilterClassFactory, Remove);
}

Gura_ImplementDescendantCreator(wx_FilterClassFactory)
{
	return new Object_wx_FilterClassFactory((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
