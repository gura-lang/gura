//----------------------------------------------------------------------------
// wxLogStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxLogStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxLogStream
//----------------------------------------------------------------------------
Object_wx_LogStream::~Object_wx_LogStream()
{
}

Object *Object_wx_LogStream::Clone() const
{
	return nullptr;
}

String Object_wx_LogStream::ToString(bool exprFlag)
{
	String rtn("<wx.LogStream:");
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
Gura_DeclareFunctionAlias(__LogStream, "LogStream")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "ostr", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_LogStream));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__LogStream)
{
	//std::ostream* ostr = arg.GetNumber(0)
	//wxLogStream(ostr);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxLogStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_LogStream)
{
	// Constructor assignment
	Gura_AssignFunction(__LogStream);
}

Gura_ImplementDescendantCreator(wx_LogStream)
{
	return new Object_wx_LogStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
