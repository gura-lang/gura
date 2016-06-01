//----------------------------------------------------------------------------
// wxConfigPathChanger
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxConfigPathChanger
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxConfigPathChanger
//----------------------------------------------------------------------------
Object_wx_ConfigPathChanger::~Object_wx_ConfigPathChanger()
{
}

Object *Object_wx_ConfigPathChanger::Clone() const
{
	return nullptr;
}

String Object_wx_ConfigPathChanger::ToString(bool exprFlag)
{
	String rtn("<wx.ConfigPathChanger:");
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
Gura_DeclareMethod(wx_ConfigPathChanger, wxConfigPathChanger)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pContainer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "strEntry", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ConfigPathChanger, wxConfigPathChanger)
{
	Signal &sig = env.GetSignal();
	Object_wx_ConfigPathChanger *pThis = Object_wx_ConfigPathChanger::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pContainer = arg.GetNumber(0)
	//int strEntry = arg.GetNumber(1)
	//pThis->GetEntity()->wxConfigPathChanger();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ConfigPathChanger, ~wxConfigPathChanger)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ConfigPathChanger, ~wxConfigPathChanger)
{
	Signal &sig = env.GetSignal();
	Object_wx_ConfigPathChanger *pThis = Object_wx_ConfigPathChanger::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxConfigPathChanger();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ConfigPathChanger, Name)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ConfigPathChanger, Name)
{
	Signal &sig = env.GetSignal();
	Object_wx_ConfigPathChanger *pThis = Object_wx_ConfigPathChanger::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Name();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ConfigPathChanger, UpdateIfDeleted)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ConfigPathChanger, UpdateIfDeleted)
{
	Signal &sig = env.GetSignal();
	Object_wx_ConfigPathChanger *pThis = Object_wx_ConfigPathChanger::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->UpdateIfDeleted();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxConfigPathChanger
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ConfigPathChanger)
{
	Gura_AssignMethod(wx_ConfigPathChanger, wxConfigPathChanger);
	Gura_AssignMethod(wx_ConfigPathChanger, ~wxConfigPathChanger);
	Gura_AssignMethod(wx_ConfigPathChanger, Name);
	Gura_AssignMethod(wx_ConfigPathChanger, UpdateIfDeleted);
}

Gura_ImplementDescendantCreator(wx_ConfigPathChanger)
{
	return new Object_wx_ConfigPathChanger((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
