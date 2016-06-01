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
Gura_DeclareMethod(wx_UniChar, wxUniChar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_UniChar, wxUniChar)
{
	Signal &sig = env.GetSignal();
	Object_wx_UniChar *pThis = Object_wx_UniChar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxUniChar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UniChar, wxUniChar_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UniChar, wxUniChar_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_UniChar *pThis = Object_wx_UniChar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int c = arg.GetNumber(0)
	//pThis->GetEntity()->wxUniChar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UniChar, wxUniChar_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UniChar, wxUniChar_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_UniChar *pThis = Object_wx_UniChar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int c = arg.GetNumber(0)
	//pThis->GetEntity()->wxUniChar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UniChar, wxUniChar_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UniChar, wxUniChar_3)
{
	Signal &sig = env.GetSignal();
	Object_wx_UniChar *pThis = Object_wx_UniChar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int c = arg.GetNumber(0)
	//pThis->GetEntity()->wxUniChar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UniChar, wxUniChar_4)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UniChar, wxUniChar_4)
{
	Signal &sig = env.GetSignal();
	Object_wx_UniChar *pThis = Object_wx_UniChar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int c = arg.GetNumber(0)
	//pThis->GetEntity()->wxUniChar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UniChar, wxUniChar_5)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UniChar, wxUniChar_5)
{
	Signal &sig = env.GetSignal();
	Object_wx_UniChar *pThis = Object_wx_UniChar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int c = arg.GetNumber(0)
	//pThis->GetEntity()->wxUniChar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UniChar, wxUniChar_6)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UniChar, wxUniChar_6)
{
	Signal &sig = env.GetSignal();
	Object_wx_UniChar *pThis = Object_wx_UniChar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int c = arg.GetNumber(0)
	//pThis->GetEntity()->wxUniChar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UniChar, wxUniChar_7)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UniChar, wxUniChar_7)
{
	Signal &sig = env.GetSignal();
	Object_wx_UniChar *pThis = Object_wx_UniChar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int c = arg.GetNumber(0)
	//pThis->GetEntity()->wxUniChar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UniChar, wxUniChar_8)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UniChar, wxUniChar_8)
{
	Signal &sig = env.GetSignal();
	Object_wx_UniChar *pThis = Object_wx_UniChar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int c = arg.GetNumber(0)
	//pThis->GetEntity()->wxUniChar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UniChar, wxUniChar_9)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UniChar, wxUniChar_9)
{
	Signal &sig = env.GetSignal();
	Object_wx_UniChar *pThis = Object_wx_UniChar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int c = arg.GetNumber(0)
	//pThis->GetEntity()->wxUniChar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UniChar, wxUniChar_10)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UniChar, wxUniChar_10)
{
	Signal &sig = env.GetSignal();
	Object_wx_UniChar *pThis = Object_wx_UniChar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int c = arg.GetNumber(0)
	//pThis->GetEntity()->wxUniChar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UniChar, wxUniChar_11)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UniChar, wxUniChar_11)
{
	Signal &sig = env.GetSignal();
	Object_wx_UniChar *pThis = Object_wx_UniChar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int c = arg.GetNumber(0)
	//pThis->GetEntity()->wxUniChar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UniChar, GetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_UniChar, GetValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_UniChar *pThis = Object_wx_UniChar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UniChar, IsAscii)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_UniChar, IsAscii)
{
	Signal &sig = env.GetSignal();
	Object_wx_UniChar *pThis = Object_wx_UniChar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsAscii();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UniChar, GetAsChar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UniChar, GetAsChar)
{
	Signal &sig = env.GetSignal();
	Object_wx_UniChar *pThis = Object_wx_UniChar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int c = arg.GetNumber(0)
	//pThis->GetEntity()->GetAsChar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UniChar, char)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_UniChar, char)
{
	Signal &sig = env.GetSignal();
	Object_wx_UniChar *pThis = Object_wx_UniChar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->char();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UniChar, char_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_UniChar, char_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_UniChar *pThis = Object_wx_UniChar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->char();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UniChar, wchar_t)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_UniChar, wchar_t)
{
	Signal &sig = env.GetSignal();
	Object_wx_UniChar *pThis = Object_wx_UniChar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wchar_t();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UniChar, int)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_UniChar, int)
{
	Signal &sig = env.GetSignal();
	Object_wx_UniChar *pThis = Object_wx_UniChar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->int();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UniChar, int_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_UniChar, int_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_UniChar *pThis = Object_wx_UniChar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->int();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UniChar, int_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_UniChar, int_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_UniChar *pThis = Object_wx_UniChar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->int();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UniChar, int_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_UniChar, int_3)
{
	Signal &sig = env.GetSignal();
	Object_wx_UniChar *pThis = Object_wx_UniChar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->int();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UniChar, int_4)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_UniChar, int_4)
{
	Signal &sig = env.GetSignal();
	Object_wx_UniChar *pThis = Object_wx_UniChar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->int();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UniChar, int_5)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_UniChar, int_5)
{
	Signal &sig = env.GetSignal();
	Object_wx_UniChar *pThis = Object_wx_UniChar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->int();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UniChar, wxLongLong_t)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_UniChar, wxLongLong_t)
{
	Signal &sig = env.GetSignal();
	Object_wx_UniChar *pThis = Object_wx_UniChar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxLongLong_t();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UniChar, wxULongLong_t)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_UniChar, wxULongLong_t)
{
	Signal &sig = env.GetSignal();
	Object_wx_UniChar *pThis = Object_wx_UniChar::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxULongLong_t();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxUniChar
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_UniChar)
{
	Gura_AssignMethod(wx_UniChar, wxUniChar);
	Gura_AssignMethod(wx_UniChar, wxUniChar_1);
	Gura_AssignMethod(wx_UniChar, wxUniChar_2);
	Gura_AssignMethod(wx_UniChar, wxUniChar_3);
	Gura_AssignMethod(wx_UniChar, wxUniChar_4);
	Gura_AssignMethod(wx_UniChar, wxUniChar_5);
	Gura_AssignMethod(wx_UniChar, wxUniChar_6);
	Gura_AssignMethod(wx_UniChar, wxUniChar_7);
	Gura_AssignMethod(wx_UniChar, wxUniChar_8);
	Gura_AssignMethod(wx_UniChar, wxUniChar_9);
	Gura_AssignMethod(wx_UniChar, wxUniChar_10);
	Gura_AssignMethod(wx_UniChar, wxUniChar_11);
	Gura_AssignMethod(wx_UniChar, GetValue);
	Gura_AssignMethod(wx_UniChar, IsAscii);
	Gura_AssignMethod(wx_UniChar, GetAsChar);
	Gura_AssignMethod(wx_UniChar, char);
	Gura_AssignMethod(wx_UniChar, char_1);
	Gura_AssignMethod(wx_UniChar, wchar_t);
	Gura_AssignMethod(wx_UniChar, int);
	Gura_AssignMethod(wx_UniChar, int_1);
	Gura_AssignMethod(wx_UniChar, int_2);
	Gura_AssignMethod(wx_UniChar, int_3);
	Gura_AssignMethod(wx_UniChar, int_4);
	Gura_AssignMethod(wx_UniChar, int_5);
	Gura_AssignMethod(wx_UniChar, wxLongLong_t);
	Gura_AssignMethod(wx_UniChar, wxULongLong_t);
}

Gura_ImplementDescendantCreator(wx_UniChar)
{
	return new Object_wx_UniChar((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
