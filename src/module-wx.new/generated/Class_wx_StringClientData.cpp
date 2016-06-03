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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__StringClientData, "StringClientData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_StringClientData));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__StringClientData)
{
	//wxStringClientData();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__StringClientData_1, "StringClientData_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_StringClientData));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__StringClientData_1)
{
	//int data = arg.GetNumber(0)
	//wxStringClientData();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_StringClientData, __GetData, "GetData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StringClientData, __GetData)
{
	Object_wx_StringClientData *pThis = Object_wx_StringClientData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_StringClientData, __SetData, "SetData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_StringClientData, __SetData)
{
	Object_wx_StringClientData *pThis = Object_wx_StringClientData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->SetData();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxStringClientData
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StringClientData)
{
	// Constructor assignment
	Gura_AssignFunction(__StringClientData);
	Gura_AssignFunction(__StringClientData_1);
	// Method assignment
	Gura_AssignMethod(wx_StringClientData, __GetData);
	Gura_AssignMethod(wx_StringClientData, __SetData);
}

Gura_ImplementDescendantCreator(wx_StringClientData)
{
	return new Object_wx_StringClientData((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
