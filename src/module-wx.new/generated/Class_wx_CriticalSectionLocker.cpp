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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_CriticalSectionLocker, __wxCriticalSectionLocker, "wxCriticalSectionLocker")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "criticalsection", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_CriticalSectionLocker, __wxCriticalSectionLocker)
{
	Object_wx_CriticalSectionLocker *pThis = Object_wx_CriticalSectionLocker::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int criticalsection = arg.GetNumber(0)
	//pThis->GetEntity()->wxCriticalSectionLocker();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxCriticalSectionLocker
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CriticalSectionLocker)
{
	Gura_AssignMethod(wx_CriticalSectionLocker, __wxCriticalSectionLocker);
}

Gura_ImplementDescendantCreator(wx_CriticalSectionLocker)
{
	return new Object_wx_CriticalSectionLocker((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
