//----------------------------------------------------------------------------
// wxDataViewModelNotifier
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewModelNotifier
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDataViewModelNotifier
//----------------------------------------------------------------------------
Object_wx_DataViewModelNotifier::~Object_wx_DataViewModelNotifier()
{
}

Object *Object_wx_DataViewModelNotifier::Clone() const
{
	return nullptr;
}

String Object_wx_DataViewModelNotifier::ToString(bool exprFlag)
{
	String rtn("<wx.DataViewModelNotifier:");
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
Gura_DeclareMethod(wx_DataViewModelNotifier, wxDataViewModelNotifier)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewModelNotifier, wxDataViewModelNotifier)
{
	Object_wx_DataViewModelNotifier *pThis = Object_wx_DataViewModelNotifier::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxDataViewModelNotifier();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewModelNotifier, Cleared)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewModelNotifier, Cleared)
{
	Object_wx_DataViewModelNotifier *pThis = Object_wx_DataViewModelNotifier::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Cleared();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewModelNotifier, GetOwner)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewModelNotifier, GetOwner)
{
	Object_wx_DataViewModelNotifier *pThis = Object_wx_DataViewModelNotifier::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOwner();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewModelNotifier, ItemAdded)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewModelNotifier, ItemAdded)
{
	Object_wx_DataViewModelNotifier *pThis = Object_wx_DataViewModelNotifier::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int item = arg.GetNumber(1)
	//pThis->GetEntity()->ItemAdded();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewModelNotifier, ItemChanged)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewModelNotifier, ItemChanged)
{
	Object_wx_DataViewModelNotifier *pThis = Object_wx_DataViewModelNotifier::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->ItemChanged();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewModelNotifier, ItemDeleted)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewModelNotifier, ItemDeleted)
{
	Object_wx_DataViewModelNotifier *pThis = Object_wx_DataViewModelNotifier::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int item = arg.GetNumber(1)
	//pThis->GetEntity()->ItemDeleted();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewModelNotifier, ItemsAdded)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewModelNotifier, ItemsAdded)
{
	Object_wx_DataViewModelNotifier *pThis = Object_wx_DataViewModelNotifier::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int items = arg.GetNumber(1)
	//pThis->GetEntity()->ItemsAdded();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewModelNotifier, ItemsChanged)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewModelNotifier, ItemsChanged)
{
	Object_wx_DataViewModelNotifier *pThis = Object_wx_DataViewModelNotifier::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int items = arg.GetNumber(0)
	//pThis->GetEntity()->ItemsChanged();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewModelNotifier, ItemsDeleted)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewModelNotifier, ItemsDeleted)
{
	Object_wx_DataViewModelNotifier *pThis = Object_wx_DataViewModelNotifier::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int items = arg.GetNumber(1)
	//pThis->GetEntity()->ItemsDeleted();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewModelNotifier, Resort)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewModelNotifier, Resort)
{
	Object_wx_DataViewModelNotifier *pThis = Object_wx_DataViewModelNotifier::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Resort();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewModelNotifier, SetOwner)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "owner", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewModelNotifier, SetOwner)
{
	Object_wx_DataViewModelNotifier *pThis = Object_wx_DataViewModelNotifier::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int owner = arg.GetNumber(0)
	//pThis->GetEntity()->SetOwner();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataViewModelNotifier, ValueChanged)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewModelNotifier, ValueChanged)
{
	Object_wx_DataViewModelNotifier *pThis = Object_wx_DataViewModelNotifier::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int col = arg.GetNumber(1)
	//pThis->GetEntity()->ValueChanged();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDataViewModelNotifier
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewModelNotifier)
{
	Gura_AssignMethod(wx_DataViewModelNotifier, wxDataViewModelNotifier);
	Gura_AssignMethod(wx_DataViewModelNotifier, Cleared);
	Gura_AssignMethod(wx_DataViewModelNotifier, GetOwner);
	Gura_AssignMethod(wx_DataViewModelNotifier, ItemAdded);
	Gura_AssignMethod(wx_DataViewModelNotifier, ItemChanged);
	Gura_AssignMethod(wx_DataViewModelNotifier, ItemDeleted);
	Gura_AssignMethod(wx_DataViewModelNotifier, ItemsAdded);
	Gura_AssignMethod(wx_DataViewModelNotifier, ItemsChanged);
	Gura_AssignMethod(wx_DataViewModelNotifier, ItemsDeleted);
	Gura_AssignMethod(wx_DataViewModelNotifier, Resort);
	Gura_AssignMethod(wx_DataViewModelNotifier, SetOwner);
	Gura_AssignMethod(wx_DataViewModelNotifier, ValueChanged);
}

Gura_ImplementDescendantCreator(wx_DataViewModelNotifier)
{
	return new Object_wx_DataViewModelNotifier((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
