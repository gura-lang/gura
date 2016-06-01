//----------------------------------------------------------------------------
// wxDataInputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDataInputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDataInputStream
//----------------------------------------------------------------------------
Object_wx_DataInputStream::~Object_wx_DataInputStream()
{
}

Object *Object_wx_DataInputStream::Clone() const
{
	return nullptr;
}

String Object_wx_DataInputStream::ToString(bool exprFlag)
{
	String rtn("<wx.DataInputStream:");
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
Gura_DeclareMethod(wx_DataInputStream, wxDataInputStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataInputStream, wxDataInputStream)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataInputStream *pThis = Object_wx_DataInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//int conv = arg.GetNumber(1)
	//pThis->GetEntity()->wxDataInputStream();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataInputStream, ~wxDataInputStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataInputStream, ~wxDataInputStream)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataInputStream *pThis = Object_wx_DataInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxDataInputStream();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataInputStream, BigEndianOrdered)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "be_order", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataInputStream, BigEndianOrdered)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataInputStream *pThis = Object_wx_DataInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int be_order = arg.GetNumber(0)
	//pThis->GetEntity()->BigEndianOrdered();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataInputStream, GetConv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataInputStream, GetConv)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataInputStream *pThis = Object_wx_DataInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetConv();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataInputStream, Read8)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataInputStream, Read8)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataInputStream *pThis = Object_wx_DataInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Read8();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataInputStream, Read8_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataInputStream, Read8_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataInputStream *pThis = Object_wx_DataInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//pThis->GetEntity()->Read8();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataInputStream, Read16)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataInputStream, Read16)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataInputStream *pThis = Object_wx_DataInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Read16();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataInputStream, Read16_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataInputStream, Read16_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataInputStream *pThis = Object_wx_DataInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//pThis->GetEntity()->Read16();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataInputStream, Read32)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataInputStream, Read32)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataInputStream *pThis = Object_wx_DataInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Read32();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataInputStream, Read32_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataInputStream, Read32_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataInputStream *pThis = Object_wx_DataInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//pThis->GetEntity()->Read32();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataInputStream, Read64)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataInputStream, Read64)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataInputStream *pThis = Object_wx_DataInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Read64();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataInputStream, Read64_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataInputStream, Read64_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataInputStream *pThis = Object_wx_DataInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//pThis->GetEntity()->Read64();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataInputStream, ReadFloat)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataInputStream, ReadFloat)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataInputStream *pThis = Object_wx_DataInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->ReadFloat();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataInputStream, ReadFloat_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataInputStream, ReadFloat_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataInputStream *pThis = Object_wx_DataInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//pThis->GetEntity()->ReadFloat();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataInputStream, ReadDouble)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataInputStream, ReadDouble)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataInputStream *pThis = Object_wx_DataInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->ReadDouble();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataInputStream, ReadDouble_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataInputStream, ReadDouble_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataInputStream *pThis = Object_wx_DataInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//pThis->GetEntity()->ReadDouble();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataInputStream, ReadString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataInputStream, ReadString)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataInputStream *pThis = Object_wx_DataInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->ReadString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataInputStream, SetConv)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataInputStream, SetConv)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataInputStream *pThis = Object_wx_DataInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int conv = arg.GetNumber(0)
	//pThis->GetEntity()->SetConv();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataInputStream, UseBasicPrecisions)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataInputStream, UseBasicPrecisions)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataInputStream *pThis = Object_wx_DataInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->UseBasicPrecisions();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataInputStream, UseExtendedPrecision)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataInputStream, UseExtendedPrecision)
{
	Signal &sig = env.GetSignal();
	Object_wx_DataInputStream *pThis = Object_wx_DataInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->UseExtendedPrecision();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDataInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataInputStream)
{
	Gura_AssignMethod(wx_DataInputStream, wxDataInputStream);
	Gura_AssignMethod(wx_DataInputStream, ~wxDataInputStream);
	Gura_AssignMethod(wx_DataInputStream, BigEndianOrdered);
	Gura_AssignMethod(wx_DataInputStream, GetConv);
	Gura_AssignMethod(wx_DataInputStream, Read8);
	Gura_AssignMethod(wx_DataInputStream, Read8_1);
	Gura_AssignMethod(wx_DataInputStream, Read16);
	Gura_AssignMethod(wx_DataInputStream, Read16_1);
	Gura_AssignMethod(wx_DataInputStream, Read32);
	Gura_AssignMethod(wx_DataInputStream, Read32_1);
	Gura_AssignMethod(wx_DataInputStream, Read64);
	Gura_AssignMethod(wx_DataInputStream, Read64_1);
	Gura_AssignMethod(wx_DataInputStream, ReadFloat);
	Gura_AssignMethod(wx_DataInputStream, ReadFloat_1);
	Gura_AssignMethod(wx_DataInputStream, ReadDouble);
	Gura_AssignMethod(wx_DataInputStream, ReadDouble_1);
	Gura_AssignMethod(wx_DataInputStream, ReadString);
	Gura_AssignMethod(wx_DataInputStream, SetConv);
	Gura_AssignMethod(wx_DataInputStream, UseBasicPrecisions);
	Gura_AssignMethod(wx_DataInputStream, UseExtendedPrecision);
}

Gura_ImplementDescendantCreator(wx_DataInputStream)
{
	return new Object_wx_DataInputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
