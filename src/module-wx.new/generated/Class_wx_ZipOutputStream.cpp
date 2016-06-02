//----------------------------------------------------------------------------
// wxZipOutputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxZipOutputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxZipOutputStream
//----------------------------------------------------------------------------
Object_wx_ZipOutputStream::~Object_wx_ZipOutputStream()
{
}

Object *Object_wx_ZipOutputStream::Clone() const
{
	return nullptr;
}

String Object_wx_ZipOutputStream::ToString(bool exprFlag)
{
	String rtn("<wx.ZipOutputStream:");
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
Gura_DeclareMethod(wx_ZipOutputStream, wxZipOutputStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ZipOutputStream, wxZipOutputStream)
{
	Object_wx_ZipOutputStream *pThis = Object_wx_ZipOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//int level = arg.GetNumber(1)
	//int conv = arg.GetNumber(2)
	//pThis->GetEntity()->wxZipOutputStream();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ZipOutputStream, wxZipOutputStream_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ZipOutputStream, wxZipOutputStream_1)
{
	Object_wx_ZipOutputStream *pThis = Object_wx_ZipOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//int level = arg.GetNumber(1)
	//int conv = arg.GetNumber(2)
	//pThis->GetEntity()->wxZipOutputStream();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ZipOutputStream, Close)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ZipOutputStream, Close)
{
	Object_wx_ZipOutputStream *pThis = Object_wx_ZipOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Close();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ZipOutputStream, CloseEntry)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ZipOutputStream, CloseEntry)
{
	Object_wx_ZipOutputStream *pThis = Object_wx_ZipOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CloseEntry();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ZipOutputStream, CopyArchiveMetaData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "inputStream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ZipOutputStream, CopyArchiveMetaData)
{
	Object_wx_ZipOutputStream *pThis = Object_wx_ZipOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int inputStream = arg.GetNumber(0)
	//pThis->GetEntity()->CopyArchiveMetaData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ZipOutputStream, CopyEntry)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "entry", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "inputStream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ZipOutputStream, CopyEntry)
{
	Object_wx_ZipOutputStream *pThis = Object_wx_ZipOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int entry = arg.GetNumber(0)
	//int inputStream = arg.GetNumber(1)
	//pThis->GetEntity()->CopyEntry();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ZipOutputStream, GetLevel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ZipOutputStream, GetLevel)
{
	Object_wx_ZipOutputStream *pThis = Object_wx_ZipOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLevel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ZipOutputStream, SetLevel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ZipOutputStream, SetLevel)
{
	Object_wx_ZipOutputStream *pThis = Object_wx_ZipOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int level = arg.GetNumber(0)
	//pThis->GetEntity()->SetLevel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ZipOutputStream, PutNextDirEntry)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ZipOutputStream, PutNextDirEntry)
{
	Object_wx_ZipOutputStream *pThis = Object_wx_ZipOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int dt = arg.GetNumber(1)
	//pThis->GetEntity()->PutNextDirEntry();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ZipOutputStream, PutNextEntry)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "entry", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ZipOutputStream, PutNextEntry)
{
	Object_wx_ZipOutputStream *pThis = Object_wx_ZipOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int entry = arg.GetNumber(0)
	//pThis->GetEntity()->PutNextEntry();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ZipOutputStream, PutNextEntry_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ZipOutputStream, PutNextEntry_1)
{
	Object_wx_ZipOutputStream *pThis = Object_wx_ZipOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int dt = arg.GetNumber(1)
	//int size = arg.GetNumber(2)
	//pThis->GetEntity()->PutNextEntry();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ZipOutputStream, SetComment)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "comment", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ZipOutputStream, SetComment)
{
	Object_wx_ZipOutputStream *pThis = Object_wx_ZipOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int comment = arg.GetNumber(0)
	//pThis->GetEntity()->SetComment();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxZipOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ZipOutputStream)
{
	Gura_AssignMethod(wx_ZipOutputStream, wxZipOutputStream);
	Gura_AssignMethod(wx_ZipOutputStream, wxZipOutputStream_1);
	Gura_AssignMethod(wx_ZipOutputStream, Close);
	Gura_AssignMethod(wx_ZipOutputStream, CloseEntry);
	Gura_AssignMethod(wx_ZipOutputStream, CopyArchiveMetaData);
	Gura_AssignMethod(wx_ZipOutputStream, CopyEntry);
	Gura_AssignMethod(wx_ZipOutputStream, GetLevel);
	Gura_AssignMethod(wx_ZipOutputStream, SetLevel);
	Gura_AssignMethod(wx_ZipOutputStream, PutNextDirEntry);
	Gura_AssignMethod(wx_ZipOutputStream, PutNextEntry);
	Gura_AssignMethod(wx_ZipOutputStream, PutNextEntry_1);
	Gura_AssignMethod(wx_ZipOutputStream, SetComment);
}

Gura_ImplementDescendantCreator(wx_ZipOutputStream)
{
	return new Object_wx_ZipOutputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
