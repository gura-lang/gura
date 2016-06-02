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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_String, wxString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, wxString)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, wxString_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stringSrc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, wxString_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stringSrc = arg.GetNumber(0)
	//pThis->GetEntity()->wxString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, wxString_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nRepeat", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, wxString_2)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ch = arg.GetNumber(0)
	//int nRepeat = arg.GetNumber(1)
	//pThis->GetEntity()->wxString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, wxString_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nRepeat", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, wxString_3)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ch = arg.GetNumber(0)
	//int nRepeat = arg.GetNumber(1)
	//pThis->GetEntity()->wxString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, wxString_4)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nRepeat", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, wxString_4)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ch = arg.GetNumber(0)
	//int nRepeat = arg.GetNumber(1)
	//pThis->GetEntity()->wxString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, wxString_5)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nRepeat", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, wxString_5)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ch = arg.GetNumber(0)
	//int nRepeat = arg.GetNumber(1)
	//pThis->GetEntity()->wxString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, wxString_6)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "psz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, wxString_6)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int psz = arg.GetNumber(0)
	//pThis->GetEntity()->wxString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, wxString_7)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "psz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, wxString_7)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int psz = arg.GetNumber(0)
	//int conv = arg.GetNumber(1)
	//pThis->GetEntity()->wxString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, wxString_8)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "psz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nLength", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, wxString_8)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int psz = arg.GetNumber(0)
	//int nLength = arg.GetNumber(1)
	//pThis->GetEntity()->wxString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, wxString_9)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "psz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nLength", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, wxString_9)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int psz = arg.GetNumber(0)
	//int conv = arg.GetNumber(1)
	//int nLength = arg.GetNumber(2)
	//pThis->GetEntity()->wxString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, wxString_10)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pwz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, wxString_10)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pwz = arg.GetNumber(0)
	//pThis->GetEntity()->wxString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, wxString_11)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pwz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nLength", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, wxString_11)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pwz = arg.GetNumber(0)
	//int nLength = arg.GetNumber(1)
	//pThis->GetEntity()->wxString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, wxString_12)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, wxString_12)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buf = arg.GetNumber(0)
	//pThis->GetEntity()->wxString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, wxString_13)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, wxString_13)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buf = arg.GetNumber(0)
	//pThis->GetEntity()->wxString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, wxString_14)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, wxString_14)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//pThis->GetEntity()->wxString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, wxString_15)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, wxString_15)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//pThis->GetEntity()->wxString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, Len)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, Len)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Len();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, Length)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, Length)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Length();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, IsEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, IsEmpty)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsEmpty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, IsNull)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, IsNull)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsNull();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, GetChar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, GetChar)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->GetChar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, GetData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, GetData)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, GetWritableChar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, GetWritableChar)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->GetWritableChar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, GetWriteBuf)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, GetWriteBuf)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int len = arg.GetNumber(0)
	//pThis->GetEntity()->GetWriteBuf();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, UngetWriteBuf)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, UngetWriteBuf)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->UngetWriteBuf();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, UngetWriteBuf_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, UngetWriteBuf_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int len = arg.GetNumber(0)
	//pThis->GetEntity()->UngetWriteBuf();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, SetChar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, SetChar)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//int ch = arg.GetNumber(1)
	//pThis->GetEntity()->SetChar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, Last)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, Last)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Last();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, Last_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, Last_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Last();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, c_str)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, c_str)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->c_str();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, char_str)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, char_str)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int conv = arg.GetNumber(0)
	//pThis->GetEntity()->char_str();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, tchar_str)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, tchar_str)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int len = arg.GetNumber(0)
	//pThis->GetEntity()->tchar_str();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, fn_str)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, fn_str)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->fn_str();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, fn_str_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, fn_str_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->fn_str();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, fn_str_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, fn_str_2)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->fn_str();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, mb_str)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, mb_str)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int conv = arg.GetNumber(0)
	//pThis->GetEntity()->mb_str();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, utf8_str)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, utf8_str)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->utf8_str();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, wc_str)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, wc_str)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wc_str();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, wc_str_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, wc_str_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wc_str();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, wchar_str)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, wchar_str)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wchar_str();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, wx_str)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, wx_str)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wx_str();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, To8BitData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, To8BitData)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->To8BitData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, ToAscii)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "replaceWith", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, ToAscii)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int replaceWith = arg.GetNumber(0)
	//pThis->GetEntity()->ToAscii();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, ToAscii_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "replaceWith", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, ToAscii_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int replaceWith = arg.GetNumber(0)
	//pThis->GetEntity()->ToAscii();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, ToStdString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, ToStdString)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ToStdString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, ToStdWstring)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, ToStdWstring)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ToStdWstring();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, ToUTF8)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, ToUTF8)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ToUTF8();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, Append)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "psz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, Append)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int psz = arg.GetNumber(0)
	//pThis->GetEntity()->Append();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, Append_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pwz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, Append_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pwz = arg.GetNumber(0)
	//pThis->GetEntity()->Append();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, Append_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "psz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nLen", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, Append_2)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int psz = arg.GetNumber(0)
	//int nLen = arg.GetNumber(1)
	//pThis->GetEntity()->Append();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, Append_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pwz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nLen", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, Append_3)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pwz = arg.GetNumber(0)
	//int nLen = arg.GetNumber(1)
	//pThis->GetEntity()->Append();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, Append_4)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, Append_4)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int s = arg.GetNumber(0)
	//pThis->GetEntity()->Append();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, Append_5)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "count", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, Append_5)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ch = arg.GetNumber(0)
	//int count = arg.GetNumber(1)
	//pThis->GetEntity()->Append();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, Prepend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, Prepend)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//pThis->GetEntity()->Prepend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, Cmp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, Cmp)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int s = arg.GetNumber(0)
	//pThis->GetEntity()->Cmp();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, CmpNoCase)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, CmpNoCase)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int s = arg.GetNumber(0)
	//pThis->GetEntity()->CmpNoCase();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, IsSameAs)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "caseSensitive", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, IsSameAs)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int s = arg.GetNumber(0)
	//int caseSensitive = arg.GetNumber(1)
	//pThis->GetEntity()->IsSameAs();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, IsSameAs_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "caseSensitive", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, IsSameAs_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ch = arg.GetNumber(0)
	//int caseSensitive = arg.GetNumber(1)
	//pThis->GetEntity()->IsSameAs();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, Matches)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mask", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, Matches)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int mask = arg.GetNumber(0)
	//pThis->GetEntity()->Matches();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, StartsWith)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "prefix", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rest", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, StartsWith)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int prefix = arg.GetNumber(0)
	//int rest = arg.GetNumber(1)
	//pThis->GetEntity()->StartsWith();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, EndsWith)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "suffix", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rest", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, EndsWith)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int suffix = arg.GetNumber(0)
	//int rest = arg.GetNumber(1)
	//pThis->GetEntity()->EndsWith();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, Mid)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "first", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nCount", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, Mid)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int first = arg.GetNumber(0)
	//int nCount = arg.GetNumber(1)
	//pThis->GetEntity()->Mid();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, SubString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "from", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "to", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, SubString)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int from = arg.GetNumber(0)
	//int to = arg.GetNumber(1)
	//pThis->GetEntity()->SubString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, operator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, operator)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int start = arg.GetNumber(0)
	//int len = arg.GetNumber(1)
	//pThis->GetEntity()->operator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, Left)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "count", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, Left)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int count = arg.GetNumber(0)
	//pThis->GetEntity()->Left();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, Right)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "count", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, Right)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int count = arg.GetNumber(0)
	//pThis->GetEntity()->Right();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, AfterFirst)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, AfterFirst)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ch = arg.GetNumber(0)
	//pThis->GetEntity()->AfterFirst();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, AfterLast)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, AfterLast)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ch = arg.GetNumber(0)
	//pThis->GetEntity()->AfterLast();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, BeforeFirst)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rest", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, BeforeFirst)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ch = arg.GetNumber(0)
	//int rest = arg.GetNumber(1)
	//pThis->GetEntity()->BeforeFirst();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, BeforeLast)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rest", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, BeforeLast)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ch = arg.GetNumber(0)
	//int rest = arg.GetNumber(1)
	//pThis->GetEntity()->BeforeLast();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, Capitalize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, Capitalize)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Capitalize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, Lower)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, Lower)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Lower();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, LowerCase)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, LowerCase)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->LowerCase();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, MakeCapitalized)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, MakeCapitalized)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->MakeCapitalized();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, MakeLower)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, MakeLower)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->MakeLower();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, MakeUpper)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, MakeUpper)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->MakeUpper();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, Upper)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, Upper)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Upper();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, UpperCase)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, UpperCase)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->UpperCase();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, Find)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fromEnd", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, Find)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ch = arg.GetNumber(0)
	//int fromEnd = arg.GetNumber(1)
	//pThis->GetEntity()->Find();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, Find_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sub", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, Find_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sub = arg.GetNumber(0)
	//pThis->GetEntity()->Find();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, First)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, First)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ch = arg.GetNumber(0)
	//pThis->GetEntity()->First();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, First_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, First_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//pThis->GetEntity()->First();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, Replace)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "strOld", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "strNew", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "replaceAll", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, Replace)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int strOld = arg.GetNumber(0)
	//int strNew = arg.GetNumber(1)
	//int replaceAll = arg.GetNumber(2)
	//pThis->GetEntity()->Replace();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, ToDouble)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, ToDouble)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int val = arg.GetNumber(0)
	//pThis->GetEntity()->ToDouble();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, ToCDouble)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, ToCDouble)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int val = arg.GetNumber(0)
	//pThis->GetEntity()->ToCDouble();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, ToLong)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "base", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, ToLong)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int val = arg.GetNumber(0)
	//int base = arg.GetNumber(1)
	//pThis->GetEntity()->ToLong();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, ToCLong)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "base", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, ToCLong)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int val = arg.GetNumber(0)
	//int base = arg.GetNumber(1)
	//pThis->GetEntity()->ToCLong();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, ToLongLong)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "base", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, ToLongLong)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int val = arg.GetNumber(0)
	//int base = arg.GetNumber(1)
	//pThis->GetEntity()->ToLongLong();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, ToULong)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "base", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, ToULong)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int val = arg.GetNumber(0)
	//int base = arg.GetNumber(1)
	//pThis->GetEntity()->ToULong();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, ToCULong)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "base", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, ToCULong)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int val = arg.GetNumber(0)
	//int base = arg.GetNumber(1)
	//pThis->GetEntity()->ToCULong();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, ToULongLong)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "base", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, ToULongLong)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int val = arg.GetNumber(0)
	//int base = arg.GetNumber(1)
	//pThis->GetEntity()->ToULongLong();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, Printf)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pszFormat", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, Printf)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pszFormat = arg.GetNumber(0)
	//pThis->GetEntity()->Printf();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, PrintfV)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pszFormat", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "argPtr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, PrintfV)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pszFormat = arg.GetNumber(0)
	//int argPtr = arg.GetNumber(1)
	//pThis->GetEntity()->PrintfV();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, Alloc)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nLen", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, Alloc)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int nLen = arg.GetNumber(0)
	//pThis->GetEntity()->Alloc();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, Shrink)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, Shrink)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Shrink();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, Clone)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, Clone)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clone();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, Clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, Clear)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, Contains)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, Contains)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//pThis->GetEntity()->Contains();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, Empty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, Empty)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Empty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, Freq)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, Freq)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ch = arg.GetNumber(0)
	//pThis->GetEntity()->Freq();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, IsAscii)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, IsAscii)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsAscii();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, IsNumber)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, IsNumber)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsNumber();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, IsWord)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, IsWord)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsWord();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, Pad)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "count", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "chPad", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fromRight", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, Pad)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int count = arg.GetNumber(0)
	//int chPad = arg.GetNumber(1)
	//int fromRight = arg.GetNumber(2)
	//pThis->GetEntity()->Pad();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, Remove)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, Remove)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->Remove();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, Remove_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, Remove_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int len = arg.GetNumber(1)
	//pThis->GetEntity()->Remove();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, RemoveLast)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, RemoveLast)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveLast();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, Strip)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, Strip)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int s = arg.GetNumber(0)
	//pThis->GetEntity()->Strip();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, Trim)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fromRight", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, Trim)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int fromRight = arg.GetNumber(0)
	//pThis->GetEntity()->Trim();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, Truncate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, Truncate)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int len = arg.GetNumber(0)
	//pThis->GetEntity()->Truncate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, begin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, begin)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->begin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, begin_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, begin_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->begin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, end)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, end)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->end();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, end_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, end_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->end();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, rbegin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, rbegin)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->rbegin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, rbegin_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, rbegin_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->rbegin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, rend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, rend)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->rend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, rend_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, rend_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->rend();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, append)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, append)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//int n = arg.GetNumber(2)
	//pThis->GetEntity()->append();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, append_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, append_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//pThis->GetEntity()->append();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, append_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, append_2)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sz = arg.GetNumber(0)
	//int n = arg.GetNumber(1)
	//pThis->GetEntity()->append();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, append_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, append_3)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sz = arg.GetNumber(0)
	//int n = arg.GetNumber(1)
	//pThis->GetEntity()->append();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, append_4)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, append_4)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//int ch = arg.GetNumber(1)
	//pThis->GetEntity()->append();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, append_5)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "first", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "last", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, append_5)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int first = arg.GetNumber(0)
	//int last = arg.GetNumber(1)
	//pThis->GetEntity()->append();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, assign)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, assign)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//int n = arg.GetNumber(2)
	//pThis->GetEntity()->assign();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, assign_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, assign_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//pThis->GetEntity()->assign();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, assign_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, assign_2)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sz = arg.GetNumber(0)
	//int n = arg.GetNumber(1)
	//pThis->GetEntity()->assign();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, assign_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, assign_3)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sz = arg.GetNumber(0)
	//int n = arg.GetNumber(1)
	//pThis->GetEntity()->assign();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, assign_4)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, assign_4)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//int ch = arg.GetNumber(1)
	//pThis->GetEntity()->assign();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, assign_5)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "first", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "last", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, assign_5)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int first = arg.GetNumber(0)
	//int last = arg.GetNumber(1)
	//pThis->GetEntity()->assign();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, at)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, at)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->at();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, at_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, at_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->at();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, clear)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->clear();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, capacity)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, capacity)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->capacity();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, compare)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, compare)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//pThis->GetEntity()->compare();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, compare_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nLen", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, compare_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int nStart = arg.GetNumber(0)
	//int nLen = arg.GetNumber(1)
	//int str = arg.GetNumber(2)
	//pThis->GetEntity()->compare();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, compare_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nLen", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart2", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nLen2", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, compare_2)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int nStart = arg.GetNumber(0)
	//int nLen = arg.GetNumber(1)
	//int str = arg.GetNumber(2)
	//int nStart2 = arg.GetNumber(3)
	//int nLen2 = arg.GetNumber(4)
	//pThis->GetEntity()->compare();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, compare_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nLen", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nCount", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, compare_3)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int nStart = arg.GetNumber(0)
	//int nLen = arg.GetNumber(1)
	//int sz = arg.GetNumber(2)
	//int nCount = arg.GetNumber(3)
	//pThis->GetEntity()->compare();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, compare_4)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nLen", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nCount", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, compare_4)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int nStart = arg.GetNumber(0)
	//int nLen = arg.GetNumber(1)
	//int sz = arg.GetNumber(2)
	//int nCount = arg.GetNumber(3)
	//pThis->GetEntity()->compare();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, data)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, data)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->data();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, empty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, empty)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->empty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, erase)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, erase)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//int n = arg.GetNumber(1)
	//pThis->GetEntity()->erase();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, erase_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "first", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "last", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, erase_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int first = arg.GetNumber(0)
	//int last = arg.GetNumber(1)
	//pThis->GetEntity()->erase();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, erase_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "first", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, erase_2)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int first = arg.GetNumber(0)
	//pThis->GetEntity()->erase();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, find)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, find)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//int nStart = arg.GetNumber(1)
	//pThis->GetEntity()->find();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, find_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, find_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sz = arg.GetNumber(0)
	//int nStart = arg.GetNumber(1)
	//int n = arg.GetNumber(2)
	//pThis->GetEntity()->find();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, find_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, find_2)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sz = arg.GetNumber(0)
	//int nStart = arg.GetNumber(1)
	//int n = arg.GetNumber(2)
	//pThis->GetEntity()->find();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, find_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, find_3)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ch = arg.GetNumber(0)
	//int nStart = arg.GetNumber(1)
	//pThis->GetEntity()->find();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, find_first_of)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, find_first_of)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sz = arg.GetNumber(0)
	//int nStart = arg.GetNumber(1)
	//pThis->GetEntity()->find_first_of();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, find_first_of_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, find_first_of_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sz = arg.GetNumber(0)
	//int nStart = arg.GetNumber(1)
	//pThis->GetEntity()->find_first_of();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, find_first_of_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, find_first_of_2)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sz = arg.GetNumber(0)
	//int nStart = arg.GetNumber(1)
	//int n = arg.GetNumber(2)
	//pThis->GetEntity()->find_first_of();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, find_first_of_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, find_first_of_3)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sz = arg.GetNumber(0)
	//int nStart = arg.GetNumber(1)
	//int n = arg.GetNumber(2)
	//pThis->GetEntity()->find_first_of();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, find_first_of_4)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, find_first_of_4)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int c = arg.GetNumber(0)
	//int nStart = arg.GetNumber(1)
	//pThis->GetEntity()->find_first_of();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, find_last_of)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, find_last_of)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//int nStart = arg.GetNumber(1)
	//pThis->GetEntity()->find_last_of();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, find_last_of_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, find_last_of_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sz = arg.GetNumber(0)
	//int nStart = arg.GetNumber(1)
	//pThis->GetEntity()->find_last_of();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, find_last_of_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, find_last_of_2)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sz = arg.GetNumber(0)
	//int nStart = arg.GetNumber(1)
	//pThis->GetEntity()->find_last_of();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, find_last_of_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, find_last_of_3)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sz = arg.GetNumber(0)
	//int nStart = arg.GetNumber(1)
	//int n = arg.GetNumber(2)
	//pThis->GetEntity()->find_last_of();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, find_last_of_4)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, find_last_of_4)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sz = arg.GetNumber(0)
	//int nStart = arg.GetNumber(1)
	//int n = arg.GetNumber(2)
	//pThis->GetEntity()->find_last_of();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, find_last_of_5)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, find_last_of_5)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int c = arg.GetNumber(0)
	//int nStart = arg.GetNumber(1)
	//pThis->GetEntity()->find_last_of();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, find_first_not_of)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, find_first_not_of)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//int nStart = arg.GetNumber(1)
	//pThis->GetEntity()->find_first_not_of();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, find_first_not_of_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, find_first_not_of_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sz = arg.GetNumber(0)
	//int nStart = arg.GetNumber(1)
	//pThis->GetEntity()->find_first_not_of();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, find_first_not_of_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, find_first_not_of_2)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sz = arg.GetNumber(0)
	//int nStart = arg.GetNumber(1)
	//pThis->GetEntity()->find_first_not_of();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, find_first_not_of_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, find_first_not_of_3)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sz = arg.GetNumber(0)
	//int nStart = arg.GetNumber(1)
	//int n = arg.GetNumber(2)
	//pThis->GetEntity()->find_first_not_of();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, find_first_not_of_4)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, find_first_not_of_4)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sz = arg.GetNumber(0)
	//int nStart = arg.GetNumber(1)
	//int n = arg.GetNumber(2)
	//pThis->GetEntity()->find_first_not_of();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, find_first_not_of_5)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, find_first_not_of_5)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ch = arg.GetNumber(0)
	//int nStart = arg.GetNumber(1)
	//pThis->GetEntity()->find_first_not_of();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, find_last_not_of)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, find_last_not_of)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//int nStart = arg.GetNumber(1)
	//pThis->GetEntity()->find_last_not_of();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, find_last_not_of_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, find_last_not_of_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sz = arg.GetNumber(0)
	//int nStart = arg.GetNumber(1)
	//pThis->GetEntity()->find_last_not_of();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, find_last_not_of_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, find_last_not_of_2)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sz = arg.GetNumber(0)
	//int nStart = arg.GetNumber(1)
	//pThis->GetEntity()->find_last_not_of();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, find_last_not_of_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, find_last_not_of_3)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sz = arg.GetNumber(0)
	//int nStart = arg.GetNumber(1)
	//int n = arg.GetNumber(2)
	//pThis->GetEntity()->find_last_not_of();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, find_last_not_of_4)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, find_last_not_of_4)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sz = arg.GetNumber(0)
	//int nStart = arg.GetNumber(1)
	//int n = arg.GetNumber(2)
	//pThis->GetEntity()->find_last_not_of();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, insert)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nPos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, insert)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int nPos = arg.GetNumber(0)
	//int str = arg.GetNumber(1)
	//pThis->GetEntity()->insert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, insert_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nPos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, insert_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int nPos = arg.GetNumber(0)
	//int str = arg.GetNumber(1)
	//int nStart = arg.GetNumber(2)
	//int n = arg.GetNumber(3)
	//pThis->GetEntity()->insert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, insert_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nPos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, insert_2)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int nPos = arg.GetNumber(0)
	//int sz = arg.GetNumber(1)
	//int n = arg.GetNumber(2)
	//pThis->GetEntity()->insert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, insert_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nPos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, insert_3)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int nPos = arg.GetNumber(0)
	//int sz = arg.GetNumber(1)
	//int n = arg.GetNumber(2)
	//pThis->GetEntity()->insert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, insert_4)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nPos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, insert_4)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int nPos = arg.GetNumber(0)
	//int n = arg.GetNumber(1)
	//int ch = arg.GetNumber(2)
	//pThis->GetEntity()->insert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, insert_5)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "it", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, insert_5)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int it = arg.GetNumber(0)
	//int ch = arg.GetNumber(1)
	//pThis->GetEntity()->insert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, insert_6)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "it", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "first", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "last", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, insert_6)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int it = arg.GetNumber(0)
	//int first = arg.GetNumber(1)
	//int last = arg.GetNumber(2)
	//pThis->GetEntity()->insert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, insert_7)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "it", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, insert_7)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int it = arg.GetNumber(0)
	//int n = arg.GetNumber(1)
	//int ch = arg.GetNumber(2)
	//pThis->GetEntity()->insert();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, length)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, length)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->length();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, max_size)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, max_size)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->max_size();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, reserve)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, reserve)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sz = arg.GetNumber(0)
	//pThis->GetEntity()->reserve();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, resize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nSize", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, resize)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int nSize = arg.GetNumber(0)
	//int ch = arg.GetNumber(1)
	//pThis->GetEntity()->resize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, replace)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nLen", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, replace)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int nStart = arg.GetNumber(0)
	//int nLen = arg.GetNumber(1)
	//int str = arg.GetNumber(2)
	//pThis->GetEntity()->replace();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, replace_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nLen", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nCount", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, replace_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int nStart = arg.GetNumber(0)
	//int nLen = arg.GetNumber(1)
	//int nCount = arg.GetNumber(2)
	//int ch = arg.GetNumber(3)
	//pThis->GetEntity()->replace();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, replace_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nLen", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart2", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nLen2", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, replace_2)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int nStart = arg.GetNumber(0)
	//int nLen = arg.GetNumber(1)
	//int str = arg.GetNumber(2)
	//int nStart2 = arg.GetNumber(3)
	//int nLen2 = arg.GetNumber(4)
	//pThis->GetEntity()->replace();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, replace_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nLen", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nCount", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, replace_3)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int nStart = arg.GetNumber(0)
	//int nLen = arg.GetNumber(1)
	//int sz = arg.GetNumber(2)
	//int nCount = arg.GetNumber(3)
	//pThis->GetEntity()->replace();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, replace_4)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nLen", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nCount", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, replace_4)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int nStart = arg.GetNumber(0)
	//int nLen = arg.GetNumber(1)
	//int sz = arg.GetNumber(2)
	//int nCount = arg.GetNumber(3)
	//pThis->GetEntity()->replace();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, replace_5)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nLen", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nCount", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, replace_5)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int nStart = arg.GetNumber(0)
	//int nLen = arg.GetNumber(1)
	//int s = arg.GetNumber(2)
	//int nCount = arg.GetNumber(3)
	//pThis->GetEntity()->replace();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, replace_6)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "first", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "last", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, replace_6)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int first = arg.GetNumber(0)
	//int last = arg.GetNumber(1)
	//int s = arg.GetNumber(2)
	//pThis->GetEntity()->replace();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, replace_7)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "first", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "last", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, replace_7)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int first = arg.GetNumber(0)
	//int last = arg.GetNumber(1)
	//int s = arg.GetNumber(2)
	//int n = arg.GetNumber(3)
	//pThis->GetEntity()->replace();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, replace_8)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "first", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "last", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, replace_8)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int first = arg.GetNumber(0)
	//int last = arg.GetNumber(1)
	//int s = arg.GetNumber(2)
	//int n = arg.GetNumber(3)
	//pThis->GetEntity()->replace();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, replace_9)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "first", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "last", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, replace_9)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int first = arg.GetNumber(0)
	//int last = arg.GetNumber(1)
	//int n = arg.GetNumber(2)
	//int ch = arg.GetNumber(3)
	//pThis->GetEntity()->replace();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, replace_10)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "first", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "last", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "first1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "last1", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, replace_10)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int first = arg.GetNumber(0)
	//int last = arg.GetNumber(1)
	//int first1 = arg.GetNumber(2)
	//int last1 = arg.GetNumber(3)
	//pThis->GetEntity()->replace();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, replace_11)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "first", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "last", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "first1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "last1", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, replace_11)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int first = arg.GetNumber(0)
	//int last = arg.GetNumber(1)
	//int first1 = arg.GetNumber(2)
	//int last1 = arg.GetNumber(3)
	//pThis->GetEntity()->replace();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, replace_12)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "first", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "last", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "first1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "last1", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, replace_12)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int first = arg.GetNumber(0)
	//int last = arg.GetNumber(1)
	//int first1 = arg.GetNumber(2)
	//int last1 = arg.GetNumber(3)
	//pThis->GetEntity()->replace();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, rfind)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, rfind)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//int nStart = arg.GetNumber(1)
	//pThis->GetEntity()->rfind();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, rfind_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, rfind_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sz = arg.GetNumber(0)
	//int nStart = arg.GetNumber(1)
	//int n = arg.GetNumber(2)
	//pThis->GetEntity()->rfind();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, rfind_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sz", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, rfind_2)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sz = arg.GetNumber(0)
	//int nStart = arg.GetNumber(1)
	//int n = arg.GetNumber(2)
	//pThis->GetEntity()->rfind();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, rfind_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, rfind_3)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ch = arg.GetNumber(0)
	//int nStart = arg.GetNumber(1)
	//pThis->GetEntity()->rfind();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, size)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_String, size)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->size();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, substr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nStart", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nLen", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, substr)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int nStart = arg.GetNumber(0)
	//int nLen = arg.GetNumber(1)
	//pThis->GetEntity()->substr();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, swap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, swap)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//pThis->GetEntity()->swap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, Format)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, Format)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int format = arg.GetNumber(0)
	//pThis->GetEntity()->Format();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, FormatV)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "argptr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, FormatV)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int format = arg.GetNumber(0)
	//int argptr = arg.GetNumber(1)
	//pThis->GetEntity()->FormatV();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, From8BitData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, From8BitData)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buf = arg.GetNumber(0)
	//int len = arg.GetNumber(1)
	//pThis->GetEntity()->From8BitData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, From8BitData_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, From8BitData_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buf = arg.GetNumber(0)
	//pThis->GetEntity()->From8BitData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, FromAscii)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, FromAscii)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int s = arg.GetNumber(0)
	//pThis->GetEntity()->FromAscii();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, FromAscii_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, FromAscii_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int s = arg.GetNumber(0)
	//pThis->GetEntity()->FromAscii();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, FromAscii_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, FromAscii_2)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int s = arg.GetNumber(0)
	//int len = arg.GetNumber(1)
	//pThis->GetEntity()->FromAscii();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, FromAscii_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, FromAscii_3)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int s = arg.GetNumber(0)
	//int len = arg.GetNumber(1)
	//pThis->GetEntity()->FromAscii();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, FromAscii_4)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, FromAscii_4)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int c = arg.GetNumber(0)
	//pThis->GetEntity()->FromAscii();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, FromCDouble)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "precision", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, FromCDouble)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int val = arg.GetNumber(0)
	//int precision = arg.GetNumber(1)
	//pThis->GetEntity()->FromCDouble();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, FromDouble)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "val", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "precision", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, FromDouble)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int val = arg.GetNumber(0)
	//int precision = arg.GetNumber(1)
	//pThis->GetEntity()->FromDouble();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, FromUTF8)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, FromUTF8)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int s = arg.GetNumber(0)
	//pThis->GetEntity()->FromUTF8();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, FromUTF8_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, FromUTF8_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int s = arg.GetNumber(0)
	//int len = arg.GetNumber(1)
	//pThis->GetEntity()->FromUTF8();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, FromUTF8Unchecked)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, FromUTF8Unchecked)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int s = arg.GetNumber(0)
	//pThis->GetEntity()->FromUTF8Unchecked();
	return Value::Nil;
}

Gura_DeclareMethod(wx_String, FromUTF8Unchecked_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_String, FromUTF8Unchecked_1)
{
	Object_wx_String *pThis = Object_wx_String::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int s = arg.GetNumber(0)
	//int len = arg.GetNumber(1)
	//pThis->GetEntity()->FromUTF8Unchecked();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxString
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_String)
{
	Gura_AssignMethod(wx_String, wxString);
	Gura_AssignMethod(wx_String, wxString_1);
	Gura_AssignMethod(wx_String, wxString_2);
	Gura_AssignMethod(wx_String, wxString_3);
	Gura_AssignMethod(wx_String, wxString_4);
	Gura_AssignMethod(wx_String, wxString_5);
	Gura_AssignMethod(wx_String, wxString_6);
	Gura_AssignMethod(wx_String, wxString_7);
	Gura_AssignMethod(wx_String, wxString_8);
	Gura_AssignMethod(wx_String, wxString_9);
	Gura_AssignMethod(wx_String, wxString_10);
	Gura_AssignMethod(wx_String, wxString_11);
	Gura_AssignMethod(wx_String, wxString_12);
	Gura_AssignMethod(wx_String, wxString_13);
	Gura_AssignMethod(wx_String, wxString_14);
	Gura_AssignMethod(wx_String, wxString_15);
	Gura_AssignMethod(wx_String, Len);
	Gura_AssignMethod(wx_String, Length);
	Gura_AssignMethod(wx_String, IsEmpty);
	Gura_AssignMethod(wx_String, IsNull);
	Gura_AssignMethod(wx_String, GetChar);
	Gura_AssignMethod(wx_String, GetData);
	Gura_AssignMethod(wx_String, GetWritableChar);
	Gura_AssignMethod(wx_String, GetWriteBuf);
	Gura_AssignMethod(wx_String, UngetWriteBuf);
	Gura_AssignMethod(wx_String, UngetWriteBuf_1);
	Gura_AssignMethod(wx_String, SetChar);
	Gura_AssignMethod(wx_String, Last);
	Gura_AssignMethod(wx_String, Last_1);
	Gura_AssignMethod(wx_String, c_str);
	Gura_AssignMethod(wx_String, char_str);
	Gura_AssignMethod(wx_String, tchar_str);
	Gura_AssignMethod(wx_String, fn_str);
	Gura_AssignMethod(wx_String, fn_str_1);
	Gura_AssignMethod(wx_String, fn_str_2);
	Gura_AssignMethod(wx_String, mb_str);
	Gura_AssignMethod(wx_String, utf8_str);
	Gura_AssignMethod(wx_String, wc_str);
	Gura_AssignMethod(wx_String, wc_str_1);
	Gura_AssignMethod(wx_String, wchar_str);
	Gura_AssignMethod(wx_String, wx_str);
	Gura_AssignMethod(wx_String, To8BitData);
	Gura_AssignMethod(wx_String, ToAscii);
	Gura_AssignMethod(wx_String, ToAscii_1);
	Gura_AssignMethod(wx_String, ToStdString);
	Gura_AssignMethod(wx_String, ToStdWstring);
	Gura_AssignMethod(wx_String, ToUTF8);
	Gura_AssignMethod(wx_String, Append);
	Gura_AssignMethod(wx_String, Append_1);
	Gura_AssignMethod(wx_String, Append_2);
	Gura_AssignMethod(wx_String, Append_3);
	Gura_AssignMethod(wx_String, Append_4);
	Gura_AssignMethod(wx_String, Append_5);
	Gura_AssignMethod(wx_String, Prepend);
	Gura_AssignMethod(wx_String, Cmp);
	Gura_AssignMethod(wx_String, CmpNoCase);
	Gura_AssignMethod(wx_String, IsSameAs);
	Gura_AssignMethod(wx_String, IsSameAs_1);
	Gura_AssignMethod(wx_String, Matches);
	Gura_AssignMethod(wx_String, StartsWith);
	Gura_AssignMethod(wx_String, EndsWith);
	Gura_AssignMethod(wx_String, Mid);
	Gura_AssignMethod(wx_String, SubString);
	Gura_AssignMethod(wx_String, operator);
	Gura_AssignMethod(wx_String, Left);
	Gura_AssignMethod(wx_String, Right);
	Gura_AssignMethod(wx_String, AfterFirst);
	Gura_AssignMethod(wx_String, AfterLast);
	Gura_AssignMethod(wx_String, BeforeFirst);
	Gura_AssignMethod(wx_String, BeforeLast);
	Gura_AssignMethod(wx_String, Capitalize);
	Gura_AssignMethod(wx_String, Lower);
	Gura_AssignMethod(wx_String, LowerCase);
	Gura_AssignMethod(wx_String, MakeCapitalized);
	Gura_AssignMethod(wx_String, MakeLower);
	Gura_AssignMethod(wx_String, MakeUpper);
	Gura_AssignMethod(wx_String, Upper);
	Gura_AssignMethod(wx_String, UpperCase);
	Gura_AssignMethod(wx_String, Find);
	Gura_AssignMethod(wx_String, Find_1);
	Gura_AssignMethod(wx_String, First);
	Gura_AssignMethod(wx_String, First_1);
	Gura_AssignMethod(wx_String, Replace);
	Gura_AssignMethod(wx_String, ToDouble);
	Gura_AssignMethod(wx_String, ToCDouble);
	Gura_AssignMethod(wx_String, ToLong);
	Gura_AssignMethod(wx_String, ToCLong);
	Gura_AssignMethod(wx_String, ToLongLong);
	Gura_AssignMethod(wx_String, ToULong);
	Gura_AssignMethod(wx_String, ToCULong);
	Gura_AssignMethod(wx_String, ToULongLong);
	Gura_AssignMethod(wx_String, Printf);
	Gura_AssignMethod(wx_String, PrintfV);
	Gura_AssignMethod(wx_String, Alloc);
	Gura_AssignMethod(wx_String, Shrink);
	Gura_AssignMethod(wx_String, Clone);
	Gura_AssignMethod(wx_String, Clear);
	Gura_AssignMethod(wx_String, Contains);
	Gura_AssignMethod(wx_String, Empty);
	Gura_AssignMethod(wx_String, Freq);
	Gura_AssignMethod(wx_String, IsAscii);
	Gura_AssignMethod(wx_String, IsNumber);
	Gura_AssignMethod(wx_String, IsWord);
	Gura_AssignMethod(wx_String, Pad);
	Gura_AssignMethod(wx_String, Remove);
	Gura_AssignMethod(wx_String, Remove_1);
	Gura_AssignMethod(wx_String, RemoveLast);
	Gura_AssignMethod(wx_String, Strip);
	Gura_AssignMethod(wx_String, Trim);
	Gura_AssignMethod(wx_String, Truncate);
	Gura_AssignMethod(wx_String, begin);
	Gura_AssignMethod(wx_String, begin_1);
	Gura_AssignMethod(wx_String, end);
	Gura_AssignMethod(wx_String, end_1);
	Gura_AssignMethod(wx_String, rbegin);
	Gura_AssignMethod(wx_String, rbegin_1);
	Gura_AssignMethod(wx_String, rend);
	Gura_AssignMethod(wx_String, rend_1);
	Gura_AssignMethod(wx_String, append);
	Gura_AssignMethod(wx_String, append_1);
	Gura_AssignMethod(wx_String, append_2);
	Gura_AssignMethod(wx_String, append_3);
	Gura_AssignMethod(wx_String, append_4);
	Gura_AssignMethod(wx_String, append_5);
	Gura_AssignMethod(wx_String, assign);
	Gura_AssignMethod(wx_String, assign_1);
	Gura_AssignMethod(wx_String, assign_2);
	Gura_AssignMethod(wx_String, assign_3);
	Gura_AssignMethod(wx_String, assign_4);
	Gura_AssignMethod(wx_String, assign_5);
	Gura_AssignMethod(wx_String, at);
	Gura_AssignMethod(wx_String, at_1);
	Gura_AssignMethod(wx_String, clear);
	Gura_AssignMethod(wx_String, capacity);
	Gura_AssignMethod(wx_String, compare);
	Gura_AssignMethod(wx_String, compare_1);
	Gura_AssignMethod(wx_String, compare_2);
	Gura_AssignMethod(wx_String, compare_3);
	Gura_AssignMethod(wx_String, compare_4);
	Gura_AssignMethod(wx_String, data);
	Gura_AssignMethod(wx_String, empty);
	Gura_AssignMethod(wx_String, erase);
	Gura_AssignMethod(wx_String, erase_1);
	Gura_AssignMethod(wx_String, erase_2);
	Gura_AssignMethod(wx_String, find);
	Gura_AssignMethod(wx_String, find_1);
	Gura_AssignMethod(wx_String, find_2);
	Gura_AssignMethod(wx_String, find_3);
	Gura_AssignMethod(wx_String, find_first_of);
	Gura_AssignMethod(wx_String, find_first_of_1);
	Gura_AssignMethod(wx_String, find_first_of_2);
	Gura_AssignMethod(wx_String, find_first_of_3);
	Gura_AssignMethod(wx_String, find_first_of_4);
	Gura_AssignMethod(wx_String, find_last_of);
	Gura_AssignMethod(wx_String, find_last_of_1);
	Gura_AssignMethod(wx_String, find_last_of_2);
	Gura_AssignMethod(wx_String, find_last_of_3);
	Gura_AssignMethod(wx_String, find_last_of_4);
	Gura_AssignMethod(wx_String, find_last_of_5);
	Gura_AssignMethod(wx_String, find_first_not_of);
	Gura_AssignMethod(wx_String, find_first_not_of_1);
	Gura_AssignMethod(wx_String, find_first_not_of_2);
	Gura_AssignMethod(wx_String, find_first_not_of_3);
	Gura_AssignMethod(wx_String, find_first_not_of_4);
	Gura_AssignMethod(wx_String, find_first_not_of_5);
	Gura_AssignMethod(wx_String, find_last_not_of);
	Gura_AssignMethod(wx_String, find_last_not_of_1);
	Gura_AssignMethod(wx_String, find_last_not_of_2);
	Gura_AssignMethod(wx_String, find_last_not_of_3);
	Gura_AssignMethod(wx_String, find_last_not_of_4);
	Gura_AssignMethod(wx_String, insert);
	Gura_AssignMethod(wx_String, insert_1);
	Gura_AssignMethod(wx_String, insert_2);
	Gura_AssignMethod(wx_String, insert_3);
	Gura_AssignMethod(wx_String, insert_4);
	Gura_AssignMethod(wx_String, insert_5);
	Gura_AssignMethod(wx_String, insert_6);
	Gura_AssignMethod(wx_String, insert_7);
	Gura_AssignMethod(wx_String, length);
	Gura_AssignMethod(wx_String, max_size);
	Gura_AssignMethod(wx_String, reserve);
	Gura_AssignMethod(wx_String, resize);
	Gura_AssignMethod(wx_String, replace);
	Gura_AssignMethod(wx_String, replace_1);
	Gura_AssignMethod(wx_String, replace_2);
	Gura_AssignMethod(wx_String, replace_3);
	Gura_AssignMethod(wx_String, replace_4);
	Gura_AssignMethod(wx_String, replace_5);
	Gura_AssignMethod(wx_String, replace_6);
	Gura_AssignMethod(wx_String, replace_7);
	Gura_AssignMethod(wx_String, replace_8);
	Gura_AssignMethod(wx_String, replace_9);
	Gura_AssignMethod(wx_String, replace_10);
	Gura_AssignMethod(wx_String, replace_11);
	Gura_AssignMethod(wx_String, replace_12);
	Gura_AssignMethod(wx_String, rfind);
	Gura_AssignMethod(wx_String, rfind_1);
	Gura_AssignMethod(wx_String, rfind_2);
	Gura_AssignMethod(wx_String, rfind_3);
	Gura_AssignMethod(wx_String, size);
	Gura_AssignMethod(wx_String, substr);
	Gura_AssignMethod(wx_String, swap);
	Gura_AssignMethod(wx_String, Format);
	Gura_AssignMethod(wx_String, FormatV);
	Gura_AssignMethod(wx_String, From8BitData);
	Gura_AssignMethod(wx_String, From8BitData_1);
	Gura_AssignMethod(wx_String, FromAscii);
	Gura_AssignMethod(wx_String, FromAscii_1);
	Gura_AssignMethod(wx_String, FromAscii_2);
	Gura_AssignMethod(wx_String, FromAscii_3);
	Gura_AssignMethod(wx_String, FromAscii_4);
	Gura_AssignMethod(wx_String, FromCDouble);
	Gura_AssignMethod(wx_String, FromDouble);
	Gura_AssignMethod(wx_String, FromUTF8);
	Gura_AssignMethod(wx_String, FromUTF8_1);
	Gura_AssignMethod(wx_String, FromUTF8Unchecked);
	Gura_AssignMethod(wx_String, FromUTF8Unchecked_1);
}

Gura_ImplementDescendantCreator(wx_String)
{
	return new Object_wx_String((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
