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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxTextInputStream, "wxTextInputStream")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sep", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxTextInputStream)
{
	//int stream = arg.GetNumber(0)
	//int sep = arg.GetNumber(1)
	//int conv = arg.GetNumber(2)
	//wxTextInputStream();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_TextInputStream, __GetInputStream, "GetInputStream")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextInputStream, __GetInputStream)
{
	Object_wx_TextInputStream *pThis = Object_wx_TextInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetInputStream();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextInputStream, __GetChar, "GetChar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextInputStream, __GetChar)
{
	Object_wx_TextInputStream *pThis = Object_wx_TextInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetChar();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextInputStream, __Read16, "Read16")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "base", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextInputStream, __Read16)
{
	Object_wx_TextInputStream *pThis = Object_wx_TextInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int base = arg.GetNumber(0)
	//pThis->GetEntity()->Read16();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextInputStream, __Read16S, "Read16S")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "base", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextInputStream, __Read16S)
{
	Object_wx_TextInputStream *pThis = Object_wx_TextInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int base = arg.GetNumber(0)
	//pThis->GetEntity()->Read16S();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextInputStream, __Read32, "Read32")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "base", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextInputStream, __Read32)
{
	Object_wx_TextInputStream *pThis = Object_wx_TextInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int base = arg.GetNumber(0)
	//pThis->GetEntity()->Read32();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextInputStream, __Read32S, "Read32S")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "base", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextInputStream, __Read32S)
{
	Object_wx_TextInputStream *pThis = Object_wx_TextInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int base = arg.GetNumber(0)
	//pThis->GetEntity()->Read32S();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextInputStream, __Read64, "Read64")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "base", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextInputStream, __Read64)
{
	Object_wx_TextInputStream *pThis = Object_wx_TextInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int base = arg.GetNumber(0)
	//pThis->GetEntity()->Read64();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextInputStream, __Read64S, "Read64S")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "base", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextInputStream, __Read64S)
{
	Object_wx_TextInputStream *pThis = Object_wx_TextInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int base = arg.GetNumber(0)
	//pThis->GetEntity()->Read64S();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextInputStream, __Read8, "Read8")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "base", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextInputStream, __Read8)
{
	Object_wx_TextInputStream *pThis = Object_wx_TextInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int base = arg.GetNumber(0)
	//pThis->GetEntity()->Read8();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextInputStream, __Read8S, "Read8S")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "base", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextInputStream, __Read8S)
{
	Object_wx_TextInputStream *pThis = Object_wx_TextInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int base = arg.GetNumber(0)
	//pThis->GetEntity()->Read8S();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextInputStream, __ReadDouble, "ReadDouble")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextInputStream, __ReadDouble)
{
	Object_wx_TextInputStream *pThis = Object_wx_TextInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ReadDouble();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextInputStream, __ReadLine, "ReadLine")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextInputStream, __ReadLine)
{
	Object_wx_TextInputStream *pThis = Object_wx_TextInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ReadLine();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextInputStream, __ReadString, "ReadString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextInputStream, __ReadString)
{
	Object_wx_TextInputStream *pThis = Object_wx_TextInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ReadString();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextInputStream, __ReadWord, "ReadWord")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextInputStream, __ReadWord)
{
	Object_wx_TextInputStream *pThis = Object_wx_TextInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ReadWord();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextInputStream, __SetStringSeparators, "SetStringSeparators")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sep", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextInputStream, __SetStringSeparators)
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
	// Constructor assignment
	Gura_AssignFunction(__wxTextInputStream);
	// Method assignment
	Gura_AssignMethod(wx_TextInputStream, __GetInputStream);
	Gura_AssignMethod(wx_TextInputStream, __GetChar);
	Gura_AssignMethod(wx_TextInputStream, __Read16);
	Gura_AssignMethod(wx_TextInputStream, __Read16S);
	Gura_AssignMethod(wx_TextInputStream, __Read32);
	Gura_AssignMethod(wx_TextInputStream, __Read32S);
	Gura_AssignMethod(wx_TextInputStream, __Read64);
	Gura_AssignMethod(wx_TextInputStream, __Read64S);
	Gura_AssignMethod(wx_TextInputStream, __Read8);
	Gura_AssignMethod(wx_TextInputStream, __Read8S);
	Gura_AssignMethod(wx_TextInputStream, __ReadDouble);
	Gura_AssignMethod(wx_TextInputStream, __ReadLine);
	Gura_AssignMethod(wx_TextInputStream, __ReadString);
	Gura_AssignMethod(wx_TextInputStream, __ReadWord);
	Gura_AssignMethod(wx_TextInputStream, __SetStringSeparators);
}

Gura_ImplementDescendantCreator(wx_TextInputStream)
{
	return new Object_wx_TextInputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
