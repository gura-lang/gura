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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_TarOutputStream, wxTarOutputStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarOutputStream, wxTarOutputStream)
{
	Object_wx_TarOutputStream *pThis = Object_wx_TarOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//int format = arg.GetNumber(1)
	//int conv = arg.GetNumber(2)
	//pThis->GetEntity()->wxTarOutputStream();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TarOutputStream, wxTarOutputStream_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stream", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarOutputStream, wxTarOutputStream_1)
{
	Object_wx_TarOutputStream *pThis = Object_wx_TarOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int stream = arg.GetNumber(0)
	//int format = arg.GetNumber(1)
	//int conv = arg.GetNumber(2)
	//pThis->GetEntity()->wxTarOutputStream();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TarOutputStream, Close)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TarOutputStream, Close)
{
	Object_wx_TarOutputStream *pThis = Object_wx_TarOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Close();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TarOutputStream, CloseEntry)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TarOutputStream, CloseEntry)
{
	Object_wx_TarOutputStream *pThis = Object_wx_TarOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CloseEntry();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TarOutputStream, CopyArchiveMetaData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "s", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarOutputStream, CopyArchiveMetaData)
{
	Object_wx_TarOutputStream *pThis = Object_wx_TarOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int s = arg.GetNumber(0)
	//pThis->GetEntity()->CopyArchiveMetaData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TarOutputStream, CopyEntry)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "entry", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "inputStream", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarOutputStream, CopyEntry)
{
	Object_wx_TarOutputStream *pThis = Object_wx_TarOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int entry = arg.GetNumber(0)
	//int inputStream = arg.GetNumber(1)
	//pThis->GetEntity()->CopyEntry();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TarOutputStream, GetBlockingFactor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TarOutputStream, GetBlockingFactor)
{
	Object_wx_TarOutputStream *pThis = Object_wx_TarOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBlockingFactor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TarOutputStream, SetBlockingFactor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "factor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarOutputStream, SetBlockingFactor)
{
	Object_wx_TarOutputStream *pThis = Object_wx_TarOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int factor = arg.GetNumber(0)
	//pThis->GetEntity()->SetBlockingFactor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TarOutputStream, PutNextDirEntry)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarOutputStream, PutNextDirEntry)
{
	Object_wx_TarOutputStream *pThis = Object_wx_TarOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int dt = arg.GetNumber(1)
	//pThis->GetEntity()->PutNextDirEntry();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TarOutputStream, PutNextEntry)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "entry", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarOutputStream, PutNextEntry)
{
	Object_wx_TarOutputStream *pThis = Object_wx_TarOutputStream::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int entry = arg.GetNumber(0)
	//pThis->GetEntity()->PutNextEntry();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TarOutputStream, PutNextEntry_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TarOutputStream, PutNextEntry_1)
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
	Gura_AssignMethod(wx_TarOutputStream, wxTarOutputStream);
	Gura_AssignMethod(wx_TarOutputStream, wxTarOutputStream_1);
	Gura_AssignMethod(wx_TarOutputStream, Close);
	Gura_AssignMethod(wx_TarOutputStream, CloseEntry);
	Gura_AssignMethod(wx_TarOutputStream, CopyArchiveMetaData);
	Gura_AssignMethod(wx_TarOutputStream, CopyEntry);
	Gura_AssignMethod(wx_TarOutputStream, GetBlockingFactor);
	Gura_AssignMethod(wx_TarOutputStream, SetBlockingFactor);
	Gura_AssignMethod(wx_TarOutputStream, PutNextDirEntry);
	Gura_AssignMethod(wx_TarOutputStream, PutNextEntry);
	Gura_AssignMethod(wx_TarOutputStream, PutNextEntry_1);
}

Gura_ImplementDescendantCreator(wx_TarOutputStream)
{
	return new Object_wx_TarOutputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
