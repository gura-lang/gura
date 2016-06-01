//----------------------------------------------------------------------------
// wxFileType
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFileType
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFileType
//----------------------------------------------------------------------------
Object_wx_FileType::~Object_wx_FileType()
{
}

Object *Object_wx_FileType::Clone() const
{
	return nullptr;
}

String Object_wx_FileType::ToString(bool exprFlag)
{
	String rtn("<wx.FileType:");
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
Gura_DeclareMethod(wx_FileType, wxFileType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileType, wxFileType)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileType *pThis = Object_wx_FileType::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxFileType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileType, MessageParameters)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileType, MessageParameters)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileType *pThis = Object_wx_FileType::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->MessageParameters();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileType, MessageParameters_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mimetype", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileType, MessageParameters_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileType *pThis = Object_wx_FileType::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//int mimetype = arg.GetNumber(1)
	//pThis->GetEntity()->MessageParameters();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileType, GetFileName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileType, GetFileName)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileType *pThis = Object_wx_FileType::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFileName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileType, GetMimeType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileType, GetMimeType)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileType *pThis = Object_wx_FileType::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetMimeType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileType, GetParamValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileType, GetParamValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileType *pThis = Object_wx_FileType::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->GetParamValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileType, ~MessageParameters)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileType, ~MessageParameters)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileType *pThis = Object_wx_FileType::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~MessageParameters();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFileType
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileType)
{
	Gura_AssignMethod(wx_FileType, wxFileType);
	Gura_AssignMethod(wx_FileType, MessageParameters);
	Gura_AssignMethod(wx_FileType, MessageParameters_1);
	Gura_AssignMethod(wx_FileType, GetFileName);
	Gura_AssignMethod(wx_FileType, GetMimeType);
	Gura_AssignMethod(wx_FileType, GetParamValue);
	Gura_AssignMethod(wx_FileType, ~MessageParameters);
}

Gura_ImplementDescendantCreator(wx_FileType)
{
	return new Object_wx_FileType((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
