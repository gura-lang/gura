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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_FileTypeInfo, wxFileTypeInfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileTypeInfo, wxFileTypeInfo)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileTypeInfo *pThis = Object_wx_FileTypeInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxFileTypeInfo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileTypeInfo, wxFileTypeInfo_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mimeType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileTypeInfo, wxFileTypeInfo_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileTypeInfo *pThis = Object_wx_FileTypeInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int mimeType = arg.GetNumber(0)
	//pThis->GetEntity()->wxFileTypeInfo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileTypeInfo, wxFileTypeInfo_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mimeType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "openCmd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "printCmd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "description", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "extension", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileTypeInfo, wxFileTypeInfo_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileTypeInfo *pThis = Object_wx_FileTypeInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int mimeType = arg.GetNumber(0)
	//int openCmd = arg.GetNumber(1)
	//int printCmd = arg.GetNumber(2)
	//int description = arg.GetNumber(3)
	//int extension = arg.GetNumber(4)
	//pThis->GetEntity()->wxFileTypeInfo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileTypeInfo, wxFileTypeInfo_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sArray", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileTypeInfo, wxFileTypeInfo_3)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileTypeInfo *pThis = Object_wx_FileTypeInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int sArray = arg.GetNumber(0)
	//pThis->GetEntity()->wxFileTypeInfo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileTypeInfo, AddExtension)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ext", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileTypeInfo, AddExtension)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileTypeInfo *pThis = Object_wx_FileTypeInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int ext = arg.GetNumber(0)
	//pThis->GetEntity()->AddExtension();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileTypeInfo, SetDescription)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "description", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileTypeInfo, SetDescription)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileTypeInfo *pThis = Object_wx_FileTypeInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int description = arg.GetNumber(0)
	//pThis->GetEntity()->SetDescription();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileTypeInfo, SetOpenCommand)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "command", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileTypeInfo, SetOpenCommand)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileTypeInfo *pThis = Object_wx_FileTypeInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int command = arg.GetNumber(0)
	//pThis->GetEntity()->SetOpenCommand();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileTypeInfo, SetPrintCommand)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "command", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileTypeInfo, SetPrintCommand)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileTypeInfo *pThis = Object_wx_FileTypeInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int command = arg.GetNumber(0)
	//pThis->GetEntity()->SetPrintCommand();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileTypeInfo, SetShortDesc)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "shortDesc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileTypeInfo, SetShortDesc)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileTypeInfo *pThis = Object_wx_FileTypeInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int shortDesc = arg.GetNumber(0)
	//pThis->GetEntity()->SetShortDesc();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileTypeInfo, SetIcon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "iconFile", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "iconIndex", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileTypeInfo, SetIcon)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileTypeInfo *pThis = Object_wx_FileTypeInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int iconFile = arg.GetNumber(0)
	//int iconIndex = arg.GetNumber(1)
	//pThis->GetEntity()->SetIcon();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileTypeInfo, GetMimeType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileTypeInfo, GetMimeType)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileTypeInfo *pThis = Object_wx_FileTypeInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetMimeType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileTypeInfo, GetOpenCommand)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileTypeInfo, GetOpenCommand)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileTypeInfo *pThis = Object_wx_FileTypeInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetOpenCommand();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileTypeInfo, GetPrintCommand)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileTypeInfo, GetPrintCommand)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileTypeInfo *pThis = Object_wx_FileTypeInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPrintCommand();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileTypeInfo, GetShortDesc)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileTypeInfo, GetShortDesc)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileTypeInfo *pThis = Object_wx_FileTypeInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetShortDesc();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileTypeInfo, GetDescription)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileTypeInfo, GetDescription)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileTypeInfo *pThis = Object_wx_FileTypeInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetDescription();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileTypeInfo, GetExtensions)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileTypeInfo, GetExtensions)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileTypeInfo *pThis = Object_wx_FileTypeInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetExtensions();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileTypeInfo, GetExtensionsCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileTypeInfo, GetExtensionsCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileTypeInfo *pThis = Object_wx_FileTypeInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetExtensionsCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileTypeInfo, GetIconFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileTypeInfo, GetIconFile)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileTypeInfo *pThis = Object_wx_FileTypeInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetIconFile();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileTypeInfo, GetIconIndex)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileTypeInfo, GetIconIndex)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileTypeInfo *pThis = Object_wx_FileTypeInfo::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetIconIndex();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFileTypeInfo
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileTypeInfo)
{
	Gura_AssignMethod(wx_FileTypeInfo, wxFileTypeInfo);
	Gura_AssignMethod(wx_FileTypeInfo, wxFileTypeInfo_1);
	Gura_AssignMethod(wx_FileTypeInfo, wxFileTypeInfo_2);
	Gura_AssignMethod(wx_FileTypeInfo, wxFileTypeInfo_3);
	Gura_AssignMethod(wx_FileTypeInfo, AddExtension);
	Gura_AssignMethod(wx_FileTypeInfo, SetDescription);
	Gura_AssignMethod(wx_FileTypeInfo, SetOpenCommand);
	Gura_AssignMethod(wx_FileTypeInfo, SetPrintCommand);
	Gura_AssignMethod(wx_FileTypeInfo, SetShortDesc);
	Gura_AssignMethod(wx_FileTypeInfo, SetIcon);
	Gura_AssignMethod(wx_FileTypeInfo, GetMimeType);
	Gura_AssignMethod(wx_FileTypeInfo, GetOpenCommand);
	Gura_AssignMethod(wx_FileTypeInfo, GetPrintCommand);
	Gura_AssignMethod(wx_FileTypeInfo, GetShortDesc);
	Gura_AssignMethod(wx_FileTypeInfo, GetDescription);
	Gura_AssignMethod(wx_FileTypeInfo, GetExtensions);
	Gura_AssignMethod(wx_FileTypeInfo, GetExtensionsCount);
	Gura_AssignMethod(wx_FileTypeInfo, GetIconFile);
	Gura_AssignMethod(wx_FileTypeInfo, GetIconIndex);
}

Gura_ImplementDescendantCreator(wx_FileTypeInfo)
{
	return new Object_wx_FileTypeInfo((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
