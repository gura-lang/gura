//----------------------------------------------------------------------------
// wxStdOutputStreamBuffer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxStdOutputStreamBuffer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxStdOutputStreamBuffer
//----------------------------------------------------------------------------
Object_wx_StdOutputStreamBuffer::~Object_wx_StdOutputStreamBuffer()
{
}

Object *Object_wx_StdOutputStreamBuffer::Clone() const
{
	return nullptr;
}

String Object_wx_StdOutputStreamBuffer::ToString(bool exprFlag)
{
	String rtn("<wx.StdOutputStreamBuffer:");
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
Gura_DeclareFunctionAlias(__StdOutputStreamBuffer, "StdOutputStreamBuffer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_StdOutputStreamBuffer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__StdOutputStreamBuffer)
{
	//int stream = arg.GetNumber(0)
	//wxStdOutputStreamBuffer();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxStdOutputStreamBuffer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StdOutputStreamBuffer)
{
	// Constructor assignment
	Gura_AssignFunction(__StdOutputStreamBuffer);
}

Gura_ImplementDescendantCreator(wx_StdOutputStreamBuffer)
{
	return new Object_wx_StdOutputStreamBuffer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
