//----------------------------------------------------------------------------
// wxDataOutputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDataOutputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDataOutputStream
//----------------------------------------------------------------------------
Object_wx_DataOutputStream::~Object_wx_DataOutputStream()
{
}

Object *Object_wx_DataOutputStream::Clone() const
{
	return nullptr;
}

String Object_wx_DataOutputStream::ToString(bool exprFlag)
{
	String rtn("<wx.DataOutputStream:");
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
Gura_DeclareMethod(wx_DataOutputStream, wxDataOutputStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataOutputStream, wxDataOutputStream)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//int conv = arg.GetNumber(1)
	//pThis->GetEntity()->wxDataOutputStream();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataOutputStream, ~wxDataOutputStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataOutputStream, ~wxDataOutputStream)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxDataOutputStream();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataOutputStream, BigEndianOrdered)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "be_order", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataOutputStream, BigEndianOrdered)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int be_order = arg.GetNumber(0)
	//pThis->GetEntity()->BigEndianOrdered();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataOutputStream, GetConv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataOutputStream, GetConv)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetConv();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataOutputStream, SetConv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataOutputStream, SetConv)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int conv = arg.GetNumber(0)
	//pThis->GetEntity()->SetConv();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataOutputStream, UseBasicPrecisions)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataOutputStream, UseBasicPrecisions)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->UseBasicPrecisions();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataOutputStream, UseExtendedPrecision)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataOutputStream, UseExtendedPrecision)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->UseExtendedPrecision();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataOutputStream, Write8)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "i8", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataOutputStream, Write8)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int i8 = arg.GetNumber(0)
	//pThis->GetEntity()->Write8();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataOutputStream, Write8_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataOutputStream, Write8_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//pThis->GetEntity()->Write8();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataOutputStream, Write16)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "i16", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataOutputStream, Write16)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int i16 = arg.GetNumber(0)
	//pThis->GetEntity()->Write16();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataOutputStream, Write16_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataOutputStream, Write16_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//pThis->GetEntity()->Write16();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataOutputStream, Write32)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "i32", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataOutputStream, Write32)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int i32 = arg.GetNumber(0)
	//pThis->GetEntity()->Write32();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataOutputStream, Write32_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataOutputStream, Write32_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//pThis->GetEntity()->Write32();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataOutputStream, Write64)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "i64", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataOutputStream, Write64)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int i64 = arg.GetNumber(0)
	//pThis->GetEntity()->Write64();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataOutputStream, Write64_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataOutputStream, Write64_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//pThis->GetEntity()->Write64();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataOutputStream, WriteFloat)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "f", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataOutputStream, WriteFloat)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int f = arg.GetNumber(0)
	//pThis->GetEntity()->WriteFloat();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataOutputStream, WriteFloat_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataOutputStream, WriteFloat_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//pThis->GetEntity()->WriteFloat();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataOutputStream, WriteDouble)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "d", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataOutputStream, WriteDouble)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int d = arg.GetNumber(0)
	//pThis->GetEntity()->WriteDouble();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataOutputStream, WriteDouble_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataOutputStream, WriteDouble_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//pThis->GetEntity()->WriteDouble();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataOutputStream, WriteString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "string", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataOutputStream, WriteString)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int string = arg.GetNumber(0)
	//pThis->GetEntity()->WriteString();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDataOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataOutputStream)
{
	Gura_AssignMethod(wx_DataOutputStream, wxDataOutputStream);
	Gura_AssignMethod(wx_DataOutputStream, ~wxDataOutputStream);
	Gura_AssignMethod(wx_DataOutputStream, BigEndianOrdered);
	Gura_AssignMethod(wx_DataOutputStream, GetConv);
	Gura_AssignMethod(wx_DataOutputStream, SetConv);
	Gura_AssignMethod(wx_DataOutputStream, UseBasicPrecisions);
	Gura_AssignMethod(wx_DataOutputStream, UseExtendedPrecision);
	Gura_AssignMethod(wx_DataOutputStream, Write8);
	Gura_AssignMethod(wx_DataOutputStream, Write8_1);
	Gura_AssignMethod(wx_DataOutputStream, Write16);
	Gura_AssignMethod(wx_DataOutputStream, Write16_1);
	Gura_AssignMethod(wx_DataOutputStream, Write32);
	Gura_AssignMethod(wx_DataOutputStream, Write32_1);
	Gura_AssignMethod(wx_DataOutputStream, Write64);
	Gura_AssignMethod(wx_DataOutputStream, Write64_1);
	Gura_AssignMethod(wx_DataOutputStream, WriteFloat);
	Gura_AssignMethod(wx_DataOutputStream, WriteFloat_1);
	Gura_AssignMethod(wx_DataOutputStream, WriteDouble);
	Gura_AssignMethod(wx_DataOutputStream, WriteDouble_1);
	Gura_AssignMethod(wx_DataOutputStream, WriteString);
}

Gura_ImplementDescendantCreator(wx_DataOutputStream)
{
	return new Object_wx_DataOutputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
