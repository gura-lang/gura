//----------------------------------------------------------------------------
// wxZipInputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxZipInputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxZipInputStream
//----------------------------------------------------------------------------
Object_wx_ZipInputStream::~Object_wx_ZipInputStream()
{
}

Object *Object_wx_ZipInputStream::Clone() const
{
	return nullptr;
}

String Object_wx_ZipInputStream::ToString(bool exprFlag)
{
	String rtn("<wx.ZipInputStream:");
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
Gura_DeclareMethod(wx_ZipInputStream, wxZipInputStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ZipInputStream, wxZipInputStream)
{
	Object_wx_ZipInputStream *pThis = Object_wx_ZipInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//int conv = arg.GetNumber(1)
	//pThis->GetEntity()->wxZipInputStream();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ZipInputStream, wxZipInputStream_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ZipInputStream, wxZipInputStream_1)
{
	Object_wx_ZipInputStream *pThis = Object_wx_ZipInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//int conv = arg.GetNumber(1)
	//pThis->GetEntity()->wxZipInputStream();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ZipInputStream, CloseEntry)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ZipInputStream, CloseEntry)
{
	Object_wx_ZipInputStream *pThis = Object_wx_ZipInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CloseEntry();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ZipInputStream, GetComment)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ZipInputStream, GetComment)
{
	Object_wx_ZipInputStream *pThis = Object_wx_ZipInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetComment();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ZipInputStream, GetNextEntry)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ZipInputStream, GetNextEntry)
{
	Object_wx_ZipInputStream *pThis = Object_wx_ZipInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetNextEntry();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ZipInputStream, GetTotalEntries)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ZipInputStream, GetTotalEntries)
{
	Object_wx_ZipInputStream *pThis = Object_wx_ZipInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTotalEntries();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ZipInputStream, OpenEntry)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "entry", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ZipInputStream, OpenEntry)
{
	Object_wx_ZipInputStream *pThis = Object_wx_ZipInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int entry = arg.GetNumber(0)
	//pThis->GetEntity()->OpenEntry();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxZipInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ZipInputStream)
{
	Gura_AssignMethod(wx_ZipInputStream, wxZipInputStream);
	Gura_AssignMethod(wx_ZipInputStream, wxZipInputStream_1);
	Gura_AssignMethod(wx_ZipInputStream, CloseEntry);
	Gura_AssignMethod(wx_ZipInputStream, GetComment);
	Gura_AssignMethod(wx_ZipInputStream, GetNextEntry);
	Gura_AssignMethod(wx_ZipInputStream, GetTotalEntries);
	Gura_AssignMethod(wx_ZipInputStream, OpenEntry);
}

Gura_ImplementDescendantCreator(wx_ZipInputStream)
{
	return new Object_wx_ZipInputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
