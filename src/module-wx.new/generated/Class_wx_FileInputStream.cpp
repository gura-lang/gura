//----------------------------------------------------------------------------
// wxFileInputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFileInputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFileInputStream
//----------------------------------------------------------------------------
Object_wx_FileInputStream::~Object_wx_FileInputStream()
{
}

Object *Object_wx_FileInputStream::Clone() const
{
	return nullptr;
}

String Object_wx_FileInputStream::ToString(bool exprFlag)
{
	String rtn("<wx.FileInputStream:");
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
Gura_DeclareMethodAlias(wx_FileInputStream, __wxFileInputStream, "wxFileInputStream")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ifileName", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileInputStream, __wxFileInputStream)
{
	Object_wx_FileInputStream *pThis = Object_wx_FileInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ifileName = arg.GetNumber(0)
	//pThis->GetEntity()->wxFileInputStream();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileInputStream, __wxFileInputStream_1, "wxFileInputStream_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "file", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileInputStream, __wxFileInputStream_1)
{
	Object_wx_FileInputStream *pThis = Object_wx_FileInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int file = arg.GetNumber(0)
	//pThis->GetEntity()->wxFileInputStream();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileInputStream, __wxFileInputStream_2, "wxFileInputStream_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fd", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileInputStream, __wxFileInputStream_2)
{
	Object_wx_FileInputStream *pThis = Object_wx_FileInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int fd = arg.GetNumber(0)
	//pThis->GetEntity()->wxFileInputStream();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileInputStream, __IsOk, "IsOk")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileInputStream, __IsOk)
{
	Object_wx_FileInputStream *pThis = Object_wx_FileInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileInputStream, __GetFile, "GetFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileInputStream, __GetFile)
{
	Object_wx_FileInputStream *pThis = Object_wx_FileInputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFile();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFileInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileInputStream)
{
	Gura_AssignMethod(wx_FileInputStream, __wxFileInputStream);
	Gura_AssignMethod(wx_FileInputStream, __wxFileInputStream_1);
	Gura_AssignMethod(wx_FileInputStream, __wxFileInputStream_2);
	Gura_AssignMethod(wx_FileInputStream, __IsOk);
	Gura_AssignMethod(wx_FileInputStream, __GetFile);
}

Gura_ImplementDescendantCreator(wx_FileInputStream)
{
	return new Object_wx_FileInputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
