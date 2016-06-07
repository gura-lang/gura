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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__HtmlHelpController, "HtmlHelpController")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parentWindow", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_HtmlHelpController));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__HtmlHelpController)
{
	//int style = arg.GetNumber(0)
	//wxWindow* parentWindow = arg.GetNumber(1)
	//wxHtmlHelpController(style, parentWindow);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__HtmlHelpController_1, "HtmlHelpController_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parentWindow", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_HtmlHelpController));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__HtmlHelpController_1)
{
	//wxWindow* parentWindow = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//wxHtmlHelpController(parentWindow, style);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_HtmlHelpController, __AddBook, "AddBook")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bookFile", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "showWaitMsg", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpController, __AddBook)
{
	Object_wx_HtmlHelpController *pThis = Object_wx_HtmlHelpController::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxFileName& bookFile = arg.GetNumber(0)
	//bool showWaitMsg = arg.GetNumber(1)
	//pThis->GetEntity()->AddBook(bookFile, showWaitMsg);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlHelpController, __AddBook_1, "AddBook_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bookUrl", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "showWaitMsg", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpController, __AddBook_1)
{
	Object_wx_HtmlHelpController *pThis = Object_wx_HtmlHelpController::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& bookUrl = arg.GetNumber(0)
	//bool showWaitMsg = arg.GetNumber(1)
	//pThis->GetEntity()->AddBook(bookUrl, showWaitMsg);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlHelpController, __Display, "Display")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpController, __Display)
{
	Object_wx_HtmlHelpController *pThis = Object_wx_HtmlHelpController::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& x = arg.GetNumber(0)
	//pThis->GetEntity()->Display(x);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlHelpController, __Display_1, "Display_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpController, __Display_1)
{
	Object_wx_HtmlHelpController *pThis = Object_wx_HtmlHelpController::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->Display(id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlHelpController, __DisplayContents, "DisplayContents")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlHelpController, __DisplayContents)
{
	Object_wx_HtmlHelpController *pThis = Object_wx_HtmlHelpController::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DisplayContents();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlHelpController, __DisplayIndex, "DisplayIndex")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlHelpController, __DisplayIndex)
{
	Object_wx_HtmlHelpController *pThis = Object_wx_HtmlHelpController::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DisplayIndex();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlHelpController, __KeywordSearch, "KeywordSearch")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "keyword", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpController, __KeywordSearch)
{
	Object_wx_HtmlHelpController *pThis = Object_wx_HtmlHelpController::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& keyword = arg.GetNumber(0)
	//wxHelpSearchMode mode = arg.GetNumber(1)
	//pThis->GetEntity()->KeywordSearch(keyword, mode);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlHelpController, __ReadCustomization, "ReadCustomization")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cfg", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpController, __ReadCustomization)
{
	Object_wx_HtmlHelpController *pThis = Object_wx_HtmlHelpController::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxConfigBase* cfg = arg.GetNumber(0)
	//const wxString& path = arg.GetNumber(1)
	//pThis->GetEntity()->ReadCustomization(cfg, path);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlHelpController, __SetShouldPreventAppExit, "SetShouldPreventAppExit")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpController, __SetShouldPreventAppExit)
{
	Object_wx_HtmlHelpController *pThis = Object_wx_HtmlHelpController::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool enable = arg.GetNumber(0)
	//pThis->GetEntity()->SetShouldPreventAppExit(enable);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlHelpController, __SetTempDir, "SetTempDir")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpController, __SetTempDir)
{
	Object_wx_HtmlHelpController *pThis = Object_wx_HtmlHelpController::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& path = arg.GetNumber(0)
	//pThis->GetEntity()->SetTempDir(path);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlHelpController, __SetTitleFormat, "SetTitleFormat")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpController, __SetTitleFormat)
{
	Object_wx_HtmlHelpController *pThis = Object_wx_HtmlHelpController::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& format = arg.GetNumber(0)
	//pThis->GetEntity()->SetTitleFormat(format);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlHelpController, __UseConfig, "UseConfig")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "config", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rootpath", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpController, __UseConfig)
{
	Object_wx_HtmlHelpController *pThis = Object_wx_HtmlHelpController::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxConfigBase* config = arg.GetNumber(0)
	//const wxString& rootpath = arg.GetNumber(1)
	//pThis->GetEntity()->UseConfig(config, rootpath);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlHelpController, __WriteCustomization, "WriteCustomization")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cfg", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpController, __WriteCustomization)
{
	Object_wx_HtmlHelpController *pThis = Object_wx_HtmlHelpController::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxConfigBase* cfg = arg.GetNumber(0)
	//const wxString& path = arg.GetNumber(1)
	//pThis->GetEntity()->WriteCustomization(cfg, path);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlHelpController, __GetHelpWindow, "GetHelpWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlHelpController, __GetHelpWindow)
{
	Object_wx_HtmlHelpController *pThis = Object_wx_HtmlHelpController::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHelpWindow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlHelpController, __SetHelpWindow, "SetHelpWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "helpWindow", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpController, __SetHelpWindow)
{
	Object_wx_HtmlHelpController *pThis = Object_wx_HtmlHelpController::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxHtmlHelpWindow* helpWindow = arg.GetNumber(0)
	//pThis->GetEntity()->SetHelpWindow(helpWindow);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlHelpController, __GetFrame, "GetFrame")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlHelpController, __GetFrame)
{
	Object_wx_HtmlHelpController *pThis = Object_wx_HtmlHelpController::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFrame();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlHelpController, __GetDialog, "GetDialog")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlHelpController, __GetDialog)
{
	Object_wx_HtmlHelpController *pThis = Object_wx_HtmlHelpController::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDialog();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlHelpController, __CreateHelpDialog, "CreateHelpDialog")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpController, __CreateHelpDialog)
{
	Object_wx_HtmlHelpController *pThis = Object_wx_HtmlHelpController::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxHtmlHelpData* data = arg.GetNumber(0)
	//pThis->GetEntity()->CreateHelpDialog(data);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlHelpController, __CreateHelpFrame, "CreateHelpFrame")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlHelpController, __CreateHelpFrame)
{
	Object_wx_HtmlHelpController *pThis = Object_wx_HtmlHelpController::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxHtmlHelpData* data = arg.GetNumber(0)
	//pThis->GetEntity()->CreateHelpFrame(data);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlHelpController
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlHelpController)
{
	// Constructor assignment
	Gura_AssignFunction(__HtmlHelpController);
	Gura_AssignFunction(__HtmlHelpController_1);
	// Method assignment
	Gura_AssignMethod(wx_HtmlHelpController, __AddBook);
	Gura_AssignMethod(wx_HtmlHelpController, __AddBook_1);
	Gura_AssignMethod(wx_HtmlHelpController, __Display);
	Gura_AssignMethod(wx_HtmlHelpController, __Display_1);
	Gura_AssignMethod(wx_HtmlHelpController, __DisplayContents);
	Gura_AssignMethod(wx_HtmlHelpController, __DisplayIndex);
	Gura_AssignMethod(wx_HtmlHelpController, __KeywordSearch);
	Gura_AssignMethod(wx_HtmlHelpController, __ReadCustomization);
	Gura_AssignMethod(wx_HtmlHelpController, __SetShouldPreventAppExit);
	Gura_AssignMethod(wx_HtmlHelpController, __SetTempDir);
	Gura_AssignMethod(wx_HtmlHelpController, __SetTitleFormat);
	Gura_AssignMethod(wx_HtmlHelpController, __UseConfig);
	Gura_AssignMethod(wx_HtmlHelpController, __WriteCustomization);
	Gura_AssignMethod(wx_HtmlHelpController, __GetHelpWindow);
	Gura_AssignMethod(wx_HtmlHelpController, __SetHelpWindow);
	Gura_AssignMethod(wx_HtmlHelpController, __GetFrame);
	Gura_AssignMethod(wx_HtmlHelpController, __GetDialog);
	Gura_AssignMethod(wx_HtmlHelpController, __CreateHelpDialog);
	Gura_AssignMethod(wx_HtmlHelpController, __CreateHelpFrame);
}

Gura_ImplementDescendantCreator(wx_HtmlHelpController)
{
	return new Object_wx_HtmlHelpController((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
