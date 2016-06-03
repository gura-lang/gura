//----------------------------------------------------------------------------
// wxUniChar
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxUniChar
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxUniChar
//----------------------------------------------------------------------------
Object_wx_UniChar::~Object_wx_UniChar()
{
}

Object *Object_wx_UniChar::Clone() const
{
	return nullptr;
}

String Object_wx_UniChar::ToString(bool exprFlag)
{
	String rtn("<wx.UniChar:");
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
Gura_DeclareMethodAlias(wx_UniChar, __wxUniChar, "wxUniChar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_UniChar, __wxUniChar)
{
	Object_wx_UniChar *pThis = Object_wx_UniChar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxUniChar();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UniChar, __wxUniChar_1, "wxUniChar_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UniChar, __wxUniChar_1)
{
	Object_wx_UniChar *pThis = Object_wx_UniChar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int c = arg.GetNumber(0)
	//pThis->GetEntity()->wxUniChar();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UniChar, __wxUniChar_2, "wxUniChar_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UniChar, __wxUniChar_2)
{
	Object_wx_UniChar *pThis = Object_wx_UniChar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int c = arg.GetNumber(0)
	//pThis->GetEntity()->wxUniChar();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UniChar, __wxUniChar_3, "wxUniChar_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UniChar, __wxUniChar_3)
{
	Object_wx_UniChar *pThis = Object_wx_UniChar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int c = arg.GetNumber(0)
	//pThis->GetEntity()->wxUniChar();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UniChar, __wxUniChar_4, "wxUniChar_4")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UniChar, __wxUniChar_4)
{
	Object_wx_UniChar *pThis = Object_wx_UniChar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int c = arg.GetNumber(0)
	//pThis->GetEntity()->wxUniChar();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UniChar, __wxUniChar_5, "wxUniChar_5")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UniChar, __wxUniChar_5)
{
	Object_wx_UniChar *pThis = Object_wx_UniChar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int c = arg.GetNumber(0)
	//pThis->GetEntity()->wxUniChar();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UniChar, __wxUniChar_6, "wxUniChar_6")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UniChar, __wxUniChar_6)
{
	Object_wx_UniChar *pThis = Object_wx_UniChar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int c = arg.GetNumber(0)
	//pThis->GetEntity()->wxUniChar();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UniChar, __wxUniChar_7, "wxUniChar_7")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UniChar, __wxUniChar_7)
{
	Object_wx_UniChar *pThis = Object_wx_UniChar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int c = arg.GetNumber(0)
	//pThis->GetEntity()->wxUniChar();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UniChar, __wxUniChar_8, "wxUniChar_8")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UniChar, __wxUniChar_8)
{
	Object_wx_UniChar *pThis = Object_wx_UniChar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int c = arg.GetNumber(0)
	//pThis->GetEntity()->wxUniChar();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UniChar, __wxUniChar_9, "wxUniChar_9")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UniChar, __wxUniChar_9)
{
	Object_wx_UniChar *pThis = Object_wx_UniChar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int c = arg.GetNumber(0)
	//pThis->GetEntity()->wxUniChar();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UniChar, __wxUniChar_10, "wxUniChar_10")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UniChar, __wxUniChar_10)
{
	Object_wx_UniChar *pThis = Object_wx_UniChar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int c = arg.GetNumber(0)
	//pThis->GetEntity()->wxUniChar();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UniChar, __wxUniChar_11, "wxUniChar_11")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UniChar, __wxUniChar_11)
{
	Object_wx_UniChar *pThis = Object_wx_UniChar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int c = arg.GetNumber(0)
	//pThis->GetEntity()->wxUniChar();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UniChar, __GetValue, "GetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_UniChar, __GetValue)
{
	Object_wx_UniChar *pThis = Object_wx_UniChar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UniChar, __IsAscii, "IsAscii")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_UniChar, __IsAscii)
{
	Object_wx_UniChar *pThis = Object_wx_UniChar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsAscii();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UniChar, __GetAsChar, "GetAsChar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UniChar, __GetAsChar)
{
	Object_wx_UniChar *pThis = Object_wx_UniChar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int c = arg.GetNumber(0)
	//pThis->GetEntity()->GetAsChar();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UniChar, __char, "char")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_UniChar, __char)
{
	Object_wx_UniChar *pThis = Object_wx_UniChar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->char();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UniChar, __char_1, "char_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_UniChar, __char_1)
{
	Object_wx_UniChar *pThis = Object_wx_UniChar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->char();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UniChar, __wchar_t, "wchar_t")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_UniChar, __wchar_t)
{
	Object_wx_UniChar *pThis = Object_wx_UniChar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wchar_t();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UniChar, __int, "int")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_UniChar, __int)
{
	Object_wx_UniChar *pThis = Object_wx_UniChar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->int();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UniChar, __int_1, "int_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_UniChar, __int_1)
{
	Object_wx_UniChar *pThis = Object_wx_UniChar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->int();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UniChar, __int_2, "int_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_UniChar, __int_2)
{
	Object_wx_UniChar *pThis = Object_wx_UniChar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->int();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UniChar, __int_3, "int_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_UniChar, __int_3)
{
	Object_wx_UniChar *pThis = Object_wx_UniChar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->int();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UniChar, __int_4, "int_4")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_UniChar, __int_4)
{
	Object_wx_UniChar *pThis = Object_wx_UniChar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->int();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UniChar, __int_5, "int_5")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_UniChar, __int_5)
{
	Object_wx_UniChar *pThis = Object_wx_UniChar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->int();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UniChar, __wxLongLong_t, "wxLongLong_t")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_UniChar, __wxLongLong_t)
{
	Object_wx_UniChar *pThis = Object_wx_UniChar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxLongLong_t();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UniChar, __wxULongLong_t, "wxULongLong_t")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_UniChar, __wxULongLong_t)
{
	Object_wx_UniChar *pThis = Object_wx_UniChar::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxULongLong_t();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxUniChar
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_UniChar)
{
	Gura_AssignMethod(wx_UniChar, __wxUniChar);
	Gura_AssignMethod(wx_UniChar, __wxUniChar_1);
	Gura_AssignMethod(wx_UniChar, __wxUniChar_2);
	Gura_AssignMethod(wx_UniChar, __wxUniChar_3);
	Gura_AssignMethod(wx_UniChar, __wxUniChar_4);
	Gura_AssignMethod(wx_UniChar, __wxUniChar_5);
	Gura_AssignMethod(wx_UniChar, __wxUniChar_6);
	Gura_AssignMethod(wx_UniChar, __wxUniChar_7);
	Gura_AssignMethod(wx_UniChar, __wxUniChar_8);
	Gura_AssignMethod(wx_UniChar, __wxUniChar_9);
	Gura_AssignMethod(wx_UniChar, __wxUniChar_10);
	Gura_AssignMethod(wx_UniChar, __wxUniChar_11);
	Gura_AssignMethod(wx_UniChar, __GetValue);
	Gura_AssignMethod(wx_UniChar, __IsAscii);
	Gura_AssignMethod(wx_UniChar, __GetAsChar);
	Gura_AssignMethod(wx_UniChar, __char);
	Gura_AssignMethod(wx_UniChar, __char_1);
	Gura_AssignMethod(wx_UniChar, __wchar_t);
	Gura_AssignMethod(wx_UniChar, __int);
	Gura_AssignMethod(wx_UniChar, __int_1);
	Gura_AssignMethod(wx_UniChar, __int_2);
	Gura_AssignMethod(wx_UniChar, __int_3);
	Gura_AssignMethod(wx_UniChar, __int_4);
	Gura_AssignMethod(wx_UniChar, __int_5);
	Gura_AssignMethod(wx_UniChar, __wxLongLong_t);
	Gura_AssignMethod(wx_UniChar, __wxULongLong_t);
}

Gura_ImplementDescendantCreator(wx_UniChar)
{
	return new Object_wx_UniChar((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
