//----------------------------------------------------------------------------
// wxZipNotifier
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxZipNotifier
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxZipNotifier
//----------------------------------------------------------------------------
Object_wx_ZipNotifier::~Object_wx_ZipNotifier()
{
}

Object *Object_wx_ZipNotifier::Clone() const
{
	return nullptr;
}

String Object_wx_ZipNotifier::ToString(bool exprFlag)
{
	String rtn("<wx.ZipNotifier:");
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
Gura_DeclareMethodAlias(wx_ZipNotifier, __OnEntryUpdated, "OnEntryUpdated")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "entry", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ZipNotifier, __OnEntryUpdated)
{
	Object_wx_ZipNotifier *pThis = Object_wx_ZipNotifier::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxZipEntry& entry = arg.GetNumber(0)
	//pThis->GetEntity()->OnEntryUpdated(entry);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxZipNotifier
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ZipNotifier)
{
	// Class assignment
	Gura_AssignValueEx("ZipNotifier", Reference());
	// Method assignment
	Gura_AssignMethod(wx_ZipNotifier, __OnEntryUpdated);
}

Gura_ImplementDescendantCreator(wx_ZipNotifier)
{
	return new Object_wx_ZipNotifier((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
