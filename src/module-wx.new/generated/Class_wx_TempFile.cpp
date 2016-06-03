//----------------------------------------------------------------------------
// wxTempFile
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTempFile
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTempFile
//----------------------------------------------------------------------------
Object_wx_TempFile::~Object_wx_TempFile()
{
}

Object *Object_wx_TempFile::Clone() const
{
	return nullptr;
}

String Object_wx_TempFile::ToString(bool exprFlag)
{
	String rtn("<wx.TempFile:");
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
Gura_DeclareMethodAlias(wx_TempFile, __wxTempFile, "wxTempFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "strName", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TempFile, __wxTempFile)
{
	Object_wx_TempFile *pThis = Object_wx_TempFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int strName = arg.GetNumber(0)
	//pThis->GetEntity()->wxTempFile();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TempFile, __Commit, "Commit")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TempFile, __Commit)
{
	Object_wx_TempFile *pThis = Object_wx_TempFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Commit();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TempFile, __Discard, "Discard")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TempFile, __Discard)
{
	Object_wx_TempFile *pThis = Object_wx_TempFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Discard();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TempFile, __Flush, "Flush")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TempFile, __Flush)
{
	Object_wx_TempFile *pThis = Object_wx_TempFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Flush();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TempFile, __IsOpened, "IsOpened")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TempFile, __IsOpened)
{
	Object_wx_TempFile *pThis = Object_wx_TempFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOpened();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TempFile, __Length, "Length")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TempFile, __Length)
{
	Object_wx_TempFile *pThis = Object_wx_TempFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Length();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TempFile, __Open, "Open")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "strName", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TempFile, __Open)
{
	Object_wx_TempFile *pThis = Object_wx_TempFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int strName = arg.GetNumber(0)
	//pThis->GetEntity()->Open();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TempFile, __Seek, "Seek")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ofs", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TempFile, __Seek)
{
	Object_wx_TempFile *pThis = Object_wx_TempFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ofs = arg.GetNumber(0)
	//int mode = arg.GetNumber(1)
	//pThis->GetEntity()->Seek();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TempFile, __Tell, "Tell")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TempFile, __Tell)
{
	Object_wx_TempFile *pThis = Object_wx_TempFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Tell();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TempFile, __Write, "Write")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TempFile, __Write)
{
	Object_wx_TempFile *pThis = Object_wx_TempFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//int conv = arg.GetNumber(1)
	//pThis->GetEntity()->Write();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTempFile
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TempFile)
{
	Gura_AssignMethod(wx_TempFile, __wxTempFile);
	Gura_AssignMethod(wx_TempFile, __Commit);
	Gura_AssignMethod(wx_TempFile, __Discard);
	Gura_AssignMethod(wx_TempFile, __Flush);
	Gura_AssignMethod(wx_TempFile, __IsOpened);
	Gura_AssignMethod(wx_TempFile, __Length);
	Gura_AssignMethod(wx_TempFile, __Open);
	Gura_AssignMethod(wx_TempFile, __Seek);
	Gura_AssignMethod(wx_TempFile, __Tell);
	Gura_AssignMethod(wx_TempFile, __Write);
}

Gura_ImplementDescendantCreator(wx_TempFile)
{
	return new Object_wx_TempFile((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
