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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__RegEx, "RegEx")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_RegEx));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RegEx)
{
	//wxRegEx();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__RegEx_1, "RegEx_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "expr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RegEx));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RegEx_1)
{
	//int expr = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//wxRegEx();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RegEx, __Compile, "Compile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pattern", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RegEx, __Compile)
{
	Object_wx_RegEx *pThis = Object_wx_RegEx::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pattern = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->Compile();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RegEx, __GetMatch, "GetMatch")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RegEx, __GetMatch)
{
	Object_wx_RegEx *pThis = Object_wx_RegEx::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int start = arg.GetNumber(0)
	//int len = arg.GetNumber(1)
	//int index = arg.GetNumber(2)
	//pThis->GetEntity()->GetMatch();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RegEx, __GetMatch_1, "GetMatch_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "index", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RegEx, __GetMatch_1)
{
	Object_wx_RegEx *pThis = Object_wx_RegEx::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//int index = arg.GetNumber(1)
	//pThis->GetEntity()->GetMatch();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RegEx, __GetMatchCount, "GetMatchCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RegEx, __GetMatchCount)
{
	Object_wx_RegEx *pThis = Object_wx_RegEx::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMatchCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RegEx, __IsValid, "IsValid")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RegEx, __IsValid)
{
	Object_wx_RegEx *pThis = Object_wx_RegEx::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsValid();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RegEx, __Matches, "Matches")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RegEx, __Matches)
{
	Object_wx_RegEx *pThis = Object_wx_RegEx::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->Matches();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RegEx, __Matches_1, "Matches_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RegEx, __Matches_1)
{
	Object_wx_RegEx *pThis = Object_wx_RegEx::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//int len = arg.GetNumber(2)
	//pThis->GetEntity()->Matches();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RegEx, __Matches_2, "Matches_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RegEx, __Matches_2)
{
	Object_wx_RegEx *pThis = Object_wx_RegEx::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->Matches();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RegEx, __Replace, "Replace")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "replacement", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "maxMatches", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RegEx, __Replace)
{
	Object_wx_RegEx *pThis = Object_wx_RegEx::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//int replacement = arg.GetNumber(1)
	//int maxMatches = arg.GetNumber(2)
	//pThis->GetEntity()->Replace();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RegEx, __ReplaceAll, "ReplaceAll")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "replacement", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RegEx, __ReplaceAll)
{
	Object_wx_RegEx *pThis = Object_wx_RegEx::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//int replacement = arg.GetNumber(1)
	//pThis->GetEntity()->ReplaceAll();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RegEx, __ReplaceFirst, "ReplaceFirst")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "replacement", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RegEx, __ReplaceFirst)
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
	// Constructor assignment
	Gura_AssignFunction(__RegEx);
	Gura_AssignFunction(__RegEx_1);
	// Method assignment
	Gura_AssignMethod(wx_RegEx, __Compile);
	Gura_AssignMethod(wx_RegEx, __GetMatch);
	Gura_AssignMethod(wx_RegEx, __GetMatch_1);
	Gura_AssignMethod(wx_RegEx, __GetMatchCount);
	Gura_AssignMethod(wx_RegEx, __IsValid);
	Gura_AssignMethod(wx_RegEx, __Matches);
	Gura_AssignMethod(wx_RegEx, __Matches_1);
	Gura_AssignMethod(wx_RegEx, __Matches_2);
	Gura_AssignMethod(wx_RegEx, __Replace);
	Gura_AssignMethod(wx_RegEx, __ReplaceAll);
	Gura_AssignMethod(wx_RegEx, __ReplaceFirst);
}

Gura_ImplementDescendantCreator(wx_RegEx)
{
	return new Object_wx_RegEx((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
