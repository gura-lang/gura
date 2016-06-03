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
Gura_DeclareFunctionAlias(__wxStdInputStream, "wxStdInputStream")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxStdInputStream)
{
	//int stream = arg.GetNumber(0)
	//wxStdInputStream();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxStdInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StdInputStream)
{
	// Constructor assignment
	Gura_AssignFunction(__wxStdInputStream);
}

Gura_ImplementDescendantCreator(wx_StdInputStream)
{
	return new Object_wx_StdInputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
