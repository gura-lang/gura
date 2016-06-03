//----------------------------------------------------------------------------
// wxDataFormat
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDataFormat
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDataFormat
//----------------------------------------------------------------------------
Object_wx_DataFormat::~Object_wx_DataFormat()
{
}

Object *Object_wx_DataFormat::Clone() const
{
	return nullptr;
}

String Object_wx_DataFormat::ToString(bool exprFlag)
{
	String rtn("<wx.DataFormat:");
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
Gura_DeclareMethodAlias(wx_DataFormat, __wxDataFormat, "wxDataFormat")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataFormat, __wxDataFormat)
{
	Object_wx_DataFormat *pThis = Object_wx_DataFormat::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int format = arg.GetNumber(0)
	//pThis->GetEntity()->wxDataFormat();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataFormat, __wxDataFormat_1, "wxDataFormat_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataFormat, __wxDataFormat_1)
{
	Object_wx_DataFormat *pThis = Object_wx_DataFormat::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int format = arg.GetNumber(0)
	//pThis->GetEntity()->wxDataFormat();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataFormat, __GetId, "GetId")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataFormat, __GetId)
{
	Object_wx_DataFormat *pThis = Object_wx_DataFormat::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetId();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataFormat, __GetType, "GetType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DataFormat, __GetType)
{
	Object_wx_DataFormat *pThis = Object_wx_DataFormat::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetType();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataFormat, __SetId, "SetId")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataFormat, __SetId)
{
	Object_wx_DataFormat *pThis = Object_wx_DataFormat::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int format = arg.GetNumber(0)
	//pThis->GetEntity()->SetId();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DataFormat, __SetType, "SetType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DataFormat, __SetType)
{
	Object_wx_DataFormat *pThis = Object_wx_DataFormat::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int type = arg.GetNumber(0)
	//pThis->GetEntity()->SetType();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDataFormat
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataFormat)
{
	Gura_AssignMethod(wx_DataFormat, __wxDataFormat);
	Gura_AssignMethod(wx_DataFormat, __wxDataFormat_1);
	Gura_AssignMethod(wx_DataFormat, __GetId);
	Gura_AssignMethod(wx_DataFormat, __GetType);
	Gura_AssignMethod(wx_DataFormat, __SetId);
	Gura_AssignMethod(wx_DataFormat, __SetType);
}

Gura_ImplementDescendantCreator(wx_DataFormat)
{
	return new Object_wx_DataFormat((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
