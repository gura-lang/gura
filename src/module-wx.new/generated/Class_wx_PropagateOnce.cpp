//----------------------------------------------------------------------------
// wxPropagateOnce
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPropagateOnce
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPropagateOnce
//----------------------------------------------------------------------------
Object_wx_PropagateOnce::~Object_wx_PropagateOnce()
{
}

Object *Object_wx_PropagateOnce::Clone() const
{
	return nullptr;
}

String Object_wx_PropagateOnce::ToString(bool exprFlag)
{
	String rtn("<wx.PropagateOnce:");
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
Gura_DeclareFunctionAlias(__PropagateOnce, "PropagateOnce")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_PropagateOnce));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__PropagateOnce)
{
	//wxEvent& event = arg.GetNumber(0)
	//wxPropagateOnce();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPropagateOnce
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PropagateOnce)
{
	// Constructor assignment
	Gura_AssignFunction(__PropagateOnce);
}

Gura_ImplementDescendantCreator(wx_PropagateOnce)
{
	return new Object_wx_PropagateOnce((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
