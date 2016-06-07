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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__BusyInfo, "BusyInfo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_BusyInfo));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__BusyInfo)
{
	//const wxBusyInfoFlags& flags = arg.GetNumber(0)
	//wxBusyInfo(flags);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__BusyInfo_1, "BusyInfo_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "msg", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_BusyInfo));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__BusyInfo_1)
{
	//const wxString& msg = arg.GetNumber(0)
	//wxWindow* parent = arg.GetNumber(1)
	//wxBusyInfo(msg, parent);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxBusyInfo
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_BusyInfo)
{
	// Constructor assignment
	Gura_AssignFunction(__BusyInfo);
	Gura_AssignFunction(__BusyInfo_1);
}

Gura_ImplementDescendantCreator(wx_BusyInfo)
{
	return new Object_wx_BusyInfo((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
