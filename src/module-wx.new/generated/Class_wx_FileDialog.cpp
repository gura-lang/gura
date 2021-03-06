//----------------------------------------------------------------------------
// wxFileDialog
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFileDialog
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFileDialog
//----------------------------------------------------------------------------
Object_wx_FileDialog::~Object_wx_FileDialog()
{
}

Object *Object_wx_FileDialog::Clone() const
{
	return nullptr;
}

String Object_wx_FileDialog::ToString(bool exprFlag)
{
	String rtn("<wx.FileDialog:");
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
Gura_DeclareFunctionAlias(__FileDialog, "FileDialog")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "message", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defaultDir", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defaultFile", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wildcard", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_FileDialog));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__FileDialog)
{
	//wxWindow* parent = arg.GetNumber(0)
	//const wxString& message = arg.GetNumber(1)
	//const wxString& defaultDir = arg.GetNumber(2)
	//const wxString& defaultFile = arg.GetNumber(3)
	//const wxString& wildcard = arg.GetNumber(4)
	//long style = arg.GetNumber(5)
	//const wxPoint& pos = arg.GetNumber(6)
	//const wxSize& size = arg.GetNumber(7)
	//const wxString& name = arg.GetNumber(8)
	//wxFileDialog(parent, message, defaultDir, defaultFile, wildcard, style, pos, size, name);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_FileDialog, __GetCurrentlySelectedFilename, "GetCurrentlySelectedFilename")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_FileDialog, __GetCurrentlySelectedFilename)
{
	Object_wx_FileDialog *pThis = Object_wx_FileDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetCurrentlySelectedFilename();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileDialog, __GetDirectory, "GetDirectory")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_FileDialog, __GetDirectory)
{
	Object_wx_FileDialog *pThis = Object_wx_FileDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetDirectory();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileDialog, __GetExtraControl, "GetExtraControl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_FileDialog, __GetExtraControl)
{
	Object_wx_FileDialog *pThis = Object_wx_FileDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* _rtn = pThis->GetEntity()->GetExtraControl();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileDialog, __GetFilename, "GetFilename")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_FileDialog, __GetFilename)
{
	Object_wx_FileDialog *pThis = Object_wx_FileDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetFilename();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileDialog, __GetFilenames, "GetFilenames")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filenames", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileDialog, __GetFilenames)
{
	Object_wx_FileDialog *pThis = Object_wx_FileDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxArrayString& filenames = arg.GetNumber(0)
	//pThis->GetEntity()->GetFilenames(filenames);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileDialog, __GetFilterIndex, "GetFilterIndex")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_FileDialog, __GetFilterIndex)
{
	Object_wx_FileDialog *pThis = Object_wx_FileDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetFilterIndex();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileDialog, __GetMessage, "GetMessage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_FileDialog, __GetMessage)
{
	Object_wx_FileDialog *pThis = Object_wx_FileDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetMessage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileDialog, __GetPath, "GetPath")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_FileDialog, __GetPath)
{
	Object_wx_FileDialog *pThis = Object_wx_FileDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetPath();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileDialog, __GetPaths, "GetPaths")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "paths", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileDialog, __GetPaths)
{
	Object_wx_FileDialog *pThis = Object_wx_FileDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxArrayString& paths = arg.GetNumber(0)
	//pThis->GetEntity()->GetPaths(paths);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileDialog, __GetWildcard, "GetWildcard")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_FileDialog, __GetWildcard)
{
	Object_wx_FileDialog *pThis = Object_wx_FileDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetWildcard();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileDialog, __SetDirectory, "SetDirectory")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "directory", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileDialog, __SetDirectory)
{
	Object_wx_FileDialog *pThis = Object_wx_FileDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& directory = arg.GetNumber(0)
	//pThis->GetEntity()->SetDirectory(directory);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileDialog, __SetExtraControlCreator, "SetExtraControlCreator")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "creator", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileDialog, __SetExtraControlCreator)
{
	Object_wx_FileDialog *pThis = Object_wx_FileDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//ExtraControlCreatorFunction creator = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->SetExtraControlCreator(creator);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileDialog, __SetFilename, "SetFilename")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "setfilename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileDialog, __SetFilename)
{
	Object_wx_FileDialog *pThis = Object_wx_FileDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& setfilename = arg.GetNumber(0)
	//pThis->GetEntity()->SetFilename(setfilename);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileDialog, __SetFilterIndex, "SetFilterIndex")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filterIndex", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileDialog, __SetFilterIndex)
{
	Object_wx_FileDialog *pThis = Object_wx_FileDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filterIndex = arg.GetNumber(0)
	//pThis->GetEntity()->SetFilterIndex(filterIndex);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileDialog, __SetMessage, "SetMessage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "message", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileDialog, __SetMessage)
{
	Object_wx_FileDialog *pThis = Object_wx_FileDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& message = arg.GetNumber(0)
	//pThis->GetEntity()->SetMessage(message);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileDialog, __SetPath, "SetPath")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileDialog, __SetPath)
{
	Object_wx_FileDialog *pThis = Object_wx_FileDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& path = arg.GetNumber(0)
	//pThis->GetEntity()->SetPath(path);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileDialog, __SetWildcard, "SetWildcard")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "wildCard", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileDialog, __SetWildcard)
{
	Object_wx_FileDialog *pThis = Object_wx_FileDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& wildCard = arg.GetNumber(0)
	//pThis->GetEntity()->SetWildcard(wildCard);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_FileDialog, __ShowModal, "ShowModal")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_FileDialog, __ShowModal)
{
	Object_wx_FileDialog *pThis = Object_wx_FileDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->ShowModal();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFileDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileDialog)
{
	// Constructor assignment
	Gura_AssignFunction(__FileDialog);
	// Method assignment
	Gura_AssignMethod(wx_FileDialog, __GetCurrentlySelectedFilename);
	Gura_AssignMethod(wx_FileDialog, __GetDirectory);
	Gura_AssignMethod(wx_FileDialog, __GetExtraControl);
	Gura_AssignMethod(wx_FileDialog, __GetFilename);
	Gura_AssignMethod(wx_FileDialog, __GetFilenames);
	Gura_AssignMethod(wx_FileDialog, __GetFilterIndex);
	Gura_AssignMethod(wx_FileDialog, __GetMessage);
	Gura_AssignMethod(wx_FileDialog, __GetPath);
	Gura_AssignMethod(wx_FileDialog, __GetPaths);
	Gura_AssignMethod(wx_FileDialog, __GetWildcard);
	Gura_AssignMethod(wx_FileDialog, __SetDirectory);
	Gura_AssignMethod(wx_FileDialog, __SetExtraControlCreator);
	Gura_AssignMethod(wx_FileDialog, __SetFilename);
	Gura_AssignMethod(wx_FileDialog, __SetFilterIndex);
	Gura_AssignMethod(wx_FileDialog, __SetMessage);
	Gura_AssignMethod(wx_FileDialog, __SetPath);
	Gura_AssignMethod(wx_FileDialog, __SetWildcard);
	Gura_AssignMethod(wx_FileDialog, __ShowModal);
}

Gura_ImplementDescendantCreator(wx_FileDialog)
{
	return new Object_wx_FileDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
