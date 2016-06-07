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
Gura_DeclareMethodAlias(wx_FilterClassFactory, __CanHandle, "CanHandle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "protocol", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FilterClassFactory, __CanHandle)
{
	Object_wx_FilterClassFactory *pThis = Object_wx_FilterClassFactory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& protocol = arg.GetNumber(0)
	//wxStreamProtocolType type = arg.GetNumber(1)
	//pThis->GetEntity()->CanHandle(protocol, type);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FilterClassFactory, __Find, "Find")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "protocol", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FilterClassFactory, __Find)
{
	Object_wx_FilterClassFactory *pThis = Object_wx_FilterClassFactory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& protocol = arg.GetNumber(0)
	//wxStreamProtocolType type = arg.GetNumber(1)
	//pThis->GetEntity()->Find(protocol, type);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FilterClassFactory, __GetFirst, "GetFirst")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FilterClassFactory, __GetFirst)
{
	Object_wx_FilterClassFactory *pThis = Object_wx_FilterClassFactory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFirst();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FilterClassFactory, __GetNext, "GetNext")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FilterClassFactory, __GetNext)
{
	Object_wx_FilterClassFactory *pThis = Object_wx_FilterClassFactory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetNext();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FilterClassFactory, __GetProtocol, "GetProtocol")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FilterClassFactory, __GetProtocol)
{
	Object_wx_FilterClassFactory *pThis = Object_wx_FilterClassFactory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetProtocol();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FilterClassFactory, __GetProtocols, "GetProtocols")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FilterClassFactory, __GetProtocols)
{
	Object_wx_FilterClassFactory *pThis = Object_wx_FilterClassFactory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxStreamProtocolType type = arg.GetNumber(0)
	//pThis->GetEntity()->GetProtocols(type);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FilterClassFactory, __NewStream, "NewStream")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FilterClassFactory, __NewStream)
{
	Object_wx_FilterClassFactory *pThis = Object_wx_FilterClassFactory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxInputStream& stream = arg.GetNumber(0)
	//pThis->GetEntity()->NewStream(stream);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FilterClassFactory, __NewStream_1, "NewStream_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FilterClassFactory, __NewStream_1)
{
	Object_wx_FilterClassFactory *pThis = Object_wx_FilterClassFactory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxOutputStream& stream = arg.GetNumber(0)
	//pThis->GetEntity()->NewStream(stream);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FilterClassFactory, __NewStream_2, "NewStream_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FilterClassFactory, __NewStream_2)
{
	Object_wx_FilterClassFactory *pThis = Object_wx_FilterClassFactory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxInputStream* stream = arg.GetNumber(0)
	//pThis->GetEntity()->NewStream(stream);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FilterClassFactory, __NewStream_3, "NewStream_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FilterClassFactory, __NewStream_3)
{
	Object_wx_FilterClassFactory *pThis = Object_wx_FilterClassFactory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxOutputStream* stream = arg.GetNumber(0)
	//pThis->GetEntity()->NewStream(stream);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FilterClassFactory, __PopExtension, "PopExtension")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "location", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FilterClassFactory, __PopExtension)
{
	Object_wx_FilterClassFactory *pThis = Object_wx_FilterClassFactory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& location = arg.GetNumber(0)
	//pThis->GetEntity()->PopExtension(location);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FilterClassFactory, __PushFront, "PushFront")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FilterClassFactory, __PushFront)
{
	Object_wx_FilterClassFactory *pThis = Object_wx_FilterClassFactory::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->PushFront();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FilterClassFactory, __Remove, "Remove")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FilterClassFactory, __Remove)
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
	// Class assignment
	Gura_AssignValueEx("FilterClassFactory", Reference());
	// Method assignment
	Gura_AssignMethod(wx_FilterClassFactory, __CanHandle);
	Gura_AssignMethod(wx_FilterClassFactory, __Find);
	Gura_AssignMethod(wx_FilterClassFactory, __GetFirst);
	Gura_AssignMethod(wx_FilterClassFactory, __GetNext);
	Gura_AssignMethod(wx_FilterClassFactory, __GetProtocol);
	Gura_AssignMethod(wx_FilterClassFactory, __GetProtocols);
	Gura_AssignMethod(wx_FilterClassFactory, __NewStream);
	Gura_AssignMethod(wx_FilterClassFactory, __NewStream_1);
	Gura_AssignMethod(wx_FilterClassFactory, __NewStream_2);
	Gura_AssignMethod(wx_FilterClassFactory, __NewStream_3);
	Gura_AssignMethod(wx_FilterClassFactory, __PopExtension);
	Gura_AssignMethod(wx_FilterClassFactory, __PushFront);
	Gura_AssignMethod(wx_FilterClassFactory, __Remove);
}

Gura_ImplementDescendantCreator(wx_FilterClassFactory)
{
	return new Object_wx_FilterClassFactory((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
