//----------------------------------------------------------------------------
// wxAny
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAny
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAny
//----------------------------------------------------------------------------
Object_wx_Any::~Object_wx_Any()
{
}

Object *Object_wx_Any::Clone() const
{
	return nullptr;
}

String Object_wx_Any::ToString(bool exprFlag)
{
	String rtn("<wx.Any:");
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

Gura_DeclareMethod(wx_Any, wxAny)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Any, wxAny)
{
	Signal &sig = env.GetSignal();
	Object_wx_Any *pThis = Object_wx_Any::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->wxAny();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Any, wxAny)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Any, wxAny)
{
	Signal &sig = env.GetSignal();
	Object_wx_Any *pThis = Object_wx_Any::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->wxAny();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Any, wxAny)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Any, wxAny)
{
	Signal &sig = env.GetSignal();
	Object_wx_Any *pThis = Object_wx_Any::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->wxAny();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Any, wxAny)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Any, wxAny)
{
	Signal &sig = env.GetSignal();
	Object_wx_Any *pThis = Object_wx_Any::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->wxAny();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Any, ~wxAny)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Any, ~wxAny)
{
	Signal &sig = env.GetSignal();
	Object_wx_Any *pThis = Object_wx_Any::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->~wxAny();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Any, As)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Any, As)
{
	Signal &sig = env.GetSignal();
	Object_wx_Any *pThis = Object_wx_Any::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->As();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Any, CheckType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Any, CheckType)
{
	Signal &sig = env.GetSignal();
	Object_wx_Any *pThis = Object_wx_Any::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->CheckType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Any, GetAs)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Any, GetAs)
{
	Signal &sig = env.GetSignal();
	Object_wx_Any *pThis = Object_wx_Any::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->GetAs();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Any, GetAs)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Any, GetAs)
{
	Signal &sig = env.GetSignal();
	Object_wx_Any *pThis = Object_wx_Any::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->GetAs();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Any, GetType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Any, GetType)
{
	Signal &sig = env.GetSignal();
	Object_wx_Any *pThis = Object_wx_Any::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->GetType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Any, HasSameType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Any, HasSameType)
{
	Signal &sig = env.GetSignal();
	Object_wx_Any *pThis = Object_wx_Any::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->HasSameType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Any, IsNull)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Any, IsNull)
{
	Signal &sig = env.GetSignal();
	Object_wx_Any *pThis = Object_wx_Any::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->IsNull();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Any, MakeNull)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_Any, MakeNull)
{
	Signal &sig = env.GetSignal();
	Object_wx_Any *pThis = Object_wx_Any::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->MakeNull();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxAny
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Any)
{
}

Gura_ImplementDescendantCreator(wx_Any)
{
	return new Object_wx_Any((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
