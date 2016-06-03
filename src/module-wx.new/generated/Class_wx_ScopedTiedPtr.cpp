//----------------------------------------------------------------------------
// wxScopedTiedPtr
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxScopedTiedPtr
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxScopedTiedPtr
//----------------------------------------------------------------------------
Object_wx_ScopedTiedPtr::~Object_wx_ScopedTiedPtr()
{
}

Object *Object_wx_ScopedTiedPtr::Clone() const
{
	return nullptr;
}

String Object_wx_ScopedTiedPtr::ToString(bool exprFlag)
{
	String rtn("<wx.ScopedTiedPtr:");
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
Gura_DeclareFunctionAlias(__ScopedTiedPtr, "ScopedTiedPtr")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ppTie", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ptr", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_ScopedTiedPtr));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__ScopedTiedPtr)
{
	//int ppTie = arg.GetNumber(0)
	//int ptr = arg.GetNumber(1)
	//wxScopedTiedPtr();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxScopedTiedPtr
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ScopedTiedPtr)
{
	// Constructor assignment
	Gura_AssignFunction(__ScopedTiedPtr);
}

Gura_ImplementDescendantCreator(wx_ScopedTiedPtr)
{
	return new Object_wx_ScopedTiedPtr((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
