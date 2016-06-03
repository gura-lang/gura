//----------------------------------------------------------------------------
// wxRichTextPrinting
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextPrinting
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextPrinting
//----------------------------------------------------------------------------
Object_wx_RichTextPrinting::~Object_wx_RichTextPrinting()
{
}

Object *Object_wx_RichTextPrinting::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextPrinting::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextPrinting:");
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
Gura_DeclareMethodAlias(wx_RichTextPrinting, __wxRichTextPrinting, "wxRichTextPrinting")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parentWindow", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrinting, __wxRichTextPrinting)
{
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int parentWindow = arg.GetNumber(1)
	//pThis->GetEntity()->wxRichTextPrinting();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPrinting, __GetFooterText, "GetFooterText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "location", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrinting, __GetFooterText)
{
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//int location = arg.GetNumber(1)
	//pThis->GetEntity()->GetFooterText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPrinting, __GetHeaderFooterData, "GetHeaderFooterData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextPrinting, __GetHeaderFooterData)
{
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHeaderFooterData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPrinting, __GetHeaderText, "GetHeaderText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "location", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrinting, __GetHeaderText)
{
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//int location = arg.GetNumber(1)
	//pThis->GetEntity()->GetHeaderText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPrinting, __GetPageSetupData, "GetPageSetupData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextPrinting, __GetPageSetupData)
{
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPageSetupData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPrinting, __GetParentWindow, "GetParentWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextPrinting, __GetParentWindow)
{
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetParentWindow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPrinting, __GetPreviewRect, "GetPreviewRect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextPrinting, __GetPreviewRect)
{
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPreviewRect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPrinting, __GetPrintData, "GetPrintData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextPrinting, __GetPrintData)
{
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPrintData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPrinting, __GetTitle, "GetTitle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextPrinting, __GetTitle)
{
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTitle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPrinting, __PageSetup, "PageSetup")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextPrinting, __PageSetup)
{
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->PageSetup();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPrinting, __PreviewBuffer, "PreviewBuffer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrinting, __PreviewBuffer)
{
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//pThis->GetEntity()->PreviewBuffer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPrinting, __PreviewFile, "PreviewFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "richTextFile", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrinting, __PreviewFile)
{
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int richTextFile = arg.GetNumber(0)
	//pThis->GetEntity()->PreviewFile();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPrinting, __PrintBuffer, "PrintBuffer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "showPrintDialog", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrinting, __PrintBuffer)
{
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int showPrintDialog = arg.GetNumber(1)
	//pThis->GetEntity()->PrintBuffer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPrinting, __PrintFile, "PrintFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "richTextFile", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "showPrintDialog", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrinting, __PrintFile)
{
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int richTextFile = arg.GetNumber(0)
	//int showPrintDialog = arg.GetNumber(1)
	//pThis->GetEntity()->PrintFile();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPrinting, __SetFooterText, "SetFooterText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "location", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrinting, __SetFooterText)
{
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//int page = arg.GetNumber(1)
	//int location = arg.GetNumber(2)
	//pThis->GetEntity()->SetFooterText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPrinting, __SetHeaderFooterData, "SetHeaderFooterData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrinting, __SetHeaderFooterData)
{
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->SetHeaderFooterData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPrinting, __SetHeaderFooterFont, "SetHeaderFooterFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrinting, __SetHeaderFooterFont)
{
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int font = arg.GetNumber(0)
	//pThis->GetEntity()->SetHeaderFooterFont();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPrinting, __SetHeaderFooterTextColour, "SetHeaderFooterTextColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrinting, __SetHeaderFooterTextColour)
{
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int colour = arg.GetNumber(0)
	//pThis->GetEntity()->SetHeaderFooterTextColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPrinting, __SetHeaderText, "SetHeaderText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "location", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrinting, __SetHeaderText)
{
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//int page = arg.GetNumber(1)
	//int location = arg.GetNumber(2)
	//pThis->GetEntity()->SetHeaderText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPrinting, __SetPageSetupData, "SetPageSetupData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pageSetupData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrinting, __SetPageSetupData)
{
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pageSetupData = arg.GetNumber(0)
	//pThis->GetEntity()->SetPageSetupData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPrinting, __SetParentWindow, "SetParentWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrinting, __SetParentWindow)
{
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//pThis->GetEntity()->SetParentWindow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPrinting, __SetPreviewRect, "SetPreviewRect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrinting, __SetPreviewRect)
{
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//pThis->GetEntity()->SetPreviewRect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPrinting, __SetPrintData, "SetPrintData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "printData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrinting, __SetPrintData)
{
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int printData = arg.GetNumber(0)
	//pThis->GetEntity()->SetPrintData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPrinting, __SetShowOnFirstPage, "SetShowOnFirstPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "show", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrinting, __SetShowOnFirstPage)
{
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int show = arg.GetNumber(0)
	//pThis->GetEntity()->SetShowOnFirstPage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextPrinting, __SetTitle, "SetTitle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrinting, __SetTitle)
{
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int title = arg.GetNumber(0)
	//pThis->GetEntity()->SetTitle();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextPrinting
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextPrinting)
{
	Gura_AssignMethod(wx_RichTextPrinting, __wxRichTextPrinting);
	Gura_AssignMethod(wx_RichTextPrinting, __GetFooterText);
	Gura_AssignMethod(wx_RichTextPrinting, __GetHeaderFooterData);
	Gura_AssignMethod(wx_RichTextPrinting, __GetHeaderText);
	Gura_AssignMethod(wx_RichTextPrinting, __GetPageSetupData);
	Gura_AssignMethod(wx_RichTextPrinting, __GetParentWindow);
	Gura_AssignMethod(wx_RichTextPrinting, __GetPreviewRect);
	Gura_AssignMethod(wx_RichTextPrinting, __GetPrintData);
	Gura_AssignMethod(wx_RichTextPrinting, __GetTitle);
	Gura_AssignMethod(wx_RichTextPrinting, __PageSetup);
	Gura_AssignMethod(wx_RichTextPrinting, __PreviewBuffer);
	Gura_AssignMethod(wx_RichTextPrinting, __PreviewFile);
	Gura_AssignMethod(wx_RichTextPrinting, __PrintBuffer);
	Gura_AssignMethod(wx_RichTextPrinting, __PrintFile);
	Gura_AssignMethod(wx_RichTextPrinting, __SetFooterText);
	Gura_AssignMethod(wx_RichTextPrinting, __SetHeaderFooterData);
	Gura_AssignMethod(wx_RichTextPrinting, __SetHeaderFooterFont);
	Gura_AssignMethod(wx_RichTextPrinting, __SetHeaderFooterTextColour);
	Gura_AssignMethod(wx_RichTextPrinting, __SetHeaderText);
	Gura_AssignMethod(wx_RichTextPrinting, __SetPageSetupData);
	Gura_AssignMethod(wx_RichTextPrinting, __SetParentWindow);
	Gura_AssignMethod(wx_RichTextPrinting, __SetPreviewRect);
	Gura_AssignMethod(wx_RichTextPrinting, __SetPrintData);
	Gura_AssignMethod(wx_RichTextPrinting, __SetShowOnFirstPage);
	Gura_AssignMethod(wx_RichTextPrinting, __SetTitle);
}

Gura_ImplementDescendantCreator(wx_RichTextPrinting)
{
	return new Object_wx_RichTextPrinting((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
