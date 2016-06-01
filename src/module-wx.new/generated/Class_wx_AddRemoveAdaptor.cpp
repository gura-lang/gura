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
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AddRemoveAdaptor, wxAddRemoveAdaptor)
{
	Signal &sig = env.GetSignal();
	Object_wx_AddRemoveAdaptor *pThis = Object_wx_AddRemoveAdaptor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->wxAddRemoveAdaptor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AddRemoveAdaptor, ~wxAddRemoveAdaptor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AddRemoveAdaptor, ~wxAddRemoveAdaptor)
{
	Signal &sig = env.GetSignal();
	Object_wx_AddRemoveAdaptor *pThis = Object_wx_AddRemoveAdaptor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->~wxAddRemoveAdaptor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AddRemoveAdaptor, GetItemsCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AddRemoveAdaptor, GetItemsCtrl)
{
	Signal &sig = env.GetSignal();
	Object_wx_AddRemoveAdaptor *pThis = Object_wx_AddRemoveAdaptor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->GetItemsCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AddRemoveAdaptor, CanAdd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AddRemoveAdaptor, CanAdd)
{
	Signal &sig = env.GetSignal();
	Object_wx_AddRemoveAdaptor *pThis = Object_wx_AddRemoveAdaptor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->CanAdd();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AddRemoveAdaptor, CanRemove)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AddRemoveAdaptor, CanRemove)
{
	Signal &sig = env.GetSignal();
	Object_wx_AddRemoveAdaptor *pThis = Object_wx_AddRemoveAdaptor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->CanRemove();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AddRemoveAdaptor, OnAdd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AddRemoveAdaptor, OnAdd)
{
	Signal &sig = env.GetSignal();
	Object_wx_AddRemoveAdaptor *pThis = Object_wx_AddRemoveAdaptor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->OnAdd();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AddRemoveAdaptor, OnRemove)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AddRemoveAdaptor, OnRemove)
{
	Signal &sig = env.GetSignal();
	Object_wx_AddRemoveAdaptor *pThis = Object_wx_AddRemoveAdaptor::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->OnRemove();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxAddRemoveAdaptor
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AddRemoveAdaptor)
{
}

Gura_ImplementDescendantCreator(wx_AddRemoveAdaptor)
{
	return new Object_wx_AddRemoveAdaptor((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
