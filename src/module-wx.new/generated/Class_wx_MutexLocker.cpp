//----------------------------------------------------------------------------
// wxMutexLocker
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMutexLocker
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMutexLocker
//----------------------------------------------------------------------------
Object_wx_MutexLocker::~Object_wx_MutexLocker()
{
}

Object *Object_wx_MutexLocker::Clone() const
{
	return nullptr;
}

String Object_wx_MutexLocker::ToString(bool exprFlag)
{
	String rtn("<wx.MutexLocker:");
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
Gura_DeclareFunctionAlias(__MutexLocker, "MutexLocker")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mutex", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_MutexLocker));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__MutexLocker)
{
	//wxMutex& mutex = arg.GetNumber(0)
	//wxMutexLocker(mutex);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_MutexLocker, __IsOk, "IsOk")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MutexLocker, __IsOk)
{
	Object_wx_MutexLocker *pThis = Object_wx_MutexLocker::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxMutexLocker
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MutexLocker)
{
	// Constructor assignment
	Gura_AssignFunction(__MutexLocker);
	// Method assignment
	Gura_AssignMethod(wx_MutexLocker, __IsOk);
}

Gura_ImplementDescendantCreator(wx_MutexLocker)
{
	return new Object_wx_MutexLocker((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
