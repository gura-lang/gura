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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_FileDialog, wxFileDialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "message", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defaultDir", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defaultFile", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wildcard", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileDialog, wxFileDialog)
{
	Object_wx_FileDialog *pThis = Object_wx_FileDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int message = arg.GetNumber(1)
	//int defaultDir = arg.GetNumber(2)
	//int defaultFile = arg.GetNumber(3)
	//int wildcard = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int pos = arg.GetNumber(6)
	//int size = arg.GetNumber(7)
	//int name = arg.GetNumber(8)
	//pThis->GetEntity()->wxFileDialog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileDialog, GetCurrentlySelectedFilename)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileDialog, GetCurrentlySelectedFilename)
{
	Object_wx_FileDialog *pThis = Object_wx_FileDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCurrentlySelectedFilename();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileDialog, GetDirectory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileDialog, GetDirectory)
{
	Object_wx_FileDialog *pThis = Object_wx_FileDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDirectory();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileDialog, GetExtraControl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileDialog, GetExtraControl)
{
	Object_wx_FileDialog *pThis = Object_wx_FileDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetExtraControl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileDialog, GetFilename)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileDialog, GetFilename)
{
	Object_wx_FileDialog *pThis = Object_wx_FileDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFilename();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileDialog, GetFilenames)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filenames", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileDialog, GetFilenames)
{
	Object_wx_FileDialog *pThis = Object_wx_FileDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filenames = arg.GetNumber(0)
	//pThis->GetEntity()->GetFilenames();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileDialog, GetFilterIndex)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileDialog, GetFilterIndex)
{
	Object_wx_FileDialog *pThis = Object_wx_FileDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFilterIndex();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileDialog, GetMessage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileDialog, GetMessage)
{
	Object_wx_FileDialog *pThis = Object_wx_FileDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMessage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileDialog, GetPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileDialog, GetPath)
{
	Object_wx_FileDialog *pThis = Object_wx_FileDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPath();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileDialog, GetPaths)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "paths", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileDialog, GetPaths)
{
	Object_wx_FileDialog *pThis = Object_wx_FileDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int paths = arg.GetNumber(0)
	//pThis->GetEntity()->GetPaths();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileDialog, GetWildcard)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileDialog, GetWildcard)
{
	Object_wx_FileDialog *pThis = Object_wx_FileDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWildcard();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileDialog, SetDirectory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "directory", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileDialog, SetDirectory)
{
	Object_wx_FileDialog *pThis = Object_wx_FileDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int directory = arg.GetNumber(0)
	//pThis->GetEntity()->SetDirectory();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileDialog, SetExtraControlCreator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "creator", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileDialog, SetExtraControlCreator)
{
	Object_wx_FileDialog *pThis = Object_wx_FileDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int creator = arg.GetNumber(0)
	//pThis->GetEntity()->SetExtraControlCreator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileDialog, SetFilename)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "setfilename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileDialog, SetFilename)
{
	Object_wx_FileDialog *pThis = Object_wx_FileDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int setfilename = arg.GetNumber(0)
	//pThis->GetEntity()->SetFilename();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileDialog, SetFilterIndex)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filterIndex", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileDialog, SetFilterIndex)
{
	Object_wx_FileDialog *pThis = Object_wx_FileDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filterIndex = arg.GetNumber(0)
	//pThis->GetEntity()->SetFilterIndex();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileDialog, SetMessage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "message", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileDialog, SetMessage)
{
	Object_wx_FileDialog *pThis = Object_wx_FileDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int message = arg.GetNumber(0)
	//pThis->GetEntity()->SetMessage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileDialog, SetPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileDialog, SetPath)
{
	Object_wx_FileDialog *pThis = Object_wx_FileDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int path = arg.GetNumber(0)
	//pThis->GetEntity()->SetPath();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileDialog, SetWildcard)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "wildCard", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FileDialog, SetWildcard)
{
	Object_wx_FileDialog *pThis = Object_wx_FileDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int wildCard = arg.GetNumber(0)
	//pThis->GetEntity()->SetWildcard();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FileDialog, ShowModal)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FileDialog, ShowModal)
{
	Object_wx_FileDialog *pThis = Object_wx_FileDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ShowModal();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFileDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileDialog)
{
	Gura_AssignMethod(wx_FileDialog, wxFileDialog);
	Gura_AssignMethod(wx_FileDialog, GetCurrentlySelectedFilename);
	Gura_AssignMethod(wx_FileDialog, GetDirectory);
	Gura_AssignMethod(wx_FileDialog, GetExtraControl);
	Gura_AssignMethod(wx_FileDialog, GetFilename);
	Gura_AssignMethod(wx_FileDialog, GetFilenames);
	Gura_AssignMethod(wx_FileDialog, GetFilterIndex);
	Gura_AssignMethod(wx_FileDialog, GetMessage);
	Gura_AssignMethod(wx_FileDialog, GetPath);
	Gura_AssignMethod(wx_FileDialog, GetPaths);
	Gura_AssignMethod(wx_FileDialog, GetWildcard);
	Gura_AssignMethod(wx_FileDialog, SetDirectory);
	Gura_AssignMethod(wx_FileDialog, SetExtraControlCreator);
	Gura_AssignMethod(wx_FileDialog, SetFilename);
	Gura_AssignMethod(wx_FileDialog, SetFilterIndex);
	Gura_AssignMethod(wx_FileDialog, SetMessage);
	Gura_AssignMethod(wx_FileDialog, SetPath);
	Gura_AssignMethod(wx_FileDialog, SetWildcard);
	Gura_AssignMethod(wx_FileDialog, ShowModal);
}

Gura_ImplementDescendantCreator(wx_FileDialog)
{
	return new Object_wx_FileDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
