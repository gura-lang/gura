//----------------------------------------------------------------------------
// wxMemoryInputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMemoryInputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMemoryInputStream
//----------------------------------------------------------------------------
Object_wx_MemoryInputStream::~Object_wx_MemoryInputStream()
{
}

Object *Object_wx_MemoryInputStream::Clone() const
{
	return nullptr;
}

String Object_wx_MemoryInputStream::ToString(bool exprFlag)
{
	String rtn("<wx.MemoryInputStream:");
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
Gura_DeclareMethodAlias(wx_MemoryInputStream, __wxMemoryInputStream, "wxMemoryInputStream")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MemoryInputStream, __wxMemoryInputStream)
{
	Object_wx_MemoryInputStream *pThis = Object_wx_MemoryInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//int len = arg.GetNumber(1)
	//pThis->GetEntity()->wxMemoryInputStream();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MemoryInputStream, __wxMemoryInputStream_1, "wxMemoryInputStream_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MemoryInputStream, __wxMemoryInputStream_1)
{
	Object_wx_MemoryInputStream *pThis = Object_wx_MemoryInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//pThis->GetEntity()->wxMemoryInputStream();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MemoryInputStream, __wxMemoryInputStream_2, "wxMemoryInputStream_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MemoryInputStream, __wxMemoryInputStream_2)
{
	Object_wx_MemoryInputStream *pThis = Object_wx_MemoryInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//int len = arg.GetNumber(1)
	//pThis->GetEntity()->wxMemoryInputStream();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MemoryInputStream, __GetInputStreamBuffer, "GetInputStreamBuffer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MemoryInputStream, __GetInputStreamBuffer)
{
	Object_wx_MemoryInputStream *pThis = Object_wx_MemoryInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetInputStreamBuffer();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxMemoryInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MemoryInputStream)
{
	Gura_AssignMethod(wx_MemoryInputStream, __wxMemoryInputStream);
	Gura_AssignMethod(wx_MemoryInputStream, __wxMemoryInputStream_1);
	Gura_AssignMethod(wx_MemoryInputStream, __wxMemoryInputStream_2);
	Gura_AssignMethod(wx_MemoryInputStream, __GetInputStreamBuffer);
}

Gura_ImplementDescendantCreator(wx_MemoryInputStream)
{
	return new Object_wx_MemoryInputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
