//----------------------------------------------------------------------------
// wxZipEntry
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxZipEntry
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxZipEntry
//----------------------------------------------------------------------------
Object_wx_ZipEntry::~Object_wx_ZipEntry()
{
}

Object *Object_wx_ZipEntry::Clone() const
{
	return nullptr;
}

String Object_wx_ZipEntry::ToString(bool exprFlag)
{
	String rtn("<wx.ZipEntry:");
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
Gura_DeclareMethod(wx_ZipEntry, wxZipEntry)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ZipEntry, wxZipEntry)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int dt = arg.GetNumber(1)
	//int size = arg.GetNumber(2)
	//pThis->GetEntity()->wxZipEntry();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ZipEntry, wxZipEntry_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "entry", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ZipEntry, wxZipEntry_1)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int entry = arg.GetNumber(0)
	//pThis->GetEntity()->wxZipEntry();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ZipEntry, Clone)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ZipEntry, Clone)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clone();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ZipEntry, GetComment)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ZipEntry, GetComment)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetComment();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ZipEntry, SetComment)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "comment", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ZipEntry, SetComment)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int comment = arg.GetNumber(0)
	//pThis->GetEntity()->SetComment();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ZipEntry, GetExternalAttributes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ZipEntry, GetExternalAttributes)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetExternalAttributes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ZipEntry, SetExternalAttributes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ZipEntry, SetExternalAttributes)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int attr = arg.GetNumber(0)
	//pThis->GetEntity()->SetExternalAttributes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ZipEntry, GetExtra)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ZipEntry, GetExtra)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetExtra();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ZipEntry, GetExtraLen)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ZipEntry, GetExtraLen)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetExtraLen();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ZipEntry, SetExtra)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "extra", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ZipEntry, SetExtra)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int extra = arg.GetNumber(0)
	//int len = arg.GetNumber(1)
	//pThis->GetEntity()->SetExtra();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ZipEntry, GetLocalExtra)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ZipEntry, GetLocalExtra)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLocalExtra();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ZipEntry, GetLocalExtraLen)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ZipEntry, GetLocalExtraLen)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLocalExtraLen();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ZipEntry, SetLocalExtra)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "extra", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ZipEntry, SetLocalExtra)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int extra = arg.GetNumber(0)
	//int len = arg.GetNumber(1)
	//pThis->GetEntity()->SetLocalExtra();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ZipEntry, GetMethod)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ZipEntry, GetMethod)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMethod();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ZipEntry, SetMethod)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "method", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ZipEntry, SetMethod)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int method = arg.GetNumber(0)
	//pThis->GetEntity()->SetMethod();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ZipEntry, GetMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ZipEntry, GetMode)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ZipEntry, SetMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ZipEntry, SetMode)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int mode = arg.GetNumber(0)
	//pThis->GetEntity()->SetMode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ZipEntry, GetSystemMadeBy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ZipEntry, GetSystemMadeBy)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSystemMadeBy();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ZipEntry, SetSystemMadeBy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "system", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ZipEntry, SetSystemMadeBy)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int system = arg.GetNumber(0)
	//pThis->GetEntity()->SetSystemMadeBy();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ZipEntry, GetCompressedSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ZipEntry, GetCompressedSize)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCompressedSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ZipEntry, GetCrc)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ZipEntry, GetCrc)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCrc();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ZipEntry, GetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ZipEntry, GetFlags)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ZipEntry, GetInternalName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pIsDir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ZipEntry, GetInternalName)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int format = arg.GetNumber(1)
	//int pIsDir = arg.GetNumber(2)
	//pThis->GetEntity()->GetInternalName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ZipEntry, GetInternalName_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ZipEntry, GetInternalName_1)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetInternalName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ZipEntry, IsMadeByUnix)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ZipEntry, IsMadeByUnix)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsMadeByUnix();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ZipEntry, IsText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ZipEntry, IsText)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ZipEntry, SetIsText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "isText", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ZipEntry, SetIsText)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int isText = arg.GetNumber(0)
	//pThis->GetEntity()->SetIsText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ZipEntry, SetNotifier)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "notifier", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ZipEntry, SetNotifier)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int notifier = arg.GetNumber(0)
	//pThis->GetEntity()->SetNotifier();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ZipEntry, UnsetNotifier)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ZipEntry, UnsetNotifier)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->UnsetNotifier();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxZipEntry
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ZipEntry)
{
	Gura_AssignMethod(wx_ZipEntry, wxZipEntry);
	Gura_AssignMethod(wx_ZipEntry, wxZipEntry_1);
	Gura_AssignMethod(wx_ZipEntry, Clone);
	Gura_AssignMethod(wx_ZipEntry, GetComment);
	Gura_AssignMethod(wx_ZipEntry, SetComment);
	Gura_AssignMethod(wx_ZipEntry, GetExternalAttributes);
	Gura_AssignMethod(wx_ZipEntry, SetExternalAttributes);
	Gura_AssignMethod(wx_ZipEntry, GetExtra);
	Gura_AssignMethod(wx_ZipEntry, GetExtraLen);
	Gura_AssignMethod(wx_ZipEntry, SetExtra);
	Gura_AssignMethod(wx_ZipEntry, GetLocalExtra);
	Gura_AssignMethod(wx_ZipEntry, GetLocalExtraLen);
	Gura_AssignMethod(wx_ZipEntry, SetLocalExtra);
	Gura_AssignMethod(wx_ZipEntry, GetMethod);
	Gura_AssignMethod(wx_ZipEntry, SetMethod);
	Gura_AssignMethod(wx_ZipEntry, GetMode);
	Gura_AssignMethod(wx_ZipEntry, SetMode);
	Gura_AssignMethod(wx_ZipEntry, GetSystemMadeBy);
	Gura_AssignMethod(wx_ZipEntry, SetSystemMadeBy);
	Gura_AssignMethod(wx_ZipEntry, GetCompressedSize);
	Gura_AssignMethod(wx_ZipEntry, GetCrc);
	Gura_AssignMethod(wx_ZipEntry, GetFlags);
	Gura_AssignMethod(wx_ZipEntry, GetInternalName);
	Gura_AssignMethod(wx_ZipEntry, GetInternalName_1);
	Gura_AssignMethod(wx_ZipEntry, IsMadeByUnix);
	Gura_AssignMethod(wx_ZipEntry, IsText);
	Gura_AssignMethod(wx_ZipEntry, SetIsText);
	Gura_AssignMethod(wx_ZipEntry, SetNotifier);
	Gura_AssignMethod(wx_ZipEntry, UnsetNotifier);
}

Gura_ImplementDescendantCreator(wx_ZipEntry)
{
	return new Object_wx_ZipEntry((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
