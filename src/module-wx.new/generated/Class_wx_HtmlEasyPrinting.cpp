//----------------------------------------------------------------------------
// wxHtmlEasyPrinting
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlEasyPrinting
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlEasyPrinting
//----------------------------------------------------------------------------
Object_wx_HtmlEasyPrinting::~Object_wx_HtmlEasyPrinting()
{
}

Object *Object_wx_HtmlEasyPrinting::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlEasyPrinting::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlEasyPrinting:");
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
Gura_DeclareFunctionAlias(__HtmlEasyPrinting, "HtmlEasyPrinting")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parentWindow", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_HtmlEasyPrinting));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__HtmlEasyPrinting)
{
	//const wxString& name = arg.GetNumber(0)
	//wxWindow* parentWindow = arg.GetNumber(1)
	//wxHtmlEasyPrinting(name, parentWindow);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_HtmlEasyPrinting, __GetName, "GetName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlEasyPrinting, __GetName)
{
	Object_wx_HtmlEasyPrinting *pThis = Object_wx_HtmlEasyPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& _rtn = pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlEasyPrinting, __GetPageSetupData, "GetPageSetupData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlEasyPrinting, __GetPageSetupData)
{
	Object_wx_HtmlEasyPrinting *pThis = Object_wx_HtmlEasyPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPageSetupDialogData* _rtn = pThis->GetEntity()->GetPageSetupData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlEasyPrinting, __GetParentWindow, "GetParentWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlEasyPrinting, __GetParentWindow)
{
	Object_wx_HtmlEasyPrinting *pThis = Object_wx_HtmlEasyPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* _rtn = pThis->GetEntity()->GetParentWindow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlEasyPrinting, __GetPrintData, "GetPrintData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlEasyPrinting, __GetPrintData)
{
	Object_wx_HtmlEasyPrinting *pThis = Object_wx_HtmlEasyPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPrintData* _rtn = pThis->GetEntity()->GetPrintData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlEasyPrinting, __PageSetup, "PageSetup")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlEasyPrinting, __PageSetup)
{
	Object_wx_HtmlEasyPrinting *pThis = Object_wx_HtmlEasyPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->PageSetup();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlEasyPrinting, __PreviewFile, "PreviewFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "htmlfile", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlEasyPrinting, __PreviewFile)
{
	Object_wx_HtmlEasyPrinting *pThis = Object_wx_HtmlEasyPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& htmlfile = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->PreviewFile(htmlfile);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlEasyPrinting, __PreviewText, "PreviewText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "htmltext", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "basepath", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlEasyPrinting, __PreviewText)
{
	Object_wx_HtmlEasyPrinting *pThis = Object_wx_HtmlEasyPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& htmltext = arg.GetNumber(0)
	//const wxString& basepath = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->PreviewText(htmltext, basepath);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlEasyPrinting, __PrintFile, "PrintFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "htmlfile", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlEasyPrinting, __PrintFile)
{
	Object_wx_HtmlEasyPrinting *pThis = Object_wx_HtmlEasyPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& htmlfile = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->PrintFile(htmlfile);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlEasyPrinting, __PrintText, "PrintText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "htmltext", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "basepath", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlEasyPrinting, __PrintText)
{
	Object_wx_HtmlEasyPrinting *pThis = Object_wx_HtmlEasyPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& htmltext = arg.GetNumber(0)
	//const wxString& basepath = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->PrintText(htmltext, basepath);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlEasyPrinting, __SetFonts, "SetFonts")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "normal_face", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fixed_face", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sizes", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlEasyPrinting, __SetFonts)
{
	Object_wx_HtmlEasyPrinting *pThis = Object_wx_HtmlEasyPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& normal_face = arg.GetNumber(0)
	//const wxString& fixed_face = arg.GetNumber(1)
	//const int* sizes = arg.GetNumber(2)
	//pThis->GetEntity()->SetFonts(normal_face, fixed_face, sizes);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlEasyPrinting, __SetName, "SetName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlEasyPrinting, __SetName)
{
	Object_wx_HtmlEasyPrinting *pThis = Object_wx_HtmlEasyPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//pThis->GetEntity()->SetName(name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlEasyPrinting, __SetStandardFonts, "SetStandardFonts")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "normal_face", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fixed_face", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlEasyPrinting, __SetStandardFonts)
{
	Object_wx_HtmlEasyPrinting *pThis = Object_wx_HtmlEasyPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//const wxString& normal_face = arg.GetNumber(1)
	//const wxString& fixed_face = arg.GetNumber(2)
	//pThis->GetEntity()->SetStandardFonts(size, normal_face, fixed_face);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlEasyPrinting, __SetFooter, "SetFooter")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "footer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pg", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlEasyPrinting, __SetFooter)
{
	Object_wx_HtmlEasyPrinting *pThis = Object_wx_HtmlEasyPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& footer = arg.GetNumber(0)
	//int pg = arg.GetNumber(1)
	//pThis->GetEntity()->SetFooter(footer, pg);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlEasyPrinting, __SetHeader, "SetHeader")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "header", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pg", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlEasyPrinting, __SetHeader)
{
	Object_wx_HtmlEasyPrinting *pThis = Object_wx_HtmlEasyPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& header = arg.GetNumber(0)
	//int pg = arg.GetNumber(1)
	//pThis->GetEntity()->SetHeader(header, pg);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlEasyPrinting, __SetParentWindow, "SetParentWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlEasyPrinting, __SetParentWindow)
{
	Object_wx_HtmlEasyPrinting *pThis = Object_wx_HtmlEasyPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* window = arg.GetNumber(0)
	//pThis->GetEntity()->SetParentWindow(window);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlEasyPrinting, __CheckFit, "CheckFit")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "pageArea", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "docArea", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlEasyPrinting, __CheckFit)
{
	Object_wx_HtmlEasyPrinting *pThis = Object_wx_HtmlEasyPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxSize& pageArea = arg.GetNumber(0)
	//const wxSize& docArea = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->CheckFit(pageArea, docArea);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlEasyPrinting
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlEasyPrinting)
{
	// Constructor assignment
	Gura_AssignFunction(__HtmlEasyPrinting);
	// Method assignment
	Gura_AssignMethod(wx_HtmlEasyPrinting, __GetName);
	Gura_AssignMethod(wx_HtmlEasyPrinting, __GetPageSetupData);
	Gura_AssignMethod(wx_HtmlEasyPrinting, __GetParentWindow);
	Gura_AssignMethod(wx_HtmlEasyPrinting, __GetPrintData);
	Gura_AssignMethod(wx_HtmlEasyPrinting, __PageSetup);
	Gura_AssignMethod(wx_HtmlEasyPrinting, __PreviewFile);
	Gura_AssignMethod(wx_HtmlEasyPrinting, __PreviewText);
	Gura_AssignMethod(wx_HtmlEasyPrinting, __PrintFile);
	Gura_AssignMethod(wx_HtmlEasyPrinting, __PrintText);
	Gura_AssignMethod(wx_HtmlEasyPrinting, __SetFonts);
	Gura_AssignMethod(wx_HtmlEasyPrinting, __SetName);
	Gura_AssignMethod(wx_HtmlEasyPrinting, __SetStandardFonts);
	Gura_AssignMethod(wx_HtmlEasyPrinting, __SetFooter);
	Gura_AssignMethod(wx_HtmlEasyPrinting, __SetHeader);
	Gura_AssignMethod(wx_HtmlEasyPrinting, __SetParentWindow);
	Gura_AssignMethod(wx_HtmlEasyPrinting, __CheckFit);
}

Gura_ImplementDescendantCreator(wx_HtmlEasyPrinting)
{
	return new Object_wx_HtmlEasyPrinting((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
