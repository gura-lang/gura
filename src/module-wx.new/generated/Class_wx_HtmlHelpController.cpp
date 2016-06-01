//----------------------------------------------------------------------------
// wxHtmlHelpController
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlHelpController
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlHelpController
//----------------------------------------------------------------------------
Object_wx_HtmlHelpController::~Object_wx_HtmlHelpController()
{
}

Object *Object_wx_HtmlHelpController::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlHelpController::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlHelpController:");
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
Gura_DeclareMethod(wx_HtmlHelpController, wxHtmlHelpController)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parentWindow", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpController, wxHtmlHelpController)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlHelpController *pThis = Object_wx_HtmlHelpController::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//int parentWindow = arg.GetNumber(1)
	//pThis->GetEntity()->wxHtmlHelpController();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlHelpController, wxHtmlHelpController_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parentWindow", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpController, wxHtmlHelpController_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlHelpController *pThis = Object_wx_HtmlHelpController::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parentWindow = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//pThis->GetEntity()->wxHtmlHelpController();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlHelpController, AddBook)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bookFile", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "showWaitMsg", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpController, AddBook)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlHelpController *pThis = Object_wx_HtmlHelpController::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int bookFile = arg.GetNumber(0)
	//int showWaitMsg = arg.GetNumber(1)
	//pThis->GetEntity()->AddBook();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlHelpController, AddBook_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bookUrl", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "showWaitMsg", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpController, AddBook_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlHelpController *pThis = Object_wx_HtmlHelpController::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int bookUrl = arg.GetNumber(0)
	//int showWaitMsg = arg.GetNumber(1)
	//pThis->GetEntity()->AddBook();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlHelpController, Display)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpController, Display)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlHelpController *pThis = Object_wx_HtmlHelpController::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//pThis->GetEntity()->Display();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlHelpController, Display_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpController, Display_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlHelpController *pThis = Object_wx_HtmlHelpController::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->Display();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlHelpController, DisplayContents)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlHelpController, DisplayContents)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlHelpController *pThis = Object_wx_HtmlHelpController::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->DisplayContents();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlHelpController, DisplayIndex)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlHelpController, DisplayIndex)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlHelpController *pThis = Object_wx_HtmlHelpController::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->DisplayIndex();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlHelpController, KeywordSearch)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "keyword", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpController, KeywordSearch)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlHelpController *pThis = Object_wx_HtmlHelpController::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int keyword = arg.GetNumber(0)
	//int mode = arg.GetNumber(1)
	//pThis->GetEntity()->KeywordSearch();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlHelpController, ReadCustomization)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cfg", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpController, ReadCustomization)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlHelpController *pThis = Object_wx_HtmlHelpController::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int cfg = arg.GetNumber(0)
	//int path = arg.GetNumber(1)
	//pThis->GetEntity()->ReadCustomization();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlHelpController, SetShouldPreventAppExit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpController, SetShouldPreventAppExit)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlHelpController *pThis = Object_wx_HtmlHelpController::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int enable = arg.GetNumber(0)
	//pThis->GetEntity()->SetShouldPreventAppExit();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlHelpController, SetTempDir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpController, SetTempDir)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlHelpController *pThis = Object_wx_HtmlHelpController::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int path = arg.GetNumber(0)
	//pThis->GetEntity()->SetTempDir();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlHelpController, SetTitleFormat)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpController, SetTitleFormat)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlHelpController *pThis = Object_wx_HtmlHelpController::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int format = arg.GetNumber(0)
	//pThis->GetEntity()->SetTitleFormat();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlHelpController, UseConfig)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "config", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rootpath", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpController, UseConfig)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlHelpController *pThis = Object_wx_HtmlHelpController::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int config = arg.GetNumber(0)
	//int rootpath = arg.GetNumber(1)
	//pThis->GetEntity()->UseConfig();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlHelpController, WriteCustomization)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cfg", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpController, WriteCustomization)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlHelpController *pThis = Object_wx_HtmlHelpController::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int cfg = arg.GetNumber(0)
	//int path = arg.GetNumber(1)
	//pThis->GetEntity()->WriteCustomization();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlHelpController, GetHelpWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlHelpController, GetHelpWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlHelpController *pThis = Object_wx_HtmlHelpController::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetHelpWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlHelpController, SetHelpWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "helpWindow", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpController, SetHelpWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlHelpController *pThis = Object_wx_HtmlHelpController::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int helpWindow = arg.GetNumber(0)
	//pThis->GetEntity()->SetHelpWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlHelpController, GetFrame)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlHelpController, GetFrame)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlHelpController *pThis = Object_wx_HtmlHelpController::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFrame();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlHelpController, GetDialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlHelpController, GetDialog)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlHelpController *pThis = Object_wx_HtmlHelpController::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetDialog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlHelpController, CreateHelpDialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpController, CreateHelpDialog)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlHelpController *pThis = Object_wx_HtmlHelpController::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->CreateHelpDialog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlHelpController, CreateHelpFrame)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpController, CreateHelpFrame)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlHelpController *pThis = Object_wx_HtmlHelpController::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->CreateHelpFrame();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlHelpController
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlHelpController)
{
	Gura_AssignMethod(wx_HtmlHelpController, wxHtmlHelpController);
	Gura_AssignMethod(wx_HtmlHelpController, wxHtmlHelpController_1);
	Gura_AssignMethod(wx_HtmlHelpController, AddBook);
	Gura_AssignMethod(wx_HtmlHelpController, AddBook_1);
	Gura_AssignMethod(wx_HtmlHelpController, Display);
	Gura_AssignMethod(wx_HtmlHelpController, Display_1);
	Gura_AssignMethod(wx_HtmlHelpController, DisplayContents);
	Gura_AssignMethod(wx_HtmlHelpController, DisplayIndex);
	Gura_AssignMethod(wx_HtmlHelpController, KeywordSearch);
	Gura_AssignMethod(wx_HtmlHelpController, ReadCustomization);
	Gura_AssignMethod(wx_HtmlHelpController, SetShouldPreventAppExit);
	Gura_AssignMethod(wx_HtmlHelpController, SetTempDir);
	Gura_AssignMethod(wx_HtmlHelpController, SetTitleFormat);
	Gura_AssignMethod(wx_HtmlHelpController, UseConfig);
	Gura_AssignMethod(wx_HtmlHelpController, WriteCustomization);
	Gura_AssignMethod(wx_HtmlHelpController, GetHelpWindow);
	Gura_AssignMethod(wx_HtmlHelpController, SetHelpWindow);
	Gura_AssignMethod(wx_HtmlHelpController, GetFrame);
	Gura_AssignMethod(wx_HtmlHelpController, GetDialog);
	Gura_AssignMethod(wx_HtmlHelpController, CreateHelpDialog);
	Gura_AssignMethod(wx_HtmlHelpController, CreateHelpFrame);
}

Gura_ImplementDescendantCreator(wx_HtmlHelpController)
{
	return new Object_wx_HtmlHelpController((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
