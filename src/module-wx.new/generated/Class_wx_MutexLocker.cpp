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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_MutexLocker, wxMutexLocker)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mutex", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MutexLocker, wxMutexLocker)
{
	Object_wx_MutexLocker *pThis = Object_wx_MutexLocker::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int mutex = arg.GetNumber(0)
	//pThis->GetEntity()->wxMutexLocker();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MutexLocker, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MutexLocker, IsOk)
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
	Gura_AssignMethod(wx_MutexLocker, wxMutexLocker);
	Gura_AssignMethod(wx_MutexLocker, IsOk);
}

Gura_ImplementDescendantCreator(wx_MutexLocker)
{
	return new Object_wx_MutexLocker((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
