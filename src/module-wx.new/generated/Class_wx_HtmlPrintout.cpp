//----------------------------------------------------------------------------
// wxHtmlPrintout
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlPrintout
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlPrintout
//----------------------------------------------------------------------------
Object_wx_HtmlPrintout::~Object_wx_HtmlPrintout()
{
}

Object *Object_wx_HtmlPrintout::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlPrintout::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlPrintout:");
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
Gura_DeclareFunctionAlias(__wxHtmlPrintout, "wxHtmlPrintout")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_HtmlPrintout));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxHtmlPrintout)
{
	//int title = arg.GetNumber(0)
	//wxHtmlPrintout();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_HtmlPrintout, __AddFilter, "AddFilter")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filter", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlPrintout, __AddFilter)
{
	Object_wx_HtmlPrintout *pThis = Object_wx_HtmlPrintout::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filter = arg.GetNumber(0)
	//pThis->GetEntity()->AddFilter();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlPrintout, __SetFonts, "SetFonts")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "normal_face", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "fixed_face", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sizes", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlPrintout, __SetFonts)
{
	Object_wx_HtmlPrintout *pThis = Object_wx_HtmlPrintout::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int normal_face = arg.GetNumber(0)
	//int fixed_face = arg.GetNumber(1)
	//int sizes = arg.GetNumber(2)
	//pThis->GetEntity()->SetFonts();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlPrintout, __SetFooter, "SetFooter")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "footer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pg", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlPrintout, __SetFooter)
{
	Object_wx_HtmlPrintout *pThis = Object_wx_HtmlPrintout::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int footer = arg.GetNumber(0)
	//int pg = arg.GetNumber(1)
	//pThis->GetEntity()->SetFooter();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlPrintout, __SetHeader, "SetHeader")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "header", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pg", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlPrintout, __SetHeader)
{
	Object_wx_HtmlPrintout *pThis = Object_wx_HtmlPrintout::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int header = arg.GetNumber(0)
	//int pg = arg.GetNumber(1)
	//pThis->GetEntity()->SetHeader();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlPrintout, __SetHtmlFile, "SetHtmlFile")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "htmlfile", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlPrintout, __SetHtmlFile)
{
	Object_wx_HtmlPrintout *pThis = Object_wx_HtmlPrintout::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int htmlfile = arg.GetNumber(0)
	//pThis->GetEntity()->SetHtmlFile();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlPrintout, __SetHtmlText, "SetHtmlText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "html", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "basepath", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "isdir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlPrintout, __SetHtmlText)
{
	Object_wx_HtmlPrintout *pThis = Object_wx_HtmlPrintout::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int html = arg.GetNumber(0)
	//int basepath = arg.GetNumber(1)
	//int isdir = arg.GetNumber(2)
	//pThis->GetEntity()->SetHtmlText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlPrintout, __SetMargins, "SetMargins")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "top", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bottom", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "left", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "right", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "spaces", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlPrintout, __SetMargins)
{
	Object_wx_HtmlPrintout *pThis = Object_wx_HtmlPrintout::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int top = arg.GetNumber(0)
	//int bottom = arg.GetNumber(1)
	//int left = arg.GetNumber(2)
	//int right = arg.GetNumber(3)
	//int spaces = arg.GetNumber(4)
	//pThis->GetEntity()->SetMargins();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlPrintout
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlPrintout)
{
	// Constructor assignment
	Gura_AssignFunction(__wxHtmlPrintout);
	// Method assignment
	Gura_AssignMethod(wx_HtmlPrintout, __AddFilter);
	Gura_AssignMethod(wx_HtmlPrintout, __SetFonts);
	Gura_AssignMethod(wx_HtmlPrintout, __SetFooter);
	Gura_AssignMethod(wx_HtmlPrintout, __SetHeader);
	Gura_AssignMethod(wx_HtmlPrintout, __SetHtmlFile);
	Gura_AssignMethod(wx_HtmlPrintout, __SetHtmlText);
	Gura_AssignMethod(wx_HtmlPrintout, __SetMargins);
}

Gura_ImplementDescendantCreator(wx_HtmlPrintout)
{
	return new Object_wx_HtmlPrintout((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
