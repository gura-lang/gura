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
Gura_DeclareMethod(wx_FFile, wxFFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FFile, wxFFile)
{
	Object_wx_FFile *pThis = Object_wx_FFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxFFile();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FFile, wxFFile_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FFile, wxFFile_1)
{
	Object_wx_FFile *pThis = Object_wx_FFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int fp = arg.GetNumber(0)
	//pThis->GetEntity()->wxFFile();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FFile, wxFFile_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FFile, wxFFile_2)
{
	Object_wx_FFile *pThis = Object_wx_FFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//int mode = arg.GetNumber(1)
	//pThis->GetEntity()->wxFFile();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FFile, Attach)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fp", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FFile, Attach)
{
	Object_wx_FFile *pThis = Object_wx_FFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int fp = arg.GetNumber(0)
	//int name = arg.GetNumber(1)
	//pThis->GetEntity()->Attach();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FFile, Close)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FFile, Close)
{
	Object_wx_FFile *pThis = Object_wx_FFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Close();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FFile, Detach)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FFile, Detach)
{
	Object_wx_FFile *pThis = Object_wx_FFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Detach();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FFile, Eof)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FFile, Eof)
{
	Object_wx_FFile *pThis = Object_wx_FFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Eof();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FFile, Error)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FFile, Error)
{
	Object_wx_FFile *pThis = Object_wx_FFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Error();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FFile, Flush)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FFile, Flush)
{
	Object_wx_FFile *pThis = Object_wx_FFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Flush();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FFile, GetKind)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FFile, GetKind)
{
	Object_wx_FFile *pThis = Object_wx_FFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetKind();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FFile, GetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FFile, GetName)
{
	Object_wx_FFile *pThis = Object_wx_FFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FFile, IsOpened)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FFile, IsOpened)
{
	Object_wx_FFile *pThis = Object_wx_FFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOpened();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FFile, Length)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FFile, Length)
{
	Object_wx_FFile *pThis = Object_wx_FFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Length();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FFile, Open)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FFile, Open)
{
	Object_wx_FFile *pThis = Object_wx_FFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//int mode = arg.GetNumber(1)
	//pThis->GetEntity()->Open();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FFile, Read)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "count", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FFile, Read)
{
	Object_wx_FFile *pThis = Object_wx_FFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int count = arg.GetNumber(1)
	//pThis->GetEntity()->Read();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FFile, ReadAll)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FFile, ReadAll)
{
	Object_wx_FFile *pThis = Object_wx_FFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//int conv = arg.GetNumber(1)
	//pThis->GetEntity()->ReadAll();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FFile, Seek)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ofs", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FFile, Seek)
{
	Object_wx_FFile *pThis = Object_wx_FFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ofs = arg.GetNumber(0)
	//int mode = arg.GetNumber(1)
	//pThis->GetEntity()->Seek();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FFile, SeekEnd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ofs", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FFile, SeekEnd)
{
	Object_wx_FFile *pThis = Object_wx_FFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ofs = arg.GetNumber(0)
	//pThis->GetEntity()->SeekEnd();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FFile, Tell)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FFile, Tell)
{
	Object_wx_FFile *pThis = Object_wx_FFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Tell();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FFile, Write)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FFile, Write)
{
	Object_wx_FFile *pThis = Object_wx_FFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//int conv = arg.GetNumber(1)
	//pThis->GetEntity()->Write();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FFile, Write_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "count", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FFile, Write_1)
{
	Object_wx_FFile *pThis = Object_wx_FFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int count = arg.GetNumber(1)
	//pThis->GetEntity()->Write();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FFile, fp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FFile, fp)
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
	Gura_AssignMethod(wx_FFile, wxFFile);
	Gura_AssignMethod(wx_FFile, wxFFile_1);
	Gura_AssignMethod(wx_FFile, wxFFile_2);
	Gura_AssignMethod(wx_FFile, Attach);
	Gura_AssignMethod(wx_FFile, Close);
	Gura_AssignMethod(wx_FFile, Detach);
	Gura_AssignMethod(wx_FFile, Eof);
	Gura_AssignMethod(wx_FFile, Error);
	Gura_AssignMethod(wx_FFile, Flush);
	Gura_AssignMethod(wx_FFile, GetKind);
	Gura_AssignMethod(wx_FFile, GetName);
	Gura_AssignMethod(wx_FFile, IsOpened);
	Gura_AssignMethod(wx_FFile, Length);
	Gura_AssignMethod(wx_FFile, Open);
	Gura_AssignMethod(wx_FFile, Read);
	Gura_AssignMethod(wx_FFile, ReadAll);
	Gura_AssignMethod(wx_FFile, Seek);
	Gura_AssignMethod(wx_FFile, SeekEnd);
	Gura_AssignMethod(wx_FFile, Tell);
	Gura_AssignMethod(wx_FFile, Write);
	Gura_AssignMethod(wx_FFile, Write_1);
	Gura_AssignMethod(wx_FFile, fp);
}

Gura_ImplementDescendantCreator(wx_FFile)
{
	return new Object_wx_FFile((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
