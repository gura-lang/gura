//----------------------------------------------------------------------------
// wxTextInputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTextInputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTextInputStream
//----------------------------------------------------------------------------
Object_wx_TextInputStream::~Object_wx_TextInputStream()
{
}

Object *Object_wx_TextInputStream::Clone() const
{
	return nullptr;
}

String Object_wx_TextInputStream::ToString(bool exprFlag)
{
	String rtn("<wx.TextInputStream:");
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
Gura_DeclareMethod(wx_TextInputStream, wxTextInputStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sep", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextInputStream, wxTextInputStream)
{
	Object_wx_TextInputStream *pThis = Object_wx_TextInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//int sep = arg.GetNumber(1)
	//int conv = arg.GetNumber(2)
	//pThis->GetEntity()->wxTextInputStream();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextInputStream, GetInputStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextInputStream, GetInputStream)
{
	Object_wx_TextInputStream *pThis = Object_wx_TextInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetInputStream();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextInputStream, GetChar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextInputStream, GetChar)
{
	Object_wx_TextInputStream *pThis = Object_wx_TextInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetChar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextInputStream, Read16)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "base", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextInputStream, Read16)
{
	Object_wx_TextInputStream *pThis = Object_wx_TextInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int base = arg.GetNumber(0)
	//pThis->GetEntity()->Read16();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextInputStream, Read16S)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "base", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextInputStream, Read16S)
{
	Object_wx_TextInputStream *pThis = Object_wx_TextInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int base = arg.GetNumber(0)
	//pThis->GetEntity()->Read16S();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextInputStream, Read32)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "base", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextInputStream, Read32)
{
	Object_wx_TextInputStream *pThis = Object_wx_TextInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int base = arg.GetNumber(0)
	//pThis->GetEntity()->Read32();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextInputStream, Read32S)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "base", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextInputStream, Read32S)
{
	Object_wx_TextInputStream *pThis = Object_wx_TextInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int base = arg.GetNumber(0)
	//pThis->GetEntity()->Read32S();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextInputStream, Read64)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "base", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextInputStream, Read64)
{
	Object_wx_TextInputStream *pThis = Object_wx_TextInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int base = arg.GetNumber(0)
	//pThis->GetEntity()->Read64();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextInputStream, Read64S)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "base", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextInputStream, Read64S)
{
	Object_wx_TextInputStream *pThis = Object_wx_TextInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int base = arg.GetNumber(0)
	//pThis->GetEntity()->Read64S();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextInputStream, Read8)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "base", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextInputStream, Read8)
{
	Object_wx_TextInputStream *pThis = Object_wx_TextInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int base = arg.GetNumber(0)
	//pThis->GetEntity()->Read8();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextInputStream, Read8S)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "base", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextInputStream, Read8S)
{
	Object_wx_TextInputStream *pThis = Object_wx_TextInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int base = arg.GetNumber(0)
	//pThis->GetEntity()->Read8S();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextInputStream, ReadDouble)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextInputStream, ReadDouble)
{
	Object_wx_TextInputStream *pThis = Object_wx_TextInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ReadDouble();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextInputStream, ReadLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextInputStream, ReadLine)
{
	Object_wx_TextInputStream *pThis = Object_wx_TextInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ReadLine();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextInputStream, ReadString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextInputStream, ReadString)
{
	Object_wx_TextInputStream *pThis = Object_wx_TextInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ReadString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextInputStream, ReadWord)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextInputStream, ReadWord)
{
	Object_wx_TextInputStream *pThis = Object_wx_TextInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ReadWord();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextInputStream, SetStringSeparators)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sep", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextInputStream, SetStringSeparators)
{
	Object_wx_TextInputStream *pThis = Object_wx_TextInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sep = arg.GetNumber(0)
	//pThis->GetEntity()->SetStringSeparators();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTextInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextInputStream)
{
	Gura_AssignMethod(wx_TextInputStream, wxTextInputStream);
	Gura_AssignMethod(wx_TextInputStream, GetInputStream);
	Gura_AssignMethod(wx_TextInputStream, GetChar);
	Gura_AssignMethod(wx_TextInputStream, Read16);
	Gura_AssignMethod(wx_TextInputStream, Read16S);
	Gura_AssignMethod(wx_TextInputStream, Read32);
	Gura_AssignMethod(wx_TextInputStream, Read32S);
	Gura_AssignMethod(wx_TextInputStream, Read64);
	Gura_AssignMethod(wx_TextInputStream, Read64S);
	Gura_AssignMethod(wx_TextInputStream, Read8);
	Gura_AssignMethod(wx_TextInputStream, Read8S);
	Gura_AssignMethod(wx_TextInputStream, ReadDouble);
	Gura_AssignMethod(wx_TextInputStream, ReadLine);
	Gura_AssignMethod(wx_TextInputStream, ReadString);
	Gura_AssignMethod(wx_TextInputStream, ReadWord);
	Gura_AssignMethod(wx_TextInputStream, SetStringSeparators);
}

Gura_ImplementDescendantCreator(wx_TextInputStream)
{
	return new Object_wx_TextInputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
