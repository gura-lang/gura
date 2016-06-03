//----------------------------------------------------------------------------
// wxUString
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxUString
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxUString
//----------------------------------------------------------------------------
Object_wx_UString::~Object_wx_UString()
{
}

Object *Object_wx_UString::Clone() const
{
	return nullptr;
}

String Object_wx_UString::ToString(bool exprFlag)
{
	String rtn("<wx.UString:");
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
Gura_DeclareFunctionAlias(__wxUString, "wxUString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_UString));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxUString)
{
	//wxUString();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxUString_1, "wxUString_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_UString));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxUString_1)
{
	//int str = arg.GetNumber(0)
	//wxUString();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxUString_2, "wxUString_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_UString));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxUString_2)
{
	//int str = arg.GetNumber(0)
	//wxUString();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxUString_3, "wxUString_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_UString));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxUString_3)
{
	//int buf = arg.GetNumber(0)
	//wxUString();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxUString_4, "wxUString_4")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_UString));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxUString_4)
{
	//int str = arg.GetNumber(0)
	//wxUString();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxUString_5, "wxUString_5")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_UString));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxUString_5)
{
	//int buf = arg.GetNumber(0)
	//wxUString();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxUString_6, "wxUString_6")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_UString));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxUString_6)
{
	//int str = arg.GetNumber(0)
	//int conv = arg.GetNumber(1)
	//wxUString();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxUString_7, "wxUString_7")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_UString));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxUString_7)
{
	//int buf = arg.GetNumber(0)
	//int conv = arg.GetNumber(1)
	//wxUString();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxUString_8, "wxUString_8")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_UString));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxUString_8)
{
	//int str = arg.GetNumber(0)
	//wxUString();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxUString_9, "wxUString_9")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_UString));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxUString_9)
{
	//int buf = arg.GetNumber(0)
	//wxUString();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxUString_10, "wxUString_10")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_UString));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxUString_10)
{
	//int str = arg.GetNumber(0)
	//wxUString();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxUString_11, "wxUString_11")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_UString));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxUString_11)
{
	//int ch = arg.GetNumber(0)
	//wxUString();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxUString_12, "wxUString_12")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_UString));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxUString_12)
{
	//int ch = arg.GetNumber(0)
	//wxUString();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxUString_13, "wxUString_13")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_UString));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxUString_13)
{
	//int ch = arg.GetNumber(0)
	//wxUString();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxUString_14, "wxUString_14")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_UString));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxUString_14)
{
	//int ch = arg.GetNumber(0)
	//wxUString();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxUString_15, "wxUString_15")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_UString));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxUString_15)
{
	//int ch = arg.GetNumber(0)
	//wxUString();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxUString_16, "wxUString_16")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_UString));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxUString_16)
{
	//int n = arg.GetNumber(0)
	//int ch = arg.GetNumber(1)
	//wxUString();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxUString_17, "wxUString_17")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_UString));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxUString_17)
{
	//int n = arg.GetNumber(0)
	//int ch = arg.GetNumber(1)
	//wxUString();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxUString_18, "wxUString_18")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_UString));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxUString_18)
{
	//int n = arg.GetNumber(0)
	//int ch = arg.GetNumber(1)
	//wxUString();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxUString_19, "wxUString_19")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_UString));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxUString_19)
{
	//int n = arg.GetNumber(0)
	//int ch = arg.GetNumber(1)
	//wxUString();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxUString_20, "wxUString_20")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_UString));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxUString_20)
{
	//int n = arg.GetNumber(0)
	//int ch = arg.GetNumber(1)
	//wxUString();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_UString, __FromAscii, "FromAscii")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UString, __FromAscii)
{
	Object_wx_UString *pThis = Object_wx_UString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//int n = arg.GetNumber(1)
	//pThis->GetEntity()->FromAscii();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UString, __FromAscii_1, "FromAscii_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UString, __FromAscii_1)
{
	Object_wx_UString *pThis = Object_wx_UString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//pThis->GetEntity()->FromAscii();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UString, __FromUTF8, "FromUTF8")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UString, __FromUTF8)
{
	Object_wx_UString *pThis = Object_wx_UString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//int n = arg.GetNumber(1)
	//pThis->GetEntity()->FromUTF8();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UString, __FromUTF8_1, "FromUTF8_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UString, __FromUTF8_1)
{
	Object_wx_UString *pThis = Object_wx_UString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//pThis->GetEntity()->FromUTF8();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UString, __FromUTF16, "FromUTF16")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UString, __FromUTF16)
{
	Object_wx_UString *pThis = Object_wx_UString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//int n = arg.GetNumber(1)
	//pThis->GetEntity()->FromUTF16();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UString, __FromUTF16_1, "FromUTF16_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UString, __FromUTF16_1)
{
	Object_wx_UString *pThis = Object_wx_UString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//pThis->GetEntity()->FromUTF16();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UString, __assignFromAscii, "assignFromAscii")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UString, __assignFromAscii)
{
	Object_wx_UString *pThis = Object_wx_UString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//pThis->GetEntity()->assignFromAscii();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UString, __assignFromAscii_1, "assignFromAscii_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UString, __assignFromAscii_1)
{
	Object_wx_UString *pThis = Object_wx_UString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//int n = arg.GetNumber(1)
	//pThis->GetEntity()->assignFromAscii();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UString, __assignFromUTF8, "assignFromUTF8")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UString, __assignFromUTF8)
{
	Object_wx_UString *pThis = Object_wx_UString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//pThis->GetEntity()->assignFromUTF8();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UString, __assignFromUTF8_1, "assignFromUTF8_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UString, __assignFromUTF8_1)
{
	Object_wx_UString *pThis = Object_wx_UString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//int n = arg.GetNumber(1)
	//pThis->GetEntity()->assignFromUTF8();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UString, __assignFromUTF16, "assignFromUTF16")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UString, __assignFromUTF16)
{
	Object_wx_UString *pThis = Object_wx_UString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//pThis->GetEntity()->assignFromUTF16();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UString, __assignFromUTF16_1, "assignFromUTF16_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UString, __assignFromUTF16_1)
{
	Object_wx_UString *pThis = Object_wx_UString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//int n = arg.GetNumber(1)
	//pThis->GetEntity()->assignFromUTF16();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UString, __assignFromCString, "assignFromCString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UString, __assignFromCString)
{
	Object_wx_UString *pThis = Object_wx_UString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//pThis->GetEntity()->assignFromCString();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UString, __assignFromCString_1, "assignFromCString_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UString, __assignFromCString_1)
{
	Object_wx_UString *pThis = Object_wx_UString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//int conv = arg.GetNumber(1)
	//pThis->GetEntity()->assignFromCString();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UString, __utf8_str, "utf8_str")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_UString, __utf8_str)
{
	Object_wx_UString *pThis = Object_wx_UString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->utf8_str();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UString, __utf16_str, "utf16_str")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_UString, __utf16_str)
{
	Object_wx_UString *pThis = Object_wx_UString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->utf16_str();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UString, __wc_str, "wc_str")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_UString, __wc_str)
{
	Object_wx_UString *pThis = Object_wx_UString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wc_str();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UString, __wxString, "wxString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_UString, __wxString)
{
	Object_wx_UString *pThis = Object_wx_UString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxString();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UString, __assign, "assign")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UString, __assign)
{
	Object_wx_UString *pThis = Object_wx_UString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//pThis->GetEntity()->assign();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UString, __append, "append")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UString, __append)
{
	Object_wx_UString *pThis = Object_wx_UString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int s = arg.GetNumber(0)
	//pThis->GetEntity()->append();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UString, __insert, "insert")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UString, __insert)
{
	Object_wx_UString *pThis = Object_wx_UString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int s = arg.GetNumber(1)
	//pThis->GetEntity()->insert();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxUString
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_UString)
{
	// Constructor assignment
	Gura_AssignFunction(__wxUString);
	Gura_AssignFunction(__wxUString_1);
	Gura_AssignFunction(__wxUString_2);
	Gura_AssignFunction(__wxUString_3);
	Gura_AssignFunction(__wxUString_4);
	Gura_AssignFunction(__wxUString_5);
	Gura_AssignFunction(__wxUString_6);
	Gura_AssignFunction(__wxUString_7);
	Gura_AssignFunction(__wxUString_8);
	Gura_AssignFunction(__wxUString_9);
	Gura_AssignFunction(__wxUString_10);
	Gura_AssignFunction(__wxUString_11);
	Gura_AssignFunction(__wxUString_12);
	Gura_AssignFunction(__wxUString_13);
	Gura_AssignFunction(__wxUString_14);
	Gura_AssignFunction(__wxUString_15);
	Gura_AssignFunction(__wxUString_16);
	Gura_AssignFunction(__wxUString_17);
	Gura_AssignFunction(__wxUString_18);
	Gura_AssignFunction(__wxUString_19);
	Gura_AssignFunction(__wxUString_20);
	// Method assignment
	Gura_AssignMethod(wx_UString, __FromAscii);
	Gura_AssignMethod(wx_UString, __FromAscii_1);
	Gura_AssignMethod(wx_UString, __FromUTF8);
	Gura_AssignMethod(wx_UString, __FromUTF8_1);
	Gura_AssignMethod(wx_UString, __FromUTF16);
	Gura_AssignMethod(wx_UString, __FromUTF16_1);
	Gura_AssignMethod(wx_UString, __assignFromAscii);
	Gura_AssignMethod(wx_UString, __assignFromAscii_1);
	Gura_AssignMethod(wx_UString, __assignFromUTF8);
	Gura_AssignMethod(wx_UString, __assignFromUTF8_1);
	Gura_AssignMethod(wx_UString, __assignFromUTF16);
	Gura_AssignMethod(wx_UString, __assignFromUTF16_1);
	Gura_AssignMethod(wx_UString, __assignFromCString);
	Gura_AssignMethod(wx_UString, __assignFromCString_1);
	Gura_AssignMethod(wx_UString, __utf8_str);
	Gura_AssignMethod(wx_UString, __utf16_str);
	Gura_AssignMethod(wx_UString, __wc_str);
	Gura_AssignMethod(wx_UString, __wxString);
	Gura_AssignMethod(wx_UString, __assign);
	Gura_AssignMethod(wx_UString, __append);
	Gura_AssignMethod(wx_UString, __insert);
}

Gura_ImplementDescendantCreator(wx_UString)
{
	return new Object_wx_UString((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
