//----------------------------------------------------------------------------
// wxFFile
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFFile
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFFile
//----------------------------------------------------------------------------
Object_wx_FFile::~Object_wx_FFile()
{
}

Object *Object_wx_FFile::Clone() const
{
	return nullptr;
}

String Object_wx_FFile::ToString(bool exprFlag)
{
	String rtn("<wx.FFile:");
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
Gura_DeclareMethodAlias(wx_FFile, __wxFFile, "wxFFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FFile, __wxFFile)
{
	Object_wx_FFile *pThis = Object_wx_FFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxFFile();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FFile, __wxFFile_1, "wxFFile_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FFile, __wxFFile_1)
{
	Object_wx_FFile *pThis = Object_wx_FFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int fp = arg.GetNumber(0)
	//pThis->GetEntity()->wxFFile();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FFile, __wxFFile_2, "wxFFile_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FFile, __wxFFile_2)
{
	Object_wx_FFile *pThis = Object_wx_FFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//int mode = arg.GetNumber(1)
	//pThis->GetEntity()->wxFFile();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FFile, __Attach, "Attach")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fp", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FFile, __Attach)
{
	Object_wx_FFile *pThis = Object_wx_FFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int fp = arg.GetNumber(0)
	//int name = arg.GetNumber(1)
	//pThis->GetEntity()->Attach();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FFile, __Close, "Close")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FFile, __Close)
{
	Object_wx_FFile *pThis = Object_wx_FFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Close();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FFile, __Detach, "Detach")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FFile, __Detach)
{
	Object_wx_FFile *pThis = Object_wx_FFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Detach();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FFile, __Eof, "Eof")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FFile, __Eof)
{
	Object_wx_FFile *pThis = Object_wx_FFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Eof();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FFile, __Error, "Error")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FFile, __Error)
{
	Object_wx_FFile *pThis = Object_wx_FFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Error();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FFile, __Flush, "Flush")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FFile, __Flush)
{
	Object_wx_FFile *pThis = Object_wx_FFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Flush();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FFile, __GetKind, "GetKind")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FFile, __GetKind)
{
	Object_wx_FFile *pThis = Object_wx_FFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetKind();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FFile, __GetName, "GetName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FFile, __GetName)
{
	Object_wx_FFile *pThis = Object_wx_FFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FFile, __IsOpened, "IsOpened")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FFile, __IsOpened)
{
	Object_wx_FFile *pThis = Object_wx_FFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOpened();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FFile, __Length, "Length")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FFile, __Length)
{
	Object_wx_FFile *pThis = Object_wx_FFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Length();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FFile, __Open, "Open")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FFile, __Open)
{
	Object_wx_FFile *pThis = Object_wx_FFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//int mode = arg.GetNumber(1)
	//pThis->GetEntity()->Open();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FFile, __Read, "Read")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "count", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FFile, __Read)
{
	Object_wx_FFile *pThis = Object_wx_FFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int count = arg.GetNumber(1)
	//pThis->GetEntity()->Read();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FFile, __ReadAll, "ReadAll")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FFile, __ReadAll)
{
	Object_wx_FFile *pThis = Object_wx_FFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//int conv = arg.GetNumber(1)
	//pThis->GetEntity()->ReadAll();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FFile, __Seek, "Seek")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ofs", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FFile, __Seek)
{
	Object_wx_FFile *pThis = Object_wx_FFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ofs = arg.GetNumber(0)
	//int mode = arg.GetNumber(1)
	//pThis->GetEntity()->Seek();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FFile, __SeekEnd, "SeekEnd")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ofs", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FFile, __SeekEnd)
{
	Object_wx_FFile *pThis = Object_wx_FFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ofs = arg.GetNumber(0)
	//pThis->GetEntity()->SeekEnd();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FFile, __Tell, "Tell")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FFile, __Tell)
{
	Object_wx_FFile *pThis = Object_wx_FFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Tell();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FFile, __Write, "Write")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FFile, __Write)
{
	Object_wx_FFile *pThis = Object_wx_FFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//int conv = arg.GetNumber(1)
	//pThis->GetEntity()->Write();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FFile, __Write_1, "Write_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "count", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FFile, __Write_1)
{
	Object_wx_FFile *pThis = Object_wx_FFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int count = arg.GetNumber(1)
	//pThis->GetEntity()->Write();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FFile, __fp, "fp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FFile, __fp)
{
	Object_wx_FFile *pThis = Object_wx_FFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->fp();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFFile
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FFile)
{
	Gura_AssignMethod(wx_FFile, __wxFFile);
	Gura_AssignMethod(wx_FFile, __wxFFile_1);
	Gura_AssignMethod(wx_FFile, __wxFFile_2);
	Gura_AssignMethod(wx_FFile, __Attach);
	Gura_AssignMethod(wx_FFile, __Close);
	Gura_AssignMethod(wx_FFile, __Detach);
	Gura_AssignMethod(wx_FFile, __Eof);
	Gura_AssignMethod(wx_FFile, __Error);
	Gura_AssignMethod(wx_FFile, __Flush);
	Gura_AssignMethod(wx_FFile, __GetKind);
	Gura_AssignMethod(wx_FFile, __GetName);
	Gura_AssignMethod(wx_FFile, __IsOpened);
	Gura_AssignMethod(wx_FFile, __Length);
	Gura_AssignMethod(wx_FFile, __Open);
	Gura_AssignMethod(wx_FFile, __Read);
	Gura_AssignMethod(wx_FFile, __ReadAll);
	Gura_AssignMethod(wx_FFile, __Seek);
	Gura_AssignMethod(wx_FFile, __SeekEnd);
	Gura_AssignMethod(wx_FFile, __Tell);
	Gura_AssignMethod(wx_FFile, __Write);
	Gura_AssignMethod(wx_FFile, __Write_1);
	Gura_AssignMethod(wx_FFile, __fp);
}

Gura_ImplementDescendantCreator(wx_FFile)
{
	return new Object_wx_FFile((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
