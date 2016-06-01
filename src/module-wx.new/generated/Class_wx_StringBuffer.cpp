//----------------------------------------------------------------------------
// wxStringBuffer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxStringBuffer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxStringBuffer
//----------------------------------------------------------------------------
Object_wx_StringBuffer::~Object_wx_StringBuffer()
{
}

Object *Object_wx_StringBuffer::Clone() const
{
	return nullptr;
}

String Object_wx_StringBuffer::ToString(bool exprFlag)
{
	String rtn("<wx.StringBuffer:");
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
Gura_DeclareMethod(wx_StringBuffer, wxStringBuffer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StringBuffer, wxStringBuffer)
{
	Signal &sig = env.GetSignal();
	Object_wx_StringBuffer *pThis = Object_wx_StringBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//int len = arg.GetNumber(1)
	//pThis->GetEntity()->wxStringBuffer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StringBuffer, ~wxStringBuffer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StringBuffer, ~wxStringBuffer)
{
	Signal &sig = env.GetSignal();
	Object_wx_StringBuffer *pThis = Object_wx_StringBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxStringBuffer();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxStringBuffer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StringBuffer)
{
	Gura_AssignMethod(wx_StringBuffer, wxStringBuffer);
	Gura_AssignMethod(wx_StringBuffer, ~wxStringBuffer);
}

Gura_ImplementDescendantCreator(wx_StringBuffer)
{
	return new Object_wx_StringBuffer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
