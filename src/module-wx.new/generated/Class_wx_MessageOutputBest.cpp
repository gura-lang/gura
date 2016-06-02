//----------------------------------------------------------------------------
// wxMessageOutputBest
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMessageOutputBest
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMessageOutputBest
//----------------------------------------------------------------------------
Object_wx_MessageOutputBest::~Object_wx_MessageOutputBest()
{
}

Object *Object_wx_MessageOutputBest::Clone() const
{
	return nullptr;
}

String Object_wx_MessageOutputBest::ToString(bool exprFlag)
{
	String rtn("<wx.MessageOutputBest:");
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
Gura_DeclareMethod(wx_MessageOutputBest, wxMessageOutputBest)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MessageOutputBest, wxMessageOutputBest)
{
	Object_wx_MessageOutputBest *pThis = Object_wx_MessageOutputBest::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->wxMessageOutputBest();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxMessageOutputBest
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MessageOutputBest)
{
	Gura_AssignMethod(wx_MessageOutputBest, wxMessageOutputBest);
}

Gura_ImplementDescendantCreator(wx_MessageOutputBest)
{
	return new Object_wx_MessageOutputBest((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
