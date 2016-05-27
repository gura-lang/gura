//----------------------------------------------------------------------------
// wxStackFrame
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxStackFrame
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxStackFrame
//----------------------------------------------------------------------------
Object_wx_StackFrame::~Object_wx_StackFrame()
{
}

Object *Object_wx_StackFrame::Clone() const
{
	return nullptr;
}

String Object_wx_StackFrame::ToString(bool exprFlag)
{
	String rtn("<wx.StackFrame:");
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
// Method implementation
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Class implementation for wxStackFrame
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StackFrame)
{
}

Gura_ImplementDescendantCreator(wx_StackFrame)
{
	return new Object_wx_StackFrame((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
