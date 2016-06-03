//----------------------------------------------------------------------------
// wxDataObjectSimple
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDataObjectSimple
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDataObjectSimple
//----------------------------------------------------------------------------
Object_wx_DataObjectSimple::~Object_wx_DataObjectSimple()
{
}

Object *Object_wx_DataObjectSimple::Clone() const
{
	return nullptr;
}

String Object_wx_DataObjectSimple::ToString(bool exprFlag)
{
	String rtn("<wx.DataObjectSimple:");
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
Gura_DeclareFunctionAlias(__wxDataObjectSimple, "wxDataObjectSimple")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_DataObjectSimple));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxDataObjectSimple)
{
	//int format = arg.GetNumber(0)
	//wxDataObjectSimple();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_DataObjectSimple, __GetDataHere, "GetDataHere")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataObjectSimple, __GetDataHere)
{
	Object_wx_DataObjectSimple *pThis = Object_wx_DataObjectSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buf = arg.GetNumber(0)
	//pThis->GetEntity()->GetDataHere();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataObjectSimple, __GetDataSize, "GetDataSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataObjectSimple, __GetDataSize)
{
	Object_wx_DataObjectSimple *pThis = Object_wx_DataObjectSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDataSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataObjectSimple, __GetFormat, "GetFormat")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataObjectSimple, __GetFormat)
{
	Object_wx_DataObjectSimple *pThis = Object_wx_DataObjectSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFormat();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataObjectSimple, __SetData, "SetData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataObjectSimple, __SetData)
{
	Object_wx_DataObjectSimple *pThis = Object_wx_DataObjectSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int len = arg.GetNumber(0)
	//int buf = arg.GetNumber(1)
	//pThis->GetEntity()->SetData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataObjectSimple, __SetFormat, "SetFormat")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataObjectSimple, __SetFormat)
{
	Object_wx_DataObjectSimple *pThis = Object_wx_DataObjectSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int format = arg.GetNumber(0)
	//pThis->GetEntity()->SetFormat();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDataObjectSimple
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataObjectSimple)
{
	// Constructor assignment
	Gura_AssignFunction(__wxDataObjectSimple);
	// Method assignment
	Gura_AssignMethod(wx_DataObjectSimple, __GetDataHere);
	Gura_AssignMethod(wx_DataObjectSimple, __GetDataSize);
	Gura_AssignMethod(wx_DataObjectSimple, __GetFormat);
	Gura_AssignMethod(wx_DataObjectSimple, __SetData);
	Gura_AssignMethod(wx_DataObjectSimple, __SetFormat);
}

Gura_ImplementDescendantCreator(wx_DataObjectSimple)
{
	return new Object_wx_DataObjectSimple((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
