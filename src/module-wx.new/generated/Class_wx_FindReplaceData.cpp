//----------------------------------------------------------------------------
// wxFindReplaceData
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFindReplaceData
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFindReplaceData
//----------------------------------------------------------------------------
Object_wx_FindReplaceData::~Object_wx_FindReplaceData()
{
}

Object *Object_wx_FindReplaceData::Clone() const
{
	return nullptr;
}

String Object_wx_FindReplaceData::ToString(bool exprFlag)
{
	String rtn("<wx.FindReplaceData:");
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
Gura_DeclareMethod(wx_FindReplaceData, wxFindReplaceData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FindReplaceData, wxFindReplaceData)
{
	Signal &sig = env.GetSignal();
	Object_wx_FindReplaceData *pThis = Object_wx_FindReplaceData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->wxFindReplaceData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FindReplaceData, GetFindString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FindReplaceData, GetFindString)
{
	Signal &sig = env.GetSignal();
	Object_wx_FindReplaceData *pThis = Object_wx_FindReplaceData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFindString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FindReplaceData, GetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FindReplaceData, GetFlags)
{
	Signal &sig = env.GetSignal();
	Object_wx_FindReplaceData *pThis = Object_wx_FindReplaceData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FindReplaceData, GetReplaceString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FindReplaceData, GetReplaceString)
{
	Signal &sig = env.GetSignal();
	Object_wx_FindReplaceData *pThis = Object_wx_FindReplaceData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetReplaceString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FindReplaceData, SetFindString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FindReplaceData, SetFindString)
{
	Signal &sig = env.GetSignal();
	Object_wx_FindReplaceData *pThis = Object_wx_FindReplaceData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//pThis->GetEntity()->SetFindString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FindReplaceData, SetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FindReplaceData, SetFlags)
{
	Signal &sig = env.GetSignal();
	Object_wx_FindReplaceData *pThis = Object_wx_FindReplaceData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->SetFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FindReplaceData, SetReplaceString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FindReplaceData, SetReplaceString)
{
	Signal &sig = env.GetSignal();
	Object_wx_FindReplaceData *pThis = Object_wx_FindReplaceData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//pThis->GetEntity()->SetReplaceString();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFindReplaceData
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FindReplaceData)
{
	Gura_AssignMethod(wx_FindReplaceData, wxFindReplaceData);
	Gura_AssignMethod(wx_FindReplaceData, GetFindString);
	Gura_AssignMethod(wx_FindReplaceData, GetFlags);
	Gura_AssignMethod(wx_FindReplaceData, GetReplaceString);
	Gura_AssignMethod(wx_FindReplaceData, SetFindString);
	Gura_AssignMethod(wx_FindReplaceData, SetFlags);
	Gura_AssignMethod(wx_FindReplaceData, SetReplaceString);
}

Gura_ImplementDescendantCreator(wx_FindReplaceData)
{
	return new Object_wx_FindReplaceData((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
