//----------------------------------------------------------------------------
// wxRichTextPrintout
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextPrintout
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextPrintout
//----------------------------------------------------------------------------
Object_wx_RichTextPrintout::~Object_wx_RichTextPrintout()
{
}

Object *Object_wx_RichTextPrintout::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextPrintout::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextPrintout:");
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
Gura_DeclareMethod(wx_RichTextPrintout, wxRichTextPrintout)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrintout, wxRichTextPrintout)
{
	Object_wx_RichTextPrintout *pThis = Object_wx_RichTextPrintout::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int title = arg.GetNumber(0)
	//pThis->GetEntity()->wxRichTextPrintout();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPrintout, CalculateScaling)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "textRect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "headerRect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "footerRect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrintout, CalculateScaling)
{
	Object_wx_RichTextPrintout *pThis = Object_wx_RichTextPrintout::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int textRect = arg.GetNumber(1)
	//int headerRect = arg.GetNumber(2)
	//int footerRect = arg.GetNumber(3)
	//pThis->GetEntity()->CalculateScaling();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPrintout, GetHeaderFooterData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextPrintout, GetHeaderFooterData)
{
	Object_wx_RichTextPrintout *pThis = Object_wx_RichTextPrintout::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHeaderFooterData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPrintout, GetPageInfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "minPage", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "maxPage", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "selPageFrom", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "selPageTo", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrintout, GetPageInfo)
{
	Object_wx_RichTextPrintout *pThis = Object_wx_RichTextPrintout::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int minPage = arg.GetNumber(0)
	//int maxPage = arg.GetNumber(1)
	//int selPageFrom = arg.GetNumber(2)
	//int selPageTo = arg.GetNumber(3)
	//pThis->GetEntity()->GetPageInfo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPrintout, GetRichTextBuffer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextPrintout, GetRichTextBuffer)
{
	Object_wx_RichTextPrintout *pThis = Object_wx_RichTextPrintout::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRichTextBuffer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPrintout, HasPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrintout, HasPage)
{
	Object_wx_RichTextPrintout *pThis = Object_wx_RichTextPrintout::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//pThis->GetEntity()->HasPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPrintout, OnPreparePrinting)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextPrintout, OnPreparePrinting)
{
	Object_wx_RichTextPrintout *pThis = Object_wx_RichTextPrintout::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->OnPreparePrinting();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPrintout, OnPrintPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrintout, OnPrintPage)
{
	Object_wx_RichTextPrintout *pThis = Object_wx_RichTextPrintout::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//pThis->GetEntity()->OnPrintPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPrintout, SetHeaderFooterData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrintout, SetHeaderFooterData)
{
	Object_wx_RichTextPrintout *pThis = Object_wx_RichTextPrintout::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->SetHeaderFooterData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPrintout, SetMargins)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "top", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bottom", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "left", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "right", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrintout, SetMargins)
{
	Object_wx_RichTextPrintout *pThis = Object_wx_RichTextPrintout::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int top = arg.GetNumber(0)
	//int bottom = arg.GetNumber(1)
	//int left = arg.GetNumber(2)
	//int right = arg.GetNumber(3)
	//pThis->GetEntity()->SetMargins();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextPrintout, SetRichTextBuffer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextPrintout, SetRichTextBuffer)
{
	Object_wx_RichTextPrintout *pThis = Object_wx_RichTextPrintout::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//pThis->GetEntity()->SetRichTextBuffer();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextPrintout
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextPrintout)
{
	Gura_AssignMethod(wx_RichTextPrintout, wxRichTextPrintout);
	Gura_AssignMethod(wx_RichTextPrintout, CalculateScaling);
	Gura_AssignMethod(wx_RichTextPrintout, GetHeaderFooterData);
	Gura_AssignMethod(wx_RichTextPrintout, GetPageInfo);
	Gura_AssignMethod(wx_RichTextPrintout, GetRichTextBuffer);
	Gura_AssignMethod(wx_RichTextPrintout, HasPage);
	Gura_AssignMethod(wx_RichTextPrintout, OnPreparePrinting);
	Gura_AssignMethod(wx_RichTextPrintout, OnPrintPage);
	Gura_AssignMethod(wx_RichTextPrintout, SetHeaderFooterData);
	Gura_AssignMethod(wx_RichTextPrintout, SetMargins);
	Gura_AssignMethod(wx_RichTextPrintout, SetRichTextBuffer);
}

Gura_ImplementDescendantCreator(wx_RichTextPrintout)
{
	return new Object_wx_RichTextPrintout((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
