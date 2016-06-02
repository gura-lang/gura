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
Gura_DeclareMethod(wx_StringTokenizer, wxStringTokenizer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StringTokenizer, wxStringTokenizer)
{
	Object_wx_StringTokenizer *pThis = Object_wx_StringTokenizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxStringTokenizer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StringTokenizer, wxStringTokenizer_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "delims", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StringTokenizer, wxStringTokenizer_1)
{
	Object_wx_StringTokenizer *pThis = Object_wx_StringTokenizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//int delims = arg.GetNumber(1)
	//int mode = arg.GetNumber(2)
	//pThis->GetEntity()->wxStringTokenizer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StringTokenizer, CountTokens)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StringTokenizer, CountTokens)
{
	Object_wx_StringTokenizer *pThis = Object_wx_StringTokenizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CountTokens();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StringTokenizer, GetLastDelimiter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StringTokenizer, GetLastDelimiter)
{
	Object_wx_StringTokenizer *pThis = Object_wx_StringTokenizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLastDelimiter();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StringTokenizer, GetNextToken)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StringTokenizer, GetNextToken)
{
	Object_wx_StringTokenizer *pThis = Object_wx_StringTokenizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetNextToken();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StringTokenizer, GetPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StringTokenizer, GetPosition)
{
	Object_wx_StringTokenizer *pThis = Object_wx_StringTokenizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StringTokenizer, GetString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StringTokenizer, GetString)
{
	Object_wx_StringTokenizer *pThis = Object_wx_StringTokenizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StringTokenizer, HasMoreTokens)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StringTokenizer, HasMoreTokens)
{
	Object_wx_StringTokenizer *pThis = Object_wx_StringTokenizer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasMoreTokens();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StringTokenizer, SetString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "delims", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StringTokenizer, SetString)
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
	Gura_AssignMethod(wx_StringTokenizer, wxStringTokenizer);
	Gura_AssignMethod(wx_StringTokenizer, wxStringTokenizer_1);
	Gura_AssignMethod(wx_StringTokenizer, CountTokens);
	Gura_AssignMethod(wx_StringTokenizer, GetLastDelimiter);
	Gura_AssignMethod(wx_StringTokenizer, GetNextToken);
	Gura_AssignMethod(wx_StringTokenizer, GetPosition);
	Gura_AssignMethod(wx_StringTokenizer, GetString);
	Gura_AssignMethod(wx_StringTokenizer, HasMoreTokens);
	Gura_AssignMethod(wx_StringTokenizer, SetString);
}

Gura_ImplementDescendantCreator(wx_StringTokenizer)
{
	return new Object_wx_StringTokenizer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
