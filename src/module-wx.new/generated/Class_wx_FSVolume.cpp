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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxFSVolume, "wxFSVolume")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_FSVolume));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxFSVolume)
{
	//wxFSVolume();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxFSVolume_1, "wxFSVolume_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_FSVolume));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxFSVolume_1)
{
	//int name = arg.GetNumber(0)
	//wxFSVolume();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_FSVolume, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FSVolume, __Create)
{
	Object_wx_FSVolume *pThis = Object_wx_FSVolume::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FSVolume, __GetVolumes, "GetVolumes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flagsSet", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flagsUnset", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FSVolume, __GetVolumes)
{
	Object_wx_FSVolume *pThis = Object_wx_FSVolume::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flagsSet = arg.GetNumber(0)
	//int flagsUnset = arg.GetNumber(1)
	//pThis->GetEntity()->GetVolumes();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FSVolume, __CancelSearch, "CancelSearch")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FSVolume, __CancelSearch)
{
	Object_wx_FSVolume *pThis = Object_wx_FSVolume::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CancelSearch();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FSVolume, __IsOk, "IsOk")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FSVolume, __IsOk)
{
	Object_wx_FSVolume *pThis = Object_wx_FSVolume::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FSVolume, __GetKind, "GetKind")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FSVolume, __GetKind)
{
	Object_wx_FSVolume *pThis = Object_wx_FSVolume::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetKind();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FSVolume, __GetFlags, "GetFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FSVolume, __GetFlags)
{
	Object_wx_FSVolume *pThis = Object_wx_FSVolume::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFlags();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FSVolume, __IsWritable, "IsWritable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FSVolume, __IsWritable)
{
	Object_wx_FSVolume *pThis = Object_wx_FSVolume::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsWritable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FSVolume, __GetName, "GetName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FSVolume, __GetName)
{
	Object_wx_FSVolume *pThis = Object_wx_FSVolume::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FSVolume, __GetDisplayName, "GetDisplayName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FSVolume, __GetDisplayName)
{
	Object_wx_FSVolume *pThis = Object_wx_FSVolume::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDisplayName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FSVolume, __GetIcon, "GetIcon")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FSVolume, __GetIcon)
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
	// Constructor assignment
	Gura_AssignFunction(__wxFSVolume);
	Gura_AssignFunction(__wxFSVolume_1);
	// Method assignment
	Gura_AssignMethod(wx_FSVolume, __Create);
	Gura_AssignMethod(wx_FSVolume, __GetVolumes);
	Gura_AssignMethod(wx_FSVolume, __CancelSearch);
	Gura_AssignMethod(wx_FSVolume, __IsOk);
	Gura_AssignMethod(wx_FSVolume, __GetKind);
	Gura_AssignMethod(wx_FSVolume, __GetFlags);
	Gura_AssignMethod(wx_FSVolume, __IsWritable);
	Gura_AssignMethod(wx_FSVolume, __GetName);
	Gura_AssignMethod(wx_FSVolume, __GetDisplayName);
	Gura_AssignMethod(wx_FSVolume, __GetIcon);
}

Gura_ImplementDescendantCreator(wx_FSVolume)
{
	return new Object_wx_FSVolume((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
