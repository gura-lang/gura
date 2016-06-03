//----------------------------------------------------------------------------
// wxRichTextListStyleDefinition
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextListStyleDefinition
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextListStyleDefinition
//----------------------------------------------------------------------------
Object_wx_RichTextListStyleDefinition::~Object_wx_RichTextListStyleDefinition()
{
}

Object *Object_wx_RichTextListStyleDefinition::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextListStyleDefinition::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextListStyleDefinition:");
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
Gura_DeclareFunctionAlias(__RichTextListStyleDefinition, "RichTextListStyleDefinition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RichTextListStyleDefinition));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RichTextListStyleDefinition)
{
	//const wxString& name = arg.GetNumber(0)
	//wxRichTextListStyleDefinition();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RichTextListStyleDefinition, __CombineWithParagraphStyle, "CombineWithParagraphStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "indent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "paraStyle", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "styleSheet", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextListStyleDefinition, __CombineWithParagraphStyle)
{
	Object_wx_RichTextListStyleDefinition *pThis = Object_wx_RichTextListStyleDefinition::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int indent = arg.GetNumber(0)
	//const wxRichTextAttr& paraStyle = arg.GetNumber(1)
	//wxRichTextStyleSheet* styleSheet = arg.GetNumber(2)
	//pThis->GetEntity()->CombineWithParagraphStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextListStyleDefinition, __FindLevelForIndent, "FindLevelForIndent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "indent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextListStyleDefinition, __FindLevelForIndent)
{
	Object_wx_RichTextListStyleDefinition *pThis = Object_wx_RichTextListStyleDefinition::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int indent = arg.GetNumber(0)
	//pThis->GetEntity()->FindLevelForIndent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextListStyleDefinition, __GetCombinedStyle, "GetCombinedStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "indent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "styleSheet", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextListStyleDefinition, __GetCombinedStyle)
{
	Object_wx_RichTextListStyleDefinition *pThis = Object_wx_RichTextListStyleDefinition::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int indent = arg.GetNumber(0)
	//wxRichTextStyleSheet* styleSheet = arg.GetNumber(1)
	//pThis->GetEntity()->GetCombinedStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextListStyleDefinition, __GetCombinedStyleForLevel, "GetCombinedStyleForLevel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "styleSheet", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextListStyleDefinition, __GetCombinedStyleForLevel)
{
	Object_wx_RichTextListStyleDefinition *pThis = Object_wx_RichTextListStyleDefinition::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int level = arg.GetNumber(0)
	//wxRichTextStyleSheet* styleSheet = arg.GetNumber(1)
	//pThis->GetEntity()->GetCombinedStyleForLevel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextListStyleDefinition, __GetLevelAttributes, "GetLevelAttributes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextListStyleDefinition, __GetLevelAttributes)
{
	Object_wx_RichTextListStyleDefinition *pThis = Object_wx_RichTextListStyleDefinition::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int level = arg.GetNumber(0)
	//pThis->GetEntity()->GetLevelAttributes();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextListStyleDefinition, __GetLevelCount, "GetLevelCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextListStyleDefinition, __GetLevelCount)
{
	Object_wx_RichTextListStyleDefinition *pThis = Object_wx_RichTextListStyleDefinition::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLevelCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextListStyleDefinition, __IsNumbered, "IsNumbered")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextListStyleDefinition, __IsNumbered)
{
	Object_wx_RichTextListStyleDefinition *pThis = Object_wx_RichTextListStyleDefinition::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int level = arg.GetNumber(0)
	//pThis->GetEntity()->IsNumbered();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextListStyleDefinition, __SetLevelAttributes, "SetLevelAttributes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "attr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextListStyleDefinition, __SetLevelAttributes)
{
	Object_wx_RichTextListStyleDefinition *pThis = Object_wx_RichTextListStyleDefinition::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int level = arg.GetNumber(0)
	//const wxRichTextAttr& attr = arg.GetNumber(1)
	//pThis->GetEntity()->SetLevelAttributes();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextListStyleDefinition
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextListStyleDefinition)
{
	// Constructor assignment
	Gura_AssignFunction(__RichTextListStyleDefinition);
	// Method assignment
	Gura_AssignMethod(wx_RichTextListStyleDefinition, __CombineWithParagraphStyle);
	Gura_AssignMethod(wx_RichTextListStyleDefinition, __FindLevelForIndent);
	Gura_AssignMethod(wx_RichTextListStyleDefinition, __GetCombinedStyle);
	Gura_AssignMethod(wx_RichTextListStyleDefinition, __GetCombinedStyleForLevel);
	Gura_AssignMethod(wx_RichTextListStyleDefinition, __GetLevelAttributes);
	Gura_AssignMethod(wx_RichTextListStyleDefinition, __GetLevelCount);
	Gura_AssignMethod(wx_RichTextListStyleDefinition, __IsNumbered);
	Gura_AssignMethod(wx_RichTextListStyleDefinition, __SetLevelAttributes);
}

Gura_ImplementDescendantCreator(wx_RichTextListStyleDefinition)
{
	return new Object_wx_RichTextListStyleDefinition((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
