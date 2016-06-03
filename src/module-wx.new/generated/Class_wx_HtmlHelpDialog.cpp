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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__HtmlHelpDialog, "HtmlHelpDialog")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_HtmlHelpDialog));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__HtmlHelpDialog)
{
	//int data = arg.GetNumber(0)
	//wxHtmlHelpDialog();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__HtmlHelpDialog_1, "HtmlHelpDialog_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_HtmlHelpDialog));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__HtmlHelpDialog_1)
{
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int title = arg.GetNumber(2)
	//int style = arg.GetNumber(3)
	//int data = arg.GetNumber(4)
	//wxHtmlHelpDialog();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_HtmlHelpDialog, __AddToolbarButtons, "AddToolbarButtons")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "toolBar", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpDialog, __AddToolbarButtons)
{
	Object_wx_HtmlHelpDialog *pThis = Object_wx_HtmlHelpDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int toolBar = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//pThis->GetEntity()->AddToolbarButtons();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlHelpDialog, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpDialog, __Create)
{
	Object_wx_HtmlHelpDialog *pThis = Object_wx_HtmlHelpDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int title = arg.GetNumber(2)
	//int style = arg.GetNumber(3)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlHelpDialog, __GetController, "GetController")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlHelpDialog, __GetController)
{
	Object_wx_HtmlHelpDialog *pThis = Object_wx_HtmlHelpDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetController();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlHelpDialog, __SetController, "SetController")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "controller", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpDialog, __SetController)
{
	Object_wx_HtmlHelpDialog *pThis = Object_wx_HtmlHelpDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int controller = arg.GetNumber(0)
	//pThis->GetEntity()->SetController();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlHelpDialog, __SetTitleFormat, "SetTitleFormat")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpDialog, __SetTitleFormat)
{
	Object_wx_HtmlHelpDialog *pThis = Object_wx_HtmlHelpDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int format = arg.GetNumber(0)
	//pThis->GetEntity()->SetTitleFormat();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlHelpDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlHelpDialog)
{
	// Constructor assignment
	Gura_AssignFunction(__HtmlHelpDialog);
	Gura_AssignFunction(__HtmlHelpDialog_1);
	// Method assignment
	Gura_AssignMethod(wx_HtmlHelpDialog, __AddToolbarButtons);
	Gura_AssignMethod(wx_HtmlHelpDialog, __Create);
	Gura_AssignMethod(wx_HtmlHelpDialog, __GetController);
	Gura_AssignMethod(wx_HtmlHelpDialog, __SetController);
	Gura_AssignMethod(wx_HtmlHelpDialog, __SetTitleFormat);
}

Gura_ImplementDescendantCreator(wx_HtmlHelpDialog)
{
	return new Object_wx_HtmlHelpDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
