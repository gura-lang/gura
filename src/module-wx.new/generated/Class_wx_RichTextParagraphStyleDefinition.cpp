//----------------------------------------------------------------------------
// wxRichTextParagraphStyleDefinition
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextParagraphStyleDefinition
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextParagraphStyleDefinition
//----------------------------------------------------------------------------
Object_wx_RichTextParagraphStyleDefinition::~Object_wx_RichTextParagraphStyleDefinition()
{
}

Object *Object_wx_RichTextParagraphStyleDefinition::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextParagraphStyleDefinition::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextParagraphStyleDefinition:");
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
Gura_DeclareMethod(wx_RichTextParagraphStyleDefinition, wxRichTextParagraphStyleDefinition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphStyleDefinition, wxRichTextParagraphStyleDefinition)
{
	Object_wx_RichTextParagraphStyleDefinition *pThis = Object_wx_RichTextParagraphStyleDefinition::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->wxRichTextParagraphStyleDefinition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphStyleDefinition, GetNextStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextParagraphStyleDefinition, GetNextStyle)
{
	Object_wx_RichTextParagraphStyleDefinition *pThis = Object_wx_RichTextParagraphStyleDefinition::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetNextStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextParagraphStyleDefinition, SetNextStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphStyleDefinition, SetNextStyle)
{
	Object_wx_RichTextParagraphStyleDefinition *pThis = Object_wx_RichTextParagraphStyleDefinition::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->SetNextStyle();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextParagraphStyleDefinition
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextParagraphStyleDefinition)
{
	Gura_AssignMethod(wx_RichTextParagraphStyleDefinition, wxRichTextParagraphStyleDefinition);
	Gura_AssignMethod(wx_RichTextParagraphStyleDefinition, GetNextStyle);
	Gura_AssignMethod(wx_RichTextParagraphStyleDefinition, SetNextStyle);
}

Gura_ImplementDescendantCreator(wx_RichTextParagraphStyleDefinition)
{
	return new Object_wx_RichTextParagraphStyleDefinition((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
