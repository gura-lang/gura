//----------------------------------------------------------------------------
// wxDirDialog
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDirDialog
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDirDialog
//----------------------------------------------------------------------------
Object_wx_DirDialog::~Object_wx_DirDialog()
{
}

Object *Object_wx_DirDialog::Clone() const
{
	return nullptr;
}

String Object_wx_DirDialog::ToString(bool exprFlag)
{
	String rtn("<wx.DirDialog:");
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
Gura_DeclareMethod(wx_DirDialog, wxDirDialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "message", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "defaultPath", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DirDialog, wxDirDialog)
{
	Object_wx_DirDialog *pThis = Object_wx_DirDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int message = arg.GetNumber(1)
	//int defaultPath = arg.GetNumber(2)
	//int style = arg.GetNumber(3)
	//int pos = arg.GetNumber(4)
	//int size = arg.GetNumber(5)
	//int name = arg.GetNumber(6)
	//pThis->GetEntity()->wxDirDialog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DirDialog, GetMessage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DirDialog, GetMessage)
{
	Object_wx_DirDialog *pThis = Object_wx_DirDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMessage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DirDialog, GetPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DirDialog, GetPath)
{
	Object_wx_DirDialog *pThis = Object_wx_DirDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPath();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DirDialog, SetMessage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "message", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DirDialog, SetMessage)
{
	Object_wx_DirDialog *pThis = Object_wx_DirDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int message = arg.GetNumber(0)
	//pThis->GetEntity()->SetMessage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DirDialog, SetPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DirDialog, SetPath)
{
	Object_wx_DirDialog *pThis = Object_wx_DirDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int path = arg.GetNumber(0)
	//pThis->GetEntity()->SetPath();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DirDialog, ShowModal)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DirDialog, ShowModal)
{
	Object_wx_DirDialog *pThis = Object_wx_DirDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ShowModal();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDirDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DirDialog)
{
	Gura_AssignMethod(wx_DirDialog, wxDirDialog);
	Gura_AssignMethod(wx_DirDialog, GetMessage);
	Gura_AssignMethod(wx_DirDialog, GetPath);
	Gura_AssignMethod(wx_DirDialog, SetMessage);
	Gura_AssignMethod(wx_DirDialog, SetPath);
	Gura_AssignMethod(wx_DirDialog, ShowModal);
}

Gura_ImplementDescendantCreator(wx_DirDialog)
{
	return new Object_wx_DirDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
