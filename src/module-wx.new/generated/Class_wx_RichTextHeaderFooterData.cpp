//----------------------------------------------------------------------------
// wxRichTextHeaderFooterData
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextHeaderFooterData
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextHeaderFooterData
//----------------------------------------------------------------------------
Object_wx_RichTextHeaderFooterData::~Object_wx_RichTextHeaderFooterData()
{
}

Object *Object_wx_RichTextHeaderFooterData::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextHeaderFooterData::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextHeaderFooterData:");
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
Gura_DeclareFunctionAlias(__RichTextHeaderFooterData, "RichTextHeaderFooterData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_RichTextHeaderFooterData));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RichTextHeaderFooterData)
{
	//wxRichTextHeaderFooterData();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__RichTextHeaderFooterData_1, "RichTextHeaderFooterData_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RichTextHeaderFooterData));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RichTextHeaderFooterData_1)
{
	//const wxRichTextHeaderFooterData& data = arg.GetNumber(0)
	//wxRichTextHeaderFooterData();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RichTextHeaderFooterData, __Clear, "Clear")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextHeaderFooterData, __Clear)
{
	Object_wx_RichTextHeaderFooterData *pThis = Object_wx_RichTextHeaderFooterData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextHeaderFooterData, __Copy, "Copy")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextHeaderFooterData, __Copy)
{
	Object_wx_RichTextHeaderFooterData *pThis = Object_wx_RichTextHeaderFooterData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxRichTextHeaderFooterData& data = arg.GetNumber(0)
	//pThis->GetEntity()->Copy();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextHeaderFooterData, __GetFont, "GetFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextHeaderFooterData, __GetFont)
{
	Object_wx_RichTextHeaderFooterData *pThis = Object_wx_RichTextHeaderFooterData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFont();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextHeaderFooterData, __GetFooterMargin, "GetFooterMargin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextHeaderFooterData, __GetFooterMargin)
{
	Object_wx_RichTextHeaderFooterData *pThis = Object_wx_RichTextHeaderFooterData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFooterMargin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextHeaderFooterData, __GetFooterText, "GetFooterText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "location", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextHeaderFooterData, __GetFooterText)
{
	Object_wx_RichTextHeaderFooterData *pThis = Object_wx_RichTextHeaderFooterData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextOddEvenPage page = arg.GetNumber(0)
	//wxRichTextPageLocation location = arg.GetNumber(1)
	//pThis->GetEntity()->GetFooterText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextHeaderFooterData, __GetHeaderMargin, "GetHeaderMargin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextHeaderFooterData, __GetHeaderMargin)
{
	Object_wx_RichTextHeaderFooterData *pThis = Object_wx_RichTextHeaderFooterData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHeaderMargin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextHeaderFooterData, __GetHeaderText, "GetHeaderText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "location", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextHeaderFooterData, __GetHeaderText)
{
	Object_wx_RichTextHeaderFooterData *pThis = Object_wx_RichTextHeaderFooterData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextOddEvenPage page = arg.GetNumber(0)
	//wxRichTextPageLocation location = arg.GetNumber(1)
	//pThis->GetEntity()->GetHeaderText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextHeaderFooterData, __GetShowOnFirstPage, "GetShowOnFirstPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextHeaderFooterData, __GetShowOnFirstPage)
{
	Object_wx_RichTextHeaderFooterData *pThis = Object_wx_RichTextHeaderFooterData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetShowOnFirstPage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextHeaderFooterData, __GetText, "GetText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "headerFooter", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "location", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextHeaderFooterData, __GetText)
{
	Object_wx_RichTextHeaderFooterData *pThis = Object_wx_RichTextHeaderFooterData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int headerFooter = arg.GetNumber(0)
	//wxRichTextOddEvenPage page = arg.GetNumber(1)
	//wxRichTextPageLocation location = arg.GetNumber(2)
	//pThis->GetEntity()->GetText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextHeaderFooterData, __GetTextColour, "GetTextColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextHeaderFooterData, __GetTextColour)
{
	Object_wx_RichTextHeaderFooterData *pThis = Object_wx_RichTextHeaderFooterData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTextColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextHeaderFooterData, __Init, "Init")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextHeaderFooterData, __Init)
{
	Object_wx_RichTextHeaderFooterData *pThis = Object_wx_RichTextHeaderFooterData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Init();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextHeaderFooterData, __SetFont, "SetFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextHeaderFooterData, __SetFont)
{
	Object_wx_RichTextHeaderFooterData *pThis = Object_wx_RichTextHeaderFooterData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxFont& font = arg.GetNumber(0)
	//pThis->GetEntity()->SetFont();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextHeaderFooterData, __SetFooterText, "SetFooterText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "location", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextHeaderFooterData, __SetFooterText)
{
	Object_wx_RichTextHeaderFooterData *pThis = Object_wx_RichTextHeaderFooterData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& text = arg.GetNumber(0)
	//wxRichTextOddEvenPage page = arg.GetNumber(1)
	//wxRichTextPageLocation location = arg.GetNumber(2)
	//pThis->GetEntity()->SetFooterText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextHeaderFooterData, __SetHeaderText, "SetHeaderText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "location", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextHeaderFooterData, __SetHeaderText)
{
	Object_wx_RichTextHeaderFooterData *pThis = Object_wx_RichTextHeaderFooterData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& text = arg.GetNumber(0)
	//wxRichTextOddEvenPage page = arg.GetNumber(1)
	//wxRichTextPageLocation location = arg.GetNumber(2)
	//pThis->GetEntity()->SetHeaderText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextHeaderFooterData, __SetMargins, "SetMargins")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "headerMargin", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "footerMargin", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextHeaderFooterData, __SetMargins)
{
	Object_wx_RichTextHeaderFooterData *pThis = Object_wx_RichTextHeaderFooterData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int headerMargin = arg.GetNumber(0)
	//int footerMargin = arg.GetNumber(1)
	//pThis->GetEntity()->SetMargins();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextHeaderFooterData, __SetShowOnFirstPage, "SetShowOnFirstPage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "showOnFirstPage", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextHeaderFooterData, __SetShowOnFirstPage)
{
	Object_wx_RichTextHeaderFooterData *pThis = Object_wx_RichTextHeaderFooterData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool showOnFirstPage = arg.GetNumber(0)
	//pThis->GetEntity()->SetShowOnFirstPage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextHeaderFooterData, __SetText, "SetText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "headerFooter", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "location", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextHeaderFooterData, __SetText)
{
	Object_wx_RichTextHeaderFooterData *pThis = Object_wx_RichTextHeaderFooterData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& text = arg.GetNumber(0)
	//int headerFooter = arg.GetNumber(1)
	//wxRichTextOddEvenPage page = arg.GetNumber(2)
	//wxRichTextPageLocation location = arg.GetNumber(3)
	//pThis->GetEntity()->SetText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextHeaderFooterData, __SetTextColour, "SetTextColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextHeaderFooterData, __SetTextColour)
{
	Object_wx_RichTextHeaderFooterData *pThis = Object_wx_RichTextHeaderFooterData::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& col = arg.GetNumber(0)
	//pThis->GetEntity()->SetTextColour();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextHeaderFooterData
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextHeaderFooterData)
{
	// Constructor assignment
	Gura_AssignFunction(__RichTextHeaderFooterData);
	Gura_AssignFunction(__RichTextHeaderFooterData_1);
	// Method assignment
	Gura_AssignMethod(wx_RichTextHeaderFooterData, __Clear);
	Gura_AssignMethod(wx_RichTextHeaderFooterData, __Copy);
	Gura_AssignMethod(wx_RichTextHeaderFooterData, __GetFont);
	Gura_AssignMethod(wx_RichTextHeaderFooterData, __GetFooterMargin);
	Gura_AssignMethod(wx_RichTextHeaderFooterData, __GetFooterText);
	Gura_AssignMethod(wx_RichTextHeaderFooterData, __GetHeaderMargin);
	Gura_AssignMethod(wx_RichTextHeaderFooterData, __GetHeaderText);
	Gura_AssignMethod(wx_RichTextHeaderFooterData, __GetShowOnFirstPage);
	Gura_AssignMethod(wx_RichTextHeaderFooterData, __GetText);
	Gura_AssignMethod(wx_RichTextHeaderFooterData, __GetTextColour);
	Gura_AssignMethod(wx_RichTextHeaderFooterData, __Init);
	Gura_AssignMethod(wx_RichTextHeaderFooterData, __SetFont);
	Gura_AssignMethod(wx_RichTextHeaderFooterData, __SetFooterText);
	Gura_AssignMethod(wx_RichTextHeaderFooterData, __SetHeaderText);
	Gura_AssignMethod(wx_RichTextHeaderFooterData, __SetMargins);
	Gura_AssignMethod(wx_RichTextHeaderFooterData, __SetShowOnFirstPage);
	Gura_AssignMethod(wx_RichTextHeaderFooterData, __SetText);
	Gura_AssignMethod(wx_RichTextHeaderFooterData, __SetTextColour);
}

Gura_ImplementDescendantCreator(wx_RichTextHeaderFooterData)
{
	return new Object_wx_RichTextHeaderFooterData((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
