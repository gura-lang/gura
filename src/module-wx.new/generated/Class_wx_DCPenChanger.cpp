//----------------------------------------------------------------------------
// wxDCPenChanger
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDCPenChanger
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDCPenChanger
//----------------------------------------------------------------------------
Object_wx_DCPenChanger::~Object_wx_DCPenChanger()
{
}

Object *Object_wx_DCPenChanger::Clone() const
{
	return nullptr;
}

String Object_wx_DCPenChanger::ToString(bool exprFlag)
{
	String rtn("<wx.DCPenChanger:");
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
Gura_DeclareMethodAlias(wx_DCPenChanger, __wxDCPenChanger, "wxDCPenChanger")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pen", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DCPenChanger, __wxDCPenChanger)
{
	Object_wx_DCPenChanger *pThis = Object_wx_DCPenChanger::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int pen = arg.GetNumber(1)
	//pThis->GetEntity()->wxDCPenChanger();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDCPenChanger
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DCPenChanger)
{
	Gura_AssignMethod(wx_DCPenChanger, __wxDCPenChanger);
}

Gura_ImplementDescendantCreator(wx_DCPenChanger)
{
	return new Object_wx_DCPenChanger((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
