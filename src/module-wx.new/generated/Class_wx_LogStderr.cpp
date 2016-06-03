//----------------------------------------------------------------------------
// wxLogStderr
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxLogStderr
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxLogStderr
//----------------------------------------------------------------------------
Object_wx_LogStderr::~Object_wx_LogStderr()
{
}

Object *Object_wx_LogStderr::Clone() const
{
	return nullptr;
}

String Object_wx_LogStderr::ToString(bool exprFlag)
{
	String rtn("<wx.LogStderr:");
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
Gura_DeclareFunctionAlias(__wxLogStderr, "wxLogStderr")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxLogStderr)
{
	//int fp = arg.GetNumber(0)
	//wxLogStderr();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxLogStderr
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_LogStderr)
{
	// Constructor assignment
	Gura_AssignFunction(__wxLogStderr);
}

Gura_ImplementDescendantCreator(wx_LogStderr)
{
	return new Object_wx_LogStderr((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
