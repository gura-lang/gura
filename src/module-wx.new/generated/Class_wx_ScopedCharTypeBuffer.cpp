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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__ScopedCharTypeBuffer, "ScopedCharTypeBuffer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_ScopedCharTypeBuffer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__ScopedCharTypeBuffer)
{
	//wxScopedCharTypeBuffer();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__ScopedCharTypeBuffer_1, "ScopedCharTypeBuffer_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "src", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_ScopedCharTypeBuffer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__ScopedCharTypeBuffer_1)
{
	//const wxScopedCharTypeBuffer& src = arg.GetNumber(0)
	//wxScopedCharTypeBuffer(src);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_ScopedCharTypeBuffer, __CreateNonOwned, "CreateNonOwned")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ScopedCharTypeBuffer, __CreateNonOwned)
{
	Object_wx_ScopedCharTypeBuffer *pThis = Object_wx_ScopedCharTypeBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const CharType* str = arg.GetNumber(0)
	//size_t len = arg.GetNumber(1)
	//pThis->GetEntity()->CreateNonOwned(str, len);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ScopedCharTypeBuffer, __CreateOwned, "CreateOwned")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ScopedCharTypeBuffer, __CreateOwned)
{
	Object_wx_ScopedCharTypeBuffer *pThis = Object_wx_ScopedCharTypeBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//CharType* str = arg.GetNumber(0)
	//size_t len = arg.GetNumber(1)
	//pThis->GetEntity()->CreateOwned(str, len);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ScopedCharTypeBuffer, __release, "release")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ScopedCharTypeBuffer, __release)
{
	Object_wx_ScopedCharTypeBuffer *pThis = Object_wx_ScopedCharTypeBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->release();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ScopedCharTypeBuffer, __reset, "reset")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ScopedCharTypeBuffer, __reset)
{
	Object_wx_ScopedCharTypeBuffer *pThis = Object_wx_ScopedCharTypeBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->reset();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ScopedCharTypeBuffer, __data, "data")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ScopedCharTypeBuffer, __data)
{
	Object_wx_ScopedCharTypeBuffer *pThis = Object_wx_ScopedCharTypeBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->data();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ScopedCharTypeBuffer, __data_1, "data_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ScopedCharTypeBuffer, __data_1)
{
	Object_wx_ScopedCharTypeBuffer *pThis = Object_wx_ScopedCharTypeBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->data();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ScopedCharTypeBuffer, __length, "length")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ScopedCharTypeBuffer, __length)
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
	// Constructor assignment
	Gura_AssignFunction(__ScopedCharTypeBuffer);
	Gura_AssignFunction(__ScopedCharTypeBuffer_1);
	// Method assignment
	Gura_AssignMethod(wx_ScopedCharTypeBuffer, __CreateNonOwned);
	Gura_AssignMethod(wx_ScopedCharTypeBuffer, __CreateOwned);
	Gura_AssignMethod(wx_ScopedCharTypeBuffer, __release);
	Gura_AssignMethod(wx_ScopedCharTypeBuffer, __reset);
	Gura_AssignMethod(wx_ScopedCharTypeBuffer, __data);
	Gura_AssignMethod(wx_ScopedCharTypeBuffer, __data_1);
	Gura_AssignMethod(wx_ScopedCharTypeBuffer, __length);
}

Gura_ImplementDescendantCreator(wx_ScopedCharTypeBuffer)
{
	return new Object_wx_ScopedCharTypeBuffer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
