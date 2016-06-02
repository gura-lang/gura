//----------------------------------------------------------------------------
// wxRichTextStyleSheet
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextStyleSheet
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextStyleSheet
//----------------------------------------------------------------------------
Object_wx_RichTextStyleSheet::~Object_wx_RichTextStyleSheet()
{
}

Object *Object_wx_RichTextStyleSheet::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextStyleSheet::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextStyleSheet:");
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
Gura_DeclareMethod(wx_RichTextStyleSheet, wxRichTextStyleSheet)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleSheet, wxRichTextStyleSheet)
{
	Object_wx_RichTextStyleSheet *pThis = Object_wx_RichTextStyleSheet::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxRichTextStyleSheet();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleSheet, AddCharacterStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "def", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleSheet, AddCharacterStyle)
{
	Object_wx_RichTextStyleSheet *pThis = Object_wx_RichTextStyleSheet::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int def = arg.GetNumber(0)
	//pThis->GetEntity()->AddCharacterStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleSheet, AddListStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "def", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleSheet, AddListStyle)
{
	Object_wx_RichTextStyleSheet *pThis = Object_wx_RichTextStyleSheet::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int def = arg.GetNumber(0)
	//pThis->GetEntity()->AddListStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleSheet, AddParagraphStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "def", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleSheet, AddParagraphStyle)
{
	Object_wx_RichTextStyleSheet *pThis = Object_wx_RichTextStyleSheet::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int def = arg.GetNumber(0)
	//pThis->GetEntity()->AddParagraphStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleSheet, AddStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "def", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleSheet, AddStyle)
{
	Object_wx_RichTextStyleSheet *pThis = Object_wx_RichTextStyleSheet::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int def = arg.GetNumber(0)
	//pThis->GetEntity()->AddStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleSheet, DeleteStyles)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleSheet, DeleteStyles)
{
	Object_wx_RichTextStyleSheet *pThis = Object_wx_RichTextStyleSheet::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DeleteStyles();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleSheet, FindCharacterStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "recurse", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleSheet, FindCharacterStyle)
{
	Object_wx_RichTextStyleSheet *pThis = Object_wx_RichTextStyleSheet::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int recurse = arg.GetNumber(1)
	//pThis->GetEntity()->FindCharacterStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleSheet, FindListStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "recurse", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleSheet, FindListStyle)
{
	Object_wx_RichTextStyleSheet *pThis = Object_wx_RichTextStyleSheet::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int recurse = arg.GetNumber(1)
	//pThis->GetEntity()->FindListStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleSheet, FindParagraphStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "recurse", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleSheet, FindParagraphStyle)
{
	Object_wx_RichTextStyleSheet *pThis = Object_wx_RichTextStyleSheet::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//int recurse = arg.GetNumber(1)
	//pThis->GetEntity()->FindParagraphStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleSheet, FindStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleSheet, FindStyle)
{
	Object_wx_RichTextStyleSheet *pThis = Object_wx_RichTextStyleSheet::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->FindStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleSheet, GetCharacterStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleSheet, GetCharacterStyle)
{
	Object_wx_RichTextStyleSheet *pThis = Object_wx_RichTextStyleSheet::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->GetCharacterStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleSheet, GetCharacterStyleCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleSheet, GetCharacterStyleCount)
{
	Object_wx_RichTextStyleSheet *pThis = Object_wx_RichTextStyleSheet::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCharacterStyleCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleSheet, GetDescription)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleSheet, GetDescription)
{
	Object_wx_RichTextStyleSheet *pThis = Object_wx_RichTextStyleSheet::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDescription();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleSheet, GetListStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleSheet, GetListStyle)
{
	Object_wx_RichTextStyleSheet *pThis = Object_wx_RichTextStyleSheet::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->GetListStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleSheet, GetListStyleCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleSheet, GetListStyleCount)
{
	Object_wx_RichTextStyleSheet *pThis = Object_wx_RichTextStyleSheet::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetListStyleCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleSheet, GetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleSheet, GetName)
{
	Object_wx_RichTextStyleSheet *pThis = Object_wx_RichTextStyleSheet::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleSheet, GetParagraphStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleSheet, GetParagraphStyle)
{
	Object_wx_RichTextStyleSheet *pThis = Object_wx_RichTextStyleSheet::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->GetParagraphStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleSheet, GetParagraphStyleCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleSheet, GetParagraphStyleCount)
{
	Object_wx_RichTextStyleSheet *pThis = Object_wx_RichTextStyleSheet::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetParagraphStyleCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleSheet, RemoveCharacterStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "def", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "deleteStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleSheet, RemoveCharacterStyle)
{
	Object_wx_RichTextStyleSheet *pThis = Object_wx_RichTextStyleSheet::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int def = arg.GetNumber(0)
	//int deleteStyle = arg.GetNumber(1)
	//pThis->GetEntity()->RemoveCharacterStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleSheet, RemoveListStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "def", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "deleteStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleSheet, RemoveListStyle)
{
	Object_wx_RichTextStyleSheet *pThis = Object_wx_RichTextStyleSheet::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int def = arg.GetNumber(0)
	//int deleteStyle = arg.GetNumber(1)
	//pThis->GetEntity()->RemoveListStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleSheet, RemoveParagraphStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "def", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "deleteStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleSheet, RemoveParagraphStyle)
{
	Object_wx_RichTextStyleSheet *pThis = Object_wx_RichTextStyleSheet::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int def = arg.GetNumber(0)
	//int deleteStyle = arg.GetNumber(1)
	//pThis->GetEntity()->RemoveParagraphStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleSheet, RemoveStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "def", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "deleteStyle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleSheet, RemoveStyle)
{
	Object_wx_RichTextStyleSheet *pThis = Object_wx_RichTextStyleSheet::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int def = arg.GetNumber(0)
	//int deleteStyle = arg.GetNumber(1)
	//pThis->GetEntity()->RemoveStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleSheet, SetDescription)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "descr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleSheet, SetDescription)
{
	Object_wx_RichTextStyleSheet *pThis = Object_wx_RichTextStyleSheet::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int descr = arg.GetNumber(0)
	//pThis->GetEntity()->SetDescription();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleSheet, SetName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleSheet, SetName)
{
	Object_wx_RichTextStyleSheet *pThis = Object_wx_RichTextStyleSheet::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->SetName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleSheet, GetProperties)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleSheet, GetProperties)
{
	Object_wx_RichTextStyleSheet *pThis = Object_wx_RichTextStyleSheet::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetProperties();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleSheet, GetProperties_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleSheet, GetProperties_1)
{
	Object_wx_RichTextStyleSheet *pThis = Object_wx_RichTextStyleSheet::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetProperties();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleSheet, SetProperties)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "props", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleSheet, SetProperties)
{
	Object_wx_RichTextStyleSheet *pThis = Object_wx_RichTextStyleSheet::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int props = arg.GetNumber(0)
	//pThis->GetEntity()->SetProperties();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextStyleSheet
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextStyleSheet)
{
	Gura_AssignMethod(wx_RichTextStyleSheet, wxRichTextStyleSheet);
	Gura_AssignMethod(wx_RichTextStyleSheet, AddCharacterStyle);
	Gura_AssignMethod(wx_RichTextStyleSheet, AddListStyle);
	Gura_AssignMethod(wx_RichTextStyleSheet, AddParagraphStyle);
	Gura_AssignMethod(wx_RichTextStyleSheet, AddStyle);
	Gura_AssignMethod(wx_RichTextStyleSheet, DeleteStyles);
	Gura_AssignMethod(wx_RichTextStyleSheet, FindCharacterStyle);
	Gura_AssignMethod(wx_RichTextStyleSheet, FindListStyle);
	Gura_AssignMethod(wx_RichTextStyleSheet, FindParagraphStyle);
	Gura_AssignMethod(wx_RichTextStyleSheet, FindStyle);
	Gura_AssignMethod(wx_RichTextStyleSheet, GetCharacterStyle);
	Gura_AssignMethod(wx_RichTextStyleSheet, GetCharacterStyleCount);
	Gura_AssignMethod(wx_RichTextStyleSheet, GetDescription);
	Gura_AssignMethod(wx_RichTextStyleSheet, GetListStyle);
	Gura_AssignMethod(wx_RichTextStyleSheet, GetListStyleCount);
	Gura_AssignMethod(wx_RichTextStyleSheet, GetName);
	Gura_AssignMethod(wx_RichTextStyleSheet, GetParagraphStyle);
	Gura_AssignMethod(wx_RichTextStyleSheet, GetParagraphStyleCount);
	Gura_AssignMethod(wx_RichTextStyleSheet, RemoveCharacterStyle);
	Gura_AssignMethod(wx_RichTextStyleSheet, RemoveListStyle);
	Gura_AssignMethod(wx_RichTextStyleSheet, RemoveParagraphStyle);
	Gura_AssignMethod(wx_RichTextStyleSheet, RemoveStyle);
	Gura_AssignMethod(wx_RichTextStyleSheet, SetDescription);
	Gura_AssignMethod(wx_RichTextStyleSheet, SetName);
	Gura_AssignMethod(wx_RichTextStyleSheet, GetProperties);
	Gura_AssignMethod(wx_RichTextStyleSheet, GetProperties_1);
	Gura_AssignMethod(wx_RichTextStyleSheet, SetProperties);
}

Gura_ImplementDescendantCreator(wx_RichTextStyleSheet)
{
	return new Object_wx_RichTextStyleSheet((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
