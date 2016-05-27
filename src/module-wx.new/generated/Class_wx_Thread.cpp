//----------------------------------------------------------------------------
// wxThread
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxThread
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxThread
//----------------------------------------------------------------------------
Object_wx_Thread::~Object_wx_Thread()
{
}

Object *Object_wx_Thread::Clone() const
{
	return nullptr;
}

String Object_wx_Thread::ToString(bool exprFlag)
{
	String rtn("<wx.Thread:");
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
// Class implementation for wxThread
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Thread)
{
}

Gura_ImplementDescendantCreator(wx_Thread)
{
	return new Object_wx_Thread((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
