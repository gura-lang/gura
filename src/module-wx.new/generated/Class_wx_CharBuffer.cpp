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
Gura_DeclareFunctionAlias(__CharBuffer, "CharBuffer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_CharBuffer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__CharBuffer)
{
	//const wxCharTypeBufferBase& buf = arg.GetNumber(0)
	//wxCharBuffer();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__CharBuffer_1, "CharBuffer_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_CharBuffer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__CharBuffer_1)
{
	//const wxScopedCharTypeBufferBase& buf = arg.GetNumber(0)
	//wxCharBuffer();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__CharBuffer_2, "CharBuffer_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_CharBuffer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__CharBuffer_2)
{
	//const CharType* str = arg.GetNumber(0)
	//wxCharBuffer();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__CharBuffer_3, "CharBuffer_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_CharBuffer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__CharBuffer_3)
{
	//size_t len = arg.GetNumber(0)
	//wxCharBuffer();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__CharBuffer_4, "CharBuffer_4")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cstr", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_CharBuffer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__CharBuffer_4)
{
	//const wxCStrData& cstr = arg.GetNumber(0)
	//wxCharBuffer();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxCharBuffer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CharBuffer)
{
	// Constructor assignment
	Gura_AssignFunction(__CharBuffer);
	Gura_AssignFunction(__CharBuffer_1);
	Gura_AssignFunction(__CharBuffer_2);
	Gura_AssignFunction(__CharBuffer_3);
	Gura_AssignFunction(__CharBuffer_4);
}

Gura_ImplementDescendantCreator(wx_CharBuffer)
{
	return new Object_wx_CharBuffer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
