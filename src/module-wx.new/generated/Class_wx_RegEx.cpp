//----------------------------------------------------------------------------
// wxRegEx
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRegEx
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRegEx
//----------------------------------------------------------------------------
Object_wx_RegEx::~Object_wx_RegEx()
{
}

Object *Object_wx_RegEx::Clone() const
{
	return nullptr;
}

String Object_wx_RegEx::ToString(bool exprFlag)
{
	String rtn("<wx.RegEx:");
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
Gura_DeclareMethod(wx_RegEx, wxRegEx)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RegEx, wxRegEx)
{
	Object_wx_RegEx *pThis = Object_wx_RegEx::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxRegEx();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RegEx, wxRegEx_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "expr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RegEx, wxRegEx_1)
{
	Object_wx_RegEx *pThis = Object_wx_RegEx::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int expr = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->wxRegEx();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RegEx, Compile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pattern", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RegEx, Compile)
{
	Object_wx_RegEx *pThis = Object_wx_RegEx::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pattern = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->Compile();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RegEx, GetMatch)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RegEx, GetMatch)
{
	Object_wx_RegEx *pThis = Object_wx_RegEx::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int start = arg.GetNumber(0)
	//int len = arg.GetNumber(1)
	//int index = arg.GetNumber(2)
	//pThis->GetEntity()->GetMatch();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RegEx, GetMatch_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RegEx, GetMatch_1)
{
	Object_wx_RegEx *pThis = Object_wx_RegEx::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//int index = arg.GetNumber(1)
	//pThis->GetEntity()->GetMatch();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RegEx, GetMatchCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RegEx, GetMatchCount)
{
	Object_wx_RegEx *pThis = Object_wx_RegEx::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMatchCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RegEx, IsValid)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RegEx, IsValid)
{
	Object_wx_RegEx *pThis = Object_wx_RegEx::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsValid();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RegEx, Matches)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RegEx, Matches)
{
	Object_wx_RegEx *pThis = Object_wx_RegEx::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->Matches();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RegEx, Matches_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RegEx, Matches_1)
{
	Object_wx_RegEx *pThis = Object_wx_RegEx::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//int len = arg.GetNumber(2)
	//pThis->GetEntity()->Matches();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RegEx, Matches_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RegEx, Matches_2)
{
	Object_wx_RegEx *pThis = Object_wx_RegEx::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->Matches();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RegEx, Replace)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "replacement", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "maxMatches", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RegEx, Replace)
{
	Object_wx_RegEx *pThis = Object_wx_RegEx::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//int replacement = arg.GetNumber(1)
	//int maxMatches = arg.GetNumber(2)
	//pThis->GetEntity()->Replace();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RegEx, ReplaceAll)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "replacement", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RegEx, ReplaceAll)
{
	Object_wx_RegEx *pThis = Object_wx_RegEx::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//int replacement = arg.GetNumber(1)
	//pThis->GetEntity()->ReplaceAll();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RegEx, ReplaceFirst)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "replacement", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RegEx, ReplaceFirst)
{
	Object_wx_RegEx *pThis = Object_wx_RegEx::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//int replacement = arg.GetNumber(1)
	//pThis->GetEntity()->ReplaceFirst();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRegEx
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RegEx)
{
	Gura_AssignMethod(wx_RegEx, wxRegEx);
	Gura_AssignMethod(wx_RegEx, wxRegEx_1);
	Gura_AssignMethod(wx_RegEx, Compile);
	Gura_AssignMethod(wx_RegEx, GetMatch);
	Gura_AssignMethod(wx_RegEx, GetMatch_1);
	Gura_AssignMethod(wx_RegEx, GetMatchCount);
	Gura_AssignMethod(wx_RegEx, IsValid);
	Gura_AssignMethod(wx_RegEx, Matches);
	Gura_AssignMethod(wx_RegEx, Matches_1);
	Gura_AssignMethod(wx_RegEx, Matches_2);
	Gura_AssignMethod(wx_RegEx, Replace);
	Gura_AssignMethod(wx_RegEx, ReplaceAll);
	Gura_AssignMethod(wx_RegEx, ReplaceFirst);
}

Gura_ImplementDescendantCreator(wx_RegEx)
{
	return new Object_wx_RegEx((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
