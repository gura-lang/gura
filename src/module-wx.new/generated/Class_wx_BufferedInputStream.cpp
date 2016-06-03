//----------------------------------------------------------------------------
// wxBufferedInputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxBufferedInputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxBufferedInputStream
//----------------------------------------------------------------------------
Object_wx_BufferedInputStream::~Object_wx_BufferedInputStream()
{
}

Object *Object_wx_BufferedInputStream::Clone() const
{
	return nullptr;
}

String Object_wx_BufferedInputStream::ToString(bool exprFlag)
{
	String rtn("<wx.BufferedInputStream:");
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
Gura_DeclareFunctionAlias(__wxBufferedInputStream, "wxBufferedInputStream")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_BufferedInputStream));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxBufferedInputStream)
{
	//int stream = arg.GetNumber(0)
	//int buffer = arg.GetNumber(1)
	//wxBufferedInputStream();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxBufferedInputStream_1, "wxBufferedInputStream_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bufsize", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_BufferedInputStream));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxBufferedInputStream_1)
{
	//int stream = arg.GetNumber(0)
	//int bufsize = arg.GetNumber(1)
	//wxBufferedInputStream();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxBufferedInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_BufferedInputStream)
{
	// Constructor assignment
	Gura_AssignFunction(__wxBufferedInputStream);
	Gura_AssignFunction(__wxBufferedInputStream_1);
}

Gura_ImplementDescendantCreator(wx_BufferedInputStream)
{
	return new Object_wx_BufferedInputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
