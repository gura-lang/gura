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
Gura_DeclareMethod(wx_TextFile, wxTextFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextFile, wxTextFile)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxTextFile();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextFile, wxTextFile_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "strFile", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextFile, wxTextFile_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int strFile = arg.GetNumber(0)
	//pThis->GetEntity()->wxTextFile();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextFile, ~wxTextFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextFile, ~wxTextFile)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxTextFile();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextFile, AddLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextFile, AddLine)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//int type = arg.GetNumber(1)
	//pThis->GetEntity()->AddLine();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextFile, Clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextFile, Clear)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextFile, Close)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextFile, Close)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Close();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextFile, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextFile, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextFile, Create_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "strFile", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextFile, Create_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int strFile = arg.GetNumber(0)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextFile, Eof)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextFile, Eof)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Eof();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextFile, Exists)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextFile, Exists)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Exists();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextFile, GetCurrentLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextFile, GetCurrentLine)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetCurrentLine();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextFile, GetEOL)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextFile, GetEOL)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int type = arg.GetNumber(0)
	//pThis->GetEntity()->GetEOL();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextFile, GetFirstLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextFile, GetFirstLine)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFirstLine();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextFile, GetLastLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextFile, GetLastLine)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetLastLine();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextFile, GetLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextFile, GetLine)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->GetLine();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextFile, GetLine_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextFile, GetLine_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->GetLine();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextFile, GetLineCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextFile, GetLineCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetLineCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextFile, GetLineType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextFile, GetLineType)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->GetLineType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextFile, GetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextFile, GetName)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextFile, GetNextLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextFile, GetNextLine)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetNextLine();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextFile, GetPrevLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextFile, GetPrevLine)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPrevLine();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextFile, GoToLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextFile, GoToLine)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->GoToLine();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextFile, GuessType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextFile, GuessType)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GuessType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextFile, InsertLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "str", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextFile, InsertLine)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int str = arg.GetNumber(0)
	//int n = arg.GetNumber(1)
	//int type = arg.GetNumber(2)
	//pThis->GetEntity()->InsertLine();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextFile, IsOpened)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextFile, IsOpened)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsOpened();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextFile, Open)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextFile, Open)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int conv = arg.GetNumber(0)
	//pThis->GetEntity()->Open();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextFile, Open_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "strFile", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextFile, Open_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int strFile = arg.GetNumber(0)
	//int conv = arg.GetNumber(1)
	//pThis->GetEntity()->Open();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextFile, RemoveLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextFile, RemoveLine)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveLine();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextFile, Write)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "typeNew", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextFile, Write)
{
	Signal &sig = env.GetSignal();
	Object_wx_TextFile *pThis = Object_wx_TextFile::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Gura_AssignMethod(wx_TextFile, wxTextFile);
	Gura_AssignMethod(wx_TextFile, wxTextFile_1);
	Gura_AssignMethod(wx_TextFile, ~wxTextFile);
	Gura_AssignMethod(wx_TextFile, AddLine);
	Gura_AssignMethod(wx_TextFile, Clear);
	Gura_AssignMethod(wx_TextFile, Close);
	Gura_AssignMethod(wx_TextFile, Create);
	Gura_AssignMethod(wx_TextFile, Create_1);
	Gura_AssignMethod(wx_TextFile, Eof);
	Gura_AssignMethod(wx_TextFile, Exists);
	Gura_AssignMethod(wx_TextFile, GetCurrentLine);
	Gura_AssignMethod(wx_TextFile, GetEOL);
	Gura_AssignMethod(wx_TextFile, GetFirstLine);
	Gura_AssignMethod(wx_TextFile, GetLastLine);
	Gura_AssignMethod(wx_TextFile, GetLine);
	Gura_AssignMethod(wx_TextFile, GetLine_1);
	Gura_AssignMethod(wx_TextFile, GetLineCount);
	Gura_AssignMethod(wx_TextFile, GetLineType);
	Gura_AssignMethod(wx_TextFile, GetName);
	Gura_AssignMethod(wx_TextFile, GetNextLine);
	Gura_AssignMethod(wx_TextFile, GetPrevLine);
	Gura_AssignMethod(wx_TextFile, GoToLine);
	Gura_AssignMethod(wx_TextFile, GuessType);
	Gura_AssignMethod(wx_TextFile, InsertLine);
	Gura_AssignMethod(wx_TextFile, IsOpened);
	Gura_AssignMethod(wx_TextFile, Open);
	Gura_AssignMethod(wx_TextFile, Open_1);
	Gura_AssignMethod(wx_TextFile, RemoveLine);
	Gura_AssignMethod(wx_TextFile, Write);
}

Gura_ImplementDescendantCreator(wx_TextFile)
{
	return new Object_wx_TextFile((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
