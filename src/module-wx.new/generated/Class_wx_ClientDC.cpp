//----------------------------------------------------------------------------
// wxClientDC
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxClientDC
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxClientDC
//----------------------------------------------------------------------------
Object_wx_ClientDC::~Object_wx_ClientDC()
{
}

Object *Object_wx_ClientDC::Clone() const
{
	return nullptr;
}

String Object_wx_ClientDC::ToString(bool exprFlag)
{
	String rtn("<wx.ClientDC:");
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
Gura_DeclareMethodAlias(wx_ClientDC, __wxClientDC, "wxClientDC")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ClientDC, __wxClientDC)
{
	Object_wx_ClientDC *pThis = Object_wx_ClientDC::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//pThis->GetEntity()->wxClientDC();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxClientDC
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ClientDC)
{
	Gura_AssignMethod(wx_ClientDC, __wxClientDC);
}

Gura_ImplementDescendantCreator(wx_ClientDC)
{
	return new Object_wx_ClientDC((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
