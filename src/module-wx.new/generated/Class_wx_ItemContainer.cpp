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
Gura_DeclareMethodAlias(wx_ItemContainer, __Append, "Append")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, __Append)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& item = arg.GetNumber(0)
	//int _rtn = pThis->GetEntity()->Append(item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ItemContainer, __Append_1, "Append_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, __Append_1)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& item = arg.GetNumber(0)
	//void* clientData = arg.GetNumber(1)
	//int _rtn = pThis->GetEntity()->Append(item, clientData);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ItemContainer, __Append_2, "Append_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, __Append_2)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& item = arg.GetNumber(0)
	//wxClientData* clientData = arg.GetNumber(1)
	//int _rtn = pThis->GetEntity()->Append(item, clientData);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ItemContainer, __Append_3, "Append_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, __Append_3)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxArrayString& items = arg.GetNumber(0)
	//int _rtn = pThis->GetEntity()->Append(items);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ItemContainer, __Append_4, "Append_4")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, __Append_4)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const std::vector<T>& items = arg.GetNumber(0)
	//int _rtn = pThis->GetEntity()->Append(items);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ItemContainer, __Append_5, "Append_5")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, __Append_5)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxArrayString& items = arg.GetNumber(0)
	//void** clientData = arg.GetNumber(1)
	//int _rtn = pThis->GetEntity()->Append(items, clientData);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ItemContainer, __Append_6, "Append_6")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, __Append_6)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxArrayString& items = arg.GetNumber(0)
	//wxClientData** clientData = arg.GetNumber(1)
	//int _rtn = pThis->GetEntity()->Append(items, clientData);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ItemContainer, __Append_7, "Append_7")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, __Append_7)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int n = arg.GetNumber(0)
	//const wxString* items = arg.GetNumber(1)
	//int _rtn = pThis->GetEntity()->Append(n, items);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ItemContainer, __Append_8, "Append_8")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, __Append_8)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int n = arg.GetNumber(0)
	//const wxString* items = arg.GetNumber(1)
	//void** clientData = arg.GetNumber(2)
	//int _rtn = pThis->GetEntity()->Append(n, items, clientData);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ItemContainer, __Append_9, "Append_9")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, __Append_9)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int n = arg.GetNumber(0)
	//const wxString* items = arg.GetNumber(1)
	//wxClientData** clientData = arg.GetNumber(2)
	//int _rtn = pThis->GetEntity()->Append(n, items, clientData);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ItemContainer, __Clear, "Clear")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ItemContainer, __Clear)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ItemContainer, __Delete, "Delete")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, __Delete)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int n = arg.GetNumber(0)
	//pThis->GetEntity()->Delete(n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ItemContainer, __DetachClientObject, "DetachClientObject")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, __DetachClientObject)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int n = arg.GetNumber(0)
	//wxClientData* _rtn = pThis->GetEntity()->DetachClientObject(n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ItemContainer, __HasClientData, "HasClientData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ItemContainer, __HasClientData)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasClientData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ItemContainer, __HasClientObjectData, "HasClientObjectData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ItemContainer, __HasClientObjectData)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasClientObjectData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ItemContainer, __HasClientUntypedData, "HasClientUntypedData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_ItemContainer, __HasClientUntypedData)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasClientUntypedData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ItemContainer, __GetClientData, "GetClientData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, __GetClientData)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int n = arg.GetNumber(0)
	//void* _rtn = pThis->GetEntity()->GetClientData(n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ItemContainer, __GetClientObject, "GetClientObject")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, __GetClientObject)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int n = arg.GetNumber(0)
	//wxClientData* _rtn = pThis->GetEntity()->GetClientObject(n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ItemContainer, __SetClientData, "SetClientData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, __SetClientData)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int n = arg.GetNumber(0)
	//void* data = arg.GetNumber(1)
	//pThis->GetEntity()->SetClientData(n, data);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ItemContainer, __SetClientObject, "SetClientObject")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, __SetClientObject)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int n = arg.GetNumber(0)
	//wxClientData* data = arg.GetNumber(1)
	//pThis->GetEntity()->SetClientObject(n, data);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ItemContainer, __Insert, "Insert")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, __Insert)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& item = arg.GetNumber(0)
	//unsigned int pos = arg.GetNumber(1)
	//int _rtn = pThis->GetEntity()->Insert(item, pos);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ItemContainer, __Insert_1, "Insert_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, __Insert_1)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& item = arg.GetNumber(0)
	//unsigned int pos = arg.GetNumber(1)
	//void* clientData = arg.GetNumber(2)
	//int _rtn = pThis->GetEntity()->Insert(item, pos, clientData);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ItemContainer, __Insert_2, "Insert_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, __Insert_2)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& item = arg.GetNumber(0)
	//unsigned int pos = arg.GetNumber(1)
	//wxClientData* clientData = arg.GetNumber(2)
	//int _rtn = pThis->GetEntity()->Insert(item, pos, clientData);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ItemContainer, __Insert_3, "Insert_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, __Insert_3)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxArrayString& items = arg.GetNumber(0)
	//unsigned int pos = arg.GetNumber(1)
	//int _rtn = pThis->GetEntity()->Insert(items, pos);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ItemContainer, __Insert_4, "Insert_4")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, __Insert_4)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const std::vector<T>& items = arg.GetNumber(0)
	//int _rtn = pThis->GetEntity()->Insert(items);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ItemContainer, __Insert_5, "Insert_5")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, __Insert_5)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxArrayString& items = arg.GetNumber(0)
	//unsigned int pos = arg.GetNumber(1)
	//void** clientData = arg.GetNumber(2)
	//int _rtn = pThis->GetEntity()->Insert(items, pos, clientData);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ItemContainer, __Insert_6, "Insert_6")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, __Insert_6)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxArrayString& items = arg.GetNumber(0)
	//unsigned int pos = arg.GetNumber(1)
	//wxClientData** clientData = arg.GetNumber(2)
	//int _rtn = pThis->GetEntity()->Insert(items, pos, clientData);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ItemContainer, __Insert_7, "Insert_7")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, __Insert_7)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int n = arg.GetNumber(0)
	//const wxString* items = arg.GetNumber(1)
	//unsigned int pos = arg.GetNumber(2)
	//int _rtn = pThis->GetEntity()->Insert(n, items, pos);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ItemContainer, __Insert_8, "Insert_8")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, __Insert_8)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int n = arg.GetNumber(0)
	//const wxString* items = arg.GetNumber(1)
	//unsigned int pos = arg.GetNumber(2)
	//void** clientData = arg.GetNumber(3)
	//int _rtn = pThis->GetEntity()->Insert(n, items, pos, clientData);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ItemContainer, __Insert_9, "Insert_9")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, __Insert_9)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int n = arg.GetNumber(0)
	//const wxString* items = arg.GetNumber(1)
	//unsigned int pos = arg.GetNumber(2)
	//wxClientData** clientData = arg.GetNumber(3)
	//int _rtn = pThis->GetEntity()->Insert(n, items, pos, clientData);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ItemContainer, __Set, "Set")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, __Set)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxArrayString& items = arg.GetNumber(0)
	//pThis->GetEntity()->Set(items);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ItemContainer, __Set_1, "Set_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, __Set_1)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const std::vector<T>& items = arg.GetNumber(0)
	//pThis->GetEntity()->Set(items);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ItemContainer, __Set_2, "Set_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, __Set_2)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxArrayString& items = arg.GetNumber(0)
	//void** clientData = arg.GetNumber(1)
	//pThis->GetEntity()->Set(items, clientData);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ItemContainer, __Set_3, "Set_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, __Set_3)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxArrayString& items = arg.GetNumber(0)
	//wxClientData** clientData = arg.GetNumber(1)
	//pThis->GetEntity()->Set(items, clientData);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ItemContainer, __Set_4, "Set_4")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, __Set_4)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int n = arg.GetNumber(0)
	//const wxString* items = arg.GetNumber(1)
	//pThis->GetEntity()->Set(n, items);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ItemContainer, __Set_5, "Set_5")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, __Set_5)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int n = arg.GetNumber(0)
	//const wxString* items = arg.GetNumber(1)
	//void** clientData = arg.GetNumber(2)
	//pThis->GetEntity()->Set(n, items, clientData);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ItemContainer, __Set_6, "Set_6")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainer, __Set_6)
{
	Object_wx_ItemContainer *pThis = Object_wx_ItemContainer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int n = arg.GetNumber(0)
	//const wxString* items = arg.GetNumber(1)
	//wxClientData** clientData = arg.GetNumber(2)
	//pThis->GetEntity()->Set(n, items, clientData);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxItemContainer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ItemContainer)
{
	// Class assignment
	Gura_AssignValueEx("ItemContainer", Reference());
	// Method assignment
	Gura_AssignMethod(wx_ItemContainer, __Append);
	Gura_AssignMethod(wx_ItemContainer, __Append_1);
	Gura_AssignMethod(wx_ItemContainer, __Append_2);
	Gura_AssignMethod(wx_ItemContainer, __Append_3);
	Gura_AssignMethod(wx_ItemContainer, __Append_4);
	Gura_AssignMethod(wx_ItemContainer, __Append_5);
	Gura_AssignMethod(wx_ItemContainer, __Append_6);
	Gura_AssignMethod(wx_ItemContainer, __Append_7);
	Gura_AssignMethod(wx_ItemContainer, __Append_8);
	Gura_AssignMethod(wx_ItemContainer, __Append_9);
	Gura_AssignMethod(wx_ItemContainer, __Clear);
	Gura_AssignMethod(wx_ItemContainer, __Delete);
	Gura_AssignMethod(wx_ItemContainer, __DetachClientObject);
	Gura_AssignMethod(wx_ItemContainer, __HasClientData);
	Gura_AssignMethod(wx_ItemContainer, __HasClientObjectData);
	Gura_AssignMethod(wx_ItemContainer, __HasClientUntypedData);
	Gura_AssignMethod(wx_ItemContainer, __GetClientData);
	Gura_AssignMethod(wx_ItemContainer, __GetClientObject);
	Gura_AssignMethod(wx_ItemContainer, __SetClientData);
	Gura_AssignMethod(wx_ItemContainer, __SetClientObject);
	Gura_AssignMethod(wx_ItemContainer, __Insert);
	Gura_AssignMethod(wx_ItemContainer, __Insert_1);
	Gura_AssignMethod(wx_ItemContainer, __Insert_2);
	Gura_AssignMethod(wx_ItemContainer, __Insert_3);
	Gura_AssignMethod(wx_ItemContainer, __Insert_4);
	Gura_AssignMethod(wx_ItemContainer, __Insert_5);
	Gura_AssignMethod(wx_ItemContainer, __Insert_6);
	Gura_AssignMethod(wx_ItemContainer, __Insert_7);
	Gura_AssignMethod(wx_ItemContainer, __Insert_8);
	Gura_AssignMethod(wx_ItemContainer, __Insert_9);
	Gura_AssignMethod(wx_ItemContainer, __Set);
	Gura_AssignMethod(wx_ItemContainer, __Set_1);
	Gura_AssignMethod(wx_ItemContainer, __Set_2);
	Gura_AssignMethod(wx_ItemContainer, __Set_3);
	Gura_AssignMethod(wx_ItemContainer, __Set_4);
	Gura_AssignMethod(wx_ItemContainer, __Set_5);
	Gura_AssignMethod(wx_ItemContainer, __Set_6);
}

Gura_ImplementDescendantCreator(wx_ItemContainer)
{
	return new Object_wx_ItemContainer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
