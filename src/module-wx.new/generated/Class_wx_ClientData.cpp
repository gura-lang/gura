//----------------------------------------------------------------------------
// wxClientData
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxClientData
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxClientData
//----------------------------------------------------------------------------
Object_wx_ClientData::~Object_wx_ClientData()
{
}

Object *Object_wx_ClientData::Clone() const
{
	return nullptr;
}

String Object_wx_ClientData::ToString(bool exprFlag)
{
	String rtn("<wx.ClientData:");
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
Gura_DeclareMethod(wx_ClientData, wxClientData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ClientData, wxClientData)
{
	Object_wx_ClientData *pThis = Object_wx_ClientData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxClientData();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxClientData
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ClientData)
{
	Gura_AssignMethod(wx_ClientData, wxClientData);
}

Gura_ImplementDescendantCreator(wx_ClientData)
{
	return new Object_wx_ClientData((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
