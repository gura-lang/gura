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
Gura_DeclareFunctionAlias(__wxHtmlEasyPrinting, "wxHtmlEasyPrinting")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parentWindow", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxHtmlEasyPrinting)
{
	//int name = arg.GetNumber(0)
	//int parentWindow = arg.GetNumber(1)
	//wxHtmlEasyPrinting();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_HtmlEasyPrinting, __GetName, "GetName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlEasyPrinting, __GetName)
{
	Object_wx_HtmlEasyPrinting *pThis = Object_wx_HtmlEasyPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlEasyPrinting, __GetPageSetupData, "GetPageSetupData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlEasyPrinting, __GetPageSetupData)
{
	Object_wx_HtmlEasyPrinting *pThis = Object_wx_HtmlEasyPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPageSetupData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlEasyPrinting, __GetParentWindow, "GetParentWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlEasyPrinting, __GetParentWindow)
{
	Object_wx_HtmlEasyPrinting *pThis = Object_wx_HtmlEasyPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetParentWindow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlEasyPrinting, __GetPrintData, "GetPrintData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlEasyPrinting, __GetPrintData)
{
	Object_wx_HtmlEasyPrinting *pThis = Object_wx_HtmlEasyPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPrintData();
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "htmlfile", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlEasyPrinting, __PreviewFile)
{
	Object_wx_HtmlEasyPrinting *pThis = Object_wx_HtmlEasyPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int htmlfile = arg.GetNumber(0)
	//pThis->GetEntity()->PreviewFile();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlEasyPrinting, __PreviewText, "PreviewText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "htmltext", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "basepath", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlEasyPrinting, __PreviewText)
{
	Object_wx_HtmlEasyPrinting *pThis = Object_wx_HtmlEasyPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int htmltext = arg.GetNumber(0)
	//int basepath = arg.GetNumber(1)
	//pThis->GetEntity()->PreviewText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlEasyPrinting, __PrintFile, "PrintFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "htmlfile", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlEasyPrinting, __PrintFile)
{
	Object_wx_HtmlEasyPrinting *pThis = Object_wx_HtmlEasyPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int htmlfile = arg.GetNumber(0)
	//pThis->GetEntity()->PrintFile();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlEasyPrinting, __PrintText, "PrintText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "htmltext", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "basepath", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlEasyPrinting, __PrintText)
{
	Object_wx_HtmlEasyPrinting *pThis = Object_wx_HtmlEasyPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int htmltext = arg.GetNumber(0)
	//int basepath = arg.GetNumber(1)
	//pThis->GetEntity()->PrintText();
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
	//int normal_face = arg.GetNumber(0)
	//int fixed_face = arg.GetNumber(1)
	//int sizes = arg.GetNumber(2)
	//pThis->GetEntity()->SetFonts();
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
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->SetName();
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
	//int normal_face = arg.GetNumber(1)
	//int fixed_face = arg.GetNumber(2)
	//pThis->GetEntity()->SetStandardFonts();
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
	//int footer = arg.GetNumber(0)
	//int pg = arg.GetNumber(1)
	//pThis->GetEntity()->SetFooter();
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
	//int header = arg.GetNumber(0)
	//int pg = arg.GetNumber(1)
	//pThis->GetEntity()->SetHeader();
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
	//int window = arg.GetNumber(0)
	//pThis->GetEntity()->SetParentWindow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlEasyPrinting, __CheckFit, "CheckFit")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pageArea", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "docArea", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlEasyPrinting, __CheckFit)
{
	Object_wx_HtmlEasyPrinting *pThis = Object_wx_HtmlEasyPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pageArea = arg.GetNumber(0)
	//int docArea = arg.GetNumber(1)
	//pThis->GetEntity()->CheckFit();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlEasyPrinting
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlEasyPrinting)
{
	// Constructor assignment
	Gura_AssignFunction(__wxHtmlEasyPrinting);
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
