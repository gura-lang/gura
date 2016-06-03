//----------------------------------------------------------------------------
// wxFileCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFileCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFileCtrl
//----------------------------------------------------------------------------
Object_wx_FileCtrl::~Object_wx_FileCtrl()
{
}

Object *Object_wx_FileCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_FileCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.FileCtrl:");
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
Gura_DeclareFunctionAlias(__FileCtrl, "FileCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_FileCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__FileCtrl)
{
	//wxFileCtrl();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__FileCtrl_1, "FileCtrl_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defaultDirectory", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defaultFilename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wildCard", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_FileCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__FileCtrl_1)
{
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int defaultDirectory = arg.GetNumber(2)
	//int defaultFilename = arg.GetNumber(3)
	//int wildCard = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int pos = arg.GetNumber(6)
	//int size = arg.GetNumber(7)
	//int name = arg.GetNumber(8)
	//wxFileCtrl();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_FileCtrl, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defaultDirectory", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defaultFilename", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wildCard", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileCtrl, __Create)
{
	Object_wx_FileCtrl *pThis = Object_wx_FileCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int defaultDirectory = arg.GetNumber(2)
	//int defaultFilename = arg.GetNumber(3)
	//int wildCard = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int pos = arg.GetNumber(6)
	//int size = arg.GetNumber(7)
	//int name = arg.GetNumber(8)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileCtrl, __GetDirectory, "GetDirectory")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileCtrl, __GetDirectory)
{
	Object_wx_FileCtrl *pThis = Object_wx_FileCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDirectory();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileCtrl, __GetFilename, "GetFilename")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileCtrl, __GetFilename)
{
	Object_wx_FileCtrl *pThis = Object_wx_FileCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFilename();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileCtrl, __GetFilenames, "GetFilenames")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filenames", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileCtrl, __GetFilenames)
{
	Object_wx_FileCtrl *pThis = Object_wx_FileCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filenames = arg.GetNumber(0)
	//pThis->GetEntity()->GetFilenames();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileCtrl, __GetFilterIndex, "GetFilterIndex")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileCtrl, __GetFilterIndex)
{
	Object_wx_FileCtrl *pThis = Object_wx_FileCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFilterIndex();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileCtrl, __GetPath, "GetPath")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileCtrl, __GetPath)
{
	Object_wx_FileCtrl *pThis = Object_wx_FileCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPath();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileCtrl, __GetPaths, "GetPaths")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "paths", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileCtrl, __GetPaths)
{
	Object_wx_FileCtrl *pThis = Object_wx_FileCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int paths = arg.GetNumber(0)
	//pThis->GetEntity()->GetPaths();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileCtrl, __GetWildcard, "GetWildcard")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileCtrl, __GetWildcard)
{
	Object_wx_FileCtrl *pThis = Object_wx_FileCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWildcard();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileCtrl, __SetDirectory, "SetDirectory")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "directory", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileCtrl, __SetDirectory)
{
	Object_wx_FileCtrl *pThis = Object_wx_FileCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int directory = arg.GetNumber(0)
	//pThis->GetEntity()->SetDirectory();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileCtrl, __SetFilename, "SetFilename")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileCtrl, __SetFilename)
{
	Object_wx_FileCtrl *pThis = Object_wx_FileCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//pThis->GetEntity()->SetFilename();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileCtrl, __SetPath, "SetPath")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileCtrl, __SetPath)
{
	Object_wx_FileCtrl *pThis = Object_wx_FileCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int path = arg.GetNumber(0)
	//pThis->GetEntity()->SetPath();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileCtrl, __SetFilterIndex, "SetFilterIndex")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filterIndex", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileCtrl, __SetFilterIndex)
{
	Object_wx_FileCtrl *pThis = Object_wx_FileCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filterIndex = arg.GetNumber(0)
	//pThis->GetEntity()->SetFilterIndex();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileCtrl, __SetWildcard, "SetWildcard")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "wildCard", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileCtrl, __SetWildcard)
{
	Object_wx_FileCtrl *pThis = Object_wx_FileCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int wildCard = arg.GetNumber(0)
	//pThis->GetEntity()->SetWildcard();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileCtrl, __ShowHidden, "ShowHidden")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "show", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileCtrl, __ShowHidden)
{
	Object_wx_FileCtrl *pThis = Object_wx_FileCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int show = arg.GetNumber(0)
	//pThis->GetEntity()->ShowHidden();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFileCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileCtrl)
{
	// Constructor assignment
	Gura_AssignFunction(__FileCtrl);
	Gura_AssignFunction(__FileCtrl_1);
	// Method assignment
	Gura_AssignMethod(wx_FileCtrl, __Create);
	Gura_AssignMethod(wx_FileCtrl, __GetDirectory);
	Gura_AssignMethod(wx_FileCtrl, __GetFilename);
	Gura_AssignMethod(wx_FileCtrl, __GetFilenames);
	Gura_AssignMethod(wx_FileCtrl, __GetFilterIndex);
	Gura_AssignMethod(wx_FileCtrl, __GetPath);
	Gura_AssignMethod(wx_FileCtrl, __GetPaths);
	Gura_AssignMethod(wx_FileCtrl, __GetWildcard);
	Gura_AssignMethod(wx_FileCtrl, __SetDirectory);
	Gura_AssignMethod(wx_FileCtrl, __SetFilename);
	Gura_AssignMethod(wx_FileCtrl, __SetPath);
	Gura_AssignMethod(wx_FileCtrl, __SetFilterIndex);
	Gura_AssignMethod(wx_FileCtrl, __SetWildcard);
	Gura_AssignMethod(wx_FileCtrl, __ShowHidden);
}

Gura_ImplementDescendantCreator(wx_FileCtrl)
{
	return new Object_wx_FileCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
