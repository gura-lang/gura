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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__FileType, "FileType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_FileType));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__FileType)
{
	//wxFileType();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_FileType, __MessageParameters, "MessageParameters")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_FileType, __MessageParameters)
{
	Object_wx_FileType *pThis = Object_wx_FileType::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->MessageParameters();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileType, __MessageParameters_1, "MessageParameters_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mimetype", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileType, __MessageParameters_1)
{
	Object_wx_FileType *pThis = Object_wx_FileType::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& filename = arg.GetNumber(0)
	//const wxString& mimetype = arg.GetNumber(1)
	//pThis->GetEntity()->MessageParameters(filename, mimetype);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileType, __GetFileName, "GetFileName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_FileType, __GetFileName)
{
	Object_wx_FileType *pThis = Object_wx_FileType::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& _rtn = pThis->GetEntity()->GetFileName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileType, __GetMimeType, "GetMimeType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_FileType, __GetMimeType)
{
	Object_wx_FileType *pThis = Object_wx_FileType::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& _rtn = pThis->GetEntity()->GetMimeType();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileType, __GetParamValue, "GetParamValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileType, __GetParamValue)
{
	Object_wx_FileType *pThis = Object_wx_FileType::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//wxString _rtn = pThis->GetEntity()->GetParamValue(name);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFileType
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileType)
{
	// Constructor assignment
	Gura_AssignFunction(__FileType);
	// Method assignment
	Gura_AssignMethod(wx_FileType, __MessageParameters);
	Gura_AssignMethod(wx_FileType, __MessageParameters_1);
	Gura_AssignMethod(wx_FileType, __GetFileName);
	Gura_AssignMethod(wx_FileType, __GetMimeType);
	Gura_AssignMethod(wx_FileType, __GetParamValue);
}

Gura_ImplementDescendantCreator(wx_FileType)
{
	return new Object_wx_FileType((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
