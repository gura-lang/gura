//----------------------------------------------------------------------------
// wxBusyCursor
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxBusyCursor
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxBusyCursor
//----------------------------------------------------------------------------
Object_wx_BusyCursor::~Object_wx_BusyCursor()
{
}

Object *Object_wx_BusyCursor::Clone() const
{
	return nullptr;
}

String Object_wx_BusyCursor::ToString(bool exprFlag)
{
	String rtn("<wx.BusyCursor:");
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
Gura_DeclareMethod(wx_BusyCursor, wxBusyCursor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cursor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BusyCursor, wxBusyCursor)
{
	Object_wx_BusyCursor *pThis = Object_wx_BusyCursor::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int cursor = arg.GetNumber(0)
	//pThis->GetEntity()->wxBusyCursor();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxBusyCursor
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_BusyCursor)
{
	Gura_AssignMethod(wx_BusyCursor, wxBusyCursor);
}

Gura_ImplementDescendantCreator(wx_BusyCursor)
{
	return new Object_wx_BusyCursor((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
