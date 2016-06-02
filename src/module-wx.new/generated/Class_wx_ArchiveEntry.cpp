//----------------------------------------------------------------------------
// wxArchiveEntry
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxArchiveEntry
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxArchiveEntry
//----------------------------------------------------------------------------
Object_wx_ArchiveEntry::~Object_wx_ArchiveEntry()
{
}

Object *Object_wx_ArchiveEntry::Clone() const
{
	return nullptr;
}

String Object_wx_ArchiveEntry::ToString(bool exprFlag)
{
	String rtn("<wx.ArchiveEntry:");
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
Gura_DeclareMethod(wx_ArchiveEntry, Clone)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ArchiveEntry, Clone)
{
	Object_wx_ArchiveEntry *pThis = Object_wx_ArchiveEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clone();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArchiveEntry, GetDateTime)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ArchiveEntry, GetDateTime)
{
	Object_wx_ArchiveEntry *pThis = Object_wx_ArchiveEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDateTime();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArchiveEntry, SetDateTime)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArchiveEntry, SetDateTime)
{
	Object_wx_ArchiveEntry *pThis = Object_wx_ArchiveEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dt = arg.GetNumber(0)
	//pThis->GetEntity()->SetDateTime();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArchiveEntry, GetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArchiveEntry, GetName)
{
	Object_wx_ArchiveEntry *pThis = Object_wx_ArchiveEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int format = arg.GetNumber(0)
	//pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArchiveEntry, SetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArchiveEntry, SetName)
{
	Object_wx_ArchiveEntry *pThis = Object_wx_ArchiveEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int format = arg.GetNumber(1)
	//pThis->GetEntity()->SetName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArchiveEntry, GetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ArchiveEntry, GetSize)
{
	Object_wx_ArchiveEntry *pThis = Object_wx_ArchiveEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArchiveEntry, SetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArchiveEntry, SetSize)
{
	Object_wx_ArchiveEntry *pThis = Object_wx_ArchiveEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->SetSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArchiveEntry, GetInternalFormat)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ArchiveEntry, GetInternalFormat)
{
	Object_wx_ArchiveEntry *pThis = Object_wx_ArchiveEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetInternalFormat();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArchiveEntry, GetInternalName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ArchiveEntry, GetInternalName)
{
	Object_wx_ArchiveEntry *pThis = Object_wx_ArchiveEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetInternalName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArchiveEntry, GetOffset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ArchiveEntry, GetOffset)
{
	Object_wx_ArchiveEntry *pThis = Object_wx_ArchiveEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOffset();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArchiveEntry, IsDir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ArchiveEntry, IsDir)
{
	Object_wx_ArchiveEntry *pThis = Object_wx_ArchiveEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsDir();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArchiveEntry, SetIsDir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "isDir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArchiveEntry, SetIsDir)
{
	Object_wx_ArchiveEntry *pThis = Object_wx_ArchiveEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int isDir = arg.GetNumber(0)
	//pThis->GetEntity()->SetIsDir();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArchiveEntry, IsReadOnly)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ArchiveEntry, IsReadOnly)
{
	Object_wx_ArchiveEntry *pThis = Object_wx_ArchiveEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsReadOnly();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArchiveEntry, SetIsReadOnly)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "isReadOnly", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArchiveEntry, SetIsReadOnly)
{
	Object_wx_ArchiveEntry *pThis = Object_wx_ArchiveEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int isReadOnly = arg.GetNumber(0)
	//pThis->GetEntity()->SetIsReadOnly();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArchiveEntry, SetNotifier)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "notifier", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArchiveEntry, SetNotifier)
{
	Object_wx_ArchiveEntry *pThis = Object_wx_ArchiveEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int notifier = arg.GetNumber(0)
	//pThis->GetEntity()->SetNotifier();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ArchiveEntry, UnsetNotifier)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ArchiveEntry, UnsetNotifier)
{
	Object_wx_ArchiveEntry *pThis = Object_wx_ArchiveEntry::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->UnsetNotifier();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxArchiveEntry
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ArchiveEntry)
{
	Gura_AssignMethod(wx_ArchiveEntry, Clone);
	Gura_AssignMethod(wx_ArchiveEntry, GetDateTime);
	Gura_AssignMethod(wx_ArchiveEntry, SetDateTime);
	Gura_AssignMethod(wx_ArchiveEntry, GetName);
	Gura_AssignMethod(wx_ArchiveEntry, SetName);
	Gura_AssignMethod(wx_ArchiveEntry, GetSize);
	Gura_AssignMethod(wx_ArchiveEntry, SetSize);
	Gura_AssignMethod(wx_ArchiveEntry, GetInternalFormat);
	Gura_AssignMethod(wx_ArchiveEntry, GetInternalName);
	Gura_AssignMethod(wx_ArchiveEntry, GetOffset);
	Gura_AssignMethod(wx_ArchiveEntry, IsDir);
	Gura_AssignMethod(wx_ArchiveEntry, SetIsDir);
	Gura_AssignMethod(wx_ArchiveEntry, IsReadOnly);
	Gura_AssignMethod(wx_ArchiveEntry, SetIsReadOnly);
	Gura_AssignMethod(wx_ArchiveEntry, SetNotifier);
	Gura_AssignMethod(wx_ArchiveEntry, UnsetNotifier);
}

Gura_ImplementDescendantCreator(wx_ArchiveEntry)
{
	return new Object_wx_ArchiveEntry((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
