//----------------------------------------------------------------------------
// wxFileTypeInfo
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFileTypeInfo
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFileTypeInfo
//----------------------------------------------------------------------------
Object_wx_FileTypeInfo::~Object_wx_FileTypeInfo()
{
}

Object *Object_wx_FileTypeInfo::Clone() const
{
	return nullptr;
}

String Object_wx_FileTypeInfo::ToString(bool exprFlag)
{
	String rtn("<wx.FileTypeInfo:");
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
Gura_DeclareFunctionAlias(__FileTypeInfo, "FileTypeInfo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_FileTypeInfo));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__FileTypeInfo)
{
	//wxFileTypeInfo();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__FileTypeInfo_1, "FileTypeInfo_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "mimeType", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_FileTypeInfo));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__FileTypeInfo_1)
{
	//const wxString& mimeType = arg.GetNumber(0)
	//wxFileTypeInfo(mimeType);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__FileTypeInfo_2, "FileTypeInfo_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "sArray", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_FileTypeInfo));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__FileTypeInfo_2)
{
	//const wxArrayString& sArray = arg.GetNumber(0)
	//wxFileTypeInfo(sArray);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_FileTypeInfo, __AddExtension, "AddExtension")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ext", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileTypeInfo, __AddExtension)
{
	Object_wx_FileTypeInfo *pThis = Object_wx_FileTypeInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& ext = arg.GetNumber(0)
	//pThis->GetEntity()->AddExtension(ext);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileTypeInfo, __SetDescription, "SetDescription")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "description", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileTypeInfo, __SetDescription)
{
	Object_wx_FileTypeInfo *pThis = Object_wx_FileTypeInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& description = arg.GetNumber(0)
	//pThis->GetEntity()->SetDescription(description);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileTypeInfo, __SetOpenCommand, "SetOpenCommand")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "command", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileTypeInfo, __SetOpenCommand)
{
	Object_wx_FileTypeInfo *pThis = Object_wx_FileTypeInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& command = arg.GetNumber(0)
	//pThis->GetEntity()->SetOpenCommand(command);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileTypeInfo, __SetPrintCommand, "SetPrintCommand")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "command", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileTypeInfo, __SetPrintCommand)
{
	Object_wx_FileTypeInfo *pThis = Object_wx_FileTypeInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& command = arg.GetNumber(0)
	//pThis->GetEntity()->SetPrintCommand(command);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileTypeInfo, __SetShortDesc, "SetShortDesc")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "shortDesc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileTypeInfo, __SetShortDesc)
{
	Object_wx_FileTypeInfo *pThis = Object_wx_FileTypeInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& shortDesc = arg.GetNumber(0)
	//pThis->GetEntity()->SetShortDesc(shortDesc);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileTypeInfo, __SetIcon, "SetIcon")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "iconFile", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "iconIndex", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileTypeInfo, __SetIcon)
{
	Object_wx_FileTypeInfo *pThis = Object_wx_FileTypeInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& iconFile = arg.GetNumber(0)
	//int iconIndex = arg.GetNumber(1)
	//pThis->GetEntity()->SetIcon(iconFile, iconIndex);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileTypeInfo, __GetMimeType, "GetMimeType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_FileTypeInfo, __GetMimeType)
{
	Object_wx_FileTypeInfo *pThis = Object_wx_FileTypeInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& _rtn = pThis->GetEntity()->GetMimeType();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileTypeInfo, __GetOpenCommand, "GetOpenCommand")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_FileTypeInfo, __GetOpenCommand)
{
	Object_wx_FileTypeInfo *pThis = Object_wx_FileTypeInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& _rtn = pThis->GetEntity()->GetOpenCommand();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileTypeInfo, __GetPrintCommand, "GetPrintCommand")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_FileTypeInfo, __GetPrintCommand)
{
	Object_wx_FileTypeInfo *pThis = Object_wx_FileTypeInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& _rtn = pThis->GetEntity()->GetPrintCommand();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileTypeInfo, __GetShortDesc, "GetShortDesc")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_FileTypeInfo, __GetShortDesc)
{
	Object_wx_FileTypeInfo *pThis = Object_wx_FileTypeInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& _rtn = pThis->GetEntity()->GetShortDesc();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileTypeInfo, __GetDescription, "GetDescription")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_FileTypeInfo, __GetDescription)
{
	Object_wx_FileTypeInfo *pThis = Object_wx_FileTypeInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& _rtn = pThis->GetEntity()->GetDescription();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileTypeInfo, __GetExtensions, "GetExtensions")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_FileTypeInfo, __GetExtensions)
{
	Object_wx_FileTypeInfo *pThis = Object_wx_FileTypeInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxArrayString& _rtn = pThis->GetEntity()->GetExtensions();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileTypeInfo, __GetExtensionsCount, "GetExtensionsCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_FileTypeInfo, __GetExtensionsCount)
{
	Object_wx_FileTypeInfo *pThis = Object_wx_FileTypeInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t _rtn = pThis->GetEntity()->GetExtensionsCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileTypeInfo, __GetIconFile, "GetIconFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_FileTypeInfo, __GetIconFile)
{
	Object_wx_FileTypeInfo *pThis = Object_wx_FileTypeInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& _rtn = pThis->GetEntity()->GetIconFile();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileTypeInfo, __GetIconIndex, "GetIconIndex")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_FileTypeInfo, __GetIconIndex)
{
	Object_wx_FileTypeInfo *pThis = Object_wx_FileTypeInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetIconIndex();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFileTypeInfo
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileTypeInfo)
{
	// Constructor assignment
	Gura_AssignFunction(__FileTypeInfo);
	Gura_AssignFunction(__FileTypeInfo_1);
	Gura_AssignFunction(__FileTypeInfo_2);
	// Method assignment
	Gura_AssignMethod(wx_FileTypeInfo, __AddExtension);
	Gura_AssignMethod(wx_FileTypeInfo, __SetDescription);
	Gura_AssignMethod(wx_FileTypeInfo, __SetOpenCommand);
	Gura_AssignMethod(wx_FileTypeInfo, __SetPrintCommand);
	Gura_AssignMethod(wx_FileTypeInfo, __SetShortDesc);
	Gura_AssignMethod(wx_FileTypeInfo, __SetIcon);
	Gura_AssignMethod(wx_FileTypeInfo, __GetMimeType);
	Gura_AssignMethod(wx_FileTypeInfo, __GetOpenCommand);
	Gura_AssignMethod(wx_FileTypeInfo, __GetPrintCommand);
	Gura_AssignMethod(wx_FileTypeInfo, __GetShortDesc);
	Gura_AssignMethod(wx_FileTypeInfo, __GetDescription);
	Gura_AssignMethod(wx_FileTypeInfo, __GetExtensions);
	Gura_AssignMethod(wx_FileTypeInfo, __GetExtensionsCount);
	Gura_AssignMethod(wx_FileTypeInfo, __GetIconFile);
	Gura_AssignMethod(wx_FileTypeInfo, __GetIconIndex);
}

Gura_ImplementDescendantCreator(wx_FileTypeInfo)
{
	return new Object_wx_FileTypeInfo((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
