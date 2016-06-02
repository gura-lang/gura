//----------------------------------------------------------------------------
// wxWindowUpdateLocker
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxWindowUpdateLocker
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxWindowUpdateLocker
//----------------------------------------------------------------------------
Object_wx_WindowUpdateLocker::~Object_wx_WindowUpdateLocker()
{
}

Object *Object_wx_WindowUpdateLocker::Clone() const
{
	return nullptr;
}

String Object_wx_WindowUpdateLocker::ToString(bool exprFlag)
{
	String rtn("<wx.WindowUpdateLocker:");
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
Gura_DeclareMethod(wx_WindowUpdateLocker, wxWindowUpdateLocker)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WindowUpdateLocker, wxWindowUpdateLocker)
{
	Object_wx_WindowUpdateLocker *pThis = Object_wx_WindowUpdateLocker::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//pThis->GetEntity()->wxWindowUpdateLocker();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxWindowUpdateLocker
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WindowUpdateLocker)
{
	Gura_AssignMethod(wx_WindowUpdateLocker, wxWindowUpdateLocker);
}

Gura_ImplementDescendantCreator(wx_WindowUpdateLocker)
{
	return new Object_wx_WindowUpdateLocker((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
