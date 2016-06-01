//----------------------------------------------------------------------------
// wxAnyValueType
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAnyValueType
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAnyValueType
//----------------------------------------------------------------------------
Object_wx_AnyValueType::~Object_wx_AnyValueType()
{
}

Object *Object_wx_AnyValueType::Clone() const
{
	return nullptr;
}

String Object_wx_AnyValueType::ToString(bool exprFlag)
{
	String rtn("<wx.AnyValueType:");
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

Gura_DeclareMethod(wx_AnyValueType, wxAnyValueType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnyValueType, wxAnyValueType)
{
	Signal &sig = env.GetSignal();
	Object_wx_AnyValueType *pThis = Object_wx_AnyValueType::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->wxAnyValueType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AnyValueType, ~wxAnyValueType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnyValueType, ~wxAnyValueType)
{
	Signal &sig = env.GetSignal();
	Object_wx_AnyValueType *pThis = Object_wx_AnyValueType::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->~wxAnyValueType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AnyValueType, CheckType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnyValueType, CheckType)
{
	Signal &sig = env.GetSignal();
	Object_wx_AnyValueType *pThis = Object_wx_AnyValueType::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->CheckType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AnyValueType, ConvertValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnyValueType, ConvertValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_AnyValueType *pThis = Object_wx_AnyValueType::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->ConvertValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AnyValueType, CopyBuffer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnyValueType, CopyBuffer)
{
	Signal &sig = env.GetSignal();
	Object_wx_AnyValueType *pThis = Object_wx_AnyValueType::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->CopyBuffer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AnyValueType, DeleteValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnyValueType, DeleteValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_AnyValueType *pThis = Object_wx_AnyValueType::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->DeleteValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AnyValueType, IsSameType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AnyValueType, IsSameType)
{
	Signal &sig = env.GetSignal();
	Object_wx_AnyValueType *pThis = Object_wx_AnyValueType::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->IsSameType();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxAnyValueType
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AnyValueType)
{
}

Gura_ImplementDescendantCreator(wx_AnyValueType)
{
	return new Object_wx_AnyValueType((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
