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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_RichTextHeaderFooterData, wxRichTextHeaderFooterData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextHeaderFooterData, wxRichTextHeaderFooterData)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextHeaderFooterData *pThis = Object_wx_RichTextHeaderFooterData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxRichTextHeaderFooterData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextHeaderFooterData, wxRichTextHeaderFooterData_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextHeaderFooterData, wxRichTextHeaderFooterData_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextHeaderFooterData *pThis = Object_wx_RichTextHeaderFooterData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->wxRichTextHeaderFooterData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextHeaderFooterData, Clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextHeaderFooterData, Clear)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextHeaderFooterData *pThis = Object_wx_RichTextHeaderFooterData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextHeaderFooterData, Copy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextHeaderFooterData, Copy)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextHeaderFooterData *pThis = Object_wx_RichTextHeaderFooterData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->Copy();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextHeaderFooterData, GetFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextHeaderFooterData, GetFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextHeaderFooterData *pThis = Object_wx_RichTextHeaderFooterData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextHeaderFooterData, GetFooterMargin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextHeaderFooterData, GetFooterMargin)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextHeaderFooterData *pThis = Object_wx_RichTextHeaderFooterData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFooterMargin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextHeaderFooterData, GetFooterText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "location", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextHeaderFooterData, GetFooterText)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextHeaderFooterData *pThis = Object_wx_RichTextHeaderFooterData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//int location = arg.GetNumber(1)
	//pThis->GetEntity()->GetFooterText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextHeaderFooterData, GetHeaderMargin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextHeaderFooterData, GetHeaderMargin)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextHeaderFooterData *pThis = Object_wx_RichTextHeaderFooterData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetHeaderMargin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextHeaderFooterData, GetHeaderText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "location", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextHeaderFooterData, GetHeaderText)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextHeaderFooterData *pThis = Object_wx_RichTextHeaderFooterData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int page = arg.GetNumber(0)
	//int location = arg.GetNumber(1)
	//pThis->GetEntity()->GetHeaderText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextHeaderFooterData, GetShowOnFirstPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextHeaderFooterData, GetShowOnFirstPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextHeaderFooterData *pThis = Object_wx_RichTextHeaderFooterData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetShowOnFirstPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextHeaderFooterData, GetText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "headerFooter", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "location", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextHeaderFooterData, GetText)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextHeaderFooterData *pThis = Object_wx_RichTextHeaderFooterData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int headerFooter = arg.GetNumber(0)
	//int page = arg.GetNumber(1)
	//int location = arg.GetNumber(2)
	//pThis->GetEntity()->GetText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextHeaderFooterData, GetTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextHeaderFooterData, GetTextColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextHeaderFooterData *pThis = Object_wx_RichTextHeaderFooterData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetTextColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextHeaderFooterData, Init)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextHeaderFooterData, Init)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextHeaderFooterData *pThis = Object_wx_RichTextHeaderFooterData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Init();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextHeaderFooterData, SetFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextHeaderFooterData, SetFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextHeaderFooterData *pThis = Object_wx_RichTextHeaderFooterData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int font = arg.GetNumber(0)
	//pThis->GetEntity()->SetFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextHeaderFooterData, SetFooterText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "location", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextHeaderFooterData, SetFooterText)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextHeaderFooterData *pThis = Object_wx_RichTextHeaderFooterData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//int page = arg.GetNumber(1)
	//int location = arg.GetNumber(2)
	//pThis->GetEntity()->SetFooterText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextHeaderFooterData, SetHeaderText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "location", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextHeaderFooterData, SetHeaderText)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextHeaderFooterData *pThis = Object_wx_RichTextHeaderFooterData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//int page = arg.GetNumber(1)
	//int location = arg.GetNumber(2)
	//pThis->GetEntity()->SetHeaderText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextHeaderFooterData, SetMargins)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "headerMargin", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "footerMargin", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextHeaderFooterData, SetMargins)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextHeaderFooterData *pThis = Object_wx_RichTextHeaderFooterData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int headerMargin = arg.GetNumber(0)
	//int footerMargin = arg.GetNumber(1)
	//pThis->GetEntity()->SetMargins();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextHeaderFooterData, SetShowOnFirstPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "showOnFirstPage", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextHeaderFooterData, SetShowOnFirstPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextHeaderFooterData *pThis = Object_wx_RichTextHeaderFooterData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int showOnFirstPage = arg.GetNumber(0)
	//pThis->GetEntity()->SetShowOnFirstPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextHeaderFooterData, SetText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "headerFooter", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "location", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextHeaderFooterData, SetText)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextHeaderFooterData *pThis = Object_wx_RichTextHeaderFooterData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//int headerFooter = arg.GetNumber(1)
	//int page = arg.GetNumber(2)
	//int location = arg.GetNumber(3)
	//pThis->GetEntity()->SetText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextHeaderFooterData, SetTextColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextHeaderFooterData, SetTextColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichTextHeaderFooterData *pThis = Object_wx_RichTextHeaderFooterData::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int col = arg.GetNumber(0)
	//pThis->GetEntity()->SetTextColour();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextHeaderFooterData
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextHeaderFooterData)
{
	Gura_AssignMethod(wx_RichTextHeaderFooterData, wxRichTextHeaderFooterData);
	Gura_AssignMethod(wx_RichTextHeaderFooterData, wxRichTextHeaderFooterData_1);
	Gura_AssignMethod(wx_RichTextHeaderFooterData, Clear);
	Gura_AssignMethod(wx_RichTextHeaderFooterData, Copy);
	Gura_AssignMethod(wx_RichTextHeaderFooterData, GetFont);
	Gura_AssignMethod(wx_RichTextHeaderFooterData, GetFooterMargin);
	Gura_AssignMethod(wx_RichTextHeaderFooterData, GetFooterText);
	Gura_AssignMethod(wx_RichTextHeaderFooterData, GetHeaderMargin);
	Gura_AssignMethod(wx_RichTextHeaderFooterData, GetHeaderText);
	Gura_AssignMethod(wx_RichTextHeaderFooterData, GetShowOnFirstPage);
	Gura_AssignMethod(wx_RichTextHeaderFooterData, GetText);
	Gura_AssignMethod(wx_RichTextHeaderFooterData, GetTextColour);
	Gura_AssignMethod(wx_RichTextHeaderFooterData, Init);
	Gura_AssignMethod(wx_RichTextHeaderFooterData, SetFont);
	Gura_AssignMethod(wx_RichTextHeaderFooterData, SetFooterText);
	Gura_AssignMethod(wx_RichTextHeaderFooterData, SetHeaderText);
	Gura_AssignMethod(wx_RichTextHeaderFooterData, SetMargins);
	Gura_AssignMethod(wx_RichTextHeaderFooterData, SetShowOnFirstPage);
	Gura_AssignMethod(wx_RichTextHeaderFooterData, SetText);
	Gura_AssignMethod(wx_RichTextHeaderFooterData, SetTextColour);
}

Gura_ImplementDescendantCreator(wx_RichTextHeaderFooterData)
{
	return new Object_wx_RichTextHeaderFooterData((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
