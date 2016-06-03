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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxDir, "wxDir")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Dir));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxDir)
{
	//wxDir();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxDir_1, "wxDir_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Dir));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxDir_1)
{
	//int dir = arg.GetNumber(0)
	//wxDir();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Dir, __Close, "Close")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Dir, __Close)
{
	Object_wx_Dir *pThis = Object_wx_Dir::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Close();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dir, __Exists, "Exists")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dir, __Exists)
{
	Object_wx_Dir *pThis = Object_wx_Dir::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dir = arg.GetNumber(0)
	//pThis->GetEntity()->Exists();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dir, __FindFirst, "FindFirst")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dirname", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "filespec", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dir, __FindFirst)
{
	Object_wx_Dir *pThis = Object_wx_Dir::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dirname = arg.GetNumber(0)
	//int filespec = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//pThis->GetEntity()->FindFirst();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dir, __GetAllFiles, "GetAllFiles")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dirname", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "files", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "filespec", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dir, __GetAllFiles)
{
	Object_wx_Dir *pThis = Object_wx_Dir::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dirname = arg.GetNumber(0)
	//int files = arg.GetNumber(1)
	//int filespec = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//pThis->GetEntity()->GetAllFiles();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dir, __GetFirst, "GetFirst")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "filespec", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dir, __GetFirst)
{
	Object_wx_Dir *pThis = Object_wx_Dir::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//int filespec = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//pThis->GetEntity()->GetFirst();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dir, __GetName, "GetName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Dir, __GetName)
{
	Object_wx_Dir *pThis = Object_wx_Dir::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dir, __GetNameWithSep, "GetNameWithSep")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Dir, __GetNameWithSep)
{
	Object_wx_Dir *pThis = Object_wx_Dir::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetNameWithSep();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dir, __GetNext, "GetNext")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dir, __GetNext)
{
	Object_wx_Dir *pThis = Object_wx_Dir::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//pThis->GetEntity()->GetNext();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dir, __GetTotalSize, "GetTotalSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "filesSkipped", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dir, __GetTotalSize)
{
	Object_wx_Dir *pThis = Object_wx_Dir::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dir = arg.GetNumber(0)
	//int filesSkipped = arg.GetNumber(1)
	//pThis->GetEntity()->GetTotalSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dir, __HasFiles, "HasFiles")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filespec", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dir, __HasFiles)
{
	Object_wx_Dir *pThis = Object_wx_Dir::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filespec = arg.GetNumber(0)
	//pThis->GetEntity()->HasFiles();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dir, __HasSubDirs, "HasSubDirs")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dirspec", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dir, __HasSubDirs)
{
	Object_wx_Dir *pThis = Object_wx_Dir::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dirspec = arg.GetNumber(0)
	//pThis->GetEntity()->HasSubDirs();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dir, __IsOpened, "IsOpened")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Dir, __IsOpened)
{
	Object_wx_Dir *pThis = Object_wx_Dir::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOpened();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dir, __Make, "Make")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "perm", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dir, __Make)
{
	Object_wx_Dir *pThis = Object_wx_Dir::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dir = arg.GetNumber(0)
	//int perm = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//pThis->GetEntity()->Make();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dir, __Open, "Open")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dir, __Open)
{
	Object_wx_Dir *pThis = Object_wx_Dir::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dir = arg.GetNumber(0)
	//pThis->GetEntity()->Open();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dir, __Remove, "Remove")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dir, __Remove)
{
	Object_wx_Dir *pThis = Object_wx_Dir::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dir = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->Remove();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dir, __Traverse, "Traverse")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sink", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "filespec", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dir, __Traverse)
{
	Object_wx_Dir *pThis = Object_wx_Dir::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
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
	// Constructor assignment
	Gura_AssignFunction(__wxDir);
	Gura_AssignFunction(__wxDir_1);
	// Method assignment
	Gura_AssignMethod(wx_Dir, __Close);
	Gura_AssignMethod(wx_Dir, __Exists);
	Gura_AssignMethod(wx_Dir, __FindFirst);
	Gura_AssignMethod(wx_Dir, __GetAllFiles);
	Gura_AssignMethod(wx_Dir, __GetFirst);
	Gura_AssignMethod(wx_Dir, __GetName);
	Gura_AssignMethod(wx_Dir, __GetNameWithSep);
	Gura_AssignMethod(wx_Dir, __GetNext);
	Gura_AssignMethod(wx_Dir, __GetTotalSize);
	Gura_AssignMethod(wx_Dir, __HasFiles);
	Gura_AssignMethod(wx_Dir, __HasSubDirs);
	Gura_AssignMethod(wx_Dir, __IsOpened);
	Gura_AssignMethod(wx_Dir, __Make);
	Gura_AssignMethod(wx_Dir, __Open);
	Gura_AssignMethod(wx_Dir, __Remove);
	Gura_AssignMethod(wx_Dir, __Traverse);
}

Gura_ImplementDescendantCreator(wx_Dir)
{
	return new Object_wx_Dir((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
