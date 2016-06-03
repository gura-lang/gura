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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxCharBuffer, "wxCharBuffer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxCharBuffer)
{
	//int buf = arg.GetNumber(0)
	//wxCharBuffer();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxCharBuffer_1, "wxCharBuffer_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxCharBuffer_1)
{
	//int buf = arg.GetNumber(0)
	//wxCharBuffer();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxCharBuffer_2, "wxCharBuffer_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxCharBuffer_2)
{
	//int str = arg.GetNumber(0)
	//wxCharBuffer();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxCharBuffer_3, "wxCharBuffer_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxCharBuffer_3)
{
	//int len = arg.GetNumber(0)
	//wxCharBuffer();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxCharBuffer_4, "wxCharBuffer_4")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cstr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxCharBuffer_4)
{
	//int cstr = arg.GetNumber(0)
	//wxCharBuffer();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxCharBuffer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CharBuffer)
{
	// Constructor assignment
	Gura_AssignFunction(__wxCharBuffer);
	Gura_AssignFunction(__wxCharBuffer_1);
	Gura_AssignFunction(__wxCharBuffer_2);
	Gura_AssignFunction(__wxCharBuffer_3);
	Gura_AssignFunction(__wxCharBuffer_4);
}

Gura_ImplementDescendantCreator(wx_CharBuffer)
{
	return new Object_wx_CharBuffer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
