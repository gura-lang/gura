//----------------------------------------------------------------------------
// wxGenericAboutDialog
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGenericAboutDialog
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGenericAboutDialog
//----------------------------------------------------------------------------
Object_wx_GenericAboutDialog::~Object_wx_GenericAboutDialog()
{
}

Object *Object_wx_GenericAboutDialog::Clone() const
{
	return nullptr;
}

String Object_wx_GenericAboutDialog::ToString(bool exprFlag)
{
	String rtn("<wx.GenericAboutDialog:");
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
Gura_DeclareMethod(wx_GenericAboutDialog, wxGenericAboutDialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GenericAboutDialog, wxGenericAboutDialog)
{
	Object_wx_GenericAboutDialog *pThis = Object_wx_GenericAboutDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxGenericAboutDialog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GenericAboutDialog, wxGenericAboutDialog_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "info", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GenericAboutDialog, wxGenericAboutDialog_1)
{
	Object_wx_GenericAboutDialog *pThis = Object_wx_GenericAboutDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int info = arg.GetNumber(0)
	//int parent = arg.GetNumber(1)
	//pThis->GetEntity()->wxGenericAboutDialog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GenericAboutDialog, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "info", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GenericAboutDialog, Create)
{
	Object_wx_GenericAboutDialog *pThis = Object_wx_GenericAboutDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int info = arg.GetNumber(0)
	//int parent = arg.GetNumber(1)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GenericAboutDialog, DoAddCustomControls)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GenericAboutDialog, DoAddCustomControls)
{
	Object_wx_GenericAboutDialog *pThis = Object_wx_GenericAboutDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DoAddCustomControls();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GenericAboutDialog, AddControl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GenericAboutDialog, AddControl)
{
	Object_wx_GenericAboutDialog *pThis = Object_wx_GenericAboutDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->AddControl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GenericAboutDialog, AddControl_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GenericAboutDialog, AddControl_1)
{
	Object_wx_GenericAboutDialog *pThis = Object_wx_GenericAboutDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//pThis->GetEntity()->AddControl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GenericAboutDialog, AddText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GenericAboutDialog, AddText)
{
	Object_wx_GenericAboutDialog *pThis = Object_wx_GenericAboutDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//pThis->GetEntity()->AddText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GenericAboutDialog, AddCollapsiblePane)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GenericAboutDialog, AddCollapsiblePane)
{
	Object_wx_GenericAboutDialog *pThis = Object_wx_GenericAboutDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int title = arg.GetNumber(0)
	//int text = arg.GetNumber(1)
	//pThis->GetEntity()->AddCollapsiblePane();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGenericAboutDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GenericAboutDialog)
{
	Gura_AssignMethod(wx_GenericAboutDialog, wxGenericAboutDialog);
	Gura_AssignMethod(wx_GenericAboutDialog, wxGenericAboutDialog_1);
	Gura_AssignMethod(wx_GenericAboutDialog, Create);
	Gura_AssignMethod(wx_GenericAboutDialog, DoAddCustomControls);
	Gura_AssignMethod(wx_GenericAboutDialog, AddControl);
	Gura_AssignMethod(wx_GenericAboutDialog, AddControl_1);
	Gura_AssignMethod(wx_GenericAboutDialog, AddText);
	Gura_AssignMethod(wx_GenericAboutDialog, AddCollapsiblePane);
}

Gura_ImplementDescendantCreator(wx_GenericAboutDialog)
{
	return new Object_wx_GenericAboutDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
