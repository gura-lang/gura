//----------------------------------------------------------------------------
// wxTextFile
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTextFile
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTextFile
//----------------------------------------------------------------------------
Object_wx_TextFile::~Object_wx_TextFile()
{
}

Object *Object_wx_TextFile::Clone() const
{
	return nullptr;
}

String Object_wx_TextFile::ToString(bool exprFlag)
{
	String rtn("<wx.TextFile:");
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
Gura_DeclareMethodAlias(wx_TextFile, __wxTextFile, "wxTextFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextFile, __wxTextFile)
{
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxTextFile();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextFile, __wxTextFile_1, "wxTextFile_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "strFile", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextFile, __wxTextFile_1)
{
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int strFile = arg.GetNumber(0)
	//pThis->GetEntity()->wxTextFile();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextFile, __AddLine, "AddLine")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextFile, __AddLine)
{
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//int type = arg.GetNumber(1)
	//pThis->GetEntity()->AddLine();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextFile, __Clear, "Clear")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextFile, __Clear)
{
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextFile, __Close, "Close")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextFile, __Close)
{
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Close();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextFile, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextFile, __Create)
{
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextFile, __Create_1, "Create_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "strFile", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextFile, __Create_1)
{
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int strFile = arg.GetNumber(0)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextFile, __Eof, "Eof")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextFile, __Eof)
{
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Eof();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextFile, __Exists, "Exists")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextFile, __Exists)
{
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Exists();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextFile, __GetCurrentLine, "GetCurrentLine")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextFile, __GetCurrentLine)
{
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCurrentLine();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextFile, __GetEOL, "GetEOL")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextFile, __GetEOL)
{
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int type = arg.GetNumber(0)
	//pThis->GetEntity()->GetEOL();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextFile, __GetFirstLine, "GetFirstLine")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextFile, __GetFirstLine)
{
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFirstLine();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextFile, __GetLastLine, "GetLastLine")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextFile, __GetLastLine)
{
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLastLine();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextFile, __GetLine, "GetLine")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextFile, __GetLine)
{
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->GetLine();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextFile, __GetLine_1, "GetLine_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextFile, __GetLine_1)
{
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->GetLine();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextFile, __GetLineCount, "GetLineCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextFile, __GetLineCount)
{
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLineCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextFile, __GetLineType, "GetLineType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextFile, __GetLineType)
{
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->GetLineType();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextFile, __GetName, "GetName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextFile, __GetName)
{
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextFile, __GetNextLine, "GetNextLine")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextFile, __GetNextLine)
{
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetNextLine();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextFile, __GetPrevLine, "GetPrevLine")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextFile, __GetPrevLine)
{
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPrevLine();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextFile, __GoToLine, "GoToLine")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextFile, __GoToLine)
{
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->GoToLine();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextFile, __GuessType, "GuessType")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextFile, __GuessType)
{
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GuessType();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextFile, __InsertLine, "InsertLine")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextFile, __InsertLine)
{
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//int n = arg.GetNumber(1)
	//int type = arg.GetNumber(2)
	//pThis->GetEntity()->InsertLine();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextFile, __IsOpened, "IsOpened")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextFile, __IsOpened)
{
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOpened();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextFile, __Open, "Open")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextFile, __Open)
{
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int conv = arg.GetNumber(0)
	//pThis->GetEntity()->Open();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextFile, __Open_1, "Open_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "strFile", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextFile, __Open_1)
{
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int strFile = arg.GetNumber(0)
	//int conv = arg.GetNumber(1)
	//pThis->GetEntity()->Open();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextFile, __RemoveLine, "RemoveLine")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextFile, __RemoveLine)
{
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveLine();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextFile, __Write, "Write")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "typeNew", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextFile, __Write)
{
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int typeNew = arg.GetNumber(0)
	//int conv = arg.GetNumber(1)
	//pThis->GetEntity()->Write();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTextFile
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextFile)
{
	Gura_AssignMethod(wx_TextFile, __wxTextFile);
	Gura_AssignMethod(wx_TextFile, __wxTextFile_1);
	Gura_AssignMethod(wx_TextFile, __AddLine);
	Gura_AssignMethod(wx_TextFile, __Clear);
	Gura_AssignMethod(wx_TextFile, __Close);
	Gura_AssignMethod(wx_TextFile, __Create);
	Gura_AssignMethod(wx_TextFile, __Create_1);
	Gura_AssignMethod(wx_TextFile, __Eof);
	Gura_AssignMethod(wx_TextFile, __Exists);
	Gura_AssignMethod(wx_TextFile, __GetCurrentLine);
	Gura_AssignMethod(wx_TextFile, __GetEOL);
	Gura_AssignMethod(wx_TextFile, __GetFirstLine);
	Gura_AssignMethod(wx_TextFile, __GetLastLine);
	Gura_AssignMethod(wx_TextFile, __GetLine);
	Gura_AssignMethod(wx_TextFile, __GetLine_1);
	Gura_AssignMethod(wx_TextFile, __GetLineCount);
	Gura_AssignMethod(wx_TextFile, __GetLineType);
	Gura_AssignMethod(wx_TextFile, __GetName);
	Gura_AssignMethod(wx_TextFile, __GetNextLine);
	Gura_AssignMethod(wx_TextFile, __GetPrevLine);
	Gura_AssignMethod(wx_TextFile, __GoToLine);
	Gura_AssignMethod(wx_TextFile, __GuessType);
	Gura_AssignMethod(wx_TextFile, __InsertLine);
	Gura_AssignMethod(wx_TextFile, __IsOpened);
	Gura_AssignMethod(wx_TextFile, __Open);
	Gura_AssignMethod(wx_TextFile, __Open_1);
	Gura_AssignMethod(wx_TextFile, __RemoveLine);
	Gura_AssignMethod(wx_TextFile, __Write);
}

Gura_ImplementDescendantCreator(wx_TextFile)
{
	return new Object_wx_TextFile((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
