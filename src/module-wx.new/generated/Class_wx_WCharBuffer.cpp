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
Gura_DeclareFunctionAlias(__WCharBuffer, "WCharBuffer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_WCharBuffer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__WCharBuffer)
{
	//const wxCharTypeBufferBase& buf = arg.GetNumber(0)
	//wxWCharBuffer(buf);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__WCharBuffer_1, "WCharBuffer_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_WCharBuffer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__WCharBuffer_1)
{
	//const wxScopedCharTypeBufferBase& buf = arg.GetNumber(0)
	//wxWCharBuffer(buf);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__WCharBuffer_2, "WCharBuffer_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_WCharBuffer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__WCharBuffer_2)
{
	//const CharType* str = arg.GetNumber(0)
	//wxWCharBuffer(str);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__WCharBuffer_3, "WCharBuffer_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_WCharBuffer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__WCharBuffer_3)
{
	//size_t len = arg.GetNumber(0)
	//wxWCharBuffer(len);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__WCharBuffer_4, "WCharBuffer_4")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "cstr", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_WCharBuffer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__WCharBuffer_4)
{
	//const wxCStrData& cstr = arg.GetNumber(0)
	//wxWCharBuffer(cstr);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxWCharBuffer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WCharBuffer)
{
	// Constructor assignment
	Gura_AssignFunction(__WCharBuffer);
	Gura_AssignFunction(__WCharBuffer_1);
	Gura_AssignFunction(__WCharBuffer_2);
	Gura_AssignFunction(__WCharBuffer_3);
	Gura_AssignFunction(__WCharBuffer_4);
}

Gura_ImplementDescendantCreator(wx_WCharBuffer)
{
	return new Object_wx_WCharBuffer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
