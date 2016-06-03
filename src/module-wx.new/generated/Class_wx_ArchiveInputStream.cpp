//----------------------------------------------------------------------------
// wxArchiveInputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxArchiveInputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxArchiveInputStream
//----------------------------------------------------------------------------
Object_wx_ArchiveInputStream::~Object_wx_ArchiveInputStream()
{
}

Object *Object_wx_ArchiveInputStream::Clone() const
{
	return nullptr;
}

String Object_wx_ArchiveInputStream::ToString(bool exprFlag)
{
	String rtn("<wx.ArchiveInputStream:");
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
Gura_DeclareMethodAlias(wx_ArchiveInputStream, __CloseEntry, "CloseEntry")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ArchiveInputStream, __CloseEntry)
{
	Object_wx_ArchiveInputStream *pThis = Object_wx_ArchiveInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CloseEntry();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ArchiveInputStream, __GetNextEntry, "GetNextEntry")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ArchiveInputStream, __GetNextEntry)
{
	Object_wx_ArchiveInputStream *pThis = Object_wx_ArchiveInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetNextEntry();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ArchiveInputStream, __OpenEntry, "OpenEntry")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "entry", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ArchiveInputStream, __OpenEntry)
{
	Object_wx_ArchiveInputStream *pThis = Object_wx_ArchiveInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int entry = arg.GetNumber(0)
	//pThis->GetEntity()->OpenEntry();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxArchiveInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ArchiveInputStream)
{
	Gura_AssignMethod(wx_ArchiveInputStream, __CloseEntry);
	Gura_AssignMethod(wx_ArchiveInputStream, __GetNextEntry);
	Gura_AssignMethod(wx_ArchiveInputStream, __OpenEntry);
}

Gura_ImplementDescendantCreator(wx_ArchiveInputStream)
{
	return new Object_wx_ArchiveInputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
