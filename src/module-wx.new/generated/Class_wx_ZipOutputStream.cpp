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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxZipOutputStream, "wxZipOutputStream")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxZipOutputStream)
{
	//int stream = arg.GetNumber(0)
	//int level = arg.GetNumber(1)
	//int conv = arg.GetNumber(2)
	//wxZipOutputStream();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxZipOutputStream_1, "wxZipOutputStream_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxZipOutputStream_1)
{
	//int stream = arg.GetNumber(0)
	//int level = arg.GetNumber(1)
	//int conv = arg.GetNumber(2)
	//wxZipOutputStream();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_ZipOutputStream, __Close, "Close")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ZipOutputStream, __Close)
{
	Object_wx_ZipOutputStream *pThis = Object_wx_ZipOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Close();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ZipOutputStream, __CloseEntry, "CloseEntry")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ZipOutputStream, __CloseEntry)
{
	Object_wx_ZipOutputStream *pThis = Object_wx_ZipOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CloseEntry();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ZipOutputStream, __CopyArchiveMetaData, "CopyArchiveMetaData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "inputStream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ZipOutputStream, __CopyArchiveMetaData)
{
	Object_wx_ZipOutputStream *pThis = Object_wx_ZipOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int inputStream = arg.GetNumber(0)
	//pThis->GetEntity()->CopyArchiveMetaData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ZipOutputStream, __CopyEntry, "CopyEntry")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "entry", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "inputStream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ZipOutputStream, __CopyEntry)
{
	Object_wx_ZipOutputStream *pThis = Object_wx_ZipOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int entry = arg.GetNumber(0)
	//int inputStream = arg.GetNumber(1)
	//pThis->GetEntity()->CopyEntry();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ZipOutputStream, __GetLevel, "GetLevel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ZipOutputStream, __GetLevel)
{
	Object_wx_ZipOutputStream *pThis = Object_wx_ZipOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLevel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ZipOutputStream, __SetLevel, "SetLevel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ZipOutputStream, __SetLevel)
{
	Object_wx_ZipOutputStream *pThis = Object_wx_ZipOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int level = arg.GetNumber(0)
	//pThis->GetEntity()->SetLevel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ZipOutputStream, __PutNextDirEntry, "PutNextDirEntry")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ZipOutputStream, __PutNextDirEntry)
{
	Object_wx_ZipOutputStream *pThis = Object_wx_ZipOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int dt = arg.GetNumber(1)
	//pThis->GetEntity()->PutNextDirEntry();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ZipOutputStream, __PutNextEntry, "PutNextEntry")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "entry", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ZipOutputStream, __PutNextEntry)
{
	Object_wx_ZipOutputStream *pThis = Object_wx_ZipOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int entry = arg.GetNumber(0)
	//pThis->GetEntity()->PutNextEntry();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ZipOutputStream, __PutNextEntry_1, "PutNextEntry_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ZipOutputStream, __PutNextEntry_1)
{
	Object_wx_ZipOutputStream *pThis = Object_wx_ZipOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int dt = arg.GetNumber(1)
	//int size = arg.GetNumber(2)
	//pThis->GetEntity()->PutNextEntry();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ZipOutputStream, __SetComment, "SetComment")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "comment", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ZipOutputStream, __SetComment)
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
	// Constructor assignment
	Gura_AssignFunction(__wxZipOutputStream);
	Gura_AssignFunction(__wxZipOutputStream_1);
	// Method assignment
	Gura_AssignMethod(wx_ZipOutputStream, __Close);
	Gura_AssignMethod(wx_ZipOutputStream, __CloseEntry);
	Gura_AssignMethod(wx_ZipOutputStream, __CopyArchiveMetaData);
	Gura_AssignMethod(wx_ZipOutputStream, __CopyEntry);
	Gura_AssignMethod(wx_ZipOutputStream, __GetLevel);
	Gura_AssignMethod(wx_ZipOutputStream, __SetLevel);
	Gura_AssignMethod(wx_ZipOutputStream, __PutNextDirEntry);
	Gura_AssignMethod(wx_ZipOutputStream, __PutNextEntry);
	Gura_AssignMethod(wx_ZipOutputStream, __PutNextEntry_1);
	Gura_AssignMethod(wx_ZipOutputStream, __SetComment);
}

Gura_ImplementDescendantCreator(wx_ZipOutputStream)
{
	return new Object_wx_ZipOutputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
