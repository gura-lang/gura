//----------------------------------------------------------------------------
// wxStringBufferLength
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxStringBufferLength
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxStringBufferLength
//----------------------------------------------------------------------------
Object_wx_StringBufferLength::~Object_wx_StringBufferLength()
{
}

Object *Object_wx_StringBufferLength::Clone() const
{
	return nullptr;
}

String Object_wx_StringBufferLength::ToString(bool exprFlag)
{
	String rtn("<wx.StringBufferLength:");
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
Gura_DeclareMethod(wx_StringBufferLength, wxStringBufferLength)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StringBufferLength, wxStringBufferLength)
{
	Object_wx_StringBufferLength *pThis = Object_wx_StringBufferLength::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//int len = arg.GetNumber(1)
	//pThis->GetEntity()->wxStringBufferLength();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StringBufferLength, SetLength)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "nLength", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StringBufferLength, SetLength)
{
	Object_wx_StringBufferLength *pThis = Object_wx_StringBufferLength::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int nLength = arg.GetNumber(0)
	//pThis->GetEntity()->SetLength();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxStringBufferLength
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StringBufferLength)
{
	Gura_AssignMethod(wx_StringBufferLength, wxStringBufferLength);
	Gura_AssignMethod(wx_StringBufferLength, SetLength);
}

Gura_ImplementDescendantCreator(wx_StringBufferLength)
{
	return new Object_wx_StringBufferLength((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
