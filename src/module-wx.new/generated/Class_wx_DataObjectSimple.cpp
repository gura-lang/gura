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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_DataObjectSimple, wxDataObjectSimple)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataObjectSimple, wxDataObjectSimple)
{
	Object_wx_DataObjectSimple *pThis = Object_wx_DataObjectSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int format = arg.GetNumber(0)
	//pThis->GetEntity()->wxDataObjectSimple();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataObjectSimple, GetDataHere)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataObjectSimple, GetDataHere)
{
	Object_wx_DataObjectSimple *pThis = Object_wx_DataObjectSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buf = arg.GetNumber(0)
	//pThis->GetEntity()->GetDataHere();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataObjectSimple, GetDataSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataObjectSimple, GetDataSize)
{
	Object_wx_DataObjectSimple *pThis = Object_wx_DataObjectSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDataSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataObjectSimple, GetFormat)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataObjectSimple, GetFormat)
{
	Object_wx_DataObjectSimple *pThis = Object_wx_DataObjectSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFormat();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataObjectSimple, SetData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "buf", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataObjectSimple, SetData)
{
	Object_wx_DataObjectSimple *pThis = Object_wx_DataObjectSimple::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int len = arg.GetNumber(0)
	//int buf = arg.GetNumber(1)
	//pThis->GetEntity()->SetData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DataObjectSimple, SetFormat)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataObjectSimple, SetFormat)
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
	Gura_AssignMethod(wx_DataObjectSimple, wxDataObjectSimple);
	Gura_AssignMethod(wx_DataObjectSimple, GetDataHere);
	Gura_AssignMethod(wx_DataObjectSimple, GetDataSize);
	Gura_AssignMethod(wx_DataObjectSimple, GetFormat);
	Gura_AssignMethod(wx_DataObjectSimple, SetData);
	Gura_AssignMethod(wx_DataObjectSimple, SetFormat);
}

Gura_ImplementDescendantCreator(wx_DataObjectSimple)
{
	return new Object_wx_DataObjectSimple((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
