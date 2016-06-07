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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__GenericAboutDialog, "GenericAboutDialog")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_GenericAboutDialog));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__GenericAboutDialog)
{
	//wxGenericAboutDialog();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__GenericAboutDialog_1, "GenericAboutDialog_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "info", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_GenericAboutDialog));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__GenericAboutDialog_1)
{
	//const wxAboutDialogInfo& info = arg.GetNumber(0)
	//wxWindow* parent = arg.GetNumber(1)
	//wxGenericAboutDialog(info, parent);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_GenericAboutDialog, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "info", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GenericAboutDialog, __Create)
{
	Object_wx_GenericAboutDialog *pThis = Object_wx_GenericAboutDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxAboutDialogInfo& info = arg.GetNumber(0)
	//wxWindow* parent = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->Create(info, parent);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GenericAboutDialog, __DoAddCustomControls, "DoAddCustomControls")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GenericAboutDialog, __DoAddCustomControls)
{
	Object_wx_GenericAboutDialog *pThis = Object_wx_GenericAboutDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DoAddCustomControls();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GenericAboutDialog, __AddControl, "AddControl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GenericAboutDialog, __AddControl)
{
	Object_wx_GenericAboutDialog *pThis = Object_wx_GenericAboutDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* win = arg.GetNumber(0)
	//const wxSizerFlags& flags = arg.GetNumber(1)
	//pThis->GetEntity()->AddControl(win, flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GenericAboutDialog, __AddControl_1, "AddControl_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GenericAboutDialog, __AddControl_1)
{
	Object_wx_GenericAboutDialog *pThis = Object_wx_GenericAboutDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* win = arg.GetNumber(0)
	//pThis->GetEntity()->AddControl(win);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GenericAboutDialog, __AddText, "AddText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GenericAboutDialog, __AddText)
{
	Object_wx_GenericAboutDialog *pThis = Object_wx_GenericAboutDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& text = arg.GetNumber(0)
	//pThis->GetEntity()->AddText(text);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GenericAboutDialog, __AddCollapsiblePane, "AddCollapsiblePane")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GenericAboutDialog, __AddCollapsiblePane)
{
	Object_wx_GenericAboutDialog *pThis = Object_wx_GenericAboutDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& title = arg.GetNumber(0)
	//const wxString& text = arg.GetNumber(1)
	//pThis->GetEntity()->AddCollapsiblePane(title, text);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGenericAboutDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GenericAboutDialog)
{
	// Constructor assignment
	Gura_AssignFunction(__GenericAboutDialog);
	Gura_AssignFunction(__GenericAboutDialog_1);
	// Method assignment
	Gura_AssignMethod(wx_GenericAboutDialog, __Create);
	Gura_AssignMethod(wx_GenericAboutDialog, __DoAddCustomControls);
	Gura_AssignMethod(wx_GenericAboutDialog, __AddControl);
	Gura_AssignMethod(wx_GenericAboutDialog, __AddControl_1);
	Gura_AssignMethod(wx_GenericAboutDialog, __AddText);
	Gura_AssignMethod(wx_GenericAboutDialog, __AddCollapsiblePane);
}

Gura_ImplementDescendantCreator(wx_GenericAboutDialog)
{
	return new Object_wx_GenericAboutDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
