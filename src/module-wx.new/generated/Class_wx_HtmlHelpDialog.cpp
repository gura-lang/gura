//----------------------------------------------------------------------------
// wxHtmlHelpDialog
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlHelpDialog
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlHelpDialog
//----------------------------------------------------------------------------
Object_wx_HtmlHelpDialog::~Object_wx_HtmlHelpDialog()
{
}

Object *Object_wx_HtmlHelpDialog::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlHelpDialog::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlHelpDialog:");
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
Gura_DeclareMethod(wx_HtmlHelpDialog, wxHtmlHelpDialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpDialog, wxHtmlHelpDialog)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlHelpDialog *pThis = Object_wx_HtmlHelpDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->wxHtmlHelpDialog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlHelpDialog, wxHtmlHelpDialog_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpDialog, wxHtmlHelpDialog_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlHelpDialog *pThis = Object_wx_HtmlHelpDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int title = arg.GetNumber(2)
	//int style = arg.GetNumber(3)
	//int data = arg.GetNumber(4)
	//pThis->GetEntity()->wxHtmlHelpDialog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlHelpDialog, AddToolbarButtons)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "toolBar", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpDialog, AddToolbarButtons)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlHelpDialog *pThis = Object_wx_HtmlHelpDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int toolBar = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//pThis->GetEntity()->AddToolbarButtons();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlHelpDialog, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpDialog, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlHelpDialog *pThis = Object_wx_HtmlHelpDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int title = arg.GetNumber(2)
	//int style = arg.GetNumber(3)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlHelpDialog, GetController)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlHelpDialog, GetController)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlHelpDialog *pThis = Object_wx_HtmlHelpDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetController();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlHelpDialog, SetController)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "controller", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpDialog, SetController)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlHelpDialog *pThis = Object_wx_HtmlHelpDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int controller = arg.GetNumber(0)
	//pThis->GetEntity()->SetController();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlHelpDialog, SetTitleFormat)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpDialog, SetTitleFormat)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlHelpDialog *pThis = Object_wx_HtmlHelpDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int format = arg.GetNumber(0)
	//pThis->GetEntity()->SetTitleFormat();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlHelpDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlHelpDialog)
{
	Gura_AssignMethod(wx_HtmlHelpDialog, wxHtmlHelpDialog);
	Gura_AssignMethod(wx_HtmlHelpDialog, wxHtmlHelpDialog_1);
	Gura_AssignMethod(wx_HtmlHelpDialog, AddToolbarButtons);
	Gura_AssignMethod(wx_HtmlHelpDialog, Create);
	Gura_AssignMethod(wx_HtmlHelpDialog, GetController);
	Gura_AssignMethod(wx_HtmlHelpDialog, SetController);
	Gura_AssignMethod(wx_HtmlHelpDialog, SetTitleFormat);
}

Gura_ImplementDescendantCreator(wx_HtmlHelpDialog)
{
	return new Object_wx_HtmlHelpDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
