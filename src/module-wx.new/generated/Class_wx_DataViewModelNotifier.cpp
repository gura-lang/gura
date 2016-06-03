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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxDataViewModelNotifier, "wxDataViewModelNotifier")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_DataViewModelNotifier));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxDataViewModelNotifier)
{
	//wxDataViewModelNotifier();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_DataViewModelNotifier, __Cleared, "Cleared")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewModelNotifier, __Cleared)
{
	Object_wx_DataViewModelNotifier *pThis = Object_wx_DataViewModelNotifier::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Cleared();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewModelNotifier, __GetOwner, "GetOwner")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewModelNotifier, __GetOwner)
{
	Object_wx_DataViewModelNotifier *pThis = Object_wx_DataViewModelNotifier::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOwner();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewModelNotifier, __ItemAdded, "ItemAdded")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewModelNotifier, __ItemAdded)
{
	Object_wx_DataViewModelNotifier *pThis = Object_wx_DataViewModelNotifier::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int item = arg.GetNumber(1)
	//pThis->GetEntity()->ItemAdded();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewModelNotifier, __ItemChanged, "ItemChanged")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewModelNotifier, __ItemChanged)
{
	Object_wx_DataViewModelNotifier *pThis = Object_wx_DataViewModelNotifier::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->ItemChanged();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewModelNotifier, __ItemDeleted, "ItemDeleted")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewModelNotifier, __ItemDeleted)
{
	Object_wx_DataViewModelNotifier *pThis = Object_wx_DataViewModelNotifier::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int item = arg.GetNumber(1)
	//pThis->GetEntity()->ItemDeleted();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewModelNotifier, __ItemsAdded, "ItemsAdded")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewModelNotifier, __ItemsAdded)
{
	Object_wx_DataViewModelNotifier *pThis = Object_wx_DataViewModelNotifier::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int items = arg.GetNumber(1)
	//pThis->GetEntity()->ItemsAdded();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewModelNotifier, __ItemsChanged, "ItemsChanged")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewModelNotifier, __ItemsChanged)
{
	Object_wx_DataViewModelNotifier *pThis = Object_wx_DataViewModelNotifier::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int items = arg.GetNumber(0)
	//pThis->GetEntity()->ItemsChanged();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewModelNotifier, __ItemsDeleted, "ItemsDeleted")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewModelNotifier, __ItemsDeleted)
{
	Object_wx_DataViewModelNotifier *pThis = Object_wx_DataViewModelNotifier::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int items = arg.GetNumber(1)
	//pThis->GetEntity()->ItemsDeleted();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewModelNotifier, __Resort, "Resort")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataViewModelNotifier, __Resort)
{
	Object_wx_DataViewModelNotifier *pThis = Object_wx_DataViewModelNotifier::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Resort();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewModelNotifier, __SetOwner, "SetOwner")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "owner", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewModelNotifier, __SetOwner)
{
	Object_wx_DataViewModelNotifier *pThis = Object_wx_DataViewModelNotifier::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int owner = arg.GetNumber(0)
	//pThis->GetEntity()->SetOwner();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataViewModelNotifier, __ValueChanged, "ValueChanged")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataViewModelNotifier, __ValueChanged)
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
	// Constructor assignment
	Gura_AssignFunction(__wxDataViewModelNotifier);
	// Method assignment
	Gura_AssignMethod(wx_DataViewModelNotifier, __Cleared);
	Gura_AssignMethod(wx_DataViewModelNotifier, __GetOwner);
	Gura_AssignMethod(wx_DataViewModelNotifier, __ItemAdded);
	Gura_AssignMethod(wx_DataViewModelNotifier, __ItemChanged);
	Gura_AssignMethod(wx_DataViewModelNotifier, __ItemDeleted);
	Gura_AssignMethod(wx_DataViewModelNotifier, __ItemsAdded);
	Gura_AssignMethod(wx_DataViewModelNotifier, __ItemsChanged);
	Gura_AssignMethod(wx_DataViewModelNotifier, __ItemsDeleted);
	Gura_AssignMethod(wx_DataViewModelNotifier, __Resort);
	Gura_AssignMethod(wx_DataViewModelNotifier, __SetOwner);
	Gura_AssignMethod(wx_DataViewModelNotifier, __ValueChanged);
}

Gura_ImplementDescendantCreator(wx_DataViewModelNotifier)
{
	return new Object_wx_DataViewModelNotifier((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
