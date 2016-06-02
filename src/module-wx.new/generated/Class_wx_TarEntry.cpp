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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_TarEntry, wxTarEntry)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarEntry, wxTarEntry)
{
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int dt = arg.GetNumber(1)
	//int size = arg.GetNumber(2)
	//pThis->GetEntity()->wxTarEntry();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TarEntry, wxTarEntry_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "entry", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarEntry, wxTarEntry_1)
{
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int entry = arg.GetNumber(0)
	//pThis->GetEntity()->wxTarEntry();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TarEntry, GetAccessTime)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TarEntry, GetAccessTime)
{
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAccessTime();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TarEntry, SetAccessTime)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarEntry, SetAccessTime)
{
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dt = arg.GetNumber(0)
	//pThis->GetEntity()->SetAccessTime();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TarEntry, GetCreateTime)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TarEntry, GetCreateTime)
{
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCreateTime();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TarEntry, SetCreateTime)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarEntry, SetCreateTime)
{
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dt = arg.GetNumber(0)
	//pThis->GetEntity()->SetCreateTime();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TarEntry, GetDevMajor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TarEntry, GetDevMajor)
{
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDevMajor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TarEntry, GetDevMinor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TarEntry, GetDevMinor)
{
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDevMinor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TarEntry, SetDevMajor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dev", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarEntry, SetDevMajor)
{
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dev = arg.GetNumber(0)
	//pThis->GetEntity()->SetDevMajor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TarEntry, SetDevMinor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dev", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarEntry, SetDevMinor)
{
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dev = arg.GetNumber(0)
	//pThis->GetEntity()->SetDevMinor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TarEntry, GetGroupId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TarEntry, GetGroupId)
{
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetGroupId();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TarEntry, GetUserId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TarEntry, GetUserId)
{
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetUserId();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TarEntry, SetGroupId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarEntry, SetGroupId)
{
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->SetGroupId();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TarEntry, SetUserId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarEntry, SetUserId)
{
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->SetUserId();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TarEntry, GetGroupName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TarEntry, GetGroupName)
{
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetGroupName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TarEntry, GetUserName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TarEntry, GetUserName)
{
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetUserName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TarEntry, SetGroupName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "group", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarEntry, SetGroupName)
{
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int group = arg.GetNumber(0)
	//pThis->GetEntity()->SetGroupName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TarEntry, SetUserName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "user", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarEntry, SetUserName)
{
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int user = arg.GetNumber(0)
	//pThis->GetEntity()->SetUserName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TarEntry, GetLinkName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TarEntry, GetLinkName)
{
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLinkName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TarEntry, SetLinkName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "link", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarEntry, SetLinkName)
{
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int link = arg.GetNumber(0)
	//pThis->GetEntity()->SetLinkName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TarEntry, GetMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TarEntry, GetMode)
{
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TarEntry, SetMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarEntry, SetMode)
{
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int mode = arg.GetNumber(0)
	//pThis->GetEntity()->SetMode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TarEntry, SetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarEntry, SetSize)
{
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->SetSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TarEntry, GetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TarEntry, GetSize)
{
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TarEntry, GetTypeFlag)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TarEntry, GetTypeFlag)
{
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTypeFlag();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TarEntry, SetTypeFlag)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarEntry, SetTypeFlag)
{
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int type = arg.GetNumber(0)
	//pThis->GetEntity()->SetTypeFlag();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TarEntry, GetInternalName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TarEntry, GetInternalName)
{
	Object_wx_TarEntry *pThis = Object_wx_TarEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetInternalName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TarEntry, GetInternalName_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pIsDir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarEntry, GetInternalName_1)
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
	Gura_AssignMethod(wx_TarEntry, wxTarEntry);
	Gura_AssignMethod(wx_TarEntry, wxTarEntry_1);
	Gura_AssignMethod(wx_TarEntry, GetAccessTime);
	Gura_AssignMethod(wx_TarEntry, SetAccessTime);
	Gura_AssignMethod(wx_TarEntry, GetCreateTime);
	Gura_AssignMethod(wx_TarEntry, SetCreateTime);
	Gura_AssignMethod(wx_TarEntry, GetDevMajor);
	Gura_AssignMethod(wx_TarEntry, GetDevMinor);
	Gura_AssignMethod(wx_TarEntry, SetDevMajor);
	Gura_AssignMethod(wx_TarEntry, SetDevMinor);
	Gura_AssignMethod(wx_TarEntry, GetGroupId);
	Gura_AssignMethod(wx_TarEntry, GetUserId);
	Gura_AssignMethod(wx_TarEntry, SetGroupId);
	Gura_AssignMethod(wx_TarEntry, SetUserId);
	Gura_AssignMethod(wx_TarEntry, GetGroupName);
	Gura_AssignMethod(wx_TarEntry, GetUserName);
	Gura_AssignMethod(wx_TarEntry, SetGroupName);
	Gura_AssignMethod(wx_TarEntry, SetUserName);
	Gura_AssignMethod(wx_TarEntry, GetLinkName);
	Gura_AssignMethod(wx_TarEntry, SetLinkName);
	Gura_AssignMethod(wx_TarEntry, GetMode);
	Gura_AssignMethod(wx_TarEntry, SetMode);
	Gura_AssignMethod(wx_TarEntry, SetSize);
	Gura_AssignMethod(wx_TarEntry, GetSize);
	Gura_AssignMethod(wx_TarEntry, GetTypeFlag);
	Gura_AssignMethod(wx_TarEntry, SetTypeFlag);
	Gura_AssignMethod(wx_TarEntry, GetInternalName);
	Gura_AssignMethod(wx_TarEntry, GetInternalName_1);
}

Gura_ImplementDescendantCreator(wx_TarEntry)
{
	return new Object_wx_TarEntry((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
