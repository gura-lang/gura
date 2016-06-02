//----------------------------------------------------------------------------
// wxItemContainer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxItemContainer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxItemContainer
//----------------------------------------------------------------------------
Object_wx_ItemContainer::~Object_wx_ItemContainer()
{
}

Object *Object_wx_ItemContainer::Clone() const
{
	return nullptr;
}

String Object_wx_ItemContainer::ToString(bool exprFlag)
{
	String rtn("<wx.ItemContainer:");
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
Gura_DeclareMethod(wx_ItemContainer, Append)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, Append)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->Append();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ItemContainer, Append_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, Append_1)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int clientData = arg.GetNumber(1)
	//pThis->GetEntity()->Append();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ItemContainer, Append_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, Append_2)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int clientData = arg.GetNumber(1)
	//pThis->GetEntity()->Append();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ItemContainer, Append_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, Append_3)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int items = arg.GetNumber(0)
	//pThis->GetEntity()->Append();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ItemContainer, Append_4)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, Append_4)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int items = arg.GetNumber(0)
	//pThis->GetEntity()->Append();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ItemContainer, Append_5)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, Append_5)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int items = arg.GetNumber(0)
	//int clientData = arg.GetNumber(1)
	//pThis->GetEntity()->Append();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ItemContainer, Append_6)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, Append_6)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int items = arg.GetNumber(0)
	//int clientData = arg.GetNumber(1)
	//pThis->GetEntity()->Append();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ItemContainer, Append_7)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, Append_7)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//int items = arg.GetNumber(1)
	//pThis->GetEntity()->Append();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ItemContainer, Append_8)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, Append_8)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//int items = arg.GetNumber(1)
	//int clientData = arg.GetNumber(2)
	//pThis->GetEntity()->Append();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ItemContainer, Append_9)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, Append_9)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//int items = arg.GetNumber(1)
	//int clientData = arg.GetNumber(2)
	//pThis->GetEntity()->Append();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ItemContainer, Clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ItemContainer, Clear)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ItemContainer, Delete)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, Delete)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->Delete();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ItemContainer, DetachClientObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, DetachClientObject)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->DetachClientObject();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ItemContainer, HasClientData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ItemContainer, HasClientData)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasClientData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ItemContainer, HasClientObjectData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ItemContainer, HasClientObjectData)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasClientObjectData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ItemContainer, HasClientUntypedData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ItemContainer, HasClientUntypedData)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasClientUntypedData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ItemContainer, GetClientData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, GetClientData)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->GetClientData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ItemContainer, GetClientObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, GetClientObject)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->GetClientObject();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ItemContainer, SetClientData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, SetClientData)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->SetClientData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ItemContainer, SetClientObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, SetClientObject)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->SetClientObject();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ItemContainer, Insert)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, Insert)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//pThis->GetEntity()->Insert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ItemContainer, Insert_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, Insert_1)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//int clientData = arg.GetNumber(2)
	//pThis->GetEntity()->Insert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ItemContainer, Insert_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, Insert_2)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//int clientData = arg.GetNumber(2)
	//pThis->GetEntity()->Insert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ItemContainer, Insert_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, Insert_3)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int items = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//pThis->GetEntity()->Insert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ItemContainer, Insert_4)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, Insert_4)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int items = arg.GetNumber(0)
	//pThis->GetEntity()->Insert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ItemContainer, Insert_5)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, Insert_5)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int items = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//int clientData = arg.GetNumber(2)
	//pThis->GetEntity()->Insert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ItemContainer, Insert_6)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, Insert_6)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int items = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//int clientData = arg.GetNumber(2)
	//pThis->GetEntity()->Insert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ItemContainer, Insert_7)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, Insert_7)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//int items = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//pThis->GetEntity()->Insert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ItemContainer, Insert_8)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, Insert_8)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//int items = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int clientData = arg.GetNumber(3)
	//pThis->GetEntity()->Insert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ItemContainer, Insert_9)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, Insert_9)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//int items = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int clientData = arg.GetNumber(3)
	//pThis->GetEntity()->Insert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ItemContainer, Set)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, Set)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int items = arg.GetNumber(0)
	//pThis->GetEntity()->Set();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ItemContainer, Set_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, Set_1)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int items = arg.GetNumber(0)
	//pThis->GetEntity()->Set();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ItemContainer, Set_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, Set_2)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int items = arg.GetNumber(0)
	//int clientData = arg.GetNumber(1)
	//pThis->GetEntity()->Set();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ItemContainer, Set_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, Set_3)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int items = arg.GetNumber(0)
	//int clientData = arg.GetNumber(1)
	//pThis->GetEntity()->Set();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ItemContainer, Set_4)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, Set_4)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//int items = arg.GetNumber(1)
	//pThis->GetEntity()->Set();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ItemContainer, Set_5)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, Set_5)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//int items = arg.GetNumber(1)
	//int clientData = arg.GetNumber(2)
	//pThis->GetEntity()->Set();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ItemContainer, Set_6)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, Set_6)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//int items = arg.GetNumber(1)
	//int clientData = arg.GetNumber(2)
	//pThis->GetEntity()->Set();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxItemContainer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ItemContainer)
{
	Gura_AssignMethod(wx_ItemContainer, Append);
	Gura_AssignMethod(wx_ItemContainer, Append_1);
	Gura_AssignMethod(wx_ItemContainer, Append_2);
	Gura_AssignMethod(wx_ItemContainer, Append_3);
	Gura_AssignMethod(wx_ItemContainer, Append_4);
	Gura_AssignMethod(wx_ItemContainer, Append_5);
	Gura_AssignMethod(wx_ItemContainer, Append_6);
	Gura_AssignMethod(wx_ItemContainer, Append_7);
	Gura_AssignMethod(wx_ItemContainer, Append_8);
	Gura_AssignMethod(wx_ItemContainer, Append_9);
	Gura_AssignMethod(wx_ItemContainer, Clear);
	Gura_AssignMethod(wx_ItemContainer, Delete);
	Gura_AssignMethod(wx_ItemContainer, DetachClientObject);
	Gura_AssignMethod(wx_ItemContainer, HasClientData);
	Gura_AssignMethod(wx_ItemContainer, HasClientObjectData);
	Gura_AssignMethod(wx_ItemContainer, HasClientUntypedData);
	Gura_AssignMethod(wx_ItemContainer, GetClientData);
	Gura_AssignMethod(wx_ItemContainer, GetClientObject);
	Gura_AssignMethod(wx_ItemContainer, SetClientData);
	Gura_AssignMethod(wx_ItemContainer, SetClientObject);
	Gura_AssignMethod(wx_ItemContainer, Insert);
	Gura_AssignMethod(wx_ItemContainer, Insert_1);
	Gura_AssignMethod(wx_ItemContainer, Insert_2);
	Gura_AssignMethod(wx_ItemContainer, Insert_3);
	Gura_AssignMethod(wx_ItemContainer, Insert_4);
	Gura_AssignMethod(wx_ItemContainer, Insert_5);
	Gura_AssignMethod(wx_ItemContainer, Insert_6);
	Gura_AssignMethod(wx_ItemContainer, Insert_7);
	Gura_AssignMethod(wx_ItemContainer, Insert_8);
	Gura_AssignMethod(wx_ItemContainer, Insert_9);
	Gura_AssignMethod(wx_ItemContainer, Set);
	Gura_AssignMethod(wx_ItemContainer, Set_1);
	Gura_AssignMethod(wx_ItemContainer, Set_2);
	Gura_AssignMethod(wx_ItemContainer, Set_3);
	Gura_AssignMethod(wx_ItemContainer, Set_4);
	Gura_AssignMethod(wx_ItemContainer, Set_5);
	Gura_AssignMethod(wx_ItemContainer, Set_6);
}

Gura_ImplementDescendantCreator(wx_ItemContainer)
{
	return new Object_wx_ItemContainer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
