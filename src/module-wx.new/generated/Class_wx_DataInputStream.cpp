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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__DataInputStream, "DataInputStream")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_DataInputStream));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DataInputStream)
{
	//wxInputStream& stream = arg.GetNumber(0)
	//const wxMBConv& conv = arg.GetNumber(1)
	//wxDataInputStream(stream, conv);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_DataInputStream, __BigEndianOrdered, "BigEndianOrdered")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "be_order", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataInputStream, __BigEndianOrdered)
{
	Object_wx_DataInputStream *pThis = Object_wx_DataInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool be_order = arg.GetNumber(0)
	//pThis->GetEntity()->BigEndianOrdered(be_order);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataInputStream, __GetConv, "GetConv")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_DataInputStream, __GetConv)
{
	Object_wx_DataInputStream *pThis = Object_wx_DataInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxMBConv* _rtn = pThis->GetEntity()->GetConv();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataInputStream, __Read8, "Read8")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_DataInputStream, __Read8)
{
	Object_wx_DataInputStream *pThis = Object_wx_DataInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxUint8 _rtn = pThis->GetEntity()->Read8();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataInputStream, __Read8_1, "Read8_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataInputStream, __Read8_1)
{
	Object_wx_DataInputStream *pThis = Object_wx_DataInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxUint8* buffer = arg.GetNumber(0)
	//size_t size = arg.GetNumber(1)
	//pThis->GetEntity()->Read8(buffer, size);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataInputStream, __Read16, "Read16")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_DataInputStream, __Read16)
{
	Object_wx_DataInputStream *pThis = Object_wx_DataInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxUint16 _rtn = pThis->GetEntity()->Read16();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataInputStream, __Read16_1, "Read16_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataInputStream, __Read16_1)
{
	Object_wx_DataInputStream *pThis = Object_wx_DataInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxUint16* buffer = arg.GetNumber(0)
	//size_t size = arg.GetNumber(1)
	//pThis->GetEntity()->Read16(buffer, size);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataInputStream, __Read32, "Read32")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_DataInputStream, __Read32)
{
	Object_wx_DataInputStream *pThis = Object_wx_DataInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxUint32 _rtn = pThis->GetEntity()->Read32();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataInputStream, __Read32_1, "Read32_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataInputStream, __Read32_1)
{
	Object_wx_DataInputStream *pThis = Object_wx_DataInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxUint32* buffer = arg.GetNumber(0)
	//size_t size = arg.GetNumber(1)
	//pThis->GetEntity()->Read32(buffer, size);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataInputStream, __Read64, "Read64")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_DataInputStream, __Read64)
{
	Object_wx_DataInputStream *pThis = Object_wx_DataInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxUint64 _rtn = pThis->GetEntity()->Read64();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataInputStream, __Read64_1, "Read64_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataInputStream, __Read64_1)
{
	Object_wx_DataInputStream *pThis = Object_wx_DataInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxUint64* buffer = arg.GetNumber(0)
	//size_t size = arg.GetNumber(1)
	//pThis->GetEntity()->Read64(buffer, size);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataInputStream, __ReadFloat, "ReadFloat")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_DataInputStream, __ReadFloat)
{
	Object_wx_DataInputStream *pThis = Object_wx_DataInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//float _rtn = pThis->GetEntity()->ReadFloat();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataInputStream, __ReadFloat_1, "ReadFloat_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataInputStream, __ReadFloat_1)
{
	Object_wx_DataInputStream *pThis = Object_wx_DataInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//float* buffer = arg.GetNumber(0)
	//size_t size = arg.GetNumber(1)
	//pThis->GetEntity()->ReadFloat(buffer, size);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataInputStream, __ReadDouble, "ReadDouble")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_DataInputStream, __ReadDouble)
{
	Object_wx_DataInputStream *pThis = Object_wx_DataInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//double _rtn = pThis->GetEntity()->ReadDouble();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataInputStream, __ReadDouble_1, "ReadDouble_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataInputStream, __ReadDouble_1)
{
	Object_wx_DataInputStream *pThis = Object_wx_DataInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//double* buffer = arg.GetNumber(0)
	//size_t size = arg.GetNumber(1)
	//pThis->GetEntity()->ReadDouble(buffer, size);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataInputStream, __ReadString, "ReadString")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_DataInputStream, __ReadString)
{
	Object_wx_DataInputStream *pThis = Object_wx_DataInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->ReadString();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataInputStream, __SetConv, "SetConv")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataInputStream, __SetConv)
{
	Object_wx_DataInputStream *pThis = Object_wx_DataInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxMBConv& conv = arg.GetNumber(0)
	//pThis->GetEntity()->SetConv(conv);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataInputStream, __UseBasicPrecisions, "UseBasicPrecisions")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataInputStream, __UseBasicPrecisions)
{
	Object_wx_DataInputStream *pThis = Object_wx_DataInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->UseBasicPrecisions();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataInputStream, __UseExtendedPrecision, "UseExtendedPrecision")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataInputStream, __UseExtendedPrecision)
{
	Object_wx_DataInputStream *pThis = Object_wx_DataInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->UseExtendedPrecision();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDataInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataInputStream)
{
	// Constructor assignment
	Gura_AssignFunction(__DataInputStream);
	// Method assignment
	Gura_AssignMethod(wx_DataInputStream, __BigEndianOrdered);
	Gura_AssignMethod(wx_DataInputStream, __GetConv);
	Gura_AssignMethod(wx_DataInputStream, __Read8);
	Gura_AssignMethod(wx_DataInputStream, __Read8_1);
	Gura_AssignMethod(wx_DataInputStream, __Read16);
	Gura_AssignMethod(wx_DataInputStream, __Read16_1);
	Gura_AssignMethod(wx_DataInputStream, __Read32);
	Gura_AssignMethod(wx_DataInputStream, __Read32_1);
	Gura_AssignMethod(wx_DataInputStream, __Read64);
	Gura_AssignMethod(wx_DataInputStream, __Read64_1);
	Gura_AssignMethod(wx_DataInputStream, __ReadFloat);
	Gura_AssignMethod(wx_DataInputStream, __ReadFloat_1);
	Gura_AssignMethod(wx_DataInputStream, __ReadDouble);
	Gura_AssignMethod(wx_DataInputStream, __ReadDouble_1);
	Gura_AssignMethod(wx_DataInputStream, __ReadString);
	Gura_AssignMethod(wx_DataInputStream, __SetConv);
	Gura_AssignMethod(wx_DataInputStream, __UseBasicPrecisions);
	Gura_AssignMethod(wx_DataInputStream, __UseExtendedPrecision);
}

Gura_ImplementDescendantCreator(wx_DataInputStream)
{
	return new Object_wx_DataInputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
