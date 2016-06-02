//----------------------------------------------------------------------------
// wxFSVolume
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFSVolume
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFSVolume
//----------------------------------------------------------------------------
Object_wx_FSVolume::~Object_wx_FSVolume()
{
}

Object *Object_wx_FSVolume::Clone() const
{
	return nullptr;
}

String Object_wx_FSVolume::ToString(bool exprFlag)
{
	String rtn("<wx.FSVolume:");
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
Gura_DeclareMethod(wx_FSVolume, wxFSVolume)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FSVolume, wxFSVolume)
{
	Object_wx_FSVolume *pThis = Object_wx_FSVolume::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxFSVolume();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FSVolume, wxFSVolume_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FSVolume, wxFSVolume_1)
{
	Object_wx_FSVolume *pThis = Object_wx_FSVolume::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->wxFSVolume();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FSVolume, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FSVolume, Create)
{
	Object_wx_FSVolume *pThis = Object_wx_FSVolume::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FSVolume, GetVolumes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flagsSet", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flagsUnset", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FSVolume, GetVolumes)
{
	Object_wx_FSVolume *pThis = Object_wx_FSVolume::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flagsSet = arg.GetNumber(0)
	//int flagsUnset = arg.GetNumber(1)
	//pThis->GetEntity()->GetVolumes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FSVolume, CancelSearch)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FSVolume, CancelSearch)
{
	Object_wx_FSVolume *pThis = Object_wx_FSVolume::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CancelSearch();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FSVolume, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FSVolume, IsOk)
{
	Object_wx_FSVolume *pThis = Object_wx_FSVolume::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FSVolume, GetKind)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FSVolume, GetKind)
{
	Object_wx_FSVolume *pThis = Object_wx_FSVolume::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetKind();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FSVolume, GetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FSVolume, GetFlags)
{
	Object_wx_FSVolume *pThis = Object_wx_FSVolume::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FSVolume, IsWritable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FSVolume, IsWritable)
{
	Object_wx_FSVolume *pThis = Object_wx_FSVolume::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsWritable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FSVolume, GetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FSVolume, GetName)
{
	Object_wx_FSVolume *pThis = Object_wx_FSVolume::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FSVolume, GetDisplayName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FSVolume, GetDisplayName)
{
	Object_wx_FSVolume *pThis = Object_wx_FSVolume::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDisplayName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FSVolume, GetIcon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FSVolume, GetIcon)
{
	Object_wx_FSVolume *pThis = Object_wx_FSVolume::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int type = arg.GetNumber(0)
	//pThis->GetEntity()->GetIcon();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFSVolume
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FSVolume)
{
	Gura_AssignMethod(wx_FSVolume, wxFSVolume);
	Gura_AssignMethod(wx_FSVolume, wxFSVolume_1);
	Gura_AssignMethod(wx_FSVolume, Create);
	Gura_AssignMethod(wx_FSVolume, GetVolumes);
	Gura_AssignMethod(wx_FSVolume, CancelSearch);
	Gura_AssignMethod(wx_FSVolume, IsOk);
	Gura_AssignMethod(wx_FSVolume, GetKind);
	Gura_AssignMethod(wx_FSVolume, GetFlags);
	Gura_AssignMethod(wx_FSVolume, IsWritable);
	Gura_AssignMethod(wx_FSVolume, GetName);
	Gura_AssignMethod(wx_FSVolume, GetDisplayName);
	Gura_AssignMethod(wx_FSVolume, GetIcon);
}

Gura_ImplementDescendantCreator(wx_FSVolume)
{
	return new Object_wx_FSVolume((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
