//----------------------------------------------------------------------------
// wxStdInputStreamBuffer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxStdInputStreamBuffer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxStdInputStreamBuffer
//----------------------------------------------------------------------------
Object_wx_StdInputStreamBuffer::~Object_wx_StdInputStreamBuffer()
{
}

Object *Object_wx_StdInputStreamBuffer::Clone() const
{
	return nullptr;
}

String Object_wx_StdInputStreamBuffer::ToString(bool exprFlag)
{
	String rtn("<wx.StdInputStreamBuffer:");
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
Gura_DeclareMethodAlias(wx_StdInputStreamBuffer, __wxStdInputStreamBuffer, "wxStdInputStreamBuffer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StdInputStreamBuffer, __wxStdInputStreamBuffer)
{
	Object_wx_StdInputStreamBuffer *pThis = Object_wx_StdInputStreamBuffer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//pThis->GetEntity()->wxStdInputStreamBuffer();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxStdInputStreamBuffer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StdInputStreamBuffer)
{
	Gura_AssignMethod(wx_StdInputStreamBuffer, __wxStdInputStreamBuffer);
}

Gura_ImplementDescendantCreator(wx_StdInputStreamBuffer)
{
	return new Object_wx_StdInputStreamBuffer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
