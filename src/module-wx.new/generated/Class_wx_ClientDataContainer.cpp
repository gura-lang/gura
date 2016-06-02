//----------------------------------------------------------------------------
// wxClientDataContainer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxClientDataContainer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxClientDataContainer
//----------------------------------------------------------------------------
Object_wx_ClientDataContainer::~Object_wx_ClientDataContainer()
{
}

Object *Object_wx_ClientDataContainer::Clone() const
{
	return nullptr;
}

String Object_wx_ClientDataContainer::ToString(bool exprFlag)
{
	String rtn("<wx.ClientDataContainer:");
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
Gura_DeclareMethod(wx_ClientDataContainer, wxClientDataContainer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ClientDataContainer, wxClientDataContainer)
{
	Object_wx_ClientDataContainer *pThis = Object_wx_ClientDataContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxClientDataContainer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ClientDataContainer, GetClientData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ClientDataContainer, GetClientData)
{
	Object_wx_ClientDataContainer *pThis = Object_wx_ClientDataContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetClientData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ClientDataContainer, GetClientObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ClientDataContainer, GetClientObject)
{
	Object_wx_ClientDataContainer *pThis = Object_wx_ClientDataContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetClientObject();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ClientDataContainer, SetClientData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ClientDataContainer, SetClientData)
{
	Object_wx_ClientDataContainer *pThis = Object_wx_ClientDataContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->SetClientData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ClientDataContainer, SetClientObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ClientDataContainer, SetClientObject)
{
	Object_wx_ClientDataContainer *pThis = Object_wx_ClientDataContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->SetClientObject();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxClientDataContainer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ClientDataContainer)
{
	Gura_AssignMethod(wx_ClientDataContainer, wxClientDataContainer);
	Gura_AssignMethod(wx_ClientDataContainer, GetClientData);
	Gura_AssignMethod(wx_ClientDataContainer, GetClientObject);
	Gura_AssignMethod(wx_ClientDataContainer, SetClientData);
	Gura_AssignMethod(wx_ClientDataContainer, SetClientObject);
}

Gura_ImplementDescendantCreator(wx_ClientDataContainer)
{
	return new Object_wx_ClientDataContainer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
