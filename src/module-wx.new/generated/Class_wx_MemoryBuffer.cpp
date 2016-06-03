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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxMemoryBuffer, "wxMemoryBuffer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "src", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_MemoryBuffer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxMemoryBuffer)
{
	//int src = arg.GetNumber(0)
	//wxMemoryBuffer();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxMemoryBuffer_1, "wxMemoryBuffer_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_MemoryBuffer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxMemoryBuffer_1)
{
	//int size = arg.GetNumber(0)
	//wxMemoryBuffer();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_MemoryBuffer, __AppendByte, "AppendByte")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MemoryBuffer, __AppendByte)
{
	Object_wx_MemoryBuffer *pThis = Object_wx_MemoryBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->AppendByte();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MemoryBuffer, __AppendData, "AppendData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MemoryBuffer, __AppendData)
{
	Object_wx_MemoryBuffer *pThis = Object_wx_MemoryBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//int len = arg.GetNumber(1)
	//pThis->GetEntity()->AppendData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MemoryBuffer, __Clear, "Clear")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MemoryBuffer, __Clear)
{
	Object_wx_MemoryBuffer *pThis = Object_wx_MemoryBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MemoryBuffer, __GetAppendBuf, "GetAppendBuf")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizeNeeded", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MemoryBuffer, __GetAppendBuf)
{
	Object_wx_MemoryBuffer *pThis = Object_wx_MemoryBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sizeNeeded = arg.GetNumber(0)
	//pThis->GetEntity()->GetAppendBuf();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MemoryBuffer, __GetBufSize, "GetBufSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MemoryBuffer, __GetBufSize)
{
	Object_wx_MemoryBuffer *pThis = Object_wx_MemoryBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBufSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MemoryBuffer, __GetData, "GetData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MemoryBuffer, __GetData)
{
	Object_wx_MemoryBuffer *pThis = Object_wx_MemoryBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MemoryBuffer, __GetDataLen, "GetDataLen")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MemoryBuffer, __GetDataLen)
{
	Object_wx_MemoryBuffer *pThis = Object_wx_MemoryBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDataLen();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MemoryBuffer, __GetWriteBuf, "GetWriteBuf")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizeNeeded", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MemoryBuffer, __GetWriteBuf)
{
	Object_wx_MemoryBuffer *pThis = Object_wx_MemoryBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sizeNeeded = arg.GetNumber(0)
	//pThis->GetEntity()->GetWriteBuf();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MemoryBuffer, __IsEmpty, "IsEmpty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MemoryBuffer, __IsEmpty)
{
	Object_wx_MemoryBuffer *pThis = Object_wx_MemoryBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsEmpty();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MemoryBuffer, __SetBufSize, "SetBufSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MemoryBuffer, __SetBufSize)
{
	Object_wx_MemoryBuffer *pThis = Object_wx_MemoryBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->SetBufSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MemoryBuffer, __SetDataLen, "SetDataLen")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MemoryBuffer, __SetDataLen)
{
	Object_wx_MemoryBuffer *pThis = Object_wx_MemoryBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->SetDataLen();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MemoryBuffer, __UngetAppendBuf, "UngetAppendBuf")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizeUsed", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MemoryBuffer, __UngetAppendBuf)
{
	Object_wx_MemoryBuffer *pThis = Object_wx_MemoryBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sizeUsed = arg.GetNumber(0)
	//pThis->GetEntity()->UngetAppendBuf();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MemoryBuffer, __UngetWriteBuf, "UngetWriteBuf")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizeUsed", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MemoryBuffer, __UngetWriteBuf)
{
	Object_wx_MemoryBuffer *pThis = Object_wx_MemoryBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sizeUsed = arg.GetNumber(0)
	//pThis->GetEntity()->UngetWriteBuf();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxMemoryBuffer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MemoryBuffer)
{
	// Constructor assignment
	Gura_AssignFunction(__wxMemoryBuffer);
	Gura_AssignFunction(__wxMemoryBuffer_1);
	// Method assignment
	Gura_AssignMethod(wx_MemoryBuffer, __AppendByte);
	Gura_AssignMethod(wx_MemoryBuffer, __AppendData);
	Gura_AssignMethod(wx_MemoryBuffer, __Clear);
	Gura_AssignMethod(wx_MemoryBuffer, __GetAppendBuf);
	Gura_AssignMethod(wx_MemoryBuffer, __GetBufSize);
	Gura_AssignMethod(wx_MemoryBuffer, __GetData);
	Gura_AssignMethod(wx_MemoryBuffer, __GetDataLen);
	Gura_AssignMethod(wx_MemoryBuffer, __GetWriteBuf);
	Gura_AssignMethod(wx_MemoryBuffer, __IsEmpty);
	Gura_AssignMethod(wx_MemoryBuffer, __SetBufSize);
	Gura_AssignMethod(wx_MemoryBuffer, __SetDataLen);
	Gura_AssignMethod(wx_MemoryBuffer, __UngetAppendBuf);
	Gura_AssignMethod(wx_MemoryBuffer, __UngetWriteBuf);
}

Gura_ImplementDescendantCreator(wx_MemoryBuffer)
{
	return new Object_wx_MemoryBuffer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
