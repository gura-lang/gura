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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__RichTextParagraphStyleDefinition, "RichTextParagraphStyleDefinition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RichTextParagraphStyleDefinition));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RichTextParagraphStyleDefinition)
{
	//const wxString& name = arg.GetNumber(0)
	//wxRichTextParagraphStyleDefinition(name);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RichTextParagraphStyleDefinition, __GetNextStyle, "GetNextStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextParagraphStyleDefinition, __GetNextStyle)
{
	Object_wx_RichTextParagraphStyleDefinition *pThis = Object_wx_RichTextParagraphStyleDefinition::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& _rtn = pThis->GetEntity()->GetNextStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextParagraphStyleDefinition, __SetNextStyle, "SetNextStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextParagraphStyleDefinition, __SetNextStyle)
{
	Object_wx_RichTextParagraphStyleDefinition *pThis = Object_wx_RichTextParagraphStyleDefinition::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//pThis->GetEntity()->SetNextStyle(name);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextParagraphStyleDefinition
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextParagraphStyleDefinition)
{
	// Constructor assignment
	Gura_AssignFunction(__RichTextParagraphStyleDefinition);
	// Method assignment
	Gura_AssignMethod(wx_RichTextParagraphStyleDefinition, __GetNextStyle);
	Gura_AssignMethod(wx_RichTextParagraphStyleDefinition, __SetNextStyle);
}

Gura_ImplementDescendantCreator(wx_RichTextParagraphStyleDefinition)
{
	return new Object_wx_RichTextParagraphStyleDefinition((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
