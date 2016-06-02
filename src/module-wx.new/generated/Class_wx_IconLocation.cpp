//----------------------------------------------------------------------------
// wxIconLocation
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxIconLocation
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxIconLocation
//----------------------------------------------------------------------------
Object_wx_IconLocation::~Object_wx_IconLocation()
{
}

Object *Object_wx_IconLocation::Clone() const
{
	return nullptr;
}

String Object_wx_IconLocation::ToString(bool exprFlag)
{
	String rtn("<wx.IconLocation:");
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
Gura_DeclareMethod(wx_IconLocation, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_IconLocation, IsOk)
{
	Object_wx_IconLocation *pThis = Object_wx_IconLocation::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethod(wx_IconLocation, SetFileName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_IconLocation, SetFileName)
{
	Object_wx_IconLocation *pThis = Object_wx_IconLocation::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//pThis->GetEntity()->SetFileName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_IconLocation, GetFileName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_IconLocation, GetFileName)
{
	Object_wx_IconLocation *pThis = Object_wx_IconLocation::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFileName();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxIconLocation
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_IconLocation)
{
	Gura_AssignMethod(wx_IconLocation, IsOk);
	Gura_AssignMethod(wx_IconLocation, SetFileName);
	Gura_AssignMethod(wx_IconLocation, GetFileName);
}

Gura_ImplementDescendantCreator(wx_IconLocation)
{
	return new Object_wx_IconLocation((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
