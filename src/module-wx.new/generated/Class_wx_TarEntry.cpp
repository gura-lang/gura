//----------------------------------------------------------------------------
// wxTarEntry
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTarEntry
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTarEntry
//----------------------------------------------------------------------------
Object_wx_TarEntry::~Object_wx_TarEntry()
{
}

Object *Object_wx_TarEntry::Clone() const
{
	return nullptr;
}

String Object_wx_TarEntry::ToString(bool exprFlag)
{
	String rtn("<wx.TarEntry:");
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
Gura_DeclareFunctionAlias(__wxTarEntry, "wxTarEntry")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_TarEntry));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxTarEntry)
{
	//int name = arg.GetNumber(0)
	//int dt = arg.GetNumber(1)
	//int size = arg.GetNumber(2)
	//wxTarEntry();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxTarEntry_1, "wxTarEntry_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "entry", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_TarEntry));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxTarEntry_1)
{
	//int entry = arg.GetNumber(0)
	//wxTarEntry();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_TarEntry, __GetAccessTime, "GetAccessTime")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TarEntry, __GetAccessTime)
{
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAccessTime();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TarEntry, __SetAccessTime, "SetAccessTime")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarEntry, __SetAccessTime)
{
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dt = arg.GetNumber(0)
	//pThis->GetEntity()->SetAccessTime();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TarEntry, __GetCreateTime, "GetCreateTime")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TarEntry, __GetCreateTime)
{
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCreateTime();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TarEntry, __SetCreateTime, "SetCreateTime")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarEntry, __SetCreateTime)
{
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dt = arg.GetNumber(0)
	//pThis->GetEntity()->SetCreateTime();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TarEntry, __GetDevMajor, "GetDevMajor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TarEntry, __GetDevMajor)
{
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDevMajor();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TarEntry, __GetDevMinor, "GetDevMinor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TarEntry, __GetDevMinor)
{
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDevMinor();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TarEntry, __SetDevMajor, "SetDevMajor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dev", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarEntry, __SetDevMajor)
{
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dev = arg.GetNumber(0)
	//pThis->GetEntity()->SetDevMajor();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TarEntry, __SetDevMinor, "SetDevMinor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dev", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarEntry, __SetDevMinor)
{
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dev = arg.GetNumber(0)
	//pThis->GetEntity()->SetDevMinor();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TarEntry, __GetGroupId, "GetGroupId")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TarEntry, __GetGroupId)
{
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetGroupId();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TarEntry, __GetUserId, "GetUserId")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TarEntry, __GetUserId)
{
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetUserId();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TarEntry, __SetGroupId, "SetGroupId")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarEntry, __SetGroupId)
{
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->SetGroupId();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TarEntry, __SetUserId, "SetUserId")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarEntry, __SetUserId)
{
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->SetUserId();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TarEntry, __GetGroupName, "GetGroupName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TarEntry, __GetGroupName)
{
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetGroupName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TarEntry, __GetUserName, "GetUserName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TarEntry, __GetUserName)
{
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetUserName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TarEntry, __SetGroupName, "SetGroupName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "group", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarEntry, __SetGroupName)
{
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int group = arg.GetNumber(0)
	//pThis->GetEntity()->SetGroupName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TarEntry, __SetUserName, "SetUserName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "user", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarEntry, __SetUserName)
{
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int user = arg.GetNumber(0)
	//pThis->GetEntity()->SetUserName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TarEntry, __GetLinkName, "GetLinkName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TarEntry, __GetLinkName)
{
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLinkName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TarEntry, __SetLinkName, "SetLinkName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "link", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarEntry, __SetLinkName)
{
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int link = arg.GetNumber(0)
	//pThis->GetEntity()->SetLinkName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TarEntry, __GetMode, "GetMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TarEntry, __GetMode)
{
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TarEntry, __SetMode, "SetMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarEntry, __SetMode)
{
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int mode = arg.GetNumber(0)
	//pThis->GetEntity()->SetMode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TarEntry, __SetSize, "SetSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarEntry, __SetSize)
{
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->SetSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TarEntry, __GetSize, "GetSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TarEntry, __GetSize)
{
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TarEntry, __GetTypeFlag, "GetTypeFlag")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TarEntry, __GetTypeFlag)
{
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTypeFlag();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TarEntry, __SetTypeFlag, "SetTypeFlag")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarEntry, __SetTypeFlag)
{
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int type = arg.GetNumber(0)
	//pThis->GetEntity()->SetTypeFlag();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TarEntry, __GetInternalName, "GetInternalName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TarEntry, __GetInternalName)
{
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetInternalName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TarEntry, __GetInternalName_1, "GetInternalName_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pIsDir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarEntry, __GetInternalName_1)
{
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int format = arg.GetNumber(1)
	//int pIsDir = arg.GetNumber(2)
	//pThis->GetEntity()->GetInternalName();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTarEntry
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TarEntry)
{
	// Constructor assignment
	Gura_AssignFunction(__wxTarEntry);
	Gura_AssignFunction(__wxTarEntry_1);
	// Method assignment
	Gura_AssignMethod(wx_TarEntry, __GetAccessTime);
	Gura_AssignMethod(wx_TarEntry, __SetAccessTime);
	Gura_AssignMethod(wx_TarEntry, __GetCreateTime);
	Gura_AssignMethod(wx_TarEntry, __SetCreateTime);
	Gura_AssignMethod(wx_TarEntry, __GetDevMajor);
	Gura_AssignMethod(wx_TarEntry, __GetDevMinor);
	Gura_AssignMethod(wx_TarEntry, __SetDevMajor);
	Gura_AssignMethod(wx_TarEntry, __SetDevMinor);
	Gura_AssignMethod(wx_TarEntry, __GetGroupId);
	Gura_AssignMethod(wx_TarEntry, __GetUserId);
	Gura_AssignMethod(wx_TarEntry, __SetGroupId);
	Gura_AssignMethod(wx_TarEntry, __SetUserId);
	Gura_AssignMethod(wx_TarEntry, __GetGroupName);
	Gura_AssignMethod(wx_TarEntry, __GetUserName);
	Gura_AssignMethod(wx_TarEntry, __SetGroupName);
	Gura_AssignMethod(wx_TarEntry, __SetUserName);
	Gura_AssignMethod(wx_TarEntry, __GetLinkName);
	Gura_AssignMethod(wx_TarEntry, __SetLinkName);
	Gura_AssignMethod(wx_TarEntry, __GetMode);
	Gura_AssignMethod(wx_TarEntry, __SetMode);
	Gura_AssignMethod(wx_TarEntry, __SetSize);
	Gura_AssignMethod(wx_TarEntry, __GetSize);
	Gura_AssignMethod(wx_TarEntry, __GetTypeFlag);
	Gura_AssignMethod(wx_TarEntry, __SetTypeFlag);
	Gura_AssignMethod(wx_TarEntry, __GetInternalName);
	Gura_AssignMethod(wx_TarEntry, __GetInternalName_1);
}

Gura_ImplementDescendantCreator(wx_TarEntry)
{
	return new Object_wx_TarEntry((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
