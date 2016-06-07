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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__ClientDataContainer, "ClientDataContainer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_ClientDataContainer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__ClientDataContainer)
{
	//wxClientDataContainer();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_ClientDataContainer, __GetClientData, "GetClientData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ClientDataContainer, __GetClientData)
{
	Object_wx_ClientDataContainer *pThis = Object_wx_ClientDataContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetClientData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ClientDataContainer, __GetClientObject, "GetClientObject")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ClientDataContainer, __GetClientObject)
{
	Object_wx_ClientDataContainer *pThis = Object_wx_ClientDataContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetClientObject();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ClientDataContainer, __SetClientData, "SetClientData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ClientDataContainer, __SetClientData)
{
	Object_wx_ClientDataContainer *pThis = Object_wx_ClientDataContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//void* data = arg.GetNumber(0)
	//pThis->GetEntity()->SetClientData(data);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ClientDataContainer, __SetClientObject, "SetClientObject")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ClientDataContainer, __SetClientObject)
{
	Object_wx_ClientDataContainer *pThis = Object_wx_ClientDataContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxClientData* data = arg.GetNumber(0)
	//pThis->GetEntity()->SetClientObject(data);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxClientDataContainer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ClientDataContainer)
{
	// Constructor assignment
	Gura_AssignFunction(__ClientDataContainer);
	// Method assignment
	Gura_AssignMethod(wx_ClientDataContainer, __GetClientData);
	Gura_AssignMethod(wx_ClientDataContainer, __GetClientObject);
	Gura_AssignMethod(wx_ClientDataContainer, __SetClientData);
	Gura_AssignMethod(wx_ClientDataContainer, __SetClientObject);
}

Gura_ImplementDescendantCreator(wx_ClientDataContainer)
{
	return new Object_wx_ClientDataContainer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
