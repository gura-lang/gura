//----------------------------------------------------------------------------
// wxArchiveNotifier
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxArchiveNotifier
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxArchiveNotifier
//----------------------------------------------------------------------------
Object_wx_ArchiveNotifier::~Object_wx_ArchiveNotifier()
{
}

Object *Object_wx_ArchiveNotifier::Clone() const
{
	return nullptr;
}

String Object_wx_ArchiveNotifier::ToString(bool exprFlag)
{
	String rtn("<wx.ArchiveNotifier:");
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
Gura_DeclareMethod(wx_ArchiveNotifier, OnEntryUpdated)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "entry", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArchiveNotifier, OnEntryUpdated)
{
	Object_wx_ArchiveNotifier *pThis = Object_wx_ArchiveNotifier::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int entry = arg.GetNumber(0)
	//pThis->GetEntity()->OnEntryUpdated();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxArchiveNotifier
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ArchiveNotifier)
{
	Gura_AssignMethod(wx_ArchiveNotifier, OnEntryUpdated);
}

Gura_ImplementDescendantCreator(wx_ArchiveNotifier)
{
	return new Object_wx_ArchiveNotifier((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
