//----------------------------------------------------------------------------
// wxTextOutputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTextOutputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTextOutputStream
//----------------------------------------------------------------------------
Object_wx_TextOutputStream::~Object_wx_TextOutputStream()
{
}

Object *Object_wx_TextOutputStream::Clone() const
{
	return nullptr;
}

String Object_wx_TextOutputStream::ToString(bool exprFlag)
{
	String rtn("<wx.TextOutputStream:");
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
Gura_DeclareMethod(wx_TextOutputStream, wxTextOutputStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextOutputStream, wxTextOutputStream)
{
	Object_wx_TextOutputStream *pThis = Object_wx_TextOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//int mode = arg.GetNumber(1)
	//int conv = arg.GetNumber(2)
	//pThis->GetEntity()->wxTextOutputStream();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextOutputStream, Flush)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextOutputStream, Flush)
{
	Object_wx_TextOutputStream *pThis = Object_wx_TextOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Flush();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextOutputStream, GetOutputStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextOutputStream, GetOutputStream)
{
	Object_wx_TextOutputStream *pThis = Object_wx_TextOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOutputStream();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextOutputStream, GetMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextOutputStream, GetMode)
{
	Object_wx_TextOutputStream *pThis = Object_wx_TextOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextOutputStream, PutChar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "c", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextOutputStream, PutChar)
{
	Object_wx_TextOutputStream *pThis = Object_wx_TextOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int c = arg.GetNumber(0)
	//pThis->GetEntity()->PutChar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextOutputStream, SetMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextOutputStream, SetMode)
{
	Object_wx_TextOutputStream *pThis = Object_wx_TextOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int mode = arg.GetNumber(0)
	//pThis->GetEntity()->SetMode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextOutputStream, Write)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "i", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextOutputStream, Write)
{
	Object_wx_TextOutputStream *pThis = Object_wx_TextOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int i = arg.GetNumber(0)
	//pThis->GetEntity()->Write();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextOutputStream, Write64)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "i64", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextOutputStream, Write64)
{
	Object_wx_TextOutputStream *pThis = Object_wx_TextOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int i64 = arg.GetNumber(0)
	//pThis->GetEntity()->Write64();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextOutputStream, Write32)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "i32", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextOutputStream, Write32)
{
	Object_wx_TextOutputStream *pThis = Object_wx_TextOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int i32 = arg.GetNumber(0)
	//pThis->GetEntity()->Write32();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextOutputStream, Write16)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "i16", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextOutputStream, Write16)
{
	Object_wx_TextOutputStream *pThis = Object_wx_TextOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int i16 = arg.GetNumber(0)
	//pThis->GetEntity()->Write16();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextOutputStream, Write8)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "i8", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextOutputStream, Write8)
{
	Object_wx_TextOutputStream *pThis = Object_wx_TextOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int i8 = arg.GetNumber(0)
	//pThis->GetEntity()->Write8();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextOutputStream, WriteDouble)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "f", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextOutputStream, WriteDouble)
{
	Object_wx_TextOutputStream *pThis = Object_wx_TextOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int f = arg.GetNumber(0)
	//pThis->GetEntity()->WriteDouble();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextOutputStream, WriteString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "string", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextOutputStream, WriteString)
{
	Object_wx_TextOutputStream *pThis = Object_wx_TextOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int string = arg.GetNumber(0)
	//pThis->GetEntity()->WriteString();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTextOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextOutputStream)
{
	Gura_AssignMethod(wx_TextOutputStream, wxTextOutputStream);
	Gura_AssignMethod(wx_TextOutputStream, Flush);
	Gura_AssignMethod(wx_TextOutputStream, GetOutputStream);
	Gura_AssignMethod(wx_TextOutputStream, GetMode);
	Gura_AssignMethod(wx_TextOutputStream, PutChar);
	Gura_AssignMethod(wx_TextOutputStream, SetMode);
	Gura_AssignMethod(wx_TextOutputStream, Write);
	Gura_AssignMethod(wx_TextOutputStream, Write64);
	Gura_AssignMethod(wx_TextOutputStream, Write32);
	Gura_AssignMethod(wx_TextOutputStream, Write16);
	Gura_AssignMethod(wx_TextOutputStream, Write8);
	Gura_AssignMethod(wx_TextOutputStream, WriteDouble);
	Gura_AssignMethod(wx_TextOutputStream, WriteString);
}

Gura_ImplementDescendantCreator(wx_TextOutputStream)
{
	return new Object_wx_TextOutputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
