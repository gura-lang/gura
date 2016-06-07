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
Gura_DeclareFunctionAlias(__UString, "UString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_UString));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__UString)
{
	//wxUString();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__UString_1, "UString_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_UString));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__UString_1)
{
	//const wxUString& str = arg.GetNumber(0)
	//wxUString(str);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__UString_2, "UString_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_UString));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__UString_2)
{
	//const wxChar32* str = arg.GetNumber(0)
	//wxUString(str);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__UString_3, "UString_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_UString));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__UString_3)
{
	//const wxU32CharBuffer& buf = arg.GetNumber(0)
	//wxUString(buf);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__UString_4, "UString_4")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_UString));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__UString_4)
{
	//const char* str = arg.GetNumber(0)
	//wxUString(str);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__UString_5, "UString_5")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_UString));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__UString_5)
{
	//const wxCharBuffer& buf = arg.GetNumber(0)
	//wxUString(buf);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__UString_6, "UString_6")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_UString));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__UString_6)
{
	//const char* str = arg.GetNumber(0)
	//const wxMBConv& conv = arg.GetNumber(1)
	//wxUString(str, conv);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__UString_7, "UString_7")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_UString));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__UString_7)
{
	//const wxCharBuffer& buf = arg.GetNumber(0)
	//const wxMBConv& conv = arg.GetNumber(1)
	//wxUString(buf, conv);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__UString_8, "UString_8")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_UString));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__UString_8)
{
	//const wxChar16* str = arg.GetNumber(0)
	//wxUString(str);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__UString_9, "UString_9")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_UString));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__UString_9)
{
	//const wxU16CharBuffer& buf = arg.GetNumber(0)
	//wxUString(buf);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__UString_10, "UString_10")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_UString));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__UString_10)
{
	//const wxString& str = arg.GetNumber(0)
	//wxUString(str);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__UString_11, "UString_11")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_UString));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__UString_11)
{
	//char ch = arg.GetNumber(0)
	//wxUString(ch);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__UString_12, "UString_12")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_UString));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__UString_12)
{
	//wxChar16 ch = arg.GetNumber(0)
	//wxUString(ch);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__UString_13, "UString_13")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_UString));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__UString_13)
{
	//wxChar32 ch = arg.GetNumber(0)
	//wxUString(ch);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__UString_14, "UString_14")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_UString));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__UString_14)
{
	//wxUniChar ch = arg.GetNumber(0)
	//wxUString(ch);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__UString_15, "UString_15")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_UString));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__UString_15)
{
	//wxUniCharRef ch = arg.GetNumber(0)
	//wxUString(ch);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__UString_16, "UString_16")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_UString));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__UString_16)
{
	//size_t n = arg.GetNumber(0)
	//char ch = arg.GetNumber(1)
	//wxUString(n, ch);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__UString_17, "UString_17")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_UString));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__UString_17)
{
	//size_t n = arg.GetNumber(0)
	//wxChar16 ch = arg.GetNumber(1)
	//wxUString(n, ch);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__UString_18, "UString_18")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_UString));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__UString_18)
{
	//size_t n = arg.GetNumber(0)
	//wxChar32 ch = arg.GetNumber(1)
	//wxUString(n, ch);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__UString_19, "UString_19")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_UString));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__UString_19)
{
	//size_t n = arg.GetNumber(0)
	//wxUniChar ch = arg.GetNumber(1)
	//wxUString(n, ch);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__UString_20, "UString_20")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_UString));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__UString_20)
{
	//size_t n = arg.GetNumber(0)
	//wxUniCharRef ch = arg.GetNumber(1)
	//wxUString(n, ch);
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
	//const char* str = arg.GetNumber(0)
	//size_t n = arg.GetNumber(1)
	//pThis->GetEntity()->FromAscii(str, n);
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
	//const char* str = arg.GetNumber(0)
	//pThis->GetEntity()->FromAscii(str);
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
	//const char* str = arg.GetNumber(0)
	//size_t n = arg.GetNumber(1)
	//pThis->GetEntity()->FromUTF8(str, n);
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
	//const char* str = arg.GetNumber(0)
	//pThis->GetEntity()->FromUTF8(str);
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
	//const wxChar16* str = arg.GetNumber(0)
	//size_t n = arg.GetNumber(1)
	//pThis->GetEntity()->FromUTF16(str, n);
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
	//const wxChar16* str = arg.GetNumber(0)
	//pThis->GetEntity()->FromUTF16(str);
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
	//const char* str = arg.GetNumber(0)
	//pThis->GetEntity()->assignFromAscii(str);
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
	//const char* str = arg.GetNumber(0)
	//size_t n = arg.GetNumber(1)
	//pThis->GetEntity()->assignFromAscii(str, n);
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
	//const char* str = arg.GetNumber(0)
	//pThis->GetEntity()->assignFromUTF8(str);
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
	//const char* str = arg.GetNumber(0)
	//size_t n = arg.GetNumber(1)
	//pThis->GetEntity()->assignFromUTF8(str, n);
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
	//const wxChar16* str = arg.GetNumber(0)
	//pThis->GetEntity()->assignFromUTF16(str);
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
	//const wxChar16* str = arg.GetNumber(0)
	//size_t n = arg.GetNumber(1)
	//pThis->GetEntity()->assignFromUTF16(str, n);
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
	//const char* str = arg.GetNumber(0)
	//pThis->GetEntity()->assignFromCString(str);
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
	//const char* str = arg.GetNumber(0)
	//const wxMBConv& conv = arg.GetNumber(1)
	//pThis->GetEntity()->assignFromCString(str, conv);
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
	//const wxUString& str = arg.GetNumber(0)
	//pThis->GetEntity()->assign(str);
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
	//const wxUString& s = arg.GetNumber(0)
	//pThis->GetEntity()->append(s);
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
	//size_t pos = arg.GetNumber(0)
	//const wxUString& s = arg.GetNumber(1)
	//pThis->GetEntity()->insert(pos, s);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxUString
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_UString)
{
	// Constructor assignment
	Gura_AssignFunction(__UString);
	Gura_AssignFunction(__UString_1);
	Gura_AssignFunction(__UString_2);
	Gura_AssignFunction(__UString_3);
	Gura_AssignFunction(__UString_4);
	Gura_AssignFunction(__UString_5);
	Gura_AssignFunction(__UString_6);
	Gura_AssignFunction(__UString_7);
	Gura_AssignFunction(__UString_8);
	Gura_AssignFunction(__UString_9);
	Gura_AssignFunction(__UString_10);
	Gura_AssignFunction(__UString_11);
	Gura_AssignFunction(__UString_12);
	Gura_AssignFunction(__UString_13);
	Gura_AssignFunction(__UString_14);
	Gura_AssignFunction(__UString_15);
	Gura_AssignFunction(__UString_16);
	Gura_AssignFunction(__UString_17);
	Gura_AssignFunction(__UString_18);
	Gura_AssignFunction(__UString_19);
	Gura_AssignFunction(__UString_20);
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
