//----------------------------------------------------------------------------
// wxScopedCharTypeBuffer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxScopedCharTypeBuffer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxScopedCharTypeBuffer
//----------------------------------------------------------------------------
Object_wx_ScopedCharTypeBuffer::~Object_wx_ScopedCharTypeBuffer()
{
}

Object *Object_wx_ScopedCharTypeBuffer::Clone() const
{
	return nullptr;
}

String Object_wx_ScopedCharTypeBuffer::ToString(bool exprFlag)
{
	String rtn("<wx.ScopedCharTypeBuffer:");
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
Gura_DeclareMethod(wx_ScopedCharTypeBuffer, wxScopedCharTypeBuffer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ScopedCharTypeBuffer, wxScopedCharTypeBuffer)
{
	Object_wx_ScopedCharTypeBuffer *pThis = Object_wx_ScopedCharTypeBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxScopedCharTypeBuffer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ScopedCharTypeBuffer, CreateNonOwned)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ScopedCharTypeBuffer, CreateNonOwned)
{
	Object_wx_ScopedCharTypeBuffer *pThis = Object_wx_ScopedCharTypeBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//int len = arg.GetNumber(1)
	//pThis->GetEntity()->CreateNonOwned();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ScopedCharTypeBuffer, CreateOwned)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ScopedCharTypeBuffer, CreateOwned)
{
	Object_wx_ScopedCharTypeBuffer *pThis = Object_wx_ScopedCharTypeBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//int len = arg.GetNumber(1)
	//pThis->GetEntity()->CreateOwned();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ScopedCharTypeBuffer, wxScopedCharTypeBuffer_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "src", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ScopedCharTypeBuffer, wxScopedCharTypeBuffer_1)
{
	Object_wx_ScopedCharTypeBuffer *pThis = Object_wx_ScopedCharTypeBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int src = arg.GetNumber(0)
	//pThis->GetEntity()->wxScopedCharTypeBuffer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ScopedCharTypeBuffer, release)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ScopedCharTypeBuffer, release)
{
	Object_wx_ScopedCharTypeBuffer *pThis = Object_wx_ScopedCharTypeBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->release();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ScopedCharTypeBuffer, reset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ScopedCharTypeBuffer, reset)
{
	Object_wx_ScopedCharTypeBuffer *pThis = Object_wx_ScopedCharTypeBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->reset();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ScopedCharTypeBuffer, data)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ScopedCharTypeBuffer, data)
{
	Object_wx_ScopedCharTypeBuffer *pThis = Object_wx_ScopedCharTypeBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->data();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ScopedCharTypeBuffer, data_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ScopedCharTypeBuffer, data_1)
{
	Object_wx_ScopedCharTypeBuffer *pThis = Object_wx_ScopedCharTypeBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->data();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ScopedCharTypeBuffer, length)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ScopedCharTypeBuffer, length)
{
	Object_wx_ScopedCharTypeBuffer *pThis = Object_wx_ScopedCharTypeBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->length();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxScopedCharTypeBuffer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ScopedCharTypeBuffer)
{
	Gura_AssignMethod(wx_ScopedCharTypeBuffer, wxScopedCharTypeBuffer);
	Gura_AssignMethod(wx_ScopedCharTypeBuffer, CreateNonOwned);
	Gura_AssignMethod(wx_ScopedCharTypeBuffer, CreateOwned);
	Gura_AssignMethod(wx_ScopedCharTypeBuffer, wxScopedCharTypeBuffer_1);
	Gura_AssignMethod(wx_ScopedCharTypeBuffer, release);
	Gura_AssignMethod(wx_ScopedCharTypeBuffer, reset);
	Gura_AssignMethod(wx_ScopedCharTypeBuffer, data);
	Gura_AssignMethod(wx_ScopedCharTypeBuffer, data_1);
	Gura_AssignMethod(wx_ScopedCharTypeBuffer, length);
}

Gura_ImplementDescendantCreator(wx_ScopedCharTypeBuffer)
{
	return new Object_wx_ScopedCharTypeBuffer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
