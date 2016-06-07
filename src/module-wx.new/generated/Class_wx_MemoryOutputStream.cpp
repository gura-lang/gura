//----------------------------------------------------------------------------
// wxMemoryOutputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMemoryOutputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMemoryOutputStream
//----------------------------------------------------------------------------
Object_wx_MemoryOutputStream::~Object_wx_MemoryOutputStream()
{
}

Object *Object_wx_MemoryOutputStream::Clone() const
{
	return nullptr;
}

String Object_wx_MemoryOutputStream::ToString(bool exprFlag)
{
	String rtn("<wx.MemoryOutputStream:");
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
Gura_DeclareFunctionAlias(__MemoryOutputStream, "MemoryOutputStream")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "length", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_MemoryOutputStream));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__MemoryOutputStream)
{
	//void* data = arg.GetNumber(0)
	//size_t length = arg.GetNumber(1)
	//wxMemoryOutputStream(data, length);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_MemoryOutputStream, __CopyTo, "CopyTo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MemoryOutputStream, __CopyTo)
{
	Object_wx_MemoryOutputStream *pThis = Object_wx_MemoryOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//void* buffer = arg.GetNumber(0)
	//size_t len = arg.GetNumber(1)
	//pThis->GetEntity()->CopyTo(buffer, len);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MemoryOutputStream, __GetOutputStreamBuffer, "GetOutputStreamBuffer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MemoryOutputStream, __GetOutputStreamBuffer)
{
	Object_wx_MemoryOutputStream *pThis = Object_wx_MemoryOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOutputStreamBuffer();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxMemoryOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MemoryOutputStream)
{
	// Constructor assignment
	Gura_AssignFunction(__MemoryOutputStream);
	// Method assignment
	Gura_AssignMethod(wx_MemoryOutputStream, __CopyTo);
	Gura_AssignMethod(wx_MemoryOutputStream, __GetOutputStreamBuffer);
}

Gura_ImplementDescendantCreator(wx_MemoryOutputStream)
{
	return new Object_wx_MemoryOutputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
