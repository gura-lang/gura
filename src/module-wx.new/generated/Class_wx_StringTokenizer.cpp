//----------------------------------------------------------------------------
// wxStringTokenizer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxStringTokenizer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxStringTokenizer
//----------------------------------------------------------------------------
Object_wx_StringTokenizer::~Object_wx_StringTokenizer()
{
}

Object *Object_wx_StringTokenizer::Clone() const
{
	return nullptr;
}

String Object_wx_StringTokenizer::ToString(bool exprFlag)
{
	String rtn("<wx.StringTokenizer:");
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
Gura_DeclareMethodAlias(wx_StringTokenizer, __wxStringTokenizer, "wxStringTokenizer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StringTokenizer, __wxStringTokenizer)
{
	Object_wx_StringTokenizer *pThis = Object_wx_StringTokenizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxStringTokenizer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StringTokenizer, __wxStringTokenizer_1, "wxStringTokenizer_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "delims", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StringTokenizer, __wxStringTokenizer_1)
{
	Object_wx_StringTokenizer *pThis = Object_wx_StringTokenizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//int delims = arg.GetNumber(1)
	//int mode = arg.GetNumber(2)
	//pThis->GetEntity()->wxStringTokenizer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StringTokenizer, __CountTokens, "CountTokens")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StringTokenizer, __CountTokens)
{
	Object_wx_StringTokenizer *pThis = Object_wx_StringTokenizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CountTokens();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StringTokenizer, __GetLastDelimiter, "GetLastDelimiter")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StringTokenizer, __GetLastDelimiter)
{
	Object_wx_StringTokenizer *pThis = Object_wx_StringTokenizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLastDelimiter();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StringTokenizer, __GetNextToken, "GetNextToken")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StringTokenizer, __GetNextToken)
{
	Object_wx_StringTokenizer *pThis = Object_wx_StringTokenizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetNextToken();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StringTokenizer, __GetPosition, "GetPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StringTokenizer, __GetPosition)
{
	Object_wx_StringTokenizer *pThis = Object_wx_StringTokenizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StringTokenizer, __GetString, "GetString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StringTokenizer, __GetString)
{
	Object_wx_StringTokenizer *pThis = Object_wx_StringTokenizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetString();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StringTokenizer, __HasMoreTokens, "HasMoreTokens")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StringTokenizer, __HasMoreTokens)
{
	Object_wx_StringTokenizer *pThis = Object_wx_StringTokenizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasMoreTokens();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StringTokenizer, __SetString, "SetString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "delims", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StringTokenizer, __SetString)
{
	Object_wx_StringTokenizer *pThis = Object_wx_StringTokenizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//int delims = arg.GetNumber(1)
	//int mode = arg.GetNumber(2)
	//pThis->GetEntity()->SetString();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxStringTokenizer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StringTokenizer)
{
	Gura_AssignMethod(wx_StringTokenizer, __wxStringTokenizer);
	Gura_AssignMethod(wx_StringTokenizer, __wxStringTokenizer_1);
	Gura_AssignMethod(wx_StringTokenizer, __CountTokens);
	Gura_AssignMethod(wx_StringTokenizer, __GetLastDelimiter);
	Gura_AssignMethod(wx_StringTokenizer, __GetNextToken);
	Gura_AssignMethod(wx_StringTokenizer, __GetPosition);
	Gura_AssignMethod(wx_StringTokenizer, __GetString);
	Gura_AssignMethod(wx_StringTokenizer, __HasMoreTokens);
	Gura_AssignMethod(wx_StringTokenizer, __SetString);
}

Gura_ImplementDescendantCreator(wx_StringTokenizer)
{
	return new Object_wx_StringTokenizer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
