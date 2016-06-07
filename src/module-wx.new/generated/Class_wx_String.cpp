//----------------------------------------------------------------------------
// wxString
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxString
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxString
//----------------------------------------------------------------------------
Object_wx_String::~Object_wx_String()
{
}

Object *Object_wx_String::Clone() const
{
	return nullptr;
}

String Object_wx_String::ToString(bool exprFlag)
{
	String rtn("<wx.String:");
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
Gura_DeclareFunctionAlias(__String, "String")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_String));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__String)
{
	//wxString();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__String_1, "String_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stringSrc", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_String));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__String_1)
{
	//const wxString& stringSrc = arg.GetNumber(0)
	//wxString(stringSrc);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__String_2, "String_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nRepeat", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_String));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__String_2)
{
	//wxUniChar ch = arg.GetNumber(0)
	//size_t nRepeat = arg.GetNumber(1)
	//wxString(ch, nRepeat);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__String_3, "String_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nRepeat", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_String));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__String_3)
{
	//wxUniCharRef ch = arg.GetNumber(0)
	//size_t nRepeat = arg.GetNumber(1)
	//wxString(ch, nRepeat);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__String_4, "String_4")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nRepeat", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_String));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__String_4)
{
	//char ch = arg.GetNumber(0)
	//size_t nRepeat = arg.GetNumber(1)
	//wxString(ch, nRepeat);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__String_5, "String_5")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nRepeat", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_String));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__String_5)
{
	//wchar_t ch = arg.GetNumber(0)
	//size_t nRepeat = arg.GetNumber(1)
	//wxString(ch, nRepeat);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__String_6, "String_6")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "psz", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_String));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__String_6)
{
	//const char* psz = arg.GetNumber(0)
	//wxString(psz);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__String_7, "String_7")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "psz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_String));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__String_7)
{
	//const char* psz = arg.GetNumber(0)
	//const wxMBConv& conv = arg.GetNumber(1)
	//wxString(psz, conv);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__String_8, "String_8")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "psz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nLength", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_String));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__String_8)
{
	//const char* psz = arg.GetNumber(0)
	//size_t nLength = arg.GetNumber(1)
	//wxString(psz, nLength);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__String_9, "String_9")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "psz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nLength", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_String));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__String_9)
{
	//const char* psz = arg.GetNumber(0)
	//const wxMBConv& conv = arg.GetNumber(1)
	//size_t nLength = arg.GetNumber(2)
	//wxString(psz, conv, nLength);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__String_10, "String_10")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pwz", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_String));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__String_10)
{
	//const wchar_t* pwz = arg.GetNumber(0)
	//wxString(pwz);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__String_11, "String_11")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pwz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nLength", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_String));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__String_11)
{
	//const wchar_t* pwz = arg.GetNumber(0)
	//size_t nLength = arg.GetNumber(1)
	//wxString(pwz, nLength);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__String_12, "String_12")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_String));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__String_12)
{
	//const wxCharBuffer& buf = arg.GetNumber(0)
	//wxString(buf);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__String_13, "String_13")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_String));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__String_13)
{
	//const wxWCharBuffer& buf = arg.GetNumber(0)
	//wxString(buf);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__String_14, "String_14")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_String));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__String_14)
{
	//const std::string& str = arg.GetNumber(0)
	//wxString(str);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__String_15, "String_15")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_String));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__String_15)
{
	//const std::wstring& str = arg.GetNumber(0)
	//wxString(str);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_String, __Len, "Len")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, __Len)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Len();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __Length, "Length")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, __Length)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Length();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __IsEmpty, "IsEmpty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, __IsEmpty)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsEmpty();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __IsNull, "IsNull")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, __IsNull)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsNull();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __GetChar, "GetChar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __GetChar)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t n = arg.GetNumber(0)
	//pThis->GetEntity()->GetChar(n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __GetData, "GetData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, __GetData)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __GetWritableChar, "GetWritableChar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __GetWritableChar)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t n = arg.GetNumber(0)
	//pThis->GetEntity()->GetWritableChar(n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __GetWriteBuf, "GetWriteBuf")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __GetWriteBuf)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t len = arg.GetNumber(0)
	//pThis->GetEntity()->GetWriteBuf(len);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __UngetWriteBuf, "UngetWriteBuf")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, __UngetWriteBuf)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->UngetWriteBuf();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __UngetWriteBuf_1, "UngetWriteBuf_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __UngetWriteBuf_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t len = arg.GetNumber(0)
	//pThis->GetEntity()->UngetWriteBuf(len);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __SetChar, "SetChar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __SetChar)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t n = arg.GetNumber(0)
	//wxUniChar ch = arg.GetNumber(1)
	//pThis->GetEntity()->SetChar(n, ch);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __Last, "Last")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, __Last)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Last();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __Last_1, "Last_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, __Last_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Last();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __c_str, "c_str")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, __c_str)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->c_str();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __char_str, "char_str")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __char_str)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxMBConv& conv = arg.GetNumber(0)
	//pThis->GetEntity()->char_str(conv);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __tchar_str, "tchar_str")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __tchar_str)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t* len = arg.GetNumber(0)
	//pThis->GetEntity()->tchar_str(len);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __fn_str, "fn_str")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, __fn_str)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->fn_str();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __fn_str_1, "fn_str_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, __fn_str_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->fn_str();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __fn_str_2, "fn_str_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, __fn_str_2)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->fn_str();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __mb_str, "mb_str")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __mb_str)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxMBConv& conv = arg.GetNumber(0)
	//pThis->GetEntity()->mb_str(conv);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __utf8_str, "utf8_str")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, __utf8_str)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->utf8_str();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __wc_str, "wc_str")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, __wc_str)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wc_str();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __wc_str_1, "wc_str_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, __wc_str_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wc_str();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __wchar_str, "wchar_str")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, __wchar_str)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wchar_str();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __wx_str, "wx_str")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, __wx_str)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wx_str();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __To8BitData, "To8BitData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, __To8BitData)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->To8BitData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __ToAscii, "ToAscii")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "replaceWith", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __ToAscii)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//char replaceWith = arg.GetNumber(0)
	//pThis->GetEntity()->ToAscii(replaceWith);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __ToAscii_1, "ToAscii_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "replaceWith", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __ToAscii_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//char replaceWith = arg.GetNumber(0)
	//pThis->GetEntity()->ToAscii(replaceWith);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __ToStdString, "ToStdString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, __ToStdString)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ToStdString();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __ToStdWstring, "ToStdWstring")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, __ToStdWstring)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ToStdWstring();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __ToUTF8, "ToUTF8")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, __ToUTF8)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ToUTF8();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __Append, "Append")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "psz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __Append)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const char* psz = arg.GetNumber(0)
	//pThis->GetEntity()->Append(psz);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __Append_1, "Append_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pwz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __Append_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wchar_t* pwz = arg.GetNumber(0)
	//pThis->GetEntity()->Append(pwz);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __Append_2, "Append_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "psz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nLen", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __Append_2)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const char* psz = arg.GetNumber(0)
	//size_t nLen = arg.GetNumber(1)
	//pThis->GetEntity()->Append(psz, nLen);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __Append_3, "Append_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pwz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nLen", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __Append_3)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wchar_t* pwz = arg.GetNumber(0)
	//size_t nLen = arg.GetNumber(1)
	//pThis->GetEntity()->Append(pwz, nLen);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __Append_4, "Append_4")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __Append_4)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& s = arg.GetNumber(0)
	//pThis->GetEntity()->Append(s);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __Append_5, "Append_5")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "count", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __Append_5)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxUniChar ch = arg.GetNumber(0)
	//size_t count = arg.GetNumber(1)
	//pThis->GetEntity()->Append(ch, count);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __Prepend, "Prepend")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __Prepend)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& str = arg.GetNumber(0)
	//pThis->GetEntity()->Prepend(str);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __Cmp, "Cmp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __Cmp)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& s = arg.GetNumber(0)
	//pThis->GetEntity()->Cmp(s);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __CmpNoCase, "CmpNoCase")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __CmpNoCase)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& s = arg.GetNumber(0)
	//pThis->GetEntity()->CmpNoCase(s);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __IsSameAs, "IsSameAs")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "caseSensitive", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __IsSameAs)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& s = arg.GetNumber(0)
	//bool caseSensitive = arg.GetNumber(1)
	//pThis->GetEntity()->IsSameAs(s, caseSensitive);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __IsSameAs_1, "IsSameAs_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "caseSensitive", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __IsSameAs_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxUniChar ch = arg.GetNumber(0)
	//bool caseSensitive = arg.GetNumber(1)
	//pThis->GetEntity()->IsSameAs(ch, caseSensitive);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __Matches, "Matches")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mask", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __Matches)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& mask = arg.GetNumber(0)
	//pThis->GetEntity()->Matches(mask);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __StartsWith, "StartsWith")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "prefix", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rest", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __StartsWith)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& prefix = arg.GetNumber(0)
	//wxString* rest = arg.GetNumber(1)
	//pThis->GetEntity()->StartsWith(prefix, rest);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __EndsWith, "EndsWith")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "suffix", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rest", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __EndsWith)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& suffix = arg.GetNumber(0)
	//wxString* rest = arg.GetNumber(1)
	//pThis->GetEntity()->EndsWith(suffix, rest);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __Mid, "Mid")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "first", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nCount", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __Mid)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t first = arg.GetNumber(0)
	//size_t nCount = arg.GetNumber(1)
	//pThis->GetEntity()->Mid(first, nCount);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __SubString, "SubString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __SubString)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t from = arg.GetNumber(0)
	//size_t to = arg.GetNumber(1)
	//pThis->GetEntity()->SubString(from, to);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __operator, "operator")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __operator)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//)(size_t start = arg.GetNumber(0)
	//size_t len = arg.GetNumber(1)
	//pThis->GetEntity()->operator(start, len);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __Left, "Left")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "count", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __Left)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t count = arg.GetNumber(0)
	//pThis->GetEntity()->Left(count);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __Right, "Right")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "count", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __Right)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t count = arg.GetNumber(0)
	//pThis->GetEntity()->Right(count);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __AfterFirst, "AfterFirst")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __AfterFirst)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxUniChar ch = arg.GetNumber(0)
	//pThis->GetEntity()->AfterFirst(ch);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __AfterLast, "AfterLast")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __AfterLast)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxUniChar ch = arg.GetNumber(0)
	//pThis->GetEntity()->AfterLast(ch);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __BeforeFirst, "BeforeFirst")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rest", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __BeforeFirst)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxUniChar ch = arg.GetNumber(0)
	//wxString* rest = arg.GetNumber(1)
	//pThis->GetEntity()->BeforeFirst(ch, rest);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __BeforeLast, "BeforeLast")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rest", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __BeforeLast)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxUniChar ch = arg.GetNumber(0)
	//wxString* rest = arg.GetNumber(1)
	//pThis->GetEntity()->BeforeLast(ch, rest);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __Capitalize, "Capitalize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, __Capitalize)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Capitalize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __Lower, "Lower")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, __Lower)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Lower();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __LowerCase, "LowerCase")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, __LowerCase)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->LowerCase();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __MakeCapitalized, "MakeCapitalized")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, __MakeCapitalized)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->MakeCapitalized();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __MakeLower, "MakeLower")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, __MakeLower)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->MakeLower();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __MakeUpper, "MakeUpper")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, __MakeUpper)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->MakeUpper();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __Upper, "Upper")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, __Upper)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Upper();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __UpperCase, "UpperCase")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, __UpperCase)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->UpperCase();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __Find, "Find")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fromEnd", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __Find)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxUniChar ch = arg.GetNumber(0)
	//bool fromEnd = arg.GetNumber(1)
	//pThis->GetEntity()->Find(ch, fromEnd);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __Find_1, "Find_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sub", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __Find_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& sub = arg.GetNumber(0)
	//pThis->GetEntity()->Find(sub);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __First, "First")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __First)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxUniChar ch = arg.GetNumber(0)
	//pThis->GetEntity()->First(ch);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __First_1, "First_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __First_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& str = arg.GetNumber(0)
	//pThis->GetEntity()->First(str);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __Replace, "Replace")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "strOld", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "strNew", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "replaceAll", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __Replace)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& strOld = arg.GetNumber(0)
	//const wxString& strNew = arg.GetNumber(1)
	//bool replaceAll = arg.GetNumber(2)
	//pThis->GetEntity()->Replace(strOld, strNew, replaceAll);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __ToDouble, "ToDouble")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __ToDouble)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//double* val = arg.GetNumber(0)
	//pThis->GetEntity()->ToDouble(val);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __ToCDouble, "ToCDouble")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __ToCDouble)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//double* val = arg.GetNumber(0)
	//pThis->GetEntity()->ToCDouble(val);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __ToLong, "ToLong")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "base", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __ToLong)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long* val = arg.GetNumber(0)
	//int base = arg.GetNumber(1)
	//pThis->GetEntity()->ToLong(val, base);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __ToCLong, "ToCLong")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "base", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __ToCLong)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long* val = arg.GetNumber(0)
	//int base = arg.GetNumber(1)
	//pThis->GetEntity()->ToCLong(val, base);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __ToLongLong, "ToLongLong")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "base", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __ToLongLong)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxLongLong_t* val = arg.GetNumber(0)
	//int base = arg.GetNumber(1)
	//pThis->GetEntity()->ToLongLong(val, base);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __ToULong, "ToULong")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "base", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __ToULong)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned long* val = arg.GetNumber(0)
	//int base = arg.GetNumber(1)
	//pThis->GetEntity()->ToULong(val, base);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __ToCULong, "ToCULong")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "base", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __ToCULong)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned long* val = arg.GetNumber(0)
	//int base = arg.GetNumber(1)
	//pThis->GetEntity()->ToCULong(val, base);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __ToULongLong, "ToULongLong")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "base", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __ToULongLong)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxULongLong_t* val = arg.GetNumber(0)
	//int base = arg.GetNumber(1)
	//pThis->GetEntity()->ToULongLong(val, base);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __PrintfV, "PrintfV")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pszFormat", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "argPtr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __PrintfV)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& pszFormat = arg.GetNumber(0)
	//va_list argPtr = arg.GetNumber(1)
	//pThis->GetEntity()->PrintfV(pszFormat, argPtr);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __Alloc, "Alloc")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nLen", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __Alloc)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t nLen = arg.GetNumber(0)
	//pThis->GetEntity()->Alloc(nLen);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __Shrink, "Shrink")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, __Shrink)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Shrink();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __Clone, "Clone")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, __Clone)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clone();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __Clear, "Clear")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, __Clear)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __Contains, "Contains")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __Contains)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& str = arg.GetNumber(0)
	//pThis->GetEntity()->Contains(str);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __Empty, "Empty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, __Empty)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Empty();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __Freq, "Freq")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __Freq)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxUniChar ch = arg.GetNumber(0)
	//pThis->GetEntity()->Freq(ch);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __IsAscii, "IsAscii")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, __IsAscii)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsAscii();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __IsNumber, "IsNumber")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, __IsNumber)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsNumber();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __IsWord, "IsWord")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, __IsWord)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsWord();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __Pad, "Pad")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "count", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "chPad", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fromRight", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __Pad)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t count = arg.GetNumber(0)
	//wxUniChar chPad = arg.GetNumber(1)
	//bool fromRight = arg.GetNumber(2)
	//pThis->GetEntity()->Pad(count, chPad, fromRight);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __Remove, "Remove")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __Remove)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t pos = arg.GetNumber(0)
	//pThis->GetEntity()->Remove(pos);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __Remove_1, "Remove_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __Remove_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t pos = arg.GetNumber(0)
	//size_t len = arg.GetNumber(1)
	//pThis->GetEntity()->Remove(pos, len);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __RemoveLast, "RemoveLast")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __RemoveLast)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t n = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveLast(n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __Strip, "Strip")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __Strip)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//stripType s = arg.GetNumber(0)
	//pThis->GetEntity()->Strip(s);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __Trim, "Trim")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fromRight", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __Trim)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool fromRight = arg.GetNumber(0)
	//pThis->GetEntity()->Trim(fromRight);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __Truncate, "Truncate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __Truncate)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t len = arg.GetNumber(0)
	//pThis->GetEntity()->Truncate(len);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __begin, "begin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, __begin)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->begin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __begin_1, "begin_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, __begin_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->begin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __end, "end")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, __end)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->end();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __end_1, "end_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, __end_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->end();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __rbegin, "rbegin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, __rbegin)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->rbegin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __rbegin_1, "rbegin_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, __rbegin_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->rbegin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __rend, "rend")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, __rend)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->rend();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __rend_1, "rend_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, __rend_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->rend();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __append, "append")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __append)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& str = arg.GetNumber(0)
	//size_t pos = arg.GetNumber(1)
	//size_t n = arg.GetNumber(2)
	//pThis->GetEntity()->append(str, pos, n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __append_1, "append_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __append_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& str = arg.GetNumber(0)
	//pThis->GetEntity()->append(str);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __append_2, "append_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __append_2)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const char* sz = arg.GetNumber(0)
	//size_t n = arg.GetNumber(1)
	//pThis->GetEntity()->append(sz, n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __append_3, "append_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __append_3)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wchar_t* sz = arg.GetNumber(0)
	//size_t n = arg.GetNumber(1)
	//pThis->GetEntity()->append(sz, n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __append_4, "append_4")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __append_4)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t n = arg.GetNumber(0)
	//wxUniChar ch = arg.GetNumber(1)
	//pThis->GetEntity()->append(n, ch);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __append_5, "append_5")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "first", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "last", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __append_5)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const_iterator first = arg.GetNumber(0)
	//const_iterator last = arg.GetNumber(1)
	//pThis->GetEntity()->append(first, last);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __assign, "assign")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __assign)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& str = arg.GetNumber(0)
	//size_t pos = arg.GetNumber(1)
	//size_t n = arg.GetNumber(2)
	//pThis->GetEntity()->assign(str, pos, n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __assign_1, "assign_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __assign_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& str = arg.GetNumber(0)
	//pThis->GetEntity()->assign(str);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __assign_2, "assign_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __assign_2)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const char* sz = arg.GetNumber(0)
	//size_t n = arg.GetNumber(1)
	//pThis->GetEntity()->assign(sz, n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __assign_3, "assign_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __assign_3)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wchar_t* sz = arg.GetNumber(0)
	//size_t n = arg.GetNumber(1)
	//pThis->GetEntity()->assign(sz, n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __assign_4, "assign_4")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __assign_4)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t n = arg.GetNumber(0)
	//wxUniChar ch = arg.GetNumber(1)
	//pThis->GetEntity()->assign(n, ch);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __assign_5, "assign_5")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "first", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "last", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __assign_5)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const_iterator first = arg.GetNumber(0)
	//const_iterator last = arg.GetNumber(1)
	//pThis->GetEntity()->assign(first, last);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __at, "at")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __at)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t n = arg.GetNumber(0)
	//pThis->GetEntity()->at(n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __at_1, "at_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __at_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t n = arg.GetNumber(0)
	//pThis->GetEntity()->at(n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __clear, "clear")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, __clear)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->clear();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __capacity, "capacity")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, __capacity)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->capacity();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __compare, "compare")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __compare)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& str = arg.GetNumber(0)
	//pThis->GetEntity()->compare(str);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __compare_1, "compare_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nLen", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __compare_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t nStart = arg.GetNumber(0)
	//size_t nLen = arg.GetNumber(1)
	//const wxString& str = arg.GetNumber(2)
	//pThis->GetEntity()->compare(nStart, nLen, str);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __compare_2, "compare_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nLen", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart2", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nLen2", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __compare_2)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t nStart = arg.GetNumber(0)
	//size_t nLen = arg.GetNumber(1)
	//const wxString& str = arg.GetNumber(2)
	//size_t nStart2 = arg.GetNumber(3)
	//size_t nLen2 = arg.GetNumber(4)
	//pThis->GetEntity()->compare(nStart, nLen, str, nStart2, nLen2);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __compare_3, "compare_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nLen", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nCount", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __compare_3)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t nStart = arg.GetNumber(0)
	//size_t nLen = arg.GetNumber(1)
	//const char* sz = arg.GetNumber(2)
	//size_t nCount = arg.GetNumber(3)
	//pThis->GetEntity()->compare(nStart, nLen, sz, nCount);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __compare_4, "compare_4")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nLen", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nCount", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __compare_4)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t nStart = arg.GetNumber(0)
	//size_t nLen = arg.GetNumber(1)
	//const wchar_t* sz = arg.GetNumber(2)
	//size_t nCount = arg.GetNumber(3)
	//pThis->GetEntity()->compare(nStart, nLen, sz, nCount);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __data, "data")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, __data)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->data();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __empty, "empty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, __empty)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->empty();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __erase, "erase")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __erase)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_type pos = arg.GetNumber(0)
	//size_type n = arg.GetNumber(1)
	//pThis->GetEntity()->erase(pos, n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __erase_1, "erase_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "first", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "last", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __erase_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//iterator first = arg.GetNumber(0)
	//iterator last = arg.GetNumber(1)
	//pThis->GetEntity()->erase(first, last);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __erase_2, "erase_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "first", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __erase_2)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//iterator first = arg.GetNumber(0)
	//pThis->GetEntity()->erase(first);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __find, "find")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __find)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& str = arg.GetNumber(0)
	//size_t nStart = arg.GetNumber(1)
	//pThis->GetEntity()->find(str, nStart);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __find_1, "find_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __find_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const char* sz = arg.GetNumber(0)
	//size_t nStart = arg.GetNumber(1)
	//size_t n = arg.GetNumber(2)
	//pThis->GetEntity()->find(sz, nStart, n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __find_2, "find_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __find_2)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wchar_t* sz = arg.GetNumber(0)
	//size_t nStart = arg.GetNumber(1)
	//size_t n = arg.GetNumber(2)
	//pThis->GetEntity()->find(sz, nStart, n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __find_3, "find_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __find_3)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxUniChar ch = arg.GetNumber(0)
	//size_t nStart = arg.GetNumber(1)
	//pThis->GetEntity()->find(ch, nStart);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __find_first_of, "find_first_of")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __find_first_of)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const char* sz = arg.GetNumber(0)
	//size_t nStart = arg.GetNumber(1)
	//pThis->GetEntity()->find_first_of(sz, nStart);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __find_first_of_1, "find_first_of_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __find_first_of_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wchar_t* sz = arg.GetNumber(0)
	//size_t nStart = arg.GetNumber(1)
	//pThis->GetEntity()->find_first_of(sz, nStart);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __find_first_of_2, "find_first_of_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __find_first_of_2)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const char* sz = arg.GetNumber(0)
	//size_t nStart = arg.GetNumber(1)
	//size_t n = arg.GetNumber(2)
	//pThis->GetEntity()->find_first_of(sz, nStart, n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __find_first_of_3, "find_first_of_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __find_first_of_3)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wchar_t* sz = arg.GetNumber(0)
	//size_t nStart = arg.GetNumber(1)
	//size_t n = arg.GetNumber(2)
	//pThis->GetEntity()->find_first_of(sz, nStart, n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __find_first_of_4, "find_first_of_4")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __find_first_of_4)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxUniChar c = arg.GetNumber(0)
	//size_t nStart = arg.GetNumber(1)
	//pThis->GetEntity()->find_first_of(c, nStart);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __find_last_of, "find_last_of")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __find_last_of)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& str = arg.GetNumber(0)
	//size_t nStart = arg.GetNumber(1)
	//pThis->GetEntity()->find_last_of(str, nStart);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __find_last_of_1, "find_last_of_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __find_last_of_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const char* sz = arg.GetNumber(0)
	//size_t nStart = arg.GetNumber(1)
	//pThis->GetEntity()->find_last_of(sz, nStart);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __find_last_of_2, "find_last_of_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __find_last_of_2)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wchar_t* sz = arg.GetNumber(0)
	//size_t nStart = arg.GetNumber(1)
	//pThis->GetEntity()->find_last_of(sz, nStart);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __find_last_of_3, "find_last_of_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __find_last_of_3)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const char* sz = arg.GetNumber(0)
	//size_t nStart = arg.GetNumber(1)
	//size_t n = arg.GetNumber(2)
	//pThis->GetEntity()->find_last_of(sz, nStart, n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __find_last_of_4, "find_last_of_4")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __find_last_of_4)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wchar_t* sz = arg.GetNumber(0)
	//size_t nStart = arg.GetNumber(1)
	//size_t n = arg.GetNumber(2)
	//pThis->GetEntity()->find_last_of(sz, nStart, n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __find_last_of_5, "find_last_of_5")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __find_last_of_5)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxUniChar c = arg.GetNumber(0)
	//size_t nStart = arg.GetNumber(1)
	//pThis->GetEntity()->find_last_of(c, nStart);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __find_first_not_of, "find_first_not_of")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __find_first_not_of)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& str = arg.GetNumber(0)
	//size_t nStart = arg.GetNumber(1)
	//pThis->GetEntity()->find_first_not_of(str, nStart);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __find_first_not_of_1, "find_first_not_of_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __find_first_not_of_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const char* sz = arg.GetNumber(0)
	//size_t nStart = arg.GetNumber(1)
	//pThis->GetEntity()->find_first_not_of(sz, nStart);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __find_first_not_of_2, "find_first_not_of_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __find_first_not_of_2)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wchar_t* sz = arg.GetNumber(0)
	//size_t nStart = arg.GetNumber(1)
	//pThis->GetEntity()->find_first_not_of(sz, nStart);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __find_first_not_of_3, "find_first_not_of_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __find_first_not_of_3)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const char* sz = arg.GetNumber(0)
	//size_t nStart = arg.GetNumber(1)
	//size_t n = arg.GetNumber(2)
	//pThis->GetEntity()->find_first_not_of(sz, nStart, n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __find_first_not_of_4, "find_first_not_of_4")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __find_first_not_of_4)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wchar_t* sz = arg.GetNumber(0)
	//size_t nStart = arg.GetNumber(1)
	//size_t n = arg.GetNumber(2)
	//pThis->GetEntity()->find_first_not_of(sz, nStart, n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __find_first_not_of_5, "find_first_not_of_5")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __find_first_not_of_5)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxUniChar ch = arg.GetNumber(0)
	//size_t nStart = arg.GetNumber(1)
	//pThis->GetEntity()->find_first_not_of(ch, nStart);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __find_last_not_of, "find_last_not_of")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __find_last_not_of)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& str = arg.GetNumber(0)
	//size_t nStart = arg.GetNumber(1)
	//pThis->GetEntity()->find_last_not_of(str, nStart);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __find_last_not_of_1, "find_last_not_of_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __find_last_not_of_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const char* sz = arg.GetNumber(0)
	//size_t nStart = arg.GetNumber(1)
	//pThis->GetEntity()->find_last_not_of(sz, nStart);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __find_last_not_of_2, "find_last_not_of_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __find_last_not_of_2)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wchar_t* sz = arg.GetNumber(0)
	//size_t nStart = arg.GetNumber(1)
	//pThis->GetEntity()->find_last_not_of(sz, nStart);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __find_last_not_of_3, "find_last_not_of_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __find_last_not_of_3)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const char* sz = arg.GetNumber(0)
	//size_t nStart = arg.GetNumber(1)
	//size_t n = arg.GetNumber(2)
	//pThis->GetEntity()->find_last_not_of(sz, nStart, n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __find_last_not_of_4, "find_last_not_of_4")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __find_last_not_of_4)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wchar_t* sz = arg.GetNumber(0)
	//size_t nStart = arg.GetNumber(1)
	//size_t n = arg.GetNumber(2)
	//pThis->GetEntity()->find_last_not_of(sz, nStart, n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __insert, "insert")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nPos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __insert)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t nPos = arg.GetNumber(0)
	//const wxString& str = arg.GetNumber(1)
	//pThis->GetEntity()->insert(nPos, str);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __insert_1, "insert_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nPos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __insert_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t nPos = arg.GetNumber(0)
	//const wxString& str = arg.GetNumber(1)
	//size_t nStart = arg.GetNumber(2)
	//size_t n = arg.GetNumber(3)
	//pThis->GetEntity()->insert(nPos, str, nStart, n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __insert_2, "insert_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nPos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __insert_2)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t nPos = arg.GetNumber(0)
	//const char* sz = arg.GetNumber(1)
	//size_t n = arg.GetNumber(2)
	//pThis->GetEntity()->insert(nPos, sz, n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __insert_3, "insert_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nPos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __insert_3)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t nPos = arg.GetNumber(0)
	//const wchar_t* sz = arg.GetNumber(1)
	//size_t n = arg.GetNumber(2)
	//pThis->GetEntity()->insert(nPos, sz, n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __insert_4, "insert_4")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nPos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __insert_4)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t nPos = arg.GetNumber(0)
	//size_t n = arg.GetNumber(1)
	//wxUniChar ch = arg.GetNumber(2)
	//pThis->GetEntity()->insert(nPos, n, ch);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __insert_5, "insert_5")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "it", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __insert_5)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//iterator it = arg.GetNumber(0)
	//wxUniChar ch = arg.GetNumber(1)
	//pThis->GetEntity()->insert(it, ch);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __insert_6, "insert_6")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "it", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "first", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "last", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __insert_6)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//iterator it = arg.GetNumber(0)
	//const_iterator first = arg.GetNumber(1)
	//const_iterator last = arg.GetNumber(2)
	//pThis->GetEntity()->insert(it, first, last);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __insert_7, "insert_7")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "it", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __insert_7)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//iterator it = arg.GetNumber(0)
	//size_type n = arg.GetNumber(1)
	//wxUniChar ch = arg.GetNumber(2)
	//pThis->GetEntity()->insert(it, n, ch);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __length, "length")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, __length)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->length();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __max_size, "max_size")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, __max_size)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->max_size();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __reserve, "reserve")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __reserve)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t sz = arg.GetNumber(0)
	//pThis->GetEntity()->reserve(sz);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __resize, "resize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nSize", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __resize)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t nSize = arg.GetNumber(0)
	//wxUniChar ch = arg.GetNumber(1)
	//pThis->GetEntity()->resize(nSize, ch);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __replace, "replace")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nLen", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __replace)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t nStart = arg.GetNumber(0)
	//size_t nLen = arg.GetNumber(1)
	//const wxString& str = arg.GetNumber(2)
	//pThis->GetEntity()->replace(nStart, nLen, str);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __replace_1, "replace_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nLen", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nCount", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __replace_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t nStart = arg.GetNumber(0)
	//size_t nLen = arg.GetNumber(1)
	//size_t nCount = arg.GetNumber(2)
	//wxUniChar ch = arg.GetNumber(3)
	//pThis->GetEntity()->replace(nStart, nLen, nCount, ch);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __replace_2, "replace_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nLen", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart2", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nLen2", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __replace_2)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t nStart = arg.GetNumber(0)
	//size_t nLen = arg.GetNumber(1)
	//const wxString& str = arg.GetNumber(2)
	//size_t nStart2 = arg.GetNumber(3)
	//size_t nLen2 = arg.GetNumber(4)
	//pThis->GetEntity()->replace(nStart, nLen, str, nStart2, nLen2);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __replace_3, "replace_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nLen", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nCount", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __replace_3)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t nStart = arg.GetNumber(0)
	//size_t nLen = arg.GetNumber(1)
	//const char* sz = arg.GetNumber(2)
	//size_t nCount = arg.GetNumber(3)
	//pThis->GetEntity()->replace(nStart, nLen, sz, nCount);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __replace_4, "replace_4")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nLen", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nCount", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __replace_4)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t nStart = arg.GetNumber(0)
	//size_t nLen = arg.GetNumber(1)
	//const wchar_t* sz = arg.GetNumber(2)
	//size_t nCount = arg.GetNumber(3)
	//pThis->GetEntity()->replace(nStart, nLen, sz, nCount);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __replace_5, "replace_5")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nLen", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nCount", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __replace_5)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t nStart = arg.GetNumber(0)
	//size_t nLen = arg.GetNumber(1)
	//const wxString& s = arg.GetNumber(2)
	//size_t nCount = arg.GetNumber(3)
	//pThis->GetEntity()->replace(nStart, nLen, s, nCount);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __replace_6, "replace_6")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "first", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "last", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __replace_6)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//iterator first = arg.GetNumber(0)
	//iterator last = arg.GetNumber(1)
	//const wxString& s = arg.GetNumber(2)
	//pThis->GetEntity()->replace(first, last, s);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __replace_7, "replace_7")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "first", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "last", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __replace_7)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//iterator first = arg.GetNumber(0)
	//iterator last = arg.GetNumber(1)
	//const char* s = arg.GetNumber(2)
	//size_type n = arg.GetNumber(3)
	//pThis->GetEntity()->replace(first, last, s, n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __replace_8, "replace_8")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "first", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "last", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __replace_8)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//iterator first = arg.GetNumber(0)
	//iterator last = arg.GetNumber(1)
	//const wchar_t* s = arg.GetNumber(2)
	//size_type n = arg.GetNumber(3)
	//pThis->GetEntity()->replace(first, last, s, n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __replace_9, "replace_9")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "first", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "last", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __replace_9)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//iterator first = arg.GetNumber(0)
	//iterator last = arg.GetNumber(1)
	//size_type n = arg.GetNumber(2)
	//wxUniChar ch = arg.GetNumber(3)
	//pThis->GetEntity()->replace(first, last, n, ch);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __replace_10, "replace_10")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "first", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "last", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "first1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "last1", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __replace_10)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//iterator first = arg.GetNumber(0)
	//iterator last = arg.GetNumber(1)
	//const_iterator first1 = arg.GetNumber(2)
	//const_iterator last1 = arg.GetNumber(3)
	//pThis->GetEntity()->replace(first, last, first1, last1);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __replace_11, "replace_11")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "first", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "last", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "first1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "last1", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __replace_11)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//iterator first = arg.GetNumber(0)
	//iterator last = arg.GetNumber(1)
	//const char* first1 = arg.GetNumber(2)
	//const char* last1 = arg.GetNumber(3)
	//pThis->GetEntity()->replace(first, last, first1, last1);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __replace_12, "replace_12")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "first", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "last", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "first1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "last1", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __replace_12)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//iterator first = arg.GetNumber(0)
	//iterator last = arg.GetNumber(1)
	//const wchar_t* first1 = arg.GetNumber(2)
	//const wchar_t* last1 = arg.GetNumber(3)
	//pThis->GetEntity()->replace(first, last, first1, last1);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __rfind, "rfind")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __rfind)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& str = arg.GetNumber(0)
	//size_t nStart = arg.GetNumber(1)
	//pThis->GetEntity()->rfind(str, nStart);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __rfind_1, "rfind_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __rfind_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const char* sz = arg.GetNumber(0)
	//size_t nStart = arg.GetNumber(1)
	//size_t n = arg.GetNumber(2)
	//pThis->GetEntity()->rfind(sz, nStart, n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __rfind_2, "rfind_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __rfind_2)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wchar_t* sz = arg.GetNumber(0)
	//size_t nStart = arg.GetNumber(1)
	//size_t n = arg.GetNumber(2)
	//pThis->GetEntity()->rfind(sz, nStart, n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __rfind_3, "rfind_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __rfind_3)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxUniChar ch = arg.GetNumber(0)
	//size_t nStart = arg.GetNumber(1)
	//pThis->GetEntity()->rfind(ch, nStart);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __size, "size")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, __size)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->size();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __substr, "substr")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nLen", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __substr)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t nStart = arg.GetNumber(0)
	//size_t nLen = arg.GetNumber(1)
	//pThis->GetEntity()->substr(nStart, nLen);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __swap, "swap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __swap)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString& str = arg.GetNumber(0)
	//pThis->GetEntity()->swap(str);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __FormatV, "FormatV")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "argptr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __FormatV)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& format = arg.GetNumber(0)
	//va_list argptr = arg.GetNumber(1)
	//pThis->GetEntity()->FormatV(format, argptr);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __From8BitData, "From8BitData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __From8BitData)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const char* buf = arg.GetNumber(0)
	//size_t len = arg.GetNumber(1)
	//pThis->GetEntity()->From8BitData(buf, len);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __From8BitData_1, "From8BitData_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __From8BitData_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const char* buf = arg.GetNumber(0)
	//pThis->GetEntity()->From8BitData(buf);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __FromAscii, "FromAscii")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __FromAscii)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const char* s = arg.GetNumber(0)
	//pThis->GetEntity()->FromAscii(s);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __FromAscii_1, "FromAscii_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __FromAscii_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const unsigned char* s = arg.GetNumber(0)
	//pThis->GetEntity()->FromAscii(s);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __FromAscii_2, "FromAscii_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __FromAscii_2)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const char* s = arg.GetNumber(0)
	//size_t len = arg.GetNumber(1)
	//pThis->GetEntity()->FromAscii(s, len);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __FromAscii_3, "FromAscii_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __FromAscii_3)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const unsigned char* s = arg.GetNumber(0)
	//size_t len = arg.GetNumber(1)
	//pThis->GetEntity()->FromAscii(s, len);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __FromAscii_4, "FromAscii_4")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __FromAscii_4)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//char c = arg.GetNumber(0)
	//pThis->GetEntity()->FromAscii(c);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __FromCDouble, "FromCDouble")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "precision", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __FromCDouble)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//double val = arg.GetNumber(0)
	//int precision = arg.GetNumber(1)
	//pThis->GetEntity()->FromCDouble(val, precision);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __FromDouble, "FromDouble")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "precision", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __FromDouble)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//double val = arg.GetNumber(0)
	//int precision = arg.GetNumber(1)
	//pThis->GetEntity()->FromDouble(val, precision);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __FromUTF8, "FromUTF8")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __FromUTF8)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const char* s = arg.GetNumber(0)
	//pThis->GetEntity()->FromUTF8(s);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __FromUTF8_1, "FromUTF8_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __FromUTF8_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const char* s = arg.GetNumber(0)
	//size_t len = arg.GetNumber(1)
	//pThis->GetEntity()->FromUTF8(s, len);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __FromUTF8Unchecked, "FromUTF8Unchecked")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __FromUTF8Unchecked)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const char* s = arg.GetNumber(0)
	//pThis->GetEntity()->FromUTF8Unchecked(s);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_String, __FromUTF8Unchecked_1, "FromUTF8Unchecked_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, __FromUTF8Unchecked_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const char* s = arg.GetNumber(0)
	//size_t len = arg.GetNumber(1)
	//pThis->GetEntity()->FromUTF8Unchecked(s, len);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxString
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_String)
{
	// Constructor assignment
	Gura_AssignFunction(__String);
	Gura_AssignFunction(__String_1);
	Gura_AssignFunction(__String_2);
	Gura_AssignFunction(__String_3);
	Gura_AssignFunction(__String_4);
	Gura_AssignFunction(__String_5);
	Gura_AssignFunction(__String_6);
	Gura_AssignFunction(__String_7);
	Gura_AssignFunction(__String_8);
	Gura_AssignFunction(__String_9);
	Gura_AssignFunction(__String_10);
	Gura_AssignFunction(__String_11);
	Gura_AssignFunction(__String_12);
	Gura_AssignFunction(__String_13);
	Gura_AssignFunction(__String_14);
	Gura_AssignFunction(__String_15);
	// Method assignment
	Gura_AssignMethod(wx_String, __Len);
	Gura_AssignMethod(wx_String, __Length);
	Gura_AssignMethod(wx_String, __IsEmpty);
	Gura_AssignMethod(wx_String, __IsNull);
	Gura_AssignMethod(wx_String, __GetChar);
	Gura_AssignMethod(wx_String, __GetData);
	Gura_AssignMethod(wx_String, __GetWritableChar);
	Gura_AssignMethod(wx_String, __GetWriteBuf);
	Gura_AssignMethod(wx_String, __UngetWriteBuf);
	Gura_AssignMethod(wx_String, __UngetWriteBuf_1);
	Gura_AssignMethod(wx_String, __SetChar);
	Gura_AssignMethod(wx_String, __Last);
	Gura_AssignMethod(wx_String, __Last_1);
	Gura_AssignMethod(wx_String, __c_str);
	Gura_AssignMethod(wx_String, __char_str);
	Gura_AssignMethod(wx_String, __tchar_str);
	Gura_AssignMethod(wx_String, __fn_str);
	Gura_AssignMethod(wx_String, __fn_str_1);
	Gura_AssignMethod(wx_String, __fn_str_2);
	Gura_AssignMethod(wx_String, __mb_str);
	Gura_AssignMethod(wx_String, __utf8_str);
	Gura_AssignMethod(wx_String, __wc_str);
	Gura_AssignMethod(wx_String, __wc_str_1);
	Gura_AssignMethod(wx_String, __wchar_str);
	Gura_AssignMethod(wx_String, __wx_str);
	Gura_AssignMethod(wx_String, __To8BitData);
	Gura_AssignMethod(wx_String, __ToAscii);
	Gura_AssignMethod(wx_String, __ToAscii_1);
	Gura_AssignMethod(wx_String, __ToStdString);
	Gura_AssignMethod(wx_String, __ToStdWstring);
	Gura_AssignMethod(wx_String, __ToUTF8);
	Gura_AssignMethod(wx_String, __Append);
	Gura_AssignMethod(wx_String, __Append_1);
	Gura_AssignMethod(wx_String, __Append_2);
	Gura_AssignMethod(wx_String, __Append_3);
	Gura_AssignMethod(wx_String, __Append_4);
	Gura_AssignMethod(wx_String, __Append_5);
	Gura_AssignMethod(wx_String, __Prepend);
	Gura_AssignMethod(wx_String, __Cmp);
	Gura_AssignMethod(wx_String, __CmpNoCase);
	Gura_AssignMethod(wx_String, __IsSameAs);
	Gura_AssignMethod(wx_String, __IsSameAs_1);
	Gura_AssignMethod(wx_String, __Matches);
	Gura_AssignMethod(wx_String, __StartsWith);
	Gura_AssignMethod(wx_String, __EndsWith);
	Gura_AssignMethod(wx_String, __Mid);
	Gura_AssignMethod(wx_String, __SubString);
	Gura_AssignMethod(wx_String, __operator);
	Gura_AssignMethod(wx_String, __Left);
	Gura_AssignMethod(wx_String, __Right);
	Gura_AssignMethod(wx_String, __AfterFirst);
	Gura_AssignMethod(wx_String, __AfterLast);
	Gura_AssignMethod(wx_String, __BeforeFirst);
	Gura_AssignMethod(wx_String, __BeforeLast);
	Gura_AssignMethod(wx_String, __Capitalize);
	Gura_AssignMethod(wx_String, __Lower);
	Gura_AssignMethod(wx_String, __LowerCase);
	Gura_AssignMethod(wx_String, __MakeCapitalized);
	Gura_AssignMethod(wx_String, __MakeLower);
	Gura_AssignMethod(wx_String, __MakeUpper);
	Gura_AssignMethod(wx_String, __Upper);
	Gura_AssignMethod(wx_String, __UpperCase);
	Gura_AssignMethod(wx_String, __Find);
	Gura_AssignMethod(wx_String, __Find_1);
	Gura_AssignMethod(wx_String, __First);
	Gura_AssignMethod(wx_String, __First_1);
	Gura_AssignMethod(wx_String, __Replace);
	Gura_AssignMethod(wx_String, __ToDouble);
	Gura_AssignMethod(wx_String, __ToCDouble);
	Gura_AssignMethod(wx_String, __ToLong);
	Gura_AssignMethod(wx_String, __ToCLong);
	Gura_AssignMethod(wx_String, __ToLongLong);
	Gura_AssignMethod(wx_String, __ToULong);
	Gura_AssignMethod(wx_String, __ToCULong);
	Gura_AssignMethod(wx_String, __ToULongLong);
	Gura_AssignMethod(wx_String, __PrintfV);
	Gura_AssignMethod(wx_String, __Alloc);
	Gura_AssignMethod(wx_String, __Shrink);
	Gura_AssignMethod(wx_String, __Clone);
	Gura_AssignMethod(wx_String, __Clear);
	Gura_AssignMethod(wx_String, __Contains);
	Gura_AssignMethod(wx_String, __Empty);
	Gura_AssignMethod(wx_String, __Freq);
	Gura_AssignMethod(wx_String, __IsAscii);
	Gura_AssignMethod(wx_String, __IsNumber);
	Gura_AssignMethod(wx_String, __IsWord);
	Gura_AssignMethod(wx_String, __Pad);
	Gura_AssignMethod(wx_String, __Remove);
	Gura_AssignMethod(wx_String, __Remove_1);
	Gura_AssignMethod(wx_String, __RemoveLast);
	Gura_AssignMethod(wx_String, __Strip);
	Gura_AssignMethod(wx_String, __Trim);
	Gura_AssignMethod(wx_String, __Truncate);
	Gura_AssignMethod(wx_String, __begin);
	Gura_AssignMethod(wx_String, __begin_1);
	Gura_AssignMethod(wx_String, __end);
	Gura_AssignMethod(wx_String, __end_1);
	Gura_AssignMethod(wx_String, __rbegin);
	Gura_AssignMethod(wx_String, __rbegin_1);
	Gura_AssignMethod(wx_String, __rend);
	Gura_AssignMethod(wx_String, __rend_1);
	Gura_AssignMethod(wx_String, __append);
	Gura_AssignMethod(wx_String, __append_1);
	Gura_AssignMethod(wx_String, __append_2);
	Gura_AssignMethod(wx_String, __append_3);
	Gura_AssignMethod(wx_String, __append_4);
	Gura_AssignMethod(wx_String, __append_5);
	Gura_AssignMethod(wx_String, __assign);
	Gura_AssignMethod(wx_String, __assign_1);
	Gura_AssignMethod(wx_String, __assign_2);
	Gura_AssignMethod(wx_String, __assign_3);
	Gura_AssignMethod(wx_String, __assign_4);
	Gura_AssignMethod(wx_String, __assign_5);
	Gura_AssignMethod(wx_String, __at);
	Gura_AssignMethod(wx_String, __at_1);
	Gura_AssignMethod(wx_String, __clear);
	Gura_AssignMethod(wx_String, __capacity);
	Gura_AssignMethod(wx_String, __compare);
	Gura_AssignMethod(wx_String, __compare_1);
	Gura_AssignMethod(wx_String, __compare_2);
	Gura_AssignMethod(wx_String, __compare_3);
	Gura_AssignMethod(wx_String, __compare_4);
	Gura_AssignMethod(wx_String, __data);
	Gura_AssignMethod(wx_String, __empty);
	Gura_AssignMethod(wx_String, __erase);
	Gura_AssignMethod(wx_String, __erase_1);
	Gura_AssignMethod(wx_String, __erase_2);
	Gura_AssignMethod(wx_String, __find);
	Gura_AssignMethod(wx_String, __find_1);
	Gura_AssignMethod(wx_String, __find_2);
	Gura_AssignMethod(wx_String, __find_3);
	Gura_AssignMethod(wx_String, __find_first_of);
	Gura_AssignMethod(wx_String, __find_first_of_1);
	Gura_AssignMethod(wx_String, __find_first_of_2);
	Gura_AssignMethod(wx_String, __find_first_of_3);
	Gura_AssignMethod(wx_String, __find_first_of_4);
	Gura_AssignMethod(wx_String, __find_last_of);
	Gura_AssignMethod(wx_String, __find_last_of_1);
	Gura_AssignMethod(wx_String, __find_last_of_2);
	Gura_AssignMethod(wx_String, __find_last_of_3);
	Gura_AssignMethod(wx_String, __find_last_of_4);
	Gura_AssignMethod(wx_String, __find_last_of_5);
	Gura_AssignMethod(wx_String, __find_first_not_of);
	Gura_AssignMethod(wx_String, __find_first_not_of_1);
	Gura_AssignMethod(wx_String, __find_first_not_of_2);
	Gura_AssignMethod(wx_String, __find_first_not_of_3);
	Gura_AssignMethod(wx_String, __find_first_not_of_4);
	Gura_AssignMethod(wx_String, __find_first_not_of_5);
	Gura_AssignMethod(wx_String, __find_last_not_of);
	Gura_AssignMethod(wx_String, __find_last_not_of_1);
	Gura_AssignMethod(wx_String, __find_last_not_of_2);
	Gura_AssignMethod(wx_String, __find_last_not_of_3);
	Gura_AssignMethod(wx_String, __find_last_not_of_4);
	Gura_AssignMethod(wx_String, __insert);
	Gura_AssignMethod(wx_String, __insert_1);
	Gura_AssignMethod(wx_String, __insert_2);
	Gura_AssignMethod(wx_String, __insert_3);
	Gura_AssignMethod(wx_String, __insert_4);
	Gura_AssignMethod(wx_String, __insert_5);
	Gura_AssignMethod(wx_String, __insert_6);
	Gura_AssignMethod(wx_String, __insert_7);
	Gura_AssignMethod(wx_String, __length);
	Gura_AssignMethod(wx_String, __max_size);
	Gura_AssignMethod(wx_String, __reserve);
	Gura_AssignMethod(wx_String, __resize);
	Gura_AssignMethod(wx_String, __replace);
	Gura_AssignMethod(wx_String, __replace_1);
	Gura_AssignMethod(wx_String, __replace_2);
	Gura_AssignMethod(wx_String, __replace_3);
	Gura_AssignMethod(wx_String, __replace_4);
	Gura_AssignMethod(wx_String, __replace_5);
	Gura_AssignMethod(wx_String, __replace_6);
	Gura_AssignMethod(wx_String, __replace_7);
	Gura_AssignMethod(wx_String, __replace_8);
	Gura_AssignMethod(wx_String, __replace_9);
	Gura_AssignMethod(wx_String, __replace_10);
	Gura_AssignMethod(wx_String, __replace_11);
	Gura_AssignMethod(wx_String, __replace_12);
	Gura_AssignMethod(wx_String, __rfind);
	Gura_AssignMethod(wx_String, __rfind_1);
	Gura_AssignMethod(wx_String, __rfind_2);
	Gura_AssignMethod(wx_String, __rfind_3);
	Gura_AssignMethod(wx_String, __size);
	Gura_AssignMethod(wx_String, __substr);
	Gura_AssignMethod(wx_String, __swap);
	Gura_AssignMethod(wx_String, __FormatV);
	Gura_AssignMethod(wx_String, __From8BitData);
	Gura_AssignMethod(wx_String, __From8BitData_1);
	Gura_AssignMethod(wx_String, __FromAscii);
	Gura_AssignMethod(wx_String, __FromAscii_1);
	Gura_AssignMethod(wx_String, __FromAscii_2);
	Gura_AssignMethod(wx_String, __FromAscii_3);
	Gura_AssignMethod(wx_String, __FromAscii_4);
	Gura_AssignMethod(wx_String, __FromCDouble);
	Gura_AssignMethod(wx_String, __FromDouble);
	Gura_AssignMethod(wx_String, __FromUTF8);
	Gura_AssignMethod(wx_String, __FromUTF8_1);
	Gura_AssignMethod(wx_String, __FromUTF8Unchecked);
	Gura_AssignMethod(wx_String, __FromUTF8Unchecked_1);
}

Gura_ImplementDescendantCreator(wx_String)
{
	return new Object_wx_String((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
