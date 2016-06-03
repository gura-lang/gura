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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__UniChar, "UniChar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_UniChar));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__UniChar)
{
	//wxUniChar();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__UniChar_1, "UniChar_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_UniChar));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__UniChar_1)
{
	//int c = arg.GetNumber(0)
	//wxUniChar();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__UniChar_2, "UniChar_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_UniChar));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__UniChar_2)
{
	//int c = arg.GetNumber(0)
	//wxUniChar();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__UniChar_3, "UniChar_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_UniChar));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__UniChar_3)
{
	//int c = arg.GetNumber(0)
	//wxUniChar();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__UniChar_4, "UniChar_4")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_UniChar));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__UniChar_4)
{
	//int c = arg.GetNumber(0)
	//wxUniChar();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__UniChar_5, "UniChar_5")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_UniChar));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__UniChar_5)
{
	//int c = arg.GetNumber(0)
	//wxUniChar();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__UniChar_6, "UniChar_6")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_UniChar));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__UniChar_6)
{
	//int c = arg.GetNumber(0)
	//wxUniChar();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__UniChar_7, "UniChar_7")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_UniChar));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__UniChar_7)
{
	//int c = arg.GetNumber(0)
	//wxUniChar();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__UniChar_8, "UniChar_8")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_UniChar));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__UniChar_8)
{
	//int c = arg.GetNumber(0)
	//wxUniChar();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__UniChar_9, "UniChar_9")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_UniChar));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__UniChar_9)
{
	//int c = arg.GetNumber(0)
	//wxUniChar();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__UniChar_10, "UniChar_10")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_UniChar));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__UniChar_10)
{
	//int c = arg.GetNumber(0)
	//wxUniChar();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__UniChar_11, "UniChar_11")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_UniChar));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__UniChar_11)
{
	//int c = arg.GetNumber(0)
	//wxUniChar();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
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
	// Constructor assignment
	Gura_AssignFunction(__UniChar);
	Gura_AssignFunction(__UniChar_1);
	Gura_AssignFunction(__UniChar_2);
	Gura_AssignFunction(__UniChar_3);
	Gura_AssignFunction(__UniChar_4);
	Gura_AssignFunction(__UniChar_5);
	Gura_AssignFunction(__UniChar_6);
	Gura_AssignFunction(__UniChar_7);
	Gura_AssignFunction(__UniChar_8);
	Gura_AssignFunction(__UniChar_9);
	Gura_AssignFunction(__UniChar_10);
	Gura_AssignFunction(__UniChar_11);
	// Method assignment
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
