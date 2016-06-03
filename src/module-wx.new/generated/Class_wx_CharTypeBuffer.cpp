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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__CharTypeBuffer, "CharTypeBuffer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_CharTypeBuffer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__CharTypeBuffer)
{
	//int str = arg.GetNumber(0)
	//int len = arg.GetNumber(1)
	//wxCharTypeBuffer();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__CharTypeBuffer_1, "CharTypeBuffer_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_CharTypeBuffer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__CharTypeBuffer_1)
{
	//int len = arg.GetNumber(0)
	//wxCharTypeBuffer();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__CharTypeBuffer_2, "CharTypeBuffer_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "src", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_CharTypeBuffer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__CharTypeBuffer_2)
{
	//int src = arg.GetNumber(0)
	//wxCharTypeBuffer();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__CharTypeBuffer_3, "CharTypeBuffer_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "src", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_CharTypeBuffer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__CharTypeBuffer_3)
{
	//int src = arg.GetNumber(0)
	//wxCharTypeBuffer();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
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
	// Constructor assignment
	Gura_AssignFunction(__CharTypeBuffer);
	Gura_AssignFunction(__CharTypeBuffer_1);
	Gura_AssignFunction(__CharTypeBuffer_2);
	Gura_AssignFunction(__CharTypeBuffer_3);
	// Method assignment
	Gura_AssignMethod(wx_CharTypeBuffer, __extend);
	Gura_AssignMethod(wx_CharTypeBuffer, __shrink);
}

Gura_ImplementDescendantCreator(wx_CharTypeBuffer)
{
	return new Object_wx_CharTypeBuffer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
