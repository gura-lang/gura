//----------------------------------------------------------------------------
// wxDir
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDir
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDir
//----------------------------------------------------------------------------
Object_wx_Dir::~Object_wx_Dir()
{
}

Object *Object_wx_Dir::Clone() const
{
	return nullptr;
}

String Object_wx_Dir::ToString(bool exprFlag)
{
	String rtn("<wx.Dir:");
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
Gura_DeclareMethod(wx_Dir, wxDir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Dir, wxDir)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dir *pThis = Object_wx_Dir::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxDir();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dir, wxDir_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dir, wxDir_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dir *pThis = Object_wx_Dir::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dir = arg.GetNumber(0)
	//pThis->GetEntity()->wxDir();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dir, ~wxDir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Dir, ~wxDir)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dir *pThis = Object_wx_Dir::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxDir();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dir, Close)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Dir, Close)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dir *pThis = Object_wx_Dir::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Close();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dir, Exists)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dir, Exists)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dir *pThis = Object_wx_Dir::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dir = arg.GetNumber(0)
	//pThis->GetEntity()->Exists();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dir, FindFirst)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dirname", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "filespec", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dir, FindFirst)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dir *pThis = Object_wx_Dir::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dirname = arg.GetNumber(0)
	//int filespec = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//pThis->GetEntity()->FindFirst();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dir, GetAllFiles)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dirname", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "files", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "filespec", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dir, GetAllFiles)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dir *pThis = Object_wx_Dir::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dirname = arg.GetNumber(0)
	//int files = arg.GetNumber(1)
	//int filespec = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//pThis->GetEntity()->GetAllFiles();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dir, GetFirst)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "filespec", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dir, GetFirst)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dir *pThis = Object_wx_Dir::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//int filespec = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//pThis->GetEntity()->GetFirst();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dir, GetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Dir, GetName)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dir *pThis = Object_wx_Dir::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dir, GetNameWithSep)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Dir, GetNameWithSep)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dir *pThis = Object_wx_Dir::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetNameWithSep();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dir, GetNext)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dir, GetNext)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dir *pThis = Object_wx_Dir::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//pThis->GetEntity()->GetNext();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dir, GetTotalSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "filesSkipped", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dir, GetTotalSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dir *pThis = Object_wx_Dir::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dir = arg.GetNumber(0)
	//int filesSkipped = arg.GetNumber(1)
	//pThis->GetEntity()->GetTotalSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dir, HasFiles)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filespec", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dir, HasFiles)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dir *pThis = Object_wx_Dir::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int filespec = arg.GetNumber(0)
	//pThis->GetEntity()->HasFiles();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dir, HasSubDirs)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dirspec", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dir, HasSubDirs)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dir *pThis = Object_wx_Dir::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dirspec = arg.GetNumber(0)
	//pThis->GetEntity()->HasSubDirs();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dir, IsOpened)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Dir, IsOpened)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dir *pThis = Object_wx_Dir::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsOpened();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dir, Make)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "perm", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dir, Make)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dir *pThis = Object_wx_Dir::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dir = arg.GetNumber(0)
	//int perm = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//pThis->GetEntity()->Make();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dir, Open)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dir, Open)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dir *pThis = Object_wx_Dir::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dir = arg.GetNumber(0)
	//pThis->GetEntity()->Open();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dir, Remove)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dir, Remove)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dir *pThis = Object_wx_Dir::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dir = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->Remove();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dir, Traverse)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sink", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "filespec", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dir, Traverse)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dir *pThis = Object_wx_Dir::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int sink = arg.GetNumber(0)
	//int filespec = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//pThis->GetEntity()->Traverse();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDir
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Dir)
{
	Gura_AssignMethod(wx_Dir, wxDir);
	Gura_AssignMethod(wx_Dir, wxDir_1);
	Gura_AssignMethod(wx_Dir, ~wxDir);
	Gura_AssignMethod(wx_Dir, Close);
	Gura_AssignMethod(wx_Dir, Exists);
	Gura_AssignMethod(wx_Dir, FindFirst);
	Gura_AssignMethod(wx_Dir, GetAllFiles);
	Gura_AssignMethod(wx_Dir, GetFirst);
	Gura_AssignMethod(wx_Dir, GetName);
	Gura_AssignMethod(wx_Dir, GetNameWithSep);
	Gura_AssignMethod(wx_Dir, GetNext);
	Gura_AssignMethod(wx_Dir, GetTotalSize);
	Gura_AssignMethod(wx_Dir, HasFiles);
	Gura_AssignMethod(wx_Dir, HasSubDirs);
	Gura_AssignMethod(wx_Dir, IsOpened);
	Gura_AssignMethod(wx_Dir, Make);
	Gura_AssignMethod(wx_Dir, Open);
	Gura_AssignMethod(wx_Dir, Remove);
	Gura_AssignMethod(wx_Dir, Traverse);
}

Gura_ImplementDescendantCreator(wx_Dir)
{
	return new Object_wx_Dir((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
