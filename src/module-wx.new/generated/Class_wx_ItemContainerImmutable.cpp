//----------------------------------------------------------------------------
// wxItemContainerImmutable
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxItemContainerImmutable
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxItemContainerImmutable
//----------------------------------------------------------------------------
Object_wx_ItemContainerImmutable::~Object_wx_ItemContainerImmutable()
{
}

Object *Object_wx_ItemContainerImmutable::Clone() const
{
	return nullptr;
}

String Object_wx_ItemContainerImmutable::ToString(bool exprFlag)
{
	String rtn("<wx.ItemContainerImmutable:");
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
Gura_DeclareFunctionAlias(__ItemContainerImmutable, "ItemContainerImmutable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_ItemContainerImmutable));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__ItemContainerImmutable)
{
	//wxItemContainerImmutable();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_ItemContainerImmutable, __GetCount, "GetCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ItemContainerImmutable, __GetCount)
{
	Object_wx_ItemContainerImmutable *pThis = Object_wx_ItemContainerImmutable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ItemContainerImmutable, __IsEmpty, "IsEmpty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ItemContainerImmutable, __IsEmpty)
{
	Object_wx_ItemContainerImmutable *pThis = Object_wx_ItemContainerImmutable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsEmpty();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ItemContainerImmutable, __GetString, "GetString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainerImmutable, __GetString)
{
	Object_wx_ItemContainerImmutable *pThis = Object_wx_ItemContainerImmutable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->GetString();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ItemContainerImmutable, __GetStrings, "GetStrings")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ItemContainerImmutable, __GetStrings)
{
	Object_wx_ItemContainerImmutable *pThis = Object_wx_ItemContainerImmutable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStrings();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ItemContainerImmutable, __SetString, "SetString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "string", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainerImmutable, __SetString)
{
	Object_wx_ItemContainerImmutable *pThis = Object_wx_ItemContainerImmutable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//int string = arg.GetNumber(1)
	//pThis->GetEntity()->SetString();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ItemContainerImmutable, __FindString, "FindString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "string", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "caseSensitive", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainerImmutable, __FindString)
{
	Object_wx_ItemContainerImmutable *pThis = Object_wx_ItemContainerImmutable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int string = arg.GetNumber(0)
	//int caseSensitive = arg.GetNumber(1)
	//pThis->GetEntity()->FindString();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ItemContainerImmutable, __SetSelection, "SetSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainerImmutable, __SetSelection)
{
	Object_wx_ItemContainerImmutable *pThis = Object_wx_ItemContainerImmutable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ItemContainerImmutable, __GetSelection, "GetSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ItemContainerImmutable, __GetSelection)
{
	Object_wx_ItemContainerImmutable *pThis = Object_wx_ItemContainerImmutable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ItemContainerImmutable, __SetStringSelection, "SetStringSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "string", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainerImmutable, __SetStringSelection)
{
	Object_wx_ItemContainerImmutable *pThis = Object_wx_ItemContainerImmutable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int string = arg.GetNumber(0)
	//pThis->GetEntity()->SetStringSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ItemContainerImmutable, __GetStringSelection, "GetStringSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ItemContainerImmutable, __GetStringSelection)
{
	Object_wx_ItemContainerImmutable *pThis = Object_wx_ItemContainerImmutable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStringSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ItemContainerImmutable, __Select, "Select")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ItemContainerImmutable, __Select)
{
	Object_wx_ItemContainerImmutable *pThis = Object_wx_ItemContainerImmutable::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->Select();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxItemContainerImmutable
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ItemContainerImmutable)
{
	// Constructor assignment
	Gura_AssignFunction(__ItemContainerImmutable);
	// Method assignment
	Gura_AssignMethod(wx_ItemContainerImmutable, __GetCount);
	Gura_AssignMethod(wx_ItemContainerImmutable, __IsEmpty);
	Gura_AssignMethod(wx_ItemContainerImmutable, __GetString);
	Gura_AssignMethod(wx_ItemContainerImmutable, __GetStrings);
	Gura_AssignMethod(wx_ItemContainerImmutable, __SetString);
	Gura_AssignMethod(wx_ItemContainerImmutable, __FindString);
	Gura_AssignMethod(wx_ItemContainerImmutable, __SetSelection);
	Gura_AssignMethod(wx_ItemContainerImmutable, __GetSelection);
	Gura_AssignMethod(wx_ItemContainerImmutable, __SetStringSelection);
	Gura_AssignMethod(wx_ItemContainerImmutable, __GetStringSelection);
	Gura_AssignMethod(wx_ItemContainerImmutable, __Select);
}

Gura_ImplementDescendantCreator(wx_ItemContainerImmutable)
{
	return new Object_wx_ItemContainerImmutable((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
