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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_HtmlEasyPrinting, wxHtmlEasyPrinting)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parentWindow", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlEasyPrinting, wxHtmlEasyPrinting)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlEasyPrinting *pThis = Object_wx_HtmlEasyPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int parentWindow = arg.GetNumber(1)
	//pThis->GetEntity()->wxHtmlEasyPrinting();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlEasyPrinting, GetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlEasyPrinting, GetName)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlEasyPrinting *pThis = Object_wx_HtmlEasyPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlEasyPrinting, GetPageSetupData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlEasyPrinting, GetPageSetupData)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlEasyPrinting *pThis = Object_wx_HtmlEasyPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPageSetupData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlEasyPrinting, GetParentWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlEasyPrinting, GetParentWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlEasyPrinting *pThis = Object_wx_HtmlEasyPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetParentWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlEasyPrinting, GetPrintData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlEasyPrinting, GetPrintData)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlEasyPrinting *pThis = Object_wx_HtmlEasyPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPrintData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlEasyPrinting, PageSetup)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlEasyPrinting, PageSetup)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlEasyPrinting *pThis = Object_wx_HtmlEasyPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->PageSetup();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlEasyPrinting, PreviewFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "htmlfile", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlEasyPrinting, PreviewFile)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlEasyPrinting *pThis = Object_wx_HtmlEasyPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int htmlfile = arg.GetNumber(0)
	//pThis->GetEntity()->PreviewFile();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlEasyPrinting, PreviewText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "htmltext", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "basepath", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlEasyPrinting, PreviewText)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlEasyPrinting *pThis = Object_wx_HtmlEasyPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int htmltext = arg.GetNumber(0)
	//int basepath = arg.GetNumber(1)
	//pThis->GetEntity()->PreviewText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlEasyPrinting, PrintFile)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "htmlfile", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlEasyPrinting, PrintFile)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlEasyPrinting *pThis = Object_wx_HtmlEasyPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int htmlfile = arg.GetNumber(0)
	//pThis->GetEntity()->PrintFile();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlEasyPrinting, PrintText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "htmltext", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "basepath", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlEasyPrinting, PrintText)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlEasyPrinting *pThis = Object_wx_HtmlEasyPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int htmltext = arg.GetNumber(0)
	//int basepath = arg.GetNumber(1)
	//pThis->GetEntity()->PrintText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlEasyPrinting, SetFonts)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "normal_face", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fixed_face", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sizes", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlEasyPrinting, SetFonts)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlEasyPrinting *pThis = Object_wx_HtmlEasyPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int normal_face = arg.GetNumber(0)
	//int fixed_face = arg.GetNumber(1)
	//int sizes = arg.GetNumber(2)
	//pThis->GetEntity()->SetFonts();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlEasyPrinting, SetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlEasyPrinting, SetName)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlEasyPrinting *pThis = Object_wx_HtmlEasyPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->SetName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlEasyPrinting, SetStandardFonts)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "normal_face", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fixed_face", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlEasyPrinting, SetStandardFonts)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlEasyPrinting *pThis = Object_wx_HtmlEasyPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//int normal_face = arg.GetNumber(1)
	//int fixed_face = arg.GetNumber(2)
	//pThis->GetEntity()->SetStandardFonts();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlEasyPrinting, SetFooter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "footer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pg", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlEasyPrinting, SetFooter)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlEasyPrinting *pThis = Object_wx_HtmlEasyPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int footer = arg.GetNumber(0)
	//int pg = arg.GetNumber(1)
	//pThis->GetEntity()->SetFooter();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlEasyPrinting, SetHeader)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "header", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pg", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlEasyPrinting, SetHeader)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlEasyPrinting *pThis = Object_wx_HtmlEasyPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int header = arg.GetNumber(0)
	//int pg = arg.GetNumber(1)
	//pThis->GetEntity()->SetHeader();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlEasyPrinting, SetParentWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlEasyPrinting, SetParentWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlEasyPrinting *pThis = Object_wx_HtmlEasyPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//pThis->GetEntity()->SetParentWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlEasyPrinting, CheckFit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pageArea", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "docArea", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlEasyPrinting, CheckFit)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlEasyPrinting *pThis = Object_wx_HtmlEasyPrinting::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Gura_AssignMethod(wx_HtmlEasyPrinting, wxHtmlEasyPrinting);
	Gura_AssignMethod(wx_HtmlEasyPrinting, GetName);
	Gura_AssignMethod(wx_HtmlEasyPrinting, GetPageSetupData);
	Gura_AssignMethod(wx_HtmlEasyPrinting, GetParentWindow);
	Gura_AssignMethod(wx_HtmlEasyPrinting, GetPrintData);
	Gura_AssignMethod(wx_HtmlEasyPrinting, PageSetup);
	Gura_AssignMethod(wx_HtmlEasyPrinting, PreviewFile);
	Gura_AssignMethod(wx_HtmlEasyPrinting, PreviewText);
	Gura_AssignMethod(wx_HtmlEasyPrinting, PrintFile);
	Gura_AssignMethod(wx_HtmlEasyPrinting, PrintText);
	Gura_AssignMethod(wx_HtmlEasyPrinting, SetFonts);
	Gura_AssignMethod(wx_HtmlEasyPrinting, SetName);
	Gura_AssignMethod(wx_HtmlEasyPrinting, SetStandardFonts);
	Gura_AssignMethod(wx_HtmlEasyPrinting, SetFooter);
	Gura_AssignMethod(wx_HtmlEasyPrinting, SetHeader);
	Gura_AssignMethod(wx_HtmlEasyPrinting, SetParentWindow);
	Gura_AssignMethod(wx_HtmlEasyPrinting, CheckFit);
}

Gura_ImplementDescendantCreator(wx_HtmlEasyPrinting)
{
	return new Object_wx_HtmlEasyPrinting((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
