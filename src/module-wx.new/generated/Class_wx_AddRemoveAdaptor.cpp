//----------------------------------------------------------------------------
// wxAddRemoveAdaptor
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAddRemoveAdaptor
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAddRemoveAdaptor
//----------------------------------------------------------------------------
Object_wx_AddRemoveAdaptor::~Object_wx_AddRemoveAdaptor()
{
}

Object *Object_wx_AddRemoveAdaptor::Clone() const
{
	return nullptr;
}

String Object_wx_AddRemoveAdaptor::ToString(bool exprFlag)
{
	String rtn("<wx.AddRemoveAdaptor:");
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
Gura_DeclareMethod(wx_AddRemoveAdaptor, wxAddRemoveAdaptor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AddRemoveAdaptor, wxAddRemoveAdaptor)
{
	Signal &sig = env.GetSignal();
	Object_wx_AddRemoveAdaptor *pThis = Object_wx_AddRemoveAdaptor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxAddRemoveAdaptor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AddRemoveAdaptor, ~wxAddRemoveAdaptor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AddRemoveAdaptor, ~wxAddRemoveAdaptor)
{
	Signal &sig = env.GetSignal();
	Object_wx_AddRemoveAdaptor *pThis = Object_wx_AddRemoveAdaptor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxAddRemoveAdaptor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AddRemoveAdaptor, GetItemsCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AddRemoveAdaptor, GetItemsCtrl)
{
	Signal &sig = env.GetSignal();
	Object_wx_AddRemoveAdaptor *pThis = Object_wx_AddRemoveAdaptor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetItemsCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AddRemoveAdaptor, CanAdd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AddRemoveAdaptor, CanAdd)
{
	Signal &sig = env.GetSignal();
	Object_wx_AddRemoveAdaptor *pThis = Object_wx_AddRemoveAdaptor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CanAdd();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AddRemoveAdaptor, CanRemove)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AddRemoveAdaptor, CanRemove)
{
	Signal &sig = env.GetSignal();
	Object_wx_AddRemoveAdaptor *pThis = Object_wx_AddRemoveAdaptor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CanRemove();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AddRemoveAdaptor, OnAdd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AddRemoveAdaptor, OnAdd)
{
	Signal &sig = env.GetSignal();
	Object_wx_AddRemoveAdaptor *pThis = Object_wx_AddRemoveAdaptor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->OnAdd();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AddRemoveAdaptor, OnRemove)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AddRemoveAdaptor, OnRemove)
{
	Signal &sig = env.GetSignal();
	Object_wx_AddRemoveAdaptor *pThis = Object_wx_AddRemoveAdaptor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->OnRemove();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxAddRemoveAdaptor
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AddRemoveAdaptor)
{
	Gura_AssignMethod(wx_AddRemoveAdaptor, wxAddRemoveAdaptor);
	Gura_AssignMethod(wx_AddRemoveAdaptor, ~wxAddRemoveAdaptor);
	Gura_AssignMethod(wx_AddRemoveAdaptor, GetItemsCtrl);
	Gura_AssignMethod(wx_AddRemoveAdaptor, CanAdd);
	Gura_AssignMethod(wx_AddRemoveAdaptor, CanRemove);
	Gura_AssignMethod(wx_AddRemoveAdaptor, OnAdd);
	Gura_AssignMethod(wx_AddRemoveAdaptor, OnRemove);
}

Gura_ImplementDescendantCreator(wx_AddRemoveAdaptor)
{
	return new Object_wx_AddRemoveAdaptor((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
