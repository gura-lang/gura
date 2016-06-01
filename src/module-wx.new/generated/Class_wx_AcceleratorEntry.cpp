//----------------------------------------------------------------------------
// wxAcceleratorEntry
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAcceleratorEntry
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAcceleratorEntry
//----------------------------------------------------------------------------
Object_wx_AcceleratorEntry::~Object_wx_AcceleratorEntry()
{
}

Object *Object_wx_AcceleratorEntry::Clone() const
{
	return nullptr;
}

String Object_wx_AcceleratorEntry::ToString(bool exprFlag)
{
	String rtn("<wx.AcceleratorEntry:");
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

Gura_DeclareMethod(wx_AcceleratorEntry, wxAcceleratorEntry)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AcceleratorEntry, wxAcceleratorEntry)
{
	Signal &sig = env.GetSignal();
	Object_wx_AcceleratorEntry *pThis = Object_wx_AcceleratorEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->wxAcceleratorEntry();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AcceleratorEntry, wxAcceleratorEntry)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AcceleratorEntry, wxAcceleratorEntry)
{
	Signal &sig = env.GetSignal();
	Object_wx_AcceleratorEntry *pThis = Object_wx_AcceleratorEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->wxAcceleratorEntry();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AcceleratorEntry, GetCommand)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AcceleratorEntry, GetCommand)
{
	Signal &sig = env.GetSignal();
	Object_wx_AcceleratorEntry *pThis = Object_wx_AcceleratorEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->GetCommand();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AcceleratorEntry, GetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AcceleratorEntry, GetFlags)
{
	Signal &sig = env.GetSignal();
	Object_wx_AcceleratorEntry *pThis = Object_wx_AcceleratorEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->GetFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AcceleratorEntry, GetKeyCode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AcceleratorEntry, GetKeyCode)
{
	Signal &sig = env.GetSignal();
	Object_wx_AcceleratorEntry *pThis = Object_wx_AcceleratorEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->GetKeyCode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AcceleratorEntry, GetMenuItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AcceleratorEntry, GetMenuItem)
{
	Signal &sig = env.GetSignal();
	Object_wx_AcceleratorEntry *pThis = Object_wx_AcceleratorEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->GetMenuItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AcceleratorEntry, Set)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AcceleratorEntry, Set)
{
	Signal &sig = env.GetSignal();
	Object_wx_AcceleratorEntry *pThis = Object_wx_AcceleratorEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->Set();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AcceleratorEntry, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AcceleratorEntry, IsOk)
{
	Signal &sig = env.GetSignal();
	Object_wx_AcceleratorEntry *pThis = Object_wx_AcceleratorEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AcceleratorEntry, ToString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AcceleratorEntry, ToString)
{
	Signal &sig = env.GetSignal();
	Object_wx_AcceleratorEntry *pThis = Object_wx_AcceleratorEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->ToString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AcceleratorEntry, ToRawString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AcceleratorEntry, ToRawString)
{
	Signal &sig = env.GetSignal();
	Object_wx_AcceleratorEntry *pThis = Object_wx_AcceleratorEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->ToRawString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AcceleratorEntry, FromString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "developer", VTYPE_string, OCCUR_Once);
}

Gura_ImplementMethod(wx_AcceleratorEntry, FromString)
{
	Signal &sig = env.GetSignal();
	Object_wx_AcceleratorEntry *pThis = Object_wx_AcceleratorEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//wxString developer = wxString::FromUTF8(arg.GetString(0));
	pThis->GetEntity()->FromString();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxAcceleratorEntry
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AcceleratorEntry)
{
}

Gura_ImplementDescendantCreator(wx_AcceleratorEntry)
{
	return new Object_wx_AcceleratorEntry((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
