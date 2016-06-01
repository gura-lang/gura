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
Gura_DeclareMethod(wx_RichTextPrinting, wxRichTextPrinting)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parentWindow", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrinting, wxRichTextPrinting)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int parentWindow = arg.GetNumber(1)
	//pThis->GetEntity()->wxRichTextPrinting();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPrinting, GetFooterText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "location", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrinting, GetFooterText)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//int location = arg.GetNumber(1)
	//pThis->GetEntity()->GetFooterText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPrinting, GetHeaderFooterData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextPrinting, GetHeaderFooterData)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetHeaderFooterData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPrinting, GetHeaderText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "location", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrinting, GetHeaderText)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//int location = arg.GetNumber(1)
	//pThis->GetEntity()->GetHeaderText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPrinting, GetPageSetupData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextPrinting, GetPageSetupData)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPageSetupData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPrinting, GetParentWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextPrinting, GetParentWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetParentWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPrinting, GetPreviewRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextPrinting, GetPreviewRect)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPreviewRect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPrinting, GetPrintData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextPrinting, GetPrintData)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPrintData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPrinting, GetTitle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextPrinting, GetTitle)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetTitle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPrinting, PageSetup)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextPrinting, PageSetup)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->PageSetup();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPrinting, PreviewBuffer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrinting, PreviewBuffer)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//pThis->GetEntity()->PreviewBuffer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPrinting, PreviewFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "richTextFile", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrinting, PreviewFile)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int richTextFile = arg.GetNumber(0)
	//pThis->GetEntity()->PreviewFile();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPrinting, PrintBuffer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "showPrintDialog", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrinting, PrintBuffer)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int showPrintDialog = arg.GetNumber(1)
	//pThis->GetEntity()->PrintBuffer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPrinting, PrintFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "richTextFile", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "showPrintDialog", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrinting, PrintFile)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int richTextFile = arg.GetNumber(0)
	//int showPrintDialog = arg.GetNumber(1)
	//pThis->GetEntity()->PrintFile();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPrinting, SetFooterText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "location", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrinting, SetFooterText)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//int page = arg.GetNumber(1)
	//int location = arg.GetNumber(2)
	//pThis->GetEntity()->SetFooterText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPrinting, SetHeaderFooterData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrinting, SetHeaderFooterData)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->SetHeaderFooterData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPrinting, SetHeaderFooterFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrinting, SetHeaderFooterFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int font = arg.GetNumber(0)
	//pThis->GetEntity()->SetHeaderFooterFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPrinting, SetHeaderFooterTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrinting, SetHeaderFooterTextColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int colour = arg.GetNumber(0)
	//pThis->GetEntity()->SetHeaderFooterTextColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPrinting, SetHeaderText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "location", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrinting, SetHeaderText)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//int page = arg.GetNumber(1)
	//int location = arg.GetNumber(2)
	//pThis->GetEntity()->SetHeaderText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPrinting, SetPageSetupData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pageSetupData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrinting, SetPageSetupData)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pageSetupData = arg.GetNumber(0)
	//pThis->GetEntity()->SetPageSetupData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPrinting, SetParentWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrinting, SetParentWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//pThis->GetEntity()->SetParentWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPrinting, SetPreviewRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrinting, SetPreviewRect)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int rect = arg.GetNumber(0)
	//pThis->GetEntity()->SetPreviewRect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPrinting, SetPrintData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "printData", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrinting, SetPrintData)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int printData = arg.GetNumber(0)
	//pThis->GetEntity()->SetPrintData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPrinting, SetShowOnFirstPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "show", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrinting, SetShowOnFirstPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int show = arg.GetNumber(0)
	//pThis->GetEntity()->SetShowOnFirstPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPrinting, SetTitle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrinting, SetTitle)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextPrinting *pThis = Object_wx_RichTextPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int title = arg.GetNumber(0)
	//pThis->GetEntity()->SetTitle();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextPrinting
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextPrinting)
{
	Gura_AssignMethod(wx_RichTextPrinting, wxRichTextPrinting);
	Gura_AssignMethod(wx_RichTextPrinting, GetFooterText);
	Gura_AssignMethod(wx_RichTextPrinting, GetHeaderFooterData);
	Gura_AssignMethod(wx_RichTextPrinting, GetHeaderText);
	Gura_AssignMethod(wx_RichTextPrinting, GetPageSetupData);
	Gura_AssignMethod(wx_RichTextPrinting, GetParentWindow);
	Gura_AssignMethod(wx_RichTextPrinting, GetPreviewRect);
	Gura_AssignMethod(wx_RichTextPrinting, GetPrintData);
	Gura_AssignMethod(wx_RichTextPrinting, GetTitle);
	Gura_AssignMethod(wx_RichTextPrinting, PageSetup);
	Gura_AssignMethod(wx_RichTextPrinting, PreviewBuffer);
	Gura_AssignMethod(wx_RichTextPrinting, PreviewFile);
	Gura_AssignMethod(wx_RichTextPrinting, PrintBuffer);
	Gura_AssignMethod(wx_RichTextPrinting, PrintFile);
	Gura_AssignMethod(wx_RichTextPrinting, SetFooterText);
	Gura_AssignMethod(wx_RichTextPrinting, SetHeaderFooterData);
	Gura_AssignMethod(wx_RichTextPrinting, SetHeaderFooterFont);
	Gura_AssignMethod(wx_RichTextPrinting, SetHeaderFooterTextColour);
	Gura_AssignMethod(wx_RichTextPrinting, SetHeaderText);
	Gura_AssignMethod(wx_RichTextPrinting, SetPageSetupData);
	Gura_AssignMethod(wx_RichTextPrinting, SetParentWindow);
	Gura_AssignMethod(wx_RichTextPrinting, SetPreviewRect);
	Gura_AssignMethod(wx_RichTextPrinting, SetPrintData);
	Gura_AssignMethod(wx_RichTextPrinting, SetShowOnFirstPage);
	Gura_AssignMethod(wx_RichTextPrinting, SetTitle);
}

Gura_ImplementDescendantCreator(wx_RichTextPrinting)
{
	return new Object_wx_RichTextPrinting((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
