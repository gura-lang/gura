//----------------------------------------------------------------------------
// wxDynamicLibraryDetails
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDynamicLibraryDetails
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDynamicLibraryDetails
//----------------------------------------------------------------------------
Object_wx_DynamicLibraryDetails::~Object_wx_DynamicLibraryDetails()
{
}

Object *Object_wx_DynamicLibraryDetails::Clone() const
{
	return nullptr;
}

String Object_wx_DynamicLibraryDetails::ToString(bool exprFlag)
{
	String rtn("<wx.DynamicLibraryDetails:");
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
Gura_DeclareMethodAlias(wx_DynamicLibraryDetails, __GetAddress, "GetAddress")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "addr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DynamicLibraryDetails, __GetAddress)
{
	Object_wx_DynamicLibraryDetails *pThis = Object_wx_DynamicLibraryDetails::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int addr = arg.GetNumber(0)
	//int len = arg.GetNumber(1)
	//pThis->GetEntity()->GetAddress();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DynamicLibraryDetails, __GetName, "GetName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DynamicLibraryDetails, __GetName)
{
	Object_wx_DynamicLibraryDetails *pThis = Object_wx_DynamicLibraryDetails::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DynamicLibraryDetails, __GetPath, "GetPath")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DynamicLibraryDetails, __GetPath)
{
	Object_wx_DynamicLibraryDetails *pThis = Object_wx_DynamicLibraryDetails::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPath();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DynamicLibraryDetails, __GetVersion, "GetVersion")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DynamicLibraryDetails, __GetVersion)
{
	Object_wx_DynamicLibraryDetails *pThis = Object_wx_DynamicLibraryDetails::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetVersion();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDynamicLibraryDetails
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DynamicLibraryDetails)
{
	// Class assignment
	Gura_AssignValueEx("DynamicLibraryDetails", Reference());
	// Method assignment
	Gura_AssignMethod(wx_DynamicLibraryDetails, __GetAddress);
	Gura_AssignMethod(wx_DynamicLibraryDetails, __GetName);
	Gura_AssignMethod(wx_DynamicLibraryDetails, __GetPath);
	Gura_AssignMethod(wx_DynamicLibraryDetails, __GetVersion);
}

Gura_ImplementDescendantCreator(wx_DynamicLibraryDetails)
{
	return new Object_wx_DynamicLibraryDetails((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
