//----------------------------------------------------------------------------
// wxWCharBuffer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxWCharBuffer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxWCharBuffer
//----------------------------------------------------------------------------
Object_wx_WCharBuffer::~Object_wx_WCharBuffer()
{
}

Object *Object_wx_WCharBuffer::Clone() const
{
	return nullptr;
}

String Object_wx_WCharBuffer::ToString(bool exprFlag)
{
	String rtn("<wx.WCharBuffer:");
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
Gura_DeclareMethod(wx_WCharBuffer, wxWCharBuffer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WCharBuffer, wxWCharBuffer)
{
	Object_wx_WCharBuffer *pThis = Object_wx_WCharBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buf = arg.GetNumber(0)
	//pThis->GetEntity()->wxWCharBuffer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WCharBuffer, wxWCharBuffer_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WCharBuffer, wxWCharBuffer_1)
{
	Object_wx_WCharBuffer *pThis = Object_wx_WCharBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buf = arg.GetNumber(0)
	//pThis->GetEntity()->wxWCharBuffer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WCharBuffer, wxWCharBuffer_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WCharBuffer, wxWCharBuffer_2)
{
	Object_wx_WCharBuffer *pThis = Object_wx_WCharBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//pThis->GetEntity()->wxWCharBuffer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WCharBuffer, wxWCharBuffer_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WCharBuffer, wxWCharBuffer_3)
{
	Object_wx_WCharBuffer *pThis = Object_wx_WCharBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int len = arg.GetNumber(0)
	//pThis->GetEntity()->wxWCharBuffer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WCharBuffer, wxWCharBuffer_4)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cstr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WCharBuffer, wxWCharBuffer_4)
{
	Object_wx_WCharBuffer *pThis = Object_wx_WCharBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int cstr = arg.GetNumber(0)
	//pThis->GetEntity()->wxWCharBuffer();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxWCharBuffer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WCharBuffer)
{
	Gura_AssignMethod(wx_WCharBuffer, wxWCharBuffer);
	Gura_AssignMethod(wx_WCharBuffer, wxWCharBuffer_1);
	Gura_AssignMethod(wx_WCharBuffer, wxWCharBuffer_2);
	Gura_AssignMethod(wx_WCharBuffer, wxWCharBuffer_3);
	Gura_AssignMethod(wx_WCharBuffer, wxWCharBuffer_4);
}

Gura_ImplementDescendantCreator(wx_WCharBuffer)
{
	return new Object_wx_WCharBuffer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
