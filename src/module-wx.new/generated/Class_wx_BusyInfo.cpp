//----------------------------------------------------------------------------
// wxBusyInfo
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxBusyInfo
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxBusyInfo
//----------------------------------------------------------------------------
Object_wx_BusyInfo::~Object_wx_BusyInfo()
{
}

Object *Object_wx_BusyInfo::Clone() const
{
	return nullptr;
}

String Object_wx_BusyInfo::ToString(bool exprFlag)
{
	String rtn("<wx.BusyInfo:");
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
Gura_DeclareMethod(wx_BusyInfo, wxBusyInfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BusyInfo, wxBusyInfo)
{
	Signal &sig = env.GetSignal();
	Object_wx_BusyInfo *pThis = Object_wx_BusyInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->wxBusyInfo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_BusyInfo, wxBusyInfo_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "msg", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BusyInfo, wxBusyInfo_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_BusyInfo *pThis = Object_wx_BusyInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int msg = arg.GetNumber(0)
	//int parent = arg.GetNumber(1)
	//pThis->GetEntity()->wxBusyInfo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_BusyInfo, ~wxBusyInfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_BusyInfo, ~wxBusyInfo)
{
	Signal &sig = env.GetSignal();
	Object_wx_BusyInfo *pThis = Object_wx_BusyInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxBusyInfo();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxBusyInfo
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_BusyInfo)
{
	Gura_AssignMethod(wx_BusyInfo, wxBusyInfo);
	Gura_AssignMethod(wx_BusyInfo, wxBusyInfo_1);
	Gura_AssignMethod(wx_BusyInfo, ~wxBusyInfo);
}

Gura_ImplementDescendantCreator(wx_BusyInfo)
{
	return new Object_wx_BusyInfo((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
