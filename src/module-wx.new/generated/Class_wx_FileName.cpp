//----------------------------------------------------------------------------
// wxFileName
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFileName
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFileName
//----------------------------------------------------------------------------
Object_wx_FileName::~Object_wx_FileName()
{
}

Object *Object_wx_FileName::Clone() const
{
	return nullptr;
}

String Object_wx_FileName::ToString(bool exprFlag)
{
	String rtn("<wx.FileName:");
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
Gura_DeclareMethod(wx_FileName, wxFileName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, wxFileName)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxFileName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, wxFileName_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, wxFileName_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//pThis->GetEntity()->wxFileName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, wxFileName_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fullpath", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, wxFileName_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int fullpath = arg.GetNumber(0)
	//int format = arg.GetNumber(1)
	//pThis->GetEntity()->wxFileName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, wxFileName_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, wxFileName_3)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int path = arg.GetNumber(0)
	//int name = arg.GetNumber(1)
	//int format = arg.GetNumber(2)
	//pThis->GetEntity()->wxFileName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, wxFileName_4)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ext", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, wxFileName_4)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int path = arg.GetNumber(0)
	//int name = arg.GetNumber(1)
	//int ext = arg.GetNumber(2)
	//int format = arg.GetNumber(3)
	//pThis->GetEntity()->wxFileName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, wxFileName_5)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "volume", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ext", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, wxFileName_5)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int volume = arg.GetNumber(0)
	//int path = arg.GetNumber(1)
	//int name = arg.GetNumber(2)
	//int ext = arg.GetNumber(3)
	//int format = arg.GetNumber(4)
	//pThis->GetEntity()->wxFileName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, AppendDir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, AppendDir)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dir = arg.GetNumber(0)
	//pThis->GetEntity()->AppendDir();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, Assign)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filepath", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, Assign)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int filepath = arg.GetNumber(0)
	//pThis->GetEntity()->Assign();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, Assign_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fullpath", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, Assign_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int fullpath = arg.GetNumber(0)
	//int format = arg.GetNumber(1)
	//pThis->GetEntity()->Assign();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, Assign_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "volume", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ext", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "hasExt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, Assign_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int volume = arg.GetNumber(0)
	//int path = arg.GetNumber(1)
	//int name = arg.GetNumber(2)
	//int ext = arg.GetNumber(3)
	//int hasExt = arg.GetNumber(4)
	//int format = arg.GetNumber(5)
	//pThis->GetEntity()->Assign();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, Assign_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "volume", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ext", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, Assign_3)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int volume = arg.GetNumber(0)
	//int path = arg.GetNumber(1)
	//int name = arg.GetNumber(2)
	//int ext = arg.GetNumber(3)
	//int format = arg.GetNumber(4)
	//pThis->GetEntity()->Assign();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, Assign_4)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, Assign_4)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int path = arg.GetNumber(0)
	//int name = arg.GetNumber(1)
	//int format = arg.GetNumber(2)
	//pThis->GetEntity()->Assign();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, Assign_5)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ext", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, Assign_5)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int path = arg.GetNumber(0)
	//int name = arg.GetNumber(1)
	//int ext = arg.GetNumber(2)
	//int format = arg.GetNumber(3)
	//pThis->GetEntity()->Assign();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, AssignCwd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "volume", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, AssignCwd)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int volume = arg.GetNumber(0)
	//pThis->GetEntity()->AssignCwd();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, AssignDir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, AssignDir)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dir = arg.GetNumber(0)
	//int format = arg.GetNumber(1)
	//pThis->GetEntity()->AssignDir();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, AssignHomeDir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, AssignHomeDir)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->AssignHomeDir();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, AssignTempFileName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "prefix", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, AssignTempFileName)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int prefix = arg.GetNumber(0)
	//pThis->GetEntity()->AssignTempFileName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, AssignTempFileName_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "prefix", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fileTemp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, AssignTempFileName_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int prefix = arg.GetNumber(0)
	//int fileTemp = arg.GetNumber(1)
	//pThis->GetEntity()->AssignTempFileName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, AssignTempFileName_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "prefix", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fileTemp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, AssignTempFileName_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int prefix = arg.GetNumber(0)
	//int fileTemp = arg.GetNumber(1)
	//pThis->GetEntity()->AssignTempFileName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, Clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, Clear)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, ClearExt)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, ClearExt)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->ClearExt();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, CreateTempFileName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "prefix", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fileTemp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, CreateTempFileName)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int prefix = arg.GetNumber(0)
	//int fileTemp = arg.GetNumber(1)
	//pThis->GetEntity()->CreateTempFileName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, CreateTempFileName_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "prefix", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fileTemp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, CreateTempFileName_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int prefix = arg.GetNumber(0)
	//int fileTemp = arg.GetNumber(1)
	//pThis->GetEntity()->CreateTempFileName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, DirExists)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, DirExists)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->DirExists();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, DirExists_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, DirExists_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dir = arg.GetNumber(0)
	//pThis->GetEntity()->DirExists();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, DirName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, DirName)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dir = arg.GetNumber(0)
	//int format = arg.GetNumber(1)
	//pThis->GetEntity()->DirName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, DontFollowLink)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, DontFollowLink)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->DontFollowLink();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, Exists)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, Exists)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->Exists();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, Exists_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, Exists_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int path = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->Exists();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, FileExists)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, FileExists)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->FileExists();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, FileExists_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "file", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, FileExists_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int file = arg.GetNumber(0)
	//pThis->GetEntity()->FileExists();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, FileName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "file", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, FileName)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int file = arg.GetNumber(0)
	//int format = arg.GetNumber(1)
	//pThis->GetEntity()->FileName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, GetCwd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "volume", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, GetCwd)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int volume = arg.GetNumber(0)
	//pThis->GetEntity()->GetCwd();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, GetDirCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, GetDirCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetDirCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, GetDirs)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, GetDirs)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetDirs();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, GetExt)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, GetExt)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetExt();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, GetForbiddenChars)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, GetForbiddenChars)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int format = arg.GetNumber(0)
	//pThis->GetEntity()->GetForbiddenChars();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, GetFormat)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, GetFormat)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int format = arg.GetNumber(0)
	//pThis->GetEntity()->GetFormat();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, GetFullName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, GetFullName)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFullName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, GetFullPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, GetFullPath)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int format = arg.GetNumber(0)
	//pThis->GetEntity()->GetFullPath();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, GetHomeDir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, GetHomeDir)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetHomeDir();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, GetHumanReadableSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "failmsg", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "precision", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, GetHumanReadableSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int failmsg = arg.GetNumber(0)
	//int precision = arg.GetNumber(1)
	//int conv = arg.GetNumber(2)
	//pThis->GetEntity()->GetHumanReadableSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, GetHumanReadableSize_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bytes", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nullsize", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "precision", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "conv", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, GetHumanReadableSize_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int bytes = arg.GetNumber(0)
	//int nullsize = arg.GetNumber(1)
	//int precision = arg.GetNumber(2)
	//int conv = arg.GetNumber(3)
	//pThis->GetEntity()->GetHumanReadableSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, GetLongPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, GetLongPath)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetLongPath();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, GetModificationTime)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, GetModificationTime)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetModificationTime();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, GetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, GetName)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, GetPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, GetPath)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//int format = arg.GetNumber(1)
	//pThis->GetEntity()->GetPath();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, GetPathSeparator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, GetPathSeparator)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int format = arg.GetNumber(0)
	//pThis->GetEntity()->GetPathSeparator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, GetPathSeparators)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, GetPathSeparators)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int format = arg.GetNumber(0)
	//pThis->GetEntity()->GetPathSeparators();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, GetPathTerminators)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, GetPathTerminators)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int format = arg.GetNumber(0)
	//pThis->GetEntity()->GetPathTerminators();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, GetPathWithSep)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, GetPathWithSep)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int format = arg.GetNumber(0)
	//pThis->GetEntity()->GetPathWithSep();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, GetShortPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, GetShortPath)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetShortPath();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, GetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, GetSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, GetSize_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, GetSize_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//pThis->GetEntity()->GetSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, GetTempDir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, GetTempDir)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetTempDir();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, GetTimes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dtAccess", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dtMod", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dtCreate", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, GetTimes)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dtAccess = arg.GetNumber(0)
	//int dtMod = arg.GetNumber(1)
	//int dtCreate = arg.GetNumber(2)
	//pThis->GetEntity()->GetTimes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, GetVolume)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, GetVolume)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetVolume();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, GetVolumeSeparator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, GetVolumeSeparator)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int format = arg.GetNumber(0)
	//pThis->GetEntity()->GetVolumeSeparator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, GetVolumeString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "drive", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, GetVolumeString)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int drive = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->GetVolumeString();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, HasExt)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, HasExt)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasExt();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, HasName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, HasName)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, HasVolume)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, HasVolume)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasVolume();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, InsertDir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "before", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, InsertDir)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int before = arg.GetNumber(0)
	//int dir = arg.GetNumber(1)
	//pThis->GetEntity()->InsertDir();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, IsAbsolute)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, IsAbsolute)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int format = arg.GetNumber(0)
	//pThis->GetEntity()->IsAbsolute();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, IsCaseSensitive)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, IsCaseSensitive)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int format = arg.GetNumber(0)
	//pThis->GetEntity()->IsCaseSensitive();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, IsDir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, IsDir)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsDir();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, IsDirReadable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, IsDirReadable)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsDirReadable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, IsDirReadable_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, IsDirReadable_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dir = arg.GetNumber(0)
	//pThis->GetEntity()->IsDirReadable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, IsDirWritable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, IsDirWritable)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsDirWritable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, IsDirWritable_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, IsDirWritable_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dir = arg.GetNumber(0)
	//pThis->GetEntity()->IsDirWritable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, IsFileExecutable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, IsFileExecutable)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsFileExecutable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, IsFileExecutable_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "file", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, IsFileExecutable_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int file = arg.GetNumber(0)
	//pThis->GetEntity()->IsFileExecutable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, IsFileReadable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, IsFileReadable)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsFileReadable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, IsFileReadable_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "file", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, IsFileReadable_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int file = arg.GetNumber(0)
	//pThis->GetEntity()->IsFileReadable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, IsFileWritable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, IsFileWritable)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsFileWritable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, IsFileWritable_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "file", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, IsFileWritable_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int file = arg.GetNumber(0)
	//pThis->GetEntity()->IsFileWritable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, IsOk)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, IsPathSeparator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ch", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, IsPathSeparator)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int ch = arg.GetNumber(0)
	//int format = arg.GetNumber(1)
	//pThis->GetEntity()->IsPathSeparator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, IsMSWUniqueVolumeNamePath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, IsMSWUniqueVolumeNamePath)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int path = arg.GetNumber(0)
	//int format = arg.GetNumber(1)
	//pThis->GetEntity()->IsMSWUniqueVolumeNamePath();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, IsRelative)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, IsRelative)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int format = arg.GetNumber(0)
	//pThis->GetEntity()->IsRelative();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, MakeAbsolute)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cwd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, MakeAbsolute)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int cwd = arg.GetNumber(0)
	//int format = arg.GetNumber(1)
	//pThis->GetEntity()->MakeAbsolute();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, MakeRelativeTo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pathBase", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, MakeRelativeTo)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pathBase = arg.GetNumber(0)
	//int format = arg.GetNumber(1)
	//pThis->GetEntity()->MakeRelativeTo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, Mkdir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "perm", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, Mkdir)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int perm = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->Mkdir();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, Mkdir_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "perm", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, Mkdir_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dir = arg.GetNumber(0)
	//int perm = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//pThis->GetEntity()->Mkdir();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, Normalize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "cwd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, Normalize)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//int cwd = arg.GetNumber(1)
	//int format = arg.GetNumber(2)
	//pThis->GetEntity()->Normalize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, PrependDir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, PrependDir)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dir = arg.GetNumber(0)
	//pThis->GetEntity()->PrependDir();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, RemoveDir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, RemoveDir)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveDir();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, RemoveLastDir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, RemoveLastDir)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->RemoveLastDir();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, ReplaceEnvVariable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "envname", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "replacementFmtString", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, ReplaceEnvVariable)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int envname = arg.GetNumber(0)
	//int replacementFmtString = arg.GetNumber(1)
	//int format = arg.GetNumber(2)
	//pThis->GetEntity()->ReplaceEnvVariable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, ReplaceHomeDir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, ReplaceHomeDir)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int format = arg.GetNumber(0)
	//pThis->GetEntity()->ReplaceHomeDir();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, Rmdir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, Rmdir)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->Rmdir();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, Rmdir_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, Rmdir_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dir = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->Rmdir();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, SameAs)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filepath", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, SameAs)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int filepath = arg.GetNumber(0)
	//int format = arg.GetNumber(1)
	//pThis->GetEntity()->SameAs();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, SetCwd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, SetCwd)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->SetCwd();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, SetCwd_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cwd", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, SetCwd_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int cwd = arg.GetNumber(0)
	//pThis->GetEntity()->SetCwd();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, SetEmptyExt)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, SetEmptyExt)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->SetEmptyExt();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, SetExt)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ext", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, SetExt)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int ext = arg.GetNumber(0)
	//pThis->GetEntity()->SetExt();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, SetFullName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fullname", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, SetFullName)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int fullname = arg.GetNumber(0)
	//pThis->GetEntity()->SetFullName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, SetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, SetName)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->SetName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, SetPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, SetPath)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int path = arg.GetNumber(0)
	//int format = arg.GetNumber(1)
	//pThis->GetEntity()->SetPath();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, SetPermissions)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "permissions", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, SetPermissions)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int permissions = arg.GetNumber(0)
	//pThis->GetEntity()->SetPermissions();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, SetTimes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dtAccess", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dtMod", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dtCreate", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, SetTimes)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dtAccess = arg.GetNumber(0)
	//int dtMod = arg.GetNumber(1)
	//int dtCreate = arg.GetNumber(2)
	//pThis->GetEntity()->SetTimes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, SetVolume)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "volume", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, SetVolume)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int volume = arg.GetNumber(0)
	//pThis->GetEntity()->SetVolume();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, ShouldFollowLink)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, ShouldFollowLink)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->ShouldFollowLink();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, SplitPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fullpath", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "volume", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ext", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "hasExt", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, SplitPath)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int fullpath = arg.GetNumber(0)
	//int volume = arg.GetNumber(1)
	//int path = arg.GetNumber(2)
	//int name = arg.GetNumber(3)
	//int ext = arg.GetNumber(4)
	//int hasExt = arg.GetNumber(5)
	//int format = arg.GetNumber(6)
	//pThis->GetEntity()->SplitPath();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, SplitPath_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fullpath", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "volume", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ext", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, SplitPath_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int fullpath = arg.GetNumber(0)
	//int volume = arg.GetNumber(1)
	//int path = arg.GetNumber(2)
	//int name = arg.GetNumber(3)
	//int ext = arg.GetNumber(4)
	//int format = arg.GetNumber(5)
	//pThis->GetEntity()->SplitPath();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, SplitPath_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fullpath", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ext", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, SplitPath_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int fullpath = arg.GetNumber(0)
	//int path = arg.GetNumber(1)
	//int name = arg.GetNumber(2)
	//int ext = arg.GetNumber(3)
	//int format = arg.GetNumber(4)
	//pThis->GetEntity()->SplitPath();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, SplitVolume)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fullpath", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "volume", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, SplitVolume)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int fullpath = arg.GetNumber(0)
	//int volume = arg.GetNumber(1)
	//int path = arg.GetNumber(2)
	//int format = arg.GetNumber(3)
	//pThis->GetEntity()->SplitVolume();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, StripExtension)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "fullname", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileName, StripExtension)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int fullname = arg.GetNumber(0)
	//pThis->GetEntity()->StripExtension();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileName, Touch)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileName, Touch)
{
	Signal &sig = env.GetSignal();
	Object_wx_FileName *pThis = Object_wx_FileName::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Touch();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFileName
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileName)
{
	Gura_AssignMethod(wx_FileName, wxFileName);
	Gura_AssignMethod(wx_FileName, wxFileName_1);
	Gura_AssignMethod(wx_FileName, wxFileName_2);
	Gura_AssignMethod(wx_FileName, wxFileName_3);
	Gura_AssignMethod(wx_FileName, wxFileName_4);
	Gura_AssignMethod(wx_FileName, wxFileName_5);
	Gura_AssignMethod(wx_FileName, AppendDir);
	Gura_AssignMethod(wx_FileName, Assign);
	Gura_AssignMethod(wx_FileName, Assign_1);
	Gura_AssignMethod(wx_FileName, Assign_2);
	Gura_AssignMethod(wx_FileName, Assign_3);
	Gura_AssignMethod(wx_FileName, Assign_4);
	Gura_AssignMethod(wx_FileName, Assign_5);
	Gura_AssignMethod(wx_FileName, AssignCwd);
	Gura_AssignMethod(wx_FileName, AssignDir);
	Gura_AssignMethod(wx_FileName, AssignHomeDir);
	Gura_AssignMethod(wx_FileName, AssignTempFileName);
	Gura_AssignMethod(wx_FileName, AssignTempFileName_1);
	Gura_AssignMethod(wx_FileName, AssignTempFileName_2);
	Gura_AssignMethod(wx_FileName, Clear);
	Gura_AssignMethod(wx_FileName, ClearExt);
	Gura_AssignMethod(wx_FileName, CreateTempFileName);
	Gura_AssignMethod(wx_FileName, CreateTempFileName_1);
	Gura_AssignMethod(wx_FileName, DirExists);
	Gura_AssignMethod(wx_FileName, DirExists_1);
	Gura_AssignMethod(wx_FileName, DirName);
	Gura_AssignMethod(wx_FileName, DontFollowLink);
	Gura_AssignMethod(wx_FileName, Exists);
	Gura_AssignMethod(wx_FileName, Exists_1);
	Gura_AssignMethod(wx_FileName, FileExists);
	Gura_AssignMethod(wx_FileName, FileExists_1);
	Gura_AssignMethod(wx_FileName, FileName);
	Gura_AssignMethod(wx_FileName, GetCwd);
	Gura_AssignMethod(wx_FileName, GetDirCount);
	Gura_AssignMethod(wx_FileName, GetDirs);
	Gura_AssignMethod(wx_FileName, GetExt);
	Gura_AssignMethod(wx_FileName, GetForbiddenChars);
	Gura_AssignMethod(wx_FileName, GetFormat);
	Gura_AssignMethod(wx_FileName, GetFullName);
	Gura_AssignMethod(wx_FileName, GetFullPath);
	Gura_AssignMethod(wx_FileName, GetHomeDir);
	Gura_AssignMethod(wx_FileName, GetHumanReadableSize);
	Gura_AssignMethod(wx_FileName, GetHumanReadableSize_1);
	Gura_AssignMethod(wx_FileName, GetLongPath);
	Gura_AssignMethod(wx_FileName, GetModificationTime);
	Gura_AssignMethod(wx_FileName, GetName);
	Gura_AssignMethod(wx_FileName, GetPath);
	Gura_AssignMethod(wx_FileName, GetPathSeparator);
	Gura_AssignMethod(wx_FileName, GetPathSeparators);
	Gura_AssignMethod(wx_FileName, GetPathTerminators);
	Gura_AssignMethod(wx_FileName, GetPathWithSep);
	Gura_AssignMethod(wx_FileName, GetShortPath);
	Gura_AssignMethod(wx_FileName, GetSize);
	Gura_AssignMethod(wx_FileName, GetSize_1);
	Gura_AssignMethod(wx_FileName, GetTempDir);
	Gura_AssignMethod(wx_FileName, GetTimes);
	Gura_AssignMethod(wx_FileName, GetVolume);
	Gura_AssignMethod(wx_FileName, GetVolumeSeparator);
	Gura_AssignMethod(wx_FileName, GetVolumeString);
	Gura_AssignMethod(wx_FileName, HasExt);
	Gura_AssignMethod(wx_FileName, HasName);
	Gura_AssignMethod(wx_FileName, HasVolume);
	Gura_AssignMethod(wx_FileName, InsertDir);
	Gura_AssignMethod(wx_FileName, IsAbsolute);
	Gura_AssignMethod(wx_FileName, IsCaseSensitive);
	Gura_AssignMethod(wx_FileName, IsDir);
	Gura_AssignMethod(wx_FileName, IsDirReadable);
	Gura_AssignMethod(wx_FileName, IsDirReadable_1);
	Gura_AssignMethod(wx_FileName, IsDirWritable);
	Gura_AssignMethod(wx_FileName, IsDirWritable_1);
	Gura_AssignMethod(wx_FileName, IsFileExecutable);
	Gura_AssignMethod(wx_FileName, IsFileExecutable_1);
	Gura_AssignMethod(wx_FileName, IsFileReadable);
	Gura_AssignMethod(wx_FileName, IsFileReadable_1);
	Gura_AssignMethod(wx_FileName, IsFileWritable);
	Gura_AssignMethod(wx_FileName, IsFileWritable_1);
	Gura_AssignMethod(wx_FileName, IsOk);
	Gura_AssignMethod(wx_FileName, IsPathSeparator);
	Gura_AssignMethod(wx_FileName, IsMSWUniqueVolumeNamePath);
	Gura_AssignMethod(wx_FileName, IsRelative);
	Gura_AssignMethod(wx_FileName, MakeAbsolute);
	Gura_AssignMethod(wx_FileName, MakeRelativeTo);
	Gura_AssignMethod(wx_FileName, Mkdir);
	Gura_AssignMethod(wx_FileName, Mkdir_1);
	Gura_AssignMethod(wx_FileName, Normalize);
	Gura_AssignMethod(wx_FileName, PrependDir);
	Gura_AssignMethod(wx_FileName, RemoveDir);
	Gura_AssignMethod(wx_FileName, RemoveLastDir);
	Gura_AssignMethod(wx_FileName, ReplaceEnvVariable);
	Gura_AssignMethod(wx_FileName, ReplaceHomeDir);
	Gura_AssignMethod(wx_FileName, Rmdir);
	Gura_AssignMethod(wx_FileName, Rmdir_1);
	Gura_AssignMethod(wx_FileName, SameAs);
	Gura_AssignMethod(wx_FileName, SetCwd);
	Gura_AssignMethod(wx_FileName, SetCwd_1);
	Gura_AssignMethod(wx_FileName, SetEmptyExt);
	Gura_AssignMethod(wx_FileName, SetExt);
	Gura_AssignMethod(wx_FileName, SetFullName);
	Gura_AssignMethod(wx_FileName, SetName);
	Gura_AssignMethod(wx_FileName, SetPath);
	Gura_AssignMethod(wx_FileName, SetPermissions);
	Gura_AssignMethod(wx_FileName, SetTimes);
	Gura_AssignMethod(wx_FileName, SetVolume);
	Gura_AssignMethod(wx_FileName, ShouldFollowLink);
	Gura_AssignMethod(wx_FileName, SplitPath);
	Gura_AssignMethod(wx_FileName, SplitPath_1);
	Gura_AssignMethod(wx_FileName, SplitPath_2);
	Gura_AssignMethod(wx_FileName, SplitVolume);
	Gura_AssignMethod(wx_FileName, StripExtension);
	Gura_AssignMethod(wx_FileName, Touch);
}

Gura_ImplementDescendantCreator(wx_FileName)
{
	return new Object_wx_FileName((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
