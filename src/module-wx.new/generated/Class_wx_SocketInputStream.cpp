//----------------------------------------------------------------------------
// wxSocketInputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSocketInputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSocketInputStream
//----------------------------------------------------------------------------
Object_wx_SocketInputStream::~Object_wx_SocketInputStream()
{
}

Object *Object_wx_SocketInputStream::Clone() const
{
	return nullptr;
}

String Object_wx_SocketInputStream::ToString(bool exprFlag)
{
	String rtn("<wx.SocketInputStream:");
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
Gura_DeclareFunctionAlias(__SocketInputStream, "SocketInputStream")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_SocketInputStream));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__SocketInputStream)
{
	//wxSocketBase& s = arg.GetNumber(0)
	//wxSocketInputStream();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSocketInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SocketInputStream)
{
	// Constructor assignment
	Gura_AssignFunction(__SocketInputStream);
}

Gura_ImplementDescendantCreator(wx_SocketInputStream)
{
	return new Object_wx_SocketInputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
