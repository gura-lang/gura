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
Gura_DeclareMethodAlias(wx_DataOutputStream, __wxDataOutputStream, "wxDataOutputStream")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataOutputStream, __wxDataOutputStream)
{
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//int conv = arg.GetNumber(1)
	//pThis->GetEntity()->wxDataOutputStream();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataOutputStream, __BigEndianOrdered, "BigEndianOrdered")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "be_order", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataOutputStream, __BigEndianOrdered)
{
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int be_order = arg.GetNumber(0)
	//pThis->GetEntity()->BigEndianOrdered();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataOutputStream, __GetConv, "GetConv")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataOutputStream, __GetConv)
{
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetConv();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataOutputStream, __SetConv, "SetConv")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataOutputStream, __SetConv)
{
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int conv = arg.GetNumber(0)
	//pThis->GetEntity()->SetConv();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataOutputStream, __UseBasicPrecisions, "UseBasicPrecisions")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataOutputStream, __UseBasicPrecisions)
{
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->UseBasicPrecisions();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataOutputStream, __UseExtendedPrecision, "UseExtendedPrecision")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataOutputStream, __UseExtendedPrecision)
{
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->UseExtendedPrecision();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataOutputStream, __Write8, "Write8")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "i8", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataOutputStream, __Write8)
{
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int i8 = arg.GetNumber(0)
	//pThis->GetEntity()->Write8();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataOutputStream, __Write8_1, "Write8_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataOutputStream, __Write8_1)
{
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//pThis->GetEntity()->Write8();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataOutputStream, __Write16, "Write16")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "i16", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataOutputStream, __Write16)
{
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int i16 = arg.GetNumber(0)
	//pThis->GetEntity()->Write16();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataOutputStream, __Write16_1, "Write16_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataOutputStream, __Write16_1)
{
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//pThis->GetEntity()->Write16();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataOutputStream, __Write32, "Write32")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "i32", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataOutputStream, __Write32)
{
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int i32 = arg.GetNumber(0)
	//pThis->GetEntity()->Write32();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataOutputStream, __Write32_1, "Write32_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataOutputStream, __Write32_1)
{
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//pThis->GetEntity()->Write32();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataOutputStream, __Write64, "Write64")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "i64", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataOutputStream, __Write64)
{
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int i64 = arg.GetNumber(0)
	//pThis->GetEntity()->Write64();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataOutputStream, __Write64_1, "Write64_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataOutputStream, __Write64_1)
{
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//pThis->GetEntity()->Write64();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataOutputStream, __WriteFloat, "WriteFloat")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "f", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataOutputStream, __WriteFloat)
{
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int f = arg.GetNumber(0)
	//pThis->GetEntity()->WriteFloat();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataOutputStream, __WriteFloat_1, "WriteFloat_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataOutputStream, __WriteFloat_1)
{
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//pThis->GetEntity()->WriteFloat();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataOutputStream, __WriteDouble, "WriteDouble")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "d", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataOutputStream, __WriteDouble)
{
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int d = arg.GetNumber(0)
	//pThis->GetEntity()->WriteDouble();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataOutputStream, __WriteDouble_1, "WriteDouble_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataOutputStream, __WriteDouble_1)
{
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//pThis->GetEntity()->WriteDouble();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataOutputStream, __WriteString, "WriteString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "string", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataOutputStream, __WriteString)
{
	Object_wx_DataOutputStream *pThis = Object_wx_DataOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int string = arg.GetNumber(0)
	//pThis->GetEntity()->WriteString();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDataOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataOutputStream)
{
	Gura_AssignMethod(wx_DataOutputStream, __wxDataOutputStream);
	Gura_AssignMethod(wx_DataOutputStream, __BigEndianOrdered);
	Gura_AssignMethod(wx_DataOutputStream, __GetConv);
	Gura_AssignMethod(wx_DataOutputStream, __SetConv);
	Gura_AssignMethod(wx_DataOutputStream, __UseBasicPrecisions);
	Gura_AssignMethod(wx_DataOutputStream, __UseExtendedPrecision);
	Gura_AssignMethod(wx_DataOutputStream, __Write8);
	Gura_AssignMethod(wx_DataOutputStream, __Write8_1);
	Gura_AssignMethod(wx_DataOutputStream, __Write16);
	Gura_AssignMethod(wx_DataOutputStream, __Write16_1);
	Gura_AssignMethod(wx_DataOutputStream, __Write32);
	Gura_AssignMethod(wx_DataOutputStream, __Write32_1);
	Gura_AssignMethod(wx_DataOutputStream, __Write64);
	Gura_AssignMethod(wx_DataOutputStream, __Write64_1);
	Gura_AssignMethod(wx_DataOutputStream, __WriteFloat);
	Gura_AssignMethod(wx_DataOutputStream, __WriteFloat_1);
	Gura_AssignMethod(wx_DataOutputStream, __WriteDouble);
	Gura_AssignMethod(wx_DataOutputStream, __WriteDouble_1);
	Gura_AssignMethod(wx_DataOutputStream, __WriteString);
}

Gura_ImplementDescendantCreator(wx_DataOutputStream)
{
	return new Object_wx_DataOutputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
