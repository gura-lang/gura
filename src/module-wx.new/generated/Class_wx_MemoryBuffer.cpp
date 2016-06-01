//----------------------------------------------------------------------------
// wxMemoryBuffer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMemoryBuffer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMemoryBuffer
//----------------------------------------------------------------------------
Object_wx_MemoryBuffer::~Object_wx_MemoryBuffer()
{
}

Object *Object_wx_MemoryBuffer::Clone() const
{
	return nullptr;
}

String Object_wx_MemoryBuffer::ToString(bool exprFlag)
{
	String rtn("<wx.MemoryBuffer:");
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
Gura_DeclareMethod(wx_MemoryBuffer, wxMemoryBuffer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "src", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MemoryBuffer, wxMemoryBuffer)
{
	Signal &sig = env.GetSignal();
	Object_wx_MemoryBuffer *pThis = Object_wx_MemoryBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int src = arg.GetNumber(0)
	//pThis->GetEntity()->wxMemoryBuffer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MemoryBuffer, wxMemoryBuffer_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MemoryBuffer, wxMemoryBuffer_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_MemoryBuffer *pThis = Object_wx_MemoryBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->wxMemoryBuffer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MemoryBuffer, AppendByte)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MemoryBuffer, AppendByte)
{
	Signal &sig = env.GetSignal();
	Object_wx_MemoryBuffer *pThis = Object_wx_MemoryBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->AppendByte();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MemoryBuffer, AppendData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MemoryBuffer, AppendData)
{
	Signal &sig = env.GetSignal();
	Object_wx_MemoryBuffer *pThis = Object_wx_MemoryBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//int len = arg.GetNumber(1)
	//pThis->GetEntity()->AppendData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MemoryBuffer, Clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MemoryBuffer, Clear)
{
	Signal &sig = env.GetSignal();
	Object_wx_MemoryBuffer *pThis = Object_wx_MemoryBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MemoryBuffer, GetAppendBuf)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizeNeeded", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MemoryBuffer, GetAppendBuf)
{
	Signal &sig = env.GetSignal();
	Object_wx_MemoryBuffer *pThis = Object_wx_MemoryBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int sizeNeeded = arg.GetNumber(0)
	//pThis->GetEntity()->GetAppendBuf();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MemoryBuffer, GetBufSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MemoryBuffer, GetBufSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_MemoryBuffer *pThis = Object_wx_MemoryBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetBufSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MemoryBuffer, GetData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MemoryBuffer, GetData)
{
	Signal &sig = env.GetSignal();
	Object_wx_MemoryBuffer *pThis = Object_wx_MemoryBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MemoryBuffer, GetDataLen)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MemoryBuffer, GetDataLen)
{
	Signal &sig = env.GetSignal();
	Object_wx_MemoryBuffer *pThis = Object_wx_MemoryBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetDataLen();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MemoryBuffer, GetWriteBuf)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizeNeeded", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MemoryBuffer, GetWriteBuf)
{
	Signal &sig = env.GetSignal();
	Object_wx_MemoryBuffer *pThis = Object_wx_MemoryBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int sizeNeeded = arg.GetNumber(0)
	//pThis->GetEntity()->GetWriteBuf();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MemoryBuffer, IsEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MemoryBuffer, IsEmpty)
{
	Signal &sig = env.GetSignal();
	Object_wx_MemoryBuffer *pThis = Object_wx_MemoryBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsEmpty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MemoryBuffer, SetBufSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MemoryBuffer, SetBufSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_MemoryBuffer *pThis = Object_wx_MemoryBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->SetBufSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MemoryBuffer, SetDataLen)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MemoryBuffer, SetDataLen)
{
	Signal &sig = env.GetSignal();
	Object_wx_MemoryBuffer *pThis = Object_wx_MemoryBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->SetDataLen();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MemoryBuffer, UngetAppendBuf)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizeUsed", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MemoryBuffer, UngetAppendBuf)
{
	Signal &sig = env.GetSignal();
	Object_wx_MemoryBuffer *pThis = Object_wx_MemoryBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int sizeUsed = arg.GetNumber(0)
	//pThis->GetEntity()->UngetAppendBuf();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MemoryBuffer, UngetWriteBuf)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizeUsed", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MemoryBuffer, UngetWriteBuf)
{
	Signal &sig = env.GetSignal();
	Object_wx_MemoryBuffer *pThis = Object_wx_MemoryBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int sizeUsed = arg.GetNumber(0)
	//pThis->GetEntity()->UngetWriteBuf();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxMemoryBuffer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MemoryBuffer)
{
	Gura_AssignMethod(wx_MemoryBuffer, wxMemoryBuffer);
	Gura_AssignMethod(wx_MemoryBuffer, wxMemoryBuffer_1);
	Gura_AssignMethod(wx_MemoryBuffer, AppendByte);
	Gura_AssignMethod(wx_MemoryBuffer, AppendData);
	Gura_AssignMethod(wx_MemoryBuffer, Clear);
	Gura_AssignMethod(wx_MemoryBuffer, GetAppendBuf);
	Gura_AssignMethod(wx_MemoryBuffer, GetBufSize);
	Gura_AssignMethod(wx_MemoryBuffer, GetData);
	Gura_AssignMethod(wx_MemoryBuffer, GetDataLen);
	Gura_AssignMethod(wx_MemoryBuffer, GetWriteBuf);
	Gura_AssignMethod(wx_MemoryBuffer, IsEmpty);
	Gura_AssignMethod(wx_MemoryBuffer, SetBufSize);
	Gura_AssignMethod(wx_MemoryBuffer, SetDataLen);
	Gura_AssignMethod(wx_MemoryBuffer, UngetAppendBuf);
	Gura_AssignMethod(wx_MemoryBuffer, UngetWriteBuf);
}

Gura_ImplementDescendantCreator(wx_MemoryBuffer)
{
	return new Object_wx_MemoryBuffer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
