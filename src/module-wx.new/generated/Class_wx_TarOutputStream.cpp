//----------------------------------------------------------------------------
// wxTarOutputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTarOutputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTarOutputStream
//----------------------------------------------------------------------------
Object_wx_TarOutputStream::~Object_wx_TarOutputStream()
{
}

Object *Object_wx_TarOutputStream::Clone() const
{
	return nullptr;
}

String Object_wx_TarOutputStream::ToString(bool exprFlag)
{
	String rtn("<wx.TarOutputStream:");
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
Gura_DeclareFunctionAlias(__wxTarOutputStream, "wxTarOutputStream")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxTarOutputStream)
{
	//int stream = arg.GetNumber(0)
	//int format = arg.GetNumber(1)
	//int conv = arg.GetNumber(2)
	//wxTarOutputStream();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxTarOutputStream_1, "wxTarOutputStream_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxTarOutputStream_1)
{
	//int stream = arg.GetNumber(0)
	//int format = arg.GetNumber(1)
	//int conv = arg.GetNumber(2)
	//wxTarOutputStream();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_TarOutputStream, __Close, "Close")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TarOutputStream, __Close)
{
	Object_wx_TarOutputStream *pThis = Object_wx_TarOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Close();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TarOutputStream, __CloseEntry, "CloseEntry")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TarOutputStream, __CloseEntry)
{
	Object_wx_TarOutputStream *pThis = Object_wx_TarOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CloseEntry();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TarOutputStream, __CopyArchiveMetaData, "CopyArchiveMetaData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarOutputStream, __CopyArchiveMetaData)
{
	Object_wx_TarOutputStream *pThis = Object_wx_TarOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int s = arg.GetNumber(0)
	//pThis->GetEntity()->CopyArchiveMetaData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TarOutputStream, __CopyEntry, "CopyEntry")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "entry", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "inputStream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarOutputStream, __CopyEntry)
{
	Object_wx_TarOutputStream *pThis = Object_wx_TarOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int entry = arg.GetNumber(0)
	//int inputStream = arg.GetNumber(1)
	//pThis->GetEntity()->CopyEntry();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TarOutputStream, __GetBlockingFactor, "GetBlockingFactor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TarOutputStream, __GetBlockingFactor)
{
	Object_wx_TarOutputStream *pThis = Object_wx_TarOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBlockingFactor();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TarOutputStream, __SetBlockingFactor, "SetBlockingFactor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "factor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarOutputStream, __SetBlockingFactor)
{
	Object_wx_TarOutputStream *pThis = Object_wx_TarOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int factor = arg.GetNumber(0)
	//pThis->GetEntity()->SetBlockingFactor();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TarOutputStream, __PutNextDirEntry, "PutNextDirEntry")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarOutputStream, __PutNextDirEntry)
{
	Object_wx_TarOutputStream *pThis = Object_wx_TarOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int dt = arg.GetNumber(1)
	//pThis->GetEntity()->PutNextDirEntry();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TarOutputStream, __PutNextEntry, "PutNextEntry")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "entry", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarOutputStream, __PutNextEntry)
{
	Object_wx_TarOutputStream *pThis = Object_wx_TarOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int entry = arg.GetNumber(0)
	//pThis->GetEntity()->PutNextEntry();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TarOutputStream, __PutNextEntry_1, "PutNextEntry_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarOutputStream, __PutNextEntry_1)
{
	Object_wx_TarOutputStream *pThis = Object_wx_TarOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int dt = arg.GetNumber(1)
	//int size = arg.GetNumber(2)
	//pThis->GetEntity()->PutNextEntry();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTarOutputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TarOutputStream)
{
	// Constructor assignment
	Gura_AssignFunction(__wxTarOutputStream);
	Gura_AssignFunction(__wxTarOutputStream_1);
	// Method assignment
	Gura_AssignMethod(wx_TarOutputStream, __Close);
	Gura_AssignMethod(wx_TarOutputStream, __CloseEntry);
	Gura_AssignMethod(wx_TarOutputStream, __CopyArchiveMetaData);
	Gura_AssignMethod(wx_TarOutputStream, __CopyEntry);
	Gura_AssignMethod(wx_TarOutputStream, __GetBlockingFactor);
	Gura_AssignMethod(wx_TarOutputStream, __SetBlockingFactor);
	Gura_AssignMethod(wx_TarOutputStream, __PutNextDirEntry);
	Gura_AssignMethod(wx_TarOutputStream, __PutNextEntry);
	Gura_AssignMethod(wx_TarOutputStream, __PutNextEntry_1);
}

Gura_ImplementDescendantCreator(wx_TarOutputStream)
{
	return new Object_wx_TarOutputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
