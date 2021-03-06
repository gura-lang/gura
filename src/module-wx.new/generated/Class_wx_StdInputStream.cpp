//----------------------------------------------------------------------------
// wxStdInputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxStdInputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxStdInputStream
//----------------------------------------------------------------------------
Object_wx_StdInputStream::~Object_wx_StdInputStream()
{
}

Object *Object_wx_StdInputStream::Clone() const
{
	return nullptr;
}

String Object_wx_StdInputStream::ToString(bool exprFlag)
{
	String rtn("<wx.StdInputStream:");
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
Gura_DeclareFunctionAlias(__StdInputStream, "StdInputStream")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_StdInputStream));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__StdInputStream)
{
	//wxInputStream& stream = arg.GetNumber(0)
	//wxStdInputStream(stream);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxStdInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StdInputStream)
{
	// Constructor assignment
	Gura_AssignFunction(__StdInputStream);
}

Gura_ImplementDescendantCreator(wx_StdInputStream)
{
	return new Object_wx_StdInputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
