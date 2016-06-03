//----------------------------------------------------------------------------
// wxCharBuffer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxCharBuffer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxCharBuffer
//----------------------------------------------------------------------------
Object_wx_CharBuffer::~Object_wx_CharBuffer()
{
}

Object *Object_wx_CharBuffer::Clone() const
{
	return nullptr;
}

String Object_wx_CharBuffer::ToString(bool exprFlag)
{
	String rtn("<wx.CharBuffer:");
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
Gura_DeclareMethodAlias(wx_CharBuffer, __wxCharBuffer, "wxCharBuffer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CharBuffer, __wxCharBuffer)
{
	Object_wx_CharBuffer *pThis = Object_wx_CharBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buf = arg.GetNumber(0)
	//pThis->GetEntity()->wxCharBuffer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CharBuffer, __wxCharBuffer_1, "wxCharBuffer_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CharBuffer, __wxCharBuffer_1)
{
	Object_wx_CharBuffer *pThis = Object_wx_CharBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buf = arg.GetNumber(0)
	//pThis->GetEntity()->wxCharBuffer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CharBuffer, __wxCharBuffer_2, "wxCharBuffer_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CharBuffer, __wxCharBuffer_2)
{
	Object_wx_CharBuffer *pThis = Object_wx_CharBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//pThis->GetEntity()->wxCharBuffer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CharBuffer, __wxCharBuffer_3, "wxCharBuffer_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CharBuffer, __wxCharBuffer_3)
{
	Object_wx_CharBuffer *pThis = Object_wx_CharBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int len = arg.GetNumber(0)
	//pThis->GetEntity()->wxCharBuffer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CharBuffer, __wxCharBuffer_4, "wxCharBuffer_4")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cstr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CharBuffer, __wxCharBuffer_4)
{
	Object_wx_CharBuffer *pThis = Object_wx_CharBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int cstr = arg.GetNumber(0)
	//pThis->GetEntity()->wxCharBuffer();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxCharBuffer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CharBuffer)
{
	Gura_AssignMethod(wx_CharBuffer, __wxCharBuffer);
	Gura_AssignMethod(wx_CharBuffer, __wxCharBuffer_1);
	Gura_AssignMethod(wx_CharBuffer, __wxCharBuffer_2);
	Gura_AssignMethod(wx_CharBuffer, __wxCharBuffer_3);
	Gura_AssignMethod(wx_CharBuffer, __wxCharBuffer_4);
}

Gura_ImplementDescendantCreator(wx_CharBuffer)
{
	return new Object_wx_CharBuffer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
