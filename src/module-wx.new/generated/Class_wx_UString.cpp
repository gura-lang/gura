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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_UString, wxUString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_UString, wxUString)
{
	Object_wx_UString *pThis = Object_wx_UString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxUString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UString, wxUString_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UString, wxUString_1)
{
	Object_wx_UString *pThis = Object_wx_UString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//pThis->GetEntity()->wxUString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UString, wxUString_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UString, wxUString_2)
{
	Object_wx_UString *pThis = Object_wx_UString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//pThis->GetEntity()->wxUString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UString, wxUString_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UString, wxUString_3)
{
	Object_wx_UString *pThis = Object_wx_UString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buf = arg.GetNumber(0)
	//pThis->GetEntity()->wxUString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UString, wxUString_4)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UString, wxUString_4)
{
	Object_wx_UString *pThis = Object_wx_UString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//pThis->GetEntity()->wxUString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UString, wxUString_5)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UString, wxUString_5)
{
	Object_wx_UString *pThis = Object_wx_UString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buf = arg.GetNumber(0)
	//pThis->GetEntity()->wxUString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UString, wxUString_6)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UString, wxUString_6)
{
	Object_wx_UString *pThis = Object_wx_UString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//int conv = arg.GetNumber(1)
	//pThis->GetEntity()->wxUString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UString, wxUString_7)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UString, wxUString_7)
{
	Object_wx_UString *pThis = Object_wx_UString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buf = arg.GetNumber(0)
	//int conv = arg.GetNumber(1)
	//pThis->GetEntity()->wxUString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UString, wxUString_8)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UString, wxUString_8)
{
	Object_wx_UString *pThis = Object_wx_UString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//pThis->GetEntity()->wxUString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UString, wxUString_9)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UString, wxUString_9)
{
	Object_wx_UString *pThis = Object_wx_UString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buf = arg.GetNumber(0)
	//pThis->GetEntity()->wxUString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UString, wxUString_10)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UString, wxUString_10)
{
	Object_wx_UString *pThis = Object_wx_UString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//pThis->GetEntity()->wxUString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UString, wxUString_11)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UString, wxUString_11)
{
	Object_wx_UString *pThis = Object_wx_UString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ch = arg.GetNumber(0)
	//pThis->GetEntity()->wxUString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UString, wxUString_12)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UString, wxUString_12)
{
	Object_wx_UString *pThis = Object_wx_UString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ch = arg.GetNumber(0)
	//pThis->GetEntity()->wxUString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UString, wxUString_13)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UString, wxUString_13)
{
	Object_wx_UString *pThis = Object_wx_UString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ch = arg.GetNumber(0)
	//pThis->GetEntity()->wxUString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UString, wxUString_14)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UString, wxUString_14)
{
	Object_wx_UString *pThis = Object_wx_UString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ch = arg.GetNumber(0)
	//pThis->GetEntity()->wxUString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UString, wxUString_15)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UString, wxUString_15)
{
	Object_wx_UString *pThis = Object_wx_UString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ch = arg.GetNumber(0)
	//pThis->GetEntity()->wxUString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UString, wxUString_16)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UString, wxUString_16)
{
	Object_wx_UString *pThis = Object_wx_UString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//int ch = arg.GetNumber(1)
	//pThis->GetEntity()->wxUString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UString, wxUString_17)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UString, wxUString_17)
{
	Object_wx_UString *pThis = Object_wx_UString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//int ch = arg.GetNumber(1)
	//pThis->GetEntity()->wxUString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UString, wxUString_18)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UString, wxUString_18)
{
	Object_wx_UString *pThis = Object_wx_UString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//int ch = arg.GetNumber(1)
	//pThis->GetEntity()->wxUString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UString, wxUString_19)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UString, wxUString_19)
{
	Object_wx_UString *pThis = Object_wx_UString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//int ch = arg.GetNumber(1)
	//pThis->GetEntity()->wxUString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UString, wxUString_20)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UString, wxUString_20)
{
	Object_wx_UString *pThis = Object_wx_UString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//int ch = arg.GetNumber(1)
	//pThis->GetEntity()->wxUString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UString, FromAscii)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UString, FromAscii)
{
	Object_wx_UString *pThis = Object_wx_UString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//int n = arg.GetNumber(1)
	//pThis->GetEntity()->FromAscii();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UString, FromAscii_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UString, FromAscii_1)
{
	Object_wx_UString *pThis = Object_wx_UString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//pThis->GetEntity()->FromAscii();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UString, FromUTF8)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UString, FromUTF8)
{
	Object_wx_UString *pThis = Object_wx_UString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//int n = arg.GetNumber(1)
	//pThis->GetEntity()->FromUTF8();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UString, FromUTF8_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UString, FromUTF8_1)
{
	Object_wx_UString *pThis = Object_wx_UString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//pThis->GetEntity()->FromUTF8();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UString, FromUTF16)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UString, FromUTF16)
{
	Object_wx_UString *pThis = Object_wx_UString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//int n = arg.GetNumber(1)
	//pThis->GetEntity()->FromUTF16();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UString, FromUTF16_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UString, FromUTF16_1)
{
	Object_wx_UString *pThis = Object_wx_UString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//pThis->GetEntity()->FromUTF16();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UString, assignFromAscii)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UString, assignFromAscii)
{
	Object_wx_UString *pThis = Object_wx_UString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//pThis->GetEntity()->assignFromAscii();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UString, assignFromAscii_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UString, assignFromAscii_1)
{
	Object_wx_UString *pThis = Object_wx_UString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//int n = arg.GetNumber(1)
	//pThis->GetEntity()->assignFromAscii();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UString, assignFromUTF8)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UString, assignFromUTF8)
{
	Object_wx_UString *pThis = Object_wx_UString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//pThis->GetEntity()->assignFromUTF8();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UString, assignFromUTF8_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UString, assignFromUTF8_1)
{
	Object_wx_UString *pThis = Object_wx_UString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//int n = arg.GetNumber(1)
	//pThis->GetEntity()->assignFromUTF8();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UString, assignFromUTF16)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UString, assignFromUTF16)
{
	Object_wx_UString *pThis = Object_wx_UString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//pThis->GetEntity()->assignFromUTF16();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UString, assignFromUTF16_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UString, assignFromUTF16_1)
{
	Object_wx_UString *pThis = Object_wx_UString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//int n = arg.GetNumber(1)
	//pThis->GetEntity()->assignFromUTF16();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UString, assignFromCString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UString, assignFromCString)
{
	Object_wx_UString *pThis = Object_wx_UString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//pThis->GetEntity()->assignFromCString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UString, assignFromCString_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UString, assignFromCString_1)
{
	Object_wx_UString *pThis = Object_wx_UString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//int conv = arg.GetNumber(1)
	//pThis->GetEntity()->assignFromCString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UString, utf8_str)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_UString, utf8_str)
{
	Object_wx_UString *pThis = Object_wx_UString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->utf8_str();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UString, utf16_str)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_UString, utf16_str)
{
	Object_wx_UString *pThis = Object_wx_UString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->utf16_str();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UString, wc_str)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_UString, wc_str)
{
	Object_wx_UString *pThis = Object_wx_UString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wc_str();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UString, wxString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_UString, wxString)
{
	Object_wx_UString *pThis = Object_wx_UString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UString, assign)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UString, assign)
{
	Object_wx_UString *pThis = Object_wx_UString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//pThis->GetEntity()->assign();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UString, append)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UString, append)
{
	Object_wx_UString *pThis = Object_wx_UString::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int s = arg.GetNumber(0)
	//pThis->GetEntity()->append();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UString, insert)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UString, insert)
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
	Gura_AssignMethod(wx_UString, wxUString);
	Gura_AssignMethod(wx_UString, wxUString_1);
	Gura_AssignMethod(wx_UString, wxUString_2);
	Gura_AssignMethod(wx_UString, wxUString_3);
	Gura_AssignMethod(wx_UString, wxUString_4);
	Gura_AssignMethod(wx_UString, wxUString_5);
	Gura_AssignMethod(wx_UString, wxUString_6);
	Gura_AssignMethod(wx_UString, wxUString_7);
	Gura_AssignMethod(wx_UString, wxUString_8);
	Gura_AssignMethod(wx_UString, wxUString_9);
	Gura_AssignMethod(wx_UString, wxUString_10);
	Gura_AssignMethod(wx_UString, wxUString_11);
	Gura_AssignMethod(wx_UString, wxUString_12);
	Gura_AssignMethod(wx_UString, wxUString_13);
	Gura_AssignMethod(wx_UString, wxUString_14);
	Gura_AssignMethod(wx_UString, wxUString_15);
	Gura_AssignMethod(wx_UString, wxUString_16);
	Gura_AssignMethod(wx_UString, wxUString_17);
	Gura_AssignMethod(wx_UString, wxUString_18);
	Gura_AssignMethod(wx_UString, wxUString_19);
	Gura_AssignMethod(wx_UString, wxUString_20);
	Gura_AssignMethod(wx_UString, FromAscii);
	Gura_AssignMethod(wx_UString, FromAscii_1);
	Gura_AssignMethod(wx_UString, FromUTF8);
	Gura_AssignMethod(wx_UString, FromUTF8_1);
	Gura_AssignMethod(wx_UString, FromUTF16);
	Gura_AssignMethod(wx_UString, FromUTF16_1);
	Gura_AssignMethod(wx_UString, assignFromAscii);
	Gura_AssignMethod(wx_UString, assignFromAscii_1);
	Gura_AssignMethod(wx_UString, assignFromUTF8);
	Gura_AssignMethod(wx_UString, assignFromUTF8_1);
	Gura_AssignMethod(wx_UString, assignFromUTF16);
	Gura_AssignMethod(wx_UString, assignFromUTF16_1);
	Gura_AssignMethod(wx_UString, assignFromCString);
	Gura_AssignMethod(wx_UString, assignFromCString_1);
	Gura_AssignMethod(wx_UString, utf8_str);
	Gura_AssignMethod(wx_UString, utf16_str);
	Gura_AssignMethod(wx_UString, wc_str);
	Gura_AssignMethod(wx_UString, wxString);
	Gura_AssignMethod(wx_UString, assign);
	Gura_AssignMethod(wx_UString, append);
	Gura_AssignMethod(wx_UString, insert);
}

Gura_ImplementDescendantCreator(wx_UString)
{
	return new Object_wx_UString((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
