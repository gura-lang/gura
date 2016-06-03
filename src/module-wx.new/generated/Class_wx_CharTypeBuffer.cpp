//----------------------------------------------------------------------------
// wxCharTypeBuffer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxCharTypeBuffer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxCharTypeBuffer
//----------------------------------------------------------------------------
Object_wx_CharTypeBuffer::~Object_wx_CharTypeBuffer()
{
}

Object *Object_wx_CharTypeBuffer::Clone() const
{
	return nullptr;
}

String Object_wx_CharTypeBuffer::ToString(bool exprFlag)
{
	String rtn("<wx.CharTypeBuffer:");
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
Gura_DeclareMethodAlias(wx_CharTypeBuffer, __wxCharTypeBuffer, "wxCharTypeBuffer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CharTypeBuffer, __wxCharTypeBuffer)
{
	Object_wx_CharTypeBuffer *pThis = Object_wx_CharTypeBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//int len = arg.GetNumber(1)
	//pThis->GetEntity()->wxCharTypeBuffer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CharTypeBuffer, __wxCharTypeBuffer_1, "wxCharTypeBuffer_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CharTypeBuffer, __wxCharTypeBuffer_1)
{
	Object_wx_CharTypeBuffer *pThis = Object_wx_CharTypeBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int len = arg.GetNumber(0)
	//pThis->GetEntity()->wxCharTypeBuffer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CharTypeBuffer, __wxCharTypeBuffer_2, "wxCharTypeBuffer_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "src", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CharTypeBuffer, __wxCharTypeBuffer_2)
{
	Object_wx_CharTypeBuffer *pThis = Object_wx_CharTypeBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int src = arg.GetNumber(0)
	//pThis->GetEntity()->wxCharTypeBuffer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CharTypeBuffer, __wxCharTypeBuffer_3, "wxCharTypeBuffer_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "src", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CharTypeBuffer, __wxCharTypeBuffer_3)
{
	Object_wx_CharTypeBuffer *pThis = Object_wx_CharTypeBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int src = arg.GetNumber(0)
	//pThis->GetEntity()->wxCharTypeBuffer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CharTypeBuffer, __extend, "extend")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CharTypeBuffer, __extend)
{
	Object_wx_CharTypeBuffer *pThis = Object_wx_CharTypeBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int len = arg.GetNumber(0)
	//pThis->GetEntity()->extend();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_CharTypeBuffer, __shrink, "shrink")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CharTypeBuffer, __shrink)
{
	Object_wx_CharTypeBuffer *pThis = Object_wx_CharTypeBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int len = arg.GetNumber(0)
	//pThis->GetEntity()->shrink();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxCharTypeBuffer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CharTypeBuffer)
{
	Gura_AssignMethod(wx_CharTypeBuffer, __wxCharTypeBuffer);
	Gura_AssignMethod(wx_CharTypeBuffer, __wxCharTypeBuffer_1);
	Gura_AssignMethod(wx_CharTypeBuffer, __wxCharTypeBuffer_2);
	Gura_AssignMethod(wx_CharTypeBuffer, __wxCharTypeBuffer_3);
	Gura_AssignMethod(wx_CharTypeBuffer, __extend);
	Gura_AssignMethod(wx_CharTypeBuffer, __shrink);
}

Gura_ImplementDescendantCreator(wx_CharTypeBuffer)
{
	return new Object_wx_CharTypeBuffer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
