//----------------------------------------------------------------------------
// wxStringClientData
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxStringClientData
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxStringClientData
//----------------------------------------------------------------------------
Object_wx_StringClientData::~Object_wx_StringClientData()
{
}

Object *Object_wx_StringClientData::Clone() const
{
	return nullptr;
}

String Object_wx_StringClientData::ToString(bool exprFlag)
{
	String rtn("<wx.StringClientData:");
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
Gura_DeclareMethod(wx_StringClientData, wxStringClientData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StringClientData, wxStringClientData)
{
	Signal &sig = env.GetSignal();
	Object_wx_StringClientData *pThis = Object_wx_StringClientData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxStringClientData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StringClientData, wxStringClientData_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StringClientData, wxStringClientData_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_StringClientData *pThis = Object_wx_StringClientData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->wxStringClientData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StringClientData, GetData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StringClientData, GetData)
{
	Signal &sig = env.GetSignal();
	Object_wx_StringClientData *pThis = Object_wx_StringClientData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StringClientData, SetData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StringClientData, SetData)
{
	Signal &sig = env.GetSignal();
	Object_wx_StringClientData *pThis = Object_wx_StringClientData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->SetData();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxStringClientData
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StringClientData)
{
	Gura_AssignMethod(wx_StringClientData, wxStringClientData);
	Gura_AssignMethod(wx_StringClientData, wxStringClientData_1);
	Gura_AssignMethod(wx_StringClientData, GetData);
	Gura_AssignMethod(wx_StringClientData, SetData);
}

Gura_ImplementDescendantCreator(wx_StringClientData)
{
	return new Object_wx_StringClientData((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
