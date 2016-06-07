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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__ZipEntry, "ZipEntry")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_ZipEntry));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__ZipEntry)
{
	//const wxString& name = arg.GetNumber(0)
	//const wxDateTime& dt = arg.GetNumber(1)
	//wxFileOffset size = arg.GetNumber(2)
	//wxZipEntry(name, dt, size);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__ZipEntry_1, "ZipEntry_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "entry", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_ZipEntry));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__ZipEntry_1)
{
	//const wxZipEntry& entry = arg.GetNumber(0)
	//wxZipEntry(entry);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_ZipEntry, __Clone, "Clone")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ZipEntry, __Clone)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clone();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ZipEntry, __GetComment, "GetComment")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ZipEntry, __GetComment)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetComment();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ZipEntry, __SetComment, "SetComment")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "comment", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ZipEntry, __SetComment)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& comment = arg.GetNumber(0)
	//pThis->GetEntity()->SetComment(comment);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ZipEntry, __GetExternalAttributes, "GetExternalAttributes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ZipEntry, __GetExternalAttributes)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetExternalAttributes();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ZipEntry, __SetExternalAttributes, "SetExternalAttributes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ZipEntry, __SetExternalAttributes)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxUint32 attr = arg.GetNumber(0)
	//pThis->GetEntity()->SetExternalAttributes(attr);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ZipEntry, __GetExtra, "GetExtra")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ZipEntry, __GetExtra)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetExtra();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ZipEntry, __GetExtraLen, "GetExtraLen")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ZipEntry, __GetExtraLen)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetExtraLen();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ZipEntry, __SetExtra, "SetExtra")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "extra", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ZipEntry, __SetExtra)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const char* extra = arg.GetNumber(0)
	//size_t len = arg.GetNumber(1)
	//pThis->GetEntity()->SetExtra(extra, len);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ZipEntry, __GetLocalExtra, "GetLocalExtra")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ZipEntry, __GetLocalExtra)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLocalExtra();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ZipEntry, __GetLocalExtraLen, "GetLocalExtraLen")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ZipEntry, __GetLocalExtraLen)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLocalExtraLen();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ZipEntry, __SetLocalExtra, "SetLocalExtra")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "extra", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ZipEntry, __SetLocalExtra)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const char* extra = arg.GetNumber(0)
	//size_t len = arg.GetNumber(1)
	//pThis->GetEntity()->SetLocalExtra(extra, len);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ZipEntry, __GetMethod, "GetMethod")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ZipEntry, __GetMethod)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMethod();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ZipEntry, __SetMethod, "SetMethod")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "method", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ZipEntry, __SetMethod)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int method = arg.GetNumber(0)
	//pThis->GetEntity()->SetMethod(method);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ZipEntry, __GetMode, "GetMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ZipEntry, __GetMode)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ZipEntry, __SetMode, "SetMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ZipEntry, __SetMode)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int mode = arg.GetNumber(0)
	//pThis->GetEntity()->SetMode(mode);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ZipEntry, __GetSystemMadeBy, "GetSystemMadeBy")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ZipEntry, __GetSystemMadeBy)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSystemMadeBy();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ZipEntry, __SetSystemMadeBy, "SetSystemMadeBy")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "system", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ZipEntry, __SetSystemMadeBy)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int system = arg.GetNumber(0)
	//pThis->GetEntity()->SetSystemMadeBy(system);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ZipEntry, __GetCompressedSize, "GetCompressedSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ZipEntry, __GetCompressedSize)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCompressedSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ZipEntry, __GetCrc, "GetCrc")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ZipEntry, __GetCrc)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCrc();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ZipEntry, __GetFlags, "GetFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ZipEntry, __GetFlags)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFlags();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ZipEntry, __GetInternalName, "GetInternalName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pIsDir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ZipEntry, __GetInternalName)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//wxPathFormat format = arg.GetNumber(1)
	//bool* pIsDir = arg.GetNumber(2)
	//pThis->GetEntity()->GetInternalName(name, format, pIsDir);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ZipEntry, __GetInternalName_1, "GetInternalName_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ZipEntry, __GetInternalName_1)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetInternalName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ZipEntry, __IsMadeByUnix, "IsMadeByUnix")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ZipEntry, __IsMadeByUnix)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsMadeByUnix();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ZipEntry, __IsText, "IsText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ZipEntry, __IsText)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ZipEntry, __SetIsText, "SetIsText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "isText", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ZipEntry, __SetIsText)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool isText = arg.GetNumber(0)
	//pThis->GetEntity()->SetIsText(isText);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ZipEntry, __SetNotifier, "SetNotifier")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "notifier", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ZipEntry, __SetNotifier)
{
	Object_wx_ZipEntry *pThis = Object_wx_ZipEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxZipNotifier& notifier = arg.GetNumber(0)
	//pThis->GetEntity()->SetNotifier(notifier);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ZipEntry, __UnsetNotifier, "UnsetNotifier")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ZipEntry, __UnsetNotifier)
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
	// Constructor assignment
	Gura_AssignFunction(__ZipEntry);
	Gura_AssignFunction(__ZipEntry_1);
	// Method assignment
	Gura_AssignMethod(wx_ZipEntry, __Clone);
	Gura_AssignMethod(wx_ZipEntry, __GetComment);
	Gura_AssignMethod(wx_ZipEntry, __SetComment);
	Gura_AssignMethod(wx_ZipEntry, __GetExternalAttributes);
	Gura_AssignMethod(wx_ZipEntry, __SetExternalAttributes);
	Gura_AssignMethod(wx_ZipEntry, __GetExtra);
	Gura_AssignMethod(wx_ZipEntry, __GetExtraLen);
	Gura_AssignMethod(wx_ZipEntry, __SetExtra);
	Gura_AssignMethod(wx_ZipEntry, __GetLocalExtra);
	Gura_AssignMethod(wx_ZipEntry, __GetLocalExtraLen);
	Gura_AssignMethod(wx_ZipEntry, __SetLocalExtra);
	Gura_AssignMethod(wx_ZipEntry, __GetMethod);
	Gura_AssignMethod(wx_ZipEntry, __SetMethod);
	Gura_AssignMethod(wx_ZipEntry, __GetMode);
	Gura_AssignMethod(wx_ZipEntry, __SetMode);
	Gura_AssignMethod(wx_ZipEntry, __GetSystemMadeBy);
	Gura_AssignMethod(wx_ZipEntry, __SetSystemMadeBy);
	Gura_AssignMethod(wx_ZipEntry, __GetCompressedSize);
	Gura_AssignMethod(wx_ZipEntry, __GetCrc);
	Gura_AssignMethod(wx_ZipEntry, __GetFlags);
	Gura_AssignMethod(wx_ZipEntry, __GetInternalName);
	Gura_AssignMethod(wx_ZipEntry, __GetInternalName_1);
	Gura_AssignMethod(wx_ZipEntry, __IsMadeByUnix);
	Gura_AssignMethod(wx_ZipEntry, __IsText);
	Gura_AssignMethod(wx_ZipEntry, __SetIsText);
	Gura_AssignMethod(wx_ZipEntry, __SetNotifier);
	Gura_AssignMethod(wx_ZipEntry, __UnsetNotifier);
}

Gura_ImplementDescendantCreator(wx_ZipEntry)
{
	return new Object_wx_ZipEntry((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
