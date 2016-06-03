//----------------------------------------------------------------------------
// wxWCharBuffer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxWCharBuffer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxWCharBuffer
//----------------------------------------------------------------------------
Object_wx_WCharBuffer::~Object_wx_WCharBuffer()
{
}

Object *Object_wx_WCharBuffer::Clone() const
{
	return nullptr;
}

String Object_wx_WCharBuffer::ToString(bool exprFlag)
{
	String rtn("<wx.WCharBuffer:");
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
Gura_DeclareFunctionAlias(__wxWCharBuffer, "wxWCharBuffer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_WCharBuffer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxWCharBuffer)
{
	//int buf = arg.GetNumber(0)
	//wxWCharBuffer();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxWCharBuffer_1, "wxWCharBuffer_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_WCharBuffer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxWCharBuffer_1)
{
	//int buf = arg.GetNumber(0)
	//wxWCharBuffer();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxWCharBuffer_2, "wxWCharBuffer_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_WCharBuffer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxWCharBuffer_2)
{
	//int str = arg.GetNumber(0)
	//wxWCharBuffer();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxWCharBuffer_3, "wxWCharBuffer_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_WCharBuffer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxWCharBuffer_3)
{
	//int len = arg.GetNumber(0)
	//wxWCharBuffer();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxWCharBuffer_4, "wxWCharBuffer_4")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cstr", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_WCharBuffer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxWCharBuffer_4)
{
	//int cstr = arg.GetNumber(0)
	//wxWCharBuffer();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxWCharBuffer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WCharBuffer)
{
	// Constructor assignment
	Gura_AssignFunction(__wxWCharBuffer);
	Gura_AssignFunction(__wxWCharBuffer_1);
	Gura_AssignFunction(__wxWCharBuffer_2);
	Gura_AssignFunction(__wxWCharBuffer_3);
	Gura_AssignFunction(__wxWCharBuffer_4);
}

Gura_ImplementDescendantCreator(wx_WCharBuffer)
{
	return new Object_wx_WCharBuffer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
