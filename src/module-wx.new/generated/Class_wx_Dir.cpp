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
Gura_DeclareFunctionAlias(__Dir, "Dir")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Dir));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Dir)
{
	//wxDir();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Dir_1, "Dir_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Dir));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Dir_1)
{
	//const wxString& dir = arg.GetNumber(0)
	//wxDir(dir);
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dir, __Exists)
{
	Object_wx_Dir *pThis = Object_wx_Dir::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& dir = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->Exists(dir);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dir, __FindFirst, "FindFirst")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "dirname", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "filespec", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dir, __FindFirst)
{
	Object_wx_Dir *pThis = Object_wx_Dir::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& dirname = arg.GetNumber(0)
	//const wxString& filespec = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//wxString _rtn = pThis->GetEntity()->FindFirst(dirname, filespec, flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dir, __GetAllFiles, "GetAllFiles")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "dirname", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "files", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "filespec", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dir, __GetAllFiles)
{
	Object_wx_Dir *pThis = Object_wx_Dir::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& dirname = arg.GetNumber(0)
	//wxArrayString* files = arg.GetNumber(1)
	//const wxString& filespec = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//size_t _rtn = pThis->GetEntity()->GetAllFiles(dirname, files, filespec, flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dir, __GetFirst, "GetFirst")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "filespec", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dir, __GetFirst)
{
	Object_wx_Dir *pThis = Object_wx_Dir::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString* filename = arg.GetNumber(0)
	//const wxString& filespec = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//bool _rtn = pThis->GetEntity()->GetFirst(filename, filespec, flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dir, __GetName, "GetName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Dir, __GetName)
{
	Object_wx_Dir *pThis = Object_wx_Dir::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dir, __GetNameWithSep, "GetNameWithSep")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Dir, __GetNameWithSep)
{
	Object_wx_Dir *pThis = Object_wx_Dir::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetNameWithSep();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dir, __GetNext, "GetNext")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dir, __GetNext)
{
	Object_wx_Dir *pThis = Object_wx_Dir::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString* filename = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->GetNext(filename);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dir, __GetTotalSize, "GetTotalSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "filesSkipped", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dir, __GetTotalSize)
{
	Object_wx_Dir *pThis = Object_wx_Dir::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& dir = arg.GetNumber(0)
	//wxArrayString* filesSkipped = arg.GetNumber(1)
	//wxULongLong _rtn = pThis->GetEntity()->GetTotalSize(dir, filesSkipped);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dir, __HasFiles, "HasFiles")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "filespec", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dir, __HasFiles)
{
	Object_wx_Dir *pThis = Object_wx_Dir::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& filespec = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->HasFiles(filespec);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dir, __HasSubDirs, "HasSubDirs")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "dirspec", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dir, __HasSubDirs)
{
	Object_wx_Dir *pThis = Object_wx_Dir::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& dirspec = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->HasSubDirs(dirspec);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dir, __IsOpened, "IsOpened")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Dir, __IsOpened)
{
	Object_wx_Dir *pThis = Object_wx_Dir::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsOpened();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dir, __Make, "Make")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "perm", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dir, __Make)
{
	Object_wx_Dir *pThis = Object_wx_Dir::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& dir = arg.GetNumber(0)
	//int perm = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//bool _rtn = pThis->GetEntity()->Make(dir, perm, flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dir, __Open, "Open")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dir, __Open)
{
	Object_wx_Dir *pThis = Object_wx_Dir::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& dir = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->Open(dir);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dir, __Remove, "Remove")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dir, __Remove)
{
	Object_wx_Dir *pThis = Object_wx_Dir::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& dir = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->Remove(dir, flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dir, __Traverse, "Traverse")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "sink", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "filespec", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dir, __Traverse)
{
	Object_wx_Dir *pThis = Object_wx_Dir::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDirTraverser& sink = arg.GetNumber(0)
	//const wxString& filespec = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//size_t _rtn = pThis->GetEntity()->Traverse(sink, filespec, flags);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDir
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Dir)
{
	// Constructor assignment
	Gura_AssignFunction(__Dir);
	Gura_AssignFunction(__Dir_1);
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
