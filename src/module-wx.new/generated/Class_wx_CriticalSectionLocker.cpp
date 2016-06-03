//----------------------------------------------------------------------------
// wxCriticalSectionLocker
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxCriticalSectionLocker
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxCriticalSectionLocker
//----------------------------------------------------------------------------
Object_wx_CriticalSectionLocker::~Object_wx_CriticalSectionLocker()
{
}

Object *Object_wx_CriticalSectionLocker::Clone() const
{
	return nullptr;
}

String Object_wx_CriticalSectionLocker::ToString(bool exprFlag)
{
	String rtn("<wx.CriticalSectionLocker:");
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
Gura_DeclareFunctionAlias(__wxCriticalSectionLocker, "wxCriticalSectionLocker")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "criticalsection", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_CriticalSectionLocker));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxCriticalSectionLocker)
{
	//int criticalsection = arg.GetNumber(0)
	//wxCriticalSectionLocker();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxCriticalSectionLocker
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CriticalSectionLocker)
{
	// Constructor assignment
	Gura_AssignFunction(__wxCriticalSectionLocker);
}

Gura_ImplementDescendantCreator(wx_CriticalSectionLocker)
{
	return new Object_wx_CriticalSectionLocker((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
